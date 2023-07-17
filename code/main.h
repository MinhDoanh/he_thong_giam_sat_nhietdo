#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#include <lcd.h>
#include<DHT11.H>

//khai bao ket noi cac nut nhan
#define MENU      input(PIN_B7)
#define TANG      input(PIN_A0)
#define GIAM      input(PIN_A1)

//khai bao ket dieu khien cac tai
#define TAI_1     PIN_E0
#define TAI_2     PIN_E1

//!#define Line_1    lcd_line_1()
//!#define Line_2    lcd_line_2()




