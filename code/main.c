/* 
 * File:   main.c
 * Author: Rahim Mohamed 
 *
 * Created on June 17, 2024, 6:47 AM
 */

#include "application.h"
/***********************************************************************************************************88*/

int main(int argc, char** argv) {
    
    
    
    intialization();
    welcome_message();
    while(1){
        write_clock();
        clock_setting();
    }
    
    return (EXIT_SUCCESS);
}

