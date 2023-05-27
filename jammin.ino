#include "Adafruit_VL53L0X.h"
#include <Adafruit_Fingerprint.h>
#define mySerial Serial1
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
Adafruit_VL53L0X TOF = Adafruit_VL53L0X();
const int Toggle_button1 = 5;
const int Toggle_button2 = 6;
const int Toggle_button3 = 7;
const int Toggle_button4 = 8;
const int MA = 12;
const int MB = 13;
boolean Toggle_buttonState1 = false;
boolean Toggle_buttonState2 = false;
boolean Toggle_buttonState3 = false;
boolean Toggle_buttonState4 = false;
void setup(void)
{
	Serial.begin(9600);
	finger.begin(57600);
	delay(5);
	Serial.println("VL53L0X test");
	finger.getTemplateCount();
	if (!TOF.begin())
	{
		Serial.println(F("Failed to boot VL53L0X"));
		while (1)
			;
	}
	pinMode(Toggle_button1, INPUT_PULLUP);
	pinMode(Toggle_button2, INPUT_PULLUP);
	pinMode(Toggle_button3, INPUT_PULLUP);
	pinMode(Toggle_button4, INPUT_PULLUP);
	pinMode(MA, OUTPUT);
	pinMode(MB, OUTPUT);
}
void loop(void)
{
	VL53L0X_RangingMeasurementData_t measure; // 측정값을 담을 구조체 변수
	Serial.print("Reading a measurement... ");
	TOF.rangingTest(&measure, false);
	if (measure.RangeStatus != 4)
	{
		Serial.print("Distance (mm): ");
		Serial.println(measure.RangeMilliMeter);
	}
	int userID = getFingerprintIDez(measure);
	if (userID != -1) {
		// userID가 1이 아님 => 인증된 사용자가 존재함
		// 여기에 원하는 행동 ㄲ
	}
	if (digitalRead(Toggle_button1) == LOW && !Toggle_buttonState1) {
		if (measure.RangeMilliMeter > 140) {
			digitalWrite(MA, HIGH);
			digitalWrite(MB, HIGH);
			Toggle_buttonState1 = true;
		}
		else if (measure.RangeMilliMeter < 140) {
			digitalWrite(MA, LOW);
			digitalWrite(MB, HIGH);
			Toggle_buttonState1 = true;
		}
	}
	if (Toggle_buttonState1 == 1 && measure.RangeMilliMeter == 140)
	{
		digitalWrite(MA, LOW);
		digitalWrite(MB, LOW);
		Toggle_buttonState1 = false;
	}
	if (digitalRead(Toggle_button2) == LOW && !Toggle_buttonState2)
	{
		if (measure.RangeMilliMeter > 391) {
			digitalWrite(MA, HIGH);
			digitalWrite(MB, HIGH);
			Toggle_buttonState2 = true;
		}
		else if (measure.RangeMilliMeter < 391)
		{
			digitalWrite(MA, LOW);
			digitalWrite(MB, HIGH);
			Toggle_buttonState2 = true;
		}
	}
	if (Toggle_buttonState2 == 1 && measure.RangeMilliMeter == 391)
	{
		digitalWrite(MA, LOW);
		digitalWrite(MB, LOW);
		Toggle_buttonState2 = false;
	}
	if (digitalRead(Toggle_button3) == LOW && !Toggle_buttonState3)
	{
		if (measure.RangeMilliMeter > 607) {
			digitalWrite(MA, HIGH);
			digitalWrite(MB, HIGH);
			Toggle_buttonState3 = true;
		}
		else if (measure.RangeMilliMeter < 607)
		{
			digitalWrite(MA, LOW);
			digitalWrite(MB, HIGH);
			Toggle_buttonState3 = true;
		}
	}
	if (Toggle_buttonState3 == 1 && measure.RangeMilliMeter == 607)
	{
		digitalWrite(MA, LOW);
		digitalWrite(MB, LOW);
		Toggle_buttonState3 = false;
	}
	if (digitalRead(Toggle_button4) == LOW && !Toggle_buttonState4)
	{
		if (measure.RangeMilliMeter > 701) {
			digitalWrite(MA, HIGH);
			digitalWrite(MB, HIGH);
			Toggle_buttonState4 = true;
		}
		else if (measure.RangeMilliMeter < 700) {
			digitalWrite(MA, LOW);
			digitalWrite(MB, HIGH);
			Toggle_buttonState4 = true;
		}
	}
	if (Toggle_buttonState4 == 1 && measure.RangeMilliMeter > 700)
	{
		digitalWrite(MA, LOW);
		digitalWrite(MB, LOW);
		Toggle_buttonState4 = false;
	}
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez()
{
	uint8_t p = finger.getImage();
	if (p != FINGERPRINT_OK)
		return -1;
	p = finger.image2Tz();
	if (p != FINGERPRINT_OK)
		return -1;
	p = finger.fingerFastSearch();
	if (p != FINGERPRINT_OK)
		return -1;
	// found a match!
	Serial.print("Found ID #");
	Serial.print(finger.fingerID);
	Serial.print(" with confidence of ");
	Serial.println(finger.confidence);
	return finger.fingerID;
}