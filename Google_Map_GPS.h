
#ifndef _GOOGLE_MAP_GPS_H_
#define _GOOGLE_MAP_GPS_H_

// Google_Map_GPS.h

#include "Labeled_GPS.h"

// class Google_Map_GPS : virtual public Labeled_GPS

class Google_Map_GPS : public Labeled_GPS
{
 private:
 protected:
 public:
#ifndef _MEMORY_LAYOUT_
  std::string url;  
#else /* _MEMORY_LAYOUT_ */
#endif /* _MEMORY_LAYOUT_ */
  
  Google_Map_GPS();
#ifndef _MEMORY_LAYOUT_
  Google_Map_GPS(double, double, std::string);
#endif /* _MEMORY_LAYOUT_ */
  bool operator==(Google_Map_GPS&);

#ifndef _MEMORY_LAYOUT_
  void foo(void) { std::cout << "Google_Map_GPS\n"; }
  Json::Value nv_dump2JSON();
  virtual Json::Value dump2JSON();
  // Json::Value dump2JSON();
#endif /* _MEMORY_LAYOUT_ */
};

#endif /* _GOOGLE_MAP_GPS_H_ */
