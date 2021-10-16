 /******************************************************************************
 *
 * Module: DC motor
 *
 * File Name: DC_motor.c
 *
 * Description: Source file for the ATmega16 DC_motor.c
 *
 * Author: nancy bahaa eldin
 *
 *******************************************************************************/

#include "DC_motor.h"
#include "PWM_driver.h"
#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"
#include "std_types.h"

void DcMotor_init(void)
{
	/*setup the directions pins as output*/
    GPIO_setupPinDirection(PORTB, INPUT1, PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB, INPUT2, PIN_OUTPUT);
    /*stop the DC motor*/
    GPIO_writePin(PORTB, INPUT1, LOGIC_LOW);
    GPIO_writePin(PORTB, INPUT2, LOGIC_LOW);
}

void DcMotor_Rotate(const DcMotor_State State,uint8 speed)
{
	uint8 port_value=0;
	/*motor speed must be controlled using PWM duty cycle */
	PWM_Timer0_Start(speed);
	port_value=GPIO_readPort(PORTB_ID);
	/*state of motor configuration*/
	port_value=(port_value & 0xFC) | (State);
	GPIO_writePort (PORTB_ID,port_value);
}


