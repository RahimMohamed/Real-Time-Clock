/* 
 * File:   function.c
 * Author: Rahim Mohamed 
 *
 * Created on June 17, 2024, 6:47 AM
 */

#include "application.h"
void intialization( void){
    
    lcd_4bit_intialize(&lcd);
    keypad_intialize(&keypad);
    gpio_pin_direction_intialize(&Line_H1);
    gpio_pin_direction_intialize(&Line_H2);
    gpio_pin_direction_intialize(&Line_M1);
    gpio_pin_direction_intialize(&Line_M2);
    gpio_pin_direction_intialize(&Line_S1);
    gpio_pin_direction_intialize(&Line_S2);
    segment_intialize(&clock);
    Timer0_Init(&delay);
   
}
/**********************************************************************************************************/
void welcome_message(void){
    
     lcd_4bit_send_string_pos(&lcd,2,7,"Welcome");
    __delay_ms(250);
    lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    __delay_ms(20);
}

/**********************************************************************************************************/

void TMR0_ISR (void){
 counter++;
 if (counter == 2){
  counter=0,sec++;
  if(sec>59){sec=0,min++;}
  if(min>59){min=0,hours++;}
  if(hours>23){hours=0;}
 }
 else{/*Nothing*/}
}
/**********************************************************************************************************/
void write_clock (void){
    
gpio_port_Write_logic(PORTA_INDEX,0x3E);
    segment_write_number(&clock,hours/10);
   __delay_ms(3);
   gpio_port_Write_logic(PORTA_INDEX,0x3D);
    segment_write_number(&clock,hours%10);
   __delay_ms(3);
    gpio_port_Write_logic(PORTA_INDEX,0x3B);
    segment_write_number(&clock,min/10);
   __delay_ms(3);
    gpio_port_Write_logic(PORTA_INDEX,0x37);
    segment_write_number(&clock,min%10);
   __delay_ms(3);
    gpio_port_Write_logic(PORTA_INDEX,0x2F);
    segment_write_number(&clock,sec/10);
    __delay_ms(3);
    gpio_port_Write_logic(PORTA_INDEX,0x1F);
    segment_write_number(&clock,sec%10);
    __delay_ms(3);
}
/**********************************************************************************************************/
void clock_setting (void){
    lcd_4bit_send_string_pos(&lcd,1,1,"Press 1 to");
    lcd_4bit_send_string_pos(&lcd,2,1,"Set Time");
    keypad_get_value(&keypad,&keypad_value);
    if (keypad_value == 1){Set_Time();}
    else {/*DO nothing*/}
}
/**********************************************************************************************************/
void Set_Time (void){
    uint_8 L_value=0xFF,display_value[4];
    Timer0_DeInit(&delay);
    min=0,sec=0,hours=0;
    write_clock();
    lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    __delay_ms(20);
    /*-------------------------------------------Set Hours------------------------------------------------*/
   lcd_4bit_send_string_pos(&lcd,1,1,"Hours = __");
   display_counter=9;
   while(setting_counter != 2){
        __delay_ms(200); 
     keypad_get_value(&keypad,&L_value);
     if(L_value != 0xFF){
         hours=(hours*10)+L_value;
         convert_byte_to_string(L_value,display_value);
       lcd_4bit_send_string_pos(&lcd,1,display_counter,display_value);
       display_counter++,setting_counter++;
     }
   }
   __delay_ms(250); 
   lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    __delay_ms(20);
   setting_counter=0;
    /*-------------------------------------------Set Minutes------------------------------------------------*/
   lcd_4bit_send_string_pos(&lcd,1,1,"Minutes = __");
   display_counter=11;
   while(setting_counter != 2){
        __delay_ms(200); 
     keypad_get_value(&keypad,&L_value);
     if(L_value != 0xFF){
         min=(min*10)+L_value;
         convert_byte_to_string(L_value,display_value);
       lcd_4bit_send_string_pos(&lcd,1,display_counter,display_value);
       display_counter++,setting_counter++;
     }
   }
   __delay_ms(250); 
   lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    __delay_ms(20);
   setting_counter=0;
  /*-------------------------------------------Set Seconds------------------------------------------------*/
    lcd_4bit_send_string_pos(&lcd,1,1,"Seconds = __");
   display_counter=11;
   while(setting_counter != 2){
        __delay_ms(200); 
     keypad_get_value(&keypad,&L_value);
     if(L_value != 0xFF){
         sec=(sec*10)+L_value;
         convert_byte_to_string(L_value,display_value);
       lcd_4bit_send_string_pos(&lcd,1,display_counter,display_value);
       display_counter++,setting_counter++;
     }
   }
   __delay_ms(250); 
   lcd_4bit_send_command(&lcd,_LCD_CLEAR);
    __delay_ms(20);
   write_clock();
   setting_counter=0;
   Timer0_Init(&delay);
}



