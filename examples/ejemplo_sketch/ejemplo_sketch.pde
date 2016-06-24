/*
SerialDataPorts.cpp - Esta libreria permite crear tramas
de los estados logicos de las entradas y salidas del Arduino.
Creada por Mauricio Duque Orozco, 06/06/2016
Lanzado bajo licencia MIT

Es necesario establecer Que la libreria funciona solamente para Arduino UNO.

Se definen fisicamente bajo el pinout del arduino las entradas, salidas y
entradas Analogas de la siguiente manera:
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

El resultado de la trama es el siguiente:
{
  E:{           // Estado de las entradas digitales [estados binarios]
    I1  : 1,    // Estado de la entrada 1 -> [pin 12]
    I2  : 0,    // Estado de la entrada 2 -> [pin 11]
    ... : ..,
    ... : ..,
    ... : ..,
    I[n]: ..    // Estado de la entrada n -> [pin "n"]
   },
   S:{          // Estado de las salidas digitales [estados binarios]
    Q1  : 0,    // Estado de la salida 1 -> [pin 2]
    Q2  : 1,
    ... : ..,
    ... : ..,
    ... : ..,
    Q[n]: ..    // Estado de la salida n -> [pin "n"]
   },
   IA:{         // Estado de las entradas analogas [estados 0-1024]
    IA1 : 444,  // Estado de la entrada analoga 1 -> [pin A0]
    IA2 : 0.00,
    ... : ..,
    ... : ..,
    ... : ..,
    IA[n]: ..   // Estado de la entrada analoga n -> [pin "n"]
   }
}& // Indicador de fin de trama
*/

#include <SerialDataPorts.h> // Libreria desarrollada

// Inicializacion de la libreria, solo se pone el pin 13 como punto de partida
SerialDataPorts sdp(13);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  //
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  Serial.println(sdp.trama());  // Siempre debe de ir despues de un cambio de estado logico.
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  Serial.println(sdp.trama()); // Mucho cuidado con los delay.
}
