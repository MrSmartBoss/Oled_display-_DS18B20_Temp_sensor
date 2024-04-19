#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is conntec to the Arduino digital pin 4
#define ONE_WIRE_BUS 4
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);



#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4 
Adafruit_SSD1306 display(OLED_RESET);


void setup(void)
{
// Start serial communication for debugging purposes
Serial.begin(9600);   	// initialize the Serial Monitor at a baud rate of 9600
// Start up the library
sensors.begin();      	// initialize the DS18B20 temperature sensor:

display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();

}

void loop(void){ 
// Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
sensors.requestTemperatures(); 
Serial.print("Celsius temperature: ");  
// Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
Serial.println(sensors.getTempCByIndex(0));   	// get and print the temperature in degree Celsius
delay(100);


display.clearDisplay();
//delay(100);
float T = sensors.getTempCByIndex(0);  // let T be temperature in degC from sensor
					// floating-point number, with a decimal point 
//delay(100);

display.setTextSize(1);
display.setTextColor(WHITE); 
display.setCursor(23,0);
delay(100);
display.println("MR SMART BOSS");   // Name

display.setTextSize(1);
display.setTextColor(WHITE); 
display.setCursor(5,9);
delay(100);
display.println("Temperature : ");   // display temperature in deg Celsius
delay(100);
display.setTextSize(2);
display.setCursor(15,19);
display.print(T);
display.print(" ");
display.cp437(true);    	// code page 437
display.write(167);     	// character 167 is degree
display.println("C");
display.display();		// for the changes to make effect
delay(1000);

}
