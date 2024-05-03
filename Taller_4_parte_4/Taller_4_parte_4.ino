/* Fundacion Kinal 
   Denis e}Estuardo de Jesús Ramirez Padilla
   EB5AM
   TALLER 4 PARTE 4
   2020288
*/


// Definir pines
#define Boton_ascendente 2
#define Boton_descendente 3


int contador = 0;

void setup() {
  
  pinMode(Boton_ascendente, INPUT_PULLUP);
  pinMode(Boton_descendente, INPUT_PULLUP);
  
 
  Serial.begin(9600);
}

void loop() {
  // Si se presiona el boton el contador incrementará
  if (digitalRead(Boton_ascendente) == LOW) {
    delay(50); 
    if (digitalRead(Boton_ascendente) == LOW) {
      contador++;
      if (contador > 100) {
        contador = 0;
      }
      Serial.println(contador);
      delay(200);
    }
  }
  
  // Si el boton se presiona el contador bajará
  if (digitalRead(Boton_descendente) == LOW) {
    delay(50); 
    if (digitalRead(Boton_descendente) == LOW) {
      contador--;
      if (contador < 0) {
        contador = 100;
      }
      Serial.println(contador);
      delay(200); 
    }
  }
}