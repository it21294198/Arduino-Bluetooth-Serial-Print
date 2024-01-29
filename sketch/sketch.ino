#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 8); // RX, TX
const byte DATA_MAX_SIZE = 32;
char data[DATA_MAX_SIZE];

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    Serial.println("conneting..."); // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("connected");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Initial setup");
}

void loop()
{
  // run over and over
  if (mySerial.available())
  {
    String receivedString = mySerial.readStringUntil('\n'); // Read until newline character
    Serial.print("My Serial: ");
    Serial.println(receivedString);
  }
}
