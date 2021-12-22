#include <stdint.h>
#include "cas-sdk/input/touch-input.h"

#define PREVIOUSTOUCHSTATUS_ADDRESS (void*)0x8C1F45A3
#define PREVIOUSTOUCHPOSX_ADDRESS   (void*)0x8C1F45A0
#define PREVIOUSTOUCHPOSY_ADDRESS   (void*)0x8C1F459E
#define GETTOUCHINPUT_SR_ADDRESS    (void*)0x8007CF60

void touch_init()
{
	uint8_t* touch_status = PREVIOUSTOUCHSTATUS_ADDRESS;
	*touch_status = 0;

	uint16_t* touch_pos = PREVIOUSTOUCHPOSX_ADDRESS;
	*touch_pos = 0;

	touch_pos = PREVIOUSTOUCHPOSY_ADDRESS;
	*touch_pos = 0;
}

// gets touch input (needs rework, because is slow)
void input_get_touch(cas_touch_input* input)
{    
	uint8_t buffer[0x68];

	uint16_t* touch_pos_x = PREVIOUSTOUCHPOSX_ADDRESS;
	uint16_t* touch_pos_y = PREVIOUSTOUCHPOSY_ADDRESS;
	uint8_t* touch_status = PREVIOUSTOUCHSTATUS_ADDRESS;

	uint32_t result = ((uint32_t (*)(uint8_t*, int8_t, uint8_t))GETTOUCHINPUT_SR_ADDRESS)(buffer, 0xFF, 0x10);
	
	uint16_t condition_one = ((buffer[0] <<8) | (uint16_t)buffer[1]);

	if(result == 0 && condition_one != 5 && condition_one == 0x4000)
	{
		// get x-position
		*touch_pos_x = (uint16_t)((buffer[0xA] <<8) | (uint16_t)buffer[0xB]);
		
		// get y-position
		*touch_pos_y = (uint16_t)((buffer[0xE] <<8) | (uint16_t)buffer[0xF]);

		*touch_status = 0;

		uint32_t condition_two = buffer[4] <<24;
		condition_two |= buffer[5] <<16;
		condition_two |= buffer[6] <<8;
		condition_two |= buffer[7]; 

		if ((condition_two == 0x21 || condition_two == 0x22) && condition_two != 0x23)
			*touch_status = 2;   

		if(condition_two != 0x40 && condition_two != 0x23 && condition_two != 0x22 && condition_two != 0x21)
			*touch_status = 1;
	}
			
	input->is_touched = *touch_status;
	input->pos_x = *touch_pos_x;
	input->pos_y = *touch_pos_y;
}