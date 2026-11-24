#include "Editor.h"
namespace {using namespace juce;const Colour bg(0xff10151b),panel(0xff181f27),line(0xff2a3440),fg(0xffe3eaf1),muted(0xff8595a6),dim(0xff536576),mint(0xff71e2ca),purple(0xffb7a2f4),gold(0xffefb86e);constexpr int W=1502,H=992;
void txt(Graphics& g,String t,Rectangle<int> r,float n=13,Colour c=muted,Justification j=Justification::centredLeft,bool bold=false){g.setColour(c);g.setFont(Font(n,bold?Font::bold:Font::plain));g.drawFittedText(t,r,j,1);}
void box(Graphics& g,Rectangle<float> r,Colour c=panel){g.setColour(c);g.fillRoundedRectangle(r,11);g.setColour(line);g.drawRoundedRectangle(r,11,1.5f);}
void rule(Graphics& g,int x,int y,int x2,int y2){g.setColour(line);g.drawLine(float(x),float(y),float(x2),float(y2));}

// UI translations are independent of parameter IDs and preset identities.
juce::String fsText(const juce::String& s,bool fr){if(!fr)return s;static const std::pair<const char*,const char*> pairs[]={
{"Digital","Numérique"},
{"Analog","Analogique"},
{"Tape","Bande"},
{"Stereo","Stéréo"},
{"Multi-Tap","Multi-échos"},
{"Reverse","Inversé"},
{"Granular / Diffuse","Granulaire / Diffus"},
{"Modulated","Modulé"},
{"Unsaved changes","Son personnalisé"},
{"Bypass","Contourner"},
{"TIMING MAP","CARTE RYTHMIQUE"},
{"STEREO REPEATS","ÉCHOS STÉRÉO"},
{"Sync","Synchro"},
{"Link","Lier"},
{"TAP TEMPO","TAPER TEMPO"},
{"Edit L","Temps G"},
{"Character","Caractère"},
{"Filters","Filtres"},
{"Dynamics","Dynamique"},
{"Taps","Échos"},
{"Hold / Freeze","Maintien / Gel"},
{"Mute","Muet"},
{"Wet solo","Échos seuls"},
{"Clear echoes","Effacer les échos"},
{"100 FACTORY SOUNDS  ›","100 SONS D’USINE  ›"},
{"LFO Sync","Synchro LFO"},
{"Sine","Sinus"},
{"Triangle","Triangle"},
{"Saw","Dent de scie"},
{"Square","Carrée"},
{"1 bar","1 mesure"},
{"2 bars","2 mesures"},
{"Feedback","Rétroaction"},
{"Dry / Wet","Sec / Effet"},
{"Stereo width","Largeur stéréo"},
{"Output","Sortie"},
{"Input","Entrée"},
{"Drive","Gain"},
{"Tone","Tonalité"},
{"Wear","Usure"},
{"Wow","Pleurage"},
{"Flutter","Scintillement"},
{"High-pass","Passe-haut"},
{"Low-pass","Passe-bas"},
{"Resonance","Résonance"},
{"Rate","Vitesse"},
{"Depth","Profondeur"},
{"Duck","Ducking"},
{"Threshold","Seuil"},
{"Attack","Attaque"},
{"Release","Relâchement"},
{"Grain size","Taille grain"},
{"Bit depth","Résolution"},
{"Pitch","Hauteur"},
{"Spread","Écartement"},
{"Pan","Panorama"},
{"Crossfeed","Croisement"},
{"Ceiling","Plafond"},
{"D E L A Y   E N G I N E","M O T E U R   D ’ É C H O"},
{"V I N T A G E","V I N T A G E"},
{"C H A R A C T E R","C A R A C T È R E"},
{"INPUT","ENTRÉE"},
{"REPEATS","ÉCHOS"},
{"OUTPUT","SORTIE"},
{"D E L A Y   T I M E","T E M P S   D ’ É C H O"},
{"Following project tempo","Tempo du projet"},
{"Local tempo / Tap to set","Tempo local / Taper"},
{"M A K E   I T   Y O U R S","À   V O T R E   M A N I È R E"},
{"F I N E   T U N E","R É G L A G E S"},
{"FREEDOM IN EVERY REPEAT.","LA LIBERTÉ À CHAQUE ÉCHO."},
{"FREE YOUR SOUND.","LIBÉREZ VOTRE SON."},
{"DRAG TO ADJUST   ·   CLICK VALUE TO EDIT   ·   DOUBLE-CLICK TO RESET   ·   RIGHT-CLICK MIDI LEARN","GLISSER : RÉGLER   ·   CLIC : SAISIR   ·   DOUBLE-CLIC : RÉINITIALISER   ·   CLIC DROIT : MIDI LEARN"},
{"Pure and precise echoes.","Des échos purs et précis."},
{"Warm, softened repeats.","Des répétitions chaudes et douces."},
{"Magnetic warmth, gentle drift,\nand imperfect motion.","Chaleur magnétique, dérive douce\net mouvement imparfait."},
{"Alternating stereo echoes.","Des échos stéréo alternés."},
{"Independent stereo timing.","Des temps stéréo indépendants."},
{"Short and focused echoes.","Des échos courts et ciblés."},
{"Four rhythmic repeat taps.","Quatre échos rythmiques."},
{"Reversed delay windows.","Des répétitions inversées."},
{"Layered, diffuse textures.","Des textures diffuses et superposées."},
{"Bit-reduced repeat character.","Des répétitions à résolution réduite."},
{"Moving, modulated echoes.","Des échos modulés en mouvement."},
{"Pitch-shifted feedback.","Une rétroaction transposée."},
{"A little imperfection.","Un peu d’imperfection."},
{"Sculpt every repeat.","Sculptez chaque écho."},
{"Let the echoes move.","Animez vos échos."},
{"Make room for the source.","Libérez de la place."},
{"Four independent taps.","Quatre échos indépendants."},
{"Explore new textures.","Explorez de nouvelles textures."},
{"Shape the stereo field.","Sculptez le champ stéréo."},
{"Shape the character of every repeat.\nTape drift is active in Tape mode.","Sculptez le caractère des répétitions.\nLa dérive est active en mode Bande."},
{"Filter the feedback loop and set safety.","Filtrez la boucle et réglez la sécurité."},
{"Set the waveform, rate and depth.","Réglez la forme, la vitesse et la profondeur."},
{"Ducking reacts to the input envelope.","Le ducking réagit à l’enveloppe d’entrée."},
{"Time ratios, levels and pan per tap.","Ratio, niveau et panorama par écho."},
{"Grains, diffusion, bits and pitch.","Grains, diffusion, résolution et hauteur."},
{"Width, spread, pan and crossfeed.","Largeur, écartement, panorama et croisement."},
{"Vocals","Voix"},
{"Guitar","Guitare"},
{"Drums","Batterie"},
{"Bass","Basse"},
{"Keys","Claviers"},
{"Synths","Synthés"},
{"Rhythmic","Rythmique"},
{"Vintage","Vintage"},
{"Ambient","Ambiance"},
{"Experimental","Expérimental"},
{"Sound Design","Design sonore"},
{"All","Tous"},
{"Factory","Usine"},
{"User","Utilisateur"},
{"Favorites","Favoris"},
{"Preset browser","Navigateur de presets"},
{"Search name or category…","Rechercher un nom ou une catégorie…"},
{"Save as…","Enregistrer sous…"},
{"Rename…","Renommer…"},
{"Delete…","Supprimer…"},
{"Import…","Importer…"},
{"Export…","Exporter…"},
{"Close","Fermer"},
{"Previous","Précédent"},
{"Next","Suivant"},
{"No matching presets","Aucun preset correspondant"},
{"Name","Nom"},
{"Category","Catégorie"},
{"Library","Bibliothèque"},
{"Save user preset","Enregistrer un preset utilisateur"},
{"Rename user preset","Renommer le preset utilisateur"},
{"Enter a unique name","Saisissez un nom unique"},
{"Apply","Appliquer"},
{"Cancel","Annuler"},
{"Delete user preset","Supprimer le preset utilisateur"},
{"Delete this preset permanently?","Supprimer définitivement ce preset ?"},
{"Preset error","Erreur de preset"},
{"Invalid or duplicate name","Nom invalide ou déjà utilisé"},
{"Unable to write preset","Impossible d’enregistrer le preset"},
{"Unable to read preset","Impossible de lire le preset"},
{"Unable to delete preset","Impossible de supprimer le preset"},
{"Safety limiter","Limiteur de sécurité"},
{"Save preset...","Enregistrer le preset…"},
{"Load preset...","Charger un preset…"},
{"Reset to defaults","Réinitialiser les réglages"},
{"Clear MIDI mapping","Effacer l’affectation MIDI"},
{"Stereo ratio","Ratio stéréo"},
{"Delay time","Temps d’écho"},
{"Enter a ratio from 0.25 to 4.00","Saisissez un ratio de 0,25 à 4,00"},
{"Enter milliseconds from 1 to 8000","Saisissez un temps de 1 à 8000 ms"},
{"Save FreeSpirit preset","Enregistrer le preset FreeSpirit"},
{"Load FreeSpirit preset","Charger un preset FreeSpirit"},
{"Undo","Annuler"},
{"Redo","Rétablir"},
{"Reset","Réinitialiser"},
{"Settings","Réglages"},
{"Toggle favorite","Basculer le favori"},
{"Switch language","Changer la langue"},
{"Double-click reset","Double-clic : réinitialiser"},
{"Right-click MIDI Learn","Clic droit : MIDI Learn"},
{"Selected","Sélectionné"},
{"Tap 1 time","Écho 1 temps"},
{"Tap 1 level","Écho 1 niveau"},
{"Tap 1 pan","Écho 1 pan"},
{"Tap 2 time","Écho 2 temps"},
{"Tap 2 level","Écho 2 niveau"},
{"Tap 2 pan","Écho 2 pan"},
{"Tap 3 time","Écho 3 temps"},
{"Tap 3 level","Écho 3 niveau"},
{"Tap 3 pan","Écho 3 pan"},
{"Tap 4 time","Écho 4 temps"},
{"Tap 4 level","Écho 4 niveau"},
{"Tap 4 pan","Écho 4 pan"}
};for(const auto& pair:pairs)if(s==juce::String::fromUTF8(pair.first))return juce::String::fromUTF8(pair.second);return s;}
juce::File fsHome(){return juce::File::getSpecialLocation(juce::File::userApplicationDataDirectory).getChildFile("Liberty Music Software").getChildFile("FreeSpirit Delay");}
juce::File fsLanguage(){return fsHome().getChildFile("language.txt");}
juce::File fsUserDir(){return fsHome().getChildFile("Presets");}
String dbText(float v){return v<.00001f?String::fromUTF8("−∞ dB"):String(20*std::log10(v),1)+" dB";}
}
SpiritLook::SpiritLook(){setColour(juce::Slider::textBoxTextColourId,fg);setColour(juce::Slider::textBoxBackgroundColourId,juce::Colours::transparentBlack);setColour(juce::Slider::textBoxOutlineColourId,juce::Colours::transparentBlack);setColour(juce::ComboBox::backgroundColourId,panel);setColour(juce::ComboBox::outlineColourId,line);setColour(juce::ComboBox::textColourId,fg);setColour(juce::PopupMenu::backgroundColourId,panel);setColour(juce::PopupMenu::textColourId,fg);setColour(juce::PopupMenu::highlightedBackgroundColourId,line);}
void SpiritLook::drawRotarySlider(juce::Graphics& g,int x,int y,int w,int h,float v,float a,float b,juce::Slider& s){using namespace juce;float rad=std::min(w,h)*.40f,cx=x+w*.5f,cy=y+h*.5f;auto id=s.getName();auto color=id=="mix"?purple:(id=="feedback"||id=="width"||id=="output"?mint:gold);auto arc=[&](float r,float end,Colour c,float thick){Path q;q.addCentredArc(cx,cy,r,r,0,a,end,true);g.setColour(c);g.strokePath(q,PathStrokeType(thick,PathStrokeType::curved,PathStrokeType::rounded));};arc(rad,b,line,4);arc(rad,a+v*(b-a),color,4);g.setColour(bg);g.fillEllipse(cx-rad+9,cy-rad+9,(rad-9)*2,(rad-9)*2);g.setColour(line);g.drawEllipse(cx-rad+9,cy-rad+9,(rad-9)*2,(rad-9)*2,2);g.setColour(Colour(0xff202832));g.fillEllipse(cx-rad+15,cy-rad+15,std::max(2.f,rad-15)*2,std::max(2.f,rad-15)*2);float ang=a+v*(b-a);g.setColour(color);g.drawLine(cx+std::sin(ang)*std::max(1.f,rad-23),cy-std::cos(ang)*std::max(1.f,rad-23),cx+std::sin(ang)*std::max(2.f,rad-15),cy-std::cos(ang)*std::max(2.f,rad-15),3);g.setColour(line.brighter(.3f));g.fillEllipse(cx-3,cy-3,6,6);}
void SpiritLook::drawButtonBackground(juce::Graphics& g,juce::Button& b,const juce::Colour&,bool over,bool down){auto r=b.getLocalBounds().toFloat().reduced(1);bool active=b.getToggleState();bool flat=bool(b.getProperties().getWithDefault("flat",false));if(!flat||active||over){g.setColour(active?juce::Colour(0xff203632):over?juce::Colour(0xff25313c):juce::Colour(0xff1c252e));g.fillRoundedRectangle(r,5);g.setColour(active?mint.withAlpha(.38f):line);g.drawRoundedRectangle(r,5,down?2:1);}}
void SpiritLook::drawButtonText(juce::Graphics& g,juce::TextButton& b,bool,bool){auto r=b.getLocalBounds().reduced(8,0);bool left=bool(b.getProperties().getWithDefault("left",false));txt(g,b.getButtonText(),r,float(int(b.getProperties().getWithDefault("font",14))),b.getToggleState()?mint:muted,left?juce::Justification::centredLeft:juce::Justification::centred,true);}

