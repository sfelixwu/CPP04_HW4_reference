#include "Thing.h"

void
myPrintLog
(std::string content, std::string fname)
{
  if (fname.size() == 0) return;
  
  FILE *log_f = fopen(fname.c_str(), "a");
  if (log_f == NULL) return;
  
  JvTime *jv_ptr = getNowJvTime();
  std::string *str_ptr = jv_ptr->getTimeString();
  fprintf(log_f, "[%s] %s\n", str_ptr->c_str(), content.c_str());
  delete str_ptr;
  delete jv_ptr;
  fflush(log_f);
  fclose(log_f);
  return;
}

Thing::Thing
(void)
{
  this->model = "";
  this->sequence_num = "";
  this->description = "";
}

Thing::Thing
(Person arg_owner)
{
  this->model = "";
  this->sequence_num = "";
  this->description = "";
  this->owner = arg_owner;
}

void Thing::dump
(void)
{
  std::cout << "[Thing] dump-begin" << std::endl;
  std::cout << "model          = " << this->model << std::endl;
  std::cout << "sequence_num   = " << this->sequence_num << std::endl;
  std::cout << "description    = " << this->description << std::endl;
  std::cout << "[Thing] dump-end" << std::endl;
  return;
}

Json::Value
Thing::dump2JSON
()
{
  Json::Value result;
  if (this->model != "")
    {
      result["model"] = this->model;
    }

  if (this->sequence_num != "")
    {
      result["sequence number"] = this->sequence_num;
    }

  if (this->description != "")
    {
      result["description"] = this->description;
    }

  result["owner"] = (this->owner).dump2JSON();
  
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}
