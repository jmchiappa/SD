
#include <SPI.h>
#include <SD.h>

#define SD_MISO  D29
#define SD_MOSI  D17
#define SD_SCK   D16
#define SD_CSn   D30

// SPI3 of NUCLEO L476RG (without SSn)

SPIClass mySPI(SD_MOSI,SD_MISO,SD_SCK);

uint32_t FULL_SPEED  = 4000000; // 4MHz

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(mySPI,FULL_SPEED,SD_CSn)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    for(uint i=0;i<255;i++) {
      dataFile.println("coordonnées : toto");
    }
    dataFile.close();
    Serial.println("batch written");
}
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}









