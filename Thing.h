
#ifndef _THING_H_
#define _THING_H_

// Thing.h
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"
using namespace std;

class Thing
{
 private:
 protected:
 public:
  
  std::string model;
  std::string sequence_num;
  std::string description;
  Person      owner;
  JvTime      purchased;
  JvTime      sold;
  GPS_DD      location;
  
  Thing(void);
  explicit Thing(Person arg_owner);
  void dump(); // print the content of the object
  Json::Value dump2JSON();
};

#endif /* _THING_H_ */
