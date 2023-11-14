<!DOCTYPE html>

<body>

  <h1>LM35 Temperature Sensor Arduino Sketch</h1>

  <p>This Arduino sketch interfaces an LM35 temperature sensor with an Arduino Uno and controls the onboard LED based on temperature readings.</p>

  <h2>Description</h2>

  <p>The code reads the analog output from the LM35 temperature sensor, converts it to Celsius, and blinks the onboard LED based on the temperature condition.</p>

  <h2>Components</h2>

  <ul>
    <li>Arduino Uno</li>
    <li>LM35 Temperature Sensor</li>
    <li>Onboard LED (LED_BUILTIN)</li>
  </ul>

  <h2>Code Overview</h2>

  <ul>
    <li><strong>sensorValue:</strong> Variable to store the analog value from the LM35.</li>
    <li><strong>ms_delay(int t):</strong> A busy-wait delay function for an approximate delay of t milliseconds.</li>
    <li><strong>setup():</strong> Initializes the onboard LED pin as an output.</li>
    <li><strong>loop():</strong> Continuously reads the LM35, converts the value to temperature, and controls the LED based on temperature conditions.</li>
  </ul>

  <h2>Temperature Conversion</h2>

  <p>The LM35 has a temperature range of -55°C to +150°C, producing a corresponding voltage output (Vout) between 0V and 1.5V. The 10-bit ADC converts this analog range to digital values, mapping 0V to 0 and 1.5V to 307. The ADC output linearly corresponds, with 0V resulting in an ADC output of 0 and 1.5V resulting in an ADC output of 307.</p>

  <h2>LED Control</h2>

  <ul>
    <li>If the temperature is less than or equal to 30°C, the LED blinks every 250 milliseconds.</li>
    <li>If the temperature is greater than 30°C, the LED blinks every 500 milliseconds.</li>
  </ul>

  <h2>Note</h2>

  <p>This code avoids using the <code>Millis()</code>, <code>delay()</code>, and <code>micros()</code> functions.</p>

</body>

</html>
