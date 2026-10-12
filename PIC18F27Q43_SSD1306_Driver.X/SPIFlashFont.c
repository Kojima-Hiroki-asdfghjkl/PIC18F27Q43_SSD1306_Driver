#include <xc.h>

#include "SPIFlashFont.h"
#include "SSD1306_Parameter.h"
#include "SSD1306.h"

volatile SpiFlashCommandBuff_t spiFlashComandBuff[2] = {};

//uint24_t flashAdderBuff[128] = {
//    0x000208,  // 'A' (0x0041 << 3)
//    0x000210,  // 'B' (0x0042 << 3)
//    0x000218,  // 'C' (0x0043 << 3)
//    0x000188,  // '1' (0x0031 << 3)
//    0x000190,  // '2' (0x0032 << 3)
//    0x000198,  // '3' (0x0033 << 3)
//    0x018210,  // 'あ' (0x3042 << 3)
//    0x018216,  // 'い' (0x3043 << 3)
//    0x018230   // 'う' (0x3044 << 3)
//};//384

//uint24_t flashAdderBuff[128] = {
//    0x02E078, // '小' (0x5C0F << 3)
//    0x02EC58, // '嶋' (0x5D8B << 3)
//    0x018000, // '　' (0x3000 << 3)
//    0x02F8C0, // '弘' (0x5F18 << 3)
//    0x0351C8, // '樹' (0x6A39 << 3)
//};//384

uint24_t flashAdderBuff[128] = {
    0x0310B0, // '或' (0x6216 << 3)
    0x033570, // '暮' (0x66AE << 3)
    0x03CE58, // '秋' (0x79CB << 3)
    0x018370, // 'の' (0x306E << 3)
    0x032F28, // '日' (0x65E5 << 3)
    0x018370, // 'の' (0x306E << 3)
    0x027458, // '事' (0x4E8B << 3)
    0x018338, // 'で' (0x3067 << 3)
    0x018210, // 'あ' (0x3042 << 3)
    0x018458, // 'る' (0x308B << 3)
    0x018010, // '。' (0x3002 << 3)
    0x027000, // '一' (0x4E00 << 3)
    0x0275D0, // '人' (0x4EBA << 3)
    0x018370, // 'の' (0x306E << 3)
    0x027058, // '下' (0x4E0B << 3)
    0x0275D0, // '人' (0x4EBA << 3)//ここまで16文字
    0x018260, // 'が' (0x304C << 3)
    0x018008, // '、' (0x3001 << 3)
    0x03FC28, // '羅' (0x7F85 << 3)
    0x03A8F8, // '生' (0x751F << 3)
    0x04AC00, // '門' (0x9580 << 3)
    0x018370, // 'の' (0x306E << 3)
    0x027058, // '下' (0x4E0B << 3)
    0x018338, // 'で' (0x3067 << 3)
    0x04B740, // '雨' (0x96E8 << 3)
    0x018420, // 'や' (0x3084 << 3)
    0x0183F8, // 'み' (0x307F << 3)
    0x018490, // 'を' (0x3092 << 3)
    0x02FC28, // '待' (0x5F85 << 3)
    0x018318, // 'っ' (0x3063 << 3)
    0x018330, // 'て' (0x3066 << 3)
    0x018220, // 'い' (0x3044 << 3)//32 <-ここまで
    0x0182F8, // 'た' (0x305F << 3)
    0x018010, // '。' (0x3002 << 3)
    0x02F418, // '広' (0x5E83 << 3)
    0x018220, // 'い' (0x3044 << 3)
    0x04AC00, // '門' (0x9580 << 3)
    0x018370, // 'の' (0x306E << 3)
    0x027058, // '下' (0x4E0B << 3)
    0x018358, // 'に' (0x306B << 3)
    0x018378, // 'は' (0x306F << 3)
    0x018008, // '、' (0x3001 << 3)
    0x018298, // 'こ' (0x3053 << 3)
    0x018370, // 'の' (0x306E << 3)
    0x03A9B8, // '男' (0x7537 << 3)
    0x018370, // 'の' (0x306E << 3)
    0x0183D8, // 'ほ' (0x307B << 3)
    0x018258, // 'か' (0x304B << 3)
    0x018358, // 'に' (0x306B << 3)
    0x045580, // '誰' (0x8AB0 << 3)
    0x018410, // 'も' (0x3082 << 3)
    0x018220, // 'い' (0x3044 << 3)
    0x018350, // 'な' (0x306A << 3)
    0x018220, // 'い' (0x3044 << 3)
    0x018010, // '。' (0x3002 << 3)
};//384

