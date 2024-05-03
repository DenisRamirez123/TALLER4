/* Fundacion Kinal 
   Denis e}Estuardo de Jesús Ramirez Padilla
   EB5AM
   TALLER 4 PARTE 1
   2020288
*/
 
int conteo = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  for(int i=0; i<=9; i++){
  conteo = 500;
    if(digitalRead(2)==HIGH){
      conteo = 1000;}
    else if (digitalRead(3)==HIGH){
      conteo = 2000;}
    else if (digitalRead(4)==HIGH){
      conteo = 3000;}
    if (digitalRead(2)==HIGH && digitalRead(3)==HIGH && digitalRead(4)==HIGH){
      conteo = 500;}
    Serial.println(i);
    delay(conteo);
    }
  }// cierre de for