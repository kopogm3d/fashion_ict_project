#include <Wire.h>

#define motorPin1 2 // IN1
#define motorPin2 3 // IN2
#define motorPin3 4 // IN3
#define motorPin4 5 // IN4
 
#define step 2048 // 1봐퀴 스텝수

// 모터 회전 Loop 문 구현을 간단하게 하기위해 핀 배열 선언
int pinArray[4] = { motorPin1, motorPin2, motorPin3, motorPin4 };

// CW 시계방향 데이터 전송
int CW[4] = {0b1000,0b0100,0b0010,0b0001};
int CCW[4] = {0b0001,0b0010,0b0100,0b1000};

int step_count = 0;
int distance = 0;

const int beepPin = 12;

const int i2c = 1;

int x = 0;
int position = 0;

int move = 0;

void initBeep()
{
  pinMode(beepPin, OUTPUT);
  beep();
}

void beep()
{
  digitalWrite(beepPin, HIGH);
  delay(70);
  digitalWrite(beepPin, LOW);
}

void setup(){
  // 핀모드 설정
  // 스텝모터 드라이브 보드의 IN 연결핀 출력으로 설정
  for(int i = 0 ; i < 4 ; i++ ) {
    pinMode(pinArray[i], OUTPUT);
  }

  // 시리얼 초기화
  Serial.begin(115200);
  Serial.println("module start");

  Wire.begin(i2c); // ic2 초기화
  Wire.onReceive(receivedEvent);

  // Beep
  initBeep();

  // 초기화 동작
  init_process();
}

void receivedEvent(int howmany){

    x = Wire.read();
    Serial.print(x);
    
    if( x >= 48 && x <= 57) {
      position = position * 10 + (x - 48);
      Serial.print("position = ");
      Serial.println(position);
    }

   if(x == 109) {
    move = 1;
  }

}

int max_detact()
{
  int status = digitalRead(7);
  if(status == LOW){
    return 1; // 끝 검출
  } else {
    return 0; // 동작가능한 범위
  }
}

int min_detact()
{
  int status = digitalRead(8);
  if(status == LOW){
    return 1; // 끝 검출
  } else {
    return 0; // 동작가능한 범위
  }
}

int direction = 1; // 역방향 : 0

int btn_up()
{
  int btn_sw1 = digitalRead(9);
  if(btn_sw1 == LOW){
    return 1;
  } else {
    return 0;
  }
}

int btn_down()
{
  int btn_sw1 = digitalRead(10);
  if(btn_sw1 == LOW){
    return 1;
  } else {
    return 0;
  }
}

int current = 0;

void loop() {
  int a = 0;
  int d = 0;
  if(Serial.available()){
    a = Serial.parseInt();
    Serial.println(a);
    //d = getDistance(a);
    position = a;
    move = 1;
  }

  if(position>0) {
    if(move == 1) {
      d = getDistance(position);
      position = 0; // 초기화
      move = 0;
    }
    
  }

  

  if(d>0) {
    setPosition(d); // 절대 좌표로 이동
    beep();
    d = 0;
  }

}

int getDistance(int a)
{
  int dispos = 0;
  if(a < distance) {
      if(a<0) {
        init_process();
        current = 0;
      } else {       
        if(current < a) {
          direction = 1; //cw
          dispos = a - current;
          current += dispos;
        } else {
          direction = 0; // ccw
          dispos = current - a; 
          current -= dispos;     
        }
    
        Serial.print("current= ");
        Serial.println(current);
      
        Serial.print("direction= ");
        Serial.println(direction);
    
        Serial.print("dispos = ");
        Serial.println(dispos);
      }
      
    } else {
      Serial.println("invaild distance");
    } 

  return dispos;
}


// 절대좌료로 이동
void setPosition(int pos)
{
  if(direction == 1) {
      Serial.println("cw");
      for(int i=0; i<pos; i++)
      {
          step_ccw(i);
          Serial.print("max = ");
          Serial.print(distance);
          Serial.print(", ");
          Serial.print("moving = ");
          Serial.println(i);
      }      

 
    } else {
      Serial.println("ccw");
      for(int i=0; i<pos; i++)
      {
          step_cw(i);
          Serial.print("max = ");
          Serial.print(distance);
          Serial.print(", ");
          Serial.print("moving = ");
          Serial.println(i);
      }

    }

    Serial.print("current = ");
    Serial.println(current);

}

void gear_loop()
{
  if(direction == 1 && min_detact()){
    step_count=0;
  }

  if(direction == 0 && max_detact()){
    step_count=0;
  }
  
  if(max_detact()) {
    // 모터 동작
    Serial.println("ccw working");
    direction = 1;
    
  } else if(min_detact()){
    // 모터 동작
    Serial.println("cw working");
    direction = 0;
  
  }

  if(direction == 0) {
      step_count++;
      //step_ccw();

  } else {
      step_count++;
      //step_cw();
  }

  Serial.println(step_count);
}








void init_process()
{
  // 앞방향 최대치 검사
  move_to_max();

  distance = 0;
  delay(1000);
  
  // 뒤방향 최소치 검사 
  distance = move_to_min();
  
  Serial.print("gear distance = ");
  Serial.println(distance);

}


int move_to_max()
{
  Serial.println("checking max");
  int temp, i=0;
  while(!max_detact()){
    temp = i++ % 4;
    digitalWrite(pinArray[0], bitRead(CCW[temp], 0));
    digitalWrite(pinArray[1], bitRead(CCW[temp], 1));
        digitalWrite(pinArray[2], bitRead(CCW[temp], 2));
        digitalWrite(pinArray[3], bitRead(CCW[temp], 3));
        stepDelay();
  }
  return i;
}

int move_to_min()
{
  Serial.println("checking min");
  int temp, i=0;
  while(!min_detact()){
    temp = i++ % 4;
    digitalWrite(pinArray[0], bitRead(CW[temp], 0));
    digitalWrite(pinArray[1], bitRead(CW[temp], 1));
    digitalWrite(pinArray[2], bitRead(CW[temp], 2));
    digitalWrite(pinArray[3], bitRead(CW[temp], 3));
    stepDelay();
  }

  return i;
}



void step_cw(int count)
{
  int temp;
  temp = count % 4;
  digitalWrite(pinArray[0], bitRead(CW[temp], 0));
  digitalWrite(pinArray[1], bitRead(CW[temp], 1));
  digitalWrite(pinArray[2], bitRead(CW[temp], 2));
  digitalWrite(pinArray[3], bitRead(CW[temp], 3));
  stepDelay();
  // Serial.println("cw");
}

void step_ccw(int count)
{
  int temp;
  temp = count % 4;
  digitalWrite(pinArray[0], bitRead(CCW[temp], 0));
  digitalWrite(pinArray[1], bitRead(CCW[temp], 1));
  digitalWrite(pinArray[2], bitRead(CCW[temp], 2));
  digitalWrite(pinArray[3], bitRead(CCW[temp], 3));
  stepDelay();
  // Serial.println("ccw");
}

void stepDelay()
{
  // 모터 부하가 없는 상태에서, 
  // 각 스텝 간격이 최소 3ms 이상이어야 정상적으로 동작합니다.
  delay(3);
}
