#include "LED.h"
#include "GPIO.h"

u8 LED[] = {LED0_Pin,LED1_Pin,LED2_Pin,LED3_Pin,LED4_Pin,LED5_Pin,LED6_Pin,LED7_Pin};

void LED_On(u8 led_port,u8 led_pin )
{
  GPIO_WritePin(led_port ,led_pin , LOW);
}

void LED_Off(u8 led_port,u8 led_pin)
{
  GPIO_WritePin(led_port ,led_pin , HIGH);
}

void LED_Close()
{
	GPIO_WritePin(LED_PORT0 , GPIO_Pin_All , HIGH);
}

void LED_LeftToRight(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
    LED_On(LED_PORT0, LED[Pinx]);  
  }
  else if (Pinx >= LED_NUM_0) 
  {
    LED_Close();
  }
  else 
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
    LED_On(LED_PORT0, LED[LED_NUM_1 - 1 - Pinx]);  
  }
  else if (Pinx >= LED_NUM_1) 
  {
    LED_Close();
  }
  else 
  {   
    LED_On(LED_PORT0, LED[LED_NUM_1 - 1 - Pinx]);
    Pinx--;
    LED_Off(LED_PORT0, LED[LED_NUM_1 - 1 - Pinx]);    
  }
}

void LED_SideToCenter(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
		LED_On(LED_PORT0, LED[Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_1 - 1 - Pinx]);  
  }
  else if (Pinx >= LED_NUM_2) 
  {
    LED_Close();
  }
  else 
  {   
    LED_On(LED_PORT0, LED[Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_1 - 1 - Pinx]);  
    Pinx--;
		LED_Off(LED_PORT0, LED[Pinx]);
    LED_Off(LED_PORT0, LED[LED_NUM_1 - 1 - Pinx]);  
  }
}

void LED_CenterToSide(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
		LED_On(LED_PORT0, LED[LED_NUM_3 - 1 -  Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_3 + Pinx]);  
  }
  else if (Pinx >= LED_NUM_3) 
  {
    LED_Close();
  }
  else 
  {   
    LED_On(LED_PORT0, LED[LED_NUM_3 - 1 -  Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_3 + Pinx]);  
    Pinx--;
		LED_Off(LED_PORT0, LED[LED_NUM_3 - 1 -  Pinx]);
    LED_Off(LED_PORT0, LED[LED_NUM_3 + Pinx]);  
  }
}
