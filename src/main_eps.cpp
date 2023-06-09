//
// Created by caspar on 6/9/23.
//

#include <transmitter.h>
#include "msp.h"
#include "DWire.h"
#include "TMP100.h"
#include "Console.h"
#include "DelfiPQcore.h"
#include "delay.h"
#include "EPS.h"
#include "I2CScanner.h"

DWire I2cinternal(0);
void main(void) {

    // initialize the MCU:
    // - clock source
    // - clock tree
    DelfiPQcore::initMCU();

    delay_init();

    /* Init console with 9600 baud. */
    Console::init( 9600 );

    /* Delay. */
    delay_ms(1000);

    // Initialize I2C master
    I2Cinternal.setFastMode();
    I2Cinternal.begin();

    uint8_t num_of_devices_scanned = I2CScanner::scan(I2Cinternal, device_handler);
    EPS


}