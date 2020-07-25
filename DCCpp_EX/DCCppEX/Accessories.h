/**********************************************************************

Accessories.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ EX BASE STATION for the Arduino

**********************************************************************/

#include <Arduino.h>

#ifndef Accessories_h
#define Accessories_h

struct TurnoutData {
  byte tStatus;
  byte subAddress;
  int id;
  int address;  
};

struct Turnout{
  static Turnout *firstTurnout;
  int num;
  struct TurnoutData data;
  Turnout *nextTurnout;
  void activate(int s);
  static void parse(const char *c);
  static Turnout* get(int);
  static void remove(int);
  static void load();
  static void store();
  static Turnout *create(int, int, int, int=0);
  static void show(int=0);
}; // Turnout
  
void sendMessage(uint16_t to_node, char *data, unsigned int bytes); //RF24
void sendPacket(uint16_t to_node, String function, String option, String data);

const uint16_t this_node = 05;   // Node address referenced in networkFunctions.h
const uint16_t master_node00 = 00; 

#endif