void SpiritLook::drawPopupMenuBackground(juce::Graphics& g,int w,int h){using namespace juce;g.fillAll(Colour(0xff111820));auto r=Rectangle<float>(1,1,float(w-2),float(h-2));g.setColour(line);g.drawRoundedRectangle(r,6,1.4f);}
void SpiritLook::getIdealPopupMenuItemSize(const juce::String& s,bool sep,int standard,int& w,int& h){juce::LookAndFeel_V4::getIdealPopupMenuItemSize(s,sep,standard,w,h);h=sep?10:juce::jmax(34,h+8);w=juce::jmax(180,w+24);}
void SpiritLook::drawPopupMenuItem(juce::Graphics& g,const juce::Rectangle<int>& a,bool sep,bool active,bool hi,bool tick,bool sub,const juce::String& t,const juce::String& shortcut,const juce::Drawable* icon,const juce::Colour*){using namespace juce;if(sep){g.setColour(line);g.drawHorizontalLine(a.getCentreY(),float(a.getX()+12),float(a.getRight()-12));return;}auto r=a.reduced(5,2);if(hi&&active){g.setColour(Colour(0xff203632));g.fillRoundedRectangle(r.toFloat(),5);g.setColour(mint);g.fillRoundedRectangle(float(r.getX()),float(r.getY()+5),3.f,float(r.getHeight()-10),1.5f);}auto ink=active?(hi||tick?mint:fg):dim;auto left=r.removeFromLeft(30);if(tick)txt(g,String::fromUTF8("✓"),left,15,mint,Justification::centred,true);else if(icon)icon->drawWithin(g,left.reduced(5).toFloat(),RectanglePlacement::centred,1.f);if(sub){auto right=r.removeFromRight(22);txt(g,String::fromUTF8("›"),right,19,muted,Justification::centred,true);}if(shortcut.isNotEmpty())txt(g,shortcut,r.removeFromRight(60),11,muted,Justification::centredRight);txt(g,t,r.reduced(4,0),14,ink);}
void SpiritLook::drawComboBox(juce::Graphics& g,int w,int h,bool down,int,int,int,int,juce::ComboBox& b){using namespace juce;auto r=Rectangle<float>(1,1,float(w-2),float(h-2));g.setColour(Colour(0xff141c24));g.fillRoundedRectangle(r,6);g.setColour((down||b.isMouseOver())?mint:line);g.drawRoundedRectangle(r,6,1.2f);Path p;p.startNewSubPath(float(w-19),float(h)*.46f);p.lineTo(float(w-13),float(h)*.60f);p.lineTo(float(w-7),float(h)*.46f);g.setColour(mint);g.strokePath(p,PathStrokeType(1.8f));}

