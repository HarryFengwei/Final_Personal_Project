#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin = 10;
const int buttonPin2 = 9;
int buttonState;
int buttonState2;
int LED = 13;
int Tilt_sensor = 7;
int val = 0;
long t = 0;
long t2 = 0;
long t3 = 0;
unsigned long ct;
unsigned long ct2;
long timeDiff = 0;
int i = 0;
int count = 0;
int flag = 0;
int sec = 11;

String counts = "";
String ts = "";
boolean on = true;
boolean on2 = true;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode (LED,OUTPUT);
  pinMode (Tilt_sensor,INPUT);
  pinMode (buttonPin,INPUT);

}

void loop() {  
  //val = digitalRead(Tilt_sensor);
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  
  Serial.print("a");
  lcd.setCursor(0,0);
  lcd.print("Choose your mode: ");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("L: Countdown    ");
  lcd.setCursor(0,1);
  lcd.print("R: Timing");

  while(buttonState == LOW && buttonState2 == LOW){
      buttonState = digitalRead(buttonPin);
      buttonState2 = digitalRead(buttonPin2);
  }
  if(buttonState == HIGH){
    if(on == true){
      on = false;
    }
    else{
      on = true;
    }
  }

  if(buttonState2 == HIGH){
    if(on2 == true){
      on2 = false;
    }
    else{
      on2 = true;
    }
  }

  if(on == false) {
  Serial.print("k");
  //delay(2000);
  while(val == LOW){
    val = digitalRead(Tilt_sensor);
  }
  for(i = 0; i <= 10000; i++){
    t2 = millis();
  if(val == HIGH){
    Serial.print("b");
    digitalWrite(LED,HIGH);
    flag = 1;
    val = digitalRead(Tilt_sensor);
    t = millis();
    }
  else if(val == LOW){
    Serial.print("c");
    if(flag == 1)
    {
      count++;
      flag = 0;
    }
    digitalWrite(LED,LOW);
    timeDiff = millis() - t;
    if(timeDiff >= 5000){
    Serial.print("d");
    t3 = (t2 - timeDiff) / 1000;
    ts.concat(t3);
    lcd.setCursor(0,0);
    lcd.print("Rolling End.....");
    lcd.setCursor(0,1);
    lcd.print("Total time = " + ts + "s");
    lcd.setCursor(0,0);
    lcd.print("Total time = " + ts + "s");
    Serial.print(count);
    Serial.print("z");
    Serial.print(t);
    counts.concat(count);
    lcd.setCursor(0,1);
    lcd.print("Final Grade = " + counts + " ");
    delay(5000);
    lcd.setCursor(0,0);
    lcd.print("Final Grade = " + counts + " ");
    lcd.setCursor(0,1);
    lcd.print("Exit....See you!");
    while(true){
    }
    }
    else{
      Serial.print("f");
      val = digitalRead(Tilt_sensor);
      lcd.print("Hurry Up!");
      delay(100);
    }
  }
  else{
    Serial.print("g");
   lcd.print("Error...See you!");
  }
  }
  }
  
//  if(on2 == false) {
//    Serial.print("l");
//    lcd.print("Rolling start!!!");
//    delay(2000);
//    
//    while(val == LOW){
//    val = digitalRead(Tilt_sensor);
//  }
//  for(i = 0; i <= 10000; i++){
//  if(val == HIGH){
//    Serial.print("b");
//    digitalWrite(LED,HIGH);
//    flag = 1;
//    val = digitalRead(Tilt_sensor);
//    }
//  else if(val == LOW){
//    Serial.print("c");
//    
//    if(flag == 1)
//    {
//      count++;
//      flag = 0;
//    }
//    digitalWrite(LED,LOW);
//    timeDiff = millis() - t;
//    if(timeDiff == 0){
//    Serial.print("d");
//    
//    lcd.setCursor(0,0);
//    lcd.print("Rolling End.....");
//   
//    counts.concat(count);
//    lcd.setCursor(0,1);
//    lcd.print("Final Grade = " + counts + " ");
//    delay(5000);
//    lcd.setCursor(0,0);
//    lcd.print("Final Grade = " + counts + " ");
//    lcd.setCursor(0,1);
//    lcd.print("Exit....See you!");
//    while(true){
//    }
//    }
//    else{
//      Serial.print("f");
//      val = digitalRead(Tilt_sensor);
//      lcd.setCursor(0,0);
//      lcd.print("Hurry Up!");
//      delay(100);
//    }
//  }
//  else{
//    Serial.print("g");
//   lcd.print("Error...See you!");
//  }
//  }
//  }
//  else{
//  }

    else if(on2 == false){
    while(sec > 0){
      ct2 = millis();
      if(ct2 - ct >= 1000){
        ct = ct2;
        lcd.clear();
        sec--;
        lcd.setCursor(0,0);
        lcd.print("Rest of Time: ");
        lcd.setCursor(8,1);
        lcd.print(sec);
        
        if(flag == 1){
        count++;
        Serial.println(count);
        flag = 0;
        val = digitalRead(Tilt_sensor);
      }
      }
      val = digitalRead(Tilt_sensor);
      if(val == HIGH){
         digitalWrite(LED, HIGH);
         flag = 1;
         val = digitalRead(Tilt_sensor);
      }
      else if(val == LOW){
      digitalWrite(LED, LOW);
      }
    }
    lcd.setCursor(0,0);
    lcd.print("Rolling End.....");
    counts.concat(count);
    delay(3000);
    lcd.setCursor(0,1);
    lcd.print("Final Grade = " + counts + " ");
    delay(5000);
    lcd.setCursor(0,0);
    lcd.print("Final Grade = " + counts + " ");
    lcd.setCursor(0,1);
    lcd.print("Exit....See you!");
    while(true){
    }
    }
    
    else{
    }
}

