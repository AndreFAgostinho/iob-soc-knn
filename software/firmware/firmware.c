//#include "stdlib.h"
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"

int main()
{
  //init uart
  uart_init(UART_BASE,FREQ/BAUD);
  int n, x, y;

  y = 0;
  for( n = 0 ; n < 100 ; n++ ) {
    x = rand()%4096 - 2048; // signed 12 bit random number with 0 average [-2048, 2047]
    y = y + (x>0?x:-x); // in average y = 1024*n
    uart_printf("n = %d |x: %d |y: %d\n", n, x, y);
  }
}
