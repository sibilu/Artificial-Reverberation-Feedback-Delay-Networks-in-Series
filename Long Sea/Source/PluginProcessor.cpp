#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LongSeaAudioProcessor::LongSeaAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", AudioChannelSet::stereo(), true)
#endif
                  )
#endif
{
}

LongSeaAudioProcessor::~LongSeaAudioProcessor()
{
}

//==============================================================================
const String LongSeaAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool LongSeaAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool LongSeaAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool LongSeaAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double LongSeaAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int LongSeaAudioProcessor::getNumPrograms()
{
    return 1;   
}

int LongSeaAudioProcessor::getCurrentProgram()
{
    return 0;
}

void LongSeaAudioProcessor::setCurrentProgram (int index)
{
}

const String LongSeaAudioProcessor::getProgramName (int index)
{
    return {};
}

void LongSeaAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void LongSeaAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    predelay.setFs(sampleRate);
    predelay.setDelaySamples(0.0f);
    fdn.setFs(sampleRate);
    fdn2.setFs(sampleRate);
    fdn3.setFs(sampleRate);
    
    Fs = sampleRate;
}

void LongSeaAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool LongSeaAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
#else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;
    
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif
    
    return true;
#endif
}
#endif

void LongSeaAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    // converting milliseconds of predelay to samples
    float predelaySec = predelayMS*0.001;
    float predelaySamples = predelaySec*Fs;
    
    //setting predelay in samples for the frac delay
    predelay.setDelaySamples(predelaySamples);
    
    fdn.setTime(timeValue);
    fdn.setDepth(modValue);
    
    fdn2.setTime(timeValue);
    fdn2.setDepth(modValue);
    
    fdn3.setTime(timeValue);
    fdn3.setDepth(modValue);
    
    
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        
        
        
        for (int n = 0 ; n < buffer.getNumSamples(); ++n){
            float x  = buffer.getWritePointer (channel)[n];

            float verb = predelay.processSample(x, channel);
            
            float verbEarly;
            float verbMid;
            
            verbEarly = fdn.processSample(verb, channel);
            verbMid = fdn2.processSample(verbEarly, channel);
            verb = fdn3.processSample(verbMid, channel);
            
            if (FDN1Toggle == false){
                fdn1Gain = 1;
                
            } else if (FDN1Toggle == true){
                fdn1Gain = 0;
            }
            
            if (FDN2Toggle == false){
                fdn2Gain = 1;
                
            } else if (FDN2Toggle == true){
                fdn2Gain = 0;
            }
            
            if (FDN3Toggle == false){
                fdn3Gain = 1;
                
            } else if (FDN3Toggle == true){
                fdn3Gain = 0;
            }
            
            
                    float verbCombined = fdn1Gain * verbEarly - fdn2Gain*0.8f*verbMid + fdn3Gain*0.6 * verb;
                    float verbCombinedDelayed =  stereoDelay.processSample(verbCombined, channel);
                    float y = (1.f - wet) * x + verbCombined * wet;
                    float delayY = (1.f - wet) * x + verbCombinedDelayed * wet;

                    buffer.getWritePointer(0)[n] = y;
                    buffer.getWritePointer(1)[n] = delayY;
        }
    }
}

//==============================================================================
bool LongSeaAudioProcessor::hasEditor() const
{
    return true; // 
}

AudioProcessorEditor* LongSeaAudioProcessor::createEditor()
{
    return new LongSeaAudioProcessorEditor (*this);
}

//==============================================================================
void LongSeaAudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

void LongSeaAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

//==============================================================================
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new LongSeaAudioProcessor();
}
