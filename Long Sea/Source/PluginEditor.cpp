#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LongSeaAudioProcessorEditor::LongSeaAudioProcessorEditor (LongSeaAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    setSize (540, 260);
    
    //BUTTONS
    addAndMakeVisible(FDN1Button);
    FDN1Button.setButtonText("Early FDN");
    FDN1Button.setBounds(Rectangle<int>(40,175, 50, 50));
    FDN1Button.addListener(this);
    
    addAndMakeVisible(FDN2Button);
      FDN2Button.setButtonText("Mid FDN");
      FDN2Button.setBounds(Rectangle<int>(140,175, 50, 50));
      FDN2Button.addListener(this);
    
    addAndMakeVisible(FDN3Button);
    FDN3Button.setButtonText("Late FDN");
    FDN3Button.setBounds(Rectangle<int>(240,175, 50, 50));
    FDN3Button.addListener(this);
    
    //REVERB TIME SLIDER
    reverbTimeSlider.addListener(this);
    reverbTimeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    reverbTimeSlider.setBounds(330, 35, 200, 200);
    reverbTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,50,30);
    reverbTimeSlider.setRange(0.01f, 0.20f, 0.001f);
    reverbTimeSlider.setValue(0.10);
    addAndMakeVisible(reverbTimeSlider);
    
    reverbTimeLabel.setText("Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider,false);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);
    
    //MODULATION SLIDER
    modulationSlider.addListener(this);
    modulationSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    modulationSlider.setBounds(115, 30, 100, 100);
    modulationSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,50,30);
    modulationSlider.setRange(1.f, 30.f, 0.01f);
    modulationSlider.setValue(15.f);
    addAndMakeVisible(modulationSlider);
    
    modulationLabel.setText("Mod", dontSendNotification);
    modulationLabel.attachToComponent(&modulationSlider,false);
    modulationLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLabel);
    
    //WET DRY SLIDER
    wetDrySlider.addListener(this);
    wetDrySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    wetDrySlider.setBounds(215, 30, 100, 100);
    wetDrySlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,50,30);
    wetDrySlider.setRange(0.0f, 1.0f, 0.01f);
    wetDrySlider.setValue(0.5f);
    addAndMakeVisible(wetDrySlider);
    
    wetDryLabel.setText("Dry/Wet", dontSendNotification);
    wetDryLabel.attachToComponent(&wetDrySlider,false);
    wetDryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLabel);
    
    
    
    
    //PREDELAY SLIDER
    predelaySlider.addListener(this);
    predelaySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    predelaySlider.setBounds(15, 30, 100, 100);
    predelaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,50,30);
    predelaySlider.setRange(0.0f, 200.0f, 0.1f);
    predelaySlider.setValue(0.0f);
    addAndMakeVisible(predelaySlider);
    
    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider,false);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);
    

    
}



LongSeaAudioProcessorEditor::~LongSeaAudioProcessorEditor()
{
}

//==============================================================================
void LongSeaAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::skyblue);
    g.setColour (Colours::white);
    g.setFont (15.0f);
    // g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);

    if(processor.FDN3Toggle == true){
        FDN3Button.setColour(TextButton::buttonOnColourId, Colours::green);
    }
}

void LongSeaAudioProcessorEditor::resized()


{
    
}

void LongSeaAudioProcessorEditor::buttonClicked(Button* button)
{
    if (button == &FDN1Button) {
        if (processor.FDN1Toggle == false){
            processor.FDN1Toggle = true;
            Logger::writeToLog("FDN1Toggle = true");

        } else if (processor.FDN1Toggle == true){
        processor.FDN1Toggle = false;
            Logger::writeToLog("FDN1Toggle = false");


        }
    }
    
   if (button == &FDN2Button) {
       if (processor.FDN2Toggle == false){
           processor.FDN2Toggle = true;
           Logger::writeToLog("FDN2Toggle = true");
       } else if (processor.FDN2Toggle == true){
       processor.FDN2Toggle = false;
           Logger::writeToLog("FDN2Toggle = false");


       }
   }
    
    if (button == &FDN3Button) {
        if (processor.FDN3Toggle == false){
            processor.FDN3Toggle = true;
            Logger::writeToLog("FDN3Toggle = true");
        } else if (processor.FDN3Toggle == true){
        processor.FDN3Toggle = false;
            Logger::writeToLog("FDN3Toggle = false");
            

        }
    }
}


void LongSeaAudioProcessorEditor::sliderValueChanged(Slider * slider){
    if (slider == & predelaySlider){
        processor.predelayMS = predelaySlider.getValue();
    }
    
    if (slider == & wetDrySlider){
        processor.wet  = wetDrySlider.getValue();
    }
    
    
    if (slider == & reverbTimeSlider){
        processor.timeValue  = reverbTimeSlider.getValue();
    }
    
    if (slider == & modulationSlider){
        processor.modValue = modulationSlider.getValue();
    }
    
  
    
}

