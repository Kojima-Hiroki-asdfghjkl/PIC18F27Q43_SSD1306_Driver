/* 
 * File:   SSD1306BuffFunc.h
 * Author: kojim
 *
 * Created on 2026/09/20, 17:37
 */

#pragma once

#include <stdint.h>

#include "SSD1306.h"
#include "SSD1306_Parameter.h"

void updateGPRAM(uint16_t buffAdder);
void updateGPRAMwhtioutBlendMask(uint16_t buffAdder);

void clearGPRAM(uint16_t buffAdder);
void fillGPRAM(uint16_t buffAdder);

void maskGPRAM(uint16_t buffAdder);
void maskConstGPRAM(uint16_t buffAdder, uint8_t mask);

void blendGPRAM(uint16_t buffAdder);
void blendConstGPRAM(uint16_t buffAdder, uint8_t blend);

//static inline void blendArea(uint16_t buffAdder, uint8_t val, uint8_t blend){
//    uint16_t FSR0_SAVE = FSR0;
//    
//    FSR0 = buffAdder;
//    
////    WREG = blend;
//    
////    do{
////        asm("IORWF POSTINC0, F");
////    } while (-- val);
////    
//    
//    while (1){
//        if(val) POSTINC0 |= blend;//1
//        else break;
//        if(-- val) POSTINC0 |= blend;//2
//        else break;
//        if(-- val) POSTINC0 |= blend;//3
//        else break;
//        if(-- val) POSTINC0 |= blend;//4
//        else break;
//        if(-- val) POSTINC0 |= blend;//5
//        else break;
//        if(-- val) POSTINC0 |= blend;//6
//        else break;
//        if(-- val) POSTINC0 |= blend;//7
//        else break;
//        if(-- val) POSTINC0 |= blend;//8
//        else break;
//        -- val;
//    }
//    FSR0 = FSR0_SAVE;
//    
//    return;
//}

//static inline void maskArea(uint16_t buffAdder, uint8_t val, uint8_t mask){
//    uint16_t FSR0_SAVE = FSR0;
//    
//    FSR0 = buffAdder;
//    
//    WREG = mask;
//    
//    do{
//        asm("ANDWF POSTINC0, F");
//    } while (-- val);
//    
//    FSR0 = FSR0_SAVE;
//    
//    return;
//}

void blendArea(uint16_t buffAdder, uint8_t val, uint8_t blend);
void maskArea(uint16_t buffAdder, uint8_t val, uint8_t mask);
void blendArea0_255(uint16_t buffAdder, uint8_t val, uint8_t blend);
void maskArea0_255(uint16_t buffAdder, uint8_t val, uint8_t mask);