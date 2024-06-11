#include<Servo.h>
int pos=0;
/*motor driver1 */
int motor1pin1 =11;
int motor1pin2 = 12;

int motor2pin1 = 6;
int motor2pin2 = 7;

/*motor driver2*/
int motor3pin1=41;
int motor3pin2=43;

int motor4pin1=1;
int motor4pin2=2;

//mq135
int sensorValue;
int digitalValue;
//led
int red=22;
Servo myservo;
void setup() {
  
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
pinMode(red, OUTPUT);
  //pinMode(9, OUTPUT); 
  //pinMode(10, OUTPUT);
myservo.attach(13);


//motor   driver 2
pinMode(motor3pin1, OUTPUT);
pinMode(motor3pin2, OUTPUT);
pinMode(motor4pin1, OUTPUT);
pinMode(motor4pin2, OUTPUT);
 //pinMode(11,OUTPUT);


//mq135
Serial.begin(9600); // sets the serial port to 9600
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
 /* analogWrite(9, 100); //ENA pin
  analogWrite(10, 200); //ENB pin*/
sensorValue = analogRead(0); // read analog input pin 0
  digitalValue = digitalRead(9);
if(sensorValue<100){

for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);     

  }

 



//mq135

  
   digitalWrite(red, HIGH);
      //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);            //EXHAUST FAN 
  digitalWrite(motor1pin2, LOW);

digitalWrite(motor2pin1, HIGH);         //PUMP AND FAN
  digitalWrite(motor2pin2, LOW);  
delay(100);


  
  delay(100);
 digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);  
 

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  

Serial.println(sensorValue, DEC); // prints the value read
  Serial.println(digitalValue, DEC);
  delay(100); 

  
 

 // delay for absorption of gas

//motor driver 2
//Controlling spin direction of motors:
  digitalWrite(motor3pin1, HIGH); /// pump punmping out water and naoh pouring
  digitalWrite(motor3pin2, LOW);

 digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(1000);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  
digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);


}
else{
    digitalWrite(red, LOW);
  // wait 100ms for next reading

  
}
}
