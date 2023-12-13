const int out_pwm = 3 ;	// Creamos variable entera constante con valor 3 
int adc_nuevo = 0 ;   	// Creamos variable entera con valor 0
int adc_viejo = 0 ;   	// Creamos variable entera con valor 0

void setup() {

  //Configuramos a la frecuencia que queremos que trabaje Arduino
  TCCR2B = TCCR2B & 0b11111000 | 0b100;

  // Inicializamos el puerto serie
  Serial.begin(9600);

  // Configuramos pin 3 como salida
  pinMode(out_pwm, OUTPUT);

}

void loop() {
  // Leemos el valor del potenciometro en el pin A0 
  adc_nuevo = analogRead(0);  

  // Mapeamos el valor leido en el pin A0 para adaptarlo al
  // PWM. Convertimos valores de 0-1023 a 0-255  
  adc_nuevo = map(adc_nuevo, 0, 1023, 0, 255);  

  if (adc_nuevo != adc_viejo) {
    // Si almacenaje de las varialbes difiere. Actualiza la lectura del ADC.
    adc_viejo = adc_nuevo;

    // Envia el valor actual al puerto serie
    Serial.println(adc_nuevo);

    // Envia el valor adaptado al PWM
    analogWrite(out_pwm, adc_nuevo); 
  }
}