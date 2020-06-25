#include <SD.h>
#include <SoftwareSerial.h>

SoftwareSerial camPort(2,3);
#define BUF_SIZE 56 // 32
uint8_t KH=0x00,KL=0x38; // KL=0x20;
int readDelay = 5;
byte incomingbyte;
int address=0x0000;

int fileIndex = 0;
int fileMax = 500;
int loopContinue = 0;
int sendImage = 0;

void setup() {
  Serial.begin(57600);
  
  serialPrint("Initializing SD card...");
  if (!SD.begin(10)) {
    serialPrintln("failed!");
    return;
  }
  serialPrintln("done.");

  camPort.begin(38400); delay(25);
  
  serialPrint("Resetting camera...");
  cmdReset(); delay(3000); consumeCamPort();

  serialPrint("Changing baudrate...");
  cmdBaudRate19200();
  camPort.end();

  serialPrint("Reconnecting camera...");
  camPort.begin(19200); delay(25); consumeCamPort();
  serialPrintln("done.");
  
  loopContinue = 1;
}

void loop() {
  char dirName[6], fileName[20];
  if (loopContinue>0) {
    do {
      sprintf(dirName,"cam%03d",fileIndex/fileMax);
      if (SD.exists(dirName)==false) {
        SD.mkdir(dirName); 
        serialPrint("Making directory "); serialPrintln(dirName);
      }
      sprintf(fileName,"cam%03d/img%05d.jpg",fileIndex/fileMax,fileIndex++);
    } while (SD.exists(fileName));
    
    File sdFile = SD.open(fileName, FILE_WRITE);
    if (sdFile) { // suceeded to open file
      serialPrint("Succeeded to open "); serialPrintln(fileName);
    
      serialPrint("Taking a photo...");
      cmdTakePhoto();
      byte returnCode[10];
      int returnCount = readCamPort(returnCode);
      if (returnCount!=5||returnCode[0]!=0x76||returnCode[1]!=0x00||
          returnCode[2]!=0x36||returnCode[3]!=0x00||returnCode[4]!=0x00) {
        serialPrintln(" ERROR(incorrect return code)");
        loopContinue = -1;
        return;
      }
      serialPrintln("done.");

      byte buf[BUF_SIZE];
      serialPrint("Reading and writing data..");
      int i=0, endFlag=0;
      while(!endFlag) {
        cmdReadData();
        if (i%10==0) { serialPrint("."); }
        int j=0, k=0, count=0;
        delay(readDelay);
        while(camPort.available()>0) {
          incomingbyte=camPort.read();
          k++;
          if((k>5)&&(j<BUF_SIZE)&&(!endFlag)) {
            buf[j]=incomingbyte;
            if(j>1&&(buf[j-1]==0xFF)&&(buf[j]==0xD9))
              endFlag=1;
            j++; count++;
          }
        }
        for(j=0;j<count;j++){
          sdFile.write((uint8_t)buf[j]);
        }
        if (sendImage) Serial.write(buf,count);
        i++;
      }
      sdFile.close();
      serialPrintln("done.");

      serialPrint("Stop taking a photo...");
      cmdStopPhoto();
      returnCount = readCamPort(returnCode);
      if (returnCount!=5||returnCode[0]!=0x76||returnCode[1]!=0x00||
          returnCode[2]!=0x36||returnCode[3]!=0x00||returnCode[4]!=0x00) {
        serialPrintln(" ERROR(incorrect return code)");
        loopContinue = -1;
        return;
      }
      serialPrintln("done.");
    } else {
      serialPrint("Error: failed to open "); serialPrintln(fileName);
      loopContinue = -1;
    }
    
    delay(50);
  }
}
void cmd(byte value) {
  camPort.write((uint8_t)value);
}
void cmdReset() {
  cmd(0x56); cmd(0x00); cmd(0x26); cmd(0x00);
}
void cmdTakePhoto() {
  address=0x0000;
  cmd(0x56); cmd(0x00); cmd(0x36); cmd(0x01); cmd(0x00);
  delay(25);
}
void cmdReadData() {
  uint8_t MH,ML;
  MH=address/0x100; ML=address%0x100;
  cmd(0x56); cmd(0x00); cmd(0x32); cmd(0x0c); cmd(0x00); cmd(0x0a); cmd(0x00); cmd(0x00);
  cmd(MH); cmd(ML); cmd(0x00); cmd(0x00); cmd(KH); cmd(KL); cmd(0x00); cmd(0x0a);
  address+=(BUF_SIZE);
}
void cmdStopPhoto() {
  cmd(0x56); cmd(0x00); cmd(0x36); cmd(0x01); cmd(0x03);
  delay(25);
}
void cmdImageSize320x240() {
  cmd(0x56); cmd(0x00); cmd(0x31); cmd(0x05); cmd(0x04); cmd(0x01); cmd(0x00);
  cmd(0x19); cmd(0x11);
  delay(25);
}
void cmdBaudRate19200() {
  cmd(0x56); cmd(0x00); cmd(0x24); cmd(0x03); cmd(0x01); cmd(0x56); cmd(0xE4);
  delay(25);
}
void cameraResolution() {
  serialPrint("Changing resolution...");
  cmdImageSize320x240();
  while(camPort.available()>0) {
    incomingbyte=camPort.read();
    //if(incomingbyte<0x10) Serial.print("0");
    //Serial.print(incomingbyte,HEX); Serial.print(" ");
  }   
  serialPrintln("done");
}
void consumeCamPort() {
  while(camPort.available()>0) {
    incomingbyte=camPort.read();
  }   
}

// read camera port and store
int readCamPort(byte * returnCode) {
  int returnIdx=0;
  while(camPort.available()>0) {
    incomingbyte=camPort.read();
    returnCode[returnIdx++]=incomingbyte;
  }
  return returnIdx;
}

void serialPrint(String text) {
  if (!sendImage)
    Serial.print(text);
}

void serialPrintln (String text) {
  if (!sendImage)
    Serial.println(text);
}
