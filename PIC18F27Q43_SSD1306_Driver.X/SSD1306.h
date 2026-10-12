/* 
 * File:   SSD1306.h
 * Author: kojim
 *
 * Created on 2026/09/20, 17:28
 */

#pragma once

#include <xc.h>
#include <stdint.h>

#include "SSD1306_Parameter.h"


//VARIABLE ---------------------------------------------------------------------
typedef struct {
    uint8_t GPRAM[128];//スクロールを使用しない際の，描画領域．50mSごとに自動で更新される
    uint8_t ExRAM[256];//スクロール用の拡張領域．設定すれば同じようにも使える
    //SUM 400 Byte
} GPBUFF_Page_t;
//ここを変更した時はアセンブラをくまなく確認すること
//意外とある

#define BUFFx_PAGE_SIZE (sizeof(GPBUFF_Page_t))

typedef union {
    GPBUFF_Page_t Page[4];
    struct {
        GPBUFF_Page_t PAGE0;
        GPBUFF_Page_t PAGE1;
        GPBUFF_Page_t PAGE2;
        GPBUFF_Page_t PAGE3;
    };
} GPBUFF_t;

typedef uint8_t GPMASK_t[4][128];
typedef uint8_t GPBLEND_t[4][128];

extern GPBUFF_t GPBUFF_A, GPBUFF_B;
extern volatile GPMASK_t GPMASK;
extern volatile GPBLEND_t GPBLEND;

extern uint8_t i2cLockStatus;
#define I2CLOCK 1
#define I2CFREE 0

//自動画面更新オンオフ
#define SSD1306_EN_UPDATE() PIE4bits.PWM1PIE = 1
#define SSD1306_DISABLE_UPDATE() PIE4bits.PWM1PIE = 0
#define SSD1306_GET_UPDATE_STAT() (PIE4bits.PWM1PIE)

//画面更新に使用するI2Cの割り込みオンオフ
#define SSD1306_TX_DMA_EN() PIE2bits.DMA1SCNTIE = 1
#define SSD1306_TX_DMA_DISABLE() PIE2bits.DMA1SCNTIE = 0
#define SSD1306_TX_DMA_CLRF() PIR2bits.DMA1SCNTIF = 0

//画面更新系のフラグ
extern uint8_t buffStatFlag;
#define BSF_BA_UREADY 0x80//buffA更新待ち
#define BSF_BB_UREADY 0x40//buffB更新待ち
#define BSF_CLRA_UREADY 0x20//buffA更新待ち消去フラグ
#define BSF_CLRB_UREADY 0x10//buffA更新待ち消去フラグ
/* 説明
 * 7:buffA更新待ち
 * 6:buffB更新待ち
 * 5:
 * 4:
 * 3:
 * 2:
 * 1:
 * 0:
 */

extern uint8_t buffAStatFlag0;
#define BASF0_DRAW_COUNTER_MASK 0x03//自動で転送する際に，現在のページを保持する為のフラグのマスク
#define BASF0_DMA_SCROLL_EN 0x04//DMAの転送開始番地を変更して，スクロールをする為のフラグ
#define BASF0_DMA_SCROLL_STAT 0x08//DMAのスクロールをする際に，ページ内で境界をまたぐ際に自動で立つフラグ．ステートマシン以外読み込み専用
#define BASF0_DMA_SCROLL_CLEAR 0x10//DMAのスクロールをする際，境界をまたいだ場合に0番地から開始するか，残りの増分を加えるかのフラグ
#define BASF0_DMA_SOURCE 0x20//DMAでバッファを転送する際に，メモリか，フラッシュのどちらから転送するかを設定するフラグ

extern uint8_t buffADmaScrollFlag0;
#define BADSF0_PAGE0_SC_EN 0x01//ページ0のスクロールを有効にする
#define BADSF0_PAGE1_SC_EN 0x02
#define BADSF0_PAGE2_SC_EN 0x04
#define BADSF0_PAGE3_SC_EN 0x08
#define BADSF0_PAGE0_SC_DIR 0x10//ページ0のスクロール方向を設定する(0:左方向，1:右方向)
#define BADSF0_PAGE1_SC_DIR 0x20
#define BADSF0_PAGE2_SC_DIR 0x40
#define BADSF0_PAGE3_SC_DIR 0x80

