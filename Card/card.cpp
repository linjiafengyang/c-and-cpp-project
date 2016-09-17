#include "card.h"
using namespace std;


//功能菜单选择，并返回用户输入的选择值 
int menu() {
	cout << endl ;
	cout << "\t\t*************校园电子卡管理系统功能菜单**************" << endl;
	cout << "\t\t|   1.添加校园卡               6.查询绑定卡信息     |" << endl;
	cout << "\t\t|   2.添加储蓄卡               7.支付               |" << endl;
	cout << "\t\t|   3.添加绑定卡               8.转账               |" << endl;
	cout << "\t\t|   4.查询校园卡信息           0.退出系统           |" << endl;
	cout << "\t\t|   5.查询储蓄卡信息                                |" << endl;
	cout << "\t\t*****************************************************" << endl;
	cout << endl << "请输入数字(0~8)选择一个功能：" << endl;
	int selection;
	cin >> selection;
	return selection;
}


Campus_card* find_C(string id, Campus_card a[], int Ccard_num) {
	for(int i = 0; i < Ccard_num; i++) {
		if(a[i].get_C_CardID() == id) {
			return &a[i];
		}
	}
}
deposit_card* find_D(string id, deposit_card a[], int Dcard_num) {
	for(int i = 0; i < Dcard_num; i++) {
		if(a[i].get_D_CardID() == id) {
			return &a[i];
		}
	}
}
binding_card* find_B(string id, binding_card a[], int Bcard_num) {
	for(int i = 0; i < Bcard_num; i++) {
		if(a[i].get_C()->get_C_CardID() == id) {
			return &a[i];
		}
	}
}


deposit_card::deposit_card() {
	balance = 0;
	transfer_num = 0;
	CardId = "";
	StudentName = "";
}
deposit_card::deposit_card(string card_id, string stu_name, double _balance) {
	CardId = card_id;
	StudentName = stu_name;
	balance = _balance;
	transfer_num = 0;
}
void deposit_card::set(string card_id, string stu_name, double _balance) {
	CardId = card_id;
	StudentName = stu_name;
	balance = _balance;
	transfer_num = 0;
}
void deposit_card::transfer(double money, deposit_card& a) {
	balance += money;
	time_t t = time(0);
	strftime(transfer_time[transfer_num], sizeof(transfer_time[transfer_num]), "%Y/%m/%d %X", localtime(&t));
	transfer_place[transfer_num] = a.get_D_CardID();
	transfer_money[transfer_num++] = money;
	a.pay(money, *this);
}
void deposit_card::pay(double money, deposit_card a) {
	balance -= money;
	time_t t = time(0);
	strftime(transfer_time[transfer_num], sizeof(transfer_time[transfer_num]),  "%Y/%m/%d %X", localtime(&t));
	transfer_place[transfer_num] = a.get_D_CardID();
	transfer_money[transfer_num++] = -money;
}
void deposit_card::pay(double money, string id) {
	balance -= money;
	time_t t = time(0);
	strftime(transfer_time[transfer_num], sizeof(transfer_time[transfer_num]), "%Y/%m/%d %X", localtime(&t));
	transfer_place[transfer_num] = id;
	transfer_money[transfer_num++] = -money;
}
void deposit_card::pay(double money) {
	balance -= money;
	time_t t = time(0);
	strftime(transfer_time[transfer_num], sizeof(transfer_time[transfer_num]), "%Y/%m/%d %X", localtime(&t));
	transfer_money[transfer_num++] = -money;
}
int deposit_card::get_D_transfer() {
	return transfer_num;
}
string deposit_card::get_D_CardID() {
	return CardId;
}
string deposit_card::getStudentName() {
	return StudentName;
}
double deposit_card::get_D_balance() {
	return balance;
}
void deposit_card::set_transfer(int num, double *money, char time[][24], string *place) {
	transfer_num = num;
	int i;
	for (i = 0; i < transfer_num; i++) {
		transfer_money[i] = money[i];
		strcpy(transfer_time[i], time[i]);
		transfer_place[i] = place[i];
	}
}
void deposit_card::D_query() {
	int i;
	for (i = 0; i < transfer_num; i++) {
		if(transfer_money[i] > 0) {
			cout << "+" << transfer_money[i] << "    ";
		}
		else {
			cout << transfer_money[i] << "    ";
		}
		cout << transfer_place[i] << "    " << transfer_time[i] << endl;
	}
}
char* deposit_card::get_transfer_time(int i) {
	return transfer_time[i];
}
double* deposit_card::get_transfer_money() {
	return transfer_money;
}
string* deposit_card::get_transfer_place() {
	return transfer_place;
}


