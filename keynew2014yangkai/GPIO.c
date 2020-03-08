
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

/*************	����˵��	**************

���ļ�ΪSTC15xxxϵ�еĶ˿ڳ�ʼ������,�û��������Բ��޸��������.


******************************************/

#include	"GPIO.h"


//========================================================================
// ����: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// ����: ��ʼ��IO��.
// ����: GPIOx: �ṹ����,��ο�timer.h��Ķ���.
// ����: �ɹ�����0, �ղ�������1,���󷵻�2.
// �汾: V1.0, 2012-10-22
//========================================================================
u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P5)				return 1;	//�ղ���
	if(GPIOx->Mode > GPIO_OUT_PP)	return 2;	//����
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //�������
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //����׼˫���
		if(GPIOx->Mode == GPIO_HighZ)		P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //��������
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //��©���
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //�������
	}
	return 0;	//�ɹ�
}

//========================================================================
// ����: u8 GPIO_WritePin(u8 GPIO , u8 Pinx , bit Level)
// ����: ʵ��д�����Ÿߵ͵�ƽ
// ����: GPIO ��ѡ��P0,P1,P2,P3�˿�
//       Pinx ��Px^0~Px^7 
//       Level: LOW 0 ��HIGH  1
// ����: �ɹ�����0, �ղ�������1,���󷵻�2.
//========================================================================
u8 GPIO_WritePin(u8 GPIO , u8 Pinx , bit Level)
 { 
	 if(GPIO > GPIO_P5)				return 1;	//�ղ���
	 if(Pinx > GPIO_Pin_All)	return 2;	//����
	 if(GPIO == GPIO_P0)     //ѡ��P0�˿�
	  {
	   if(Level==1)
		  P0 = P0|Pinx;        //ѡ��Ķ˿�������1
	   else
	    P0 = P0&(~Pinx);     //ѡ��Ķ˿�������0
    }
	 if(GPIO == GPIO_P1)  //ѡ��P1�˿�
	  {
	   if(Level==1)
		  P1 = P1|Pinx;        //ѡ��Ķ˿�������1
	   else
	    P1 = P1&(~Pinx);     //ѡ��Ķ˿�������0
    }
		if(GPIO == GPIO_P2)
	  {
	   if(Level==1)
		 	P2 = P2|Pinx;        //ѡ��Ķ˿�������1
	   else
	    P2 = P2&(~Pinx);     //ѡ��Ķ˿�������0
    }
		if(GPIO == GPIO_P3)
	  {
	   if(Level==1)
		 	P3 = P3|Pinx;        //ѡ��Ķ˿�������1
	   else
	    P3 = P3&(~Pinx);     //ѡ��Ķ˿�������0
    }
		if(GPIO == GPIO_P4)
	  {
	   if(Level==1)
		 	P4 = P4|Pinx;        //ѡ��Ķ˿�������1
	   else
	    P4 = P4&(~Pinx);     //ѡ��Ķ˿�������0
    }
		if(GPIO == GPIO_P5)
	  {
	   if(Level==1)
		 	P5 = P5|Pinx;        //ѡ��Ķ˿�������1
	   else
	    P5 = P5&(~Pinx);     //ѡ��Ķ˿�������0
    }
		return 0;
 }
 
//========================================================================
// ����: bit GPIO_ReadPin(u8 GPIO , u8 Pinx)
// ����: ʵ�ֶ�ȡ�������ŵ�ƽ
// ����: GPIO ��ѡ��P0,P1,P2,P3�˿�
//       Pinx ��Px^0~Px^7 
// ����: HIGH  �ߵ�ƽ ��LOW  �͵�ƽ
//========================================================================
 bit GPIO_ReadPin(u8 GPIO , u8 Pinx)
 {
	 if(GPIO == GPIO_P0)     //ѡ��P0�˿�
	  {
	    if((P0 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P1)     //ѡ��P1�˿�
	  {
	    if((P1 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P2)     //ѡ��P2�˿�
	  {
	    if((P2 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P3)     //ѡ��P3�˿�
	  {
	    if((P3 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P4)     //ѡ��P4�˿�
	  {
	    if((P4 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		if(GPIO == GPIO_P5)     //ѡ��P5�˿�
	  {
	    if((P5 & Pinx) == Pinx)
				return HIGH;
			else
				return LOW;
    }
		return 1;
 }
 
 //========================================================================
// ����: u8 GPIO_Read8bit(u8 GPIO)
// ����: ʵ��д�����Ÿߵ͵�ƽ
// ����: GPIO ��ѡ��P0,P1,P2,P3�˿�
// ����: ����Px�˿ڵ�ƽ״̬
//========================================================================
 u8 GPIO_Read8bit(u8 GPIO)
 {
	   if(GPIO > GPIO_P5)				
			 return 1;	//�ղ���
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