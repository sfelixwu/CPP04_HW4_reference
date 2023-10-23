
#ifndef _LABELED_GPS_H_
#define _LABELED_GPS_H_

// Labeled_GPS.h

// Instructional Plan --
// Inheritance ==> Is-A relationship among classes

// GPS: the parent class
// Labeled_GPS: the derived/child class
// a Labeled_GPS object "is a" GPS object.
// features: constructor, casting (moving up and down in the inheritance hierarchy) 

// today -- single inheritance, constructors, casting, virtual functions, operator-overloading

// Comparison ==>
// C++:    Single, Multiple, Virtual
// Java:   Single (but it has the Interface feature to handle MI)
// Python: Single, Multiple (but it is equivalent to Virtual Inheritance in C++)

// uncertainty in object-oriented programming
// such that we HAVE TO "guess and verify", even for experienced programmers --

// (1) operator overloading
// Are you sure about the semantics of the operators?

// (2) inheritance (signle, multiple, virtual)
// Is this member function defined in the current class or by one of the ancesters?

// (3) polymorphism (virtual functions in C++)
// Do you even know what is the "current" class?

// AFTER all the above, we will talke about

	     // Multiple Inheritance
	     // Virtual Inheritance
	     // Object Memory Layout
	     // JSONRPC and Proxy Objects

#include "GPS.h"

class Labeled_GPS : GPS_DD
{
 private:
 protected:
 public:
  std::string label;
  Labeled_GPS();
  Labeled_GPS(double, double, std::string);

  bool operator==(Labeled_GPS&);
  Json::Value nv_dump2JSON();
  virtual Json::Value dump2JSON();
};

#endif /* _LABELED_GPS_H_ */