//uint24_t flashAdderBuff[128] = {
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//    0x000000,
//};//384
uint16_t SSD1306AdderBuff[128] = {
    0x0000
};//256
uint8_t spiCommandCounter = 0;
uint8_t spiCommandLen = 55;
uint8_t spiFlashToBuffFlag = 0x02;

void __interrupt(irq(IRQ_SPI1)) SPI1_TX_CMOP_INT(){
//    LATA ^= 0x02;
    SPI1_TX_COMP_INT_CLRF();
    spiFlashToBuffStateMachine();
//    LATB ^= 0x04;
}

void spiFlashToBuffStateMachine(){
    LATB ^= 0x08;
//    LATB ^= 0x04;
    uint16_t FSR0_Save = FSR0;
    uint16_t FSR1_Save = FSR1;
    uint16_t FSR2_Save = FSR2;
    
    uint8_t dmaSave = DMASELECT;
    
    union {//ライフタイムが異なるので，まとめる
        uint8_t flashAreaType;
        uint8_t rollover;
    } u_work1;
    
    uint8_t indf2Temp;
    
    if (spiCommandCounter != spiCommandLen){
        LATB ^= 0x04;
        //ここから，フラッシュからの読み出し部
        FSR0 = (uint16_t)(((uint16_t)&flashAdderBuff[0]) + 2 + (spiCommandCounter * sizeof(flashAdderBuff[0])));
        //各バッファのMSByteをFSRに代入する
        //FSR0にフラッシュから読み出すアドレスバッファのアドレスを入れる
        if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){
            //コマンドのコピー
            spiFlashComandBuff[0].command = FLASH_COMM_READ;
            //アドレスのコピー
            spiFlashComandBuff[0].addressU8[0] = POSTDEC0;
            spiFlashComandBuff[0].addressU8[1] = POSTDEC0;
            spiFlashComandBuff[0].addressU8[2] = POSTDEC0;
            //この順番で読み出すことで，バッファにアドレスを転送しつつ，その後のバッファに詰めるときのFSRのアドレス操作が不要になる

            u_work1.flashAreaType = GetFlashAreaType(spiFlashComandBuff[0].addressU8[0]);
            SPI1TCNT = (GetFlashReadSize(u_work1.flashAreaType) + 1 + 3);//1 + 3 + DataSize

            DMASELECT = DMA_SPI_RX;
            DMAnCON0bits.EN = 0;
            DMAnDSA = (uint16_t)&spiFlashComandBuff[0];
            DMAnDSZ = SPI1TCNT;
            DMAnCON0bits.SIRQEN = 1;
            DMAnCON0bits.EN = 1;

            DMASELECT = DMA_SPI_TX;
            DMAnCON0bits.EN = 0;
            DMAnSSA = (uint16_t)&spiFlashComandBuff[0];
            DMAnSSZ = SPI1TCNT;
            DMAnCON0bits.SIRQEN = 1;
            DMAnCON0bits.EN = 1;//ここで転送開始される
        }
        else {
            //コマンドのコピー
            spiFlashComandBuff[1].command = FLASH_COMM_READ;
            //アドレスのコピー
            spiFlashComandBuff[1].addressU8[0] = POSTDEC0;
            spiFlashComandBuff[1].addressU8[1] = POSTDEC0;
            spiFlashComandBuff[1].addressU8[2] = POSTDEC0;
            //この順番で読み出すことで，バッファにアドレスを転送しつつ，その後のバッファに詰めるときのFSRのアドレス操作が不要になる

            u_work1.flashAreaType = GetFlashAreaType(spiFlashComandBuff[1].addressU8[0]);
            SPI1TCNT = (GetFlashReadSize(u_work1.flashAreaType) + 1 + 3);//1 + 3 + DataSize

            DMASELECT = DMA_SPI_RX;
            DMAnCON0bits.EN = 0;
            DMAnDSA = (uint16_t)&spiFlashComandBuff[1];
            DMAnDSZ = SPI1TCNT;
            DMAnCON0bits.SIRQEN = 1;
            DMAnCON0bits.EN = 1;

            DMASELECT = DMA_SPI_TX;
            DMAnCON0bits.EN = 0;
            DMAnSSA = (uint16_t)&spiFlashComandBuff[1];
            DMAnSSZ = SPI1TCNT;
            DMAnCON0bits.SIRQEN = 1;
            DMAnCON0bits.EN = 1;//ここで転送開始される
        }
    }
    else {
        FSR0 = (uint16_t)(((uint16_t)&flashAdderBuff[0]) - 1 + (spiCommandCounter * sizeof(flashAdderBuff[0])));
    }
    spiFlashToBuffFlag ^= SFBF_FLASH_BUFF_SEL;
    //ここからデータをバッファに詰める部分
    if (spiCommandCounter == 0){//一番初めなので，ここの部分ではデータが来てないから，すぐに終了させる．
        //ここで割り込みとかを有効化する
        SPI1_TX_COMP_INT_EN();
    }
    else {//データがそろっている場合
//        LATB ^= 0x20;
        //ここで，フラッシュからの読み出しモード変数を破壊し，書き込みに使用するタイプを格納し直す
        u_work1.flashAreaType = GetFlashAreaType(INDF0);//ここまでしかFSR0の値は使用しない
        //アドレスを詰めるときに，POSTDEC0にしたので，自動的に1つ前のバッファのMSByteが選択されている．
        
        //どのみちここから，FSRをアドレス格納に使うので，あらかじめ入れておいて，ここから使い回してメモリをケチる
        FSR2 = (uint16_t)((uint16_t)&SSD1306AdderBuff[0] + ((spiCommandCounter - 1) * sizeof(SSD1306AdderBuff[0])));
        //もしかしたら，ここのspiCommandCounterを-1した値使わないとおかしくなるかもしれない
        FSR1L = POSTINC2;
        indf2Temp = INDF2;//ここには，転送タイプとかがもりもり詰まっているので，保持しておく
        FSR1H = POSTDEC2 & SAB_WRITE_COLUMN_ADDH;//カウンタの上位ビットを転送する
        //ここまでで，アドレスにはバッファに転送を開始する番号が入っている．
        if (u_work1.flashAreaType == FONT8x8Type){
            if ((spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQ_GPBUFF) == 0){
                //GPBUFF領域に限定しない
                //境界をまたがないかどうかを判定する
                if (FSR1 <= (sizeof(GPBUFF_Page_t) - FONT8x8Size)){
                    //変数 <= 定数の形なら，どうやっても大体速度同じにしてくれる
                    //境界をまたがない場合
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE3;
                        }
                    }
                    else {//バッファB
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE3;
                        }
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    POSTINC1 = POSTINC0;//1
                    POSTINC1 = POSTINC0;//2
                    POSTINC1 = POSTINC0;//3
                    POSTINC1 = POSTINC0;//4
                    POSTINC1 = POSTINC0;//5
                    POSTINC1 = POSTINC0;//6
                    POSTINC1 = POSTINC0;//7
                    POSTINC1 = POSTINC0;//8
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        __asm__ volatile ("MOVLW 8");
                        __asm__ volatile ("ADDWF POSTINC1, F");
                        __asm__ volatile ("MOVLW 0");
                        __asm__ volatile ("ADDWFC INDF1, F");
                    }
                }
                else if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQ_PAGE){
                    //ページ内でループさせる
                    //一気に書き込めないので，余りを計算する
                    u_work1.rollover = (uint8_t)(FSR1 + FONT8x8Size - sizeof(GPBUFF_Page_t));
                    //変数 <= 定数の形なら，どうやっても大体速度同じにしてくれる
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE3;
                        }
                    }
                    else {//バッファB
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE3;
                        }
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    //ここに来るってことは，一回で書き込みきれないってこと
                    //って事は，一回目の転送は0回から7回まで
                    //2回目は1-8までになる
                    WREG = u_work1.rollover;

                    __asm__ volatile ("SUBLW 8");//１文字8バイトなので
                    __asm__ volatile ("BZ $ + 54");//0
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//6:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4

                    FSR1 -= sizeof(GPBUFF_Page_t);

                    WREG = u_work1.rollover;

                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 54");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//6:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//7:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//8:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4
