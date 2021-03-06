
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

/*************	功能说明	**************

本文件为STC15xxx系列的端口初始化程序,用户几乎可以不修改这个程序.


******************************************/

#include	"GPIO.h"


//========================================================================
// 函数: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// 描述: 初始化IO口.
// 参数: GPIOx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2012-10-22
//========================================================================
u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P5)				return 1;	//空操作
	if(GPIOx->Mode > GPIO_OUT_PP)	return 2;	//错误
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //推挽输出
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //上拉准双向口
		if(GPIOx->Mode == GPIO_HighZ)		P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //浮空输入
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //开漏输出
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //推挽输出
	}
	return 0;	//成功
}

//========================================================================
// 函数: u8 GPIO_WritePin(u8 GPIO , u8 Pinx , bit Level)
// 描述: 实现写入引脚高低电平
// 参数: GPIO ：选择P0,P1,P2,P3端口
//       Pinx ：Px^0~Px^7 
//       Level: LOW 0 ，HIGH  1
// 返回: 成功返回0, 空操作返回1,错误返回2.
//========================================================================
u8 GPIO_WritePin(u8 GPIO , u8 Pinx , bit Level)
 { 
	 if(GPIO > GPIO_P5)				return 1;	//空操作
	 if(Pinx > GPIO_Pin_All)	return 2;	//错误
	 if(GPIO == GPIO_P0)     //选择P0端口
	  {
	   if(Level==1)
		  P0 = P0|Pinx;        //选择的端口引脚置1
	   else
	    P0 = P0&(~Pinx);     //选择的端口引脚置0
    }
	 if(GPIO == GPIO_P1)  //选择P1端口
	  {
	   if(Level==1)
		  P1 = P1|Pinx;        //选择的端口引脚置1
	   else
	    P1 = P1&(~Pinx);     //选择的端口引脚置0
    }
		if(GPIO == GPIO_P2)
	  {
	   if(Level==1)
		 	P2 = P2|Pinx;        //选择的端口引脚置1
	   else
	    P2 = P2&(~Pinx);     //选择的端口引脚置0
    }
		if(GPIO == GPIO_P3)
	  {
	   if(Level==1)
		 	P3 = P3|Pinx;        //选择的端口引脚置1
	   else
	    P3 = P3&(~Pinx);     //选择的端口引脚置0
    }
		if(GPIO == GPIO_P4)
	  {
	   if(Level==1)
		 	P4 = P4|Pinx;        //选择的端口引脚置1
	   else
	    P4 = P4&(~Pinx);     //选择的端口引脚置0
    }
		if(GPIO == GPIO_P5)
	  {
	   if(Level==1)
		 	P5 = P5|Pinx;        //选择的端口引脚置1
	   else
	    P5 = P5&(~Pinx);     //选择的端口引脚置0
    }
		return 0;
 }
 
//========================================================================
// 函数: bit GPIO_ReadPin(u8 GPIO , u8 Pinx)
// 描述: 实现读取单个引脚电平
// 参数: GPIO ：选择P0,P1,P2,P3端口
//       Pinx ：Px^0~Px^7 
// 返回: HIGH  高电平 ，LOW  低电平
//========================================================================
 bit GPIO_ReadPin(u8 GPIO , u8 Pinx)
 {
	 if(GPIO == GPIO_P0)     //选择P0端口
	  {
	    if((P0 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P1)     //选择P1端口
	  {
	    if((P1 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P2)     //选择P2端口
	  {
	    if((P2 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P3)     //选择P3端口
	  {
	    if((P3 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P4)     //选择P4端口
	  {
	    if((P4 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P5)     //选择P5端口
	  {
	    if((P5 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		return 1;
 }
 
 //========================================================================
// 函数: u8 GPIO_Read8bit(u8 GPIO)
// 描述: 实现写入引脚高低电平
// 参数: GPIO ：选择P0,P1,P2,P3端口
// 返回: 返回Px端口电平状态
//========================================================================
 u8 GPIO_Read8bit(u8 GPIO)
 {
	   if(GPIO > GPIO_P5)				
			 return 1;	//空操作
	   if(GPIO == GPIO_P0) 
			 return P0;
	   if(GPIO == GPIO_P1) 
			 return P1;
	   if(GPIO == GPIO_P2) 
			 return P2;
	   if(GPIO == GPIO_P3) 
			 return P3;
	   if(GPIO == GPIO_P4) 
			 return P4;
	   return 2;
 }