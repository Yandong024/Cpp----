/*
class with point member:
(1) point：
（2）Big three: 拷贝构造，拷贝赋值，析构函数
*/

//防卫声明
#ifndef __MYSTRING__
#define __MYSTRING__
#include <string>

// 第一部分：声明

class String {
 public:
  // 构造函数, cstr还改变吗，为什么不初始化呢
  String(const char* cstr = 0);
  // 拷贝构造，构造函数没有返回值
  String(const String& str);
  // 拷贝赋值
  String& operator=(const String& str);
  //析构函数
  ~String();
  // inline 定义
  char* get_c_str() const { return m_data; }

 private:
  // 指针：内存大小可变
  char* m_data;
};

// 第二部分：定义
inline String::String(const char* cstr) {
  if (cstr) {
    m_data = new char[strlen(cstr) + 1];  //内存开辟空间，全局生命周期
    strcpy(m_data, cstr);                 // 拷贝 copy
  } else {                                //未指定初值
    m_data = new char[1];
    *m_data = '\0';
  }
}

inline String::~String() { delete[] m_data; }

inline String::String(const String& str) {
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str) {
  //赋值给自己
  if (this == &str) return *this;
  /*
  （1）清空原有内存；
  （2）分配空间；
  （3）拷贝内容；
  */
  delete[] m_data;
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
  return *this;
}

#endif