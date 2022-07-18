/*
为什么成员函数要加 const
https://zhuanlan.zhihu.com/p/110159656
const 修饰成员函数， 根本上是修饰了 this 指针
*/


#include<iostream>

using namespace std;

class A
{
private:
    int data;
public:
    A(int num):data(num){}
    ~A(){};
    // 必须添加 const
    int get_data()const 
    {
        return data;
    }
};

int main()
{
    // const A a(1); //我的实例a是const的
    A a(1);
    a.get_data();
    return 0;
}