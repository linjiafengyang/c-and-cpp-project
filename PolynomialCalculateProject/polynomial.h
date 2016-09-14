#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Polynomial {
	private:
		static Polynomial polynomial[1000];//�����������飬�����������ʽ 
		int* p;//����һ��ָ��int���͵�ָ�룬�������ʽ 
		int saveNum;//��¼�ѱ���Ķ���ʽ������ 
	public:
		Polynomial();
		//���ؼӺ������������һ������ʽ���󣬽��ж���ʽ��Ӳ����ض���ʽ 
		Polynomial operator+(const Polynomial& obj);
		//���ؼ��������������һ������ʽ���󣬽��ж���ʽ��������ض���ʽ
		Polynomial operator-(const Polynomial& obj);
		//���س˺������������һ������ʽ���󣬽��ж���ʽ��˲����ض���ʽ
		Polynomial operator*(const Polynomial& obj);
		//���س˺������������һ�����������г��������ʽ��˲����ض���ʽ
		Polynomial operator*(const int a);
		//���ж���ʽ�󵼣������ض�������
		Polynomial findDerivative();
		//����һ������ʽ�����ж϶���ʽ�Ƿ���Ȳ�����boolֵ 
		bool operator==(Polynomial obj);
		//����һ�����������ж���ʽ������ֵ������һ��������ʾ��ֵ���
		int value(const int point);
		//����>>�����������һ������ʽ���󣬿������벢��������
		friend istream& operator>>(istream& in, Polynomial& obj);
		//����<<�����������һ������ʽ���󣬿���������������
		friend ostream& operator<<(ostream& out, Polynomial obj);
		int* getPolynomial();//����ָ�����͵�polynomialָ��
		int get_saveNum();//����һ�����ͱ�ʾ����ʽ������ 
		/*��ӡϵͳ�Ľ���ͼ����ʾ�û��������ֽ��в���ѡ��
		�������û��Ĳ���ѡ��(һ��int���͵�����)*/ 
		int menu();
		/*�������ѡ�񡢼�����(���ô��ݣ��ı���ֵ),
		�˳�ϵͳ�ж�����(���ô��ݣ��ı���ֵ)����ӡ��ʵ�ֵĹ���*/ 
		void select(const int selection, int& count, bool& isQuit);
};
Polynomial Polynomial::polynomial[1000];
#endif
