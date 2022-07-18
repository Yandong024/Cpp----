/*
体会下构造函数
（1）Complex class
（2）main object
（3）friends func
*/

#include <iostream>
using namespace std;

class Complex {
 private:
  /* data */
  double re;
  double img;

 public:
  //构造函数
  Complex(double r=0, double i=0) : re(0), img(0) {
    re = r;
    img = i;
  }
  //返回实部和虚部
  double return_r() const { return re; }
  double return_i() const { return img; }
  // 另一个complex，处理实部和虚部
  const double c_func(const Complex& param);
  // doapl实现实部与虚部的加法
  Complex& __doapl(Complex* ths, const Complex& r){
    ths->re += r.re;
    ths->img += r.img;
    return *ths;
  }
  // operator 操作符重载
  Complex& operator += (const Complex &r){
    return __doapl(this, r);
  }
  // 声明
  double return_r(Complex& ) const;
  double return_i(Complex& ) const;

};

// c_func complex类方法定义
const double Complex::c_func(const Complex& param){
  return param.re + param.img;
}

// 重载 return_r, 参数形式不同了
double Complex::return_r(Complex& x) const { return x.return_r(); }
double Complex::return_i(Complex& x) const { return x.return_i(); }
  

// 非成员函数的操作符重载 
inline Complex operator+ (const Complex& x, const Complex& y){
  return Complex(x.return_r()+y.return_r(), x.return_i()+y.return_i());
}


int main(int argc, char const *argv[]) {
  Complex c1(1, 2);
  cout << c1.return_r() << " " <<c1.return_i() << endl;
  Complex c2(3);
  const double result_c2 = c2.c_func(c1);
  cout << result_c2 << endl;
  cout << "使用操作符重载+=，计算复数加法" << endl;
  c1 += c2;
  cout << "实部：" << c1.return_r() << " " <<"虚部："<<c1.return_i() << endl;
  // 使用非成员函数，操作符重载
  Complex c3 = c1 + c2;
  cout << "C3 使用操作符重载+，计算复数加法" << endl;
  cout << "实部：" << c3.return_r() << " " <<"虚部："<<c3.return_i() << endl;

  return 0;
}
