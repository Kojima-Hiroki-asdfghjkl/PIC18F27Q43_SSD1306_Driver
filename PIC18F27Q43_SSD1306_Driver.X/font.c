#include <xc.h>

#include "font.h"
#include "SSD1306_Parameter.h"

void copyFontMemoryDMA8x8(uint16_t address, uint16_t charVal){
    //実際に運用するときは，spiのフラッシュから読み出して，それを詰めるので，この関数は使用しない
    //今回は仮で，フラッシュから読み出すので，dmaをそれ用の設定にする
    //dma2を借りる形になる
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_GPRAM;
    DMAnCON0bits.EN = 0;
    DMAnCON1 |= 0x08;//PFM -> GPR
    DMAnSSA = (uint24_t)(((uint24_t)&misaki_8x8_font) + (uint24_t)(font_char_offset * charVal));
//    DMAnSSA = (uint24_t)(((uint24_t)&misaki_8x8_font) + 8);
    DMAnSSZ = 8;
    DMAnDSA = address;
    DMAnDSZ = 8;
    DMAnCON0bits.SIRQEN = 0;
    DMAnCON0bits.EN = 1;
    DMAnCON0bits.DGO = 1;
    while (DMAnCON0bits.DGO);
    DMASELECT = dmaSave;
    return ;
    
}

void copyFontMemoryDMA8x6(uint16_t address, uint16_t charVal){
    //実際に運用するときは，spiのフラッシュから読み出して，それを詰めるので，この関数は使用しない
    //今回は仮で，フラッシュから読み出すので，dmaをそれ用の設定にする
    //dma2を借りる形になる
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_GPRAM;
    DMAnCON0bits.EN = 0;
    DMAnCON1 |= 0x08;//PFM -> GPR
    DMAnSSA = (uint24_t)(((uint24_t)&font5x5) + (uint24_t)(6 * charVal));
//    DMAnSSA = (uint24_t)(((uint24_t)&misaki_8x8_font) + 8);
    DMAnSSZ = 6;
    DMAnDSA = address;
    DMAnDSZ = 6;
    DMAnCON0bits.SIRQEN = 0;
    DMAnCON0bits.EN = 1;
    DMAnCON0bits.DGO = 1;
    while (DMAnCON0bits.DGO);
    DMASELECT = dmaSave;
    return ;
    
}
void copyFontMemoryDMA8x6Left(uint16_t address, uint16_t charVal){
    //実際に運用するときは，spiのフラッシュから読み出して，それを詰めるので，この関数は使用しない
    //今回は仮で，フラッシュから読み出すので，dmaをそれ用の設定にする
    //dma2を借りる形になる
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_GPRAM;
    DMAnCON0bits.EN = 0;
    DMAnCON1 |= 0x08;//PFM -> GPR
    DMAnSSA = (uint24_t)(((uint24_t)&font5x5Left) + (uint24_t)(6 * charVal));
//    DMAnSSA = (uint24_t)(((uint24_t)&misaki_8x8_font) + 8);
    DMAnSSZ = 6;
    DMAnDSA = address;
    DMAnDSZ = 6;
    DMAnCON0bits.SIRQEN = 0;
    DMAnCON0bits.EN = 1;
    DMAnCON0bits.DGO = 1;
    while (DMAnCON0bits.DGO);
    DMASELECT = dmaSave;
    return ;
    
}

void copyPageFromPFMToGPR(uint24_t sAdd, uint16_t dAdd){
    //実際に運用するときは，spiのフラッシュから読み出して，それを詰めるので，この関数は使用しない
    //今回は仮で，フラッシュから読み出すので，dmaをそれ用の設定にする
    //dma2を借りる形になる
    uint8_t dmaSave = DMASELECT;
    DMASELECT = DMA_GPRAM;
    DMAnCON0bits.EN = 0;
    DMAnCON1 |= 0x08;//PFM -> GPR
    DMAnSSA = sAdd;
    DMAnSSZ = 128;
    DMAnDSA = dAdd;
    DMAnDSZ = 128;
    DMAnCON0bits.SIRQEN = 0;
    DMAnCON0bits.EN = 1;
    DMAnCON0bits.DGO = 1;
    while (DMAnCON0bits.DGO);
    DMASELECT = dmaSave;
    return ;
}