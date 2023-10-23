
#include "Person.h"

Person::Person(std::string arg_SSN, std::string arg_name, GPS_DD arg_home)
{
  this->SSN = arg_SSN;
  this->name = arg_name;
  this->home = arg_home;
}

Person::Person()
{
  this->SSN = "";
  this->name = "";
  this->home = GPS_DD {};
}

void
Person::setHome
(GPS_DD arg_home)
{
  this->home = arg_home;
}

void
Person::setLocation
(GPS_DD arg_location, JvTime arg_time)
{
  this->location = arg_location;
  this->since_when = arg_time;
}

GPS_DD
Person::getHome
(void)
{
  return this->home;
}

std::string
Person::getSSN()
{
  return this->SSN;
}

std::string
Person::getName()
{
  return this->name;
}

// function prototype
bool
Person::operator==
(Person& aPerson)
{
  // Person& aPerson;
  // Person aPerson;
  // aPerson.whatever
  
  // Person * aPerson;
  // aPerson->whatever
  
  return (this->SSN == aPerson.getSSN());

  return (this->name == aPerson.getName());
  
  return ((this->name == aPerson.getName()) &&
	  (this->SSN == aPerson.getSSN()));
}

void Person::dump
(void)
{
  std::cout << "[Person] dump-begin" << std::endl;
  std::cout << "name           = " << this->name << std::endl;
  std::cout << "SSN            = " << this->SSN << std::endl;
  std::cout << "[Person] dump-end" << std::endl;

  return;
}

Json::Value
Person::dump2JSON
()
{
  Json::Value result;
  if (this->name != "")
    {
      result["name"] = this->name;
    }

  if (this->SSN != "")
    {
      result["SSN"] = this->SSN;
    }

  result["home"] = (this->home).dump2JSON();
  
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}
