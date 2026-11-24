#pragma once
#include "Plugin.h"
class SpiritLook final:public juce::LookAndFeel_V4{public:SpiritLook();void drawRotarySlider(juce::Graphics&,int,int,int,int,float,float,float,juce::Slider&)override;void drawButtonBackground(juce::Graphics&,juce::Button&,const juce::Colour&,bool,bool)override;void drawButtonText(juce::Graphics&,juce::TextButton&,bool,bool)override;};
class FreeSpiritEditor final:public juce::AudioProcessorEditor,private juce::Timer {
public:explicit FreeSpiritEditor(FreeSpiritProcessor&);~FreeSpiritEditor()override;void resized()override;
private:
 class Surface:public juce::Component{public:explicit Surface(FreeSpiritEditor& e):owner(e){}void paint(juce::Graphics& g)override{owner.draw(g);}FreeSpiritEditor& owner;};
 class Knob:public juce::Slider{public:Knob(FreeSpiritProcessor& p,juce::String i):proc(p),id(i){}void mouseDown(const juce::MouseEvent& e)override;FreeSpiritProcessor& proc;juce::String id;};
 FreeSpiritProcessor& p;SpiritLook look;Surface surface{*this};juce::TooltipWindow tooltips{this,650};
 using SA=juce::AudioProcessorValueTreeState::SliderAttachment;using BA=juce::AudioProcessorValueTreeState::ButtonAttachment;using CA=juce::AudioProcessorValueTreeState::ComboBoxAttachment;
 struct K{juce::String id,name;std::unique_ptr<Knob> slider;std::unique_ptr<SA> attach;juce::Rectangle<int> area;int tab=-1;};std::vector<K> knobs;
 std::vector<std::unique_ptr<juce::TextButton>> buttons;std::vector<std::unique_ptr<BA>> bat;std::array<juce::TextButton*,12> modes{};std::array<juce::TextButton*,7> tabs{};juce::ComboBox division,wave;std::unique_ptr<CA> divAttachment,waveAttachment;juce::TextButton* timing=nullptr;juce::TextButton* fav=nullptr;juce::TextButton* presetLabel=nullptr;juce::TextButton* sync=nullptr;juce::TextButton* link=nullptr;juce::TextButton* tap=nullptr;int selectedTab=0,preset=-1;bool map=false;double lastTap=0;std::unique_ptr<juce::FileChooser> chooser;
 juce::TextButton* button(const juce::String&,juce::Rectangle<int>,std::function<void()>,bool toggle=false,const char* id=nullptr);void knob(const char*,juce::Rectangle<int>,int=-1);void update();void draw(juce::Graphics&);void timerCallback()override;void browse();void settings();void save();void load();void choose(int);void setTab(int);void editTime(bool right);bool isFrench=false;
};
