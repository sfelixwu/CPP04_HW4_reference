
// test_Labeled_GPS.cpp

#include "Labeled_GPS.h"

int
main(int argc, char *argv[])
{
  // if (argc != 3) return -1;

  Labeled_GPS gps_Home_Woodland { 38.672215864622636, -121.72280111121437, "Costco, Woodland" };
  Labeled_GPS gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306, "Teaching and Learning Complex" };
  Labeled_GPS gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501, "IKEA, West Sacramento" };

  // calling different foo's
  gps_TLC_UCDavis.foo();
  ((GPS_DD&) gps_TLC_UCDavis).foo();

  // move up and down with reference
  GPS_DD& gps_ref = (GPS_DD&) gps_TLC_UCDavis;
  Labeled_GPS& labeled_ref_1 = (Labeled_GPS&) gps_ref;

  std::cout << gps_TLC_UCDavis.label << std::endl;
  // move up with copy and down with reference
  GPS_DD gps_copy = (GPS_DD) gps_TLC_UCDavis;
  // error => Labeled_GPS labeled_copy_1 = (Labeled_GPS) gps_copy;
  Labeled_GPS labeled_copy_1 = (Labeled_GPS&) gps_copy;
  std::cout << labeled_copy_1.label << std::endl;

  GPS_DD gps_Test { 38.672215864622636, -121.72280111121437 };
  Labeled_GPS& labeled_ref_2 = (Labeled_GPS&) gps_Test;

  Json::Value x;
  x = gps_IKEA_Sacramento.dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  GPS_DD * gps_ptr;
  gps_ptr = ((GPS_DD *) (&gps_IKEA_Sacramento));
  x = gps_ptr->dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  x = gps_ptr->nv_dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  x = ((GPS_DD&) gps_IKEA_Sacramento).nv_dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  x = ((GPS_DD&) gps_IKEA_Sacramento).dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  return 0;
}
