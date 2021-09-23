#ifndef FDN_hpp
#define FDN_hpp

#include "FracDelay.h"
using namespace std;

class FDN {
    
public:
    
    FDN();
    
    FDN(float delay1, float speed1, float delay2, float speed2, float delay3, float speed3, float delay4, float speed4, float delay5, float speed5, float delay6, float speed6, float delay7, float speed7, float delay8, float speed8, float delay9, float speed9, float delay10, float speed10, float delay11, float speed11, float delay12, float speed12, float delay13, float speed13, float delay14, float speed14, float delay15, float speed15, float delay16, float speed16);
    
    // Destructor
    ~FDN();
    
    float processSample(float x,int channel);
    
    void setFs(float Fs);
    
    
    void setModSpeed(float modSpeed);
    
    
    void setTime(float timeValue);
    
    void setDepth(float depth);
    
    
private:
    float feedbackGain = 0.02f;
    
    float Fs = 48000.f;
    
    float delay1 = 0;
    float delay2 = 0;
    float delay3 = 0;
    float delay4 = 0;
    float delay5 = 0;
    float delay6 = 0;
    float delay7 = 0;
    float delay8 = 0;
    float delay9 = 0;
    float delay10 = 0;
    float delay11 = 0;
    float delay12 = 0;
    float delay13 = 0;
    float delay14 = 0;
    float delay15 = 0;
    float delay16 = 0;
    
    float speed1 = 0;
       float speed2 = 0;
       float speed3 = 0;
       float speed4 = 0;
       float speed5 = 0;
       float speed6 = 0;
       float speed7 = 0;
       float speed8 = 0;
       float speed9 = 0;
       float speed10 = 0;
       float speed11 = 0;
       float speed12 = 0;
       float speed13 = 0;
       float speed14 = 0;
       float speed15 = 0;
       float speed16 = 0;
    
    
    
    FracDelay fractionalDelay1 {};
    FracDelay fractionalDelay2 {};
    FracDelay fractionalDelay3 {};
    FracDelay fractionalDelay4 {};
    FracDelay fractionalDelay5 {};
    FracDelay fractionalDelay6 {};
    FracDelay fractionalDelay7 {};
    FracDelay fractionalDelay8 {};
    FracDelay fractionalDelay9 {};
    FracDelay fractionalDelay10 {};
    FracDelay fractionalDelay11 {};
    FracDelay fractionalDelay12 {};
    FracDelay fractionalDelay13 {};
    FracDelay fractionalDelay14 {};
    FracDelay fractionalDelay15 {};
    FracDelay fractionalDelay16 {};

    
    float fb1[2] = {0.f};
    float fb2[2] = {0.f};
    float fb3[2] = {0.f};
    float fb4[2] = {0.f};
    float fb5[2] = {0.f};
    float fb6[2] = {0.f};
    float fb7[2] = {0.f};
    float fb8[2] = {0.f};
    float fb9[2] = {0.f};
    float fb10[2] = {0.f};
    float fb11[2] = {0.f};
    float fb12[2] = {0.f};
    float fb13[2] = {0.f};
    float fb14[2] = {0.f};
    float fb15[2] = {0.f};
    float fb16[2] = {0.f};
    
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    

