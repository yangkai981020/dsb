#include	"config.h"
#include	"GPIO.h"
#include  "timer.h"
#include  "LED.h"

#define MODE0    500
#define MODE1    500
#define MODE2    500
#define MODE3    500

#define MODE_0 0x00
#define MODE_1 0x01
#define MODE_2 0x02
#define MODE_3 0x03
#define BUZZER_OPEN  500     //��������Ӧʱ��ms
#define BUZZER_CLOSE  500    //������ֹͣʱ��ms


#define BUZZER   P25

#define FLASE   0  
#define TRUE    1 

bit  mode0_next = FLASE;  
bit  mode1_next = FLASE;
bit  mode2_next = FLASE;  
bit  mode3_next = FLASE;
bit  buzzer1 = FLASE;

u8 mode = MODE_0;
unsigned int cnt = 0; 
unsigned int buzzer_timers = 0; 
u8 i = 0;

void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//�ṹ����
	GPIO_InitStructure.Pin  = GPIO_Pin_All;		//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);
}

void	Timer_config(void)
{
	TIM_InitTypeDef		TIM_InitStructure;					//�ṹ����
	TIM_InitStructure.TIM_Mode      = TIM_8BitAutoReload;	//ָ������ģʽ,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//ָ���ж����ȼ�, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;//DISABLE;				//�ж��Ƿ�����,   ENABLE��DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;			//ָ��ʱ��Դ,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//�Ƿ������������, ENABLE��DISABLE
	TIM_InitStructure.TIM_Value     = 5;		//��ֵ,
	TIM_InitStructure.TIM_Run       = ENABLE;				//�Ƿ��ʼ����������ʱ��, ENABLE��DISABLE
	Timer_Inilize(Timer0,&TIM_InitStructure);				//��ʼ��Timer0	  Timer0,Timer1,Timer2
}

void timer0_int (void) interrupt TIMER0_VECTOR
{  
	  cnt++;
	  buzzer_timers ++ ;
    if (cnt % MODE0 == 0)  mode0_next = TRUE ;
    if (cnt % MODE1 == 0)  mode1_next = TRUE ;
	  if (cnt % MODE2 == 0)  mode2_next = TRUE ;
    if (cnt % MODE3 == 0)  mode3_next = TRUE ;
	  if (buzzer_timers <= BUZZER_OPEN)  buzzer1 = TRUE ;
	  if (buzzer_timers > BUZZER_OPEN && buzzer_timers <=  (BUZZER_OPEN + BUZZER_CLOSE)) buzzer1 = FLASE ;
	  if (buzzer_timers == (BUZZER_OPEN + BUZZER_CLOSE)) buzzer_timers = 0;
    if (cnt % 60000 == 0) cnt = 0;
}


/******************** ������ **************************/
void main(void)
{
	GPIO_config();
	Timer_config();
	EA = 1;
	while(1)
	{
    switch (mode) 
    {
      case MODE_0:
      {
         if (mode0_next == TRUE)
         {
            mode0_next = FALSE;
            LED_LeftToRight(i);
            if( i >= LED_NUM_0 + 1) 
            {
							i = 0;
              mode = MODE_1;
              break;
            } 
            i++;
         }
       }break;
      case MODE_1:
      {
				if (mode1_next == TRUE)
         {
            mode1_next = FALSE;
            LED_RightToLeft(i);
            if( i >= LED_NUM_1 + 1) 
            {
							i = 0;
              mode = MODE_2;
              break;
            } 
            i++;
         }     
      }break;				
			case MODE_2:
      {
				if (mode2_next == TRUE)
         {
            mode2_next = FALSE;
            LED_SideToCenter(i);	
            if( i >= LED_NUM_2 + 1) 
            {
							i = 0;
              mode = MODE_3;
              break;
            } 
            i++;
         }      			 
      }break;	
			case MODE_3:
      {
				if (mode3_next == TRUE)
         {
            mode3_next = FALSE;
            LED_CenterToSide(i);
            if( i >= LED_NUM_3 + 1) 
            {
							i = 0;
              mode = MODE_0;
              break;
            } 
            i++;
         }  		 
      } break;		
    }	
		if(buzzer1 == TRUE) BUZZER = 1;
		if(buzzer1 == FLASE) BUZZER = 0;
	}
}




