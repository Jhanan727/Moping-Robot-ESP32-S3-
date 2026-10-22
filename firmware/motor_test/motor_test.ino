/*
 * motor_test.ino: two DC motors via TB6612FNG on an ESP32-S3
 *
 * Toolchain: Arduino IDE + ESP32 Arduino core 3.x (uses ledcAttach/ledcWrite by pin)
 * Board:     ESP32S3 Dev Module [adjust to your board]
 *
 * Status:  motor direction control works.
 *          PWM speed control: NOT working yet (root cause unknown).
 *
 * Pin notes (to check while debugging PWM): on the ESP32-S3, GPIO20 is USB D+,
 * GPIO45 is a strapping pin and GPIO48 is the RGB LED on some dev boards.
 */

// ── Motor A pins ───────────────────────────────────────
#define AIN1  41
#define AIN2  42
#define PWMA  45

// ── Motor B pins ───────────────────────────────────────
#define BIN1  48
#define BIN2  47
#define PWMB  21

// ── Standby ────────────────────────────────────────────
#define STBY  20

// ── PWM configuration ──────────────────────────────────
#define FREQ  1000   // Hz
#define RES   8      // bits -> duty 0-255

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  // Core 3.x API: ledcAttach(pin, frequency, resolution)
  ledcAttach(PWMA, FREQ, RES);
  ledcAttach(PWMB, FREQ, RES);

  digitalWrite(STBY, HIGH);  // leave standby
}

// speed: -255 (full reverse) ... 0 (brake) ... 255 (full forward)
void moveMotor(bool isA, int speed) {
  int pin1   = isA ? AIN1 : BIN1;
  int pin2   = isA ? AIN2 : BIN2;
  int pinPWM = isA ? PWMA : PWMB;

  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  } else if (speed < 0) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  } else {
    // Short brake
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
  }

  // Core 3.x API: ledcWrite(pin, duty), referenced by pin, not channel
  ledcWrite(pinPWM, abs(speed));
}

void stopAll() {
  ledcWrite(PWMA, 0);
  ledcWrite(PWMB, 0);
  digitalWrite(STBY, LOW);
}

void loop() {
  // Motor A forward ~70 %, Motor B backward ~50 %
  moveMotor(true,  180);
  moveMotor(false, -128);
  delay(2000);

  // Brake
  moveMotor(true,  0);
  moveMotor(false, 0);
  delay(500);

  // Full speed forward
  moveMotor(true,  255);
  moveMotor(false, 255);
  delay(2000);

  stopAll();
  delay(1000);

  digitalWrite(STBY, HIGH);  // re-enable for the next cycle
  delay(500);
}
