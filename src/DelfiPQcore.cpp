/*
 * DelfiPQcore.cpp
 *
 *  Created on: 26 Aug 2019
 *      Author: stefanosperett
 */

#include "DelfiPQcore.h"

/**
 *
 *   Initialize the clock system: high frequency crystal is the
 *   first selection and, in case of fault fall back to the DCO.
 *
 *   Parameters:
 *   Returns:
 *
 */
void DelfiPQcore::initMCU( void )
{
    // Configuring pins for HF XTAL
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ,
            GPIO_PIN3 | GPIO_PIN2, GPIO_PRIMARY_MODULE_FUNCTION);

    // Starting HFXT in non-bypass mode with a timeout. Before we start
    // we have to change VCORE to 1 to support the 48MHz frequency
    MAP_CS_setExternalClockSourceFrequency(SCLOCK, FCLOCK);

    MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);
    MAP_FlashCtl_setWaitState(FLASH_BANK0, 2);
    MAP_FlashCtl_setWaitState(FLASH_BANK1, 2);

    uint32_t clock;
    if( CS_startHFXTWithTimeout(false, 100000) )
    {
        // HF XTAL successfully started
        clock = CS_HFXTCLK_SELECT;
    }
    else
    {
        // HF XTAL not working, fall back onto DCO
        MAP_CS_setExternalClockSourceFrequency(0, 0);

        // set new clock source
        clock = CS_DCOCLK_SELECT;

        // disable clock pins
        MAP_GPIO_setAsInputPin( GPIO_PORT_PJ, GPIO_PIN3 | GPIO_PIN2 );

        //Setting the DCO Frequency
        MAP_CS_setDCOFrequency(FCLOCK);
    }

    // Configure clocks that we need
    MAP_CS_initClockSignal(CS_MCLK, clock, CS_CLOCK_DIVIDER_1);
    MAP_CS_initClockSignal(CS_SMCLK, clock, CS_CLOCK_DIVIDER_4);
    MAP_CS_initClockSignal(CS_HSMCLK, clock, CS_CLOCK_DIVIDER_2);
}

/**
 *
 *   Get the status of the High Frequency oscillator
 *
 *   Parameters:
 *   Returns:
 *   bool                  true   working
 *                         false  not working
 *
 */
bool DelfiPQcore::getHFOscillatorStatus( void )
{
    return (MAP_CS_getInterruptStatus() & CS_HFXT_FAULT) == 0;
}

/**
 *
 *   Get the status of the Low Frequency oscillator
 *
 *   Parameters:
 *   Returns:
 *   bool                  true   working
 *                         false  not working
 *
 */
bool DelfiPQcore::getLFOscillatorStatus( void )
{
    return (MAP_CS_getInterruptStatus() & CS_LFXT_FAULT) == 0;
}
