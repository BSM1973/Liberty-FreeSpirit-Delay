#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <vector>
namespace fsd {
constexpr float pi=3.14159265358979323846f;
inline float clamp(float x,float lo,float hi){return std::clamp(x,lo,hi);}
inline float db(float x){return std::pow(10.f,x/20.f);}
struct Settings {
 int mode=0, wave=0; bool sync=true,link=true,modSync=false,freeze=false,mute=false,solo=false,bypass=false,safety=true;
 float left=500,right=500,division=9,ratio=1,feedback=42,mix=28,width=100,output=0,input=0,saturation=20,drive=3,tone=0,wear=15,wow=15,flutter=10;
 float hp=40,lp=12000,res=0.7f,rate=.6f,depth=10,duck=0,threshold=-24,attack=10,release=250,spread=0,pan=0,cross=100,grain=80,diffuse=35,bits=12,shift=12,safe=-1;
 std::array<float,4> tapTime{1,1.5f,2,3},tapLevel{100,55,35,20},tapPan{-50,50,-70,70};
};
inline constexpr std::array<float,15> beats{.125f,1.f/6,.1875f,.25f,1.f/3,.5f,.375f,2.f/3,.75f,1,1.5f,2,3,4,8};
inline constexpr std::array<const char*,15> divisions{"1/32","1/16 T","1/32 D","1/16","1/8 T","1/8","1/16 D","1/4 T","1/8 D","1/4","1/4 D","1/2","1/2 D","1 bar","2 bars"};
struct Core {
 std::array<std::vector<float>,2> ring; size_t pos=0; double sr=48000; float phase=0,env=0; std::array<float,2> lo{},hpState{},smoothDelay{},lastWet{},meterWet{},holdSample{}; std::array<float,2> reversePhase{},pitchPhase{},grainPhase{}; unsigned sampleCounter=0;
 void prepare(double rate){sr=rate; for(auto& r:ring) r.assign(size_t(sr*16)+8,0); reset();}
 void reset(){for(auto& r:ring)std::fill(r.begin(),r.end(),0);pos=0;phase=env=0;lo={};hpState={};smoothDelay={};lastWet={};meterWet={};holdSample={};reversePhase={};pitchPhase={};grainPhase={};sampleCounter=0;}
 float read(int c,float delay)const{const auto& r=ring[c];float d=clamp(delay,1.f,float(r.size()-3));double x=double(pos)-d;if(x<0)x+=r.size();auto a=size_t(x);auto b=(a+1)%r.size();float f=float(x-a);return r[a]+f*(r[b]-r[a]);}
 float dual(int c,float base,float& ph,float step,float window){ph+=step;if(ph>=1)ph-=std::floor(ph);if(ph<0)ph-=std::floor(ph);float q=std::fmod(ph+.5f,1.f);float w=.5f-.5f*std::cos(2*pi*ph);return w*read(c,base+ph*window)+(1-w)*read(c,base+q*window);}
 std::array<float,2> tick(float l,float r,const Settings& s,float bpm){
  if(ring[0].empty())return {l,r};float dry[2]={l,r}, wet[2]={};float ins[2]={l*db(s.input),r*db(s.input)};
  float tempo=60000.f/std::max(20.f,bpm);float ms=s.sync?tempo*beats[size_t(clamp(s.division,0,14))]:s.left;
  float msR=s.link?ms*s.ratio:(s.sync?tempo*beats[size_t(clamp(s.division,0,14))]*s.ratio:s.right);
  if(s.mode==5){ms=clamp(ms,35,160);msR=clamp(msR,35,160);}
  float target[2]={ms*float(sr)/1000,msR*float(sr)/1000}; target[0]*=1-s.spread*.002f;target[1]*=1+s.spread*.002f;
  float rate=s.modSync?bpm/60.f*s.rate:s.rate;phase+=rate/float(sr);phase-=std::floor(phase);float wav=s.wave==1?1-4*std::abs(phase-.5f):s.wave==2?2*phase-1:s.wave==3?(phase<.5f?1.f:-1.f):std::sin(2*pi*phase);
  for(int c=0;c<2;++c){if(smoothDelay[c]==0)smoothDelay[c]=target[c];smoothDelay[c]+=.0015f*(target[c]-smoothDelay[c]);float d=smoothDelay[c];float mod=s.depth*.00015f*float(sr)*(c? -wav:wav);if(s.mode==2)mod+=float(sr)*(.00008f*s.wow*std::sin(2*pi*phase)+.000015f*s.flutter*std::sin(2*pi*phase*13)); if(s.mode==2||s.mode==10||s.depth>0) d+=mod;d=clamp(d,2,float(ring[c].size()-3));
   if(s.mode==6){float sum=0;for(int t=0;t<4;t++){float p=clamp((s.tapPan[t]+100)/200,0,1);float gain=s.tapLevel[t]*.01f*(c?std::sqrt(p):std::sqrt(1-p));sum+=gain*read(c,d*s.tapTime[t]);}wet[c]=sum*.65f;}
   else if(s.mode==7){float window=clamp(d*.5f,64,float(sr)*.6f);wet[c]=dual(c,d,reversePhase[c],1.f/window,window*2);}
   else if(s.mode==8){float window=std::max(32.f,s.grain*.001f*float(sr));float g=dual(c,d,grainPhase[c],.73f/window,window);float a=clamp(s.diffuse*.01f,0,1);wet[c]=(1-a)*g+a*(read(c,d+window*.37f)+read(c,d+window*.71f)+read(1-c,d+window*.91f))/3;}
   else if(s.mode==11){float window=float(sr)*.07f;float factor=std::pow(2.f,s.shift/12.f);wet[c]=dual(c,d,pitchPhase[c],(1-factor)/window,window);}
   else wet[c]=read(c,d);
  }
  meterWet={wet[0],wet[1]};float f=clamp(s.feedback*.01f,0,1.2f);if(s.freeze)f=1;
  for(int c=0;c<2;c++){float cross=s.mode==3?s.cross*.01f:0;float v=(wet[c]*(1-cross)+wet[1-c]*cross)*f;
   if(!s.freeze){float high=clamp(s.lp*std::pow(2.f,s.tone/50.f),100,float(sr)*.45f);if(s.mode==1||s.mode==2)high*=1-s.wear*.006f;float a=1-std::exp(-2*pi*high/float(sr));float b=1-std::exp(-2*pi*clamp(s.hp,10,2000)/float(sr));lo[c]+=a*(v-lo[c]);hpState[c]+=b*(lo[c]-hpState[c]);v=lo[c]-hpState[c];v+=(v-lastWet[c])*clamp((s.res-.7f)*.16f,0,.6f);lastWet[c]=v;float sat=s.saturation*.01f;if(s.mode==1||s.mode==2)sat=std::max(sat,.12f);if(sat>0){float gain=db(s.drive)*(1+sat*3);v=(1-sat)*v+sat*std::tanh(v*gain)/std::max(1.f,gain*.65f);}if(s.mode==9){float steps=std::pow(2.f,clamp(s.bits,3,16)-1);if(sampleCounter%unsigned(1+s.wear*.12f)==0)holdSample[c]=std::round(v*steps)/steps;v=holdSample[c];}}
   if(s.safety)v=clamp(v,-db(s.safe),db(s.safe));else v=clamp(v,-8,8);ring[c][pos]=clamp((s.freeze?0:ins[c])+v,-16,16);
  }
  pos=(pos+1)%ring[0].size();++sampleCounter;float e=std::max(std::abs(l),std::abs(r));float tc=e>env?s.attack:s.release;env+=(1-std::exp(-1000.f/(float(sr)*std::max(tc,1.f))))*(e-env);float reduction=1/(1+s.duck*.01f*6*std::max(0.f,env/std::max(.001f,db(s.threshold))-1));float mid=(wet[0]+wet[1])*.5f,side=(wet[0]-wet[1])*.5f*s.width*.01f;float w[2]={mid+side,mid-side};float m=s.solo?1:s.mix*.01f;std::array<float,2> out{};for(int c=0;c<2;c++){float p=c?clamp(1+s.pan*.01f,0,1):clamp(1-s.pan*.01f,0,1);out[c]=s.bypass?dry[c]:((1-m)*dry[c]+(s.mute?0:m*w[c]*reduction*p))*db(s.output);if(!s.bypass&&s.safety)out[c]=clamp(out[c],-db(s.safe),db(s.safe));}return out;
 }
};
}
