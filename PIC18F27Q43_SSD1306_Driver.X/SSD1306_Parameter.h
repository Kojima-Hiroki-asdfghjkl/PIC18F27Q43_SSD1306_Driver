/* 
 * File:   SSD1306_Parameter.h
 * Author: kojim
 *
 * Created on 2026/09/20, 17:29
 */
#pragma once

#include <stdint.h>

//DMA --------------------------------------------------------------------------
#define DMA_I2C_TX 0//1
#define DMA_GPRAM  1//2

//I2C --------------------------------------------------------------------------
#define SSD1306_I2C_ADDER 0x78

//command
#define SSD1306_CTRL_CMD_SINGLE   0x80  // コマンド単発 (Co=0, D/C#=0)
#define SSD1306_CTRL_CMD_STREAM   0x00  // コマンド連続 (Co=1, D/C#=0)
#define SSD1306_CTRL_DATA_SINGLE  0xC0  // データ単発   (Co=0, D/C#=1)
#define SSD1306_CTRL_DATA_STREAM  0x40  // データ連続   (Co=1, D/C#=1)

const volatile uint8_t SSD1306InitComm[] = {
    25,   // 送信バイト数
    
    0xAE, // ディスプレイをオフにする (Display OFF)
    0xD5, // ディスプレイクロック分周比 / OSC周波数を設定
    0xB0, // 分周比: 1, OSC: 0x8 (デフォルト値)
//    0xC0, // 分周比: 1, OSC: 0x8 (デフォルト値)
    0xA8, // マルチプレックス比を設定 (Multiplex Ratio)
    0x3F, // 128x64用 (64-1 = 0x3F)
    0xD3, // ディスプレイオフセットを設定 (Display Offset)
    0x20, // オフセット
    0x40, // ディスプレイの開始ラインを設定 (Start Line = 0)
    0x8D, // チャージポンプを設定 (Charge Pump Setting)
    0x14, // 内部DC/DCコンバータ有効 (内部チャージポンプ 3.3V生成)
    
    0xA0, // セグメント再マッピングを設定 (Column 127 -> SEG0) ※左右反転時は0xA0
    0xC0, // COM出力スキャン方向を設定 (COM[N-1] -> COM0) ※上下反転時は0xC0
    0xDA, // COMハードウェア構成を設定 (Common Pads Hardware Configuration)
    0x22, // 代替COMピン構成、連続COMピン無効
    0x81, // コントラスト制御を設定 (Contrast Control)
    0x08, // コントラスト値 (0xCF)
    0xD9, // プリチャージ期間を設定 (Pre-charge Period)
    0xF1, // 内部チャージポンプ用設定 (Phase 1: 1DCLK, Phase 2: 15DCLK)
    0xD8, // VCOMH Deselect Levelを設定
    0x40, // VCOMH レベル選択 (約 0.77 x Vcc)
    
    0xA4, // 全体表示機能の解除 (Entire Display ON, RAMのデータに従う)
    0xA6, // 通常表示に設定 (A7で反転表示)
    0xAF, // ディスプレイをオンにする (Display ON)
    0x20, // メモリ・アドレッシング・モード設定
    0x00  // 0x00: 水平アドレッシングモード (Horizontal Addressing Mode)
};

const volatile uint8_t SSD1306SetAddAComm[] = {
    5, 
    0x00, 
    0x10,
    0x22,
    0x00,
    0x03,
};
const volatile uint8_t SSD1306SetAddBComm[] = {
    5, 
    0x00, 
    0x10,
    0x22,
    0x04,
    0x07,
};

const volatile uint8_t SSD1306ClearBuff[128] = {};