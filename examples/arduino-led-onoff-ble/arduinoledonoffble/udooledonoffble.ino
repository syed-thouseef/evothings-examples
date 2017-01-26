int led = 13;




char inChar;




// the setup routine runs once when you press reset:

void setup() {

  // initialize the digital pin as an output and turn off 

  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);

  

  // initialize serial port at a baud rate of 115200 bps

  Serial.begin(9600);

  delay(100);

  Serial.println("start");

}




void loop() {

  

  inChar = '\0';

  

  while (Serial.available()) {

    

    // get the new byte:

    inChar = (char)Serial.read();

  }

  

  //Serial.print("inChar= ");Serial.println(inChar);

  //char byteParsed = parseResponse(inChar);

  

  if (inChar == '1') { // compare received data

    digitalWrite(led, HIGH); // turn on light

  } else if (inChar == '0') {

    digitalWrite(led, LOW);  // turn off light

  }




  delay(10); 

}




// the characters sent to Arduino as String are interpreted as ASCII,

// we decrease 48 to return to ASCII range 

char parseResponse(char received) {

  return received - 48;

}
