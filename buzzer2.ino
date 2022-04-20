int buzzer = 8;
int buzzer_on_off = 9;
int soundDuration;
int silenceDuration;
int finishDuration;
String soundString;
int str_len ;
String temp;
 
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(buzzer_on_off,OUTPUT);
  Serial.begin(9600);
  digitalWrite(buzzer_on_off,LOW);
 
}
 
void loop() {

  
  Serial.print("PLEASE ENTER SOUND DURATION (MS): ");
  while(Serial.available() ==0){}
  soundDuration=Serial.parseInt(); 
  Serial.println(soundDuration);

  Serial.print("PLEASE ENTER SILENCE DURATION (MS): ");
  while(Serial.available() ==0){}
  silenceDuration=Serial.parseInt(); 
  Serial.println(silenceDuration);

  Serial.print("PLEASE ENTER FINISH DURATION (MS): ");
  while(Serial.available() ==0){}
  finishDuration=Serial.parseInt(); 
  Serial.println(finishDuration);

 Serial.print("PLEASE ENTER SOUND STRING     :");
  while(Serial.available() ==0){}
  soundString=Serial.readString(); 
  Serial.println(soundString);
 

  while(Serial.available() == 0)
  {
    for(int i=0; i<soundString.length(); i++){
      Serial.print(soundString[i]);
      temp=soundString[i];
      if(temp.toInt()==1){
          digitalWrite(buzzer_on_off,HIGH);
          Serial.println("High");
       }
      else if(temp.toInt()==0) {
          digitalWrite(buzzer_on_off,LOW);
           Serial.println("Low");
       }
       if(i==soundString.length()-1){
          
          digitalWrite(buzzer_on_off,LOW);
        }
       else{
          delay(soundDuration);
          digitalWrite(buzzer_on_off,LOW);
          delay(silenceDuration);
         }
         
    }
    delay(finishDuration);
  }

 
 
 
// tone(buzzer, 1000); // tone() is the main function to use with a buzzer, it takes 2 or 3 parameteres (buzzer pin, sound frequency, duration)
// delay(1000);
// tone(buzzer, 2000); // You can also use noTone() to stop the sound it takes 1 parametere which is the buzzer pin
// delay(1000);
 
}
