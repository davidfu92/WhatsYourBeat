int Pin=14;
int ledpin=13;
int beat=0;
int beat2=0;

void setup()
{
  pinMode(Pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //digitalWrite(ledpin,HIGH);
  //delay(100);
  //digitalWrite(ledpin,LOW);
  //delay(100);
  beat=analogRead(Pin);
  delay(10);
  //Serial.println(beat);
  delta();
  //Serial.flush();
}
void delta()
{
  beat2=analogRead(Pin);
  if(abs(beat-beat2)>1000) {
    int delta = 0;
    //Serial.println("beatt "+ String(beat));
    //Serial.println("beat2: "+ String(beat2));
    delta = abs(beat-beat2);
    //Serial.println(" Delta: "+String(beat-beat2));
    Serial.println((String(delta)));
  }
  else {
    Serial.println("0");
  }
}
