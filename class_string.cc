

// 声明
#include<iostream>
#include"class_string.h"
using namespace std;

int main(int argc, char const *argv[])
{
  char my_string[] = "Hello World!!! \n";
  String s1(my_string);
  char *ps = s1.get_c_str();
  for (size_t i = 0; i<sizeof(my_string); i++)
  {
    /* code */
    cout << *ps ;
    ++ps;  
  }
  
 
  return 0;
}
