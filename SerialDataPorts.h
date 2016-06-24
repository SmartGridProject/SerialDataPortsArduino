/*
  Blink.h - Descripción de la librería
Creada por Nombre Autor, Fecha
Lanzado bajo licencia ---
*/
#ifndef SerialDataPorts_h
#define SerialDataPorts_h
#include "arduino.h"
class SerialDataPorts {
  public:
   SerialDataPorts(int pin);
   String parpadeo();
  private:
    // Phisical Inputs
    int _pin;
    int _pin_8;
    int _pin_9;
    int _pin_10;
    int _pin_11;
    int _pin_12;
    //int _pin_13;

    // Phisical Outputs
    int _pin_2;
    int _pin_3;
    int _pin_4;
    int _pin_5;
    int _pin_6;
    int _pin_7;

    // Phisical Analog Inputs
    int _pin_A0;
    int _pin_A1;
    int _pin_A2;
    int _pin_A3;
    int _pin_A4;
    int _pin_A5;
};
#endif
