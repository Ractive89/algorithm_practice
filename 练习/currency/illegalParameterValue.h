/*
 * @Author: Ractive 
 * @Date: 2019-02-20 00:17:53 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 01:21:46
 */
#ifndef Illegal_ParameterValue_
#define Illegal_ParameterValue_

#include <iostream>
#include <string>

class illegalParameterValue
{
  private:
    std::string message;

  public:
    illegalParameterValue() : message("Illegal parameter value"){};
    illegalParameterValue(const char *the_Message);
    ~illegalParameterValue();
    void out_Put_Message();
};

illegalParameterValue::illegalParameterValue(const char *the_Message)
{
    message = the_Message;
}

illegalParameterValue::~illegalParameterValue()
{
}

void illegalParameterValue::out_Put_Message()
{
    std::cout << message << std::endl;
}

#endif
