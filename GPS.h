
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#ifndef _MEMORY_LAYOUT_
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

#include "ecs36b_Common.h"
using namespace std;
#endif /* _MEMORY_LAYOUT_ */

class GPS_DD
{
 private:
 protected:
 public:
  double latitude;
  double longitude;

  GPS_DD();
  GPS_DD(double, double);
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  bool operator==(GPS_DD& another);
  
#ifndef _MEMORY_LAYOUT_
  void foo(void) { std::cout << "GPS_DD\n"; }
  Json::Value nv_dump2JSON();
  // Json::Value dump2JSON();
  virtual Json::Value dump2JSON();
#endif /* _MEMORY_LAYOUT_ */
};

#endif /* _GPS_H_ */
