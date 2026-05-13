// ==========================================
// Projeto: FruitBox
// Descrição: Monitoramento de Temperatura e Umidade
// ==========================================

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Biblioteca para o display LCD I2C

// Definição do pino e tipo do sensor
#define DHTPIN 2  // Pino Digital 2 escolhido para não conflitar com I2C (A4/A5)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Configura o display I2C no endereço 0x27 e tamanho 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inicializa comunicação serial
  Serial.begin(9600);
  
  // Inicializa o sensor DHT
  dht.begin();
  
  // Inicializa o display LCD
  lcd.init(); 
  lcd.backlight();

  // Tela de inicialização do sistema
  lcd.setCursor(0, 0);
  lcd.print("FruitBox System");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2500);
  lcd.clear();
}

void loop() {
  // Realiza a leitura do sensor
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Verifica se as leituras são válidas (NaN = Not a Number)
  if (!isnan(temperatura) && !isnan(umidade)) {
    
    // Log de monitoramento no Monitor Serial
    Serial.print("[FruitBox Log] Temp: ");
    Serial.print(temperatura);
    Serial.print(" °C | Umidade: ");
    Serial.print(umidade);
    Serial.println(" %");

    // Atualiza os dados no display LCD
    lcd.clear();
    
    // Linha 0 (Temperatura)
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura, 1);
    lcd.print(" C");

    // Linha 1 (Umidade)
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade, 1);
    lcd.print(" %");
    
  } else {
    // Tratamento de falha na leitura do sensor
    Serial.println("[Erro] Falha na leitura do DHT11.");
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no Sensor");
    lcd.setCursor(0, 1);
    lcd.print("Verifique cabos!");
  }

  // O DHT11 necessita de intervalo entre leituras (2 segundos recomendado)
  delay(2000);
}