        float g1_1 = 1.f, g1_2 = 1.f, g1_3 = 1.f, g1_4 = 1.f, g1_5 = 1.f, g1_6 = 1.f, g1_7 = 1.f, g1_8 = 1.f, g1_9 = 1.f, g1_10 = 1.f, g1_11 = 1.f, g1_12 = 1.f, g1_13 = 1.f, g1_14 = 1.f, g1_15 = 1.f, g1_16 = 1.f;
         float g2_1 = 1.f, g2_2 = -1.f, g2_3 = 1.f, g2_4 = -1.f, g2_5 = 1.f, g2_6 = -1.f, g2_7 = 1.f, g2_8 = -1.f, g2_9 = 1.f, g2_10 = -1.f, g2_11 = 1.f, g2_12 = -1.f, g2_13 = 1.f, g2_14 = -1.f, g2_15 = 1.f, g2_16 = -1.f;
         float g3_1 = 1.f, g3_2 = 1.f, g3_3 = -1.f, g3_4 = -1.f, g3_5 = 1.f, g3_6 = 1.f, g3_7 = -1.f, g3_8 = -1.f, g3_9 = 1.f, g3_10 = 1.f, g3_11 = -1.f, g3_12 = -1.f, g3_13 = 1.f, g3_14 = 1.f, g3_15 = -1.f, g3_16 = -1.f;
         float g4_1 = 1.f, g4_2 = -1.f, g4_3 = -1.f, g4_4 = 1.f, g4_5 = 1.f, g4_6 = -1.f, g4_7 = -1.f, g4_8 = 1.f, g4_9 = 1.f, g4_10 = -1.f, g4_11 =-1.f, g4_12 = 1.f, g4_13 = 1.f, g4_14 = -1.f, g4_15 = -1.f, g4_16 = 1.f;
         float g5_1 = 1.f, g5_2 = 1.f, g5_3 = 1.f, g5_4 = 1.f, g5_5 = -1.f, g5_6 = -1.f, g5_7 = -1.f, g5_8 = -1.f, g5_9 = 1.f, g5_10 = 1.f, g5_11 = 1.f, g5_12 = 1.f, g5_13 = -1.f, g5_14 = -1.f, g5_15 = -1.f, g5_16 = -1.f;
         float g6_1 = 1.f, g6_2 = -1.f, g6_3 = 1.f, g6_4 = -1.f, g6_5 = -1.f, g6_6 = 1.f, g6_7 = -1.f, g6_8 = 1.f, g6_9 = 1.f, g6_10 = -1.f, g6_11 = 1.f, g6_12 = -1.f, g6_13 = -1.f, g6_14 = 1.f, g6_15 = -1.f, g6_16 = 1.f;
         float g7_1 = 1.f, g7_2 = 1.f, g7_3 = -1.f, g7_4 = -1.f, g7_5 = -1.f, g7_6 = -1.f, g7_7 = 1.f, g7_8 = 1.f, g7_9 = 1.f, g7_10 = 1.f, g7_11 = -1.f, g7_12 = -1.f, g7_13 = -1.f, g7_14 = -1.f, g7_15 = 1.f, g7_16 = 1.f;
         float g8_1 = 1.f, g8_2 = -1.f, g8_3 = -1.f, g8_4 = 1.f, g8_5 = -1.f, g8_6 = 1.f, g8_7 = 1.f, g8_8 = -1.f, g8_9 = 1.f, g8_10 = -1.f, g8_11 = -1.f, g8_12 = 1.f, g8_13 = -1.f, g8_14 = 1.f, g8_15 = 1.f, g8_16 = -1.f;

      
        float g9_1 = g1_1, g9_2 = g1_2, g9_3 = g1_3, g9_4 = g1_4, g9_5 = g1_5, g9_6 = g1_6, g9_7 = g1_7, g9_8 = g1_8, g9_9 = -g1_9, g9_10 = -g1_10, g9_11 = -g1_11, g9_12 = -g1_12, g9_13 = -g1_13, g9_14 = -g1_14, g9_15 = -g1_15, g9_16 = -g1_16;
        float g10_1 = g2_1, g10_2 = g2_2, g10_3 = g2_3, g10_4 = g2_4, g10_5 = g2_5, g10_6 = g2_6, g10_7 = g2_7, g10_8 = g2_8, g10_9 = -g2_9, g10_10 = -g2_10, g10_11 = -g2_11, g10_12 = -g2_12, g10_13 = -g2_13, g10_14 = -g2_14, g10_15 = -g2_15, g10_16 = -g2_16;
        float g11_1 = g3_1, g11_2 = g3_2, g11_3 = g3_3, g11_4 = g3_4, g11_5 = g3_5, g11_6 = g3_6, g11_7 = g3_7, g11_8 = g3_8, g11_9 = -g3_9, g11_10 = -g3_10, g11_11 = -g3_11, g11_12 = -g3_12, g11_13 = -g3_13, g11_14 = -g3_14, g11_15 = -g3_15, g11_16 = -g3_16;
        float g12_1 = g4_1, g12_2 = g4_2, g12_3 = g4_3, g12_4 = g4_4, g12_5 = g4_5, g12_6 = g4_6, g12_7 = g4_7, g12_8 = g4_8, g12_9 = -g4_9, g12_10 = -g4_10, g12_11 = -g4_11, g12_12 = -g4_12, g12_13 = -g4_13, g12_14 = -g4_14, g12_15 = -g4_15, g12_16 = -g4_16;
        float g13_1 = g5_1, g13_2 = g5_2, g13_3 = g5_3, g13_4 = g5_4, g13_5 = g5_5, g13_6 = g5_6, g13_7 = g5_7, g13_8 = g5_8, g13_9 = -g5_9, g13_10 = -g5_10, g13_11 = -g5_11, g13_12 = -g5_12, g13_13 = -g5_13, g13_14 = -g5_14, g13_15 = -g5_15, g13_16 = -g5_16;
        float g14_1 = g6_1, g14_2 = g6_2, g14_3 = g6_3, g14_4 = g6_4, g14_5 = g6_5, g14_6 = g6_6, g14_7 = g6_7, g14_8 = g6_8, g14_9 = -g6_9, g14_10 = -g6_10, g14_11 = -g6_11, g14_12 = -g6_12, g14_13 = -g6_13, g14_14 = -g6_14, g14_15 = -g6_15, g14_16 = -g6_16;
        float g15_1 = g7_1, g15_2 = g7_2, g15_3 = g7_3, g15_4 = g7_4, g15_5 = g7_5, g15_6 = g7_6, g15_7 = g7_7, g15_8 = g7_8, g15_9 = -g7_9, g15_10 = -g7_10, g15_11 = -g7_11, g15_12 = -g7_12, g15_13 = -g7_13, g15_14 = -g7_14, g15_15 = -g7_15, g15_16 = -g7_16;
        float g16_1 = g8_1, g16_2 = g8_2, g16_3 = g8_3, g16_4 = g8_4, g16_5 = g8_5, g16_6 = g8_6, g16_7 =g8_7, g16_8 = g8_8, g16_9 = -g8_9, g16_10 = -g8_10, g16_11 = -g8_11, g16_12 = -g1_12, g16_13 = -g1_13, g16_14 = -g8_14, g16_15 = -g8_15, g16_16 = -g8_16;



   
};



#endif /* FDN_hpp */
