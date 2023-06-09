/*
 * eps.cpp
 *
 *  Created on: Mar 24, 2023
 *      Author: marco
 */

#include <eps_test.h>

EPS::watchdog_reply EPS::reset_watchdog(DWire &wire, uint8_t i2c_address) {
    watchdog_reply reply;

    /* Write command to EPS. */
    wire.beginTransmission(i2c_address);
    wire.write(0x00);
    wire.write(0x06);
    wire.write(0x06);
    wire.write(0x00);

    /* Wait for EPS to process command. */
    delay_ms(30);

    /* Read data from EPS. */
    uint8_t res = wire.requestFrom(i2c_address, 5);

    /* Construct reply if data arrived. */
    if (res == 5)
    {
        reply.stid = wire.read();
        reply.ivid = wire.read();
        reply.rc = wire.read();
        reply.bid = wire.read();
        reply.stat = wire.read();
        reply.error = false;
    }
    /* Signal error if data did not arrive. */
    else
    {
        reply.error = true;
    }

    return reply;
}
