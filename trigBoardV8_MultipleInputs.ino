#include "includes.h"

const char fwVersion[] = "10/14/20_Multiple";
//THIS IS ADDED FOR MULTIPLE INPUTS
void scanMultiple();
const int SW1_ADC_pin = 33;
const int SW2_ADC_pin = 34;
const int SW3_ADC_pin = 35;
const int SW4_ADC_pin = 39;

const char SW1_ID[] = "SW1";
const char SW2_ID[] = "SW2";
const char SW3_ID[] = "SW3";
const char SW4_ID[] = "SW4";

char multiMessage[10] = "";

void setup() {
  pinMode(ESPlatchPin, OUTPUT);
  digitalWrite(ESPlatchPin, HIGH);
  pinMode(LEDpin, OUTPUT);
  Serial.begin(115200);
  checkWakeupPins();
  scanMultiple();//ADDED IN FOR MULTIPLE
  loadConfiguration(filename, config);
  rtcInit(config.timerCountDown, false);
  Serial.println(getBattery(), 2);
  //THIS IS ADDED FOR MULTIPLE INPUTS




  if (pushLogic()) { //decide if push will occur or nt and what message will be
    if (wiFiNeeded) {
      if (connectWiFi()) {
        pushOver();
        pushSafer();
        ifttt();
        mqtt();
      }
    }
    udp();
  }

  killPower();
  waitForButton();
  initBluetooth();
}

void loop() {
  if (!OTAsetup)
    serviceBluetooth();
  else
    checkOTA();
}
