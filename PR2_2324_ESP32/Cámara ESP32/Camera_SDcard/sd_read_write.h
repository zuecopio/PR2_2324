/*-----------------------------------------------------+
 |     S D _ R E A D _ W R I T E . H                   |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Cámara y visión en el ESP32       |
 +-----------------------------------------------------*/

#ifndef __SD_READ_WRITE_H
#define __SD_READ_WRITE_H

#include "Arduino.h"
#include "FS.h"
#include "SD_MMC.h"

#define SD_MMC_CMD  38 /* Please do not modify it. */
#define SD_MMC_CLK  39 /* Please do not modify it. */ 
#define SD_MMC_D0   40 /* Please do not modify it. */

void sdmmcInit(void); 

void listDir(fs::FS & fs, const char * dirname, uint8_t levels);
void createDir(fs::FS & fs, const char * path);
void removeDir(fs::FS & fs, const char * path);
void readFile(fs::FS & fs, const char * path);
void writeFile(fs::FS & fs, const char * path, const char * message);
void appendFile(fs::FS & fs, const char * path, const char * message);
void renameFile(fs::FS & fs, const char * path1, const char * path2);
void deleteFile(fs::FS & fs, const char * path);
void testFileIO(fs::FS & fs, const char * path);

void writejpg(fs::FS & fs, const char * path, const uint8_t * buf, size_t size);
int readFileNum(fs::FS & fs, const char * dirname);

#endif /* __SD_READ_WRITE_H */

/*** end of file ***/