#include "SSD1306.h"

GPBUFF_t GPBUFF_A = {}, GPBUFF_B = {};
volatile GPMASK_t GPMASK = {};
volatile GPBLEND_t GPBLEND = {};

//画面更新系のフラグ
uint8_t buffStatFlag = 0x20;
uint8_t buffAStatFlag0 = 0x04;
uint8_t buffBStatFlag = 0x00;

uint8_t buffADmaScrollFlag0 = 0x10;

uint8_t buffADmaScrollFlag1 = 0x00;//ステートマシンで自動的に更新されるため，書き込み禁止

//使用サイズは128から，ページの最大サイズまでの間で指定すること

uint16_t buffAScrollAdderP0 = 0x00;//DMAのスクロールをする際に，転送開始アドレスを保持する為の変数
uint16_t buffAScrollSizeP0 = 128;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
uint16_t buffAScrollStartP0 = 0x00;//DMAのスクロールをする際に，スタートさせるページを指定する
uint8_t buffAScrollRolloverP0 = 0x00;//境界をまたいだ後の残り転送量
uint8_t buffAScrollUpP0 = 8;//一回ごとのスクロールの増分

uint16_t buffAScrollAdderP1 = 0x00;//DMAのスクロールをする際に，転送開始アドレスを保持する為の変数
uint16_t buffAScrollSizeP1 = 192;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
uint16_t buffAScrollStartP1 = 0x00;//DMAのスクロールをする際に，スタートさせるページを指定する
uint8_t buffAScrollRolloverP1 = 0x00;//境界をまたいだ後の残り転送量
uint8_t buffAScrollUpP1 = 2;//一回ごとのスクロールの増分

uint16_t buffAScrollAdderP2 = 0x00;//DMAのスクロールをする際に，転送開始アドレスを保持する為の変数
uint16_t buffAScrollSizeP2 = 192;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
uint16_t buffAScrollStartP2 = 0x00;//DMAのスクロールをする際に，スタートさせるページを指定する
uint8_t buffAScrollRolloverP2 = 0x00;//境界をまたいだ後の残り転送量
uint8_t buffAScrollUpP2 = 2;//一回ごとのスクロールの増分

uint16_t buffAScrollAdderP3 = 0x00;//DMAのスクロールをする際に，転送開始アドレスを保持する為の変数
uint16_t buffAScrollSizeP3 = 192;//DMAのスクロールをする際に，スクロールに使用するサイズを保持する
uint16_t buffAScrollStartP3 = 0x00;//DMAのスクロールをする際に，スタートさせるページを指定する
uint8_t buffAScrollRolloverP3 = 0x00;//境界をまたいだ後の残り転送量
uint8_t buffAScrollUpP3 = 2;//一回ごとのスクロールの増分

void __interrupt(irq(IRQ_PWM1PR)) SSD1306_SYNC_INT(){
//    LATA ^= 0x01;
//    SSD1306UpdateDrawSM();
    SSD1306StateMachine();
    PIR4bits.PWM1PIF = 0;
}
void __interrupt(irq(IRQ_DMA1SCNT)) SSD1306_TX_DMA_INT(){
//    SSD1306UpdateDrawSM();
    SSD1306_TX_DMA_CLRF();
    SSD1306StateMachine();
}

//void __interrupt(irq(IRQ_I2C1)) I2C_INT(){//ほとんどテスト用
////    LATB ^= 0x08;
//    //割り込みソースによって，クリアするフラグを切り替える
//    I2C1PIR &= ~0x80;
//}

