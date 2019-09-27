/*
 * uart.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Yasas Tharinda
 */

#ifndef UART_H_
#define UART_H_



#include "main.h"
#include "string.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"

#define UART_BUFFER_SIZE 64


typedef struct
{
  unsigned char buffer[UART_BUFFER_SIZE];
  volatile  int head;
  volatile  int tail;
} ring_buffer;

class MULTIPLE_UART{
private:

	UART_HandleTypeDef *uart;

	ring_buffer rx_buffer ;
	ring_buffer tx_buffer ;

	ring_buffer *_rx_buffer;
	ring_buffer *_tx_buffer;
//	ring_buffer *_rx_buffer;
//	ring_buffer *_tx_buffer;

public:
	void Uart_init(UART_HandleTypeDef* uart1);

	void Uart_write(int c);

	/* function to send the string to the uart */
	void Uart_sendstring(const char *s);

	/* Print a number with any base
	 * base can be 10, 8 etc*/
	void Uart_printbase (long n, uint8_t base);

	/* Initialize the ring buffer */
	//void Ringbuf_init(void);

	/* checks if the data is available to read in the rx_buffer */
	int IsDataAvailable(void);

	/* get the position of the given string within the incoming data.
	 * It returns the position, where the string ends */
	uint16_t get_pos (char *string);

	/* the ISR for the uart. put it in the IRQ handler */
	void Uart_isr ();


	/* once you hit 'enter' (\r\n), it copies the entire string to the buffer*/
	void Get_string (char *buffer);

	/* keep waiting until the given string has arrived and stores the data in the buffertostore
	 * on success return 1
	 * or else returns 0
	 * @ usage :  while (!(wait_until("\r\n", buffer)));
	*/
	int wait_until (char *string, char *buffertostore);
	void store_char(unsigned char c, ring_buffer *buffer);
	int Uart_read(void);
	//void Get_string (char *buffer);

};
#endif
//void Uart_isr (UART_HandleTypeDef *huart);


