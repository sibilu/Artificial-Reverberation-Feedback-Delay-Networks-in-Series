#include "FDN.h"

FDN::FDN(float delay1, float speed1, float delay2, float speed2, float delay3, float speed3, float delay4, float speed4, float delay5, float speed5, float delay6, float speed6, float delay7, float speed7, float delay8, float speed8, float delay9, float speed9, float delay10, float speed10, float delay11, float speed11, float delay12, float speed12, float delay13, float speed13, float delay14, float speed14, float delay15, float speed15, float delay16, float speed16){

    fractionalDelay1.setDelaySamples(delay1);
    fractionalDelay2.setDelaySamples(delay2);
    fractionalDelay3.setDelaySamples(delay3);
    fractionalDelay4.setDelaySamples(delay4);
    fractionalDelay5.setDelaySamples(delay5);
    fractionalDelay6.setDelaySamples(delay6);
    fractionalDelay7.setDelaySamples(delay7);
    fractionalDelay8.setDelaySamples(delay8);
    fractionalDelay9.setDelaySamples(delay9);
    fractionalDelay10.setDelaySamples(delay10);
    fractionalDelay11.setDelaySamples(delay11);
    fractionalDelay12.setDelaySamples(delay12);
    fractionalDelay13.setDelaySamples(delay13);
    fractionalDelay14.setDelaySamples(delay14);
    fractionalDelay15.setDelaySamples(delay15);
    fractionalDelay16.setDelaySamples(delay16);

    fractionalDelay1.setModSpeed(speed1);
    fractionalDelay2.setModSpeed(speed2);
    fractionalDelay3.setModSpeed(speed3);
    fractionalDelay4.setModSpeed(speed4);
    fractionalDelay5.setModSpeed(speed5);
    fractionalDelay6.setModSpeed(speed6);
    fractionalDelay7.setModSpeed(speed7);
    fractionalDelay8.setModSpeed(speed8);
    fractionalDelay9.setModSpeed(speed9);
    fractionalDelay10.setModSpeed(speed10);
    fractionalDelay11.setModSpeed(speed11);
    fractionalDelay12.setModSpeed(speed12);
    fractionalDelay13.setModSpeed(speed13);
    fractionalDelay14.setModSpeed(speed14);
    fractionalDelay15.setModSpeed(speed15);
    fractionalDelay16.setModSpeed(speed16);
}



// Destructor
FDN::~FDN(){
}


