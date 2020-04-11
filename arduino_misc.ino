#include <arduino.h>


// be quick in here, since you're running inside an ISR
// this function is called approximately once every millisecond
void onTick()
{
  // empty
}


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


void onEncoderButton( const bool buttonDown )
{
  if ( buttonDown ) {
    Serial.println( "Button down" ); 
  }
  else {
    Serial.println( "Button up" );
  }
}


void onEncoderButtonDown()
{
  Serial.println( "Button down" );
}


void setup() {
  Serial.begin( 9600 );
  Serial.println( "Example ISR-based rotary encoder demo for Arduino" );
}


void loop() {
  while ( true )
    ;
}