//                    __asm__ volatile ("NOP");//やっぱりここにNOPを入れないとおかしくなるからとりあえず入れておく
                    //1サイクルで治るならまぁ仕方ない
                    //ここをCでかくと，最適化のときに変なところに飛ばされるからインラインアセンブリにする
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        
                        //8-384
                        //-376 (0x0178) の減算 <- バッファサイズをいじったときは変更する事
                        __asm__ volatile ("MOVLW 0x78");       // 下位バイト用の定数 (120)
                        __asm__ volatile ("SUBWF POSTINC1, F");  // 下位バイトを引く（FSR1が上位バイトへ進む）
                        __asm__ volatile ("MOVLW 0x01");       // 上位バイト用の定数 (1)
                        __asm__ volatile ("SUBWFB INDF1, F");    // 上位バイトから定数とボロー（桁下がり）を引く
                    }
                }
                else if ((indf2Temp & SAB_WRITE_PAGE_SELH) == SAB_WRITE_PAGE_SELH_3){
                    //ページに限定しないで，境界をまたぐ場合
                    //ページ内でループさせる
                    //一気に書き込めないので，余りを計算する
                    u_work1.rollover = (uint8_t)(FSR1 + FONT8x8Size - sizeof(GPBUFF_Page_t));
                    //変数 <= 定数の形なら，どうやっても大体速度同じにしてくれる
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        FSR1 += (uint16_t)&GPBUFF_A.PAGE3;
                    }
                    else {//バッファB
                        FSR1 += (uint16_t)&GPBUFF_B.PAGE3;
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    //ここに来るってことは，一回で書き込みきれないってこと
                    //って事は，一回目の転送は0回から7回まで
                    //2回目は1-8までになる
                    WREG = u_work1.rollover;

                    __asm__ volatile ("SUBLW 8");
                    __asm__ volatile ("BZ $ + 54");//0
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//6:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4

                    FSR1 -= sizeof(GPBUFF_t);

                    WREG = u_work1.rollover;

                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 54");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//6:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//7:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//8:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4
//                    __asm__ volatile ("NOP");//やっぱりここにNOPを入れないとおかしくなるからとりあえず入れておく
                    //1サイクルで治るならまぁ仕方ない
                    //ここをCでかくと，最適化のときに変なところに飛ばされるからインラインアセンブリにする
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        
                        //8-384
                        //-376 (0x0178) の減算 <- バッファサイズをいじったときは変更する事
                        __asm__ volatile ("MOVLW 0x78");       // 下位バイト用の定数 (120)
                        __asm__ volatile ("SUBWF POSTINC1, F");  // 下位バイトを引く（FSR1が上位バイトへ進む）
                        __asm__ volatile ("MOVLW 0x01");       // 上位バイト用の定数 (1)
                        __asm__ volatile ("SUBWFB INDF1, F");    // 上位バイトから定数とボロー（桁下がり）を引く
                        INDF1 &= ~(SAB_WRITE_PAGE_SELH);
                    }
                }
                else {
                    //境界をまたがない場合
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE1;
                        }
                        else {//ページ2
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE2;
                        }
                    }
                    else {//バッファB
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE1;
                        }
                        else {//ページ2
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE2;
                        }
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    POSTINC1 = POSTINC0;//1
                    POSTINC1 = POSTINC0;//2
                    POSTINC1 = POSTINC0;//3
                    POSTINC1 = POSTINC0;//4
                    POSTINC1 = POSTINC0;//5
                    POSTINC1 = POSTINC0;//6
                    POSTINC1 = POSTINC0;//7
                    POSTINC1 = POSTINC0;//8
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        
                        //8-384
                        //-376 (0x0178) の減算 <- バッファサイズをいじったときは変更する事
                        __asm__ volatile ("MOVLW 0x78");       // 下位バイト用の定数 (120)
                        __asm__ volatile ("SUBWF POSTINC1, F");  // 下位バイトを引く（FSR1が上位バイトへ進む）
                        __asm__ volatile ("MOVLW 0x01");       // 上位バイト用の定数 (1)
                        __asm__ volatile ("SUBWFB INDF1, F");    // 上位バイトから定数とボロー（桁下がり）を引く
                        INDF1 += SAB_WRITE_PAGE_SELH_1;
                    }
                }
            }
            else {
//                LATB ^= 0x04;
                //GPBUFF領域に限定する-------------------------------------------
                //境界をまたがないかどうかを判定する
                if (FSR1 <= (sizeof(((GPBUFF_Page_t *)0)->GPRAM) - FONT8x8Size)){
//                        LATB ^= 0x10;
                    //変数 <= 定数の形なら，どうやっても大体速度同じにしてくれる
                    //境界をまたがない場合
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE3;
                        }
                    }
                    else {//バッファB
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE3;
                        }
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    POSTINC1 = POSTINC0;//1
                    POSTINC1 = POSTINC0;//2
                    POSTINC1 = POSTINC0;//3
                    POSTINC1 = POSTINC0;//4
                    POSTINC1 = POSTINC0;//5
                    POSTINC1 = POSTINC0;//6
                    POSTINC1 = POSTINC0;//7
                    POSTINC1 = POSTINC0;//8
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        __asm__ volatile ("MOVLW 8");
                        __asm__ volatile ("ADDWF POSTINC1, F");
                        __asm__ volatile ("MOVLW 0");
                        __asm__ volatile ("ADDWFC INDF1, F");
