
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

using namespace std;

class Person
{
 private:
  std::string SSN;
  std::string name;
  GPS_DD home;
  GPS_DD location;
  JvTime since_when;
  
public:
  Person(std::string, std::string, GPS_DD);
  Person();
  void setHome(GPS_DD);
  void setLocation(GPS_DD, JvTime);

  bool operator==(Person& aPerson);
  std::string getSSN();
  std::string getName();
  GPS_DD getHome();
  GPS_DD& getLocation();
  JvTime getLocationTime();
  void dump();
  Json::Value dump2JSON();
};

#endif  /* _PERSON_H_ */
