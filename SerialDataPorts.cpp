/*
Libejemplo.cpp -Descripción cpp
Creada por Nombre Autor, Fecha
Lanzado bajo licencia---
*/

#include "arduino.h"
#include "SerialDataPorts.h"

SerialDataPorts::SerialDataPorts(int pin)
{
  // Pinout Inputs
  _pin = pin;
  _pin_8 = 8;
  _pin_9 = 9;
  _pin_10 = 10;
  _pin_11 = 11;
  _pin_12 = 12;
  //_pin_13 = 13;

  // Pinout Outputs
  _pin_2 = 2;
  _pin_3 = 3;
  _pin_4 = 4;
  _pin_5 = 5;
  _pin_6 = 6;
  _pin_7 = 7;

  // Pinout Analog Inputs
  _pin_A0 = A0;
  _pin_A1 = A1;
  _pin_A2 = A2;
  _pin_A3 = A3;
  _pin_A4 = A4;
  _pin_A5 = A5;
}

// funcion principal de la libreria

String SerialDataPorts::parpadeo()
{
//código
  String chain = "{E:{I12:" + String(digitalRead(_pin_12)) +
                    ",I11:" + String(digitalRead(_pin_11)) +
                    ",I10:" + String(digitalRead(_pin_10)) +
                    ",I9:" + String(digitalRead(_pin_9)) +
                    ",I8:" + String(digitalRead(_pin_8)) +
                  "},S:{Q2:" + String(digitalRead(_pin_2)) +
                      ",Q3:" + String(digitalRead(_pin_3)) +
                      ",Q4:" + String(digitalRead(_pin_4)) +
                      ",Q5:" + String(digitalRead(_pin_5)) +
                      ",Q6:" + String(digitalRead(_pin_6)) +
                      ",Q7:" + String(digitalRead(_pin_7)) +
                  "},IA:{IA1:" + String(analogRead(_pin_A0)) +
                        ",IA2:" + String(analogRead(_pin_A1)) +
                        ",IA3:" + String(analogRead(_pin_A2)) +
                        ",IA4:" + String(analogRead(_pin_A3)) +
                        ",IA5:" + String(analogRead(_pin_A4)) +
                        ",IA6:" + String(analogRead(_pin_A5)) +
                  "}}&";

  return  chain;
}
