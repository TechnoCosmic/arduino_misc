// To use this encoder sample, just be sure this file is compiled into your project,
// then use the onEncoderXXX() functions as shown in the main sketch.

// NO WARRANTY - PLEASE BE SURE CODE IS FIT FOR PURPOSE BEFORE USE

#include <arduino.h>
#include <avr/interrupt.h>


// _BTN and _CLK should be on D2 and D3 unless you want
// to hand-code the PCINTs for the other interrupts that
// attachInterrupt() doesn't support
#define PIN_ENCODER_BTN 2
#define PIN_ENCODER_CLK 3
#define PIN_ENCODER_DIR 4


// default (empty) handlers
void __attribute__((weak)) onEncoderRotate( const int direction, const bool buttonDown )
{
  // empty
}


void __attribute__((weak)) onEncoderButton( const bool buttonDown )
{
  // empty
}


namespace {


  volatile bool _lastEncoderClockState{ true };
  volatile bool _lastEncoderButtonState{ true };


  // Encoder rotate ISR
  void handleEncoderRotate()
  {
    const auto curEncoderClockState{ digitalRead( PIN_ENCODER_CLK ) };
  
    if ( curEncoderClockState != _lastEncoderClockState ) {
      _lastEncoderClockState = curEncoderClockState;
  
      if ( digitalRead( PIN_ENCODER_CLK ) ) {
        auto dir{ 1 };

        if ( !!digitalRead( PIN_ENCODER_DIR ) ) {
          dir = -1;
        }  
          
        onEncoderRotate( dir, !!!digitalRead( PIN_ENCODER_BTN ) );
      }
    }
  }

  
  // Encoder push button ISR
  void handleEncoderPush()
  {
    const auto curEncoderButtonState{ digitalRead( PIN_ENCODER_BTN ) };
  
    if ( curEncoderButtonState != _lastEncoderButtonState ) {
      _lastEncoderButtonState = curEncoderButtonState;
  
      if ( digitalRead( PIN_ENCODER_BTN ) ) {
        onEncoderButton( false );  
      }
      else {
        onEncoderButton( true );
      }
    }
  }
  
  
  // ctor attribute means this function will run before main()
  void __attribute__((constructor)) encoderInit()
  {
    pinMode( PIN_ENCODER_CLK, INPUT_PULLUP );
    pinMode( PIN_ENCODER_DIR, INPUT_PULLUP );
    pinMode( PIN_ENCODER_BTN, INPUT_PULLUP );
  
    attachInterrupt( digitalPinToInterrupt( PIN_ENCODER_CLK ), handleEncoderRotate, CHANGE );
    attachInterrupt( digitalPinToInterrupt( PIN_ENCODER_BTN ), handleEncoderPush, CHANGE );
  }


}
