
#include "sd_read_write.h"
#include "SD_MMC.h"

#define trigPin 13 // define TrigPin
#define echoPin 14 // define EchoPin.
#define MAX_DISTANCE 700 // Maximum sensor distance is rated at 400-500cm.

#define SD_MMC_CMD 38 //Please do not modify it.
#define SD_MMC_CLK 39 //Please do not modify it. 
#define SD_MMC_D0  40 //Please do not modify it.
#define PIN_ANALOG_IN   1
int contador=0;
//timeOut= 2*MAX_DISTANCE /100 /340 *1000000 = MAX_DISTANCE*58.8
float timeOut = MAX_DISTANCE * 60; 
int soundVelocity = 340; // define sound speed=340m/s
float distancia=0.0;
void setup() {
  pinMode(trigPin,OUTPUT);// set trigPin to output mode
  pinMode(echoPin,INPUT); // set echoPin to input mode
  Serial.begin(115200);   // Open serial monitor at 115200 baud to see ping results.
  SD_MMC.setPins(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0);
    if (!SD_MMC.begin("/sdcard", true, true, SDMMC_FREQ_DEFAULT, 5)) {
      Serial.println("Card Mount Failed");
      return;
    }
    uint8_t cardType = SD_MMC.cardType();
    if(cardType == CARD_NONE){
        Serial.println("No SD_MMC card attached");
        return;
    }

    Serial.print("SD_MMC Card Type: ");
    if(cardType == CARD_MMC){
        Serial.println("MMC");
    } else if(cardType == CARD_SD){
        Serial.println("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
    Serial.printf("SD_MMC Card Size: %lluMB\n", cardSize);

    createDir(SD_MMC, "/pruebasUS");
    listDir(SD_MMC, "/", 0);
    writeFile(SD_MMC, "/pruebasUS/test_US.txt", "Valores US\n");
}

void loop() {
  char* str_cont="";  //Cadena donde almacenaremos el contador
  char* str_valor="";  //Cadena donde almacenaremos el valor convertido
  delay(100); // Wait 100ms between pings (about 20 pings/sec). 
  sprintf(str_cont,"%d",contador);
  appendFile(SD_MMC, "/pruebasUS/test_US.txt",str_cont);
  appendFile(SD_MMC, "/pruebasUS/test_US.txt",";");
  Serial.printf("Distance: ");
  distancia=getSonar();
  sprintf(str_valor,"%f\n",distancia);
  appendFile(SD_MMC, "/pruebasUS/test_US.txt",str_valor);
  Serial.print(distancia); // Send ping, get distance in cm and print result 
  Serial.println("cm");
  contador++;
}

float getSonar() {
  unsigned long pingTime;
  float distance;
  // make trigPin output high level lasting for 10μs to triger HC_SR04
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Wait HC-SR04 returning to the high level and measure out this waitting time
  pingTime = pulseIn(echoPin, HIGH, timeOut); 
  // calculate the distance according to the time
  distance = (float)pingTime * soundVelocity / 2 / 10000; 
  return distance; // return the distance value
}
