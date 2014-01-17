// LED_Controller.ino
// Scans the serial port for a value 
// and writes it to the LED.

const int led = 9;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("initializing");
}

void loop() {
  if(Serial.available() > 0) {
    char ch = Serial.read();
    int val = (int)ch;
    if(ch == '1') val = 180;
    else val = 0;
    
    Serial.println(val);
    analogWrite(led, val);
  }
}
