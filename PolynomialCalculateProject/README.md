#实验报告
功能实现：  
实现一个简单的多项式计算器，具体功能包括如下：  
基本功能：  
1.输入多项式   
2.多项式相加   
3.多项式相减  
4.常数乘多项式  
5.多项式代数求值  
6.显示多项式  
附加功能：  
7.多项式相乘  
8.多项式求导  
9.多项式比较  



分析与设计
4.1	、需求分析：  
1.输入多项式：  
创建一个对象数组Polynomial p[1000]；  
重载<<运算符，实现多项式要求的格式输入(系数，指数)；  
对象数组负责储存输入的多项式；  
2.多项式相加：  
输入时重载<<运算符；  
计算时重载+运算符；  
输出时重载>>运算符；  
3.多项式相减：  
输入时重载<<运算符；  
计算时重载-运算符；  
输出时重载>>运算符；  
4.常数乘多项式：  
输入一个整数表示常数；  
输入时重载<<运算符；  
计算时重载*运算符；   
输出时重载>>运算符；  
5.多项式代数求值：  
输入时重载<<运算符；  
输入一个整数代表要代的点；  
调用int value(int)成员函数求值；  
6.显示多项式：  
重载<<运算符；  
把对象数组中的多项式的打印出来；  
7.多项式相乘：  
输入时重载<<运算符；  
计算时重载*运算符；  
输出时重载>>运算符；  
8.多项式求导：  
输入时重载<<运算符；  
调用Polynomial findDerivative()成员函数求导；  
输出时重载>>运算符；  
9.多项式比较：  
输入时重载<<运算符；  
比较时重载==运算符；  
10.退出系统：  
