#ifndef LOGGER_H_
#define LOGGER_H_

#include <Arduino.h>

// Define debug and log port
#define DEBUG_PORT

// Define wanted debug levels
#define ERROR_ENABLED
#define DEBUG_ENABLED

#ifdef DEBUG_PORT
  #define DebugInit(baud) Serial.begin(baud)
#else
  #define DebugInit(baud)
#endif

/******************** Debug levels ********************/
#ifdef ERROR_ENABLED
  #define Err(...)     do { Serial.print("ERROR: "); Serial.printf(__VA_ARGS__); } while (0)
  #define ErrFunc(...) do { Serial.print("ERROR: ["); Serial.print(__PRETTY_FUNCTION__); Serial.print("] "); Serial.printf(__VA_ARGS__); } while (0)
#else
  #define Err(...)
  #define ErrFunc(...)
#endif

#ifdef DEBUG_ENABLED
  #define Debugf(...)    Serial.printf( __VA_ARGS__ )
  #define DebugFunc(...) do { Serial.print("["); Serial.print(__PRETTY_FUNCTION__); Serial.print("] "); Serial.printf(__VA_ARGS__); } while (0)
#else
  #define Debugf(...)
  #define DebugFunc(...)
#endif

void chipInformation() {
  Serial.println();
  Serial.print( F("Heap: ") );  Serial.println(ESP.getFreeHeap());
  Serial.print( F("Boot Vers: ") );  Serial.println(ESP.getBootVersion());
  Serial.print( F("CPU: ") );  Serial.println(ESP.getCpuFreqMHz());
  Serial.print( F("SDK: ") );  Serial.println(ESP.getSdkVersion());
  Serial.print( F("Chip ID: ") );  Serial.println(ESP.getChipId());
  Serial.print( F("Flash ID: ") );  Serial.println(ESP.getFlashChipId());
  Serial.print( F("Flash Size: ") );  Serial.println(ESP.getFlashChipRealSize());
  Serial.print( F("Vcc: ") );  Serial.println(ESP.getVcc());
  Serial.println();
}

#endif // LOGGER_H_