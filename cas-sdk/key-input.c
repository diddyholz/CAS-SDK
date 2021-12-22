#include <stdint.h>
#include "cas-sdk/input/key-input.h"

#define KEYBOARDBUFFER_ADDRESS      0xA44B0000

// gets the input of the keyboard buffer
uint8_t input_get_keys(cas_key_input* input)
{
	uint32_t *buffer = (uint32_t *)KEYBOARDBUFFER_ADDRESS;

	input->buffer_one = *buffer;
	input->buffer_two = *(++buffer);
	
	volatile uint32_t temp = *(++buffer);
    
	return ((input->buffer_one || input->buffer_two) > 0);
}