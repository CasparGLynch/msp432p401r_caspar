/*
 * eps.h
 *
 *  Created on: Mar 24, 2023
 *      Author: marco
 */

#ifndef EPS_TEST_H_
#define EPS_TEST_H_

#include "DWire.h"
#include "delay.h"

class EPS {
public:

    struct watchdog_reply {
        uint8_t stid;
        uint8_t ivid;
        uint8_t rc;
        uint8_t bid;
        uint8_t stat;
        uint8_t error;
    };

    static watchdog_reply reset_watchdog(DWire &wire, uint8_t i2c_address);
};



#endif /* EPS_TEST_H_ */
