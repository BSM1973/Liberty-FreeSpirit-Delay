#pragma once
#include "Params.h"
class FreeSpiritProcessor final: public juce::AudioProcessor {
public:
 juce::UndoManager undo;juce::AudioProcessorValueTreeState state;fsd::Core core;std::atomic<float> bpm{120},inputPeak{0},wetPeak{0},outputPeak{0};std::atomic<bool> clear{false},hostTempo{false};
 std::array<std::atomic<int>,std::size(fsd::specs)> cc;std::atomic<int> learn{-1};
 struct Preset{juce::String name,category;std::vector<std::pair<juce::String,float>> values;};std::vector<Preset> presets;juce::StringArray favorites;juce::String presetName{"Custom sound"};float localTempo=120;
 FreeSpiritProcessor();~FreeSpiritProcessor()override=default;
 const juce::String getName()const override{return "FreeSpirit Delay";} bool acceptsMidi()const override{return true;}bool producesMidi()const override{return false;}bool isMidiEffect()const override{return false;}double getTailLengthSeconds()const override{return 30;}
 int getNumPrograms()override{return 1;}int getCurrentProgram()override{return 0;}void setCurrentProgram(int)override{}const juce::String getProgramName(int)override{return {};}void changeProgramName(int,const juce::String&)override{}
 void prepareToPlay(double s,int)override{core.prepare(s);}void releaseResources()override{}bool isBusesLayoutSupported(const BusesLayout& b)const override{return b.getMainInputChannelSet()==b.getMainOutputChannelSet()&&(b.getMainOutputChannelSet()==juce::AudioChannelSet::stereo()||b.getMainOutputChannelSet()==juce::AudioChannelSet::mono());}
 void processBlock(juce::AudioBuffer<float>&,juce::MidiBuffer&)override;void getStateInformation(juce::MemoryBlock&)override;void setStateInformation(const void*,int)override;bool hasEditor()const override{return true;}juce::AudioProcessorEditor* createEditor()override;
 float get(const char* id)const{return state.getRawParameterValue(id)->load();}void set(const juce::String&,float);void reset();void loadPreset(int);void makePresets();void midiLearn(const juce::String& id);void midiClear(const juce::String& id);void tap(float t){manualTempo.store(t);}std::atomic<float> manualTempo{120};
private:fsd::Settings settings()const;std::array<std::atomic<float>*,std::size(fsd::specs)> raw{};
};
