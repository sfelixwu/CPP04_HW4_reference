
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

#include "ecs36b_Common.h"
using namespace std;

class GPS_DD
{
 private:
 protected:
  double latitude;
  double longitude;
 public:
  GPS_DD();
  GPS_DD(double, double);
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  bool operator==(GPS_DD& another);
  
  Json::Value nv_dump2JSON();
  virtual Json::Value dump2JSON();
};

#endif /* _GPS_H_ */
