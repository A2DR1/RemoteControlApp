/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 48 bytes
  { 255,3,0,0,0,41,0,19,0,0,0,77,65,82,66,76,69,0,5,1,
  200,84,1,1,2,0,5,13,2,75,75,32,2,26,31,1,114,6,66,66,
  0,2,31,74,85,77,80,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_01_x; // from -100 to 100
  int8_t joystick_01_y; // from -100 to 100
  uint8_t button_01; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#define PIN_MOTOR_RIGHT D10
#define PIN_MOTOR_LEFT D0

int RightMotor = PIN_MOTOR_RIGHT;
int LeftMotor = PIN_MOTOR_LEFT;

void Wheel (int motor, int v)
{
  if (v>100) v=100;
  if (v<-100) v=-100;
  if (v>0) {
    analogWrite(motor, v*2.55);
  }
  else {
    analogWrite(motor, 0);
  }
}

void setup() 
{
  pinMode (PIN_MOTOR_RIGHT, OUTPUT);
  pinMode (PIN_MOTOR_LEFT, OUTPUT);

  /* initialization module RemoteXY */
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
  Wheel (RightMotor, RemoteXY.joystick_01_y - RemoteXY.joystick_01_x);
  Wheel (LeftMotor, RemoteXY.joystick_01_y + RemoteXY.joystick_01_x);

}