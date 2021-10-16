
 /******************************************************************************
 *
 * Module: Project 3
 *
 * File Name: nancy_bahaa_eldin_mini_project3.c
 *
 * Description: Fan controller system
 *
 * Author: nancy bahaa eldin
 *
 *******************************************************************************/
#include "common_macros.h"
#include "gpio.h"
#include "avr/io.h"
#include <util/delay.h>
#include "adc_driver.h"
#include "lcd_driver.h"
#include "lm35_sensor.h"
#include "DC_motor.h"
#include "PWM_driver.h"





int main()
{
	uint8 temp=0;
		LCD_init();
		DcMotor_init();
		ADC_ConfigType config_type= {INTERNAL,F_CPU_8};
	    ADC_init(&config_type);


		LCD_displayString("Temp =    C");

		while(1)
		{
		    	temp=LM35_getTemperature();
		    	LCD_moveCursor(0,3);

		    	if(temp<30)
		    	{
		    		DcMotor_Rotate(OFF,0);
		    		LCD_displayString("Fan is off");
		    		LCD_moveCursor(1,2);
		    		LCD_displayString("Temp = ");
		    		LCD_intgerToString(temp);
		    		LCD_displayString(" C ");

		    	}

		    	if(temp >= 30 && temp < 60)
		    	{
		    		DcMotor_Rotate(CCW,64);
		    		LCD_displayString("Fan is on ");
		    		LCD_moveCursor(1,2);
		    		LCD_displayString("Temp = ");
		    		LCD_intgerToString(temp);
		    		LCD_displayString(" C ");

		    	}

		    	if(temp >= 60 && temp < 90)
		    	{
		    		DcMotor_Rotate(CW,128);
		    		LCD_displayString("Fan is on ");
		    		LCD_moveCursor(1,2);
		    		LCD_displayString("Temp = ");
		    		LCD_intgerToString(temp);
		    		LCD_displayString(" C ");

		    	}

		    	if(temp >= 90 && temp < 120)
		    	{
		    		DcMotor_Rotate(CCW,192);
		    		LCD_displayString("Fan is on ");
		    		LCD_moveCursor(1,2);
		    		LCD_displayString("Temp = ");
		    		LCD_intgerToString(temp);
		    		LCD_displayString(" C ");

		    	}

		    	if( temp>= 120)
		    	{
		    		DcMotor_Rotate(CW,255);
		    		LCD_displayString("Fan is on ");
		    		LCD_moveCursor(1,2);
		    		LCD_displayString("Temp = ");
		    		LCD_intgerToString(temp);
		    		LCD_displayString(" C ");

		    	}


		    }
}
