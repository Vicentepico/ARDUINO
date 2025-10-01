const int PinInterruptor = 8;
unsigned long TiempoPrevio = 0;
int EstadodelInterruptor = 0;
int EstadoPreviodelInterruptor = 0;
int Led = 2;
long TiempoIntervalocadaLed = 10000;
void setup() {
    for(int x = 2;x<8;x++){
      pinMode(x, OUTPUT);
    }
    pinMode(PinInterruptor, INPUT);
}
void loop() {
    unsigned long TiempoActual = millis();
    if(TiempoActual - TiempoPrevio > TiempoIntervalocadaLed){
        TiempoPrevio = TiempoActual;
        digitalWrite(Led, HIGH);
            Led++;
            if (Led == 7){
            }
    }
EstadodelInterruptor = digitalRead(PinInterruptor);
    if(EstadodelInterruptor != EstadoPreviodelInterruptor){
        for (int x = 2; x < 8; x++) {
            digitalWrite(x, LOW);
        }
        Led = 2;
        TiempoPrevio = TiempoActual;
    }
    EstadoPreviodelInterruptor = EstadodelInterruptor;
}