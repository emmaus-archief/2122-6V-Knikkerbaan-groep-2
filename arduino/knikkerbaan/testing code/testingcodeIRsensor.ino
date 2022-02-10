int switchState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(10,INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
} 

void loop() {
  switchState = digitalRead(8);

  Serial.println(switchState);

  if (switchState == HIGH) {
        digitalWrite(LED_BUILTIN, HIGH);
   } 
   else {
      digitalWrite(LED_BUILTIN, LOW);
   }    
  
}