float FDN::processSample(float x, int channel){

    float yNoTonalCorrection;
    
    float inDL1 = x + fb1[channel];
    float inDL2 = x + fb2[channel];
    float inDL3 = x + fb3[channel];
    float inDL4 = x + fb4[channel];
    float inDL5 = x + fb5[channel];
    float inDL6 = x + fb6[channel];
    float inDL7 = x + fb7[channel];
    float inDL8 = x + fb8[channel];
    float inDL9 = x + fb9[channel];
    float inDL10 = x + fb10[channel];
    float inDL11 = x + fb11[channel];
    float inDL12 = x + fb12[channel];
    float inDL13 = x + fb13[channel];
    float inDL14 = x + fb14[channel];
    float inDL15 = x + fb15[channel];
    float inDL16 = x + fb16[channel];
    
     

    float outDL1 = fractionalDelay1.processSample(inDL1, channel);
    float outDL2 = fractionalDelay2.processSample(inDL2, channel);
    float outDL3 = fractionalDelay3.processSample(inDL3, channel);
    float outDL4 = fractionalDelay4.processSample(inDL4, channel);
    float outDL5 = fractionalDelay5.processSample(inDL5, channel);
    float outDL6 = fractionalDelay6.processSample(inDL6, channel);
    float outDL7 = fractionalDelay7.processSample(inDL7, channel);
    float outDL8 = fractionalDelay8.processSample(inDL8, channel);
    float outDL9 = fractionalDelay9.processSample(inDL9, channel);
    float outDL10 = fractionalDelay10.processSample(inDL10, channel);
    float outDL11 = fractionalDelay11.processSample(inDL11, channel);
    float outDL12 = fractionalDelay12.processSample(inDL12, channel);
    float outDL13 = fractionalDelay13.processSample(inDL13, channel);
    float outDL14 = fractionalDelay14.processSample(inDL14, channel);
    float outDL15 = fractionalDelay15.processSample(inDL15, channel);
    float outDL16 = fractionalDelay16.processSample(inDL16, channel);

    yNoTonalCorrection = 0.1f * (outDL1 + outDL2 + outDL3 + outDL4 + outDL5 + outDL6 + outDL7 + outDL8 + outDL9 + outDL10 + outDL11 + outDL12 + outDL13 + outDL14 + outDL15 + outDL16);
    
    
    fb1[channel] = (g1_1*outDL1 + g1_2*outDL2 + g1_3*outDL3 + g1_4*outDL4 + g1_5*outDL5 + g1_6*outDL6 + g1_7*outDL7 + g1_8*outDL8 + g1_9*outDL9 + g1_10*outDL10 + g1_11*outDL11 + g1_12*outDL12 + g1_13*outDL13 + g1_14*outDL14 + g1_15*outDL15 + g1_16*outDL16) * feedbackGain;
    
    fb2[channel] = (g2_1*outDL1 + g2_2*outDL2 + g2_3*outDL3 + g2_4*outDL4 + g2_5*outDL5 + g2_6*outDL6 + g2_7*outDL7 + g2_8*outDL8 + g2_9*outDL9 + g2_10*outDL10 + g2_11*outDL11 + g2_12*outDL12 + g2_13*outDL13 + g2_14*outDL14 + g2_15*outDL15 + g2_16*outDL16) * feedbackGain;
   
    fb3[channel] = (g3_1*outDL1 + g3_2*outDL2 + g3_3*outDL3 + g3_4*outDL4 + g3_5*outDL5 + g3_6*outDL6 + g3_7*outDL7 + g3_8*outDL8 + g3_9*outDL9 + g3_10*outDL10 + g3_11*outDL11 + g3_12*outDL12 + g3_13*outDL13 + g3_14*outDL14 + g3_15*outDL15 + g3_16*outDL16) * feedbackGain;

    fb4[channel] = (g4_1*outDL1 + g4_2*outDL2 + g4_3*outDL3 + g4_4*outDL4 + g4_5*outDL5 + g4_6*outDL6 + g4_7*outDL7 + g4_8*outDL8 + g4_9*outDL9 + g4_10*outDL10 + g4_11*outDL11 + g4_12*outDL12 + g4_13*outDL13 + g4_14*outDL14 + g4_15*outDL15 + g4_16*outDL16) * feedbackGain;

    fb5[channel] = (g5_1*outDL1 + g5_2*outDL2 + g5_3*outDL3 + g5_4*outDL4 + g5_5*outDL5 + g5_6*outDL6 + g5_7*outDL7 + g5_8*outDL8 + g5_9*outDL9 + g5_10*outDL10 + g5_11*outDL11 + g5_12*outDL12 + g5_13*outDL13 + g5_14*outDL14 + g5_15*outDL15 + g5_16*outDL16) * feedbackGain;

    fb6[channel] = (g6_1*outDL1 + g6_2*outDL2 + g6_3*outDL3 + g6_4*outDL4 + g6_5*outDL5 + g6_6*outDL6 + g6_7*outDL7 + g6_8*outDL8 + g6_9*outDL9 + g6_10*outDL10 + g6_11*outDL11 + g6_12*outDL12 + g6_13*outDL13 + g6_14*outDL14 + g6_15*outDL15 + g6_16*outDL16) * feedbackGain;

    fb7[channel] = (g7_1*outDL1 + g7_2*outDL2 + g7_3*outDL3 + g7_4*outDL4 + g7_5*outDL5 + g7_6*outDL6 + g7_7*outDL7 + g7_8*outDL8 + g7_9*outDL9 + g7_10*outDL10 + g7_11*outDL11 + g7_12*outDL12 + g7_13*outDL13 + g7_14*outDL14 + g7_15*outDL15 + g7_16*outDL16) * feedbackGain;

    fb8[channel] = (g8_1*outDL1 + g8_2*outDL2 + g8_3*outDL3 + g8_4*outDL4 + g8_5*outDL5 + g8_6*outDL6 + g8_7*outDL7 + g8_8*outDL8 + g8_9*outDL9 + g8_10*outDL10 + g8_11*outDL11 + g8_12*outDL12 + g8_13*outDL13 + g8_14*outDL14 + g8_15*outDL15 + g8_16*outDL16) * feedbackGain;

    fb9[channel] = (g9_1*outDL1 + g9_2*outDL2 + g9_3*outDL3 + g9_4*outDL4 + g9_5*outDL5 + g9_6*outDL6 + g9_7*outDL7 + g9_8*outDL8 + g9_9*outDL9 + g9_10*outDL10 + g9_11*outDL11 + g9_12*outDL12 + g9_13*outDL13 + g9_14*outDL14 + g9_15*outDL15 + g9_16*outDL16) * feedbackGain;

    fb10[channel] = (g10_1*outDL1 + g10_2*outDL2 + g10_3*outDL3 + g10_4*outDL4 + g10_5*outDL5 + g10_6*outDL6 + g10_7*outDL7 + g10_8*outDL8 + g10_9*outDL9 + g10_10*outDL10 + g10_11*outDL11 + g10_12*outDL12 + g10_13*outDL13 + g10_14*outDL14 + g10_15*outDL15 + g10_16*outDL16) * feedbackGain;

    fb11[channel] = (g11_1*outDL1 + g11_2*outDL2 + g11_3*outDL3 + g11_4*outDL4 + g11_5*outDL5 + g11_6*outDL6 + g11_7*outDL7 + g11_8*outDL8 + g11_9*outDL9 + g11_10*outDL10 + g11_11*outDL11 + g11_12*outDL12 + g11_13*outDL13 + g11_14*outDL14 + g11_15*outDL15 + g11_16*outDL16) * feedbackGain;

    fb12[channel] = (g12_1*outDL1 + g12_2*outDL2 + g12_3*outDL3 + g12_4*outDL4 + g12_5*outDL5 + g12_6*outDL6 + g12_7*outDL7 + g12_8*outDL8 + g12_9*outDL9 + g12_10*outDL10 + g12_11*outDL11 + g12_12*outDL12 + g12_13*outDL13 + g12_14*outDL14 + g12_15*outDL15 + g12_16*outDL16) * feedbackGain;

    fb13[channel] = (g13_1*outDL1 + g13_2*outDL2 + g13_3*outDL3 + g13_4*outDL4 + g13_5*outDL5 + g13_6*outDL6 + g13_7*outDL7 + g13_8*outDL8 + g13_9*outDL9 + g13_10*outDL10 + g13_11*outDL11 + g13_12*outDL12 + g13_13*outDL13 + g13_14*outDL14 + g13_15*outDL15 + g13_16*outDL16) * feedbackGain;

    fb14[channel] = (g14_1*outDL1 + g14_2*outDL2 + g14_3*outDL3 + g14_4*outDL4 + g14_5*outDL5 + g14_6*outDL6 + g14_7*outDL7 + g14_8*outDL8 + g14_9*outDL9 + g14_10*outDL10 + g14_11*outDL11 + g14_12*outDL12 + g14_13*outDL13 + g14_14*outDL14 + g14_15*outDL15 + g14_16*outDL16) * feedbackGain;

    fb15[channel] = (g15_1*outDL1 + g15_2*outDL2 + g15_3*outDL3 + g15_4*outDL4 + g15_5*outDL5 + g15_6*outDL6 + g15_7*outDL7 + g15_8*outDL8 + g15_9*outDL9 + g15_10*outDL10 + g15_11*outDL11 + g15_12*outDL12 + g15_13*outDL13 + g15_14*outDL14 + g15_15*outDL15 + g15_16*outDL16) * feedbackGain;

    fb16[channel] = (g16_1*outDL1 + g16_2*outDL2 + g16_3*outDL3 + g16_4*outDL4 + g16_5*outDL5 + g16_6*outDL6 + g16_7*outDL7 + g16_8*outDL8 + g16_9*outDL9 + g16_10*outDL10 + g16_11*outDL11 + g16_12*outDL12 + g16_13*outDL13 + g16_14*outDL14 + g16_15*outDL15 + g16_16*outDL16) * feedbackGain;

    
    return yNoTonalCorrection;
    
}

