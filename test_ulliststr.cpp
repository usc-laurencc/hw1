#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_front("0");
  dat.push_front("1");
  dat.push_front("2");
  dat.push_front("3");
  dat.push_front("4");
  dat.push_front("5");
  dat.push_front("6");
  dat.push_front("7");
  dat.push_front("8");
  dat.push_front("9");
  dat.push_front("10");
  dat.push_front("11");

  for (int i = 0; i < 12; i++) {
    cout << dat.get(i) << endl;
  }
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

  cout << dat.back() << " " << dat.front() << endl;
  dat.pop_back();
  cout << dat.size() << endl;
  dat.pop_front();
  cout << dat.size() << endl;
  cout << dat.back() << " " << dat.front() << endl;
  dat.pop_back();
  dat.pop_back();
  cout << dat.size() << endl;
}
