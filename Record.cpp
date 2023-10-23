
#include "Record.h"

Record::Record()
{
}

void
Record::addWho
(Person _p)
{
  (this->who_persons).push_back(_p);
}

void
Record::addWhat
(Thing _t)
{
  (this->what_things).push_back(_t);
}

void
Record::setWho(std::vector<Person> _vp)
{
  this->who_persons = _vp;
}

void
Record::setWhat(std::vector<Thing> _vt)
{
  this->what_things = _vt;
}

void
Record::setWhere(GPS_DD _g)
{
  this->where = _g;
}

void
Record::setWhen(JvTime _jt)
{
  this->when = _jt;
}

// we did talk about the difference between passing by value and passing by reference/pointer
// But, at this moment, we will only use call by value

// JSON syntax --
//    (1) Data is in name/value pairs
//        value types -- Number(e.g., int, double), String, Boolean, Array, Object, null
//        https://jsoncpp.sourceforge.net/class_json_1_1_value.html
//    (2) Data is separated by commas
//        including array elements
//    (3) Curly braces hold objects
//        {...}
//    (4) Square brackets hold arrays
//        And, elements in a JSON array might have different data types!!
//        [{...}, {..}, 5, [...], "mine string", {...}]

// dump ==> print out all the content of an object
// dump2JSON ==> dump everything to a JSON::Value object (JSON representation)
// important instructional point about OOD/OOP --
//   to dump composite/complex objects, we might need "Recursions".
//   I.e., we have dump2JSON on every single class, and when we dump a higher
//         level object, we just recursively call the dump2JSON on all the immediate
//         lower-level objects.
//         And, we collect/integrate all the lower-level return JSON objects into
//         the current JSON with corresponding key.

Json::Value
Record::dump2JSON()
{
  Json::Value result;
  // null
  std::cout << result.toStyledString() << std::endl;

  result["where"] = (this->where).dump2JSON();
  // { "where": <return value from dump2JSON> }
  std::cout << result.toStyledString() << std::endl;
  
  result["when"] = (this->when).dump2JSON();
  // { "where": <return value from dump2JSON>,
  //   "when": <return value from dump2JSON>   } 
  std::cout << result.toStyledString() << std::endl;
  // or just simply
  // std::cout << result << std::endl;

  int i;
  for (i = 0; i < (this->who_persons).size(); i++)
    {
      // ((this->who_persons)[i]) ==> data type is class Person
      // ((this->who_persons)[i]).dump2JSON() ==> class Json::Value
      // result["who"] ==> class Json::Value ==> array
      // result["who"][i] ==> class Json::Value ==> object or whatever assigned?
      
      result["who"][i] = ((this->who_persons)[i]).dump2JSON();
    }
  
  for (i = 0; i < (this->what_things).size(); i++)
    {
      result["what"][i] = ((this->what_things)[i]).dump2JSON();
    }

  return result;
}
