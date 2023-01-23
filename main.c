#include <stdio.h>
#include "pico/stdlib.h"

bool timerCallback (repeating_timer_t *rt) {
    printf("Timer callback\n");
    return true;
}

// #if defined RASPBERRYPI_PICO_W
// // Pico W
// #else
// // Pico
// #endif

repeating_timer_t timer;

int main() {
    stdio_init_all();

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    add_repeating_timer_ms(1000, timerCallback, NULL, &timer);

    while(true) {
        printf("Test print\n");

        gpio_put(25, 1);
        sleep_ms(1000);

        gpio_put(25, 0);
        sleep_ms(1000);
    }

    return 0;
}