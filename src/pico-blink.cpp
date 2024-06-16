// Copyright 2024 by Bert Laverman, all rights reserved

#include <pico/stdlib.h>
#include <hardware/gpio.h>

#include <raspberry-pi.hpp>
#include <components/local-led.hpp>


using namespace nl::rakis::raspberrypi;


int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
    RaspberryPi& pi(RaspberryPi::instance());
    pi.gpio().verbose(true);

    stdio_init_all();
    pi.sleepMs(5000);
    printf("Starting blink.\n");

    components::LocalLed internalLed(pi, PICO_DEFAULT_LED_PIN);

    while (true) {
        internalLed.toggle();

        sleep_ms(500);
    }
}