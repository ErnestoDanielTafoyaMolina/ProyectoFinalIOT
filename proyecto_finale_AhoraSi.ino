#include <SoftwareSerial.h>
SoftwareSerial bt(10,11);//tx rx(y la conexion con el modulo hc05)
char letra;//va recibiendo letra por letra
String mensaje;// con la letra creara una cadena que sera el mensaje
int r=6;//luz roja en el pin 6
int g=5;// luz verde en el pin 5
int b=3;// luz azul en el pin 3
int sensor=A0;// recibir los datos del lmr35
int val,temp;//auxiliares para convertir los datos del lm35 a datos reales
void setup() {
  bt.begin(38400);//inicializamos el puerto bluethoot
  Serial.begin(9600);//iniciamos el serial
  pinMode(r,OUTPUT);//iniciamos la luz roja como salida
  pinMode(g,OUTPUT);//iniciamos la luz verde como salida
  pinMode(b,OUTPUT);//iniciamos la luz azul como salida
}

void loop() {
  while(bt.available()>0){//en esta linea formamos el mensaje
    letra=bt.read();
    mensaje+=letra;
   
  }
  if(mensaje.length()>0){// condicionales para ver en que color prenderá
     Serial.println(mensaje);
     if(mensaje=="r"){//prende la luz de color rojo 
      analogWrite(r,255);
      analogWrite(g,0);
      analogWrite(b,0);
     }
     if(mensaje=="g"){//prende la luz de color verde
      analogWrite(r,0);
      analogWrite(g,255);
      analogWrite(b,0);
     }
      if(mensaje=="b"){//prende la luz de color azul
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,255);
     }
     if(mensaje=="c"){//prende la luz de color cyan
      analogWrite(r,56);
      analogWrite(g,175);
      analogWrite(b,209);
     }
     if(mensaje=="m"){//prende la luz de color magenta
      analogWrite(r,109);
      analogWrite(g,66);
      analogWrite(b,155);
     }
     if(mensaje=="y"){//prende la luz de color amarillo
      analogWrite(r,242);
      analogWrite(g,236);
      analogWrite(b,22);
     }
     if(mensaje=="l"){//prende la luz de color lima
      analogWrite(r,161);
      analogWrite(g,206);
      analogWrite(b,55);
     }
     if(mensaje=="o"){//prende la luz de color naranja
      analogWrite(r,244);
      analogWrite(g,123);
      analogWrite(b,40);
     }
     if(mensaje=="ly"){//prende la luz de color naranja claro
      analogWrite(r,248);
      analogWrite(g,211);
      analogWrite(b,8);
     }
     if(mensaje=="gl"){//prende la luz de color verde claro
      analogWrite(r,249);
      analogWrite(g,161);
      analogWrite(b,27);
     }
     if(mensaje=="lb"){//prende la luz de color azul claro
      analogWrite(r,45);
      analogWrite(g,118);
      analogWrite(b,187);
     }
     if(mensaje=="w"){//prende la luz de color blanco
      analogWrite(r,255);
      analogWrite(g,255);
      analogWrite(b,255);
     }
     if(mensaje=="off"){//apaga las luces
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
     }
     mensaje="";//limpia el mensaje para recibir uno mas
  }
  
   val=analogRead(sensor);//lee el valor que hay en el sensor
   Serial.println(sensor);//imprime el valor en el monitor srial
   temp=val*5000*.0/1024/10;//convierte los valores a valores legibles
   Serial.println(temp);//imprime la temperatura
   bt.println(temp);//envia la temperatura a la aplicacion
   delay(1000);
}
