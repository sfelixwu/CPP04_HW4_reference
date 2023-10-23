
#ifndef _ECS36B_COMMON_H_
#define _ECS36B_COMMON_H_

// ecs36b_Common.h

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
#include <stdio.h>
#include <stdlib.h>

// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

// c library
#include <arpa/inet.h>

using namespace std;

#include "ecs36b_Exception.h"

// utility functions
void myPrintLog(std::string content, std::string fname);
int myParseJSON(std::string input, Json::Value * jv_ptr);
char *myFile2String(char *f_name);
int myFile2JSON(char *f_name, Json::Value * jv_ptr);
int myJSON2File(char *f_name, Json::Value * jv_ptr);

#endif /* _ECS36B_COMMONy_H_ */
