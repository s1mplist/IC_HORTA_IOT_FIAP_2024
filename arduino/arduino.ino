#define RELE 11
#define BUTTON 10
#define umidadeAnalogica A0 // Pino A0 para leitura analógica do sensor
#define umidadeDigital 7 // Pino 7 para leitura digital do sensor

const int THRESHOLD_RAW = 512; // Valor limite bruto para a leitura analógica do sensor
const int DELAY_TIME = 2000; // Tempo de atraso em milissegundos

int valorAnalogicoBruto; // Armazena o valor bruto da leitura analógica
int valorumidadeDigital; // Armazena a saída digital do sensor de umidade do solo

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  
  pinMode(RELE, OUTPUT); // Define RELE como saída
  pinMode(BUTTON, INPUT); // Define BUTTON como entrada
  
  pinMode(umidadeAnalogica, INPUT); // Define umidadeAnalogica como entrada
  pinMode(umidadeDigital, INPUT); // Define umidadeDigital como entrada

  digitalWrite(RELE, LOW); // Garante que o relé comece desligado
}

void readSensors() {
  valorAnalogicoBruto = analogRead(umidadeAnalogica); // Leitura bruta do sensor analógico
  valorumidadeDigital = digitalRead(umidadeDigital); // Leitura digital do sensor
}

void displayStatus() {
  Serial.print("Leitura analogica: ");
  Serial.print(valorAnalogicoBruto); // Imprime o valor bruto da leitura analógica
  Serial.print(" - Leitura Digital: ");
  Serial.print(valorumidadeDigital);
  Serial.print(" - Status: ");
  Serial.println(valorumidadeDigital == 0 ? "Solo umido" : "Solo seco");
}

void controlRelay() {
  if(valorAnalogicoBruto < THRESHOLD_RAW) {
    digitalWrite(RELE, HIGH); // Ativa o relé
  } else {
    digitalWrite(RELE, LOW); // Mantém o relé desligado
  }
}

void loop() {
  readSensors(); // Lê os valores dos sensores
  displayStatus(); // Exibe o status no monitor serial
  controlRelay(); // Controla o relé com base nas leituras dos sensores
  delay(DELAY_TIME); // Atraso de 500ms
}
