#pragma once
#ifndef __MYCOMPLEX__ //防卫式声明
#define __MYCOMPLEX__

class complex;
complex&
__doapl(complex* ths, const complex& r);
complex&
__doami(complex* ths, const complex& r);
complex&
__doaml(complex* ths, const complex* r);

class complex
{
public:
	/*
  构造函数
  （1）value or reference
  （2）初始化
  */
  complex(double r = 0,double i = 0):re(r),im(i){}//构造函数及其初始化

  //方法声明，成员函数，操作符重载
	complex& operator += (const complex&);//操作符重载
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	double real()const { return re; }//取实部和虚部的函数
	double imag()const { return im; }

private:
  //放数据
	double re, im;

  //友元，直接取 private的数据
	friend complex& __doapl(complex*, const complex&);//类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
	friend complex& __doami(complex*, const complex&);//尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数
	friend complex& __doaml(complex*, const complex&);
};


//内联函数是通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
//对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
//如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inline，在调用函数之前需要对函数进行定义。如果已定义的函数多于一行，编译器会忽略 inline 限定符。
//只有当函数只有 10 行甚至更少时才将其定义为内联函数.
//+=函数
inline complex&//关键字 inline 必须与函数定义体放在一起才能使函数成为内联，仅将 inline 放在函数声明前面不起任何作用。
__doapl(complex* ths, const complex& r)//定义好的+=函数
{
	ths->re += r.re;
	ths->re += r.im;
	return *ths;
}

/*
成员函数，操作符重载，先接口后定义
（1）作用域 complex class， this
（2）参数：r 不改变数值使用const，complex类的引用
（3）返回值：类型，可以传引用& local object
*/
inline complex&
complex::operator +=(const complex& r)
{
	return __doapl(this, r);//返回上面定义好的+=函数
}


//-=函数
inline complex&
__doami(complex* ths, const complex& r)
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths;
}

inline complex&
complex::operator -= (const complex& r)
{
	return __doami(this, r);
}

//*=函数
//规定复数的乘法按照以下的法则进行： 设z1 = a + bi，z2 = c + di(a、b、c、d∈R)是任意两个复数，那么它们的积(a + bi)(c + di) = (ac - bd) + (bc + ad)i
inline complex&
__doaml(complex* ths, const complex& r)
{
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f;
	return *ths;
}

inline complex&
complex::operator*=(const complex& r)
{
	return __doaml(this, r);
}

//取实部和虚部
inline double
imag(const complex& x)
{
	return x.imag();
}

inline double
real(const complex& x)
{
	return x.real();
}


//+函数 考虑返回值是否可以 传引用，local object
//为什么不是成员函数的形式呢？complex::operator + (this, )
inline complex
operator + (const complex& x, const complex& y)//两个参数都是复数
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}
inline complex
operator + (const complex& x, double y)//左边参数是复数，右边是实数
{
	return complex(real(x) + y, imag(x));
}

inline complex
operator + (double x, const complex& y)//左边参数是实数，右边是复数
{
	return complex(x + real(y), imag(y)); //加法
}

//-函数
inline complex
operator - (const complex & x, const complex & y)
{
	return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex
operator -(const complex& x, double y)
{
	return complex(real(x) - y, imag(x));
}

inline complex
operator -(double x, complex& y)
{
	return complex(x - real(y), -imag(y));
}

//*函数
inline complex
operator * (const complex& x, const complex& y)
{
	return complex(real(x) * real(y) - imag(x) * imag(y),
		real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator * (const complex& x, double y)
{
	return complex(real(x) * y, imag(x) * y);
}

inline complex
operator * (double x, const complex& y)
{
	return complex(x * real(y), x * imag(y));
}

//除法函数
complex
operator/(const complex& x, double y)
{
	return complex(real(x) / y, imag(x) / y);
}

inline complex
operator+(const complex& x)
{
	return x;
}

inline complex
operator-(const complex& x)
{
	return complex(-real(x), -imag(x));
}

//判断相等
inline bool
operator ==(const complex& x, const complex& y)
{
	return real(x) == real(y) && imag(x) == imag(y);
}
inline bool
operator == (const complex& x, double y)
{
	return real(x) == y && imag(x) == 0;
}

inline bool
operator == (double x, const complex& y)
{
	return x == real(y) && imag(y) == 0;
}

//不等于
inline bool
operator != (const complex& x, const complex& y)
{
	return real(x) != real(y) || imag(x) != imag(y);
}

inline bool
operator != (const complex& x, double y)
{
	return real(x) != y || imag(x) != 0;
}

inline bool
operator != (double x, const complex& y)
{
	return x != real(y) || imag(y) != 0;
}

#include<cmath>

inline complex
polar(double r, double t)
{
	return complex(r * cos(t), r * sin(t));
}

inline complex
conj(const complex& x)
{
	return complex(real(x), -imag(x));//取共轭
}

inline double
norm(const complex& x) {
	return real(x) * real(x) + imag(x) * imag(x);//取模
}

#endif //__MYCOMPLEX
