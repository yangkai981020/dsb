#include "key.h"

bit key_detection(u8 GPIOx , u8 Pinx)
{
	 bit key_d;
   static bit key_o = 1; //��һ������״̬
   bit key_n;               //��ǰ����״̬
	
   if(GPIO_ReadPin(GPIOx , Pinx) != 1)
     key_n = 0;
   else
     key_n = 1;
	 
   key_d = (key_n ^ key_o) & key_o;
	 key_o = key_n;
	 return key_d;
}

