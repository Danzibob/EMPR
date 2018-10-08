// Serial code
#include "lpc17xx_uart.h"		// Central include files
#include "lpc17xx_pinsel.h"
#include "lpc_types.h"
#include "lpc17xx_gpio.h"

int timems = 0;
// Function Prototypes
void delayms(int);

// Define our pin numbers
#define LED1 18
#define LED2 20
#define LED3 21
#define LED4 23
int LEDs[4] = {1<<LED1, 1<<LED2, 1<<LED3, 1<<LED4};
int allLEDs= (1<<LED1)|(1<<LED2)|(1<<LED3)|(1<<LED4);

int main(){
  // Initialize LED GPIO to out
  GPIO_SetDir(1, 0xFFFFFFFF, 1);
  int digit = 2;
  GPIO_SetValue(1, LEDs[digit]);
  GPIO_SetValue(1, LEDs[1]);

  while (true){
    delayms(1000);
    GPIO_SetValue(1, allLEDs);
    delayms(1000);
    GPIO_SetValue(1, allLEDs);
  }

}

void delayms(int ms){
	int start = timems;
	while(timems - start < ms){}
}
