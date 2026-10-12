#include <xc.h>

#include "SSD1306.h"
#include "SSD1306BuffFunc.h"


void updateGPRAM(uint16_t buffAdder){
    uint16_t FSR0_SAVE = FSR0;
    uint16_t FSR1_SAVE = FSR1;
    uint16_t FSR2_SAVE = FSR2;
    
    FSR0 = buffAdder;
    FSR1 = (uint16_t)&GPMASK;
    FSR2 = (uint16_t)&GPBLEND;
    
    uint8_t counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("ANDWF INDF2, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 = FSR0_SAVE;
    FSR1 = FSR1_SAVE;
    FSR2 = FSR2_SAVE;
    
    return ;
}

void updateGPRAMwhtioutBlendMask(uint16_t buffAdder){
    uint16_t FSR0_SAVE = FSR0;
    uint16_t FSR1_SAVE = FSR1;
    uint16_t FSR2_SAVE = FSR2;
    
    FSR0 = buffAdder;
    FSR1 = (uint16_t)&GPMASK;
    FSR2 = (uint16_t)&GPBLEND;
    
    uint8_t counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF INDF0, F");
        __asm__ volatile ("MOVF POSTINC2, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 = FSR0_SAVE;
    FSR1 = FSR1_SAVE;
    FSR2 = FSR2_SAVE;
    
    return ;
}

void clearGPRAM(uint16_t buffAdder){
    uint16_t FSR0_SAVE = FSR0;
    
    FSR0 = buffAdder;
    
    uint8_t counter = 8;
    do {
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
        __asm__ volatile ("CLRF POSTINC0");//1
        __asm__ volatile ("CLRF POSTINC0");//2
        __asm__ volatile ("CLRF POSTINC0");//3
        __asm__ volatile ("CLRF POSTINC0");//4
        __asm__ volatile ("CLRF POSTINC0");//5
        __asm__ volatile ("CLRF POSTINC0");//6
        __asm__ volatile ("CLRF POSTINC0");//7
        __asm__ volatile ("CLRF POSTINC0");//8
    }while (-- counter);
    
    
    FSR0 = FSR0_SAVE;
    
    return ;
}

void fillGPRAM(uint16_t buffAdder){
    uint16_t FSR0_SAVE = FSR0;
    
    FSR0 = buffAdder;
    
    uint8_t counter = 8;
    do {
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
        __asm__ volatile ("SETF POSTINC0");//1
        __asm__ volatile ("SETF POSTINC0");//2
        __asm__ volatile ("SETF POSTINC0");//3
        __asm__ volatile ("SETF POSTINC0");//4
        __asm__ volatile ("SETF POSTINC0");//5
        __asm__ volatile ("SETF POSTINC0");//6
        __asm__ volatile ("SETF POSTINC0");//7
        __asm__ volatile ("SETF POSTINC0");//8
    }while (-- counter);
    
    
    FSR0 = FSR0_SAVE;
    
    return ;
}

void maskGPRAM(uint16_t buffAdder){
    uint16_t FSR0_SAVE = FSR0;
    uint16_t FSR1_SAVE = FSR1;
    
    FSR0 = buffAdder;
    FSR1 = (uint16_t)&GPMASK;
    
    uint8_t counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 = FSR0_SAVE;
    FSR1 = FSR1_SAVE;
    
    return ;
}

void maskConstGPRAM(uint16_t buffAdder, uint8_t mask){
    uint16_t FSR0_SAVE = FSR0;
    
    FSR0 = buffAdder;
    
    WREG = mask;
    uint8_t counter = 8;
    do {
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
        __asm__ volatile ("ANDWF POSTINC0, F");//1
        __asm__ volatile ("ANDWF POSTINC0, F");//2
        __asm__ volatile ("ANDWF POSTINC0, F");//3
        __asm__ volatile ("ANDWF POSTINC0, F");//4
        __asm__ volatile ("ANDWF POSTINC0, F");//5
        __asm__ volatile ("ANDWF POSTINC0, F");//6
        __asm__ volatile ("ANDWF POSTINC0, F");//7
        __asm__ volatile ("ANDWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 = FSR0_SAVE;
    
    return ;
}

void blendGPRAM(uint16_t buffAdder){
    uint16_t FSR0_SAVE = FSR0;
    uint16_t FSR1_SAVE = FSR1;
    
    FSR0 = buffAdder;
    FSR1 = (uint16_t)&GPBLEND;
    
    uint8_t counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    do {
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("MOVF POSTINC1, W");
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 = FSR0_SAVE;
    FSR1 = FSR1_SAVE;
    
    return ;
}

void blendConstGPRAM(uint16_t buffAdder, uint8_t blend){
    uint16_t FSR0_SAVE = FSR0;
    
    FSR0 = buffAdder;
    
    uint8_t counter = 8;
    
    WREG = blend;
    do {
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    WREG = blend;
    do {
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    WREG = blend;
    do {
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    FSR0 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);
    
    counter = 8;
    WREG = blend;
    do {
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
        __asm__ volatile ("IORWF POSTINC0, F");//1
        __asm__ volatile ("IORWF POSTINC0, F");//2
        __asm__ volatile ("IORWF POSTINC0, F");//3
        __asm__ volatile ("IORWF POSTINC0, F");//4
        __asm__ volatile ("IORWF POSTINC0, F");//5
        __asm__ volatile ("IORWF POSTINC0, F");//6
        __asm__ volatile ("IORWF POSTINC0, F");//7
        __asm__ volatile ("IORWF POSTINC0, F");//8
    }while (-- counter);
    
    FSR0 = FSR0_SAVE;
    
    return ;
}


void blendArea(uint16_t buffAdder, uint8_t val, uint8_t blend){
    //valが0の時は1回IORWFする
    //valが255の時は256回IORWFする
    //ほんとはswitch caseでこれくらい最適化してくれればいいんだけど...
    //遅かったので気合いで計算gotoする
    
    //Min:40cy, Max:295cy
    //※WREG=valでバンク切り替えがなかった場合
    
    uint16_t FSR0_SAVE = FSR0;
    uint8_t FSR1L_SAVE = FSR1L;
    
    FSR0 = buffAdder;//<-最適化の為にこれは引数として渡すときにuint16_tでキャストする
    FSR1L = blend;//FSR1Lって自動退避されるから超便利だよね
    
    WREG = val;//ここはMOVFになる ここは仮にバンクをいじられたとしても，関係ない

    //ここから全部ACCESS FSR内で完結する
    //PRODもFSRもTOSもSTATUSもWREGも自動退避だから割り込んでも死なない
    __asm__ volatile ("SUBLW 0xFF");//WREG = L - WREG = 0xFF - WREG
    __asm__ volatile ("MULLW 2");//PROD = WREG * L(2)
    //これでPRODに展開される，キャリーとか影響しないし，上位まで残るからこうする

    //ここで余分なサイクルを足す
    __asm__ volatile ("MOVLW 16");//WREG = L <-ここの定数でサイクル数を調整する
    __asm__ volatile ("ADDWF PRODL, F");//PRODL += WREG
    __asm__ volatile ("MOVLW 0");//WREG = 0 <- ここは変えない
    __asm__ volatile ("ADDWFC PRODH, F");//PRODH += WREG + C
    //ここまででPROD[15:0] += 定数

    __asm__ volatile ("PUSH");//スタックを積む ここからのサイクル数は厳密にしなければならない
    //↑ TOS = PC + 2　PUSH命令万歳

    //ここからリターンスタックポインタをいじる
    //TOS[23:0] += PROD[15:0]
    __asm__ volatile ("MOVF PRODL, W");//2:1  WREG = PRODL
    __asm__ volatile ("ADDWF TOSL, F");//2:2  TOSL += WREG
    __asm__ volatile ("MOVF PRODH, W");//2:3  WREG = PRODH
    __asm__ volatile ("ADDWFC TOSH, F");//2:4 TOSH += WREG + C
    __asm__ volatile ("MOVLW 0");//2:5        WREG = 0
    __asm__ volatile ("ADDWFC TOSU, F");//2:6 TOSU += WREG + C

    __asm__ volatile ("MOVF FSR1L, W");//2:7  WREG = FSR1L(blend)
    //ここに関してはサイクル数をいじられたくなかったから，FSRを使った
    //WREG = blendなんだけど，MOVLBが入られると狂うのでこうするしかない
    //WREG使わないならもっと簡単なんだけどなぁ ﾒﾝﾄﾞｸｾ

    __asm__ volatile ("RETURN");//2:8 <- goto TOS
    //↑ PC = TOS

    //ここまでで 8 * 2 = 16 なので調整で16足す
    
    //仮にvalが255だったときは一番初めに飛ばさないといけない
    //*buffAdder ++ |= WREG
    // --- [   0 ～  15 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //   0 -   3
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //   4 -   7
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //   8 -  11
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  12 -  15

    // --- [  16 ～  31 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  16 -  19
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  20 -  23
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  24 -  27
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  28 -  31

    // --- [  32 ～  47 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  32 -  35
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  36 -  39
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  40 -  43
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  44 -  47

    // --- [  48 ～  63 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  48 -  51
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  52 -  55
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  56 -  59
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  60 -  63

    // --- [  64 ～  79 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  64 -  67
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  68 -  71
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  72 -  75
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  76 -  79

    // --- [  80 ～  95 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  80 -  83
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  84 -  87
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  88 -  91
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  92 -  95

    // --- [  96 ～ 111 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  96 -  99
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 100 - 103
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 104 - 107
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 108 - 111

    // --- [ 112 ～ 127 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 112 - 115
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 116 - 119
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 120 - 123
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 124 - 127

    // --- [ 128 ～ 143 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 128 - 131
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 132 - 135
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 136 - 139
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 140 - 143

    // --- [ 144 ～ 159 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 144 - 147
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 148 - 151
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 152 - 155
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 156 - 159

    // --- [ 160 ～ 175 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 160 - 163
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 164 - 167
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 168 - 171
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 172 - 175

    // --- [ 176 ～ 191 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 176 - 179
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 180 - 183
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 184 - 187
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 188 - 191

    // --- [ 192 ～ 207 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 192 - 195
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 196 - 199
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 200 - 203
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 204 - 207

    // --- [ 208 ～ 223 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 208 - 211
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 212 - 215
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 216 - 219
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 220 - 223

    // --- [ 224 ～ 239 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 224 - 227
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 228 - 231
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 232 - 235
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 236 - 239

    // --- [ 240 ～ 255 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 240 - 243
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 244 - 247
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 248 - 251
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 252 - 255
    
    FSR0 = FSR0_SAVE;
    FSR1L = FSR1L_SAVE;
    
    return;
}

void maskArea(uint16_t buffAdder, uint8_t val, uint8_t mask){
    //valが0の時は1回IORWFする
    //valが255の時は256回IORWFする
    //ほんとはswitch caseでこれくらい最適化してくれればいいんだけど...
    //遅かったので気合いで計算gotoする
    
    //Min:40cy, Max:295cy
    //※WREG=valでバンク切り替えがなかった場合
    
    uint16_t FSR0_SAVE = FSR0;
    uint8_t FSR1L_SAVE = FSR1L;
    
    FSR0 = buffAdder;//<-最適化の為にこれは引数として渡すときにuint16_tでキャストする
    FSR1L = mask;
    
    WREG = val;//ここはMOVFになる ここは仮にバンクをいじられたとしても，関係ない
    
    //ここから全部ACCESS FSR内で完結する
    //PRODもFSRもTOSもSTATUSもWREGも自動退避だから割り込んでも死なない
    __asm__ volatile ("SUBLW 0xFF");//WREG = L - WREG = 0xFF - WREG
    __asm__ volatile ("MULLW 2");//PROD = WREG * L(2)
    //これでPRODに展開される，キャリーとか影響しないし，上位まで残るからこうする
    
    //ここで余分なサイクルを足す
    __asm__ volatile ("MOVLW 16");//WREG = L <-ここの定数でサイクル数を調整する
    __asm__ volatile ("ADDWF PRODL, F");//PRODL += WREG
    __asm__ volatile ("MOVLW 0");//WREG = 0 <- ここは変えない
    __asm__ volatile ("ADDWFC PRODH, F");//PRODH += WREG + C
    //ここまででPROD[15:0] += 定数
    
    __asm__ volatile ("PUSH");//スタックを積む ここからのサイクル数は厳密にしなければならない
    //↑ TOS = PC + 2　PUSH命令万歳
    
    //ここからリターンスタックポインタをいじる
    //TOS[23:0] += PROD[15:0]
    __asm__ volatile ("MOVF PRODL, W");//2:1  WREG = PRODL
    __asm__ volatile ("ADDWF TOSL, F");//2:2  TOSL += WREG
    __asm__ volatile ("MOVF PRODH, W");//2:3  WREG = PRODH
    __asm__ volatile ("ADDWFC TOSH, F");//2:4 TOSH += WREG + C
    __asm__ volatile ("MOVLW 0");//2:5        WREG = 0
    __asm__ volatile ("ADDWFC TOSU, F");//2:6 TOSU += WREG + C
    
    __asm__ volatile ("MOVF FSR1L, W");//2:7  WREG = INDF1(blend)
    //ここに関してはサイクル数をいじられたくなかったから，FSRを使った
    //WREG = blendなんだけど，MOVLBが入られると狂うのでこうするしかない
    //WREG使わないならもっと簡単なんだけどなぁ ﾒﾝﾄﾞｸｾ
    
    __asm__ volatile ("RETURN");//2:8 <- goto TOS
    //↑ PC = TOS
    
    //ここまでで 8 * 2 = 16 なので調整で16足す
    
    //仮にvalが255だったときは一番初めに飛ばさないといけない
    //*buffAdder ++ |= WREG
    // --- [   0 ～  15 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //   0 -   3
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //   4 -   7
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //   8 -  11
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  12 -  15

    // --- [  16 ～  31 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  16 -  19
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  20 -  23
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  24 -  27
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  28 -  31

    // --- [  32 ～  47 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  32 -  35
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  36 -  39
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  40 -  43
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  44 -  47

    // --- [  48 ～  63 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  48 -  51
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  52 -  55
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  56 -  59
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  60 -  63

    // --- [  64 ～  79 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  64 -  67
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  68 -  71
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  72 -  75
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  76 -  79

    // --- [  80 ～  95 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  80 -  83
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  84 -  87
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  88 -  91
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  92 -  95

    // --- [  96 ～ 111 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  96 -  99
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 100 - 103
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 104 - 107
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 108 - 111

    // --- [ 112 ～ 127 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 112 - 115
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 116 - 119
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 120 - 123
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 124 - 127

    // --- [ 128 ～ 143 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 128 - 131
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 132 - 135
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 136 - 139
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 140 - 143

    // --- [ 144 ～ 159 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 144 - 147
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 148 - 151
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 152 - 155
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 156 - 159

    // --- [ 160 ～ 175 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 160 - 163
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 164 - 167
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 168 - 171
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 172 - 175

    // --- [ 176 ～ 191 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 176 - 179
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 180 - 183
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 184 - 187
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 188 - 191

    // --- [ 192 ～ 207 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 192 - 195
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 196 - 199
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 200 - 203
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 204 - 207

    // --- [ 208 ～ 223 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 208 - 211
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 212 - 215
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 216 - 219
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 220 - 223

    // --- [ 224 ～ 239 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 224 - 227
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 228 - 231
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 232 - 235
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 236 - 239

    // --- [ 240 ～ 255 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 240 - 243
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 244 - 247
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 248 - 251
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 252 - 255
    
    FSR0 = FSR0_SAVE;
    FSR1L = FSR1L_SAVE;
    
    return;
}

void blendArea0_255(uint16_t buffAdder, uint8_t val, uint8_t blend){
    //valが0の時は1回IORWFする
    //valが255の時は256回IORWFする
    //ほんとはswitch caseでこれくらい最適化してくれればいいんだけど...
    //遅かったので気合いで計算gotoする
    
    //Min:40cy, Max:295cy
    //※WREG=valでバンク切り替えがなかった場合
    
    uint16_t FSR0_SAVE = FSR0;
    uint8_t FSR1L_SAVE = FSR1L;
    
    FSR0 = buffAdder;//<-最適化の為にこれは引数として渡すときにuint16_tでキャストする
    FSR1L = blend;//FSR1Lって自動退避されるから超便利だよね
    
    WREG = val;//ここはMOVFになる ここは仮にバンクをいじられたとしても，関係ない

    //ここから全部ACCESS FSR内で完結する
    //PRODもFSRもTOSもSTATUSもWREGも自動退避だから割り込んでも死なない
    __asm__ volatile ("SUBLW 0xFF");//WREG = L - WREG = 0xFF - WREG
    __asm__ volatile ("MULLW 2");//PROD = WREG * L(2)
    //これでPRODに展開される，キャリーとか影響しないし，上位まで残るからこうする

    //ここで余分なサイクルを足す
    __asm__ volatile ("MOVLW 16");//WREG = L <-ここの定数でサイクル数を調整する
    __asm__ volatile ("ADDWF PRODL, F");//PRODL += WREG
    __asm__ volatile ("MOVLW 0");//WREG = 0 <- ここは変えない
    __asm__ volatile ("ADDWFC PRODH, F");//PRODH += WREG + C
    //ここまででPROD[15:0] += 定数

    __asm__ volatile ("PUSH");//スタックを積む ここからのサイクル数は厳密にしなければならない
    //↑ TOS = PC + 2　PUSH命令万歳

    //ここからリターンスタックポインタをいじる
    //TOS[23:0] += PROD[15:0]
    __asm__ volatile ("MOVF PRODL, W");//2:1  WREG = PRODL
    __asm__ volatile ("ADDWF TOSL, F");//2:2  TOSL += WREG
    __asm__ volatile ("MOVF PRODH, W");//2:3  WREG = PRODH
    __asm__ volatile ("ADDWFC TOSH, F");//2:4 TOSH += WREG + C
    __asm__ volatile ("MOVLW 0");//2:5        WREG = 0
    __asm__ volatile ("ADDWFC TOSU, F");//2:6 TOSU += WREG + C

    __asm__ volatile ("MOVF FSR1L, W");//2:7  WREG = FSR1L(blend)
    //ここに関してはサイクル数をいじられたくなかったから，FSRを使った
    //WREG = blendなんだけど，MOVLBが入られると狂うのでこうするしかない
    //WREG使わないならもっと簡単なんだけどなぁ ﾒﾝﾄﾞｸｾ

    __asm__ volatile ("RETURN");//2:8 <- goto TOS
    //↑ PC = TOS

    //ここまでで 8 * 2 = 16 なので調整で16足す
    
    //仮にvalが255だったときは一番初めに飛ばさないといけない
    //*buffAdder ++ |= WREG
    // --- [   0 ～  15 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //   0 -   3
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //   4 -   7
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //   8 -  11
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  12 -  15

    // --- [  16 ～  31 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  16 -  19
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  20 -  23
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  24 -  27
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  28 -  31

    // --- [  32 ～  47 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  32 -  35
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  36 -  39
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  40 -  43
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  44 -  47

    // --- [  48 ～  63 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  48 -  51
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  52 -  55
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  56 -  59
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  60 -  63

    // --- [  64 ～  79 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  64 -  67
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  68 -  71
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  72 -  75
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  76 -  79

    // --- [  80 ～  95 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  80 -  83
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  84 -  87
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  88 -  91
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  92 -  95

    // --- [  96 ～ 111 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); //  96 -  99
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 100 - 103
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 104 - 107
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 108 - 111

    // --- [ 112 ～ 127 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 112 - 115
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 116 - 119
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 120 - 123
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 124 - 127

    // --- [ 128 ～ 143 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 128 - 131
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 132 - 135
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 136 - 139
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 140 - 143

    // --- [ 144 ～ 159 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 144 - 147
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 148 - 151
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 152 - 155
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 156 - 159

    // --- [ 160 ～ 175 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 160 - 163
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 164 - 167
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 168 - 171
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 172 - 175

    // --- [ 176 ～ 191 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 176 - 179
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 180 - 183
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 184 - 187
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 188 - 191

    // --- [ 192 ～ 207 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 192 - 195
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 196 - 199
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 200 - 203
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 204 - 207

    // --- [ 208 ～ 223 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 208 - 211
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 212 - 215
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 216 - 219
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 220 - 223

    // --- [ 224 ～ 239 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 224 - 227
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 228 - 231
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 232 - 235
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 236 - 239

    // --- [ 240 ～ 255 ] ---
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 240 - 243
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 244 - 247
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); // 248 - 251
    __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F"); __asm__ volatile ("IORWF POSTINC0, F");// 252 - 254
    
    FSR0 = FSR0_SAVE;
    FSR1L = FSR1L_SAVE;
    
    return;
}

void maskArea0_255(uint16_t buffAdder, uint8_t val, uint8_t mask){
    //valが0の時は1回IORWFする
    //valが255の時は256回IORWFする
    //ほんとはswitch caseでこれくらい最適化してくれればいいんだけど...
    //遅かったので気合いで計算gotoする
    
    //Min:40cy, Max:295cy
    //※WREG=valでバンク切り替えがなかった場合
    
    uint16_t FSR0_SAVE = FSR0;
    uint8_t FSR1L_SAVE = FSR1L;
    
    FSR0 = buffAdder;//<-最適化の為にこれは引数として渡すときにuint16_tでキャストする
    FSR1L = mask;
    
    WREG = val;//ここはMOVFになる ここは仮にバンクをいじられたとしても，関係ない
    
    //ここから全部ACCESS FSR内で完結する
    //PRODもFSRもTOSもSTATUSもWREGも自動退避だから割り込んでも死なない
    __asm__ volatile ("SUBLW 0xFF");//WREG = L - WREG = 0xFF - WREG
    __asm__ volatile ("MULLW 2");//PROD = WREG * L(2)
    //これでPRODに展開される，キャリーとか影響しないし，上位まで残るからこうする
    
    //ここで余分なサイクルを足す
    __asm__ volatile ("MOVLW 16");//WREG = L <-ここの定数でサイクル数を調整する
    __asm__ volatile ("ADDWF PRODL, F");//PRODL += WREG
    __asm__ volatile ("MOVLW 0");//WREG = 0 <- ここは変えない
    __asm__ volatile ("ADDWFC PRODH, F");//PRODH += WREG + C
    //ここまででPROD[15:0] += 定数
    
    __asm__ volatile ("PUSH");//スタックを積む ここからのサイクル数は厳密にしなければならない
    //↑ TOS = PC + 2　PUSH命令万歳
    
    //ここからリターンスタックポインタをいじる
    //TOS[23:0] += PROD[15:0]
    __asm__ volatile ("MOVF PRODL, W");//2:1  WREG = PRODL
    __asm__ volatile ("ADDWF TOSL, F");//2:2  TOSL += WREG
    __asm__ volatile ("MOVF PRODH, W");//2:3  WREG = PRODH
    __asm__ volatile ("ADDWFC TOSH, F");//2:4 TOSH += WREG + C
    __asm__ volatile ("MOVLW 0");//2:5        WREG = 0
    __asm__ volatile ("ADDWFC TOSU, F");//2:6 TOSU += WREG + C
    
    __asm__ volatile ("MOVF FSR1L, W");//2:7  WREG = INDF1(blend)
    //ここに関してはサイクル数をいじられたくなかったから，FSRを使った
    //WREG = blendなんだけど，MOVLBが入られると狂うのでこうするしかない
    //WREG使わないならもっと簡単なんだけどなぁ ﾒﾝﾄﾞｸｾ
    
    __asm__ volatile ("RETURN");//2:8 <- goto TOS
    //↑ PC = TOS
    
    //ここまでで 8 * 2 = 16 なので調整で16足す
    
    //仮にvalが255だったときは一番初めに飛ばさないといけない
    //*buffAdder ++ |= WREG
    // --- [   0 ～  15 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //   0 -   3
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //   4 -   7
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //   8 -  11
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  12 -  15

    // --- [  16 ～  31 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  16 -  19
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  20 -  23
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  24 -  27
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  28 -  31

    // --- [  32 ～  47 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  32 -  35
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  36 -  39
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  40 -  43
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  44 -  47

    // --- [  48 ～  63 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  48 -  51
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  52 -  55
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  56 -  59
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  60 -  63

    // --- [  64 ～  79 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  64 -  67
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  68 -  71
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  72 -  75
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  76 -  79

    // --- [  80 ～  95 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  80 -  83
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  84 -  87
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  88 -  91
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  92 -  95

    // --- [  96 ～ 111 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); //  96 -  99
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 100 - 103
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 104 - 107
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 108 - 111

    // --- [ 112 ～ 127 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 112 - 115
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 116 - 119
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 120 - 123
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 124 - 127

    // --- [ 128 ～ 143 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 128 - 131
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 132 - 135
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 136 - 139
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 140 - 143

    // --- [ 144 ～ 159 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 144 - 147
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 148 - 151
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 152 - 155
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 156 - 159

    // --- [ 160 ～ 175 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 160 - 163
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 164 - 167
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 168 - 171
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 172 - 175

    // --- [ 176 ～ 191 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 176 - 179
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 180 - 183
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 184 - 187
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 188 - 191

    // --- [ 192 ～ 207 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 192 - 195
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 196 - 199
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 200 - 203
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 204 - 207

    // --- [ 208 ～ 223 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 208 - 211
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 212 - 215
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 216 - 219
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 220 - 223

    // --- [ 224 ～ 239 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 224 - 227
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 228 - 231
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 232 - 235
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 236 - 239

    // --- [ 240 ～ 255 ] ---
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 240 - 243
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 244 - 247
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 248 - 251
    __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); __asm__ volatile ("ANDWF POSTINC0, F"); // 252 - 254
    
    FSR0 = FSR0_SAVE;
    FSR1L = FSR1L_SAVE;
    
    return;
}

