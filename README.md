# CAS-SDK
CAS-SDK is an open source SDK to write applications for the Casio Classpad II (fx-CP400). It currently supports the calculators firmware version 02.01.7000.0000.

## Features
The SDK's current featureset consist of:
- Basic file system access (writing, deleting and reading files)
- Display manipulation (reading and writing to VRAM and modifying the display state)
- Reading keyboard input
- Reading touch input (experimental)
- Access to the CPU's RTC-registers
- Basic debugging print functions

It also includes a python script to prepare sh4-binaries for the HolzMod CFW. 

In the example-app/ directory you can find all the necessary files and their contents to create an app with this SDK.

## Installation
### Requirements
You will need to build gcc, binutils, and newlib for the sh target yourself. An indepth tutorial will follow soon. I also recommend using this SDK on Linux since it was not tested in a Windows environment. 

### SDK
To install the sdk, clone this repoand and run make.
```
git clone https://github.com/diddyholz/CAS-SDK
cd CAS-SDK
make 
```
After that define the "CAS_SDK" variable, pointing to the just created cas-sdk.o, in your shell.

You can now use CAS-SDK in your projects.

To get code completion for the SDK in your editor, add the cas-sdk/include/ directory to your include paths.

## Notes
To install apps that you created with this SDK, your calculator needs to run the HolzMod CFW. This CFW is currently not publicy available but I will soon finish it and upload installation instructions to my GitHub.

Huge thanks goes to [@the6p4c](https://github.com/the6p4c), without his tutorials on reverse engineering the Classpad II, I would not have known how to develop this project.