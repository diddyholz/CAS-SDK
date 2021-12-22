#ifndef DEBUG_H
#define DEBUG_H

#include <stdint.h>
#include "display.h"

/// @brief The width of a character in pixels
#define DEBUG_CHAR_WIDTH 	8

/// @brief The height of a character in pixels
#define DEBUG_CHAR_HEIGHT	12

/*!
	@brief Print a character at an absolute position on the screen
	@param character The character to print
	@param x The x-position where the character should be printed in pixels
	@param y The y-position where the character should be printed in pixels
	@param size Pass 0 to print in normal size and 1 to print double sized
	@param foreground The color in which the text should be printed
	@param background The background of the text
	@param enable_transparency Pass 0 to disable the use of black (0x0000) background as transparent
*/
void print_char(char character, uint16_t x, uint16_t y, uint8_t size,
	cas_color foreground, cas_color background, uint8_t enable_transparency);

/*!
	@brief Print a string at an absolute position on the screen
	@param string A pointer to the string to be printed
	@param x The x-position where the character should be printed in pixels
	@param y The y-position where the character should be printed in pixels
	@param size Pass 0 to print in normal size and 1 to print double sized
	@param foreground The color in which the text should be printed
	@param background The background of the text
	@param enable_transparency Pass 0 to disable the use of black (0x0000) background as transparent
*/
void print_string(char *string, uint16_t x, uint16_t y, uint8_t size,
	cas_color foreground, cas_color background, uint8_t enable_transparency);

/*!
	@brief Print a 16-bit word as hex at an absolute position on the screen
	@param word The 16-bit word to be printed
	@param x The x-position where the character should be printed in pixels
	@param y The y-position where the character should be printed in pixels
	@param size Pass 0 to print in normal size and 1 to print double sized
	@param foreground The color in which the text should be printed
	@param background The background of the text
	@param enable_transparency Pass 0 to disable the use of black (0x0000) background as transparent
*/
void print_hex_word(uint16_t word, uint16_t x, uint16_t y, uint8_t size,
	cas_color foreground, cas_color background, uint8_t enable_transparency);

#endif