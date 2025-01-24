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
  cout << dat.empty() << " " << dat.size() << endl;
  dat.push_back("a");
  dat.pop_back();
  
  // for (size_t i = 0; i < 51; i++) {
  //   dat.push_front(to_string(i));
  // }

  // for (size_t i = 0; i < dat.size(); i++) {
  //   cout << dat.get(i) << " ";
  // }
  // cout << endl;

  // for (size_t i = 0; i < 50; i++) {
  //   dat.pop_back();
  // }

  // for (size_t i = 0; i < dat.size(); i++) {
  //   cout << dat.get(i) << " ";
  // }
  // cout << endl;

  
  // // prints: 8 7 9
  // cout << dat.size() << endl; 
  
}
