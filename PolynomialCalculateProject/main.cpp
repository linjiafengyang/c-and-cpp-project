#include "polynomial.cpp"
int main() {
	Polynomial a;//创建对象，以便调用类成员函数 
	bool isQuit = false;//循环退出条件，即可退出计算器系统 
	int count = 0;
	int selection;//接受用户的操作选择 
	while(!isQuit) {
		selection = a.menu();
	    a.select(selection, count, isQuit);
	}
	return 0;
}