void FDN::setFs(float Fs){
    this->Fs  = Fs;
    fractionalDelay1.setFs(Fs);
    fractionalDelay2.setFs(Fs);
    fractionalDelay3.setFs(Fs);
    fractionalDelay4.setFs(Fs);
    fractionalDelay5.setFs(Fs);
    fractionalDelay6.setFs(Fs);
    fractionalDelay7.setFs(Fs);
    fractionalDelay8.setFs(Fs);
    fractionalDelay9.setFs(Fs);
    fractionalDelay10.setFs(Fs);
    fractionalDelay11.setFs(Fs);
    fractionalDelay12.setFs(Fs);
    fractionalDelay13.setFs(Fs);
    fractionalDelay14.setFs(Fs);
    fractionalDelay15.setFs(Fs);
    fractionalDelay16.setFs(Fs);
    

}


void FDN::setTime(float timeValue){
    feedbackGain = timeValue;
    
}


void FDN::setDepth(float depth){
    this->depth = depth;
    fractionalDelay1.setDepth(depth);
    fractionalDelay2.setDepth(depth);
    fractionalDelay3.setDepth(depth);
    fractionalDelay4.setDepth(depth);
    fractionalDelay5.setDepth(depth);
    fractionalDelay6.setDepth(depth);
    fractionalDelay7.setDepth(depth);
    fractionalDelay8.setDepth(depth);
    fractionalDelay9.setDepth(depth);
    fractionalDelay10.setDepth(depth);
    fractionalDelay11.setDepth(depth);
    fractionalDelay12.setDepth(depth);
    fractionalDelay13.setDepth(depth);
    fractionalDelay14.setDepth(depth);
    fractionalDelay15.setDepth(depth);
    fractionalDelay16.setDepth(depth);

  
}

    



