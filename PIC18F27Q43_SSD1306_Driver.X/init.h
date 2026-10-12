/* 
 * File:   init.h
 * Author: kojim
 *
 * Created on 2026/09/20, 17:54
 */

#pragma once

#include <xc.h>
#include <stdint.h>

#include "SSD1306_Parameter.h"
#include "SPIFlashFont.h"

static inline void init(){
    //IO SETTING ---------------------------------------------------------------
    //PORTA
    TRISA = 0x00;
    LATA = 0x01;
    
    //PORTB
    TRISB = 0x00;
    ANSELB = 0x00;
    LATB = 0x00;
    ODCONB = 0x03;//RB0, 1 OPEN DRAIN
    WPUB = 0x03;
    
    //PORTC
    TRISC = 0x04;
    ANSELC = 0x00;
    SLRCONC = 0xF4;
    
    //PPS SETTING---------------------------------------------------------------
    //I2C
    //INPUT
    I2C1SDAPPS = 0b001001;//RB1
    I2C1SCLPPS = 0b001000;//RB0
    //OUTPUT
    RB1PPS = 0x38;//SDA
    RB0PPS = 0x37;//SCL
    
    //SPI
    //INPUT
    SPI1SDIPPS = 0x12;//RC2
    //OUTPUT
    RC1PPS = 0x31;//SPI1SKCK
    RC0PPS = 0x32;//SPI1SDO
    RC3PPS = 0x33;//SPI1SS
    
    //OSC SETTING --------------------------------------------------------------
    OSCEN = 0x20;//MFINTOSC
    while (OSCSTATbits.MFOR == 0);//WAITINT FOR MFINTOSC_READY
    
    //TIMER2 SETTING : 2MHz ----------------------------------------------------
    T2PR = 27;//2Mにしたいなら31にする．いまは533k
    T2CON = 0x80;//TMR2:EN, 1:1PRE, 1:1POST
    T2HLT = 0x00;//HLT:DISABLE
    T2CLKCON = 0x02;//Fosc(64MHz)
    
    //I2C SETTING 400KHz -------------------------------------------------------
    I2C1CON0 = 0b10000100;//I2C MASTER(HOST MODE?)
    I2C1CON1 = 0b10000000;
    I2C1CON2 = 0b00000010;//SCL frequency (FSCL) = FI2CxCLK/5
    I2C1CLK = 0x07;//TMR2_POST_OUT(2MHz)
    I2C1CNT = 0;
    I2C1ADB1 = SSD1306_I2C_ADDER;//SSD1306 ADDER
//    I2C1ADB1 = 0x10;
    
    I2C1PIE = 0x80;
    
    //SPI1 SETTING : Fclk = FOSC -----------------------------------------------
    SPI1CON0 = 0x83;
    SPI1CON1 = 0x44;//SPI:Mode0
    SPI1CON2 = 0x03;
    SPI1CLK = 0x00;
    SPI1BAUD = 2;
//    SPI1INTE = 0x40;//TCZIE
    SPI1INTE = 0x00;
    
    //SYSTEM SETTING -----------------------------------------------------------
    //SYSTEM ARBITER
    ISRPR  = 0x03;
    MAINPR = 0x05;
    DMA1PR = 0x00;//buff->i2c
    DMA2PR = 0x02;//buff->buff
    DMA3PR = 0x01;//BUFF -> SPITX
    DMA4PR = 0x00;//SPIRX -> BUFF
    
    PRLOCK = 0x55;
    PRLOCK = 0xAA;
    PRLOCKbits.PRLOCKED = 1;
    
    //DMA SETTING --------------------------------------------------------------
    //DMA1:PRIORITY_0, BUFF -> I2C
    DMASELECT = DMA_I2C_TX;
    DMAnCON0 = 0x40;//SIRQEN:EN
    DMAnCON1 = 0x03;//SFR->GPR, SMODE:INCREMENT, SSTP:EN
    DMAnSSA = (uint16_t)0;
    DMAnSSZ = 0;
    DMAnDSA = (uint16_t)&I2C1TXB;
    DMAnDSZ = 1;
    DMAnSIRQ = 0x39;//I2C1TX
    
    //DMA2:PRIORITY_2, BUFF -> BUFF
    DMASELECT = DMA_GPRAM;
    DMAnCON0 = 0x40;//SIRQEN:EN
    DMAnCON1 = 0x43;//SFR->GPR, DMODE:INCREMENT, SMODE:INCREMENT, SSTP:EN
    DMAnSSA = (uint16_t)0;
    DMAnSSZ = 0;
    DMAnDSA = (uint16_t)0;
    DMAnDSZ = 0;
    
    //DMA3:PRIORITY_1, BUFF -> SPITX
    DMASELECT = DMA_SPI_TX;//3
    DMAnCON0 = 0x40;//SIRQEN:EN
    DMAnCON1 = 0x03;//GPR->SFR, SMODE:INCREMENT, SSTP:EN
    DMAnSSA = (uint16_t)0;
    DMAnSSZ = 0;
    DMAnDSA = (uint16_t)&SPI1TXB;
    DMAnDSZ = 1;
    DMAnSIRQ = 0x19;//SPI1TX
    
    //DMA4:PRIORITY_0, SPI1RX -> BUFF
    DMASELECT = DMA_SPI_RX;//4
    DMAnCON0 = 0x40;//SIRQEN:EN
    DMAnCON1 = 0x60;//SFR->GPR, DMODE:INCREMENT, DSTP:EN, SFR->GPR
    DMAnSSA = (uint16_t)&SPI1RXB;
    DMAnSSZ = 1;
    DMAnDSA = (uint16_t)0;
    DMAnDSZ = 0;
    DMAnSIRQ = 0x18;//SPI1RX
    
    //PWM SETTING --------------------------------------------------------------
    //PWM1 20Hz (50mS)
    PWM1CLK = 0x05;//MFINTOSC(500KHz)
    PWM1LDS = 0x00;
    PWM1PR = 249;//20Hz
    PWM1CPRE = 99;//100:1
    PWM1PIPOS = 0x00;//1:1
    PWM1GIE = 0x00;
    PWM1S1CFG = 0x00;
    PWM1CON = 0x80;
    
    //INT SETTING --------------------------------------------------------------
    INTCON0 = 0xE0;
    IPR2bits.DMA1SCNTIP = 0;
//    PIE4bits.PWM1PIE = 1;
    IPR4bits.PWM1PIP = 0;//LOW
//    PIE7bits.I2C1IE = 1;
//    IPR7bits.I2C1IP = 0;
    
    IPR3bits.SPI1IP = 0;//SPIのパケット送受信完了割り込みの優先度
    PIE3bits.SPI1IE = 1;
}