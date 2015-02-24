//Sketch /  Code:
#define triggerPin 2
#define echoPin 3
#define ledGreen 12
#define ledRed 13
#define buzzer 10

int sound = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  
  if (distance <= 30 || distance >=20){
    digitalWrite (ledGreen, HIGH);
    sound = 100;
  }
  else{
    digitalWrite(ledGreen, LOW);
  }
  if (distance < 20){
    digitalWrite(ledRed, HIGH);
    sound = 500;
  }
  else{
    digitalWrite(ledRed, LOW);
  }
  if(distance < 30){
    Serial.print("Obstacle is in:  ");
    Serial.print(distance);
    Serial.println(" cm; ");
    Serial.println("Warning!");
    
    digitalWrite (ledGreen, LOW);
    tone(buzzer, sound);
  }
  else{
    Serial.print("Obstacle is in:  ");
    Serial.print(distance);
    Serial.print(" cm; ");
    Serial.println("You are safe!");
    digitalWrite (ledGreen, HIGH);
    noTone(buzzer);
  }
  delay(500);
}
