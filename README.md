# R3-SoftwareTraining-JohnCabuguason
Arduino code and Tinkercad Diagrams detailing the creation of simple two motor vehicle robot


TinkerCAD Project Link: https://www.tinkercad.com/things/eM7HPvrz6u1



Following the lab manual I..
- Implemented differential steering with one motor on each side of the robot
- Took potentiometer input into an analog pin in the arduino which then determines the value of the pwm instructed to the two motors controlled by the L293D controller
- I write output from the arduino to the motor controller in order to control the value of the motors 
- The dip switches are connected to arduino digital input pins that read High or Low and determines what mode the motors should be 
- The dip switches are connected to the arduino 5v source 

- Dip Switch 1 = Forward
- Dip Switch 2 = Backward
- Dip Switch 3 = Turning Left
- Dip Switch 4 = Turning Right
- Turning off all dip switches sets all motors off.

In addition..
- In order for the dip switches to work properly I put resistors connecting to ground where each switch branch is so that when turned off, the dip switch would not have a floating voltage that would be read into the arduino.

Some future notes..

- Although the motorPWM is constant and does not vary unless changed by the potentiometer, the RPM value of both motors vary always from around +/- 8, I've thought of adding a capacitor but have not actually tried to implement his. Looking online, the capacitor may be a viable solution.
