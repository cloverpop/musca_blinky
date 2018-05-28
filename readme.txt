Musca-A1 Secure/Non-secure Blinky example
This example switches the Musca LEDs ON and OFF with a hard coded interval.

The implementation is divided into secure and non-secure code projects. You need to set a project as the "Active Project" in order to compile it, load it, or view it's settings.

The secure code performs the follow functionality:

Sets secure and non-secure system configuration.
Handles time management
Initilizes GPIO pins for the LEDs
Switches user LEDs on/off
The non-secure code performs the follow functionality:

If there is only one LED
Asks the secure code to switch LED state
Maintains LED state based on the return value from the secure code
If there are many LEDs
Maintains the state of the LED that has changed the last time based on the return value from the secure code
Asks the secure code to switch state of the next LED
All the target options necessary for compiling, loading and debugging this example are already set in the project for you.  These can be viewed by clicking on the "Options for Target" button for both projects. 

To compile this example correctly the secure code needs to be compiled first and then the non-secure. Each projects image can be loaded onto the board by clicking the Load icon. It does not matter which image is loaded first.
https://community.arm.com/dev-platforms/w/docs/321/musca-a1-secure-non-secure-blinky-example
