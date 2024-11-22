int trigger = D2; 
int echo = D1;
int led1 = D3;
int led2 = D4;
int led3 = D5;


long duration = 0;
int cm = 0;
int inch = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  cm = duration*0.034/2;
  inch = duration*0.0133/2;

  if (inch <10){
    digitalWrite(led1, HIGH);
    // digitalWrite(led2, LOW);
    // digitalWrite(led3, LOW);
  } 
  else if(inch<20){
    digitalWrite(led2, HIGH);
    // digitalWrite(led2, LOW);
    // digitalWrite(led3, LOW);
  }
  else if(inch<30){
    digitalWrite(led3, HIGH);
    // digitalWrite(led2, LOW);
    // digitalWrite(led3, HIGH);
  }
  if(inch<100){
    Serial.print("Inches: ");
    Serial.println(inch);
    Serial.print("Cm: ");
    Serial.println(cm);
  }
  delay(500);
  }