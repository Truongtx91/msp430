/*
 * button.c
 *
 *  Created on: Sep 19, 2018
 *      Author: truongtx
 */

#include <drivers/include/gpio.h>
#include <msp430.h>

static CallBack _callback;
void pint_init()
{
    P1IE |=  BIT3;                            // P1.3 interrupt enabled
    P1IES |= BIT3;                            // P1.3 Hi/lo edge
    P1REN |= BIT3;                            // Enable Pull Up on SW2 (P1.3)
    P1IFG &= ~BIT3;                           // P1.3 IFG cleared
                                              //BIT3 on Port 1 can be used as Switch

    _BIS_SR(GIE);                 // Enter LPM4 w/interrupt
}

/*
 * Pin: mapping pin 1.0 ~ 1.7
 * Mode: output or input
 * */
void pin_mode(uint8_t pin, uint8_t mode){
    if(pin > 7){
        mode ? (P2DIR |= 1 << (pin - 8)) : (P2DIR &= ~(1 << (pin - 8)));
    }else{
        mode ? (P1DIR |= 1 << pin) : (P1DIR &=~(1 << pin));
    }
}

void digital_write(uint8_t pin, uint8_t value){
    if(pin > 7){
        value ? (P2OUT |= 1 << (pin - 8)) : (P2OUT &= ~(1 << (pin-8)));
    }else{
        value? (P1OUT |= 1 << pin) : (P1OUT &= ~(1 << pin));
    }
}

void attachInterrupt(CallBack IRCallback)
{
    _callback = IRCallback;
}


// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){

  if(_callback != NULL)
      _callback(0);
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared
}

