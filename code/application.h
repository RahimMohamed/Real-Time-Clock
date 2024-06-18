/* 
 * File:   application.h
 * Author: Rahim Mohamed
 *
 * Created on June 17, 2024, 6:49 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*section : Includes  */

#include "ECU_LAYER/KEYPAD/ecu_keypad.h"
#include "ECU_LAYER/LCD/ecu_lcd.h"
#include "ECU_LAYER/SEGMENT/segment.h"
#include "MCAL_LAYER/interrupt/mcal_external_interrupt.h"
#include "MCAL_LAYER/EEPROM/eeprom.h"
#include "MCAL_LAYER/Timer0/Timer0.h"
#include "MCAL_LAYER/Timer1/TMR1.h"
#include "MCAL_LAYER/Timer2/TMR2.h"
#include "MCAL_LAYER/Timer3/TMR3.h"

/*section :  Functions Declaration  */
void intialization( void);
void welcome_message(void);
void TMR0_ISR (void);
void write_clock (void);
void clock_setting (void);
void Set_Time (void);
/*section : Macro Declaration  */


/*section : Macro Functions Declaration  */


/*section : Data Type Declaration  */

/*-----------------------------------LCD-------------------------------------*/
lcd_4bit_t lcd={
  .lcd_rs.direction=GPIO_OUTPUT,
  .lcd_rs.logic=LOW,
  .lcd_rs.port=PORTC_INDEX,
  .lcd_rs.pin=GPIO_PIN0, 
  .lcd_en.direction=GPIO_OUTPUT,
  .lcd_en.logic=LOW,
  .lcd_en.port=PORTC_INDEX,
  .lcd_en.pin=GPIO_PIN1,
  .lcd_data[0].direction=GPIO_OUTPUT,
  .lcd_data[0].logic=LOW,
  .lcd_data[0].port=PORTC_INDEX,
  .lcd_data[0].pin=GPIO_PIN2,
  .lcd_data[1].direction=GPIO_OUTPUT,
  .lcd_data[1].logic=LOW,
  .lcd_data[1].port=PORTC_INDEX,
  .lcd_data[1].pin=GPIO_PIN3,
  .lcd_data[2].direction=GPIO_OUTPUT,
  .lcd_data[2].logic=LOW,
  .lcd_data[2].port=PORTC_INDEX,
  .lcd_data[2].pin=GPIO_PIN4,
  .lcd_data[3].direction=GPIO_OUTPUT,
  .lcd_data[3].logic=LOW,
  .lcd_data[3].port=PORTC_INDEX,
  .lcd_data[3].pin=GPIO_PIN5,
};
/*-----------------------------------KEYPAD-------------------------------------*/
keypad_t keypad ={
    
    .rows_pins[0].direction=GPIO_OUTPUT,
    .rows_pins[0].logic=LOW,
    .rows_pins[0].port=PORTD_INDEX,
    .rows_pins[0].pin=GPIO_PIN0,
    .rows_pins[1].direction=GPIO_OUTPUT,
    .rows_pins[1].logic=LOW,
    .rows_pins[1].port=PORTD_INDEX,
    .rows_pins[1].pin=GPIO_PIN1,
    .rows_pins[2].direction=GPIO_OUTPUT,
    .rows_pins[2].logic=LOW,
    .rows_pins[2].port=PORTD_INDEX,
    .rows_pins[2].pin=GPIO_PIN2,
    .rows_pins[3].direction=GPIO_OUTPUT,
    .rows_pins[3].logic=LOW,
    .rows_pins[3].port=PORTD_INDEX,
    .rows_pins[3].pin=GPIO_PIN3,
    .columns_pins[0].direction=GPIO_INPUT,
    .columns_pins[0].logic=LOW,
    .columns_pins[0].port=PORTD_INDEX,
    .columns_pins[0].pin=GPIO_PIN4,
    .columns_pins[1].direction=GPIO_INPUT,
    .columns_pins[1].logic=LOW,
    .columns_pins[1].port=PORTD_INDEX,
    .columns_pins[1].pin=GPIO_PIN5,
    .columns_pins[2].direction=GPIO_INPUT,
    .columns_pins[2].logic=LOW,
    .columns_pins[2].port=PORTD_INDEX,
    .columns_pins[2].pin=GPIO_PIN6,
    .columns_pins[3].direction=GPIO_INPUT,
    .columns_pins[3].logic=LOW,
    .columns_pins[3].port=PORTD_INDEX,
    .columns_pins[3].pin=GPIO_PIN7,    
    
};
/*-----------------------------------7Segment-------------------------------------*/
segment_t clock={
  .segment_pins[0].direction=GPIO_OUTPUT,
  .segment_pins[0].logic=LOW,
  .segment_pins[0].port=PORTB_INDEX,
  .segment_pins[0].pin=GPIO_PIN0,
  .segment_pins[1].direction=GPIO_OUTPUT,
  .segment_pins[1].logic=LOW,
  .segment_pins[1].port=PORTB_INDEX,
  .segment_pins[1].pin=GPIO_PIN1,
  .segment_pins[2].direction=GPIO_OUTPUT,
  .segment_pins[2].logic=LOW,
  .segment_pins[2].port=PORTB_INDEX,
  .segment_pins[2].pin=GPIO_PIN2,
  .segment_pins[3].direction=GPIO_OUTPUT,
  .segment_pins[3].logic=LOW,
  .segment_pins[3].port=PORTB_INDEX,
  .segment_pins[3].pin=GPIO_PIN3,
  .type=SEGMENT_COMMON_CATHODE,
};
/*-----------------------------------Line Multiplexer-------------------------------------*/
pin_config_t Line_H1 ={
  .direction=GPIO_OUTPUT,
  .logic=LOW,
  .port=PORTA_INDEX,
  .pin=GPIO_PIN0,  
};
pin_config_t Line_H2 ={
  .direction=GPIO_OUTPUT,
  .logic=LOW,
  .port=PORTA_INDEX,
  .pin=GPIO_PIN1,  
};
pin_config_t Line_M1 ={
  .direction=GPIO_OUTPUT,
  .logic=LOW,
  .port=PORTA_INDEX,
  .pin=GPIO_PIN2,  
};

pin_config_t Line_M2 ={
  .direction=GPIO_OUTPUT,
  .logic=LOW,
  .port=PORTA_INDEX,
  .pin=GPIO_PIN3,  
};

pin_config_t Line_S1 ={
  .direction=GPIO_OUTPUT,
  .logic=LOW,
  .port=PORTA_INDEX,
  .pin=GPIO_PIN4,  
};

pin_config_t Line_S2 ={
  .direction=GPIO_OUTPUT,
  .logic=LOW,
  .port=PORTA_INDEX,
  .pin=GPIO_PIN5,  
};
/*-----------------------------------Timer-------------------------------------*/
Timer0_t delay={
    .Timer0_InterruptHandler=TMR0_ISR,
    .mode=Timer_mode,
    .Register_Size_flag=TIMER0_16BIT_FLAG,
    .PSA_flag=TIMER0_PSA_ON_FLAG,
    .PSA=PSA_16,
    .period=3036,
};
/*-------------------------------------------------------------------------------*/
uint_8 sec=45,min=59,hours=9,keypad_value=0,counter=0,setting_counter=0,display_counter=0;

#endif	/* APPLICATION_H */

