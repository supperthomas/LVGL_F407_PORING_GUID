#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "touch.h" 

	
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化 
	KEY_Init(); 				//按键初始化 
  TIM3_Int_Init(999,83);	
	tp_dev.init();				//触摸屏初始化
	lv_init();						//lvgl系统初始化
	lv_demo_benchmark();
 	while(1)
	{
		lv_timer_handler();
	}
}
