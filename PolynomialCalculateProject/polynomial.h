#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Polynomial {
	private:
		static Polynomial polynomial[1000];//创建对象数组，用来保存多项式 
		int* p;//定义一个指向int类型的指针，储存多项式 
		int saveNum;//记录已保存的多项式的数量 
	public:
		Polynomial();
		//重载加号运算符：传入一个多项式对象，进行多项式相加并返回多项式 
		Polynomial operator+(const Polynomial& obj);
		//重载减号运算符：传入一个多项式对象，进行多项式相减并返回多项式
		Polynomial operator-(const Polynomial& obj);
		//重载乘号运算符：传入一个多项式对象，进行多项式相乘并返回多项式
		Polynomial operator*(const Polynomial& obj);
		//重载乘号运算符：传入一个整数，进行常数与多项式相乘并返回多项式
		Polynomial operator*(const int a);
		//进行多项式求导，并返回对象类型
		Polynomial findDerivative();
		//传入一个多项式对象，判断多项式是否相等并返回bool值 
		bool operator==(Polynomial obj);
		//传入一个整数，进行多项式代点求值并返回一个整数表示求值结果
		int value(const int point);
		//重载>>运算符：传入一个多项式对象，控制输入并返回输入
		friend istream& operator>>(istream& in, Polynomial& obj);
		//重载<<运算符：传入一个多项式对象，控制输出并返回输出
		friend ostream& operator<<(ostream& out, Polynomial obj);
		int* getPolynomial();//返回指向整型的polynomial指针
		int get_saveNum();//返回一个整型表示多项式的数量 
		/*打印系统的界面图，提示用户输入数字进行操作选择，
		并返回用户的操作选择(一个int类型的数字)*/ 
		int menu();
		/*传入操作选择、计数器(引用传递，改变其值),
		退出系统判断条件(引用传递，改变其值)，打印出实现的功能*/ 
		void select(const int selection, int& count, bool& isQuit);
};
Polynomial Polynomial::polynomial[1000];
#endif