void FreeSpiritEditor::Knob::mouseDown(const juce::MouseEvent& e){if(e.mods.isPopupMenu()){juce::PopupMenu m;m.setLookAndFeel(&getLookAndFeel());m.addItem(1,"MIDI Learn");m.addItem(2,fsText("Clear MIDI mapping",french));auto safe=juce::Component::SafePointer<Knob>(this);m.showMenuAsync(juce::PopupMenu::Options().withTargetComponent(this),[safe](int n){if(safe!=nullptr){if(n==1)safe->proc.midiLearn(safe->id);if(n==2)safe->proc.midiClear(safe->id);}});return;}juce::Slider::mouseDown(e);}
juce::TextButton* FreeSpiritEditor::button(const juce::String& t,juce::Rectangle<int> r,std::function<void()> f,bool tog,const char* id){auto b=std::make_unique<juce::TextButton>(t);auto* q=b.get();surface.addAndMakeVisible(*q);q->setBounds(r);q->setClickingTogglesState(tog);q->onClick=std::move(f);q->getProperties().set("en",t);q->setTooltip(t);if(id)bat.push_back(std::make_unique<BA>(p.state,id,*q));buttons.push_back(std::move(b));return q;}
void FreeSpiritEditor::knob(const char* id,juce::Rectangle<int> r,int tab){for(auto& spec:fsd::specs)if(juce::String(id)==spec.id){K k;k.id=id;k.name=spec.name;k.area=r;k.tab=tab;k.slider=std::make_unique<Knob>(p,k.id,isFrench);auto& s=*k.slider;s.setName(id);s.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);s.setTextBoxStyle(juce::Slider::TextBoxBelow,false,r.getWidth()-8,25);s.setRotaryParameters(juce::MathConstants<float>::pi*1.22f,juce::MathConstants<float>::pi*2.78f,true);s.setDoubleClickReturnValue(true,spec.def);s.setTextValueSuffix(spec.unit);s.setTooltip(k.name+" | Double-click reset | Right-click MIDI Learn");surface.addAndMakeVisible(s);s.setBounds(r.withTrimmedTop(20));k.attach=std::make_unique<SA>(p.state,id,s);knobs.push_back(std::move(k));return;}}

