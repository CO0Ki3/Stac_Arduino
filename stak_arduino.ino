#include <SoftwareSerial.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU9250.h"
/**
 * 자이로 센서 변수
 */
MPU9250 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;
float Axyz[3];

/** 
 *  블루투스 센서 변수
 */
SoftwareSerial BTSerial(2, 3);

/**
 * 플렉스 센서 변수
 */
int flex_top = A0;
int flex_mid = A3;
int flex_bot = A5;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  BTSerial.begin(9600);
  accelgyro.initialize();
  Serial.println("C");
  BTSerial.println("C");
}

void loop() {
  /*
   * 플렉스 센서 값
   */
  int flex_top = A0;
  int flex_mid = A3;
  int flex_bot = A5;
  /*
   * 자이로 센서 계산식
   */
  accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
  Axyz[0] = (double) ax / 16384;
  Axyz[1] = (double) ay / 16384;
  Axyz[2] = (double) az / 16384;
  int x = Axyz[0]*100;
  int y = Axyz[1]*100;
  int z = Axyz[2]*100;

  /*
   * 플렉스 센서 계산식
   */
  flexTopValue = analogRead(flex_top);
  flexMidValue = analogRead(flex_mid);
  flexBotValue = analogRead(flex_bot);
  /*
   * 자이로 센서 출력
   */
  Serial.print("X : ");
  Serial.println(x);
  Serial.print("Y : ");
  Serial.println(y);
  Serial.print("Z : ");
  Serial.println(z);
  Serial.println();
  /*
   * 플렉스 센서 출력
   */
  Serial.print("Top: ");
  Serial.println(flexTopValue);
  Serial.print("Mid: ");
  Serial.println(flexMidValue);
  Serial.print("Bot: ");
  Serial.println(flexbotValue);
  delay(1000);
}