//                        LATB ^= 0x10;
                    }
                }
                else if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQ_PAGE){
//                    LATB ^= 0x04;
                    //ページ内でループさせる
                    //一気に書き込めないので，余りを計算する
                    u_work1.rollover = (uint8_t)(FSR1 + FONT8x8Size - sizeof(((GPBUFF_Page_t *)0)->GPRAM));
                    //変数 <= 定数の形なら，どうやっても大体速度同じにしてくれる
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE3;
                        }
                    }
                    else {//バッファB
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE1;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_2){//ページ2
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE2;
                        }
                        else {//ページ3
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE3;
                        }
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    //ここに来るってことは，一回で書き込みきれないってこと
                    //って事は，一回目の転送は0回から7回まで
                    //2回目は1-8までになる
                    WREG = u_work1.rollover;

                    __asm__ volatile ("SUBLW 8");
                    __asm__ volatile ("BZ $ + 54");//0
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//6:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4

                    FSR1 -= sizeof(((GPBUFF_Page_t *)0)->GPRAM);

                    WREG = u_work1.rollover;

                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 54");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//6:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//7:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//8:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4
                    __asm__ volatile ("NOP");//やっぱりここにNOPを入れないとおかしくなるからとりあえず入れておく
                    //1サイクルで治るならまぁ仕方ない
                    //ここをCでかくと，最適化のときに変なところに飛ばされるからインラインアセンブリにする
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        
                        //8-128
                        // ここから -120の減算
                        __asm__ volatile ("MOVLW 120");       // 下位バイト用の定数 (136)
                        __asm__ volatile ("SUBWF POSTINC1, F");  // 下位バイトを引く（FSR1が上位バイトへ進む）
                        __asm__ volatile ("MOVLW 0x00");       // 上位バイト用の定数 (1)
                        __asm__ volatile ("SUBWFB INDF1, F");    // 上位バイトから定数とボロー（桁下がり）を引く
                    }
                }
                else if ((indf2Temp & SAB_WRITE_PAGE_SELH) == SAB_WRITE_PAGE_SELH_3){
                    //ページに限定しないで，境界をまたぐ場合
                    //一気に書き込めないので，余りを計算する
                    u_work1.rollover = (uint8_t)(FSR1 + FONT8x8Size - sizeof(((GPBUFF_Page_t *)0)->GPRAM));
                    //変数 <= 定数の形なら，どうやっても大体速度同じにしてくれる
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        FSR1 += (uint16_t)&GPBUFF_A.PAGE3;
                    }
                    else {//バッファB
                        FSR1 += (uint16_t)&GPBUFF_B.PAGE3;
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    //ここに来るってことは，一回で書き込みきれないってこと
                    //って事は，一回目の転送は0回から7回まで
                    //2回目は1-8までになる
                    WREG = u_work1.rollover;

                    __asm__ volatile ("SUBLW 8");
                    __asm__ volatile ("BZ $ + 54");//0
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//6:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4

                    FSR1 -= (sizeof(GPBUFF_t) - sizeof(((GPBUFF_Page_t *)0)->ExRAM));

                    WREG = u_work1.rollover;

                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 54");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//6:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//7:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//8:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4
//                    __asm__ volatile ("NOP");//やっぱりここにNOPを入れないとおかしくなるからとりあえず入れておく
                    //1サイクルで治るならまぁ仕方ない
                    //ここをCでかくと，最適化のときに変なところに飛ばされるからインラインアセンブリにする
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        
                        //8-128
                        // ここから -120の減算
                        __asm__ volatile ("MOVLW 120");       // 下位バイト用の定数 (136)
                        __asm__ volatile ("SUBWF POSTINC1, F");  // 下位バイトを引く（FSR1が上位バイトへ進む）
                        __asm__ volatile ("MOVLW 0x00");       // 上位バイト用の定数 (1)
                        __asm__ volatile ("SUBWFB INDF1, F");    // 上位バイトから定数とボロー（桁下がり）を引く
                        INDF1 &= ~(SAB_WRITE_PAGE_SELH);
                    }
                }
                else {
//                    LATB ^= 0x08;
                    //ページに限定しないで，境界をまたぐ場合
                    //一気に書き込めないので，余りを計算する
                    u_work1.rollover = (uint8_t)(FSR1 + FONT8x8Size - sizeof(((GPBUFF_Page_t *)0)->GPRAM));
                    //書き込むバッファを得る
                    if ((indf2Temp & SAB_WRITE_BUFF_SELH) == 0){//バッファA
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE0;
//                            LATB ^= 0x08;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE1;
                        }
                        else {//ページ2
                            FSR1 += (uint16_t)&GPBUFF_A.PAGE2;
                        }
                    }
                    else {//バッファB
                        indf2Temp &= SAB_WRITE_PAGE_SELH;
                        if (indf2Temp == SAB_WRITE_PAGE_SELH_0){//ページ0
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE0;
                        }
                        else if (indf2Temp == SAB_WRITE_PAGE_SELH_1){//ページ1
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE1;
                        }
                        else {//ページ2
                            FSR1 += (uint16_t)&GPBUFF_B.PAGE2;
                        }
                    }

                    //読み込むバッファを得る
                    if ((spiFlashToBuffFlag & SFBF_FLASH_BUFF_SEL) == 0){//spiFlashComandBuff[0]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[0].data[0];
                    }
                    else {//spiFlashComandBuff[1]の方
                        //1つ前のバッファから読み出す．上の方で反転しているので，そのまま使う
                        FSR0 = (uint16_t)&spiFlashComandBuff[1].data[0];
                    }

                    //転送する
                    //ここに来るってことは，一回で書き込みきれないってこと
                    //って事は，一回目の転送は0回から7回まで
                    //2回目は1-8までになる
                    WREG = u_work1.rollover;
                    
                    __asm__ volatile ("SUBLW 8");
                    __asm__ volatile ("BZ $ + 54");//0
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//6:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4

                    FSR1 += sizeof(((GPBUFF_Page_t *)0)->ExRAM);

                    WREG = u_work1.rollover;

                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 54");//1:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 46");//2:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 38");//3:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 30");//4:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 22");//5:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 14");//6:2
                    __asm__ volatile ("DECF WREG, W");//:2
                    __asm__ volatile ("BZ $ + 6");//7:2
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//8:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//7:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//6:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//5:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//4:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//3:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//2:4
                    __asm__ volatile ("MOVFF POSTINC0, POSTINC1");//1:4
