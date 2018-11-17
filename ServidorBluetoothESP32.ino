/*
 * Programa para acionar e desacionar o LED integrado do ESP32 via bluetooth
 * (Usando um aplicativo como o Bluetooth Terminal).
 * O aplicativo poderá ser substituido por um de construção própria.
*/

#include "BluetoothSerial.h"
#define LED 2

BluetoothSerial bluetoothSerial; // Cria um objeto Bluetooth

int valorRecebido; // Variável que sera usada para armazenar o valor recebido do aplicativo Android
void setup() {
  bluetoothSerial.begin("ESP32BluetoothCtism"); // Configura "ESP32BluetoothCtism" como nome do dispositivo bluetooth. 
  pinMode(LED, OUTPUT); // Define o pino 2 como saída;
  digitalWrite(LED, LOW); // Iniciar com o LED desligado;
}

void loop() {
  if (bluetoothSerial.available()) { // Verifica se alguma informação foi recebida pelo bluetooth.
    valorRecebido = bluetoothSerial.read(); // Armazena a informação recebida na variável valorRecebido.
    // O valor recebido do aplicativo Android é um caractere.
    if (valorRecebido == 48) { // 48 é valor decimal correspondente ao caractere '0' da tabela ASCII.
        digitalWrite(LED, LOW);
        bluetoothSerial.println("LED foi desligado");
    }
    
    if (valorRecebido == 49) { // 49 é valor decimal correspondente ao caractere '1' da tabela ASCII.
        digitalWrite(LED, HIGH);
        bluetoothSerial.println("LED foi ligado");
    }     
  }
  delay(100);
}
