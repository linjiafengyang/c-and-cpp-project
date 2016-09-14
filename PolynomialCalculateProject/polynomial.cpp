#include "polynomial.h"
//动态分配polynomial整型数组，并初始化为0 
Polynomial::Polynomial() {
	p = new int[1001];
    for(int i = 0; i < 1001; i++) {
	    p[i] = 0;
    }
    saveNum = 0;
}
//返回指向整型的polynomial指针 
int* Polynomial::getPolynomial() {
	return p;
}
//返回多项式的数量 
int Polynomial::get_saveNum() {
	return saveNum;
}
//传入一个多项式对象，进行多项式相加并返回多项式 
Polynomial Polynomial::operator+(const Polynomial& obj) {
	int i;
	Polynomial temp;
	for(i = 0; i < 1001; i++) {
		temp.p[i] = p[i] + obj.p[i];
    }
    return temp;
}
//传入一个多项式对象，进行多项式相减并返回多项式 
Polynomial Polynomial::operator-(const Polynomial& obj) {
	int i;
	Polynomial temp;
	for(i = 0; i < 1001; i++) {
		temp.p[i] = p[i] - obj.p[i];
	}  
	return temp;
}
//传入一个多项式对象，进行多项式相乘并返回多项式 
Polynomial Polynomial::operator*(const Polynomial& obj) {
	int i, j, temp1, temp2;
	Polynomial temp;
	for(i = 0; i < 1001; i++) {
		temp1 = i; 
		if(p[i] != 0) {
			if(i > 1000) {
				i = -i + 1000;
				for(j = 0; j < 1001; j++) {
					temp2 = j;
					if(obj.p[j] != 0) {
						if(j > 1000) {
							j = -j + 1000;
							temp.p[-(i + j) + 1000] += p[temp1] * obj.p[temp2];
						}
						else {
							if(i + j < 0) {
								int temp3 = -(i + j) + 1000;
								temp.p[temp3] += p[temp1] * obj.p[temp2];
							}
							else {
								temp.p[i + j] += p[temp1] * obj.p[temp2];
							}
						}
					}
					j = temp2;
			    }
			} 
			else {
				for(j = 0; j < 1001; j++) {
					temp2 = j;
					if(obj.p[j] != 0) {
						if(j > 1000) {
							j = -j + 1000;
							if(i + j < 0) {
								int temp3 = -(i + j) + 1000;
								temp.p[temp3] += p[temp1] * obj.p[temp2];
							}
							else {
								temp.p[i + j] += p[temp1] * obj.p[temp2];
							}
						}
						else {
							if(i + j < 0) {
								int temp3 = -(i + j) + 1000;
								temp.p[temp3] += p[temp1] * obj.p[temp2];
							}
							else {
								temp.p[i + j] += p[temp1] * obj.p[temp2];
							}
						}
					}
					j = temp2;
			    }
			}
		}
		i = temp1;
    } 
	return temp;
}
//传入一个整数，进行常数与多项式相乘并返回多项式 
Polynomial Polynomial::operator*(const int a) {
	int i;
	Polynomial temp;
	for(i = 0; i < 1001; i++) {
		if(p[i] != 0) {
			temp.p[i] = a * p[i];
		}
	}
	return temp;
}
//传入一个整数，进行多项式代点求值并返回一个整数表示求值结果 
int Polynomial::value(const int point) {
	int i, sum = 0;
	for(i = 0; i < 1001; i++) {
		if(p[i] != 0) {
			sum += p[i] * pow(point, i);
		}
	}
	return sum;
}
//传入一个多项式对象，判断多项式是否相等并返回bool值 
bool Polynomial::operator==(Polynomial obj){
	int i;
	for(i = 0; i < 1001; i++) {
		if(p[i] != obj.p[i]) {
			return false;
		}
	}
	return true;
}
//进行多项式求导，并返回对象类型 
Polynomial Polynomial::findDerivative() {
	Polynomial temp;
	int i;
	for(i = 0; i < 1001; i++) {
		if(p[i] != 0) {
			if(i != 0) {
				temp.p[i - 1] = p[i] * i;
			}
		}
	}
	return temp;
}
//传入一个多项式对象，控制输入并返回输入 
istream& operator>>(istream& in, Polynomial& obj) {
	string Polynomial;
	in >> Polynomial;
	int i, k = 0, j = 0;
	int temp = 0;
	bool p = false, q = false;
	for(i = Polynomial.size() - 1; i >= 0; i--) {
		if(Polynomial[i] == ')') {
			p = true;
			continue;
		}
		if(Polynomial[i] == ',') {
			q = true;
			p = false;
			k = 0;
			continue;
		}
		if(Polynomial[i] == '(') {
			k = 0;
			obj.p[temp] = j;
			if (temp <= 1000) {
				obj.saveNum = temp;
			}
			j = 0;
			temp = 0;
			q = false;
			continue;
		}
		if(Polynomial[i] == '-' && p) {
			temp = temp + 1000;
			continue;
		}
		if(Polynomial[i] == '-' && q) {
			j = -j;
			continue;
		}
		if(p) {
			temp += (Polynomial[i] - '0') * pow(10, k++);
		}
		if(q) {
			j += (Polynomial[i] - '0') * pow(10, k++);
		}
	}
	return in;
}
//传入一个多项式对象，控制输出并返回输出 
ostream& operator<<(ostream& out, Polynomial obj) {
	int* temp;
	temp = obj.getPolynomial();
	int saveNum = obj.get_saveNum();
	bool p = false, q = false;
	for(int i = 0; i < 1001; i++) {
		if(obj.p[i] != 0) {
			q = true;
			break;
		}
	}
	if(!q) {
		cout << 0;
		return out;
	}
	for(int i = 1000; i >= 0; i--) {
		if(temp[i] > 0) {
			if(temp[i] != 1) {
				if(i == 0) {
					out << "+" << temp[i];
				}
				else if(i == 1) {
					if (i == saveNum) {
						out << temp[i] << "x"; 
					}
					else {
						out << "+" << temp[i] << "x"; 
					}
				}
				else if(i <= 1000) {
					if(i == saveNum) {
						out << temp[i] << "x^" << i; 
					}
					else {
						out << "+" << temp[i] << "x^" << i; 
					}
				} 
				else {
					int tmp = -i + 1000;
					out << "+" << temp[i] << "x^" << tmp; 
				}
			}
			else {
				if(i == 0) {
					out << "+" << temp[i];
				} 
				else if(i == 1) {
					if(i == saveNum) {
						out << "x";
					}
					else {
						out << "+" << "x";
					}
				}
				else if(i <= 1000) {
					if(i == saveNum) {
						out << "x^" << i;
					}
					else {
						out << "+" << "x^" << i;
					}
				}
				else {
					int tmp = -i + 1000;
					out << "+" << "x^" << tmp;
				}
			}
		}
		else if(temp[i] < 0) {
			if(temp[i] != -1) {
				if(i == 0) {
					out << temp[i];
				}
				else if(i == 1) {
					out << temp[i] << "x";
				}
				else if(i <= 1000) {
					out << temp[i] << "x^" << i;
				}
				else {
					int tmp = -i + 1000;
					out << temp[i] << "x^" << tmp;
				}
			}
			else {
				if(i == 0) {
					out << temp[i];
				}
				else if(i <= 1000){
					out << "-" << "x^" << i;
				}
				else {
					int temp = -i + 1000;
					out << "-" << "x^" << temp;
				}
			}
		}
		if(p) {
			p = false;
			i = -i + 1000;
		}
	}
	for(int i = 1001; i < 1001; i++) {
		if(temp[i] > 0) {
			if(temp[i] != 1) {
				if(i == 0) {
					out << "+" << temp[i];
				}
				else if(i == 1) {
					if(i == saveNum) {
						out << temp[i] << "x";
					}
					else {
						out << "+" << temp[i] << "x";
					}
				}
				else if(i <= 1000){
					if(i == saveNum) {
						out << temp[i] << "x^" << i;
					}
					else {
						out << "+" << temp[i] << "x^" << i;
					}
				}
				else {
					int temp1 = -i + 1000;
					out << "+" << temp[i] << "x^" << temp1;
				}
			}
			else {
				if(i == 0) {
					out << "+" << temp[i];
				}
				else if(i == 1) {
					if(i == saveNum) {
						out << "x";
					}
					else {
						out << "+" << "x";
					}
				}
				else if(i <= 1000) {
					if(i == saveNum) {
						out << "x^" << i;
					}
					else {
						out << "+" << "x^" << i;
					}
				}
				else {
					int temp = -i + 1000;
					out << "+" << "x^" << temp;
				}
			}
		}
		else if(temp[i] < 0) {
			if(temp[i] != -1) {
				if(i == 0) {
					out << temp[i];
				} 
				else if(i == 1) {
					out << temp[i] << "x";
				}
				else if(i <= 1000){
					out << temp[i] << "x^" << i;
				}
				else {
					int temp1 = -i + 1000;
					out << temp[i] << "x^" << temp1;
				}
			}
			else {
				if(i == 0) {
					out << temp[i];
				} 
				else if(i <= 1000){
					out << "-" << "x^" << i;
				}
				else {
					int temp = -i + 1000;
					out << "-" << "x^" << temp;
				}
			}
		}
		if(p) {
			p = false;
			i = -i + 1000;
		}
	}
	return out;
}
//打印系统的界面图，提示用户输入数字进行操作选择，并返回用户的操作选择(一个int类型的数字)
int Polynomial::menu() {
	cout << endl;
	cout << "\t\t\t     欢迎使用多项式计算系统               " << endl; 
	cout << "\t\t#********************************************#" << endl;
	cout << "\t\t|1.输入多项式              6.显示多项式      |" << endl; 
	cout << "\t\t|2.多项式相加              7.多项式相乘      |" << endl;
	cout << "\t\t|3.多项式相减              8.多项式求导      |" << endl;
	cout << "\t\t|4.常数乘多项式            9.多项式比较      |" << endl;
	cout << "\t\t|5.多项式代数求值          10.退出系统       |" << endl;
	cout << "\t\t#********************************************#" << endl;
	cout << endl;
	int selection;//用户进行操作选择 
	cout << "请选择一个数字（1~10）进行操作：";
	cin >> selection;
	return selection;
}
//传入操作选择、计数器(引用传递，改变其值), 对象数组，退出系统判断条件(引用传递，改变其值) 
void Polynomial::select(const int selection, int& count, bool& isQuit) {
	Polynomial t1, t2;//创建两个对象 
	switch(selection) {
		case 1:
			int number;//多项式的数量 
			cout << "请输入要输入的多项式的数量：";
			cin >> number;
			for(int i = 0; i < number; i++) {
				cout << "请输入多项式，格式为(系数,指数):" << endl;
				cin >> polynomial[count++];
			}
			cout << "输入成功！" << endl;
			break;
		case 2:
			//多项式相加 
			cout << "请输入需要进行加法操作的多项式1:" << endl;
			cin >> t1;
			cout << "请输入需要进行加法操作的多项式2:" << endl; 
			cin >> t2;
			cout << "(" << t1 << ")" << "+" << "(" << t2 << ")" << "=" << t1 + t2 << endl;
			break;
		case 3:
			//多项式相减 
			cout << "请输入需要进行减法操作的多项式1:" << endl;
			cin >> t1;
			cout << "请输入需要进行减法操作的多项式2:" << endl; 
			cin >> t2;
			cout << "(" << t1 << ")" << "-" << "(" << t2 << ")" << "=" << t1 - t2 << endl;
			break;
		case 4:
			//常数与多项式相乘 
		    int a;
			cout << "请选择需要进行乘法操作的常数:" << endl; 
			cin >> a;
			cout << "请输入需要进行乘法操作的多项式:" << endl; 
			cin >> t1;
			cout << a << "*" << "(" << t1 << ")" << "=" << t1 * a << endl;
			break;
		case 5:
			//多项式代点求值 
			int point;//代入多项式的点 
			cout << "请输入需要进行求值的多项式:" << endl;
			cin >> t1;
			cout << "请输入所要代入的点："; 
			cin >> point;
			cout << "value=" << t1.value(point) << endl;
			break;	   
		case 6:
			//显示多项式 
			for(int i = 0; i  < count; i++) {
				cout << polynomial[i] << endl;
			}
			break;
		case 7:
			//多项式相乘 
			cout << "请输入需要进行乘法操作的多项式1:" << endl;
			cin >> t1;
			cout << "请输入需要进行乘法操作的多项式2:" << endl; 
			cin >> t2;
			cout << "(" << t1 << ")" << "*" << "(" << t2 << ")" << "=" << t1 * t2 << endl;
			break;
		case 8:
			//多项式求导 
			cout << "请输入需要进行求导的多项式:" << endl; 
			cin >> t1;
			cout << "(" << t1 << ")" << "'" << "=" << t1.findDerivative() << endl;
			break;
		case 9:
			//多项式比较 
			cout << "请输入需要进行比较操作的多项式1：" << endl;
			cin >> t1;
			cout << "请输入需要进行比较操作的多项式2:" << endl; 
			cin >> t2;
			if(t1 == t2) {
				cout << "相等" << endl;
			}
			else {
				cout << "不相等" << endl;
			}
			break;
		case 10:
			//退出系统 
			isQuit = true;//退出while循环 
			break;
	}
}