extern uint8_t buffADmaScrollFlag1;//ステートマシンで自動的に更新されるため，書き込み禁止
#define BADSF1_PAGE0_SC_READY 0x01//このフラグは，自動スクロールが有効の際，転送準備が完了した場合に自動で立ち，転送が完了した場合に，自動で下がる
#define BADSF1_PAGE1_SC_READY 0x02
#define BADSF1_PAGE2_SC_READY 0x04
#define BADSF1_PAGE3_SC_READY 0x08
#define BSDAF1_PAGE0_SC_ADDER 0x10//このフラグは，自動スクロール機能時自動で，SSD1306のアドレスを自動で更新するフラグ．必要な際は自動で立ち，設定完了した場合は，自動で下がる
#define BSDAF1_PAGE1_SC_ADDER 0x20
#define BSDAF1_PAGE2_SC_ADDER 0x40
#define BSDAF1_PAGE3_SC_ADDER 0x80

extern uint16_t buffAScrollAdderP0;//DMAのScrollをする際に，転送開始アドレスを保持する為の変数
extern uint16_t buffAScrollSizeP0;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
extern uint16_t buffAScrollStartP0;//DMAのスクロールをする際に，スタートさせるページを指定する
extern uint8_t buffAScrollRolloverP0;//境界をまたいだ後の残り転送量
extern uint8_t buffAScrollUpP0;//一回ごとのスクロールの増分

extern uint16_t buffAScrollAdderP1;//DMAのScrollをする際に，転送開始アドレスを保持する為の変数
extern uint16_t buffAScrollSizeP1;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
extern uint16_t buffAScrollStartP1;//DMAのスクロールをする際に，スタートさせるページを指定する
extern uint8_t buffAScrollRolloverP1;//境界をまたいだ後の残り転送量
extern uint8_t buffAScrollUpP1;//一回ごとのスクロールの増分

extern uint16_t buffAScrollAdderP2;//DMAのScrollをする際に，転送開始アドレスを保持する為の変数
extern uint16_t buffAScrollSizeP2;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
extern uint16_t buffAScrollStartP2;//DMAのスクロールをする際に，スタートさせるページを指定する
extern uint8_t buffAScrollRolloverP2;//境界をまたいだ後の残り転送量
extern uint8_t buffAScrollUpP2;//一回ごとのスクロールの増分

extern uint16_t buffAScrollAdderP3;//DMAのScrollをする際に，転送開始アドレスを保持する為の変数
extern uint16_t buffAScrollSizeP3;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
extern uint16_t buffAScrollStartP3;//DMAのスクロールをする際に，スタートさせるページを指定する
extern uint8_t buffAScrollRolloverP3;//境界をまたいだ後の残り転送量
extern uint8_t buffAScrollUpP3;//一回ごとのスクロールの増分

extern uint8_t buffBStatFlag;
#define BBSF_DRAW_COUNTER_MASK 0x03

#define DMA_SET_SOURCE_PFM() do { DMAnCON1 |=  0x08; } while (0)//PFM -> SFR
#define DMA_SET_SOURCE_GPR() do { DMAnCON1 &= ~0x08; } while (0)//GPR -> SFR
#define DMA_SELECT(DMANUM) do {DMASELECT = DMANUM; } while (0)//DMAを選ぶ

#define I2C_SURPLUS_COUNT 8

