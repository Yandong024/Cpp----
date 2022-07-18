#ifndef __MYSTRING__
#define __MYSTRING__

// 声明
#include<string>

class String {
 private:
  /* data */
  char* m_data;

 public:
  // 构造函数
  String(const char* cstr=0);
  // 拷贝构造 参数就是这个类
  String(const String& str);
  // 拷贝赋值
  String& operator=(const String& str);
  // 析构函数
  ~String();
  //成员函数
  char* get_c_str() const{return m_data;}
};


// 定义

// 构造函数
inline
String::String(const char* cstr){
  if (cstr)
  {
    /* code */
    m_data = new char[strlen(cstr)+1];
    strcpy(m_data, cstr);
  }
  else
  {
    m_data = new char[1];
    *m_data = '\0';
  }
}

// 析构函数 内存管理
inline
String::~String(){
  delete[] m_data;
}
#endif