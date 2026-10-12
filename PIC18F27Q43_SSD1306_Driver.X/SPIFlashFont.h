/* 
 * File:   SPIFlash_Font.h
 * Author: kojim
 *
 * Created on 2026/10/01, 9:48
 */

#pragma once
#include <stdint.h>

//DMA
#define DMA_SPI_TX 2//3
#define DMA_SPI_RX 3//4

//SPI
//#define SPI1_TX_COMP_INT_EN() PIE3bits.SPI1IE = 1
//#define SPI1_TX_COMP_INT_DISABLE() PIE3bits.SPI1IE = 0
#define SPI1_TX_COMP_INT_EN() do { SPI1INTEbits.SPI1TCZIE = 1; LATB ^= 0x10; } while (0)
#define SPI1_TX_COMP_INT_DISABLE() do { SPI1INTEbits.SPI1TCZIE = 0; LATB ^= 0x20; } while (0)
#define SPI1_TX_COMP_INT_CLRF() SPI1INTFbits.SPI1TCZIF = 0;

//spiFlashMemory
/*
 * =============================================================================
 * SPI Flash (W25Q64FV / 8MB) Memory Map
 * =============================================================================
 * 0x000000 +-----------------------------------+
 *          | 8x8 Font                          | 512 KB
 *          | 0x00 - 0x07 : MSByte              |
 * 0x080000 +-----------------------------------+
 *          | 16x16 Font                        | 2 MB
 *          | 0x08 - 0x27                       |
 * 0x280000 +-----------------------------------+
 *          | 6x6 Font                          | 384 KB
 *          | 0x28 - 0x2D                       |
 * 0x2E0000 +-----------------------------------+
 *          | SJIS -> UTF-16 Translation Table  | 128 KB
 *          | 0x2E - 0x2F                       |
 * 0x300000 +-----------------------------------+
 *          | Free Area / Bitmaps               | 5 MB
 *          | 0x30 - 0x7F                       |
 * 0x800000 +-----------------------------------+
 * =============================================================================
 */

#define FONT8x8OffsetAddress      0x000000
#define FONT8x8OffsetUpperAdd     0x00
#define FONT8x8Size               8
#define FONT8x8Type               0
#define FONT16x16OffsetAddress    0x080000
#define FONT16x16OffsetUpperAdd   0x08
#define FONT16x16Size             32
#define FONT16x16Type             1
#define FONT6x6OffsetAddress      0x280000
#define FONT6x6OffsetUpperAdd     0x28
#define FONT6x6Size               6
#define FONT6x6Type               2
#define SJISToUTF16TableOffset    0x2E0000
#define SJISToUTF16OffsetUpperAdd 0x2E
#define SJISToUTF16Size           2
#define SJISToUTF16Type           3
#define FreeAreaOffset            0x300000
#define FreeAreaOffsetUpperAdd    0x30
#define FreeAreaType              4

static inline uint8_t GetFlashAreaType(uint8_t Address){
    if (Address < FONT16x16OffsetUpperAdd){
        return FONT8x8Type;
    }
    else if (Address < FONT6x6OffsetUpperAdd){
        return FONT16x16Type;
    }
    else if (Address < SJISToUTF16OffsetUpperAdd){
        return FONT6x6Type;
    }
    else if (Address < FreeAreaOffsetUpperAdd){
        return SJISToUTF16Type;
    }
    else {
        return FreeAreaType;
    }
}

static inline uint8_t GetFlashReadSize(uint8_t Type){
    switch (Type){
        case FONT8x8Type:
            return FONT8x8Size;
        case FONT16x16Type:
            return FONT16x16Size;
        case FONT6x6Type:
            return FONT6x6Size;
        case SJISToUTF16Type:
            return SJISToUTF16Size;
        default :
            return 0x00;
    }
}

typedef struct {
    uint8_t command;
    union {
        uint24_t addressU24;
        uint8_t addressU8[3];
    };
    uint8_t data[32];
} SpiFlashCommandBuff_t;
volatile SpiFlashCommandBuff_t spiFlashComandBuff[2];
#define font6x6Size 6
#define font8x8Size 8
#define font16x16Size 32

uint24_t flashAdderBuff[128];//384
uint16_t SSD1306AdderBuff[128];//256
#define SAB_WRITE_MODE_MASK   0xC000//上位2ビット分はモード指定に使用する※もしかしたら使わないかも
#define SAB_WRITE_BUFF_SEL    0x2000//この位置のビットで，どちらのバッファに書き込むかを指定する
#define SAB_WRITE_BUFF_SELH   0x20  //上のやつの上位バイトのやつ
#define SAB_WRITE_PAGE_SEL    0x0C00//この位置のビットで，どのページに書き込むかを指定する
#define SAB_WRITE_PAGE_SELH   0x0C  //上のやつの上位バイトのやつ
#define SAB_WRITE_PAGE_SELH_0 0x00  //ページ0
#define SAB_WRITE_PAGE_SELH_1 0x04  //ページ1
#define SAB_WRITE_PAGE_SELH_2 0x08  //ページ2
#define SAB_WRITE_PAGE_SELH_3 0x0C  //ページ3
#define SAB_WRITE_PAGE_SEL_0  0x0000//ページ0
#define SAB_WRITE_PAGE_SEL_1  0x0400//ページ1
#define SAB_WRITE_PAGE_SEL_2  0x0800//ページ2
#define SAB_WRITE_PAGE_SEL_3  0x0C00//ページ3

#define SAB_WRITE_COLUMN_ADD  0x03FF//この位置のビットで，書き込みを開始するカラムを指定する
#define SAB_WRITE_COLUMN_ADDH 0x03//上位バイトのマスク
uint8_t spiCommandLen;//コマンドの長さを指定する．連続モードの場合には，転送する長さを指定する．
uint8_t spiCommandCounter;//現在どこまで処理したかをカウントする

uint8_t spiFlashToBuffFlag;
#define SFBF_FLASH_BUFF_SEL 0x01//フラッシュから読み出すバッファを切り換えるフラグ
#define SFBF_SSD1306BUFF_SEQUENTIAL 0x02//バッファに積めるときに，連続で書き込むか，バッファに書かれたアドレスを使用して，分散的に書き込むかを指定する
#define SFBF_SSD1306BUFF_SEQ_GPBUFF 0x04//バッファに連続で書き込むモードの際，GPBUFF領域に限定するかどうか
#define SFBF_SSD1306BUFF_SEQ_PAGE   0x08//バッファに連続で書き込む際に，ページ内でループするかどうか
#define SFBF_FONT_

//SPI Flash Commands -----------------------------------------------------------
#define FLASH_COMM_READ   0x03
#define FLASH_COMM_FREAD  0x0B
#define FLASH_COMM_SLEEP  0xB9
#define FLASH_COMM_ENABLE 0xAB
#define FLASH_COMM_ENRST  0x66
#define FLASH_COMM_RESET  0x99

void spiFlashToBuffStateMachine();