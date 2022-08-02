#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "touch.h" 

	
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ�� 
	KEY_Init(); 				//������ʼ�� 
  TIM3_Int_Init(999,83);	
	tp_dev.init();				//��������ʼ��
	lv_init();						//lvglϵͳ��ʼ��
	lv_demo_benchmark();
 	while(1)
	{
		lv_timer_handler();
	}
}
