Tinker Titan V1

Here we will give some basic instructions on how to set up your Tinker Titan, Start to Finish.

**1. Board Assembly:**

Start by soldering the provided connectors onto the main PCB. Depending on how your doing this program, you may also have to
install the surface mount parts yourself, or all of the components will come pre-installed on the circuit board.note that the
2x3 connector in the center of the board is intentionally left blank, as it is the ISP header used to burn the first files
onto the Atmel chip. <-(more on this later)                               .
![20240626_102552](https://github.com/TannerDuce/TinkerTitan/assets/61127003/7baaa9eb-f2da-477c-9ff0-047269d639a3)



Next, we solder the motor wires onto the end of the motor. each wire should measure approximately 5.5" long. The wires 
can be cut as short as 5", but a little extra is always good. additionally, tin the opposite ends of the wires. this will 
make it easier to get them into the terminal blocks.
![motorwirelength](https://github.com/TannerDuce/TinkerTitan/assets/61127003/a265dc03-b485-402d-8ab7-500ab0ef1e77)



Next, we will fit the motors into the main chassis. Note that there is a tab on the chassis where the motor lies, which
helps to hold it in place. if the motor is set in upside-down, it simply will not fit in all the way and will need 
to be flipped around. Once the motors are in place, use #4 hardware to secure them, as shown below. Once they are in
place, the cables must be routed along the central channel to provide space for the battery to be set in place on top of them

![motorinstalation](https://github.com/TannerDuce/TinkerTitan/assets/61127003/68c9e55d-84d1-4e0d-beac-ef2364e66345)



Next up is the battery. once you have assembled the battery pack, insert it into the chassis as shown. make sure the
switch on the battery pack is turned on, as it will no longer be accessible. instead of using the switch, the Tinker 
Titan was designed just to be unplugged to power it off.
![batterypackinstalation](https://github.com/TannerDuce/TinkerTitan/assets/61127003/87228cf1-47d4-4f7b-b382-aebde7c4e3ec)



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
sumo challenge and do things such as line following. start by clipping the Ultrasonic sensor into the piece with
the dovetail on it. for this step, make sure that the connector on the ultrasonic sensor faces the opposite way of the 
opening on the dovetail connector. once it is in place, slide the line following module into the remaining piece, and fit
it over the "eyes" of the ultrasonic sensor. 
![20240627_135216](https://github.com/TannerDuce/TinkerTitan/assets/61127003/4a3e1011-6aa9-496b-b101-34f63622f989)



Once this module is assembled, slide it into the dovetail on the chassis. we use IR#2 for wiring for the line sensor
and the header labelled HC-SR04 for the ultrasonic sensor. As for the line sensor, the pins on the module connect to the 
following pins on the board. OUT --> A6, GND --> GND, and VCC --> 5V. For the Ultrasonic, all the pins' names match
except for power, which on the module is labelled VCC and on the board is noted as 5V. 

![20240701_151121](https://github.com/TannerDuce/TinkerTitan/assets/61127003/7ba3bce0-0d17-40aa-8b23-e0155c97e658)




**2. Setup Programming:**
You have now completed the hardware assembly, and it is time to move on to the programming! with a fresh board out of the box, 
it will not have a bootloader programmed into it, which is a specific piece of startup code that must be on the chip in order
to be programmed through the USB interface. If you are doing this in class, this section will be completed with the help of the
instructor, but it still doesn't hurt to know what's happening! afterwards, we will continue with ensuring everything else works.


Start by installing the application AVRDUDESS here-> https://github.com/ZakKemble/AVRDUDESS/releases/tag/v2.17 
this application is used to burn the bootloader, which is a term used for adding some code directly onto the microcontroller 
that tells it how to receive code from the USB port. once the application is open, we will set the -b bit clock divider to 16,
(Green box) and then click the detect button (orange box). if done correctly, the board should be recognized and will be confirmed
in the terminal.
![Step1program](https://github.com/TannerDuce/TinkerTitan/assets/61127003/4777b202-1389-4595-a51f-b5f71e2d5b7c)



Second, we will program the fuse bits. note we only want to edit the fuse bit, NOT the lock bit. Copy the values shown in the
picture for the bits shown in the blue box, then the hit Program (red arrow)
![Step2program](https://github.com/TannerDuce/TinkerTitan/assets/61127003/a49e99dd-13fa-436a-914e-c02ff66467ac)



Finally, we can add in the hex file, and program the boot loader which will be the last step required to be able to use the USB
port for programming. start by downloading the hex file labelled as the hex file for burning the bootloader (in this GitHub repository).
Once it's been loaded in,(orange) select "Write" and then "GO". you have now successfully programmeed the bootloader!
![Step3program](https://github.com/TannerDuce/TinkerTitan/assets/61127003/331de693-2a4d-4cc7-82db-e373097f42ed)




**3. Uploading your first program**
here, we will make sure both motors are wired in the correct way, as well as verify that the Line sensor and Ultrasonic work.
Using the Arduino IDE, open the Initializer code, and try uploading it. ensure you have the correct COM port, and that the board
selected is and Arduino UNO. keep it connected to the computer, and open the terminal in the IDE. Once the correct BAUD rate is
selected (9600) you should see a walk-through of what the code will do. if you notice either of the motors are backward, switch
the two wires associated with it around in the terminal block it is connected to. if one motor appears to be stronger than the
other, adjust its weight_value, which is simply a number that the final speed is multiplied by. To set up the line sensor, wave
it over a dar and light patch on paper. if the program cannot tell the difference, try adjusting the potentiometer on the line
sensor. If the line sensor or ultrasonic appear to not be working, ensure all the wires are in the correct spot.

Once it all works, you can go ahead and upload some of the other code provided onto the robot, or try writing some of your own!

And please, by all means if you encounter a problem, go to the issues tab on this github page and report an issue! I will do my best to respond accordingly.