//FUNC -------------------------------------------------------------------------
//初期化用関数(DMA使用)
static inline void initSSD1306(){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_PFM();
    DMAnSSZ = (uint16_t)SSD1306InitComm[0];
    DMAnSSA = (uint24_t)&SSD1306InitComm[1];
    DMAnCON0bits.EN = 1;
    I2C1CNT = SSD1306InitComm[0] + 1;
    I2C1TXB = SSD1306_CTRL_CMD_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

//ページA書き込み指定関数(DMA使用)
static inline void SSD1306SetAddA(){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_PFM();
    DMAnSSZ = (uint16_t)SSD1306SetAddAComm[0];
    DMAnSSA = (uint24_t)&SSD1306SetAddAComm[1];
    DMAnCON0bits.EN = 1;
    I2C1CNT = SSD1306SetAddAComm[0] + 1;
    I2C1TXB = SSD1306_CTRL_CMD_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

typedef struct{
    uint8_t columnCom;
    uint8_t columnStart;
    uint8_t columnEnd;
    uint8_t pageCom;
    uint8_t pageStart;
    uint8_t pageEnd;
} SSD1306SetAddress_t;
SSD1306SetAddress_t SSD1306SetAddressBuff = {
    .columnCom = 0x21,
    .pageCom = 0x22
};

static inline void SSD1306SetAdd(){
    //この関数はマクロからのみ叩く
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = (uint16_t)6;
    DMAnSSA = (uint16_t)&SSD1306SetAddressBuff;
    DMAnCON0bits.EN = 1;
    I2C1CNT = 6 + 1;
    I2C1TXB = SSD1306_CTRL_CMD_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

//書き込みアドレス指定関数(この関数は開始場所を指定して，終わりは最後になる．モードは変更しない)
#define SSD1306SetAddS(column, page)\
do {\
    SSD1306SetAddressBuff.columnStart = (uint8_t)column;\
    SSD1306SetAddressBuff.columnEnd = 127;\
    SSD1306SetAddressBuff.pageStart = (uint8_t)page;\
    SSD1306SetAddressBuff.pageEnd = 7;\
    SSD1306SetAdd();\
}while (0)

//書き込みアドレス指定関数(この関数は開始場所と，終了場所を指定する．モードは変更しない)
#define SSD1306SetAddSE(columnStart, pageStart, columnEnd, pageEnd)\
do {\
    SSD1306SetAddressBuff.columnStart = (uint8_t)columnStart;\
    SSD1306SetAddressBuff.columnEnd = (uint8_t)columnEnd;\
    SSD1306SetAddressBuff.pageStart = (uint8_t)pageStart;\
    SSD1306SetAddressBuff.pageEnd = (uint8_t)pageEnd;\
    SSD1306SetAdd();\
}while (0)

//ページ転送用関数(DMA使用)
static inline void SSD1306DrawPage(volatile uint16_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = (uint16_t)128;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = 128 + 1;
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageFromPFM(uint24_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_PFM();
    DMAnSSZ = (uint16_t)128;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = 128 + 1;
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

//ほぼステートマシン専用の関数
static inline void SSD1306DrawPageStart(uint16_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = 128;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = (volatile uint8_t)(128 + 1 + I2C_SURPLUS_COUNT);//転送完了後もストップコンディション出ない様に1つ多めにしておく
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageStartDMASize(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = (volatile uint8_t)(128 + 1 + I2C_SURPLUS_COUNT);//転送完了後もストップコンディション出ない様に1つ多めにしておく
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageStartTXSize(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = (volatile uint8_t)(size + 1 + I2C_SURPLUS_COUNT);//転送完了後もストップコンディション出ない様に1つ多めにしておく
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageStartDmaTXSize(uint16_t buffAdder, uint8_t dmaSize, uint8_t TXSize){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = dmaSize;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = (volatile uint8_t)(TXSize + 1 + I2C_SURPLUS_COUNT);//転送完了後もストップコンディション出ない様に1つ多めにしておく
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

static inline void SSD1306DrawPageContinue(uint16_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSA = buffAdder;
    DMAnSSZ = 128;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)128;//多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageContinueDmaSize(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)128;//多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageContinueTXSize(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)size;//多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageContinueDmaTXSize(uint16_t buffAdder, uint8_t DmaSize, uint8_t TXSize){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = DmaSize;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)TXSize;//多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageContinueDmaOnly(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

static inline void SSD1306DrawPageEnd( uint16_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSA = buffAdder;
    DMAnSSZ = 128;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)(128 - I2C_SURPLUS_COUNT);//元々1バイト多かったので，一バイト少なくしておく．多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageEndDmaSize(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)(128 - I2C_SURPLUS_COUNT);//元々1バイト多かったので，一バイト少なくしておく．多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageEndTxSize(uint16_t buffAdder, uint8_t size){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = size;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)(size - I2C_SURPLUS_COUNT);//元々1バイト多かったので，一バイト少なくしておく．多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageEndDmaTxSize(uint16_t buffAdder, uint8_t dmaSize, uint8_t TXSize){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSZ = dmaSize;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)(TXSize - I2C_SURPLUS_COUNT);//元々1バイト多かったので，一バイト少なくしておく．多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

static inline void SSD1306DrawPageStartFromPFM(uint24_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_PFM();
    DMAnSSZ = 128;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT = (volatile uint8_t)(128 + 1 + I2C_SURPLUS_COUNT);//転送完了後もストップコンディション出ない様に1つ多めにしておく
    I2C1TXB = SSD1306_CTRL_DATA_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageContinueFromPFM(uint24_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)128;//多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}
static inline void SSD1306DrawPageEndFromPFM(uint24_t buffAdder){
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMAnSSA = buffAdder;
    DMAnCON0bits.EN = 1;
    I2C1CNT += (volatile uint8_t)(128 - I2C_SURPLUS_COUNT);//元々1バイト多かったので，一バイト少なくしておく．多分アトミックな操作
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

typedef struct{
    uint8_t offsetCom;
    uint8_t offset;
} SSD1306VerticalOffset_t;
SSD1306VerticalOffset_t SSD1306SetVerticalOffsetBuff = {
    .offsetCom = 0xD3
};

//この関数は，SSD1306本体の描画範囲を選択します．これをいじると，縦方向にスクロールできます
static inline void SSD1306SetVerticalOffset(uint8_t offset){
    SSD1306SetVerticalOffsetBuff.offset = (offset & 0x3F);
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = (uint16_t)2;
    DMAnSSA = (uint16_t)&SSD1306SetVerticalOffsetBuff;
    DMAnCON0bits.EN = 1;
    I2C1CNT = 2 + 1;
    I2C1TXB = SSD1306_CTRL_CMD_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

typedef struct{
    uint8_t offsetComL;
    uint8_t offsetComH;
} SSD1306HorizontalOffset_t;
SSD1306HorizontalOffset_t SSD1306SetHorizontalOffsetBuff;

static inline void SSD1306SetHorizontalOffset(uint8_t offset){
    SSD1306SetHorizontalOffsetBuff.offsetComL = (offset & 0x0F);
    SSD1306SetHorizontalOffsetBuff.offsetComH = (((offset >> 4) & 0x07) | 0x10);
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_I2C_TX;
    DMAnCON0bits.EN = 0;
    DMA_SET_SOURCE_GPR();
    DMAnSSZ = (uint16_t)2;
    DMAnSSA = (uint16_t)&SSD1306SetHorizontalOffsetBuff;
    DMAnCON0bits.EN = 1;
    I2C1CNT = 2 + 1;
    I2C1TXB = SSD1306_CTRL_CMD_STREAM;
    I2C1CON0bits.S = 1;
    DMAnCON0bits.SIRQEN = 1;
    DMASELECT = dmaSave;
}

////旧関数
//static inline void SSD1306UpdateDrawSM(){
//    LATA ^= 0x04;//後で消す
//    if (buffStatFlag & BSF_BA_UREADY){
//        if ((buffAStatFlag0 & BASF0_DMA_SOURCE) == 0){//GPR -> I2C
//            if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){
//                SSD1306DrawPageStart((uint16_t)&GPBUFF_A.Page[0].GPRAM[0]);
//                buffAStatFlag0 ++;
//                SSD1306_TX_DMA_CLRF();
//                SSD1306_TX_DMA_EN();
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[1].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[2].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else {
//                SSD1306DrawPageEnd((uint16_t)&GPBUFF_A.Page[3].GPRAM[0]);
//                buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
//                SSD1306_TX_DMA_DISABLE();
//                if (buffStatFlag & BSF_CLRA_UREADY) buffStatFlag &= ~BSF_BA_UREADY;
//            }
//        }
//        else {//PFM -> I2C
//            if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){
//                SSD1306DrawPageStart((uint16_t)&GPBUFF_A.Page[0].GPRAM[0]);//ここら辺は後で書き換える
//                buffAStatFlag0 ++;
//                SSD1306_TX_DMA_CLRF();
//                SSD1306_TX_DMA_EN();
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[1].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[2].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else {
//                SSD1306DrawPageEnd((uint16_t)&GPBUFF_A.Page[3].GPRAM[0]);
//                buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
//                SSD1306_TX_DMA_DISABLE();
//                if (buffStatFlag & BSF_CLRA_UREADY) buffStatFlag &= ~BSF_BA_UREADY;
//            }
//        }
//    }
//    else if (buffStatFlag & BSF_BB_UREADY){
//        if ((buffAStatFlag0 & BASF0_DMA_SOURCE) == 0){//GPR -> I2C
//            if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){
//                SSD1306DrawPageStart((uint16_t)&GPBUFF_B.Page[0].GPRAM[0]);
//                buffAStatFlag0 ++;
//                SSD1306_TX_DMA_CLRF();
//                SSD1306_TX_DMA_EN();
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_B.Page[1].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_B.Page[2].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else {
//                SSD1306DrawPageEnd((uint16_t)&GPBUFF_B.Page[3].GPRAM[0]);
//                buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
//                SSD1306_TX_DMA_DISABLE();
//                if (buffStatFlag & BSF_CLRA_UREADY) buffStatFlag &= ~BSF_BA_UREADY;
//            }
//        }
//        else {//PFM -> I2C
//            if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){
//                SSD1306DrawPageStart((uint16_t)&GPBUFF_B.Page[0].GPRAM[0]);//ここら辺は後で書き換える
//                buffAStatFlag0 ++;
//                SSD1306_TX_DMA_CLRF();
//                SSD1306_TX_DMA_EN();
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_B.Page[1].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){
//                SSD1306DrawPageContinue((uint16_t)&GPBUFF_B.Page[2].GPRAM[0]);
//                buffAStatFlag0 ++;
//            }
//            else {
//                SSD1306DrawPageEnd((uint16_t)&GPBUFF_B.Page[3].GPRAM[0]);
//                buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
//                SSD1306_TX_DMA_DISABLE();
//                if (buffStatFlag & BSF_CLRA_UREADY) buffStatFlag &= ~BSF_BA_UREADY;
//            }
//        }
//    }
//}

void SSD1306StateMachine(void);