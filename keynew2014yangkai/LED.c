#include "LED.h"
#include "GPIO.h"

u8 LED[] = {LED0_Pin,LED1_Pin,LED2_Pin,LED3_Pin,LED4_Pin,LED5_Pin,LED6_Pin,LED7_Pin};

void LED_On(u8 led_port,u8 led_pin )
{
  GPIO_WritePin(led_port ,led_pin , 0);
}

void LED_Off(u8 led_port,u8 led_pin)
{
  GPIO_WritePin(led_port ,led_pin , 1);
}

void LED_Close()
{
	GPIO_WritePin(LED_PORT0 , GPIO_Pin_All , 1);
}

void LED_LeftToRight(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
    LED_On(LED_PORT0, LED[Pinx]);  
  }
  else if (Pinx >= 8) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮右边的LED，再熄灭左边的
  {   
    LED_On(LED_PORT0, LED[Pinx]);
    Pinx--;
    LED_Off(LED_PORT0, LED[Pinx]);    
  }
}

void LED_RightToLeft(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
    LED_On(LED_PORT0, LED[7 - Pinx]);  
  }
  else if (Pinx >= 8) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮左的LED，再熄灭右边的
  {   
    LED_On(LED_PORT0, LED[7 - Pinx]);
    Pinx--;
    LED_Off(LED_PORT0, LED[7 - Pinx]);    
  }
}

void LED_SideToCenter(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
		LED_On(LED_PORT0, LED[Pinx]); 
    LED_On(LED_PORT0, LED[7 - Pinx]);  
  }
  else if (Pinx >= 8) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮左的LED，再熄灭右边的
  {   
    LED_On(LED_PORT0, LED[Pinx]); 
    LED_On(LED_PORT0, LED[7 - Pinx]);  
    Pinx--;
		LED_Off(LED_PORT0, LED[Pinx]);
    LED_Off(LED_PORT0, LED[7 - Pinx]);  
  }
}

void LED_CenterToSide(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
		LED_On(LED_PORT0, LED[3 -  Pinx]); 
    LED_On(LED_PORT0, LED[4 + Pinx]);  
  }
  else if (Pinx >= 4) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮左的LED，再熄灭右边的
  {   
    LED_On(LED_PORT0, LED[3 -  Pinx]); 
    LED_On(LED_PORT0, LED[4 + Pinx]);  
    Pinx--;
		LED_Off(LED_PORT0, LED[3 -  Pinx]);
    LED_Off(LED_PORT0, LED[4 + Pinx]);  
  }
}

void LED_Toggle(bit mode , u8 LED_GPIO , u8 Pinx)  //闪烁
{
	if(mode==1) 
		LED_On(LED_GPIO,Pinx);
  else   
		LED_Off(LED_GPIO,Pinx);
}