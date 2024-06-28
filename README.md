Tinker Titan V1

Here we will give some basic instructions on how to set up your Tinker Titan, Start to Finish.

**1. Board Assembly:**

Start by soldering the provided connectors onto the main PCB. note that the 2x3 connector in the center of the board is 
intentionally left blank, as it is the ISP header used to burn the first files onto the Atmel chip. <-(more on this later)
![20240626_102552](https://github.com/TannerDuce/TinkerTitan/assets/61127003/7baaa9eb-f2da-477c-9ff0-047269d639a3)


Next, we solder the motor wires onto the end of the motor. each wire should measure approximately 5.5" long. The wires 
can be cut as short as 5", but a little extra is always good. additionally, tin the opposite ends of the wires. this will 
make it easier to get them into the terminal blocks.
![motorwirelength](https://github.com/TannerDuce/TinkerTitan/assets/61127003/a265dc03-b485-402d-8ab7-500ab0ef1e77)


Next, we will fit the motors into the main chassis. Note that there is a tab on the chassis where the motor lies, which
helps to hold it in place. if the motor is set in upside-down, it simply will not fit in all the way and will need 
to be flipped around. Once the motors are in place, use #4 hardware to secure them, as shown below. Once they are in
place, the cables must be routed along the central channel to provide space for the battery on top.
![motorinstalation](https://github.com/TannerDuce/TinkerTitan/assets/61127003/68c9e55d-84d1-4e0d-beac-ef2364e66345)


Next up is the battery. once you have assembled the battery pack, insert it into the chassis as shown. make sure the
switch on the battery pack is turned on, as it will no longer be accessible. instead of using the switch, the Tinker 
Titan was designed to just be unplugged to power it off.
![motorinstalation](https://github.com/TannerDuce/TinkerTitan/assets/61127003/b9dbe232-90a1-48c8-b10e-a012893d4384)


Once the battery pack is in place, install the cover plate. use #4 hardware to secure it to the chassis.
![20240626_125109(0)](https://github.com/TannerDuce/TinkerTitan/assets/61127003/c33d2807-d651-41cc-bddc-d550bed1fcb0)


Using the machined stand-offs, mount the circuit board to the top of the cover plate as shown below:
![20240626_130304](https://github.com/TannerDuce/TinkerTitan/assets/61127003/08139dfc-8e29-43fe-bb7d-3083b8fa397e)


Next, wire up your motors into the terminal blocks at the bottom. Don't worry about polarity yet, as long as the 2 wires
from the left motor go to the left terminal block, and the same for the right. (we will correct this later) Try plugging
it in to ensure the battery pack is on. The green light should stay on, solid.
![20240626_130730](https://github.com/TannerDuce/TinkerTitan/assets/61127003/e0a387bf-c246-4b65-8cac-20e94e794f5a)


Next, we will assemble the tracks. using the hardware from the back the tracks come in, place the nut in the front slot.
take the short bolt and after placing the wheel on the bolt, add a washer and fasten it to the chassis. for the driven
wheel, find the wheel with the keyed D shaft, and fit it onto the motor. once both are in place, stretch the track over
the two sprockets. do this for both sides of the robot:
![20240626_160846](https://github.com/TannerDuce/TinkerTitan/assets/61127003/c4f9eed8-3f56-45e2-b058-bbcbae5e27fb)

Now that the base model is complete, we will add the sensor assembly. this gives the robot the ability to compete in the
sumo challenge, as well as do things such as line following. start by clipping the Ultrasonic sensor into the piece with
the dovetail on it. for this step, make sure that the connector on the ultrasonic sensor faces the opposite way of the 
opening on the dovetail connector. once it is in place, slide the line following module into the remaining piece, and fit
it over the "eyes" of the ultrasonic sensor. 
![20240627_135216](https://github.com/TannerDuce/TinkerTitan/assets/61127003/4a3e1011-6aa9-496b-b101-34f63622f989)

Once this module is assembled, slide it into the dovetail on the chassis. for wiring, we use IR#2 for the line sensor,
and the header labelled HC-SR04 for the ultrasonic sensor. As for the line sensor, the pins on the module connect to the 
following pins on the board. OUT --> A6, GND --> GND, and VCC --> 5V. for the Ultrasonic, All the names of the pins match
exept for power, which on the module is labled VCC and on the board is noted as 5V