class FreeSpiritEditor::Browser final:public juce::Component {
 using S=juce::String;using B=juce::TextButton;using F=juce::File;
 struct Row{int factory=-1;F file;S name,category;};
 FreeSpiritEditor& e;juce::TextEditor search;std::vector<std::unique_ptr<B>> owned;
 std::array<B*,12> categories{};std::array<B*,4> filters{};std::array<B*,10> rows{},stars{};B *prev=nullptr,*next=nullptr,*rename=nullptr,*remove=nullptr;std::vector<Row> results;int category=0,filter=0,page=0;F selectedUser;
 static constexpr const char* cats[]={"All","Vocals","Guitar","Drums","Bass","Keys","Synths","Rhythmic","Vintage","Ambient","Experimental","Sound Design"};
 static constexpr const char* scopes[]={"All","Factory","User","Favorites"};
 S tr(const S& s)const{return fsText(s,e.isFrench);}
 B* add(const S& en,juce::Rectangle<int> r,std::function<void()> f,bool left=false){auto b=std::make_unique<B>(en);auto* x=b.get();x->getProperties().set("en",en);x->getProperties().set("left",left);x->getProperties().set("font",15);x->setBounds(r);x->onClick=std::move(f);addAndMakeVisible(*x);owned.push_back(std::move(b));return x;}
 S key(const Row& r)const{return r.factory>=0?r.name:"user:"+r.name;}
 bool selected(const Row& r)const{return r.factory>=0?e.preset==r.factory&&e.p.presetName==r.name:selectedUser==r.file&&e.p.presetName==r.name;}
 void error(const S& m){juce::AlertWindow::showMessageBoxAsync(juce::MessageBoxIconType::WarningIcon,tr("Preset error"),tr(m),tr("Close"),this);}
 void select(int i){int n=page*10+i;if(n>=int(results.size()))return;auto r=results[size_t(n)];if(r.factory>=0){selectedUser=F{};e.choose(r.factory);}else{juce::MemoryBlock data;if(!r.file.loadFileAsData(data)){error("Unable to read preset");return;}auto favorites=e.p.favorites;std::array<int,std::size(fsd::specs)> mappings{};for(size_t k=0;k<mappings.size();++k)mappings[k]=e.p.cc[k].load();e.p.setStateInformation(data.getData(),int(data.getSize()));e.p.favorites=favorites;for(size_t k=0;k<mappings.size();++k)e.p.cc[k]=mappings[k];e.p.presetName=r.name;e.preset=-1;selectedUser=r.file;e.update();}refresh();}
 void star(int i){int n=page*10+i;if(n>=int(results.size()))return;auto k=key(results[size_t(n)]);if(e.p.favorites.contains(k))e.p.favorites.removeString(k);else e.p.favorites.add(k);e.update();refresh();}
 void nameDialog(bool renaming){if(renaming&&!selectedUser.existsAsFile())return;auto* w=new juce::AlertWindow(tr(renaming?"Rename user preset":"Save user preset"),tr("Enter a unique name"),juce::MessageBoxIconType::NoIcon,this);w->setLookAndFeel(&e.look);w->addTextEditor("name",renaming?selectedUser.getFileNameWithoutExtension():(e.p.presetName=="Custom sound"?S():e.p.presetName+" User"));w->addButton(tr("Apply"),1);w->addButton(tr("Cancel"),0);auto safe=juce::Component::SafePointer<Browser>(this);w->enterModalState(true,juce::ModalCallbackFunction::create([safe,w,renaming](int n){if(safe==nullptr||n!=1)return;auto name=w->getTextEditorContents("name").trim();auto dir=fsUserDir();auto f=dir.getChildFile(name+".fspreset");bool duplicate=false;for(auto& p:safe->e.p.presets)duplicate|=p.name.equalsIgnoreCase(name);if(name.isEmpty()||name.length()>80||F::createLegalFileName(name)!=name||name=="."||name==".."||duplicate||(f.exists()&&(!renaming||f!=safe->selectedUser))){safe->error("Invalid or duplicate name");return;}if(dir.createDirectory().failed()){safe->error("Unable to write preset");return;}if(renaming){auto old=safe->selectedUser;if(f!=old&&!old.moveFileTo(f)){safe->error("Unable to write preset");return;}auto k="user:"+old.getFileNameWithoutExtension();if(safe->e.p.favorites.contains(k)){safe->e.p.favorites.removeString(k);safe->e.p.favorites.addIfNotAlreadyThere("user:"+name);}}else{juce::MemoryBlock data;safe->e.p.getStateInformation(data);if(!f.replaceWithData(data.getData(),data.getSize())){safe->error("Unable to write preset");return;}}safe->selectedUser=f;safe->e.p.presetName=name;safe->e.preset=-1;safe->filter=2;safe->category=0;safe->page=0;safe->search.clear();safe->e.update();safe->refresh();}),true);}
 void deleteDialog(){if(!selectedUser.existsAsFile())return;auto file=selectedUser;auto* w=new juce::AlertWindow(tr("Delete user preset"),tr("Delete this preset permanently?"),juce::MessageBoxIconType::WarningIcon,this);w->setLookAndFeel(&e.look);w->addButton(tr("Delete…"),1);w->addButton(tr("Cancel"),0);auto safe=juce::Component::SafePointer<Browser>(this);w->enterModalState(true,juce::ModalCallbackFunction::create([safe,file](int n){if(safe==nullptr||n!=1)return;if(!file.deleteFile()){safe->error("Unable to delete preset");return;}safe->e.p.favorites.removeString("user:"+file.getFileNameWithoutExtension());if(safe->e.p.presetName==file.getFileNameWithoutExtension())safe->e.p.presetName="Custom sound";safe->selectedUser=F{};safe->e.update();safe->refresh();}),true);}
 public:
 explicit Browser(FreeSpiritEditor& owner):e(owner){setBounds(0,0,W,H);setInterceptsMouseClicks(true,true);addAndMakeVisible(search);search.setBounds(479,203,513,46);search.setFont(juce::Font(18.f));search.setColour(juce::TextEditor::backgroundColourId,juce::Colour(0xff111820));search.setColour(juce::TextEditor::textColourId,fg);search.setColour(juce::TextEditor::outlineColourId,line);search.setColour(juce::TextEditor::focusedOutlineColourId,mint);search.onTextChange=[this]{page=0;refresh();};
 add("Close",{1144,154,130,40},[this]{setVisible(false);});
 for(int i=0;i<4;++i)filters[i]=add(scopes[i],{479+i*195,263,184,38},[this,i]{filter=i;category=0;page=0;refresh();});
 for(int i=0;i<12;++i)categories[i]=add(cats[i],{230,225+i*43,225,39},[this,i]{category=i;if(filter==2&&i>0)filter=0;page=0;refresh();},true);
 for(int i=0;i<10;++i){rows[i]=add("",{479,345+i*43,724,39},[this,i]{select(i);},true);stars[i]=add("",{1210,345+i*43,54,39},[this,i]{star(i);});}
 prev=add("Previous",{480,786,145,39},[this]{if(page>0){--page;refresh();}});next=add("Next",{1119,786,145,39},[this]{if((page+1)*10<int(results.size())){++page;refresh();}});
 add("Save as…",{230,756,225,39},[this]{nameDialog(false);});rename=add("Rename…",{230,801,109,39},[this]{nameDialog(true);});remove=add("Delete…",{344,801,111,39},[this]{deleteDialog();});add("Import…",{230,846,109,35},[this]{e.load();});add("Export…",{344,846,111,35},[this]{e.save();});
 setVisible(false);refresh();
 }
 void open(){setVisible(true);toFront(true);auto f=fsUserDir().getChildFile(e.p.presetName+".fspreset");selectedUser=f.existsAsFile()&&e.preset<0?f:F{};refresh();search.grabKeyboardFocus();}
 void refresh(){search.setTextToShowWhenEmpty(tr("Search name or category…"),muted);for(auto& b:owned){auto en=b->getProperties().getWithDefault("en","").toString();if(en.isNotEmpty())b->setButtonText(tr(en));}auto term=search.getText().trim();results.clear();auto append=[&](Row r){if(filter==3&&!e.p.favorites.contains(key(r)))return;if(category>0&&r.category!=cats[category])return;if(term.isNotEmpty()&&!r.name.containsIgnoreCase(term)&&!r.category.containsIgnoreCase(term)&&!tr(r.category).containsIgnoreCase(term))return;results.push_back(std::move(r));};if(filter!=2)for(size_t i=0;i<e.p.presets.size();++i){auto& p=e.p.presets[i];append({int(i),{},p.name,p.category});}if(filter!=1&&category==0){auto files=fsUserDir().findChildFiles(F::findFiles,false,"*.fspreset");std::sort(files.begin(),files.end(),[](const F& a,const F& b){return a.getFileName().compareNatural(b.getFileName())<0;});for(const auto& f:files)append({-1,f,f.getFileNameWithoutExtension(),"User"});}
 page=juce::jlimit(0,juce::jmax(0,(int(results.size())-1)/10),page);for(int i=0;i<4;++i)filters[i]->setToggleState(i==filter,juce::dontSendNotification);for(int i=0;i<12;++i)categories[i]->setToggleState(i==category,juce::dontSendNotification);
 for(int i=0;i<10;++i){int n=page*10+i;bool show=n<int(results.size());rows[i]->setVisible(show);stars[i]->setVisible(show);if(show){auto& r=results[size_t(n)];rows[i]->setButtonText(r.name+"     /     "+tr(r.category));rows[i]->setTooltip(r.name);rows[i]->setToggleState(selected(r),juce::dontSendNotification);bool f=e.p.favorites.contains(key(r));stars[i]->setButtonText(S::fromUTF8(f?"★":"☆"));stars[i]->setToggleState(f,juce::dontSendNotification);stars[i]->setTooltip(tr("Toggle favorite"));}}
 prev->setEnabled(page>0);next->setEnabled((page+1)*10<int(results.size()));rename->setEnabled(selectedUser.existsAsFile()&&e.p.presetName==selectedUser.getFileNameWithoutExtension());remove->setEnabled(rename->isEnabled());repaint();
 }
 void step(int delta){if(results.empty())return;int pos=-1;for(size_t i=0;i<results.size();++i)if(selected(results[i])){pos=int(i);break;}int n=pos<0?(delta>0?0:int(results.size())-1):(pos+delta+int(results.size()))%int(results.size());page=n/10;select(n%10);}
 bool keyPressed(const juce::KeyPress& k)override{if(k==juce::KeyPress::escapeKey){setVisible(false);return true;}return false;}
 void paint(juce::Graphics& g)override{using namespace juce;g.fillAll(Colours::black.withAlpha(.64f));auto r=Rectangle<float>(202,125,1096,788);ColourGradient grad(Colour(0xff202b36),r.getX(),r.getY(),Colour(0xff121a22),r.getX(),r.getBottom(),false);g.setGradientFill(grad);g.fillRoundedRectangle(r,15);g.setColour(mint.withAlpha(.40f));g.drawRoundedRectangle(r,15,1.5f);txt(g,tr("Preset browser"),{230,147,850,45},28,fg,Justification::centredLeft,true);txt(g,tr("Library"),{230,192,225,31},13,gold,Justification::centredLeft,true);rule(g,466,201,466,886);rule(g,478,318,1264,318);txt(g,tr("Name")+"  /  "+tr("Category"),{490,318,740,27},12,muted);int count=int(results.size());txt(g,S(count)+" presets  •  "+S(page+1)+" / "+S(juce::jmax(1,(count+9)/10)),{630,786,480,39},15,mint,Justification::centred);if(results.empty())txt(g,tr("No matching presets"),{479,380,785,100},20,muted,Justification::centred);}
};

