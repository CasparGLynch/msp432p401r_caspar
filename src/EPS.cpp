//
// Created by caspar on 6/9/23.
//
#include "EPS.h"

EPS::standard_reply EPS::reset_watchdog(DWire &wire, uint8_t i2c_address) {
    /* This command applies to all EPS address, i.e for PDU, PBU, PCU and PIU*/
    standard_reply reply;


    /* Write command to EPS */
    wire.beginTransmission(i2c_address);
    wire.write(0x00);
    wire.write(RESET_WATCHDOG_COMMAND_CODE);
    wire.write(0x06);
    wire.write(0x00);

    // delay
    delay_ms(25);

    // request 5 bytes of data (i.e) the length of the response
    uint8_t response = wire.requestFrom(i2c_address, 5);

    // if response if 5 bytes long populate reply struct else mark error
    if (response == 5) {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    } else {
        reply.error = true;
    }

    return reply;

}

EPS::standard_reply EPS::no_operation(DWire &wire, uint8_t i2c_address) {
    standard_reply reply;

}

