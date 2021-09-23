

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class LongSeaAudioProcessorEditor  : public AudioProcessorEditor,
                                        public juce::Slider::Listener,
                                        public Button::Listener
{
public:
    LongSeaAudioProcessorEditor (LongSeaAudioProcessor&);
    ~LongSeaAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider * slider) override;
    void buttonClicked(Button* button) override;

private:
    TextButton FDN1Button { "FDN 1" };
   TextButton FDN2Button { "FDN 2" };

    TextButton FDN3Button { "FDN 3" };

    Slider reverbTimeSlider;
    Slider modulationSlider;
    Slider wetDrySlider;
    Slider predelaySlider;   
    
    Label reverbTimeLabel;
    Label modulationLabel;
    Label wetDryLabel;
    Label predelayLabel;
    
    
   
    LongSeaAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LongSeaAudioProcessorEditor)
};
