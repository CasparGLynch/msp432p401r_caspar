/*
 * delay.cpp
 *
 *  Created on: Mar 24, 2023
 *      Author: marco
 */

#include "delay.h"
#include "DelfiPQcore.h"

uint32_t time_ms = 0;

void SysTick_Handler(void)
{
    time_ms++;
}

void delay_init() {
    /* Enable SysTick timer for delays. */
    constexpr uint32_t period = FCLOCK / 1000; // Assume clock speed in MHz
    static_assert(period >> 24 == 0, "SysTick accepts counter up to 24 bits.");
    MAP_SysTick_enableModule();
    MAP_SysTick_setPeriod(period); //Depends on your clock and tick requirements
    MAP_SysTick_registerInterrupt(&SysTick_Handler);
    MAP_SysTick_enableInterrupt();
    MAP_Interrupt_enableMaster();
}

void delay_ms(uint32_t ms) {
    uint32_t time_ms_start = time_ms;

    while (time_ms - time_ms_start < ms) {}
}



