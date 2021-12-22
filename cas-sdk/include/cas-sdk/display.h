#ifndef DISPLAY_H
#define DISPLAY_H

#include <string.h>
#include <stdint.h>

#define DISPLAY_WIDTH       320
#define DISPLAY_HEIGHT      528

/// @brief Starting address of the framebuffer
#define FRAMEBUFFER_ADDRESS (void*)0x8C000000

/// @brief A type for 16-bit 565 colors. Typically used when manipulating screen contents.
typedef union
{
	uint16_t as_uint16; // Get the color struct as a 16-bit unsigned int
	
	struct {
		uint16_t red : 5; // Bit 11 - 15 of the 16 bit color struct
		uint16_t green : 6; // Bit 5 - 10 of the 16 bit color struct
		uint16_t blue : 5; // Bit 0 - 4 of the 16 bit color struct
	};
} cas_color;

/// @brief A pointer to the framebuffer 2D-array with a width of \b DISPLAY_WIDTH and height of \b DISPLAY_HEIGHT
extern volatile cas_color (*display_framebuffer)[DISPLAY_WIDTH];

/// @brief Refresh the displays content with the current content in the framebuffer 
extern void (*display_refresh)(void);

/// @brief Fill the framebuffer with 0x0000 (black) 
extern void (*display_clear)(void);

/// @brief Turn the display off
extern void (*display_power_off)(void);

/// @brief Turn the display on
extern void (*display_power_on)(void);

/*! 
	@brief Fill the display with the specified color
 	@param fill_color The color with which the display should be filled
*/
void display_fill(cas_color fill_color);

#endif