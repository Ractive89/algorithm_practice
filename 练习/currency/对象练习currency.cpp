/*
 * @Author: Ractive 
 * @Date: 2019-02-17 16:08:33 
 * @Last Modified by: Ractive
 * @Last Modified time: 2019-02-20 02:20:57
 */
#include <iostream>
#include "currency.h"

using namespace std;

int main(int argc, char *argv[])
{

  currency a(currency::plus, 12, 23);
  currency b(currency::plus, 2, 3);

  cout << a.interest_compound(0.05, 5) << a.interest(0.05, 5);
  // try
  // {
  //   a.set_Value(currency::minus, 3, 512);
  // }
  // catch (illegalParameterValue err)
  // {
  //   cout << "Caught thrown exception" << endl;
  //   err.out_Put_Message();
  // }
  system("pause");
  return 0;
}
