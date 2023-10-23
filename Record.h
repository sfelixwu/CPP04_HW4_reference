
#ifndef _RECORD_H_
#define _RECORD_H_

// Record.h

#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

// instructional objective for HW2 --

// (1) std::vector
// std::vector is part of the Standard Template Library in C++
// reference -- https://cplusplus.com/reference/vector/vector/
// std::vector<[type of the elements]> [vector variable name];

// (2) design a bunch of classes for a "story/description"
// NL => Objects
// trade-offs in Object-Oriented Design

// (3) separate compilation or why Record.h and Record.cpp?
// and, how will Makefile/make help to realize that?

// (4) the basic idea of JSON (Javascript Object Notation)
// a linearized representation of object(s)

// (4.5) why do we need the "dump" functionality in OOP?

// (5) installation of library such as JSONCPP
// and, how to set -I and -L flags to find those files?
// useful tool to find the successfully installed files --
// $ sudo find / -name json -print

class Record
{
 private:
  // original: Person who;
  std::vector<Person> who_persons; // #1
  
  // original: Thing what; // one thing
  // how do we represent multiple things?
  // vector is C++ std template for array
  std::vector<Thing> what_things;  // #2
  // std::vector<Thing *> what_things;  // #2

  // Bus_Stop where; // location (event at one particular loaction) #3
  GPS_DD where; // location (event at one particular loaction) #3
  JvTime when;  // one particular event, one particular time point #4
  // extension -- a Record, correlating an event across multiple locations and times
  
public:
  Record();
  
  void addWho(Person _p);
  void setWho(std::vector<Person> _vp);
  void addWhat(Thing _t);
  void setWhat(std::vector<Thing> _vt);
  
  void setWhere(GPS_DD);
  void setWhen(JvTime);
  
  Json::Value dump2JSON();
};

#endif  /* _RECORD_H_ */
