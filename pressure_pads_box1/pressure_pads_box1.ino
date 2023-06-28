#include <Smoothed.h>

/* USB MIDI AnalogControlChange Example

   You must select MIDI from the "Tools > USB Type" menu
   http://www.pjrc.com/teensy/td_midi.html

   This example code is in the public domain.
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

Smoothed <int> pad0;
Smoothed <int> pad1;
Smoothed <int> pad2;
Smoothed <int> pad3;
Smoothed <int> pad4;
Smoothed <int> pad5;
Smoothed <int> pad6;
Smoothed <int> pad7;
Smoothed <int> pad8;
Smoothed <int> pad9;

// the MIDI continuous controller for each analog input
const int controllerA0 = 10; // 10 = pan position
const int controllerA1 = 11; // 11 = volume/expression
const int controllerA2 = 12; // 11 = volume/expression
const int controllerA3 = 13; // 11 = volume/expression
const int controllerA4 = 14; // 11 = volume/expression
const int controllerA5 = 15; // 11 = volume/expression
const int controllerA6 = 16; // 11 = volume/expression
const int controllerA7 = 17; // 11 = volume/expression
const int controllerA8 = 18; // 11 = volume/expression
const int controllerA9 = 19; // 11 = volume/expression

void setup() {
  pad0.begin(SMOOTHED_EXPONENTIAL, 5);
  pad1.begin(SMOOTHED_EXPONENTIAL, 5);
  pad2.begin(SMOOTHED_EXPONENTIAL, 5);
  pad3.begin(SMOOTHED_EXPONENTIAL, 5);
  pad4.begin(SMOOTHED_EXPONENTIAL, 5);
  pad5.begin(SMOOTHED_EXPONENTIAL, 5);
  pad6.begin(SMOOTHED_EXPONENTIAL, 5);
  pad7.begin(SMOOTHED_EXPONENTIAL, 5);
  pad8.begin(SMOOTHED_EXPONENTIAL, 5);
  pad9.begin(SMOOTHED_EXPONENTIAL, 5);
  Serial.begin(9600);
  Serial.println("10 pads midi usb!");
}


// store previously sent values, to detect changes
int previousA0 = -1;
int previousA1 = -1;
int previousA2 = -1;
int previousA3 = -1;
int previousA4 = -1;
int previousA5 = -1;
int previousA6 = -1;
int previousA7 = -1;
int previousA8 = -1;
int previousA9 = -1;

elapsedMillis msec = 0;

void loop() {
  int currentSensorValue0 = analogRead(A0);
  int currentSensorValue1 = analogRead(A1);
  int currentSensorValue2 = analogRead(A2);
  int currentSensorValue3 = analogRead(A3);
  int currentSensorValue4 = analogRead(A4);
  int currentSensorValue5 = analogRead(A5);
  int currentSensorValue6 = analogRead(A6);
  int currentSensorValue7 = analogRead(A7);
  int currentSensorValue8 = analogRead(A8);
  int currentSensorValue9 = analogRead(A9);
  pad0.add(currentSensorValue0);
  pad1.add(currentSensorValue1);
  pad2.add(currentSensorValue2);
  pad3.add(currentSensorValue3);
  pad4.add(currentSensorValue4);
  pad5.add(currentSensorValue5);
  pad6.add(currentSensorValue6);
  pad7.add(currentSensorValue7);
  pad8.add(currentSensorValue8);
  pad9.add(currentSensorValue9);
  int n0 = pad0.get();
  int n1 = pad1.get();
  int n2 = pad2.get();
  int n3 = pad3.get();
  int n4 = pad4.get();
  int n5 = pad5.get();
  int n6 = pad6.get();
  int n7 = pad7.get();
  int n8 = pad8.get();
  int n9 = pad9.get();
  // only chec the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
  if (msec >= 20) {
    msec = 0;
//    int n0 = analogRead(A0);
//    int n1 = analogRead(A1);
//    int n2 = analogRead(A2);
//    int n3 = analogRead(A3);
//    int n4 = analogRead(A4);
//    int n5 = analogRead(A5);
//    int n6 = analogRead(A6);
//    int n7 = analogRead(A7);
//    int n8 = analogRead(A8);
//    int n9 = analogRead(A9);
    Serial.println(n1 );
    n0 = NewMap(n0, 150, 500, 0, 127);
    n1 = NewMap(n1, 150, 500, 0, 127);
    n2 = NewMap(n2, 150, 500, 0, 127);
    n3 = NewMap(n3, 150, 500, 0, 127);
    n4 = NewMap(n4, 150, 500, 0, 127);
    n5 = NewMap(n5, 150, 500, 0, 127);
    n6 = NewMap(n6, 150, 500, 0, 127);
    n7 = NewMap(n7, 150, 500, 0, 127);
    n8 = NewMap(n8, 150, 500, 0, 127);
    n9 = NewMap(n9, 150, 500, 0, 127);

    // only transmit MIDI messages if analog input changed
    if (n0 != previousA0) {
      usbMIDI.sendControlChange(controllerA0, n0, channel);
      previousA0 = n0;
    }
    if (n1 != previousA1) {
      usbMIDI.sendControlChange(controllerA1, n1, channel);
      previousA1 = n1;
    }
    if (n2 != previousA2) {
      usbMIDI.sendControlChange(controllerA2, n2, channel);
      previousA2 = n2;
    }
    if (n3 != previousA3) {
      usbMIDI.sendControlChange(controllerA3, n3, channel);
      previousA3 = n3;
    }
    if (n4 != previousA4) {
      usbMIDI.sendControlChange(controllerA4, n4, channel);
      previousA4 = n4;
    }
    if (n5 != previousA5) {
      usbMIDI.sendControlChange(controllerA5, n5, channel);
      previousA5 = n5;
    }
    if (n6 != previousA6) {
      usbMIDI.sendControlChange(controllerA6, n6, channel);
      previousA6 = n6;
    }
    if (n7 != previousA7) {
      usbMIDI.sendControlChange(controllerA7, n7, channel);
      previousA7 = n7;
    }
    if (n8 != previousA8) {
      usbMIDI.sendControlChange(controllerA8, n8, channel);
      previousA8 = n8;
    }
    if (n9 != previousA9) {
      usbMIDI.sendControlChange(controllerA9, n9, channel);
      previousA9 = n9;
    }
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}

#define MAXLONG 2147483647

long NewMap(long val, long in_min, long in_max, long out_min, long out_max)
{
  // TEST: in_min must be lower than in_max => flip the ranges
  // must be done before out of range test
  if (in_min > in_max) return NewMap(val, in_max, in_min, out_max, out_min);

  // TEST: if input value out of range it is mapped to border values. By choice.
  if (val <= in_min) return out_min;
  if (val >= in_max) return out_max;

  // TEST: special range cases
  if (out_min == out_max) return out_min;
  if (in_min == in_max) return out_min / 2 + out_max / 2; // out_min or out_max? better

  // test if there will be an overflow with well known (unbalanced) formula
  if (( (MAXLONG / abs(out_max - out_min)) < (val - in_min) )  // multiplication overflow test
      || ((MAXLONG - in_max) < -in_min ))                        // division overflow test
  {
    // if overflow would occur that means the ranges are too big
    // To solve this we divide both the input & output range in two
    // alternative is to throw an error.
    // Serial.print(" >> "); // just to see the dividing
    long mid = in_min / 2 + in_max / 2;
    long Tmid = out_min / 2 + out_max / 2;
    if (val > mid)
    {
      // map with upper half of original range
      return NewMap(val, mid, in_max, Tmid, out_max);
    }
    // map with lower half of original range
    return NewMap(val, in_min, mid, out_min, Tmid);
  }

  // finally we have a range that can be calculated
  // unbalanced
  // return out_min + ((out_max - out_min) * (val - in_min)) / (in_max - in_min);

  // or balanced
  // return BalancedMap(val, in_min, in_max, out_min, out_max);
  unsigned long niv = in_max - in_min + 1;          // number input valuer
  unsigned long nov = abs(out_max - out_min) + 1;   // number output values
  unsigned long pos = val - in_min + 1;             // position of val

  unsigned long newpos = ((pos * nov) + niv - 1) / niv; // new position with rounding
  if (out_min < out_max) return out_min + newpos - 1;
  return out_min - newpos + 1;
}
