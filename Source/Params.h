#pragma once
#include "DelayCore.h"
#include <JuceHeader.h>
namespace fsd {
struct Spec{const char* id;const char* name;float lo,hi,def,step;const char* unit;};
inline constexpr Spec specs[]={
{"mode","Engine",0,11,2,1,""},{"sync","Sync",0,1,1,1,""},{"link","Link",0,1,1,1,""},{"division","Division",0,14,9,1,""},{"ratio","Ratio L/R",.25,4,1,.25,""},{"left","Left delay",1,8000,500,1," ms"},{"right","Right delay",1,8000,500,1," ms"},
{"feedback","Feedback",0,120,42,.1,"%"},{"mix","Dry / Wet",0,100,28,.1,"%"},{"width","Stereo width",0,200,100,1,"%"},{"output","Output",-24,12,0,.1," dB"},{"input","Input",-24,12,0,.1," dB"},
{"saturation","Saturation",0,100,20,1,"%"},{"drive","Drive",-12,24,3,.1," dB"},{"tone","Tone",-100,100,0,1,""},{"wear","Wear",0,100,15,1,"%"},{"wow","Wow",0,100,15,1,"%"},{"flutter","Flutter",0,100,10,1,"%"},
{"hp","High-pass",20,2000,40,1," Hz"},{"lp","Low-pass",200,20000,12000,1," Hz"},{"res","Resonance",.5,4,.7,.01,""},{"rate","Rate",.05,12,.6,.01," Hz"},{"depth","Depth",0,100,10,1,"%"},{"wave","Wave",0,3,0,1,""},{"modSync","LFO sync",0,1,0,1,""},
{"duck","Duck",0,100,0,1,"%"},{"threshold","Threshold",-60,0,-24,.1," dB"},{"attack","Attack",1,250,10,1," ms"},{"release","Release",10,2000,250,1," ms"},
{"grain","Grain size",10,250,80,1," ms"},{"diffuse","Diffusion",0,100,35,1,"%"},{"bits","Bit depth",3,16,12,1," bit"},{"shift","Pitch",-24,24,12,1," st"},{"spread","Spread",0,100,0,1,"%"},{"pan","Pan",-100,100,0,1,"%"},{"cross","Crossfeed",0,100,100,1,"%"},
{"freeze","Hold / Freeze",0,1,0,1,""},{"mute","Mute",0,1,0,1,""},{"solo","Wet solo",0,1,0,1,""},{"bypass","Bypass",0,1,0,1,""},{"safety","Safety",0,1,1,1,""},{"safe","Ceiling",-12,0,-1,.1," dB"},
{"tapTime1","Tap 1 time",.25,4,1,.25," x"},{"tapTime2","Tap 2 time",.25,4,1.5,.25," x"},{"tapTime3","Tap 3 time",.25,4,2,.25," x"},{"tapTime4","Tap 4 time",.25,4,3,.25," x"},
{"tapLevel1","Tap 1 level",0,100,100,1,"%"},{"tapLevel2","Tap 2 level",0,100,55,1,"%"},{"tapLevel3","Tap 3 level",0,100,35,1,"%"},{"tapLevel4","Tap 4 level",0,100,20,1,"%"},
{"tapPan1","Tap 1 pan",-100,100,-50,1,"%"},{"tapPan2","Tap 2 pan",-100,100,50,1,"%"},{"tapPan3","Tap 3 pan",-100,100,-70,1,"%"},{"tapPan4","Tap 4 pan",-100,100,70,1,"%"}};
inline const char* modes[]={"Digital","Analog","Tape","Ping-Pong","Stereo","Slapback","Multi-Tap","Reverse","Granular / Diffuse","Lo-Fi","Modulated","Shimmer"};
inline juce::AudioProcessorValueTreeState::ParameterLayout layout(){juce::AudioProcessorValueTreeState::ParameterLayout p;for(auto& s:specs){juce::NormalisableRange<float> r(s.lo,s.hi,s.step);if(juce::String(s.id)=="lp"||juce::String(s.id)=="hp"||juce::String(s.id)=="left"||juce::String(s.id)=="right")r.setSkewForCentre(std::sqrt(s.lo*s.hi));p.add(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID{s.id,1},s.name,r,s.def));}return p;}
}
