# C++ 面向对象编程 OOP

> https://www.youtube.com/channel/UCfYxPWIuOvjfRJzu0yhEM8w

侯捷老师的编程课程



## 1. Complex Class

class menber without point 知识点

- 项目文件：\**.h ， \**.cc

- Include 头文件，防止重复定义 #ifndef 防卫式声明

- 头文件分为两个部分：声明，定义

- class：private 数据 public 方法

- 声明函数的思路：

  - 函数名字
  - 参数，reference or value，  const
  - 返回值 reference   const ？

- 操作符重载 左右两端，参数const，this

  



## 2. String class

Class with point menber 中有指针

- 构造函数，拷贝构造 a（b），拷贝赋值 a=b
- 为什么要重写构造函数，内存管理，内存溢出
- 指针，引用（reference），值
- New 创建对象 （1）分配内存；（2）构造函数；生命周期。使用delete释放内存；
- static function & value 脱离this 引出了 singleton 单类设计模式；
- 还有很多其他的C++特性：
  - 操作符重载
  - 模版 类&函数
  - namespace 命名空间