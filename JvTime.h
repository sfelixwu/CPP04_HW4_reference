
#ifndef _JVTIME_H_
#define _JVTIME_H_

#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <exception> 
#include <time.h>

#include "ecs36b_Common.h"

using namespace std;

class JvTime
{
 private:
 protected:
 public:
  bool good;
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  char tail4[64];

  JvTime(const char *);
  JvTime() { }
  struct std::tm * getStdTM(void);
  int setStdTM(struct std::tm *);
  std::string * getTimeString(void);
  Json::Value dump2JSON();
};

JvTime *getNowJvTime(void);

#endif /* _JVTIME_H_ */
