#include <Arduino.h>
/********************************
 * Libraries included
 *******************************/
#include <Ethernet.h>
#include <SPI.h>
#include <UbidotsEthernet.h>

/********************************
 * Constants and objects
 *******************************/
/* Assigns the Ubidots parameters */
char const * TOKEN = "BBFF-DZKKbJ247xVNIVm1xexbf0FtPneoWk"; // Assign your Ubidots TOKEN
char const * VARIABLE_LABEL = "switch"; // Assign the unique variable label to get the last value

/* Enter a MAC address for your controller below */
/* Newer Ethernet shields have a MAC address printed on a sticker on the shield */
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

/* initialize the instance */
Ubidots client(TOKEN);

/********************************
 * Main Functions
 *******************************/
void setup() {
  Serial.begin(9600);
  //client.setDebug(true);// uncomment this line to visualize the debug message
  /* start the Ethernet connection */
  Serial.print(F("Starting ethernet..."));
  if (!Ethernet.begin(mac)) {
    Serial.println(F("failed"));
  } else {
    Serial.println(Ethernet.localIP());
  }
  /* Give the Ethernet shield a second to initialize */
  delay(2000);
  Serial.println(F("Ready"));
}

void loop() {
  Ethernet.maintain();
  /* Getting the last value from a variable */
  float value = client.getValue(DEVICE_LABEL, VARIABLE_LABEL);
  /* Print the value obtained */
  Serial.print("the value received is:  ");
  Serial.println(value);
  delay(5000);
}