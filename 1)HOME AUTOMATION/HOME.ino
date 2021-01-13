String voice;
void setup() {
Serial.begin(9600);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(7, OUTPUT);
}

void loop() {
while(Serial.available()){
  delay(3);
  char c = Serial.read();
  voice+=c;}

if(voice.length() >0){
  Serial.println(voice);
  if(voice == "night lamp on")
  {digitalWrite(6, HIGH);}
  else if(voice == "night lamp of")
  {digitalWrite(6, LOW);}
  else if(voice == "fan on")
  {digitalWrite(5, HIGH);}
  else if(voice == "fan off")
  {digitalWrite(5, LOW);}
  else if(voice == "light one on")
  {digitalWrite(4, HIGH);}
  else if(voice == "light one of")
  {digitalWrite(4, LOW);}
  else if(voice == "light to on")
  {digitalWrite(7, HIGH);}
  else if(voice == "light to of")
  {digitalWrite(7, LOW);}
  else if(voice == "all on")
  {digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);}
  else if(voice == "all of")
  { digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  digitalWrite(6, LOW);}
  voice = "";}
}
