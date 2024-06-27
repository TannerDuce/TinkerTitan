Tinker Titan V1

Here we will give some basic instructions on how to set up your Tinker Titan, Start to Finish.

**1. Board Assembly:**

Start by soldering the provided connectors onto the main PCB. note that the 2x3 connector in the center of the board is 
intentionally left blank, as it is the ISP header used to burn the first files onto the Atmel chip. <-(more on this later)
![20240626_102552](https://github.com/TannerDuce/TinkerTitan/assets/61127003/c68d15bf-b02a-4e29-8628-ab555e4a7f66)

Next, we solder the motor wires onto the end of the motor. each wire should measure approximately 5.5" long. The wires 
can be cut as short as 5", but a little extra is always good. additionally, tin the opposite ends of the wires. this will 
make it easier to get them into the terminal blocks.
![motorwirelength](https://github.com/TannerDuce/TinkerTitan/assets/61127003/3d57fd9c-44f9-4f92-ae4d-bc507cac8bd8)

Next, we will fit the motors into the main chassis. Note that there is a tab on the chassis where the motor lies, which
helps to hold it in place. if the motor is set in upside-down, it simply will not fit in all the way and will need 
to be flipped around. Once the motors are in place, use #4 hardware to secure them, as shown below. Once they are in
place, the cables must be routed along the central channel to provide space for the battery on top.
![motorinstalation](https://github.com/TannerDuce/TinkerTitan/assets/61127003/9b5915ff-f439-4c83-a20a-7c805890244a)

Next up is the battery. once you have assembled the battery pack, insert it into the chassis as shown. make sure the
switch on the battery pack is turned on, as it will no longer be accessible. instead of using the switch, the Tinker 
Titan was designed to just be unplugged to power it off.
![batterypackinstalation](https://github.com/TannerDuce/TinkerTitan/assets/61127003/adec8362-32b6-4438-832e-a69915c935fc)

Once the battery pack is in place, install the cover plate. use #4 hardware to secure it to the chassis.
![20240626_125109(0)](https://github.com/TannerDuce/TinkerTitan/assets/61127003/3066567d-598c-494b-9b17-ea1135bffe87)

Using the machined stand-offs, mount the circuit board to the top of the cover plate as shown below:
![20240626_130304](https://github.com/TannerDuce/TinkerTitan/assets/61127003/f8545e36-ff75-4e34-94ea-fbf4fac89622)

Next, wire up your motors into the terminal blocks at the bottom. Don't worry about polarity yet, as long as the 2 wires
from the left motor go to the left terminal block, and the same for the right. (we will correct this later) Try plugging
it in to ensure the battery pack is on. The green light should stay on, solid.
![20240626_130730](https://github.com/TannerDuce/TinkerTitan/assets/61127003/cd1142f2-f58e-4344-9a3e-cbdbb3213812)

