#include "cas-sdk/file-system.h"

#define FATMAKEDIR_SR_ADDRESS     (void*)0x80057834
#define FATMOUNTFS_SR_ADDRESS   	(void*)0x800574EE
#define FATUMOUNT_SR_ADDRESS    	(void*)0x800575D8  // untested
#define FATOPENFILE_SR_ADDRESS  	(void*)0x80057874
#define FATCLOSEFILE_SR_ADDRESS 	(void*)0x80057932
#define FATREADFILE_SR_ADDRESS  	(void*)0x800578C2
#define FATWRITEFILE_SR_ADDRESS 	(void*)0x800578FA 
#define FATUNLINKFILE_SR_ADDRESS	(void*)0x8005796E
#define FATMAGICFUNC1_SR_ADDRESS	(void*)0x80059334
#define FATMAGICFUNC2_SR_ADDRESS	(void*)0x800662E8
#define FUGUEGETERROR_SR_ADDRESS	(void*)0x80065A98

int32_t (*fs_mount)(const char* volume) = FATMOUNTFS_SR_ADDRESS;
int32_t (*fs_unmount)(int32_t volume_handle) = FATUMOUNT_SR_ADDRESS; 
int32_t (*fs_file_open)(const char* path, uint8_t mode) = FATOPENFILE_SR_ADDRESS; 
int32_t (*fs_file_close)(int32_t file_handle) = FATCLOSEFILE_SR_ADDRESS;
int32_t (*fs_file_delete)(int32_t file_handle) = FATUNLINKFILE_SR_ADDRESS;
int32_t (*fs_file_read)(int32_t file_handle, uint8_t* buffer, uint32_t n) = FATREADFILE_SR_ADDRESS;
int32_t (*fs_file_write)(int32_t file_handle, uint8_t* buffer, uint32_t n) = FATWRITEFILE_SR_ADDRESS; 
int32_t (*fs_make_dir)(const char* path) = FATMAKEDIR_SR_ADDRESS; 
void (*fs_error_message)(int32_t error) = FUGUEGETERROR_SR_ADDRESS;

// prepares file system access, needs to be called before you can open a file for the first time
void fs_init()
{
	char magicstring[10] = { 0, 'f', 0, 'l', 0, 's', 0, '0', 0, 0 };
	((void (*)(char*))FATMAGICFUNC1_SR_ADDRESS)(magicstring);
	((void (*)(void))FATMAGICFUNC2_SR_ADDRESS)();
}