# Application Template (MSP432P401R)
This repository can be used to start a new application project for the MSP432P401R MCU.
The project can be imported into and built with Code Composer Studio (CCS), or, alternatively, cloned using git and built using a GCC toolchain in a GNU/Linux environment.

# Using Code Composer Studio
## Prerequisites
* A github account with an SSH key set up.

## Setup
1. Download and install
    * [Code Composer Studio 12.3.0](https://www.ti.com/tool/download/CCSTUDIO)

## Importing
TODO

## Building
TODO

## Flashing
TODO

# Using GCC/GMake
## Prerequisites
* A github account with an SSH key set up.
* gmake
* git

## Setup
1. Download and install:
    * [GNU Arm Embedded Toolchain 7-2017-q4-major](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads/7-2017-q4-major-1-1)
    * [SimpleLink MSP432P4 SDK 3.40.01.02](https://www.ti.com/tool/download/SIMPLELINK-MSP432-SDK/3.40.01.02)

2. Open \<SimpleLink SDK install location>/imports.mak and modify the following:
    * Set `GCC_ARMCOMPILER` to point to your GNU Arm Embedded Toolchain folder location.
    * Comment out all other variable declarations, except for those under 'For Linux'
    * Set the `SIMPLELINK_MSP432_SDK_INSTALL_DIR` environment variable to point to your SimpleLink SDK location.

imports.mak example:
```Makefile
#XDC_INSTALL_DIR        ?= /home/username/xdctools_3_60_02_34_core
#SYSCONFIG_TOOL         ?= /home/username/ccs930/ccs/utils/sysconfig/sysconfig_cli.sh
#FREERTOS_INSTALL_DIR   ?= /home/username/FreeRTOSv10.1.1
#CCS_ARMCOMPILER        ?= /home/username/ti/ti-cgt-arm_18.12.4.LTS
GCC_ARMCOMPILER        ?= /home/username/gcc-arm-none-eabi-7-2017-q4-major

# For Linux
RM     = rm -f
RMDIR  = rm -rf
DEVNULL = /dev/null
ECHOBLANKLINE = echo
```

Environment variable decleration example:
```
export SIMPLELINK_MSP432_SDK_INSTALL_DIR=/home/username/simplelink_msp432p4_sdk_3_40_01_02
```


## Importing
1. Clone the repository

```
git clone git@github.com:davincisatellite/application-template-msp432p401r.git
```

## Building
1. Go into the 'gcc' folder in the project

```
cd application-template-msp432p401r
cd gcc
```
2. Run gmake

```
make
```

## Flashing
TODO

# Common problems and fixes

Problem: When `make`ing
```bash
Makefile:1: /imports.mak: No such file or directory
make: *** No rule to make target '/imports.mak'.  Stop.
```
Fix:
Set `SIMPLELINK_MSP432_SDK_INSTALL_DIR` environment variable