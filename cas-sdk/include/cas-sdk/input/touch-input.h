#ifndef TOUCH_INPUT_H
#define TOUCH_INPUT_H

#include <stdint.h>

/// @brief A type to store touch input
typedef struct cas_touch_input
{
  uint16_t pos_x; // The x position of the touch event
  uint16_t pos_y;	// The y position of the touch event
  uint8_t is_touched; // 1 if there are any touch events, else 0
} cas_touch_input;

/// @brief Initialize touch input. Call this once before trying to read any touch input. Please note that touch input events are not implemented completely yet and using them is therefore experimental.
void touch_init();

/*!
	@brief Get the current touch input and save it to the specified input struct. Please note that touch input events are not implemented completely yet. When there is no touch input, this function will hold the cpu for about a second for unknown reasons.
	@param input A pointer to the \b cas_touch_input struct where the input should be saved to
 */
void input_get_touch(cas_touch_input* input);

#endif