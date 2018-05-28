MPS2+ SSE-200 Secure/Non-secure Blinky Example
This example swicthes ON and OFF the MPS2 SCC LEDs based on the MPS2 user button pressed.

The implementation is divided in secure and non-secure code.

The secure code performs the follow functionality:

Sets secure and non-secure system configuration.
Gets and provides button states.
Sleep function.
Switchs on/off user LEDs based on user button states.
The non-secure code performs the follow functionality:

Requests to the secure code:
Button states.
Sleep for X amount of ms.
Switchs on/off the SCC LEDs based on:
if User button 0 is pressed, the SCC LEDs blink state is enabled.
If User button 1 is pressed, the SCC LEDs blink state is disabled.
To compile the example correctly it is necessary to first compile the secure code, and then the non-secure code.
Compiling the secure code generates the veneers object file required by the non-secure code to compile correctly.

See the ReadMe file provided with the example for further information.
https://community.arm.com/dev-platforms/w/docs/353/mps2-sse-200-secure-non-secure-blinky-example