Campus_card::Campus_card() {
	balance = 0;
	transfer_num = 0;
	CardId = "";
	StudentID = "";
	StudentName = "";
	college = "";
}
Campus_card::Campus_card(string card_id, string stu_id, string stu_name, string _college, double _balance) {
	CardId = card_id;
	StudentID = stu_id;
	StudentName = stu_name;
	college = _college;
	balance = _balance;
	transfer_num = 0;
}
void Campus_card::set(string card_id, string stu_id, string stu_name, string _college, double _balance) {
	CardId = card_id;
	StudentID = stu_id;
	StudentName = stu_name;
	college = _college;
	balance = _balance;
	transfer_num = 0;
}
void Campus_card::transfer(double money, deposit_card& a) {
	balance += money;
	time_t t = time(0);
	strftime(transfer_time[transfer_num], sizeof(transfer_time[transfer_num]), "%Y/%m/%d %X", localtime(&t));
	transfer_money[transfer_num++] = money;
	a.pay(money, CardId);
}
void Campus_card::pay(double money) {
	if(balance - money < 0) {
		cout << "余额不足，支付失败" << endl;
		return;
    }
	balance -= money;
	time_t t = time(0);
	strftime(transfer_time[transfer_num], sizeof(transfer_time[transfer_num]), "%Y/%m/%d %X", localtime(&t));
	transfer_money[transfer_num++] = -money;
}
int Campus_card::get_C_transfer() {
	return transfer_num;
}
string Campus_card::get_C_CardID() {
	return CardId;
}
string Campus_card::getStudentId() {
	return StudentID;
}
string Campus_card::get_college() {
	return college;
}
string Campus_card::getStudentName() {
	return StudentName;
}
double Campus_card::get_C_balance() {
	return balance;
}
void Campus_card::set_transfer(int num, double *money, char time[][24], string *place) {
	transfer_num = num;
	int i;
	for (i = 0; i < transfer_num; i++) {
		transfer_money[i] = money[i];
		strcpy(transfer_time[i], time[i]);
		transfer_place[i] = place[i];
	}
}
void Campus_card::C_query(void) {
	int i;
	for(i = 0; i < transfer_num; i++) {
		if(transfer_money[i] > 0) {
			cout << "+" << transfer_money[i] << "    ";
		}
		else {
			cout << transfer_money[i] << "    ";
		}
		cout << transfer_time[i] << endl;
	}
}
char* Campus_card::get_transfer_time(int i) {
	return transfer_time[i];
}
double* Campus_card::get_transfer_money() {
	return transfer_money;
}
string* Campus_card::get_transfer_place() {
	return transfer_place;
}
binding_card::binding_card(){
	deposit_cards_num = 0;
}
binding_card::binding_card(Campus_card * a, deposit_card **b, int Dcard_num) {
	deposit_cards_num = Dcard_num;
	campus_card = a;
	deposit_cards = b;
}
void binding_card::set(Campus_card * a, deposit_card **b, int Dcard_num) {
	deposit_cards_num = Dcard_num;
	campus_card = a;
	deposit_cards = b;
}
void binding_card::pay(double money) {
	int i;
	if(campus_card->get_C_balance() - money < 0) {
		for(i = 0; i < deposit_cards_num; i++) {
			if(deposit_cards[i]->get_D_balance() - money > -10000) {
				deposit_cards[i]->pay(money);
			}
		}
	}
	else {
		campus_card->pay(money);
	}
}
deposit_card** binding_card::get_D() {
	return deposit_cards;
}
Campus_card* binding_card::get_C() {
	return campus_card;
}
int binding_card::get_D_num() {
	return deposit_cards_num;
}


