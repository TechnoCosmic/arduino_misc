#include <avr/interrupt.h>


void __attribute__((constructor)) initTicks()
{
  // copy compare register A, since in Arduino world, this
  // is already set up for one millisecond
  OCR0B = OCR0A;

  // activate compare B ISR
  TIMSK0 |= ( 1 << OCIE0B );
}


// default (empty) handler

/// @brief Allows simple scheduled events on a timer
/// @details This function is called approximately every one (1) millisecond. Be quick here, as
/// code inside this handler is running inside an ISR and other interrupts are disabled during
/// this time.
void __attribute__((weak)) onTick()
{
  // empty
}


// ISR which calls the handler
ISR( TIMER0_COMPB_vect )
{
  onTick();
}
