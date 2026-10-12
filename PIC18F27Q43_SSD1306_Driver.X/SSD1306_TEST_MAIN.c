/*
 * File:   SSD1306_TEST_MAIN.c
 * Author: kojim
 *
 * Created on 2026/09/19, 21:51
 */

#include <xc.h>
#include <stdint.h>
#include <stdlib.h>

#include "SSD1306_TEST_MAIN.h"

#include "SSD1306_Parameter.h"
#include "SSD1306BuffFunc.h"
#include "init.h"

#include "font.h"

#include "SPIFlashFont.h"

#define _XTAL_FREQ 64000000//64MHz

void main(void) {
    init();
    
    //main
    initSSD1306();
    __delay_ms(10);
    
    
    SSD1306SetAddA();
    
//    SSD1306SetAddS(20, 4);
    __delay_ms(10);
    buffStatFlag |= BSF_BA_UREADY;
//    SSD1306UpdateDrawSM();
    SSD1306StateMachine();
    __delay_ms(10);
    
//    copyPageFromPFMToGPR((uint24_t)&walkmanOpeningLogo[0]  , (uint16_t)&GPBUFF_A.PAGE0);
//    copyPageFromPFMToGPR((uint24_t)&walkmanOpeningLogo[128], (uint16_t)&GPBUFF_A.PAGE1);
//    copyPageFromPFMToGPR((uint24_t)&walkmanOpeningLogo[256], (uint16_t)&GPBUFF_A.PAGE2);
//    copyPageFromPFMToGPR((uint24_t)&walkmanOpeningLogo[384], (uint16_t)&GPBUFF_A.PAGE3);
    
    
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], 68);//-
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[6], 54);//2
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[12], 52);//0
    
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[32], 53);//2
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[38], 52);//0
    
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[50], 59);//0
    
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[62], 57);//0
    
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[76], 55);//0
    
    copyFontMemoryDMA8x6Left((uint16_t)&GPBUFF_A.PAGE3.GPRAM[107], 52);//0
        __delay_ms(10);
////    for (uint8_t i = 0;i < 128;i ++){
////        GPBUFF_A.PAGE0.GPRAM[i] = i;
////    }
//    
//    copyFontMemoryDMA8x6((uint16_t)&GPBUFF_A.PAGE0.GPRAM[100], 60);
//    
//    
//    maskArea((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], 128, 0xFC);
//    blendArea((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], 110, 0x01);
//    blendArea((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], 48, 0x02);
    
//    SSD1306_EN_UPDATE();
//    buffStatFlag |= BSF_BA_UREADY;
    while (1){
//        LATA ^= 0x02;
        static uint8_t count = 0;
        count ++;
        count &= 0x7F;
//        
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0],  220);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE0.GPRAM[8],  283);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE0.GPRAM[16], 204);//A
        
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0], 203);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE1.GPRAM[8], 204);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE1.GPRAM[16], 205);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE1.GPRAM[24], 206);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE1.GPRAM[32], 207);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE1.GPRAM[40], 208);//A
//        
//        
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0], 203);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE2.GPRAM[8], 204);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE2.GPRAM[16], 205);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE2.GPRAM[24], 206);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE2.GPRAM[32], 207);//A
//        copyFontMemoryDMA8x8((uint16_t)&GPBUFF_A.PAGE2.GPRAM[40], 208);//A
//        
        maskArea0_255((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], 255, 0xFC);
        blendArea0_255((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], count, 0x01);
        blendArea0_255((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0], count, 0x02);
//        __delay_ms(1);
//        SSD1306DrawPage((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0]);
//        __delay_ms(5);
//        SSD1306DrawPage((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0]);
//        __delay_ms(5);
//        SSD1306DrawPage((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0]);
//        __delay_ms(5);
//        SSD1306DrawPage((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0]);
//        __delay_ms(5);
//        SSD1306SetAddS(10, 4);
//        SSD1306SetHorizontalOffset((uint8_t)count);
//        __delay_ms(5);
//        SSD1306SetVerticalOffset((uint8_t)count);
//        __delay_ms(5);
        
        buffStatFlag |= BSF_BA_UREADY;
        SSD1306StateMachine();
//        
        spiFlashToBuffStateMachine();
        
        
//        SSD1306DrawPage((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0]);
        __delay_ms(50);
        
//        LATA &= ~0x01;
//        clearGPRAM(&GPBUFF_A.Page[0].GPRAM[0]);
//        __delay_ms(500);
//        fillGPRAM(&GPBUFF_A.Page[0].GPRAM[0]);
//        buffStatFlag |= BSF_BA_UREADY;
//        __delay_ms(500);
    }
//    
//    updateGPRAM(&GPBUFF_A.PAGE0.GPRAM[0]);
    
    return;
}

