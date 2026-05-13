# FruitBox 🍎📦

O **FruitBox** é um sistema de monitoramento ambiental focado no controle de qualidade e armazenamento. Desenvolvido em C++ para microcontroladores (Arduino), o projeto realiza a leitura constante de dados digitais de temperatura e umidade do ar, exibindo as condições em tempo real em um display LCD para garantir o ambiente ideal de conservação.

## 🛠️ Tecnologias e Hardwares Utilizados
* **Linguagem:** C/C++
* **Plataforma:** Arduino IDE
* **Hardware:** Arduino Uno (ou compatível), Sensor de Temperatura e Umidade DHT11, Display LCD 16x2 com Módulo I2C.
* **Bibliotecas:** `DHT.h` (Adafruit), `Wire.h` (Nativa) e `LiquidCrystal_I2C.h`.

## 🔌 Esquema de Ligação (Wiring)

**Sensor DHT11:**
* Pino VCC ➔ 5V do Arduino
* Pino DATA ➔ Pino Digital 2 *(Alterado para evitar conflito com I2C)*
* Pino GND ➔ GND

**Display LCD I2C:**
* VCC ➔ 5V
* GND ➔ GND
* SDA ➔ Pino A4
* SCL ➔ Pino A5 

## 🚀 Como executar
1. Clone este repositório.
2. Certifique-se de ter as bibliotecas `DHT sensor library` e `LiquidCrystal_I2C` instaladas na Arduino IDE.
3. Abra o arquivo `FruitBox/FruitBox.ino`.
4. Conecte sua placa via USB, compile e faça o upload do código.
5. Os dados de monitoramento da caixa aparecerão no display e no Monitor Serial (baud rate: 9600).
