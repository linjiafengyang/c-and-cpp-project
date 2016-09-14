#include "polynomial.h"
//��̬����polynomial�������飬����ʼ��Ϊ0 
Polynomial::Polynomial() {
	p = new int[1001];
    for(int i = 0; i < 1001; i++) {
	    p[i] = 0;
    }
    saveNum = 0;
}
//����ָ�����͵�polynomialָ�� 
int* Polynomial::getPolynomial() {
	return p;
}
//���ض���ʽ������ 
int Polynomial::get_saveNum() {
	return saveNum;
}
//����һ������ʽ���󣬽��ж���ʽ��Ӳ����ض���ʽ 
Polynomial Polynomial::operator+(const Polynomial& obj) {
	int i;
	Polynomial temp;
	for(i = 0; i < 1001; i++) {
		temp.p[i] = p[i] + obj.p[i];
    }
    return temp;
}
//����һ������ʽ���󣬽��ж���ʽ��������ض���ʽ 
Polynomial Polynomial::operator-(const Polynomial& obj) {
	int i;
	Polynomial temp;
	for(i = 0; i < 1001; i++) {
		temp.p[i] = p[i] - obj.p[i];
	}  
	return temp;
}
//����һ������ʽ���󣬽��ж���ʽ��˲����ض���ʽ 
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
//����һ�����������г��������ʽ��˲����ض���ʽ 
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
//����һ�����������ж���ʽ������ֵ������һ��������ʾ��ֵ��� 
int Polynomial::value(const int point) {
	int i, sum = 0;
	for(i = 0; i < 1001; i++) {
		if(p[i] != 0) {
			sum += p[i] * pow(point, i);
		}
	}
	return sum;
}
//����һ������ʽ�����ж϶���ʽ�Ƿ���Ȳ�����boolֵ 
bool Polynomial::operator==(Polynomial obj){
	int i;
	for(i = 0; i < 1001; i++) {
		if(p[i] != obj.p[i]) {
			return false;
		}
	}
	return true;
}
//���ж���ʽ�󵼣������ض������� 
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
//����һ������ʽ���󣬿������벢�������� 
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
//����һ������ʽ���󣬿��������������� 
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
//��ӡϵͳ�Ľ���ͼ����ʾ�û��������ֽ��в���ѡ�񣬲������û��Ĳ���ѡ��(һ��int���͵�����)
int Polynomial::menu() {
	cout << endl;
	cout << "\t\t\t     ��ӭʹ�ö���ʽ����ϵͳ               " << endl; 
	cout << "\t\t#********************************************#" << endl;
	cout << "\t\t|1.�������ʽ              6.��ʾ����ʽ      |" << endl; 
	cout << "\t\t|2.����ʽ���              7.����ʽ���      |" << endl;
	cout << "\t\t|3.����ʽ���              8.����ʽ��      |" << endl;
	cout << "\t\t|4.�����˶���ʽ            9.����ʽ�Ƚ�      |" << endl;
	cout << "\t\t|5.����ʽ������ֵ          10.�˳�ϵͳ       |" << endl;
	cout << "\t\t#********************************************#" << endl;
	cout << endl;
	int selection;//�û����в���ѡ�� 
	cout << "��ѡ��һ�����֣�1~10�����в�����";
	cin >> selection;
	return selection;
}
//�������ѡ�񡢼�����(���ô��ݣ��ı���ֵ), �������飬�˳�ϵͳ�ж�����(���ô��ݣ��ı���ֵ) 
void Polynomial::select(const int selection, int& count, bool& isQuit) {
	Polynomial t1, t2;//������������ 
	switch(selection) {
		case 1:
			int number;//����ʽ������ 
			cout << "������Ҫ����Ķ���ʽ��������";
			cin >> number;
			for(int i = 0; i < number; i++) {
				cout << "���������ʽ����ʽΪ(ϵ��,ָ��):" << endl;
				cin >> polynomial[count++];
			}
			cout << "����ɹ���" << endl;
			break;
		case 2:
			//����ʽ��� 
			cout << "��������Ҫ���мӷ������Ķ���ʽ1:" << endl;
			cin >> t1;
			cout << "��������Ҫ���мӷ������Ķ���ʽ2:" << endl; 
			cin >> t2;
			cout << "(" << t1 << ")" << "+" << "(" << t2 << ")" << "=" << t1 + t2 << endl;
			break;
		case 3:
			//����ʽ��� 
			cout << "��������Ҫ���м��������Ķ���ʽ1:" << endl;
			cin >> t1;
			cout << "��������Ҫ���м��������Ķ���ʽ2:" << endl; 
			cin >> t2;
			cout << "(" << t1 << ")" << "-" << "(" << t2 << ")" << "=" << t1 - t2 << endl;
			break;
		case 4:
			//���������ʽ��� 
		    int a;
			cout << "��ѡ����Ҫ���г˷������ĳ���:" << endl; 
			cin >> a;
			cout << "��������Ҫ���г˷������Ķ���ʽ:" << endl; 
			cin >> t1;
			cout << a << "*" << "(" << t1 << ")" << "=" << t1 * a << endl;
			break;
		case 5:
			//����ʽ������ֵ 
			int point;//�������ʽ�ĵ� 
			cout << "��������Ҫ������ֵ�Ķ���ʽ:" << endl;
			cin >> t1;
			cout << "��������Ҫ����ĵ㣺"; 
			cin >> point;
			cout << "value=" << t1.value(point) << endl;
			break;	   
		case 6:
			//��ʾ����ʽ 
			for(int i = 0; i  < count; i++) {
				cout << polynomial[i] << endl;
			}
			break;
		case 7:
			//����ʽ��� 
			cout << "��������Ҫ���г˷������Ķ���ʽ1:" << endl;
			cin >> t1;
			cout << "��������Ҫ���г˷������Ķ���ʽ2:" << endl; 
			cin >> t2;
			cout << "(" << t1 << ")" << "*" << "(" << t2 << ")" << "=" << t1 * t2 << endl;
			break;
		case 8:
			//����ʽ�� 
			cout << "��������Ҫ�����󵼵Ķ���ʽ:" << endl; 
			cin >> t1;
			cout << "(" << t1 << ")" << "'" << "=" << t1.findDerivative() << endl;
			break;
		case 9:
			//����ʽ�Ƚ� 
			cout << "��������Ҫ���бȽϲ����Ķ���ʽ1��" << endl;
			cin >> t1;
			cout << "��������Ҫ���бȽϲ����Ķ���ʽ2:" << endl; 
			cin >> t2;
			if(t1 == t2) {
				cout << "���" << endl;
			}
			else {
				cout << "�����" << endl;
			}
			break;
		case 10:
			//�˳�ϵͳ 
			isQuit = true;//�˳�whileѭ�� 
			break;
	}
}
