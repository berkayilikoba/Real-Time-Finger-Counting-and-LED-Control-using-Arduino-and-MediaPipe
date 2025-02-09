#define led1 2  // Define the pin for Red LED
#define led2 3  // Define the pin for Green LED
#define led3 4  // Define the pin for third LED
#define led4 5  // Define the pin for fourth LED
#define led5 6  // Define the pin for fifth LED

void setup() {
  pinMode(led1, OUTPUT);  // Set the Red LED pin as output
  pinMode(led2, OUTPUT);  // Set the Green LED pin as output
  pinMode(led3, OUTPUT);  // Set the third LED pin as output
  pinMode(led4, OUTPUT);  // Set the fourth LED pin as output
  pinMode(led5, OUTPUT);  // Set the fifth LED pin as output
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  if (Serial.available() > 0) {  // If data is available in the serial buffer
    int fingerCount = Serial.parseInt();  // Read the integer from the serial input

    // If the number of fingers is 1, turn on the first LED and turn off others
    if (fingerCount == 1){
      digitalWrite(led1, HIGH);  // Turn on LED 1 (Red)
      digitalWrite(led2, LOW);   // Turn off LED 2 (Green)
      digitalWrite(led3, LOW);   // Turn off LED 3
      digitalWrite(led4, LOW);   // Turn off LED 4
      digitalWrite(led5, LOW);   // Turn off LED 5

    }
    // If the number of fingers is 2, turn on the first two LEDs and turn off others
    else if(fingerCount == 2){
      digitalWrite(led1, HIGH);  // Turn on LED 1 (Red)
      digitalWrite(led2, HIGH);  // Turn on LED 2 (Green)
      digitalWrite(led3, LOW);   // Turn off LED 3
      digitalWrite(led4, LOW);   // Turn off LED 4
      digitalWrite(led5, LOW);   // Turn off LED 5

    }
    // If the number of fingers is 3, turn on the first three LEDs and turn off others
    else if(fingerCount == 3){
      digitalWrite(led1, HIGH);  // Turn on LED 1 (Red)
      digitalWrite(led2, HIGH);  // Turn on LED 2 (Green)
      digitalWrite(led3, HIGH);  // Turn on LED 3
      digitalWrite(led4, LOW);   // Turn off LED 4
      digitalWrite(led5, LOW);   // Turn off LED 5

    }
    // If the number of fingers is 4, turn on the first four LEDs and turn off the last one
    else if(fingerCount == 4){
      digitalWrite(led1, HIGH);  // Turn on LED 1 (Red)
      digitalWrite(led2, HIGH);  // Turn on LED 2 (Green)
      digitalWrite(led3, HIGH);  // Turn on LED 3
      digitalWrite(led4, HIGH);  // Turn on LED 4
      digitalWrite(led5, LOW);   // Turn off LED 5
    }
    // If the number of fingers is 5, turn on all LEDs
    else if(fingerCount == 5){
      digitalWrite(led1, HIGH);  // Turn on LED 1 (Red)
      digitalWrite(led2, HIGH);  // Turn on LED 2 (Green)
      digitalWrite(led3, HIGH);  // Turn on LED 3
      digitalWrite(led4, HIGH);  // Turn on LED 4
      digitalWrite(led5, HIGH);  // Turn on LED 5
    }
    // If the finger count is other than 1 to 5, turn off all LEDs
    else{
      digitalWrite(led1, LOW);   // Turn off LED 1 (Red)
      digitalWrite(led2, LOW);   // Turn off LED 2 (Green)
      digitalWrite(led3, LOW);   // Turn off LED 3
      digitalWrite(led4, LOW);   // Turn off LED 4
      digitalWrite(led5, LOW);   // Turn off LED 5
    }
  }
}