void input(int& Ccard_num, int& Dcard_num, int& Bcard_num, Campus_card *Campus_cards, deposit_card *Deposit_cards, binding_card *Binding_cards) {
	ifstream in;

	in.open("campus_card.txt");
	int i;
	for(i = 0; i < Ccard_num; i++) {
		string C_CardID;
		in >> C_CardID;
		string StudentID;
		in >> StudentID;
		string StudentName;
		in >> StudentName;
		string college;
		in >> college;
		double balance;
		in >> balance;
		Campus_cards[i].set(C_CardID, StudentID, StudentName, college, balance);
	}
	in.close();

	in.open("deposit_card.txt");
	for(i = 0; i < Dcard_num; i++) {
		string D_CardID;
		in >> D_CardID;
		string StudentName;
		in >> StudentName;
		double balance;
		in >> balance;
		Deposit_cards[i].set(D_CardID, StudentName, balance);
	}
	in.close();

	in.open("binding_card.txt");
	for(i = 0; i < Bcard_num; i++) {
		string id;
		in >> id;
		Campus_card * tempC = find_C(id, Campus_cards, Ccard_num);
		int temp;
		in >> temp;
		deposit_card ** tempD = (deposit_card **)malloc(100 * sizeof(deposit_card *));
		for(int j = 0; j < temp; j++) {
			in >> id;
			tempD[j] = find_D(id, Deposit_cards, Dcard_num);
		}
		Binding_cards[i].set(tempC, tempD, temp);
	}
	in.close();

	FILE *fp = fopen("campus_transfer.txt", "r");
	for(i = 0; i < Ccard_num; i++) {
		int transfer_num;
		fscanf(fp, "%d", &transfer_num);
		cout << transfer_num << "m" << endl;
		char transfer_time[100][24];
		double transfer_money[100];
		string transfer_place[100];
		for(int j = 0; j < transfer_num; j++) {
			fscanf(fp, "%lf", &transfer_money[j]);
			fgets(transfer_time[j], sizeof(char) * 30, fp);
			in >> transfer_place[j];
		}
		Campus_cards[i].set_transfer(transfer_num, transfer_money, transfer_time, transfer_place);
	}
	fclose(fp);

	fp = fopen("deposit_transfer.txt", "r");
	for(i = 0; i < Ccard_num; i++) {
		int transfer_num;
		fscanf(fp, "%d", &transfer_num);
		cout << transfer_num << "t" << endl; 
		char transfer_time[100][24];
		double transfer_money[100];
		string transfer_place[100];
		for(int j = 0; j < transfer_num; j++) {
			fscanf(fp, "%lf", &transfer_money[j]);
			fscanf(fp,"%s", transfer_time[j]);
			int k = strlen(transfer_time[j]);
			for(int i = 0; i < 4; i++) {
				transfer_time[j][k + i] = ' ';
			}
			char temp[20];
			fscanf(fp, "%s", temp);
			k += 4;
			for(int i = 0; i < strlen(temp); i++) {
				transfer_time[j][i + k] = temp[i];
			}
			in >> transfer_place[j];
		}
		Deposit_cards[i].set_transfer(transfer_num, transfer_money, transfer_time, transfer_place);
	}
	fclose(fp);
}
void output(int Ccard_num, int Dcard_num, int Bcard_num, Campus_card *Campus_cards, deposit_card *Deposit_cards, binding_card *Binding_cards) {
	ofstream out;

	out.open("campus_card.txt");
	int i;
	for(i = 0; i < Ccard_num; i++) {
		out << Campus_cards[i].get_C_CardID() << endl;
		out << Campus_cards[i].getStudentId() << endl;
		out << Campus_cards[i].getStudentName() << endl;
		out << Campus_cards[i].get_college() << endl;
		out << Campus_cards[i].get_C_balance() << endl;
	}
	out.close();

	out.open("deposit_card.txt");
	for(i = 0; i < Dcard_num; i++) {
		out << Deposit_cards[i].get_D_CardID() << endl;
		out << Deposit_cards[i].getStudentName() << endl;
		out << Deposit_cards[i].get_D_balance() << endl;
	}
	out.close();

	out.open("binding_card.txt");
	for(i = 0; i < Bcard_num; i++) {
		out << Binding_cards[i].get_C()->get_C_CardID() << endl;
		out << Binding_cards[i].get_D_num() << endl;
		for(int j = 0; j < Binding_cards[i].get_D_num(); j++) {
			out << Binding_cards[i].get_D()[i]->get_D_CardID() << endl;
		}
	}
	out.close();

	FILE *fp = fopen("campus_transfer.txt", "w");
	for(i = 0; i < Ccard_num; i++) {
		int transfer_num =  Campus_cards[i].get_C_transfer();
		fprintf(fp, "%d\n", transfer_num);
		for(int j = 0; j < transfer_num; j++) {
			fprintf(fp, "%lf\n", Campus_cards[i].get_transfer_money()[j]);
			fputs(Campus_cards[i].get_transfer_time(j), fp);
			fprintf(fp, "\n");
			out << Campus_cards[i].get_transfer_place()[j] << endl;
		}
	}
	fclose(fp);

	fp = fopen("deposit_transfer.txt", "w");
	for(i = 0; i < Dcard_num; i++) {
		int transfer_num =  Deposit_cards[i].get_D_transfer();
		cout << transfer_num << "t" << endl;
		fprintf(fp, "%d\n", transfer_num);
		for(int j = 0; j < Deposit_cards[i].get_D_transfer(); j++) {
			fprintf(fp, "%lf\n", Deposit_cards[i].get_transfer_money()[j]);
			fputs(Deposit_cards[i].get_transfer_time(j), fp);
			fprintf(fp, "\n");
			out << Deposit_cards[i].get_transfer_place()[j] << endl;
		}
	}
	fclose(fp);
}
