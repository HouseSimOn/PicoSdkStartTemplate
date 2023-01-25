#include <stdio.h>
#include "pico/stdlib.h"
#if defined RASPBERRYPI_PICO_W
#include "pico/cyw43_arch.h"
#endif

bool timerCallback (repeating_timer_t *rt) {
    printf("Timer callback\n");
    return true;
}

#if defined RASPBERRYPI_PICO_W
// Pico-W
void static setLedPin(bool State) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, State);
}
#else
// Pico
void static setLedPin(bool State) {
    gpio_put(25, State);
}
#endif

repeating_timer_t timer;

int main() {
    stdio_init_all();

#if defined RASPBERRYPI_PICO_W
    cyw43_arch_init();
#else
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
#endif

    add_repeating_timer_ms(1000, timerCallback, NULL, &timer);

    while(true) {
        printf("Test print\n");

        // gpio_put(25, 1);
        setLedPin(true);
        sleep_ms(1000);

        // gpio_put(25, 0);
        setLedPin(false);
        sleep_ms(1000);
    }

    return 0;
}
