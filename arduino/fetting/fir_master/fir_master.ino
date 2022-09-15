#include <Wire.h>
/*
const int button1 = 8;
const int button2 = 9;

int x = 0;
int y = 0;
*/

const int beep = 12;

void initBeep()
{
  pinMode(beep, OUTPUT);
  
  digitalWrite(beep, HIGH);
  delay(70);
  digitalWrite(beep, LOW);
  delay(70);
  digitalWrite(beep, HIGH);
  delay(70);
  digitalWrite(beep, LOW);
}

void setup()
{
  Wire.begin(); // i2c 통신
  Serial.begin(115200); // 시리얼 통신

  initBeep();
  
  Serial.println("start");
}

int module = 0; // 0: 선택하지 않음
int position = 0;
int exponent = 0; // 숫자 승수

void loop()
{
  int position = 0;
  if(Serial.available()){
    char a = Serial.read();
    if(a >= 'a' && a <= 'j') {
      Serial.print("select module = ");
        Serial.println(a);
        module = a-96; // 모듈 선택 저장
    }
    
    if(a == '-') {
      Serial.println("init...");
        module = 0;
    }
    
    if(a >= '0' && a <= '9') {
      Serial.print("position = ");
      //Serial.print(a);
      
      position = position * 10 + (a - '0');
      Serial.println(position);
      
      selectModule( module, a);
    }

    if(a == 'm') {
      selectModule( module, 'm');
      Serial.print("move = ");
      Serial.print(a);
    }
    
  }
 
}




void selectModule(int m, int value)
{
  Wire.beginTransmission(m);
    Wire.write(value);
    Wire.endTransmission();
}