//                    __asm__ volatile ("NOP");//やっぱりここにNOPを入れないとおかしくなるからとりあえず入れておく
                    //1サイクルで治るならまぁ仕方ない
                    //ここをCでかくと，最適化のときに変なところに飛ばされるからインラインアセンブリにする
                    
                    if (spiCommandCounter == spiCommandLen){
                        spiCommandCounter = 0;
                        SPI1_TX_COMP_INT_DISABLE();
                        goto EXIT_spiFlashToBuffStateMachine;
//                        LATB ^= 0x10;
                    }
                    
                    if (spiFlashToBuffFlag & SFBF_SSD1306BUFF_SEQUENTIAL){//連続で書き込む場合
                        FSR1 = FSR2;
                        __asm__ volatile ("ADDFSR 1, 2");
                        __asm__ volatile ("MOVFF POSTINC2, POSTINC1");
                        __asm__ volatile ("MOVFF INDF2, POSTDEC1");
                        
                        //8-128
                        // ここから -120の減算
                        __asm__ volatile ("MOVLW 120");       // 下位バイト用の定数 (136)
                        __asm__ volatile ("SUBWF POSTINC1, F");  // 下位バイトを引く（FSR1が上位バイトへ進む）
                        __asm__ volatile ("MOVLW 0x00");       // 上位バイト用の定数 (1)
                        __asm__ volatile ("SUBWFB INDF1, F");    // 上位バイトから定数とボロー（桁下がり）を引く
                        INDF1 += SAB_WRITE_PAGE_SELH_1;
//                        LATB ^= 0x08;
                    }
                }
            }
        }
    }
    spiCommandCounter ++;
    
EXIT_spiFlashToBuffStateMachine:
    
    FSR0 = FSR0_Save;
    FSR1 = FSR1_Save;
    FSR2 = FSR2_Save;
    DMASELECT = dmaSave;
    LATB ^= 0x08;
}