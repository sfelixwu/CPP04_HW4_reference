
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
	     // why do we need casting?
	     // moving up and down from IH

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


// Questions from the 10/23/2023 lecture
// (1) How to define a Single Inheritance relationship? [public, protected, private, virtual]
// (2) How to move "up and down" from a Single Inheritance Hierarchy?
// ==> cast up via reference (casting is done by the compiler, NOT run-time !!!)
// ==> cast down via reference if it is Single Inheritance
// ==> you cannot cast down at all if it is Virtual Inheritance

// (3) How are objects, including those inherited components, allocated in memory?
// (4) What is a virtual function?
	     // virtual table pointer
// (4.5) Or, what is the difference between the object creation time and the object access time?
// The above questions are pretty much all we need to worry for midterm #3.

#include "GPS.h"

// class Labeled_GPS : virtual public GPS_DD

class Labeled_GPS : public GPS_DD
{
 private:
 protected:
 public:
#ifndef _MEMORY_LAYOUT_
  std::string label;
#else /* _MEMORY_LAYOUT_ */
  double label;  
#endif /* _MEMORY_LAYOUT_ */
  
  Labeled_GPS();
#ifndef _MEMORY_LAYOUT_
  Labeled_GPS(double, double, std::string);
#endif /* _MEMORY_LAYOUT_ */
  bool operator==(Labeled_GPS&);

#ifndef _MEMORY_LAYOUT_
  void foo(void) { std::cout << "Label_GPS\n"; }
  Json::Value nv_dump2JSON();
  virtual Json::Value dump2JSON();
  // Json::Value dump2JSON();
#endif /* _MEMORY_LAYOUT_ */
};

#endif /* _LABELED_GPS_H_ */
