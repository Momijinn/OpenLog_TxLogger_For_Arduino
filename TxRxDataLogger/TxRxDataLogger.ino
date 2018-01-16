#include <SPI.h>
#include <SdFat.h>

#define FILE_BASE_NAME "Data"
// Error messages stored in flash.
#define error(msg) sd.errorHalt(F(msg))

// File system object.
SdFat sd;
// Log file.
SdFile file;


void setup() {
  const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
  char fileName[13] = FILE_BASE_NAME "00.txt";

  Serial.begin(115200);
  while (!Serial) {} // wait for Leonardo
  delay(100);

  // Initialize the SD card at SPI_HALF_SPEED to avoid bus errors with
  // breadboards.  use SPI_FULL_SPEED for better performance.
  // if (!sd.begin(chipSelect, SPI_HALF_SPEED)) {
  if (!sd.begin(chipSelect, SPI_FULL_SPEED)) {
    sd.initErrorHalt();
  }

  // Find an unused file name.
  //ファイルの作成
  if (BASE_NAME_SIZE > 6) {
    error("FILE_BASE_NAME too long");
  }
  while (sd.exists(fileName)) {
    if (fileName[BASE_NAME_SIZE + 1] != '9') {
      fileName[BASE_NAME_SIZE + 1]++;
    } else if (fileName[BASE_NAME_SIZE] != '9') {
      fileName[BASE_NAME_SIZE + 1] = '0';
      fileName[BASE_NAME_SIZE]++;
    } else {
      error("Can't create file name");
    }
  }
  if (!file.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
    error("file.open");
  }

  Serial.print(F("Logging to: "));
  Serial.println(fileName);
  Serial.println(F("Type!!"));

}

void loop() {
  //ファイルの書き込みエラー
  if (!file.sync() || file.getWriteError()) {
    error("write error");
  }

}

//Serial割り込み
void serialEvent(){
  String str = "";
  if (Serial.available() > 0){
    str = Serial.readStringUntil(';'); //wait終了文字列を入れる デフォルトで1secのTimeoutを持っている
  }
  Serial.println(str);
  // file.print(str);
  file.println(str);
}