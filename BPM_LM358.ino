//codigo pulsos cardiacos con LM358
volatile int contador = 0;
long tiempo= 0;
void interrup(){

  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 250)
  {
    contador++;
    //Serial.println(contador);
  }
  last_interrupt_time = interrupt_time;
}
 
void setup(){
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),interrup, RISING);
}

void loop(){
 
  if (millis()- tiempo >= 15000)
  {
  int pulso = contador*4;
  Serial.print("pulso:");
  Serial.print(pulso);
  Serial.println(" BPM");
  contador=0;
   tiempo = millis();
  }
}
