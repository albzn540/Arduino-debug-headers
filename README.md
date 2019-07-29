# Arduino debug headers

For easier Arduino debugging.

## How to install
Stand in your platformio project root and run the following commands.  
```sh
$ wget https://raw.githubusercontent.com/albzn540/Arduino-debug-headers/master/install.sh
```  
```sh
$ chmod +x install.sh
```  
```sh
$ ./install.sh
```

## How to use

In your src/main.cpp file  
``` cpp
#include "Logger.cpp"

void testFunction() { // Function you want to debug
  Debugf("Debug message\n");
  // "Debug message"

  DebuFunc("Debug message\n");
  // "[testFunction()] Debug message"

  Err("Error message");
  // ERROR: Error message

  ErrFunc("Error message\n");
  // ERROR: [testFunction] Error message 
}

void setup() {
  // Initialize debugger
  DebugInit(115200);
}
```