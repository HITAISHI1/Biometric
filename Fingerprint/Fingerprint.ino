/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_Fingerprint.h>

// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
// #define mySerial Serial1

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;

void setup()  
{
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("\nFound fingerprint sensor!");
  } else {
    Serial.println("\nDid not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println("\n templates");
  Serial.println("\nWaiting for valid finger...");
}

uint8_t readnumber(void) {
  uint8_t num = 0;
  
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}
void loop()
{
  uint8_t num = 0;
  Serial.println("\nPress Enroll or Search!!!");
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  if(num==1)
    loop1();
  else if(num==2)
    loop2();
  else
    Serial.println("\nERROR!!!!!!");
   
}

void loop2()                     // run over and over again
{
  uint8_t p=100;
  uint8_t k=0;
  while(p!=FINGERPRINT_NOFINGER){
  p=getFingerprintIDez();
  if(Serial.available())
    k=Serial.parseInt();
   if(k==9)
    break;
  if(p==FINGERPRINT_OK)
    break;
  if(p==FINGERPRINT_PACKETRECIEVEERR)
    break;
  if(p==FINGERPRINT_IMAGEFAIL)
    break;
  delay(50);            //don't ned to run this at full speed.
  }
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImage taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("\nNo finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nCommunication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("\nImaging error");
      return p;
    default:
      Serial.println("\nUnknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImage converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("\nImage too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nCommunication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("\nCould not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("\nCould not find fingerprint features");
      return p;
    default:
      Serial.println("\nUnknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("\nFound a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("\nCommunication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("\nDid not find a match");
    return p;
  } else {
    Serial.println("\nUnknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
void loop1()                     // run over and over again
{
  Serial.println("\nReady to enroll a fingerprint!");
  Serial.println("\nPlease type in the ID # (from 1 to 127) you want to save this finger as...");
  id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);
  
  while (!  getFingerprintEnroll() );
}

uint8_t getFingerprintEnroll() {

  int p = -1;
  Serial.println("\nWaiting for valid finger to enroll as #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImage taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println("\n.");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nCommunication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("\nImaging error");
      break;
    default:
      Serial.println("\nUnknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImage converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("\nImage too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nCommunication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("\nCould not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("\nCould not find fingerprint features");
      return p;
    default:
      Serial.println("\nUnknown error");
      return p;
  }
  
  Serial.println("\nRemove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("\nPlace same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImage taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nCommunication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("\nImaging error");
      break;
    default:
      Serial.println("\nUnknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("\nImage converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("\nImage too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("\nCommunication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("\nCould not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("\nCould not find fingerprint features");
      return p;
    default:
      Serial.println("\nUnknown error");
      return p;
  }
  
  // OK converted!
  Serial.print("Creating model for #");  Serial.println(id);
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("\nPrints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("\nCommunication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("\nFingerprints did not match");
    return p;
  } else {
    Serial.println("\nUnknown error");
    return p;
  }   
  
  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("\nStored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("\nCommunication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("\nCould not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("\nError writing to flash");
    return p;
  } else {
    Serial.println("\nUnknown error");
    return p;
  }   
}
