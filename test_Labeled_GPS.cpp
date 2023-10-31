
// test_Labeled_GPS.cpp

#include "Labeled_GPS.h"

int
main(int argc, char *argv[])
{
  // if (argc != 3) return -1;

  Labeled_GPS gps_Home_Woodland { 38.672215864622636, -121.72280111121437, "Costco, Woodland" };
  Labeled_GPS gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306, "Teaching and Learning Complex" };
  Labeled_GPS gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501, "IKEA, West Sacramento" };

  GPS_DD gps1 { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps2 { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps3 { 38.672215864622636, -121.72280111121437 };

  std::vector<GPS_DD *> gps_vector;
  gps_vector.push_back(&gps_Home_Woodland);
  gps_vector.push_back(&gps_TLC_UCDavis);
  gps_vector.push_back(&gps_IKEA_Sacramento);
  gps_vector.push_back(&gps1);
  gps_vector.push_back(&gps2);
  gps_vector.push_back(&gps3);  
  
  // calling different foo's
  // gps_TLC_UCDavis->foo();
  gps_TLC_UCDavis.foo();
  ((GPS_DD&) gps_TLC_UCDavis).foo();
  // there are multiple reasons for casting up, but if we only want to invoke the function
  gps_TLC_UCDavis.GPS_DD::foo();

  std::cout << std::endl;
  std::cout << "before\n";
  std::cout << "label     content = " <<   gps_TLC_UCDavis.label      << std::endl;
  std::cout << "label     address = " << &(gps_TLC_UCDavis.label)     << std::endl;
  std::cout << "longitude address = " << &(gps_TLC_UCDavis.longitude) << std::endl;
  std::cout << "latitude  address = " << &(gps_TLC_UCDavis.latitude)  << std::endl;

  // move up and down with reference
  std::cout << std::endl;
  std::cout << gps_TLC_UCDavis.label << std::endl;

  std::cout << std::endl;
  std::cout << "before type casting to the base class using reference\n";
  std::cout << "object    address = " <<   &gps_TLC_UCDavis       << std::endl;
  GPS_DD& gps_ref = (GPS_DD&) gps_TLC_UCDavis;

  std::cout << std::endl;  
  std::cout << "after type casting to the base class using reference\n";
  // BTW, below, you can only use &gps_ref, NOT gps_ref.
  std::cout << "object    address = " <<   &gps_ref      << std::endl;
  Labeled_GPS& labeled_ref_1 = (Labeled_GPS&) gps_ref;
  std::cout << std::endl;
  std::cout << labeled_ref_1.label << std::endl;

  std::cout << std::endl;
  std::cout << "after up and down via reference\n";
  std::cout << "label     content = " <<   labeled_ref_1.label      << std::endl;
  std::cout << "label     address = " << &(labeled_ref_1.label)     << std::endl;
  std::cout << "longitude address = " << &(labeled_ref_1.longitude) << std::endl;
  std::cout << "latitude  address = " << &(labeled_ref_1.latitude)  << std::endl;

  // Thing -> IOT_Thing
  // Thing -> Food

  // move up with copy and down with reference
  GPS_DD gps_copy = (GPS_DD) gps_TLC_UCDavis;
  std::cout << std::endl;
  std::cout << "after type casting to the base class using copy\n";
  std::cout << "object    address = " <<   &gps_copy      << std::endl;
  // error => Labeled_GPS labeled_copy_1 = (Labeled_GPS) gps_copy;
  Labeled_GPS labeled_copy_1 = (Labeled_GPS&) gps_copy;

  std::cout << std::endl;
  std::cout << "after up via copy and down via reference\n";
  std::cout << "label     content = " <<   labeled_copy_1.label      << std::endl;
  std::cout << "label     address = " << &(labeled_copy_1.label)     << std::endl;
  std::cout << "longitude address = " << &(labeled_copy_1.longitude) << std::endl;
  std::cout << "latitude  address = " << &(labeled_copy_1.latitude)  << std::endl;

  GPS_DD gps_Test { 38.672215864622636, -121.72280111121437 };
  Labeled_GPS& labeled_ref_2 = (Labeled_GPS&) gps_Test;

  // ==> starting here 10/30/2023
  
  Json::Value x;
  x = gps_IKEA_Sacramento.dump2JSON();
  std::cout << x.toStyledString() << std::endl; // three lines

  GPS_DD * gps_ptr;
  gps_ptr = ((GPS_DD *) (&gps_IKEA_Sacramento));
  // x = gps_ptr->dump2JSON();
  x = (*gps_ptr).dump2JSON();
  std::cout << "pointer: \n" << x.toStyledString() << std::endl; // three lines

  GPS_DD gps_copy_2;
  gps_copy_2 = gps_IKEA_Sacramento;
  x = gps_copy_2.dump2JSON();
  std::cout << "copy: \n" << x.toStyledString() << std::endl; // two lines
  
  x = gps_ptr->nv_dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  x = ((GPS_DD&) gps_IKEA_Sacramento).nv_dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  x = ((GPS_DD&) gps_IKEA_Sacramento).dump2JSON();
  std::cout << "reference: \n" << x.toStyledString() << std::endl;

  return 0;
}
