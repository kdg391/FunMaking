#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define BT_RXD 5
#define BT_TXD 4

SoftwareSerial bluetooth(BT_RXD, BT_TXD);
Adafruit_NeoPixel RGB_LED = Adafruit_NeoPixel(3, 6, NEO_GRB);
Servo servo;

char rec_data;
bool rec_chk = false;
int Fan = 11;
int Buzzer_Pin = 7;
int Sensor = 10;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);                          // 스마트폰 블루투스 통신속도

  RGB_LED.begin();
  RGB_LED.setBrightness(100);                    //RGB_LED 밝기조절
  RGB_LED.clear();

  pinMode(Fan, OUTPUT); // 쿨링 팬
  pinMode(Buzzer_Pin, OUTPUT); // 피에조 부저
  servo.attach(13); // 서브 모터(문)
}

void loop() {
  if (bluetooth.available()) {                   // 블루투스 명령 수신
    rec_data = bluetooth.read();
    rec_chk = true;
  }

  // LED Control
  // RED
  if (rec_data == 'r') { 
    RGB_Color(RGB_LED.Color(255, 0, 0), 10);
  }
  // ORANGE
  if (rec_data == 'o') { 
    RGB_Color(RGB_LED.Color(255, 165, 0), 10);
  }
  // YELLOW
  if (rec_data == 'y') {
    RGB_Color(RGB_LED.Color(255, 255, 0), 10);
  }
  // GREEN
  if (rec_data == 'g') {
    RGB_Color(RGB_LED.Color(124, 252, 0), 10);
  }
  // BLUE
  if (rec_data == 'b') {
    RGB_Color(RGB_LED.Color(0, 191, 255), 10);
  }
  // PURPLE
  if (rec_data == 'v') {
    RGB_Color(RGB_LED.Color(138, 43, 226), 10);
  }
  // WHITE
  if (rec_data == 'w') {
    RGB_Color(RGB_LED.Color(255, 255, 255), 10);
  }
  // OFF
  if (rec_data == 'x') {
    RGB_LED.clear();
    RGB_LED.show();
  }


  // Smart Airconditional
  // ON
  if (rec_data == 'p') {
    digitalWrite(Fan, HIGH);
  }
  // OFF
  if (rec_data == 'q') {
    digitalWrite(Fan, LOW);
  }

  // Smart Door
  // ON
  if (rec_data == 'm') {
    servo.write(90);
  }
  // CLOSE
  if (rec_data == 'n') {
    servo.write(180);
  }

  // 침입자 경보
  // Lock
  if (rec_data == '1') {
    
  }
  // Unlock
  if (rec_data == '0') {
    
  }
}

void RGB_Color(float c, int wait) {                
  for (int i = 0; i < RGB_LED.numPixels(); i++) 
  {  
     RGB_LED.setPixelColor(i, c);
     RGB_LED.show();
     delay(wait);
  }
}