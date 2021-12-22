#include <stdint.h>
#include "cas-sdk/display.h"
#include "cas-sdk/debug.h"

#define FONTBASE 0x80632FD0

void word_to_string(uint16_t word, char* string);

char hex_chars[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F' };

void print_hex_word(uint16_t word, uint16_t x, uint16_t y, uint8_t size,
	cas_color foreground, cas_color background, uint8_t enable_transparency)
{
	char string[7];

	uint32_t counter = 0;

	word_to_string(word, string);

	while (string[counter] != 0 && (x + (counter * DEBUG_CHAR_WIDTH)) < DISPLAY_WIDTH)
	{
		print_char(string[counter], x + (counter * ((DEBUG_CHAR_WIDTH - 1) * (size + 1))), y, 
			size, foreground, background, enable_transparency);  
		counter++; 
	}    
}

void word_to_string(uint16_t word, char* string)
{
	string[0] = '0';
	string[1] = 'x';
	string[6] = 0;

	for(uint8_t x = 0; x < 4; x++)
	{
		string[x] = hex_chars[word % 16];
		word /= 16;
	}
}

void print_string(char *string, uint16_t x, uint16_t y, uint8_t size,
	cas_color foreground, cas_color background, uint8_t enable_transparency)
{
	uint32_t counter = 0;

	while (string[counter] != 0 && (x + (counter * (DEBUG_CHAR_WIDTH - 2) * (size + 1))) < DISPLAY_WIDTH)
	{
		print_char(string[counter], x + (counter * ((DEBUG_CHAR_WIDTH - 2) * (size + 1))), y, 
			size, foreground, background, enable_transparency);  
		counter++; 
	}    
}

void print_char(char character, uint16_t x, uint16_t y, uint8_t size,
	cas_color foreground, cas_color background, uint8_t enable_transparency)
{
	uint8_t charIndex = character - ' ';
	uint16_t tempXPos = x;
	uint16_t tempYPos = y;

	size = (size != 0);

	size++;

	// fill background with background color if it is not black
	if(background.as_uint16 || !enable_transparency)
	{
		for(uint8_t y = 0; y < ((DEBUG_CHAR_HEIGHT + 2) * size); y++)
		{
			tempXPos = x;

			for(uint8_t x = 0; x < (DEBUG_CHAR_WIDTH * size); x++)
			{
				display_framebuffer[tempYPos][tempXPos] = background;
				tempXPos++;
			}

			tempYPos++;
		}
	}

	// now draw the character
	uint16_t *pixel = (uint16_t *)(FONTBASE + (0xC0 * charIndex));

	tempXPos = x;
	tempYPos = y;

	tempYPos++;

	for(uint8_t y = 0; y < DEBUG_CHAR_HEIGHT; y++)
	{
		tempXPos = x;

		for(uint8_t x = 0; x < DEBUG_CHAR_WIDTH; x++)
		{
			if(*pixel == 0)
			{
				display_framebuffer[tempYPos][tempXPos] = foreground;

				if(size == 2)
				{
					display_framebuffer[tempYPos][tempXPos + 1] = foreground;
					display_framebuffer[tempYPos + 1][tempXPos] = foreground;
					display_framebuffer[tempYPos + 1][tempXPos + 1] = foreground;
				}
			}
			
			pixel++;   
			tempXPos += size;
		}

		tempYPos += size;
	}
}
