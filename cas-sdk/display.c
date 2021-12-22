#include <string.h>
#include <stdint.h>
#include "cas-sdk/display.h"

#define CLEARSCREEN_SR_ADDRESS  	(void*)0x800394EC
#define DRAWSCREEN_SR_ADDRESS   	(void*)0x8003735E
#define TURNOFFSCREEN_SR_ADDRESS	(void*)0x800379AE
#define TURNONSCREEN_SR_ADDRESS 	(void*)0x800379AA

void (*display_refresh)(void) = DRAWSCREEN_SR_ADDRESS;
void (*display_clear)(void) = CLEARSCREEN_SR_ADDRESS;
void (*display_power_off)(void) = TURNOFFSCREEN_SR_ADDRESS;
void (*display_power_on)(void) = TURNONSCREEN_SR_ADDRESS;

volatile cas_color (*display_framebuffer)[DISPLAY_WIDTH] = FRAMEBUFFER_ADDRESS;

void display_fill(cas_color fill_color)
{    
	for(uint16_t y = 0; y < DISPLAY_HEIGHT; y++)
	{
		for(uint16_t x = 0; x < DISPLAY_WIDTH; x++)
			display_framebuffer[y][x] = fill_color;
	}
}