## Available Functions and Control Systems

In the provided sample code, you have access to several functions and libraries that will help you implement your control system. While we highlight some key functions below, it's important to note that there are many more functions available in the library documentation. We strongly encourage you to refer to the official documentation for a comprehensive list of functions and their detailed usage.

### Available Functions

Note: This is just a small selection of commonly used functions. For a complete list and detailed explanations, please refer to the official documentation of the QTRSensors and L298N libraries.

1. **Motor Control Functions:**

   - `motorA.setSpeed(speed)` and `motorB.setSpeed(speed)`: Set the speed of motors A and B (0-255).
   - `motorA.forward()` and `motorB.forward()`: Set motors to move forward.
   - `motorA.backward()` and `motorB.backward()`: Set motors to move backward.
   - `motorA.stop()` and `motorB.stop()`: Stop the motors.

2. **Sensor Reading Functions:**

   - `qtr.readLineBlack(sensorValues)`: Read the position of a black line on a white surface.
   - `qtr.read(sensorValues)`: Read raw sensor values.
   - `qtr.readCalibrated(sensorValues)`: Read calibrated sensor values.

3. **Utility Functions:**
   - `constrain(value, min, max)`: Constrain a value between a minimum and maximum.
   - `map(value, fromLow, fromHigh, toLow, toHigh)`: Map a value from one range to another.

For a complete list of functions and their detailed usage, please refer to:

- [QTRSensors Library Documentation](https://github.com/pololu/qtr-sensors-arduino)
- [L298N Library Documentation](https://github.com/AndreaLombardo/L298N)

These libraries offer many more functions that can be useful for advanced control and fine-tuning of your robot's behavior.

### Control Systems to Consider

1. **Bang-Bang Control:**

   - Simplest form of control.
   - Robot turns left or right based on whether it's to the left or right of the line.

2. **Proportional Control (P):**

   - Adjusts motor speeds proportionally to the error (distance from the line center).
   - Smoother than Bang-Bang but may oscillate.

3. **Proportional-Integral Control (PI):**

   - Adds an integral term to reduce steady-state error.
   - Can help eliminate consistent offsets from the line.

4. **Proportional-Integral-Derivative Control (PID):**

   - Most comprehensive control system.
   - Adds a derivative term to predict and dampen oscillations.
   - Typically provides the smoothest and most accurate line following.

5. **Fuzzy Logic Control:**
   - Uses fuzzy set theory to make decisions.
   - Can be more intuitive to design and often works well for non-linear systems.

## References

1. PID Control:

   - [PID Control with Arduino](https://www.teachmemicro.com/arduino-pid-control-tutorial/)

2. Fuzzy Logic Control:
   - [Fuzzy Logic Tutorial](https://www.youtube.com/watch?v=LmIUXV7N45E)
   - [Fuzzy Logic Control System](https://www.sciencedirect.com/topics/engineering/fuzzy-logic-control-system)

We encourage you to explore these control systems and choose the one that best suits your needs. Remember, the key to success is not just implementing a control system, but also fine-tuning its parameters for optimal performance on the competition track.
