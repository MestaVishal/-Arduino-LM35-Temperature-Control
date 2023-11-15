float sensorValue = 0;  // variable to store the value coming from the sensor

void ms_delay( int t )  // busy-wait delay function to generate approximate delay of t millisecond
{
  for( int i = 0 ; i < t ; i++ )
    for( int j = 0 ; j < 16000 ; j++ ) ;  // factoring that system clock frequency is 16MHz
}

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() 
{
  // read the value from the sensor:
  sensorValue = analogRead( A0 );
  
  /* 
    LM35 is a temperature sensor with a range of -55°C to +150°C, generating a voltage output (Vout) between 0V and 1.5V.
    A 10-bit ADC converts this analog voltage range to digital values, mapping 0V to 0 and 1.5V to 307.
    Therefore, the ADC output corresponds linearly, with 0V resulting in an ADC output of 0, and 1.5V resulting in an ADC output of 307.
  */
  sensorValue = sensorValue * 205 / 307 - 55 ;  //Convert to deg celcius
  
  if( sensorValue <= 30 )   // if temperature value is less than or equal to 30 deg C
  {
	  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  
    ms_delay( 250 );                      // wait for 250 second
  
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  
    ms_delay( 250 );   
  }
  
  else    // if temperature greater than to 30 deg C
  {
	  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  
    ms_delay( 500 );                      // wait for 500 second
  
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  
    ms_delay( 500 );   
  }

}