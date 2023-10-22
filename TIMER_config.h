/*******************************************************/
/****   Author : Ibrahim Elshimy      ******************/
/****   SWC:          TIMER_config.h  ******************/
/****   Date :        5/8/2023        ******************/
/****   Version : 1.00                ******************/
/*******************************************************/
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
/*
 * AVR: Timer is 8 bit resolution
 *    : External Clock is 8MHZ
 * */

/*Choose the Timer Mode :
 *                       1) NORMAL_MODE
 *                       2) PWM_MODE
 *                       3) CTC_MODE
 *                       4) FAST_PWM_MODE
 * */
#define    TIMER_MODE     CTC_MODE

/*Choose COMPAREMATCH_MODE_NO_PWM OC0 PIN :
 *                      1) DISCONNECTED_OC0
 *                      2) TOGGLE_0C0
 *                      2) CLEAR_0C0
 *                      3) SET_0C0
 * */
#define COMP_MATCH_NO_PWM     DISCONNECTED_OC0


/*Choose the Mode in FAST_PWM_MODE :
 *                                 1) NON_INVERTED_MODE  //CLEAR_OC0_ONCOMPMATCH_SET_OCO_ONTOP
 *                                 2) INVERTED_MODE      //SET_OC0_ONCOMPMATCH_CLEAR_OCO_ONTOP
 *
 *                                 PIN 0C0 is the Output HW PWM pin
 * */
#define COMPARE_FASTPWMMODE  NON_INVERTED_MODE

/*Choose the PRE-SCALER  :
 *                       1) NO_CLOCK_SOURCE
 *                       2) NO_PRESCALER
 *                       3) PRESCALER_BY_8
 *                       4) PRESCALER_BY_64
 *                       5) PRESCALER_BY_256
 *                       6) PRESCALER_BY_1024
 *                       7) EXTERNAL_CLOCK_FALLING_EDGE_T0Pin      // PORTB-pin0
 *                       8) EXTERNAL_CLOCK_RISING_EDGE_T0Pin
 * */
#define TIMER_PRESCALER    PRESCALER_BY_64

#endif
