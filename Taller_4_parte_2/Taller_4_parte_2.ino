/* Fundacion Kinal 
   Denis e}Estuardo de Jesús Ramirez Padilla
   EB5AM
   TALLER 4 PARTE 2
   2020288
*/



// Definición de pines para los LED y los interruptores
 int ledPins[] = {4, 5, 6, 7, 8, 9}; // Pines para los LEDs
 int funcion1 = 2; // Primer interruptor
 int funcion2 = 3; // Segundo interruptor

// Velocidades de la secuencia
const int velo1 = 500; // Velocidad 1 en milisegundos
const int velo2 = velo1 / 2; // Velocidad 2: el doble de la velocidad 1

void setup() {
  // Inicializar los pines de los LED como salidas
  for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configurar los pines de los interruptores como entradas
  pinMode(funcion1, INPUT_PULLUP);
  pinMode(funcion2, INPUT_PULLUP);
  
  // Iniciar comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leer el estado de los interruptores
  bool switchState1 = digitalRead(funcion1);
  bool switchState2 = digitalRead(funcion2);
  
  // Si el primer interruptor está presionado
  if (!switchState1) {
    Serial.println("Secuencia - velocidad 1");
    runSequence(velo1);
  }
  // Si el segundo interruptor está presionado
  else if (!switchState2) {
    Serial.println("Secuencia - velocidad 2");
    runSequence(velo2);
  }
  // Si ninguno de los interruptores está presionado, no hacer nada
}

// Función para ejecutar la secuencia de luces
void runSequence(int speed) {
  for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    digitalWrite(ledPins[i], HIGH); // Encender el LED actual
    delay(speed); // Esperar según la velocidad
    digitalWrite(ledPins[i], LOW); // Apagar el LED actual
  }
  
  for (int i = sizeof(ledPins)/sizeof(ledPins[0]) - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH); // Encender el LED actual
    delay(speed); // Esperar según la velocidad
    digitalWrite(ledPins[i], LOW); // Apagar el LED actual
  }
}