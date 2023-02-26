/*
 * This program reads the value on the MCP23017 GPIO port A and outputs the
 * value to the MCP23017 GPIO port B.
 */

// Include the needed libraries
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "../../src/mcp23017_lib.h"

// Define constants
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
    mcp23017_set_dir_gpioa(mcp23017_i2c, mcp23017_addr, 0b11111111);
    mcp23017_set_dir_gpiob(mcp23017_i2c, mcp23017_addr, 0b00000000);

    // Tight loop to read the state of the pins on GPIOA and output this value to GPIOB
    while(true) {
        uint8_t input_pin_state = mcp23017_get_pins_gpioa(mcp23017_i2c, mcp23017_addr);
        mcp23017_set_pins_gpiob(mcp23017_i2c, mcp23017_addr, input_pin_state);
        // Delay to keep slow the loop down
        sleep_ms(1);
    }
}
