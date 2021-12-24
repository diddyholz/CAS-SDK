#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <stdint.h>

/// @brief Open the file read only
#define OPEN_READ   0x01
/// @brief Open the file with read and write access
#define OPEN_WRITE  0x02
/// @brief Create the file if it does not exist
#define OPEN_CREATE 0x04
/// @brief Open the file with the write offset set to the end of the file
#define OPEN_APPEND 0x08

/*!
	@brief Mounts the volume specified in the paramter
	@param volume The volume to be mounted. Pass 0 to default mount fls0.
	@return Negative integer if an error occured, else the volume handle
*/
extern int32_t (*fs_mount)(const char* volume);

/*!
	@brief Unmounts the volume by the volumehandle specified in the paramter. Please note that this function has not been tested and it might not work as expected.
	@param volume_handle The volume_handle of the volume to be umounted. This is the return value you get from mounting a volume.
	@return Negative integer if an error occured
*/
extern int32_t (*fs_unmount)(int32_t volume_handle);

/*!
	@brief Opens a file and optains its file handle.
	@param path The path to the file to be opened. Use /fls0/ as root dir (e.g. /fls0/path/to/file).
	@param mode The mode in which the file should be opened. See OPEN_ definitions for all modes. Multiple modes can be selected by doing a bitwise or of them.
	@return Negative integer if an error occured, else the file handle
*/
extern int32_t (*fs_file_open)(const char* path, uint8_t mode);

/*!
	@brief Closes a file by its file handle.
	@param file_handle The file handle of the file to be closed
	@return Negative integer if an error occured
*/
extern int32_t (*fs_file_close)(int32_t file_handle);

/*!
	@brief Deletes a file
	@param file_handle The file handle of the file to be deleted
	@return Negative integer if an error occured
*/
extern int32_t (*fs_file_delete)(int32_t file_handle);

/*!
	@brief Reads the content of a file into a buffer
	@param file_handle The file handle of the file to be read
	@param buffer A pointer to a buffer, where the file contents should be read to. Make sure it is of enough size. 
	@param n The amount of bytes to be read from the file content. Make sure it is not bigger than the buffer.
	@return Negative integer if an error occured
*/
extern int32_t (*fs_file_read)(int32_t file_handle, uint8_t* buffer, uint32_t n);

/*!
	@brief Writes the content of a buffer into a file. After writing, reopen the file to read its contents or else you will recieve an end of file error. 
	@param file_handle The file handle of the file to be written to
	@param buffer A pointer to a buffer of which contents should be written into the file
	@param n The amount of bytes to be written into the file. Make sure it is not bigger than the buffer.
	@return Negative integer if an error occured
*/
extern int32_t (*fs_file_write)(int32_t file_handle, uint8_t* buffer, uint32_t n);

/*!
	@brief Make a directory
	@param path The path to the directory that should be created. Do not end it with a slash! Use /fls0/ as root dir (e.g. /fls0/path/to/dir).
	@return Negative integer if an error occured
*/
extern int32_t (*fs_make_dir)(const char* path);

/*!
	@brief An internal function to print error messages. Use this to get more info on your error code.
	@param error The error code that you recieved from a file system function
*/
extern void (*fs_error_message)(int32_t error);

/*! 
	@brief A function that prepares file system access. Needs to be called at least once before trying to open/modify files.
*/
void fs_init();

/*
	A note on reading and writing to files:
	before you can open a file for the first time you will have to call file_init().
	This will prepare the device for file system access.

	When you write to a file you will have to reopen it to be able to read changes of the file. Else you will get an EOF error.
*/

#endif