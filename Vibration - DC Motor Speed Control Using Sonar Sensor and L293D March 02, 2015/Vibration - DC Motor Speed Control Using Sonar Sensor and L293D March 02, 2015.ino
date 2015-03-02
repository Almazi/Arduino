#define triggerPin 2 // Trigger pin for sonar sensor
#define echoPin 3 // Echo pin for sonar sensor
#define E1 10  // Enable Pin for motor
#define I1 8  // Control pin 1 for motor
#define I2 9  // Control pin 2 for motor
 
void setup() {
    Serial.begin (9600);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(E1, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
}
 
void loop() {
    long duration, distance;
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2)/29.1;
 
 
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    if(distance < 100 || distance >50){
      Serial.print("Obstacle is in:  ");
      Serial.print(distance);
      Serial.println(" cm; ");
      Serial.println("Warning!");
      analogWrite(E1, 100);  // Run in half speed
    }
    if(distance < 50){
      Serial.print("Obstacle is in:  ");
      Serial.print(distance);
      Serial.println(" cm; ");
      Serial.println("Warning!");
      analogWrite(E1, 200);  // Run in high speed
    }
    else{
      Serial.print("Obstacle is in:  ");
      Serial.print(distance);
      Serial.print(" cm; ");
      Serial.println("You are safe!");
      analogWrite(E1, 50);  // Run in low speed
   
    }
    delay(1000);
}
