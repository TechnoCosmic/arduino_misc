#include <arduino.h>


/// @brief Be quick in here, since you're running inside an ISR
/// @details This function is called approximately once every millisecond.
void onTick()
{
  // empty
}


/// @brief This is called when the rotary encoder is turned.
/// @param direction -1 when turned counter clockwise, 1 when turned clockwise.
/// @param buttonDown true if the rotary encoder button is down, false otherwise.
void onEncoderRotate( const int direction, const bool buttonDown )
{
  if ( direction == -1 ) {
    Serial.print( "Counter clockwise, " );
  }
  else {
    Serial.print( "Clockwise, " );
  }

  if ( buttonDown ) {
    Serial.print( "down" );
  }
  else {
    Serial.print( "up" );
  }

  Serial.println();
}


/// @brief Called when the rotary encoder button is pressed or released
/// @param buttonDown true if the button was pressed, false if it was released.
void onEncoderButton( const bool buttonDown )
{
  if ( buttonDown ) {
    Serial.println( "Button down" ); 
  }
  else {
    Serial.println( "Button up" );
  }
}


void setup() {
  Serial.begin( 9600 );
  Serial.println( "Example ISR-based rotary encoder demo for Arduino" );
}


void loop() {
  while ( true )
    ;
}
