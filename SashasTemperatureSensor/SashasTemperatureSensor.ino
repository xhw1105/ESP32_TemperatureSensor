#include <DHT.h>
#include <DHT_U.h>

/*
 Temperature Sensor
*/
#define DHTPIN 16
#define DHTTYPE DHT11


// these constants won't change:
//const int DHpin = 16;      // Sensor pin is set to GPIO 16
//byte dat [5];

DHT dht(DHTPIN, DHTTYPE);

void setup() {
//  pinMode(DHpin, OUTPUT); // declare the DHpin as as OUTPUT
  Serial.begin(9600);       // use the serial port
  Serial.println("DHT11 sensor!");
  dht.begin();
}

void loop() {
  //use the functions which are supplied by library.
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }
  // print the result to Terminal
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  //we delay a little bit for next read
  delay(2000);
  
//  start_test();
//  Serial.print("Hello World");
//  Serial.print("Current humdity =");
//  Serial.print(dat[0], DEC);
//  Serial.print(".");
//  Serial.print(dat[1],DEC);
//  Serial.print("%");
//  Serial.print("Current temperature =");
//  Serial.print(dat[2],DEC);
//  Serial.print(".");
//  Serial.print(dat[3],DEC);
//  Serial.print("C");
//  delay(700);
  
}

//byte read_data(){
//  byte data;
//  for(int i=0; i<8; i++){
//    if (digitalRead(DHpin) == LOW){
//      while(digitalRead (DHpin) == LOW);
//      delayMicroseconds(30); // determine the duration of the high level to determine the data is 0 or 1
//      if (digitalRead(DHpin) == HIGH) 
//      data |= (1 << (7-i)); // high front and low in the post
//      while(digitalRead(DHpin) == HIGH);
//    }
//  }
//  return data;
//}
//
//void start_test() {
//  digitalWrite(DHpin, LOW); // bus down, send start signal
//  delay(30); // delay greater than 18ms, so DHT11 start signal can be detected
//
//  digitalWrite (DHpin, HIGH);
//  delayMicroseconds(40); // Wait for DHT11 response
//
//  pinMode(DHpin, INPUT);
//  while (digitalRead(DHpin) == HIGH);
//  delayMicroseconds(80); // DHT11 response, pulled the bus 80us
//  
//  if (digitalRead(DHpin) == LOW);
//  delayMicroseconds(80); // DHT 80us after the bus pulled to start sending data
//  
//
//  for (int i=0; i<4; i++)
//  dat[i] = read_data();
// 
//
//  pinMode(DHpin, OUTPUT);
//  digitalWrite(DHpin, HIGH); // Send data once after releasing the bus, wait for the host to open the next Start signal
//  
//}
