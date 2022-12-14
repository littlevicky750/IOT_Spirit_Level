#ifndef OLED_H
#define OLED_H
#include <U8g2lib.h>
#include <Wire.h>
#include "IMU42688.h"
#include "RealTimeClock.h"
#include "AngleCalculate.h"
#include "NetState.h"
#include "Go_Standard.h"

#define H 1
#define V 0

class OLED
{
private:
    int Count = 0;
    void Begin();
    bool isU8G2Begin = false;
    uint8_t I2C_Add = 0x3C;
    void Menu(int x, int y, bool isH);
    void Describe(int x, int y, int w, int h, bool isH);
    void QuickInfo(int x, int y, int w, int h);
    void Main2(int x, int y, int TW, int TH);
    void ICON(int x, int y, int w, int h);
    void Battery(int x, int y, int w, int h, int b);
    void CheckState();
    void Clock();
    void Save(int x, int y);
    void Wifi(int x, int y, int Rotation);
    int WiFiShow();
    bool Flash(int Due, int Period);
    void Mode();
    void Unit();
    int FlashCount;
    byte WiFi_Select_Flag = 0;

    const uint8_t *Default_Font = u8g2_font_helvB10_tr;
    const uint8_t *Describe_Font = u8g2_font_helvB08_tr;
    const uint8_t *MSpace_Font = u8g2_font_7x14B_tr;

public:
    int *Bat;
    RealTimeClock *ClockShow;
    String *ID;
    AngleCalculate *Measure;
    // IMU901 *imu;
    IMU42688 *imu;
    bool *SDState;
    bool *fSave;
    SDCard *pSD;
    NetState *pWifiState;
    byte State = 0;
    byte Page = 0;
    byte MenuCursor = 0;
    Go_Standard *Standard;
    int BlockTime = 0;
    byte ShowUnit = 0;

    void Initialize();
    void Clear();
    void TurnOff();
    void ShowLowPower();
    void Update();
    void Block(String BlockInfo);
};

#endif