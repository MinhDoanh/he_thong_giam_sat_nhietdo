#include <main.h>
//!#include <lcd.c>
//-----------------------------------------------------------------------------

char Option=0;
unsigned int8 NhietDoMax=30,NhietDoMin=25,DoAmMax=65,DoAmMin=60; // cai dat min max cho nhiet do, do am
//-----------------------------------------------------------------------------
//!#define led PIN_C2
#INT_RB
void _NgatRB(void)
{
   if(MENU==0)
   {
      delay_ms(300);
      //while(MENU==0);
      //output_bit(TAI_1,1);
      Option=Option+1;
      if(Option>4)
      {
         Option=0;
      }
   }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void main()
{
   //khai bao bien cuc bo o day
   unsigned int8 dh_nhiet_do,dh_nhiet_do2,dh_do_am,dh_do_am2;
   unsigned int8 str[20];
   
   lcd_init();
   lcd_putc('\f');
   port_b_pullups(1);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);
   output_bit(TAI_1,0);
   output_bit(TAI_2,0);
   
   lcd_gotoxy(5,1);
   printf(lcd_putc,"DO AN 3");
   lcd_gotoxy(2,2);
   printf(lcd_putc,"NGUYENMINHDOANH");
   delay_ms(2000);
   delay_ms(1000);
   lcd_putc('\f');   

   while(TRUE)
   {
//!   output_low(led);
//!   delay_ms(200);
//!   output_high(led);
      //TODO: User Code
      
      lcd_clear();
      while(Option==0)
      {
      // xuat tin hieu ra man hinh LCD
         if(DHT_GetTemHumi(dh_nhiet_do,dh_nhiet_do2,dh_do_am,dh_do_am2))
         {
            sprintf(str,"HU: %u,%u",dh_do_am,dh_do_am2);         
            lcd_gotoxy(1,1);
            printf(lcd_putc,"%s",str);   
            lcd_putc('%');
            printf(lcd_putc," %d-%d",DoAmMin,DoAmMax);
            lcd_putc('%');
            sprintf(str,"TE: %u,%u",dh_nhiet_do,dh_nhiet_do2);
            lcd_gotoxy(1,2);
            printf(lcd_putc,"%s",str);         
            lcd_putc(223);
//!            lcd_putc('C');
            printf(lcd_putc," %d-%d",NhietDoMin,NhietDoMax);
            lcd_putc(223);
//!            lcd_putc('C');
         }
         else {printf(lcd_putc,"K DOC DUOC GTRI");
               lcd_gotoxy(1,1);}
               
         if(dh_nhiet_do>=NhietDoMax && dh_do_am<=DoAmMin || dh_nhiet_do>=NhietDoMax && dh_do_am>=DoAmMax)
         {
            output_bit(TAI_1,1);
            output_bit(TAI_2,1);
         }
         else if(dh_nhiet_do<=NhietDoMin && dh_do_am>=DoAmMax || dh_nhiet_do<=NhietDoMin && dh_do_am<=DoAmMax)
         {
            output_bit(TAI_1,0);
            output_bit(TAI_2,0); 
         }
      }
      
      // Cai dat nhiet do max
      lcd_clear();
      while(Option==1)
      {
         lcd_line_1();
         printf(lcd_putc,"CAI DAT ND MAX");
         lcd_line_2();
         printf(lcd_putc,"GIA TRI:%d",NhietDoMax);
         
         if(TANG==0)
         {
            while(TANG==0);
            NhietDoMax=NhietDoMax+1;
            if(NhietDoMax>40 )
            {
               NhietDoMax=30;
            }
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            NhietDoMax=NhietDoMax-1;
            if(NhietDoMax<20 || NhietDoMax <= NhietDoMin)
            {
               NhietDoMax=26;
            }
         }
      }
      
    // Cai dat nhiet do min
      lcd_clear();
      while(Option==2)
      {
         lcd_line_1();
         printf(lcd_putc,"CAI DAT ND MIN");
         lcd_line_2();
         printf(lcd_putc,"GIA TRI:%d",NhietDoMin);
         
         if(TANG==0)
         {
            while(TANG==0);
            NhietDoMin=NhietDoMin+1;
            if(NhietDoMin>35 || NhietDoMin >= NhietDoMax)
            {
               NhietDoMin=20;
            }
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            NhietDoMin=NhietDoMin-1;
            if(NhietDoMin<15)
            {
               NhietDoMin=20;
            }
         }
      }      
      // Cai dat do am max
      lcd_clear();
      while(Option==3)
      {
         lcd_line_1();
         printf(lcd_putc,"CAI DAT HU MAX");
         lcd_line_2();
         printf(lcd_putc,"GIA TRI:%d",DoAmMax);
         lcd_putc('%');
         
         if(TANG==0)
         {
            while(TANG==0);
            DoAmMax=DoAmMax+1;
            if(DoAmMax>99)
            {
               DoAmMax=70;
            }
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            DoAmMax=DoAmMax-1;
            if(DoAmMax<50 || DoAmMax <= DoAmMin)
            {
               DoAmMax=70;
            }
         }
      }          
      // Cai dat do am min
      lcd_clear();
      while(Option==4)
      {
         lcd_line_1();
         printf(lcd_putc,"CAI DAT HU MIN");
         lcd_line_2();
         printf(lcd_putc,"GIA TRI:%d",DoAmMin);
         lcd_putc('%');
         
         if(TANG==0)
         {
            while(TANG==0);
            DoAmMin=DoAmMin+1;
            if(DoAmMin>85 || DoAmMin >= DoAmMax)
            {
               DoAmMin=55;
            }
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            DoAmMin=DoAmMin-1;
            if(DoAmMin<40)
            {
               DoAmMin=55;
            }
         }
      }       
      
   }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

