
#include "Labeled_GPS.h"

Labeled_GPS::Labeled_GPS
()
{
  this->label = "default";
}

Labeled_GPS::Labeled_GPS
(double arg_latitude, double arg_longitude, std::string arg_label)
  : GPS_DD(arg_latitude, arg_longitude)
{
  this->label = arg_label;
}

bool
Labeled_GPS::operator==
(Labeled_GPS& another)
{
  return((this->latitude == another.getLatitude()) &&
	 (this->longitude == another.getLongitude()) &&
	 (this->label == another.label));
}

Json::Value
Labeled_GPS::dump2JSON
()
{
  // option #1
  // v-table pointer will link to the class GPS_DD (becuase of object creation)
  // GPS_DD parent_copy = (*this);
  // parent_copy is a GPS_DD object without the Labeled_GPS derived portion
  // Json::Value result = parent_copy.dump2JSON();

  // option #2
  // force the compiler to link to the parent version of dump2JSON()
  Json::Value result = this->GPS_DD::dump2JSON();

  // the following is a wrong option
  // Json::Value result = ((GPS_DD *) this)->dump2JSON();
  // Json::Value result = ((GPS_DD&) (*this)).dump2JSON();
  // Json::Value result = (*((GPS_DD *) this)).dump2JSON();
  
  if (this->label != "default")
    {
      result["label"] = this->label;
    }

  // std::cout << result.toStyledString() << std::endl;
  return result;
}

Json::Value
Labeled_GPS::nv_dump2JSON
()
{
  GPS_DD parent_copy = (*this);
  Json::Value result = parent_copy.dump2JSON();
  
  if (this->label != "default")
    {
      result["label"] = this->label;
    }

  // std::cout << result.toStyledString() << std::endl;
  return result;
}
