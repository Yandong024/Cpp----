/*
函数的参数有三种形式，值，引用，指针
对象与别名
*/
#include <iostream>

using namespace std;

void func1(int x) { x = x + 10; }
void func2(int &x) { x = x + 10; }
void func3(int *x) { (*x) = (*x) + 10; }

int main(int argc, char const *argv[]) {
  /*
  (1) 值传递
  全局变量，局部变化，形参，实参
   */
  int n = 0;
  func1(n);
  cout << "值传递：" << n << endl;
  cout << "变量n的地址&n：" << &n << endl;
  /*
  (2) 引用
  引用与取值操作符号，与类型（右侧）一起出现的是引用，和变量(左侧)一起出现的是取地址
  必须初始化
  */
  int &m = n;
  cout << "m是n的一个引用（别名）" << m << endl;
  cout << "取地址，就是n的地址" << &m << endl;
  func2(m);
  cout << "这个时候，n和m的值各是多少呢：" << n << ' ' << m << endl;
  /*
 (3) 指针
 对象：有地址，内存一部分储存空间
 地址和存储数据的地址
 */
  int *o = nullptr; //空指针
  // cout << "*o ：" << *o << endl;
  cout << "取指针o的地址&o ：" << &o << endl;
  cout << "o ：" << o << endl;
  o = &n;  //如何赋值呢？ *o = n
  cout << "*o ：" << *o << endl;
  *o = m;
  cout << "o ：" << o << endl;
  func3(o);
  cout << "这个时候，n和m的值各是多少呢：" << n << ' ' << m << endl;
  /*
  对比上述三个示例程序，会发现"引用传递"的性质象"指针传递"，而书写方式象"值传递"。
  实际上"引用"可以做的任何事情"指针"也都能够做，为什么还要"引用"这东西？
  答案是"用适当的工具做恰如其分的工作"。
  指针能够毫无约束地操作内存中的任何东西，尽管指针功能强大，但是非常危险。
  如果的确只需要借用一下某个对象的"别名"，那么就用"引用"，而不要用"指针"，以免发生意外。
  */
  func3(&m);
  cout << "这个时候，n和m的值各是多少呢：" << n << ' ' << m << endl;
  func3(&n);
  cout << "这个时候，n和m的值各是多少呢：" << n << ' ' << m << endl;


  return 0;
}
