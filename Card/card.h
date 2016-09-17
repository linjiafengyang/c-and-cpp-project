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
	card() {}//构造函数 
	virtual void query() {}//查询函数 
	virtual void pay() {}//支付函数 
	virtual void transfer() {}//转账函数 
	virtual void pay(double money) = 0;//转账纯虚函数 
};
class deposit_card: virtual public card {//虚继承card类 
public:
	deposit_card();//构造函数 
	deposit_card(string card_id, string stu_name, double _balance);//拷贝构造函数 
	void set(string card_id, string stu_name, double _balance);//设定卡号、学生姓名、卡内余额 
	virtual void transfer(double money, deposit_card& a);//传入转账金额和储蓄卡，进行转账功能 
	void pay(double money, deposit_card a);//传入支付金额和储蓄卡，进行支付功能 
	void pay(double money, string id);//进行支付功能 
	virtual void pay(double money);//传入支付金额，进行支付功能
	void set_transfer(int num, double *money, char time[][24], string *place);//记录交易时间、地点、金额等等 
	void D_query();//查询储蓄卡信息及交易记录 
	int get_D_transfer();//获得交易次数 
	string get_D_CardID();//获得卡号 
	string getStudentName();//获得学生姓名 
	double get_D_balance();//获得卡内余额 
	char* get_transfer_time(int i);//获得交易时间 
	double* get_transfer_money();//获得交易金额 
	string* get_transfer_place();//获得交易地点 
private:
	string CardId;//储蓄卡卡号 
	string StudentName;//学生姓名 
	double balance;//卡内余额 
	int transfer_num;//记录交易次数 
	char transfer_time[100][24];//记录交易时间 
	string transfer_place[100];//记录交易地点 
	double transfer_money[100];//记录交易金额 
};
class Campus_card: virtual public card {
public:
	Campus_card();//构造函数 
	Campus_card(string card_id, string stu_id, string stu_name, string _college, double _balance);//拷贝构造函数 
	void set(string card_id, string stu_id, string stu_name, string _college, double _balance);//设定卡号、学生学号、姓名、所在学院、卡内余额 
	void transfer(double money, deposit_card& a);//传入转账金额和储蓄卡，进行转账功能 
	virtual void pay(double money);//传入支付金额，进行支付功能 
	void set_transfer(int num, double *money, char time[][24], string *place);//记录交易时间、地点、金额等等 
	void C_query();//查询校园卡信息及交易记录 
	string getStudentName();//获得学生姓名 
	string getStudentId();//获得学生学号 
	string get_college();//获得学生所在学院 
	int get_C_transfer();//获得交易次数 
	string get_C_CardID();//获得卡号 
	double get_C_balance();//获得卡内余额 
	char* get_transfer_time(int i);//获得交易时间 
	double* get_transfer_money();//获得交易金额 
	string* get_transfer_place();//获得交易地点 
private:
	string CardId;//储蓄卡卡号 
	string StudentID;//学生学号 
	string StudentName;//学生姓名 
	string college;//学生所在学院 
	double balance;//卡内余额 
	int transfer_num;//记录交易次数 
	char transfer_time[100][24];//记录交易时间 
	string transfer_place[100];//记录交易地点 
	double transfer_money[100];//记录交易金额 
};
class binding_card: public Campus_card, public deposit_card {
public:
	binding_card();//构造函数 
	binding_card(Campus_card * a, deposit_card **b, int Dcard_num);//拷贝构造函数 
	void set(Campus_card * a, deposit_card **b, int Dcard_num);//设定所绑定的校园卡和储蓄卡及卡数 
	void pay(double money);//进行支付功能 
	deposit_card** get_D();//获得储蓄卡信息 
	Campus_card* get_C();//获得校园卡信息 
	int get_D_num();//获得绑定卡（储蓄卡）的数目 
private:
	deposit_card** deposit_cards;//创建对象数组 
	Campus_card * campus_card;
	int deposit_cards_num;//绑定卡（储蓄卡）的数目 
};
#endif
