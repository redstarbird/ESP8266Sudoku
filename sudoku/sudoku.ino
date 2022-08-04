#include <ESP8266WiFi.h>
#include <FS.h>
#include <String.h>

int Grid[9][9];
int AnswerGrid[9][9];

bool isValidSquare(int num, int row, int col) {
  return true;
}

void setup() {
  randomSeed(millis() + analogRead(1));

  int row, col;
  WiFi.mode(WIFI_OFF); // saves power
  int fileNum = random(1, 51);
  if (SPIFFS.begin()) {
    File f = SPIFFS.open("Puzzle" + String(fileNum) + ".txt", "r");
    if (!f) {
      ESP.restart(); // restart if file cannot be opened
    }
    else {
      int currentNum;
      for (int i = 0; i < 9) {
        for (int j = 0; j < 9) {
          currentNum = ((char)f.read()) - '0';
          Grid[i][j] = currentNum;
        }
      }
    }
  }
  else {
    ESP.restart();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
