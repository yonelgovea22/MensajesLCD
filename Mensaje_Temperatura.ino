#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

int imprimir=0;
String Mensaje="";

const int sensorPin= A5;
int dia=12,mes=4,ano=2018;
int mit = 00, seg=2, hor=10;

void setup(){
pinMode(10,OUTPUT);
digitalWrite(10,HIGH);
lcd.begin(16, 2);

Serial.begin(9600);
}

void loop(){

int cuenta=0;
int caracteres=0;
while (Serial.available()>0){
Mensaje=Mensaje+Decimal_to_ASCII(Serial.read());
cuenta++;
}
caracteres=Mensaje.length();
if (caracteres>16){
  if (Mensaje!=""){
 lcd.clear();

  lcd.print(Mensaje.substring(0,16));
  lcd.setCursor(0,1);
    lcd.print(Mensaje.substring(16,caracteres));
}
}
else
{
if (Mensaje!=""){
 lcd.clear();
  lcd.print(Mensaje);
}
}
delay(1000);
Mensaje="";

delay(5000);
 lcd.clear();
        lcd.begin(16,2);
        lcd.setCursor(0,0);

        lcd.print("TEMPERATURA");
        int value = analogRead(sensorPin);

        float millivolts = (value / 1023.0) * 5000;
        
        float celsius = millivolts / 10;
        
       
        lcd.setCursor(0,1);
        
        Serial.print(celsius);
        
        Serial.println(" C");
        
        lcd.print(celsius);
        
        lcd.print(" C");
   delay(5000);
  
    //Iniciamos el contador del segundos para que empiece a contar los segundos y inicie tambien el reloj  
    seg++;    
    if(seg > 59){
      mit++;
      seg=0;  
    }
    if(mit > 59){
      hor++;
      mit=0;  
    }
    if(hor == 23 && mit == 59 && seg == 59){
      dia++;
    }
    if(dia == 31 || mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 && hor == 23 && mit == 59 && seg == 59){
      mes++;
      dia=1;  
    }else if(dia == 30 || mes == 4 || mes == 6 || mes == 9 && hor == 23 && mit == 59 && seg == 59){
      mes++;
      dia=1;
    }else if(dia == 28 && mes == 2 && hor == 23 && mit == 59 && seg == 59){
      mes++;
      dia=1;
    }
    if(dia == 31 && mes == 12 && hor == 23 && mit == 59 && seg == 59){
      ano++;
      mes=1;
    }
    //Limpiar el display
    lcd.clear();
    //Mostramos la información obtenida (temperatura y humedad) en el Monitor Serial
 
    //Situamos el cursor en la posicion 0 de la primera linea
    lcd.setCursor(0,0); 
    lcd.print("HORA: ");
    if(hor < 10){        
      lcd.print("0");      
    }
    lcd.print(hor);
    lcd.print(":");
    if(mit < 10){
      lcd.print("0");
    }    
    lcd.print(mit);
    if(hor<12){
      lcd.print(" AM");
    }else{
      lcd.print(" PM"); 
    }
    dia=12;
    lcd.setCursor(0,1);
    lcd.print("Fecha:");
    lcd.print(dia);
    lcd.print("/");
    lcd.print(mes);
    lcd.print("/");
    lcd.print(ano);    
  

   delay(5000);    

}

char Decimal_to_ASCII(int entrada){
  char salida=' ';
  switch(entrada){
case 32: 
salida=' '; 
break; 
case 33: 
salida='!'; 
break; 
case 34: 
salida='"'; 
break; 
case 35: 
salida='#'; 
break; 
case 36: 
salida='$'; 
break; 
case 37: 
salida='%'; 
break; 
case 38: 
salida='&'; 
break; 
case 39: 
salida=' '; 
break; 
case 40: 
salida='('; 
break; 
case 41: 
salida=')'; 
break; 
case 42: 
salida='*'; 
break; 
case 43: 
salida='+'; 
break; 
case 44: 
salida=','; 
break; 
case 45: 
salida='-'; 
break; 
case 46: 
salida='.'; 
break; 
case 47: 
salida='/'; 
break; 
case 48: 
salida='0'; 
break; 
case 49: 
salida='1'; 
break; 
case 50: 
salida='2'; 
break; 
case 51: 
salida='3'; 
break; 
case 52: 
salida='4'; 
break; 
case 53: 
salida='5'; 
break; 
case 54: 
salida='6'; 
break; 
case 55: 
salida='7'; 
break; 
case 56: 
salida='8'; 
break; 
case 57: 
salida='9'; 
break; 
case 58: 
salida=':'; 
break; 
case 59: 
salida=';'; 
break; 
case 60: 
salida='<'; 
break; 
case 61: 
salida='='; 
break; 
case 62: 
salida='>'; 
break; 
case 63: 
salida='?'; 
break; 
case 64: 
salida='@'; 
break; 
case 65: 
salida='A'; 
break; 
case 66: 
salida='B'; 
break; 
case 67: 
salida='C'; 
break; 
case 68: 
salida='D'; 
break; 
case 69: 
salida='E'; 
break; 
case 70: 
salida='F'; 
break; 
case 71: 
salida='G'; 
break; 
case 72: 
salida='H'; 
break; 
case 73: 
salida='I'; 
break; 
case 74: 
salida='J'; 
break; 
case 75: 
salida='K'; 
break; 
case 76: 
salida='L'; 
break; 
case 77: 
salida='M'; 
break; 
case 78: 
salida='N'; 
break; 
case 79: 
salida='O'; 
break; 
case 80: 
salida='P'; 
break; 
case 81: 
salida='Q'; 
break; 
case 82: 
salida='R'; 
break; 
case 83: 
salida='S'; 
break; 
case 84: 
salida='T'; 
break; 
case 85: 
salida='U'; 
break; 
case 86: 
salida='V'; 
break; 
case 87: 
salida='W'; 
break; 
case 88: 
salida='X'; 
break; 
case 89: 
salida='Y'; 
break; 
case 90: 
salida='Z'; 
break; 
case 91: 
salida='['; 
break; 
case 92: 
salida=' '; 
break; 
case 93: 
salida=']'; 
break; 
case 94: 
salida='^'; 
break; 
case 95: 
salida='_'; 
break; 
case 96: 
salida='`'; 
break; 
case 97: 
salida='a'; 
break; 
case 98: 
salida='b'; 
break; 
case 99: 
salida='c'; 
break; 
case 100: 
salida='d'; 
break; 
case 101: 
salida='e'; 
break; 
case 102: 
salida='f'; 
break; 
case 103: 
salida='g'; 
break; 
case 104: 
salida='h'; 
break; 
case 105: 
salida='i'; 
break; 
case 106: 
salida='j'; 
break; 
case 107: 
salida='k'; 
break; 
case 108: 
salida='l'; 
break; 
case 109: 
salida='m'; 
break; 
case 110: 
salida='n'; 
break; 
case 111: 
salida='o'; 
break; 
case 112: 
salida='p'; 
break; 
case 113: 
salida='q'; 
break; 
case 114: 
salida='r'; 
break; 
case 115: 
salida='s'; 
break; 
case 116: 
salida='t'; 
break; 
case 117: 
salida='u'; 
break; 
case 118: 
salida='v'; 
break; 
case 119: 
salida='w'; 
break; 
case 120: 
salida='x'; 
break; 
case 121: 
salida='y'; 
break; 
case 122: 
salida='z'; 
break; 
case 123: 
salida='{'; 
break; 
case 124: 
salida='|'; 
break; 
case 125: 
salida='}'; 
break; 
case 126: 
salida='~'; 
break; 




  }
  return salida;
}