FreeSpiritEditor::FreeSpiritEditor(FreeSpiritProcessor& proc):AudioProcessorEditor(&proc),p(proc){isFrench=fsLanguage().loadFileAsString().trim()!="EN";setLookAndFeel(&look);addAndMakeVisible(surface);surface.setSize(W,H);setResizable(true,true);setResizeLimits(900,595,2253,1488);if(auto* c=getConstrainer())c->setFixedAspectRatio(double(W)/H);setSize(1126,744);
 const char* symbols[]={"~","∿","◎","↔","≋","▥","▤","↶","∴","⌁","∿","✧"};for(int i=0;i<12;i++){modes[i]=button(juce::String::fromUTF8(symbols[i])+"   "+fsd::modes[i],{39,205+39*i,210,36},[this,i]{p.set("mode",float(i));if(i==6)setTab(4);update();});modes[i]->getProperties().set("flat",true);modes[i]->getProperties().set("left",true);}
 button(juce::String::fromUTF8("‹"),{460,22,36,60},[this]{stepPreset(-1);});presetLabel=button("Unsaved changes",{498,22,321,60},[this]{browse();});presetLabel->getProperties().set("left",true);button(juce::String::fromUTF8("▦"),{820,22,36,60},[this]{browse();});button(juce::String::fromUTF8("›"),{858,22,37,60},[this]{stepPreset(1);});fav=button(juce::String::fromUTF8("☆"),{896,22,44,60},[this]{auto key=p.presetName;if(preset<0&&fsUserDir().getChildFile(key+".fspreset").existsAsFile())key="user:"+key;if(p.favorites.contains(key))p.favorites.removeString(key);else p.favorites.add(key);update();if(browser)browser->refresh();});
 language=button("FR / EN",{1044,33,128,36},[this]{changeLanguage();});language->getProperties().set("font",15);button(juce::String::fromUTF8("↶"),{1185,33,42,36},[this]{p.undo.undo();})->getProperties().set("flat",true);button(juce::String::fromUTF8("↷"),{1233,33,42,36},[this]{p.undo.redo();})->getProperties().set("flat",true);button(juce::String::fromUTF8("⟲"),{1278,33,42,36},[this]{p.reset();preset=-1;})->getProperties().set("flat",true);button("Bypass",{1346,33,79,36},{},true,"bypass");button(juce::String::fromUTF8("⚙"),{1432,33,42,36},[this]{settings();})->getProperties().set("flat",true);
 timing=button("TIMING MAP",{477,151,114,30},[this]{map=!map;update();});timing->getProperties().set("flat",true);button("STEREO REPEATS",{304,151,164,30},[this]{map=false;update();})->getProperties().set("flat",true);
 sync=button("Sync",{550,428,63,35},{},true,"sync");link=button("Link",{621,428,60,35},{},true,"link");tap=button("TAP TEMPO",{584,578,97,35},[this]{double now=juce::Time::getMillisecondCounterHiRes();if(lastTap>0&&now-lastTap>=150&&now-lastTap<=3000)p.tap(float(60000/(now-lastTap)));lastTap=now;});
 for(int i=0;i<int(fsd::divisions.size());++i)division.addItem(fsd::divisions[size_t(i)],i+1);surface.addAndMakeVisible(division);division.setBounds(334,478,151,42);divAttachment=std::make_unique<CA>(p.state,"division",division);
 button("Edit L",{334,478,151,42},[this]{editTime(false);})->getProperties().set("timeL",true);button("1 : 1",{530,478,151,42},[this]{editTime(true);})->getProperties().set("timeR",true);
 knob("feedback",{775,434,132,190});knob("mix",{995,434,132,190});knob("width",{1214,463,94,139});knob("output",{1328,463,94,139});
 const char* ts[]={"Character","Filters","Modulation","Dynamics","Taps","Texture","Stereo"};for(int i=0;i<7;i++){tabs[i]=button(ts[i],{304+109*i,662,106,40},[this,i]{setTab(i);});tabs[i]->getProperties().set("flat",true);}
 auto row=[&](int t,std::initializer_list<const char*> ids){int i=0;for(auto id:ids)knob(id,{790+112*i++,724,98,144},t);};row(0,{"saturation","drive","tone","wear","wow","flutter"});row(1,{"hp","lp","res","input","safe"});row(2,{"rate","depth"});row(3,{"duck","threshold","attack","release"});row(5,{"grain","diffuse","bits","shift"});row(6,{"width","spread","pan","cross"});
 for(int i=0;i<4;i++){for(int j=0;j<3;j++){const char* prefixes[]={"tapTime","tapLevel","tapPan"};auto id=juce::String(prefixes[j])+juce::String(i+1);knob(id.toRawUTF8(),{690+i*187+j*61,727,58,133},4);}}
 wave.addItemList(juce::StringArray{"Sine","Triangle","Saw","Square"},1);surface.addAndMakeVisible(wave);wave.setBounds(1033,750,128,35);waveAttachment=std::make_unique<CA>(p.state,"wave",wave);button("LFO Sync",{1180,750,105,35},{},true,"modSync")->getProperties().set("tab",2);
 button("Hold / Freeze",{43,787,201,40},{},true,"freeze");button("Mute",{43,836,97,35},{},true,"mute");button("Wet solo",{147,836,97,35},{},true,"solo");button("Clear echoes",{43,877,201,35},[this]{p.clear=true;})->getProperties().set("flat",true);button(juce::String::fromUTF8("100 FACTORY SOUNDS  ›"),{1285,952,187,36},[this]{browse();})->getProperties().set("flat",true);browser=std::make_unique<Browser>(*this);surface.addChildComponent(*browser);refreshLanguage();setTab(0);startTimerHz(24);update();}
