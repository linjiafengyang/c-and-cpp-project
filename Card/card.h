#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
class card {
public:
	card() {}//���캯�� 
	virtual void query() {}//��ѯ���� 
	virtual void pay() {}//֧������ 
	virtual void transfer() {}//ת�˺��� 
	virtual void pay(double money) = 0;//ת�˴��麯�� 
};
class deposit_card: virtual public card {//��̳�card�� 
public:
	deposit_card();//���캯�� 
	deposit_card(string card_id, string stu_name, double _balance);//�������캯�� 
	void set(string card_id, string stu_name, double _balance);//�趨���š�ѧ��������������� 
	virtual void transfer(double money, deposit_card& a);//����ת�˽��ʹ��������ת�˹��� 
	void pay(double money, deposit_card a);//����֧�����ʹ��������֧������ 
	void pay(double money, string id);//����֧������ 
	virtual void pay(double money);//����֧��������֧������
	void set_transfer(int num, double *money, char time[][24], string *place);//��¼����ʱ�䡢�ص㡢���ȵ� 
	void D_query();//��ѯ�����Ϣ�����׼�¼ 
	int get_D_transfer();//��ý��״��� 
	string get_D_CardID();//��ÿ��� 
	string getStudentName();//���ѧ������ 
	double get_D_balance();//��ÿ������ 
	char* get_transfer_time(int i);//��ý���ʱ�� 
	double* get_transfer_money();//��ý��׽�� 
	string* get_transfer_place();//��ý��׵ص� 
private:
	string CardId;//������� 
	string StudentName;//ѧ������ 
	double balance;//������� 
	int transfer_num;//��¼���״��� 
	char transfer_time[100][24];//��¼����ʱ�� 
	string transfer_place[100];//��¼���׵ص� 
	double transfer_money[100];//��¼���׽�� 
};
class Campus_card: virtual public card {
public:
	Campus_card();//���캯�� 
	Campus_card(string card_id, string stu_id, string stu_name, string _college, double _balance);//�������캯�� 
	void set(string card_id, string stu_id, string stu_name, string _college, double _balance);//�趨���š�ѧ��ѧ�š�����������ѧԺ��������� 
	void transfer(double money, deposit_card& a);//����ת�˽��ʹ��������ת�˹��� 
	virtual void pay(double money);//����֧��������֧������ 
	void set_transfer(int num, double *money, char time[][24], string *place);//��¼����ʱ�䡢�ص㡢���ȵ� 
	void C_query();//��ѯУ԰����Ϣ�����׼�¼ 
	string getStudentName();//���ѧ������ 
	string getStudentId();//���ѧ��ѧ�� 
	string get_college();//���ѧ������ѧԺ 
	int get_C_transfer();//��ý��״��� 
	string get_C_CardID();//��ÿ��� 
	double get_C_balance();//��ÿ������ 
	char* get_transfer_time(int i);//��ý���ʱ�� 
	double* get_transfer_money();//��ý��׽�� 
	string* get_transfer_place();//��ý��׵ص� 
private:
	string CardId;//������� 
	string StudentID;//ѧ��ѧ�� 
	string StudentName;//ѧ������ 
	string college;//ѧ������ѧԺ 
	double balance;//������� 
	int transfer_num;//��¼���״��� 
	char transfer_time[100][24];//��¼����ʱ�� 
	string transfer_place[100];//��¼���׵ص� 
	double transfer_money[100];//��¼���׽�� 
};
class binding_card: public Campus_card, public deposit_card {
public:
	binding_card();//���캯�� 
	binding_card(Campus_card * a, deposit_card **b, int Dcard_num);//�������캯�� 
	void set(Campus_card * a, deposit_card **b, int Dcard_num);//�趨���󶨵�У԰���ʹ�������� 
	void pay(double money);//����֧������ 
	deposit_card** get_D();//��ô����Ϣ 
	Campus_card* get_C();//���У԰����Ϣ 
	int get_D_num();//��ð󶨿������������Ŀ 
private:
	deposit_card** deposit_cards;//������������ 
	Campus_card * campus_card;
	int deposit_cards_num;//�󶨿������������Ŀ 
};
#endif
