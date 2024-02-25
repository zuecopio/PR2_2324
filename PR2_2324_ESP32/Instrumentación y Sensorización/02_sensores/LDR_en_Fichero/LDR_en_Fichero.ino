/*-----------------------------------------------------+
 |     L D R _ E N _ F I C H E R O . I N O             |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/
 
#include "sd_read_write.h"
#include "SD_MMC.h"
#define SD_MMC_CMD 38 /* Please do not modify it. */
#define SD_MMC_CLK 39 /* Please do not modify it. */ 
#define SD_MMC_D0  40 /* Please do not modify it. */
#define PIN_ANALOG_IN 1

int contador = 0;

void setup(void)
{
    Serial.begin(115200);
    SD_MMC.setPins(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0);
    
    if (!SD_MMC.begin("/sdcard", true, true, SDMMC_FREQ_DEFAULT, 5))
    {
      Serial.println("Card Mount Failed");
      return;
    }
    
    uint8_t cardType = SD_MMC.cardType();
    
    if (cardType == CARD_NONE)
    {
        Serial.println("No SD_MMC card attached");
        return;
    }

    Serial.print("SD_MMC Card Type: ");
    
    if (cardType == CARD_MMC)
    {
        Serial.println("MMC");
    }
    else if (cardType == CARD_SD)
    {
        Serial.println("SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
        Serial.println("SDHC");
    }
    else
    {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
    Serial.printf("SD_MMC Card Size: %lluMB\n", cardSize);

    createDir(SD_MMC, "/pruebasLDR");
    listDir(SD_MMC, "/", 0);
    writeFile(SD_MMC, "/pruebasLDR/test_LDR2.txt", "Valores LDR\n");

} /* setup() */

void loop(void)
{
	char * str_cont  = "";  /* Cadena donde almacenaremos el contador         */
	char * str_valor = "";  /* Cadena donde almacenaremos el valor convertido */

	sprintf(str_cont,"%d",contador);
	appendFile(SD_MMC, "/pruebasLDR/test_LDR2.txt",str_cont);
	appendFile(SD_MMC, "/pruebasLDR/test_LDR2.txt",";");
	int adcVal = analogRead(PIN_ANALOG_IN); /* read adc */
	sprintf(str_valor,"%d\n",adcVal);
	appendFile(SD_MMC, "/pruebasLDR/test_LDR2.txt",str_valor);
	Serial.println(str_valor);
	contador++;
	delay(100);

} /* loop() */

/*** end of file ***/
