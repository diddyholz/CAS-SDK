#ifndef KEY_INPUT_H
#define KEY_INPUT_H

#include <stdint.h>

// keycodes for buffer 1
#define KEY_EXE_1           0x04000000
#define KEY_PLUS_1          0x08000000
#define KEY_MINUS_1         0x10000000
#define KEY_MULTIPLY_1      0x20000000
#define KEY_DIVIDE_1        0x40000000
#define KEY_SHIFT_1         0x80000000
#define KEY_ON_CLEAR_1      0x00020000
#define KEY_Z_1             0x00002000
#define KEY_LEFT_1          0x00004000
#define KEY_RIGHT_1         0x00008000
#define KEY_EXP_1           0x00000004
#define KEY_3_1             0x00000008
#define KEY_6_1             0x00000010
#define KEY_9_1             0x00000020
#define KEY_CAROT_1         0x00000040
#define KEY_BACKSPACE_1     0x00000080

// keycodes for buffer 2
#define KEY_0_2             0x04000000
#define KEY_1_2             0x08000000
#define KEY_4_2             0x10000000
#define KEY_7_2             0x20000000
#define KEY_Y_2             0x40000000
#define KEY_KEYBOARD_2      0x80000000
#define KEY_DOT_2           0x00040000
#define KEY_2_2             0x00080000
#define KEY_5_2             0x00100000
#define KEY_8_2             0x00200000
#define KEY_DOWN_2          0x00400000
#define KEY_UP_2            0x00800000
#define KEY_PARANTHESES_O_2 0x00000200
#define KEY_X_2             0x00000400
#define KEY_EQUALS_2        0x00000800
#define KEY_MINUS_P_2       0x00000004
#define KEY_COMMA_2         0x00000008
#define KEY_PARANTHESES_C_2 0x00000010

/// @brief A type to store keyboard input
typedef struct cas_key_input
{
	uint32_t buffer_one; // The first keyboard buffer. KEY constants that end with 1s are saved in this buffer.
	uint32_t buffer_two; // The second keyboard buffer. KEY constants that end with 2s are saved in this buffer.
} cas_key_input;

/*!
	@brief Write the current keyboard buffer into the passed input struct. Returns 1 if any buttons are pressed, else 0. Please note that this function sometimes does not register quick button releases.
	@param input The input struct where the information should be written to
	@return 1 if any buttons are pressed, else 0
 */
uint8_t input_get_keys(cas_key_input* input);

#endif