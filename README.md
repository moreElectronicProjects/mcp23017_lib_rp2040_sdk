# MCP23017 Library For RP2040 C SDK

## Introduction

This repository contains the code which implements a library for the MCP23017 IO expander.

## Installation

This library requires no additional dependencies outside of the Raspberry Pi RP2040 C SDK. To install this library, download this repository into your project and add the following lines to your project's CMake file:

```
set(mcp23017_lib_dir {path_to_mcp23017_lib_folder})
include({path_to_mcp23017_lib_folder}/src/mcp23017_lib.cmake)
```

where `{path_to_mcp23017_lib_folder}` is replaced with the path to the library.

## Usage

This section describes the functions implemented by this library.

All functions have the same first two arguments. The following table lists these arguments and their purpose.

| Parameter number | Parameter Type | Parameter Name  | Parameter Description                                                                                                                     |
|------------------|----------------|-----------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 1                | `i2c_inst_t*`  | `hardware_i2c`  | A pointer to the RP2040's i2c hardware peripheral which the MCP23017 is connected to.                                                     |
| 2                | `uint8_t`      | `mcp23017_addr` | The address which the MCP23017 is listening on. This is in the form of 0b0100xxx, where xxx is address pins A2-A0 on the IC respectively. |

In the following sections, to get more information on a given function, see the comments in the header file located at [src/mcp23017_lib.h](src/mcp23017_lib.h).

### Initialization

The chip must be initialized prior to using any other functions.

This can be achieved by the `mcp23017_init` function. This function returns 0 if the initialization was successful and 1 otherwise. If the function returns 1, do not continue to use the library as the chip can be in an uninitialized state.

### General Chip Configuration

The following functions allows for general configuration of the chip.

- `mcp23017_set_int_mirror`

- `mcp23017_get_int_mirror`

- `mcp23017_set_int_open_drain`

- `mcp23017_get_int_open_drain`

- `mcp23017_set_int_polarity`

- `mcp23017_get_int_polarity`

### Configuring the Pins

The following functions allows for configuration of the chip's IO pins.

- `mcp23017_set_dir_gpioa`

- `mcp23017_get_dir_gpioa`

- `mcp23017_set_dir_gpiob`

- `mcp23017_get_dir_gpiob`

- `mcp23017_set_dir_gpioa_pin`

- `mcp23017_get_dir_gpioa_pin`

- `mcp23017_set_dir_gpiob_pin`

- `mcp23017_get_dir_gpiob_pin`

- `mcp23017_set_polarity_gpioa`

- `mcp23017_get_polarity_gpioa`

- `mcp23017_set_polarity_gpiob`

- `mcp23017_get_polarity_gpiob`

- `mcp23017_set_polarity_gpioa_pin`

- `mcp23017_get_polarity_gpioa_pin`

- `mcp23017_set_polarity_gpiob_pin`

- `mcp23017_get_polarity_gpiob_pin`

- `mcp23017_set_pullup_gpioa`

- `mcp23017_get_pullup_gpioa`

- `mcp23017_set_pullup_gpiob`

- `mcp23017_get_pullup_gpiob`

- `mcp23017_set_pullup_gpioa_pin`

- `mcp23017_get_pullup_gpioa_pin`

- `mcp23017_set_pullup_gpiob_pin`

- `mcp23017_get_pullup_gpiob_pin`

### GPIO Input and Output

The following functions allows for reading and writing to the chip's GPIO.

- `mcp23017_set_pins_gpioa`

- `mcp23017_get_pins_gpioa`

- `mcp23017_set_pins_gpiob`

- `mcp23017_get_pins_gpiob`

- `mcp23017_set_pins_gpioa_pin`

- `mcp23017_get_pins_gpioa_pin`

- `mcp23017_set_pins_gpiob_pin`

- `mcp23017_get_pins_gpiob_pin`

### Interrupt Configuration

The following functions allows for configuration of the chip's interrupt capabilities.

- `mcp23017_set_int_on_change_gpioa`

- `mcp23017_get_int_on_change_gpioa`

- `mcp23017_set_int_on_change_gpiob`

- `mcp23017_get_int_on_change_gpiob`

- `mcp23017_set_int_on_change_gpioa_pin`

- `mcp23017_get_int_on_change_gpioa_pin`

- `mcp23017_set_int_on_change_gpiob_pin`

- `mcp23017_get_int_on_change_gpiob_pin`

- `mcp23017_set_default_int_compare_gpioa`

- `mcp23017_get_default_int_compare_gpioa`

- `mcp23017_set_default_int_compare_gpiob`

- `mcp23017_get_default_int_compare_gpiob`

- `mcp23017_set_default_int_compare_gpioa_pin`

- `mcp23017_get_default_int_compare_gpioa_pin`

- `mcp23017_set_default_int_compare_gpiob_pin`

- `mcp23017_get_default_int_compare_gpiob_pin`

- `mcp23017_set_int_control_gpioa`

- `mcp23017_get_int_control_gpioa`

- `mcp23017_set_int_control_gpiob`

- `mcp23017_get_int_control_gpiob`

- `mcp23017_set_int_control_gpioa_pin`

- `mcp23017_get_int_control_gpioa_pin`

- `mcp23017_set_int_control_gpiob_pin`

- `mcp23017_get_int_control_gpiob_pin`

### Interrupt State

The following functions allows for querying the current state of the interrupt pins.

- `mcp23017_get_int_flag_gpioa`

- `mcp23017_get_int_captured_val_gpioa`

- `mcp23017_get_int_flag_gpiob`

- `mcp23017_get_int_captured_val_gpiob`

- `mcp23017_get_int_flag_gpioa_pin`

- `mcp23017_get_int_captured_val_gpioa_pin`

- `mcp23017_get_int_flag_gpiob_pin`

- `mcp23017_get_int_captured_val_gpiob_pin`

### Additional Features

By default, this library implements functions which allow the programmer to modify a single pin. For example, the programmer can modify the output of a single pin with the following command to set pin 7 on GPIO A to a logic LOW.

```
mcp23017_set_pins_gpioa_pin(mcp23017_i2c, mcp23017_addr, 7, 0);
```

All such functions can be identified as the end in `_pin` and require an additional parameter after the MCP23017_addr to specify the pin to modify or get the state of.

In case the programmer does not need these individual pin functions, these functions can be removed at compile time by adding the following line to you project's Cmake file:

```
set(mcp23017_lib_enable_individual_pin_functions OFF)
```

## Examples

This repository also contains examples on using this library. They can be found in the `examples` folder of this repository.
