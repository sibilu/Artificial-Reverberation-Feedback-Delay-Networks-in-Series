// This class is very much based on a Eric Tarr's tutorial on FDN's from his Patreon

#ifndef FracDelay_h
#define FracDelay_h

#include <cmath>
using namespace std;

class FracDelay {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FracDelay();
    
    FracDelay(float delay, float modSpeed);
    
    // Destructor
    ~FracDelay();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDelaySamples(float delay);
    
    void setModSpeed(float modSpeed);
    void setDepth(float depth);

    int readIndexD1;
    int readIndexD2;
    
private:
    
    float Fs = 48000.f;
    
    float delay = 5.f;
    
    const int MAX_BUFFER_SIZE = 96000;
    float delayBuffer[96000][2] = {0.0f};
    int writeIndex[2] = {0};
    
    float modSpeed = 1.0f; // Hz, frequency of LFO
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    float currentAngle[2] = {0.0f};
    float angleChange = modSpeed * (1.f/Fs) * 2.f * M_PI;
    
    
    
};



#endif /* FractionalDelay_hpp */
