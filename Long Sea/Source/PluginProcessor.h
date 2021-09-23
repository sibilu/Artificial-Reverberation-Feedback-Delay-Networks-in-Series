#pragma once

#include <JuceHeader.h>
#include "FracDelay.h"
#include "FDN.h"

//==============================================================================
/**
 */
class LongSeaAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    LongSeaAudioProcessor();
    ~LongSeaAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //public var to access from plugineditor.cpp
    float predelayMS = 0.0f;
    float wet = 0.5f;
    float timeValue = 0.1f;
    float modValue = 15.f;
    
    bool FDN1Toggle = false;
    bool FDN2Toggle = false;
    bool FDN3Toggle = false;

private:
    FracDelay predelay;
    FracDelay stereoDelay{1800.f, 0.0f};
    
    float fdn1Gain;
    float fdn2Gain;
    float fdn3Gain;
    
    FDN fdn{353.f, 0.6f,587.f, 0.9f,997.f, 1.3f,1361.f, 0.7f,1789.f, 0.9f,2111.f, 0.4f,2677.f, 0.6f,2963.f, 0.8f,3217.f, 0.3f,3547.f, 0.9f,3967.f, 0.5f,4373.f, 0.8f,4723.f, 0.9f,5153.f, 0.6f,5503.f, 0.4f,6043.f, 0.5f};
    
    FDN fdn2{6131.f, 0.6f,6719.f, 0.9f,7247.f, 1.3f,7607.f, 0.7f,8093.f, 0.9f,8669.f, 0.4f,9371.f, 0.6f,9973.f, 0.8f,10837.f, 0.3f,11279.f, 0.9f,12073.f, 0.5f,12703.f, 0.8f,13487.f, 0.9f,14083.f, 0.6f,15017.f, 0.4f,15787.f, 0.5f};
    
    
    FDN fdn3{15083.f,0.6f,15173.f,0.9f,15241.f,1.3f, 15299.f,0.7f,15461.f,0.9f, 15559.f,0.4f, 15643.f,0.6f, 15731.f,0.8f, 15791.f,0.3f,15887.f,0.9f, 15971.f,0.5f,16067.f,0.8f, 16139.f,0.9f,16231.f,0.6f,16349.f,0.4f, 16433.f,0.5f,
};
   

    float Fs = 41000.f;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LongSeaAudioProcessor)
};
