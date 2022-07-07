#include <Arduino.h>
#include <M5Stack.h>
#include <WiFi.h>

// WiFi設定
const char* SSID = "HAcTisaiIke";
const char* PASSWORD = "minecraftkn7";

const double PWM_Hz = 20000;
const uint8_t PWM_level = 8;
const uint8_t PWM_CH = 0;

const int encoder_a_pin = 16;
const int encoder_b_pin = 17;
const int dir_pin = 2;
const int pwm_pin = 26;

void setup() {
  M5.begin();
  M5.Power.begin();

  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED) {
    M5.Lcd.print(".");
    delay(500);
  }
  M5.Lcd.print("Connected");

  pinMode(pwm_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(encoder_a_pin, INPUT);
  pinMode(encoder_b_pin, INPUT);

  ledcSetup(PWM_CH, PWM_Hz, PWM_level);
  ledcAttachPin(pwm_pin, PWM_CH);
  ledcWrite(PWM_CH, LOW);
  M5.Lcd.println("PWM HIGH");
  delay(1000);
}

void loop() {
  // 正回転
  M5.Lcd.print("Move Forward");
  digitalWrite(dir_pin, HIGH);
  ledcWrite(PWM_CH, 128); 

  delay(1000);

  M5.Lcd.print(" Move Backward");
  digitalWrite(dir_pin, LOW);
  ledcWrite(PWM_CH, 30);

  delay(3000);

  M5.Lcd.println(" STOP");
  ledcWrite(PWM_CH, LOW);

  delay(3000);

}