Libreria-SerialDataPorts-Arduino
==========================

Esta librería comunica tu arduino con VWL.
***Esta librería permite consultar el estado de las entradas y salidas para determinar su valor lógico y realizar la trama de envío de datos,***

# SerialDataPortsArduino

Es una librería que permite consultar los estados de los puertos del Arduino.

***

* [Plataformas Soportadas](#plataformas-soportadas)
* [Instalacion SerialDataPorts](#instalacion-serialdataports)
* [Instalacion Casos Especiales](#instalacion-casos-especiales)
  * [Windows](#windows)
  * [Mac OS X](#mac-os-x)
  * [Ubuntu Linux](#ubuntu-linux)
  * [Raspberry Pi Linux](#raspberry-pi-linux)
* [Uso](#uso)
  * [Pinout](#pinout)
  * [Trama Normalizada](#trama-normalizada)
* [Ejemplo](#ejemplo)
* [Aclaraciones](#aclaraciones)

***
## Plataformas Soportadas

**Nota:** Para Arduino Mega  y otros es necesario cambiar la distribución de pines en los archivos:
- SerialDataPorts.cpp
- SerialDataPorts.h

| Platform / Arch | Versión Placa|
|       ---       | --- |
| Arduino UNO    |  ☑  |  
| Arduino Mega   |  ☑  |  
| Arduino DUE |  ☑  |  

## Instalacion SerialDataPorts

Acceder a la página oficial de Arduino, para descargar el entorno de programación.

https://www.arduino.cc/en/Main/Software

### Instalacion Casos Especiales

Para ver el funcionamiento de la librería acceder a:

https://www.youtube.com/watch?v=HPumk8_aqA0

#### Windows

Acceder a la página oficial de Arduino
https://www.arduino.cc/en/Main/Software

#### Mac OS X

https://www.arduino.cc/en/Guide/MacOSX

#### Ubuntu Linux

http://playground.arduino.cc/Linux/Ubuntu

#### Raspberry Pi Linux
Terminal
```
sudo apt-get install arduino
```

## Uso


#### Pinout

Es necesario estandarizar los pines del arduino:

- Los pines del 8 al 12, ***deben estar destinados a "entradas digitales".***
- Para los pines 2 al 7, ***deben estar destinados a "salidas digitales".***

```
// Pinout Inputs
  _pin = pin;
  _pin_8 = 8;
  _pin_9 = 9;
  _pin_10 = 10;
  _pin_11 = 11;
  _pin_12 = 12;

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
```
***

#### Trama Normalizada

La trama permite la normalización de los datos provenientes del Arduino.

```
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
```

**Nota:** Siempre debe ponerse al final de la trama "&" como indicador de final.

## Ejemplo

Este ejemplo muesta el uso de la librería.


```cpp
  #include <SerialDataPorts.h>

  SerialDataPorts sdp(13);

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    //...
    // Inserta tu código aquí.
    //...
    Serial.println(sdp.trama());  // Siempre debe de ir después de un cambio de estado lógico.
  }
```

**Nota:** Especial cuidado cuando usa instrucciones como "Delay", pueden provocar
pérdida de datos, es preferible usar la instruccion `Serial.println(sdp.trama());`
después de cada cambio lógico de los puertos

```cpp
#include <SerialDataPorts.h>
SerialDataPorts sdp(13);

void setup() {

  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {

  digitalWrite(12, HIGH);   
  delay(500);   
  Serial.println(sdp.trama());  
  digitalWrite(12, LOW);    
  delay(500);
  Serial.println(sdp.trama());
}
```
## Aclaraciones


- ***La librería solo permite la lectura de los puertos análogos como entradas,
por el momento no se desarrolla para las entradas análogas***

- ***En futuras versiones se propone ampliar la librería para demás versiones de Arduino***

- ***Para cualquier error por favor consultar o informar a: https://github.com/virtualweblab/SerialDataPortsArduino/issues ***