void SSD1306StateMachine(void){
    //デバッグ用にLATレジスタいっぱいいじってるけど，そのうち消す
//    LATA ^= 0x08;
    if (buffStatFlag & BSF_BA_UREADY){
        if ((buffAStatFlag0 & BASF0_DMA_SCROLL_EN) == 0){//自動スクロールをしない設定のとき
            if ((buffAStatFlag0 & BASF0_DMA_SOURCE) == 0){//GPR空読み出して転送するとき
                //通常の転送モードの時
                if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){
                    SSD1306DrawPageStart((uint16_t)&GPBUFF_A.Page[0].GPRAM[0]);
                    buffAStatFlag0 ++;
                    SSD1306_TX_DMA_CLRF();
                    SSD1306_TX_DMA_EN();
                }
                else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){
                    SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[1].GPRAM[0]);
                    buffAStatFlag0 ++;
                }
                else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){
                    SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[2].GPRAM[0]);
                    buffAStatFlag0 ++;
                }
                else {
                    SSD1306DrawPageEnd((uint16_t)&GPBUFF_A.Page[3].GPRAM[0]);
                    buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
                    SSD1306_TX_DMA_DISABLE();
                    if (buffStatFlag & BSF_CLRA_UREADY) buffStatFlag &= ~BSF_BA_UREADY;
                }
            }
            else {//PFMから読み出して転送するとき
                if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){
                    SSD1306DrawPageStart((uint16_t)&GPBUFF_A.Page[0].GPRAM[0]);//ここら辺は後で書き換える
                    buffAStatFlag0 ++;
                    SSD1306_TX_DMA_CLRF();
                    SSD1306_TX_DMA_EN();
                }
                else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){
                    SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[1].GPRAM[0]);
                    buffAStatFlag0 ++;
                }
                else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){
                    SSD1306DrawPageContinue((uint16_t)&GPBUFF_A.Page[2].GPRAM[0]);
                    buffAStatFlag0 ++;
                }
                else {
                    SSD1306DrawPageEnd((uint16_t)&GPBUFF_A.Page[3].GPRAM[0]);
                    buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
                    SSD1306_TX_DMA_DISABLE();
                    if (buffStatFlag & BSF_CLRA_UREADY) buffStatFlag &= ~BSF_BA_UREADY;
                }
            }
        }
        else {//スクロールを使用するとき
            //これ転送開始アドレスごと変更するんじゃなくて，現在のアドレスを変更した方が簡単で，効率もいいかもしれない
            //ただし，それは128バイト未満じゃないと駄目だと思う
            if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 0){//ページ0
                if (buffAStatFlag0 & BASF0_DMA_SCROLL_STAT){//境界をまたぐ場合
//                        LATA ^= 0x01;
                    SSD1306DrawPageContinueDmaOnly(((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0]) + buffAScrollStartP0, buffAScrollRolloverP0);
                    buffAStatFlag0 &= ~(BASF0_DMA_SCROLL_STAT);
                    buffAStatFlag0 ++;
                }
                else {
                    SSD1306_TX_DMA_CLRF();
//                    if (buffAScrollSizeP0 > 128){//転送サイズがページよりも大きい場合
                    if ((uint16_t)(buffAScrollAdderP0 + 128 - 1) < (uint16_t)(buffAScrollSizeP0)){//1回で転送できる場合 <=よりこっちの方が高速
//                                LATA ^= 0x04;
                        SSD1306DrawPageStart((uint16_t)(((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0]) + buffAScrollAdderP0 + buffAScrollStartP0));
                        buffAStatFlag0 ++;
                    }
                    else {//1回では転送できない場合
//                                LATA ^= 0x02;
                        buffAScrollRolloverP0 = (uint8_t)((uint16_t)(buffAScrollAdderP0 + 128) - buffAScrollSizeP0);
                        /* メモ
                         * 仮に，サイズが200で，オフセットを設けなかった場合
                         * 
                         * 72までは1度で転送できる
                         * 73から，1オーバーするので，1度で計算するのは127になって，残りが1ある
                         */
                        SSD1306DrawPageStartDMASize(((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0] + buffAScrollAdderP0 + buffAScrollStartP0), (uint8_t)(128 - buffAScrollRolloverP0));
                        buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
                    }
//                    }
//                    else {//転送サイズがページよりも小さい場合
//                        if (buffAScrollAdderP0 == 0){//1回で転送できる場合
//                            SSD1306DrawPageStartTXSize((uint16_t)(((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0]) + buffAScrollStartP0), (uint8_t)buffAScrollSizeP0);
//                            buffAStatFlag0 ++;
//                        }
//                        else {//1回では転送できない場合
//                            buffAScrollRolloverP0 = (uint8_t)buffAScrollAdderP0;//ここ直さないとバグるかもしれないけど，今現在アドレスを逐一指定できないので，それを実装した時に直す
//                            SSD1306DrawPageStartDmaTXSize(((uint16_t)&GPBUFF_A.PAGE0.GPRAM[0] + buffAScrollAdderP0 + buffAScrollStartP0), (uint8_t)(buffAScrollSizeP0 - buffAScrollAdderP0), (uint8_t)buffAScrollSizeP0);
//                            buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
//                        }
//                    }
                    
                    //ここから，次回の為に増減を決定する
                    if ((buffADmaScrollFlag0 & BADSF0_PAGE0_SC_DIR) == 0){//左方向に文字が移動する場合
                        buffAScrollAdderP0 += buffAScrollUpP0;
                        if (buffAScrollAdderP0 > (buffAScrollSizeP0 - 1)){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP0 = 0;
                            }
                            else {
                                buffAScrollAdderP0 -= buffAScrollSizeP0;
                            }
                        }
                    }
                    else {
                        buffAScrollAdderP0 -= buffAScrollUpP0;
                        if (STATUSbits.C == 0 || buffAScrollAdderP0 < buffAScrollStartP0){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP0 = buffAScrollSizeP0 - 1;
                            }
                            else {
                                buffAScrollAdderP0 += buffAScrollSizeP0;
                            }
                        }
                    }
                    SSD1306_TX_DMA_EN();
                }
            }
            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 1){//ページ1
//                LATA ^= 0x04;
                if (buffAStatFlag0 & BASF0_DMA_SCROLL_STAT){//境界をまたぐ場合
//                        LATA ^= 0x01;
                    SSD1306DrawPageContinueDmaOnly(((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0]) + buffAScrollStartP1, buffAScrollRolloverP1);
                    buffAStatFlag0 &= ~(BASF0_DMA_SCROLL_STAT);
                    buffAStatFlag0 ++;
                }
                else {
//                        LATA ^= 0x02;
//                    if (buffAScrollSizeP1 > 128){//転送サイズがページよりも大きい場合
                    if ((uint16_t)(buffAScrollAdderP1 + 128 - 1) < (uint16_t)(buffAScrollSizeP1)){//1回で転送できる場合
//                                LATA ^= 0x01;
                        SSD1306DrawPageContinue((uint16_t)(((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0]) + buffAScrollAdderP1 + buffAScrollStartP1));
                        buffAStatFlag0 ++;
                    }
                    else {//1回では転送できない場合
//                                LATA ^= 0x02;
                        buffAScrollRolloverP1 = (uint8_t)((uint16_t)(buffAScrollAdderP1 + 128) - buffAScrollSizeP1);
                        SSD1306DrawPageContinueDmaSize(((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0] + buffAScrollAdderP1 + buffAScrollStartP1), (128 - buffAScrollRolloverP1));
                        buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
                    }
//                }
//                else {//転送サイズがページよりも小さい場合
//                    if (buffAScrollAdderP1 == 0){//1回で転送できる場合
//                        SSD1306DrawPageContinueTXSize((uint16_t)(((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0]) + buffAScrollStartP1), (uint8_t)buffAScrollSizeP1);
//                        buffAStatFlag0 ++;
//                    }
//                    else {//1回では転送できない場合
////                                LATB ^= 0x08;
//                        buffAScrollRolloverP1 = (uint8_t)buffAScrollAdderP1;
//                        SSD1306DrawPageContinueDmaTXSize(((uint16_t)&GPBUFF_A.PAGE1.GPRAM[0] + buffAScrollAdderP1 + buffAScrollStartP1), (uint8_t)(buffAScrollSizeP1 - buffAScrollAdderP1), (uint8_t)buffAScrollSizeP1);
//                        buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
//                    }
//                }
//                        buffAScrollAdderP1 += buffAScrollUpP1;
//                        if (buffAScrollAdderP1 > (buffAScrollSizeP1 - 1)){
//                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
//                                buffAScrollAdderP1 = 0;
//                            }
//                            else {
//                                buffAScrollAdderP1 -= buffAScrollSizeP1;
//                            }
//                        }

                    if ((buffADmaScrollFlag0 & BADSF0_PAGE1_SC_DIR) == 0){//左方向に文字が移動する場合
                        buffAScrollAdderP1 += buffAScrollUpP1;
                        if (buffAScrollAdderP1 > (buffAScrollSizeP1 - 1)){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP1 = 0;
                            }
                            else {
                                buffAScrollAdderP1 -= buffAScrollSizeP1;
                            }
                        }
                    }
                    else {
                        buffAScrollAdderP1 -= buffAScrollUpP1;
                        if (STATUSbits.C == 0 || buffAScrollAdderP1 < buffAScrollStartP1){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP1 = buffAScrollSizeP1 - 1;
                            }
                            else {
                                buffAScrollAdderP1 += buffAScrollSizeP1;
                            }
                        }
                    }
                }
            }
            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 2){//ページ2
//                LATB ^= 0x08;
                if (buffAStatFlag0 & BASF0_DMA_SCROLL_STAT){//境界をまたぐ場合
                    SSD1306DrawPageContinueDmaOnly(((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0]) + buffAScrollStartP2, buffAScrollRolloverP2);
                    buffAStatFlag0 &= ~(BASF0_DMA_SCROLL_STAT);
                    buffAStatFlag0 ++;
                }
                else {
//                    if (buffAScrollSizeP2 > 128){//転送サイズがページよりも大きい場合
                    if ((uint16_t)(buffAScrollAdderP2 + 128 - 1) < (uint16_t)(buffAScrollSizeP2)){//1回で転送できる場合
                        SSD1306DrawPageContinue((uint16_t)(((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0]) + buffAScrollAdderP2 + buffAScrollStartP2));
                        buffAStatFlag0 ++;
                    }
                    else {//1回では転送できない場合
                        buffAScrollRolloverP2 = (uint8_t)((uint16_t)(buffAScrollAdderP2 + 128) - buffAScrollSizeP2);
                        SSD1306DrawPageContinueDmaSize(((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0] + buffAScrollAdderP2 + buffAScrollStartP2), (128 - buffAScrollRolloverP2));
                        buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
                    }
//                    }
//                    else {//転送サイズがページよりも小さい場合
//                        if (buffAScrollAdderP2 == 0){//1回で転送できる場合
////                                LATB ^= 0x08;
//                            SSD1306DrawPageContinueTXSize((uint16_t)(((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0]) + buffAScrollStartP2), (uint8_t)buffAScrollSizeP2);
//                            buffAStatFlag0 ++;
//                        }
//                        else {//1回では転送できない場合
//                            buffAScrollRolloverP2 = (uint8_t)buffAScrollAdderP2;
//                            SSD1306DrawPageContinueDmaTXSize(((uint16_t)&GPBUFF_A.PAGE2.GPRAM[0] + buffAScrollAdderP2 + buffAScrollStartP2), (uint8_t)(buffAScrollSizeP2 - buffAScrollAdderP2), (uint8_t)buffAScrollSizeP2);
//                            buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
//                        }
//                    }
//                        buffAScrollAdderP2 += buffAScrollUpP2;
//                        if (buffAScrollAdderP2 > (buffAScrollSizeP2 - 1)){
//                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
//                                buffAScrollAdderP2 = 0;
//                            }
//                            else {
//                                buffAScrollAdderP2 -= buffAScrollSizeP2;
//                            }
//                        }

                    if ((buffADmaScrollFlag0 & BADSF0_PAGE2_SC_DIR) == 0){//左方向に文字が移動する場合
                        buffAScrollAdderP2 += buffAScrollUpP2;
                        if (buffAScrollAdderP2 > (buffAScrollSizeP2 - 1)){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP2 = 0;
                            }
                            else {
                                buffAScrollAdderP2 -= buffAScrollSizeP2;
                            }
                        }
                    }
                    else {
                        buffAScrollAdderP2 -= buffAScrollUpP2;
                        if (STATUSbits.C == 0 || buffAScrollAdderP2 < buffAScrollStartP2){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP2 = buffAScrollSizeP2 - 1;
                            }
                            else {
                                buffAScrollAdderP2 += buffAScrollSizeP2;
                            }
                        }
                    }
                }
            }
            else if ((buffAStatFlag0 & BASF0_DRAW_COUNTER_MASK) == 3){//ページ3
                if (buffAStatFlag0 & BASF0_DMA_SCROLL_STAT){//境界をまたぐ場合
                    SSD1306DrawPageContinueDmaOnly(((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0]) + buffAScrollStartP3, buffAScrollRolloverP3);
                    buffAStatFlag0 &= ~(BASF0_DMA_SCROLL_STAT);
                    buffAStatFlag0 &= ~(BASF0_DRAW_COUNTER_MASK);
                    SSD1306_TX_DMA_DISABLE();
                }
                else {
//                    if (buffAScrollSizeP3 > 128){//転送サイズがページよりも大きい場合
                    if ((uint16_t)(buffAScrollAdderP3 + 128 - 1) < (uint16_t)(buffAScrollSizeP3)){//1回で転送できる場合
                        SSD1306DrawPageEnd((uint16_t)(((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0]) + buffAScrollAdderP3 + buffAScrollStartP3));
                        buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
                        SSD1306_TX_DMA_DISABLE();
                    }
                    else {//1回では転送できない場合
                        buffAScrollRolloverP3 = (uint8_t)((uint16_t)(buffAScrollAdderP3 + 128) - buffAScrollSizeP3);
                        SSD1306DrawPageEndDmaSize(((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0] + buffAScrollAdderP3 + buffAScrollStartP3), (128 - buffAScrollRolloverP3));
                        buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
                    }
//                    }
//                    else {//転送サイズがページよりも小さい場合
//                        if (buffAScrollAdderP3 == 0){//1回で転送できる場合
//                            SSD1306DrawPageEndTxSize((uint16_t)(((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0]) + buffAScrollStartP3), (uint8_t)buffAScrollSizeP3);
//                            buffAStatFlag0 &= ~BASF0_DRAW_COUNTER_MASK;
//                            SSD1306_TX_DMA_DISABLE();
//                        }
//                        else {//1回では転送できない場合
//                            buffAScrollRolloverP3 = (uint8_t)buffAScrollAdderP3;
//                            SSD1306DrawPageEndDmaTxSize(((uint16_t)&GPBUFF_A.PAGE3.GPRAM[0] + buffAScrollAdderP3 + buffAScrollStartP3), (uint8_t)(buffAScrollSizeP3 - buffAScrollAdderP3), (uint8_t)buffAScrollSizeP3);
//                            buffAStatFlag0 |= BASF0_DMA_SCROLL_STAT;
//                        }
//                    }
//                        buffAScrollAdderP3 += buffAScrollUpP3;
//                        if (buffAScrollAdderP3 > (buffAScrollSizeP3 - 1)){
//                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
//                                buffAScrollAdderP3 = 0;
//                            }
//                            else {
//                                buffAScrollAdderP3 -= buffAScrollSizeP3;
//                            }
//                        }

                    if ((buffADmaScrollFlag0 & BADSF0_PAGE3_SC_DIR) == 0){//左方向に文字が移動する場合
                        buffAScrollAdderP3 += buffAScrollUpP3;
                        if (buffAScrollAdderP3 > (buffAScrollSizeP3 - 1)){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP3 = 0;
                            }
                            else {
                                buffAScrollAdderP3 -= buffAScrollSizeP3;
                            }
                        }
                    }
                    else {
                        buffAScrollAdderP3 -= buffAScrollUpP3;
                        if (STATUSbits.C == 0 || buffAScrollAdderP3 < buffAScrollStartP3){
                            if (buffAStatFlag0 & BASF0_DMA_SCROLL_CLEAR){
                                buffAScrollAdderP3 = buffAScrollSizeP3 - 1;
                            }
                            else {
                                buffAScrollAdderP3 += buffAScrollSizeP3;
                            }
                        }
                    }
                }
            }
        }
    }
}