/*
 * This program does a LED walking pattern on GPIO port A and B on the MCP23017.
 */

// Include the needed libraries
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "../../src/mcp23017_lib.h"

// Define the constants
#define mcp23017_addr 0b0100000
#define mcp23017_scl_pin 4
#define mcp23017_sda_pin 5

int main()
{
    // Get a pointer to the i2c0 hardware peripheral
    i2c_inst_t *mcp23017_i2c = i2c0;

    // Initialize all pico io
    stdio_init_all();

    // Initialize the i2c peripheral to 400 kHz
    i2c_init(mcp23017_i2c, 400*1000);

    // Setup the i2c lines on the pico
    gpio_set_function(mcp23017_scl_pin, GPIO_FUNC_I2C);
    gpio_set_function(mcp23017_sda_pin, GPIO_FUNC_I2C);
    gpio_pull_up(mcp23017_scl_pin);
    gpio_pull_up(mcp23017_sda_pin);

    // Initialize the MCP23017 and configure all pins on port A as inputs and all pins port B as outputs
    mcp23017_init(mcp23017_i2c, mcp23017_addr);
    mcp23017_set_dir_gpioa(mcp23017_i2c, mcp23017_addr, 0b00000000);
    mcp23017_set_dir_gpiob(mcp23017_i2c, mcp23017_addr, 0b00000000);

    // Setup the outputs the first state in the pattern
    mcp23017_set_pins_gpioa(mcp23017_i2c, mcp23017_addr, 0b10000000);
    mcp23017_set_pins_gpiob(mcp23017_i2c, mcp23017_addr, 0b00000001);

    // Loop through each step of the pattern with a 1ms delay between steps
    while(true) {
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 7, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 6, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 0, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 1, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 6, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 5, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 1, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 2, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 5, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 4, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 2, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 3, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 4, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 3, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 3, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 4, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 3, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 2, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 4, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 5, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 2, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 1, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 5, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 6, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 1, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 0, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 6, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 7, 1);
        sleep_ms(1);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 0, 0);
        mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 7, 1);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 7, 0);
        mcp23017_set_pins_gpiob_pin(mcp23017_i2c, mcp23017_addr, 0, 1);
        sleep_ms(1);
    }
}
