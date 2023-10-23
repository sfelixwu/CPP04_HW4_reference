
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
  std::string location_label;
 public:
  GPS_DD();
  GPS_DD(double, double);
  GPS_DD(double, double, std::string);
  void setLocationLabel(std::string);
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  Json::Value dump2JSON();
};

#endif /* _GPS_H_ */