FreeSpiritEditor::~FreeSpiritEditor(){stopTimer();browser.reset();juce::PopupMenu::dismissAllActiveMenus();setLookAndFeel(nullptr);surface.setLookAndFeel(nullptr);}
void FreeSpiritEditor::resized(){surface.setTransform(juce::AffineTransform::scale(float(getWidth())/W,float(getHeight())/H));}
void FreeSpiritEditor::setTab(int t){selectedTab=t;for(auto& k:knobs)k.slider->setVisible(k.tab<0||k.tab==t);wave.setVisible(t==2);for(auto& b:buttons)if(b->getProperties().contains("tab"))b->setVisible(int(b->getProperties()["tab"])==t);update();}
void FreeSpiritEditor::choose(int i){p.loadPreset(i);preset=i;update();}
void FreeSpiritEditor::update(){int m=int(p.get("mode"));for(int i=0;i<12;i++)if(modes[i])modes[i]->setToggleState(i==m,juce::dontSendNotification);for(int i=0;i<7;i++)if(tabs[i])tabs[i]->setToggleState(i==selectedTab,juce::dontSendNotification);if(timing)timing->setToggleState(map,juce::dontSendNotification);if(presetLabel)presetLabel->setButtonText(p.presetName=="Custom sound"?fsText("Unsaved changes",isFrench):p.presetName);if(fav){auto key=p.presetName;if(preset<0&&p.favorites.contains("user:"+key))key="user:"+key;fav->setButtonText(juce::String::fromUTF8(p.favorites.contains(key)?"★":"☆"));}bool sy=p.get("sync")>.5;division.setVisible(sy);for(auto& b:buttons){if(b->getProperties().contains("timeL")){b->setVisible(!sy);b->setButtonText(juce::String(p.get("left"),0)+" ms");}if(b->getProperties().contains("timeR"))b->setButtonText(sy||p.get("link")>.5?"1 : "+juce::String(p.get("ratio"),2):juce::String(p.get("right"),0)+" ms");}surface.repaint();}
void FreeSpiritEditor::timerCallback(){update();}
void FreeSpiritEditor::editTime(bool right){using namespace juce;bool ratio=right&&(p.get("sync")>.5||p.get("link")>.5);String id=ratio?"ratio":right?"right":"left";auto* w=new AlertWindow(fsText(ratio?"Stereo ratio":"Delay time",isFrench),fsText(ratio?"Enter a ratio from 0.25 to 4.00":"Enter milliseconds from 1 to 8000",isFrench),MessageBoxIconType::NoIcon,this);w->setLookAndFeel(&look);w->addTextEditor("value",String(p.get(id.toRawUTF8()),ratio?2:0));w->addButton(fsText("Apply",isFrench),1);w->addButton(fsText("Cancel",isFrench),0);auto safe=Component::SafePointer<FreeSpiritEditor>(this);w->enterModalState(true,ModalCallbackFunction::create([safe,w,id,ratio](int i){if(safe!=nullptr&&i==1){auto value=w->getTextEditorContents("value").replaceCharacter(',', '.').getFloatValue();safe->p.set(id,fsd::clamp(value,ratio?.25f:1.f,ratio?4.f:8000.f));}}),true);}
void FreeSpiritEditor::draw(juce::Graphics& g){using namespace juce;auto txt=[this](Graphics& gr,String t,Rectangle<int> r,float n=13,Colour col=muted,Justification j=Justification::centredLeft,bool bold=false){::txt(gr,fsText(t,isFrench),r,n,col,j,bold);};g.fillAll(bg);g.setColour(Colour(0xff171d25));g.fillRect(0,0,W,109);g.fillRect(0,941,W,51);rule(g,0,108,W,108);rule(g,0,941,W,941);
 Path logo;logo.startNewSubPath(34,63);logo.lineTo(47,38);logo.lineTo(61,63);logo.startNewSubPath(47,63);logo.lineTo(61,38);logo.lineTo(74,63);g.setColour(mint);g.strokePath(logo,PathStrokeType(3));g.setColour(purple);g.drawLine(47,64,62,64,2);txt(g,"L I B E R T Y",{94,19,105,24},13,fg,Justification::centredLeft,true);txt(g,"AUDIO / 01",{194,19,106,24},10,dim);txt(g,"FreeSpirit",{93,43,132,40},29,fg,Justification::centredLeft,true);txt(g,"Delay",{225,43,112,40},29,muted);
 box(g,{27,138,234,783});txt(g,"D E L A Y   E N G I N E",{47,151,184,32},12,muted,Justification::centredLeft,true);txt(g,"12",{213,154,27,26},12,muted,Justification::centred);rule(g,28,194,260,194);rule(g,39,683,249,683);int mode=int(p.get("mode"));const char* descriptions[]={"Pure and precise echoes.","Warm, softened repeats.","Magnetic warmth, gentle drift,\nand imperfect motion.","Alternating stereo echoes.","Independent stereo timing.","Short and focused echoes.","Four rhythmic repeat taps.","Reversed delay windows.","Layered, diffuse textures.","Bit-reduced repeat character.","Moving, modulated echoes.","Pitch-shifted feedback."};txt(g,mode==2||mode==1?"V I N T A G E":"C H A R A C T E R",{48,693,200,26},11,muted);g.setColour(muted);g.setFont(Font(13.f));g.drawFittedText(fsText(String::fromUTF8(descriptions[mode]),isFrench),{48,722,190,43},Justification::topLeft,3);rule(g,28,771,260,771);
 box(g,{283,138,1190,260},Colour(0xff141b22));txt(g,(p.hostTempo.load()?(isFrench?"HÔTE  ":"HOST  "):"LOCAL  ")+String(p.bpm.load(),1)+" BPM",{1240,150,191,32},13,mint,Justification::centredRight,true);float leftms=p.get("sync")>.5?60000/p.bpm.load()*fsd::beats[size_t(p.get("division"))]:p.get("left");float rightms=p.get("sync")>.5||p.get("link")>.5?leftms*p.get("ratio"):p.get("right");float maxms=std::max(leftms,rightms)*5;float feedback=p.get("feedback")*.01f;
 txt(g,"L",{310,221,30,30},12,mint);txt(g,"R",{310,288,30,30},12,purple);rule(g,352,260,1439,260);rule(g,352,276,1439,276);for(int i=0;i<=5;i++){float x=353+i*211.f;g.setColour(line.withAlpha(.7f));g.drawVerticalLine(int(x),200,332);txt(g,map?String(maxms*i/5,0)+" ms":String(i==0?"1.1":i==4?"2.1":"."+String(i+1)),{int(x)-38,330,76,18},10,dim,Justification::centred);}
 for(int c=0;c<2;c++){auto color=c?purple:mint;float base=c?276.f:260.f;float sign=c?1.f:-1.f;for(int i=0;i<6;i++){float t=(c?rightms:leftms)*i;float x=353+1056*t/std::max(1.f,maxms);float h=i==0?41:std::min(45.f,44.f*std::pow(std::min(.99f,feedback),float(i-1)));if(x>1439)continue;Path cone;cone.startNewSubPath(x-18,base);cone.lineTo(x,base+sign*h);cone.lineTo(x+18,base);cone.closeSubPath();g.setColour(color.withAlpha(.11f));g.fillPath(cone);g.setColour((i?color:fg).withAlpha(i?1.f:0.7f));g.drawLine(x,base,x,base+sign*h,2);if(i)g.fillEllipse(x-3.5f,base+sign*h-3.5f,7,7);}}
 rule(g,305,355,1451,355);float peaks[]={p.inputPeak.load(),p.wetPeak.load(),p.outputPeak.load()};const char* names[]={"INPUT","REPEATS","OUTPUT"};for(int c=0;c<3;c++){int x=305+289*c;txt(g,names[c],{x,361,120,22},11,muted);txt(g,dbText(peaks[c]),{x+150,361,106,22},10,muted,Justification::centredRight);float norm=fsd::clamp((20*std::log10(std::max(.00001f,peaks[c]))+60)/60.f,0.f,1.f);for(int j=0;j<12;j++){g.setColour(j<norm*12?(j>10?gold:mint):line);g.fillRect(x+j*21,388,19,4);}}txt(g,String::fromUTF8(p.get("safety")>.5?(isFrench?"● SÉCURITÉ  ":"● SAFE  "):(isFrench?"○ SÉCURITÉ OFF  ":"○ SAFE OFF  "))+String(p.get("safe"),1)+" dB",{1270,364,181,27},11,mint,Justification::centredRight);
 box(g,{283,413,1190,226});rule(g,703,414,703,638);rule(g,1197,459,1197,601);txt(g,"D E L A Y   T I M E",{305,433,226,26},12,muted,Justification::centredLeft,true);txt(g,"L",{306,479,23,38},12,mint,Justification::centred);txt(g,"R",{502,479,23,38},12,purple,Justification::centred);txt(g,String(leftms,0)+" ms",{335,523,150,28},13,muted,Justification::centred);txt(g,String(rightms,0)+" ms",{530,523,150,28},13,muted,Justification::centred);rule(g,305,565,681,565);txt(g,p.hostTempo.load()?"Following project tempo":"Local tempo / Tap to set",{305,578,266,35},12,muted);
 box(g,{283,655,1190,224});rule(g,284,704,1473,704);g.setColour(mint);g.fillRect(316+109*selectedTab,702,60,2);const char* title[]={"A little imperfection.","Sculpt every repeat.","Let the echoes move.","Make room for the source.","Four independent taps.","Explore new textures.","Shape the stereo field."};const char* desc[]={"Shape the character of every repeat.\nTape drift is active in Tape mode.","Filter the feedback loop and set safety.","Set the waveform, rate and depth.","Ducking reacts to the input envelope.","Time ratios, levels and pan per tap.","Grains, diffusion, bits and pitch.","Width, spread, pan and crossfeed."};txt(g,"M A K E   I T   Y O U R S",{310,735,340,27},11,gold,Justification::centredLeft,true);txt(g,title[selectedTab],{310,765,360,36},21,fg);g.setColour(muted);g.setFont(Font(13.f));g.drawFittedText(fsText(String::fromUTF8(desc[selectedTab]),isFrench),{310,808,356,43},Justification::topLeft,3);txt(g,"F I N E   T U N E",{1340,666,108,31},10,dim,Justification::centredRight);for(auto& k:knobs)if(k.tab<0||k.tab==selectedTab)txt(g,k.name,k.area.withHeight(20),k.tab==4?10:13,muted,Justification::centred,true);
 txt(g,String::fromUTF8(isFrench?"● MOTEUR ACTIF   /   ":"● ENGINE ACTIVE   /   ")+fsText(String(fsd::modes[mode]),isFrench).toUpperCase(),{284,889,340,30},11,mint);txt(g,"FREEDOM IN EVERY REPEAT.",{1165,889,305,30},10,dim,Justification::centredRight);txt(g,"L I B E R T Y",{27,951,100,37},12,muted);txt(g,"FREE YOUR SOUND.",{110,951,160,37},10,dim);txt(g,String::fromUTF8("DRAG TO ADJUST   ·   CLICK VALUE TO EDIT   ·   DOUBLE-CLICK TO RESET   ·   RIGHT-CLICK MIDI LEARN"),{400,951,825,37},10,dim,Justification::centred);
}

