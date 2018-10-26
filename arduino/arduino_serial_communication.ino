#include <SoftwareSerial.h>

// Connecting both the HC-05 (bluetooth module) and the HC-12 (wireless transceiver) will require an arduino with atleast 4 serial ports (Arduino Mega and better)

SoftwareSerial HC12(12, 13); // HC-12 TX Pin, HC-12 RX Pin
SoftwareSerial HC05(63, 64); // HC-05 TX Pin, HC-12 RX Pin


void setup()
{
    HC05.begin(9600);
    HC12.begin(9600);
}

void loop()
{
    // When a character arrives on the serial port this will be true
    if (HC05.available()) 
    {
        // wait a bit for the entire message to arrive
        delay(100);

        while (HC05.available()) 
        {      
            // If Serial monitor has data
            HC12.write(HC05.read());      // Send that data to HC-12
        }
    }
}