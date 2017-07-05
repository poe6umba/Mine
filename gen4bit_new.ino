#define out1 4
#define out2 5
#define out3 6
#define out4 7
String input = "";
const String mode = "mode";
const String change_freq = "rate";
const String increase_digit = "inc";
const String change_digit = "digit";
byte mod=1; //автомод по умолчнию
float time_delay=500; //2 Гц частота по умолчанию, время задержки 0.5 сек
byte INC=0;
void setup(){
Serial.begin(9600);
pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT);
pinMode(out3, OUTPUT);
pinMode(out4, OUTPUT);
Serial.print("Enter: 'mode' for change mode");
}

void rate(int x){
   time_delay=(1.0/x)*1000; //считаем время задержки для частоты х
   if(x==0){x=1;time_delay=500;} // при отсутствии входных данных ставим частоту 2 Гц
   Serial.print("\nfreq now = ");
   Serial.print(x);
   Serial.print(" Hz");
  }
  
void loop() {
  while (Serial.available() > 0) { //обработчик команд
    char c = Serial.read();
    if (c == '\n') { 
      if (input.equals(mode) == true){ //выбор мода
       Serial.print("\nChoose mod: 1-auto, 0-manual");
       Serial.setTimeout(5000); // ждем ввода 5 секунд
       mod=Serial.parseInt();
        if(mod==1){
        Serial.print("\nautomod, 'rate' for choose freq");
        }
        else if(mod==0){
          Serial.print("\nmanual mod,'inc' for increase digit, 'digit' for choose");
          }
        else{Serial.print("\ninvalid mod");}
        }
      else if (input.equals(change_freq) == true){ //меняем частоту
       Serial.print("\nEnter freq, 1..9(Hz)");
       Serial.setTimeout(5000); // ждем ввода 5 секунд
       rate(Serial.parseInt());
       }
       else if (input.equals(increase_digit) == true){ 
       INC++; //меняем число на 1
       Serial.print("\ndigit increase, ");
       Serial.print(INC);
       }
       else if (input.equals(change_digit) == true){ 
       Serial.print("\nEnter digit, 1..15");
       Serial.setTimeout(5000); // ждем ввода 5 секунд
       INC= Serial.parseInt();
       if(INC<16&&INC>=0){
       Serial.print("\ndigit now = ");
       Serial.print(INC);
       }
       else{
        Serial.print("\ninvalid digit");
        }
       }
      input = "";
      }
      else{
        input += c; //записываем все данные в строку, пока не будет нажат Enter
      }
  }
if(INC==0){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, LOW); 
digitalWrite(out3, LOW); 
digitalWrite(out4, LOW); 
} 
else if(INC==1){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, LOW); 
digitalWrite(out3, LOW); 
digitalWrite(out4, LOW); 
} 
else if(INC==2){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, LOW); 
digitalWrite(out4, LOW); 
} 
else if(INC==3){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, LOW); 
digitalWrite(out4, LOW); 
} 
else if(INC==4){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, LOW); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, LOW);  
} 
else if(INC==5){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, LOW); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, LOW);  
} 
else if(INC==6){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, LOW); 
} 
else if(INC==7){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, LOW); 
} 
else if(INC==8){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, LOW); 
digitalWrite(out3, LOW); 
digitalWrite(out4, HIGH); 
} 
else if(INC==9){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, LOW); 
digitalWrite(out3, LOW); 
digitalWrite(out4, HIGH); 
} 
else if(INC==10){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, LOW); 
digitalWrite(out4, HIGH);  
} 
else if(INC==11){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, LOW); 
digitalWrite(out4, HIGH); 
} 
else if(INC==12){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, LOW); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, HIGH);  
} 
else if(INC==13){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, LOW); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, HIGH);  
} 
else if(INC==14){ 
digitalWrite(out1, LOW); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, HIGH); 
} 
else if(INC==15){ 
digitalWrite(out1, HIGH); 
digitalWrite(out2, HIGH); 
digitalWrite(out3, HIGH); 
digitalWrite(out4, HIGH);  
}
 if (mod==1){ //авторежим
  INC++;
  delay(time_delay); //время задержки
  }
  if(INC>15){ //обнуляем число
  INC=0;
    }  
 }  
