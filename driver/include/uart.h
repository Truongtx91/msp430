/*
 * uart.h
 *
 *  Created on: Oct 16, 2018
 *      Author: truongtx
 */

#ifndef DRIVER_INCLUDE_UART_H_
#define DRIVER_INCLUDE_UART_H_

#include "type.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

/* Macro to ignore unused parameters */
#define IGNORE(p)         ((void) p)

typedef struct
{
    uint32_t baud;
} uart_config_t;

/**
 * \brief Initialize the UART peripheral
 * \param[in] config - the UART configuration
 * \return 0 on success, -1 otherwise
 */
int8_t uart_init(uart_config_t *config);

/*Enable interrupt receive data and transmit data*/
void uart_enableInt();

/*Disable interrupt*/
void uart_disableInt();

/**
 * \brief Read a character from UART
 * \return the character read on success, -1 if nothing was read
 */
int8_t uart_getchar(void);

/**
 * \brief Write a character to UART
 * \param[in] c - the character to write
 * \return 0 on sucess, -1 otherwise
 */
int8_t uart_putchar(int8_t c);

/**
 * \brief Write a string to UART
 * \return 0 on sucesss, -1 otherwise
 */
int8_t uart_puts(const int8_t *str);

/*
 * write a number to UART;
 * */
int8_t uart_putnum(uint32_t val, uint8_t dec, uint8_t neg);




#endif /* DRIVER_INCLUDE_UART_H_ */