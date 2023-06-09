//
// Created by caspar on 6/9/23.
//

#ifndef EPS_CONVERSION_EPS_H
#define EPS_CONVERSION_EPS_H

// TODO: put correct addr here
#define EPS_I2C_ADDR 0x00
#define RESET_WATCHDOG_COMMAND_CODE 0x06

#include "DWire.h"
#include "delay.h"

class EPS {
public:
    // standard reply
    struct standard_reply {
        uint8_t stid;
        uint8_t ivid;
        uint8_t rc;
        uint8_t bid;
        uint8_t stat;
        uint8_t error;
    };

    static standard_reply reset_watchdog(DWire &wire, uint8_t i2c_address);
};

#endif //EPS_CONVERSION_EPS_H
