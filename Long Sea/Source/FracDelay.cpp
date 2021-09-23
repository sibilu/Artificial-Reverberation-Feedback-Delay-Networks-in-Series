// This class is very much based on a Eric Tarr's tutorial on FDN's from his Patreon

#include "FracDelay.h"


FracDelay::FracDelay(){
}

FracDelay::FracDelay(float delay,float modSpeed){
    this->delay = delay;
    this->modSpeed = modSpeed;
}

// Destructor
FracDelay::~FracDelay(){
}


float FracDelay::processSample(float x, int channel){
    
    if (delay < 1.f){
        return x;
    }
    else{
        float lfo;
        
        lfo = depth * sin(currentAngle[channel]);
        
        currentAngle[channel] += angleChange;
        if (currentAngle[channel] > 2.f * M_PI){
            currentAngle[channel] -= 2.f * M_PI;
        }
        
        // Delay Buffer
        // "delay" can be fraction
        int d1 = floor(delay+lfo);
        // one sample apart
        int d2 = d1 + 1;
        
        // subtracting the floored version from the non-floored version, leaving decimals. 
        float weight2 = delay + lfo - (float)d1;
        // inversing by subtracting decimals from 1 to get "weighing" for each sample
        float weight1 = 1.0f - weight2;
        
        // circulate read indices. x= MAX_BUFFER_SIZE acts as modulo
         readIndexD1 = writeIndex[channel] - d1;
        if (readIndexD1 < 0){
            readIndexD1 += MAX_BUFFER_SIZE; }
        
         readIndexD2 = writeIndex[channel] - d2;
        if (readIndexD2 < 0){
            readIndexD2 += MAX_BUFFER_SIZE; }
        
        
        // weighing the two samples in the linear interpolation with weight1 and weight2.
        float y = weight1 * delayBuffer[readIndexD1][channel] + weight2 * delayBuffer[readIndexD2][channel];
        
        delayBuffer[writeIndex[channel]][channel] = x;
        
        // -1 as we index from 0 but buffer size starts at 1
        // circulate write index
        if (writeIndex[channel] < MAX_BUFFER_SIZE - 1){
            writeIndex[channel]++;
            
        }
        else{
            writeIndex[channel] = 0;
        }

        return y;
    }
}

void FracDelay::setFs(float Fs){
    this->Fs = Fs;
}


void FracDelay::setDelaySamples(float delay){
    if (delay >= 1.f){
        this->delay = delay;
    }
    else{
        this->delay = 0.f;
    }
}


void FracDelay::setModSpeed(float modSpeed){
        this->modSpeed = modSpeed;
        angleChange = modSpeed * (1.f/Fs) * 2 * M_PI;
    }


void FracDelay::setDepth(float depth){

    this->depth = depth;

}
