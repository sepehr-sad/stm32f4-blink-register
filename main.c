#include "stm32f4xx.h"

int main(void) {
    // Enable the clock for GPIOA
    RCC->AHB1ENR |= (1 << 0);  // GPIOA clock enable

    // Set PA0 as output
    GPIOA->MODER &= ~((uint32_t)(0x3 << (0 * 2)));  // Clear the previous mode
    GPIOA->MODER |= (0x1 << (0 * 2));   // Set PA0 as output   
    while (1) {
        // Turn the LED on (PA0 high)
        GPIOA->BSRR |= (1 << 0);

        // Delay (simple software loop)
        for (int i = 0; i < 1000000; i++);

        // Turn the LED off (PA0 low)
        GPIOA->BSRR |= (1 << (0 + 16));

        // Delay (simple software loop)
        for (int i = 0; i < 1000000; i++);
    }
}