void FreeSpiritEditor::browse(){if(browser)browser->open();}
void FreeSpiritEditor::stepPreset(int delta){if(browser&&browser->isVisible()){browser->step(delta);return;}int current=-1;for(size_t i=0;i<p.presets.size();++i)if(p.presets[i].name==p.presetName){current=int(i);break;}int n=int(p.presets.size());if(n>0)choose(current<0?(delta>0?0:n-1):(current+delta+n)%n);}
void FreeSpiritEditor::changeLanguage(){isFrench=!isFrench;fsHome().createDirectory();fsLanguage().replaceWithText(isFrench?"FR":"EN");refreshLanguage();update();}
void FreeSpiritEditor::refreshLanguage(){using namespace juce;for(auto& b:buttons){auto en=b->getProperties().getWithDefault("en","").toString();b->setButtonText(fsText(en,isFrench));b->setTooltip(fsText(en,isFrench));}const char* symbols[]={"~","∿","◎","↔","≋","▥","▤","↶","∴","⌁","∿","✧"};for(int i=0;i<12;++i){auto name=fsText(fsd::modes[i],isFrench);modes[i]->setButtonText(String::fromUTF8(symbols[i])+"   "+name);modes[i]->setTooltip(name);}for(auto& k:knobs)k.slider->setTooltip(fsText(k.name,isFrench)+" | "+fsText("Double-click reset",isFrench)+" | "+fsText("Right-click MIDI Learn",isFrench));if(language){language->setButtonText(isFrench?"FR   /   en":"fr   /   EN");language->setToggleState(isFrench,dontSendNotification);language->setTooltip(fsText("Switch language",isFrench));}const std::pair<const char*,const char*> tips[]={{"↶","Undo"},{"↷","Redo"},{"⟲","Reset"},{"⚙","Settings"},{"‹","Previous"},{"›","Next"},{"▦","Preset browser"},{"☆","Toggle favorite"}};for(auto& b:buttons)for(auto& tip:tips)if(b->getProperties().getWithDefault("en","").toString()==String::fromUTF8(tip.first))b->setTooltip(fsText(tip.second,isFrench));int di=int(p.get("division"))+1,wi=int(p.get("wave"))+1;division.clear(dontSendNotification);for(int i=0;i<int(fsd::divisions.size());++i)division.addItem(fsText(fsd::divisions[size_t(i)],isFrench),i+1);division.setSelectedId(di,dontSendNotification);wave.clear(dontSendNotification);const char* waves[]={"Sine","Triangle","Saw","Square"};for(int i=0;i<4;++i)wave.addItem(fsText(waves[i],isFrench),i+1);wave.setSelectedId(wi,dontSendNotification);if(browser)browser->refresh();surface.repaint();}
void FreeSpiritEditor::settings(){juce::PopupMenu m;m.setLookAndFeel(&look);m.addItem(1,fsText("Safety limiter",isFrench),true,p.get("safety")>.5);m.addSeparator();m.addItem(2,fsText("Save preset...",isFrench));m.addItem(3,fsText("Load preset...",isFrench));m.addSeparator();m.addItem(4,fsText("Reset to defaults",isFrench));auto safe=juce::Component::SafePointer<FreeSpiritEditor>(this);m.showMenuAsync(juce::PopupMenu::Options().withTargetComponent(this),[safe](int i){if(safe==nullptr)return;if(i==1)safe->p.set("safety",safe->p.get("safety")>.5?0:1);if(i==2)safe->save();if(i==3)safe->load();if(i==4)safe->p.reset();});}
void FreeSpiritEditor::save(){using namespace juce;chooser=std::make_unique<FileChooser>(fsText("Save FreeSpirit preset",isFrench),File::getSpecialLocation(File::userDocumentsDirectory).getChildFile(p.presetName+".fspreset"),"*.fspreset");auto safe=Component::SafePointer<FreeSpiritEditor>(this);chooser->launchAsync(FileBrowserComponent::saveMode|FileBrowserComponent::canSelectFiles|FileBrowserComponent::warnAboutOverwriting,[safe](const FileChooser& c){if(safe==nullptr)return;auto f=c.getResult();if(f==File{})return;f=f.withFileExtension(".fspreset");MemoryBlock b;safe->p.getStateInformation(b);if(f.replaceWithData(b.getData(),b.getSize())){safe->p.presetName=f.getFileNameWithoutExtension();safe->preset=-1;safe->update();if(safe->browser)safe->browser->refresh();}});}
void FreeSpiritEditor::load(){using namespace juce;chooser=std::make_unique<FileChooser>(fsText("Load FreeSpirit preset",isFrench),File::getSpecialLocation(File::userDocumentsDirectory),"*.fspreset");auto safe=Component::SafePointer<FreeSpiritEditor>(this);chooser->launchAsync(FileBrowserComponent::openMode|FileBrowserComponent::canSelectFiles,[safe](const FileChooser& c){if(safe==nullptr)return;MemoryBlock b;if(c.getResult().loadFileAsData(b)){auto f=safe->p.favorites;safe->p.setStateInformation(b.getData(),int(b.getSize()));safe->p.favorites=f;safe->p.presetName=c.getResult().getFileNameWithoutExtension();safe->preset=-1;safe->update();if(safe->browser)safe->browser->refresh();}});}
