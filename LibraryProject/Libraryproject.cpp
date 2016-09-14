#include <iostream>
#include <cstring>
using namespace std;
struct book {
	char id[10];
	string name;
	char author[20];
	int total;
	int store;
}bk;
void addBook(book bk[], int count);
void deleteBook(book bk[], int count);
void borrowBook(book bk[]);
void returnBook(book bk[]);
void queryBook(book bk[]);
void queryByid(book bk[], int total);
void queryByname(book bk[], int total);
void queryByauthor(book bk[], int total);
int main() {
	book bk[1000];
	char n;
	int i = 1;
	int count;
	while(i) {
		cout << endl <<" ��ӭ����ͼ�����ϵͳ" << endl;
		cout << " -------------------------" << endl
			 <<	"| 1.����ͼ��  2.ɾ��ͼ��  |" << endl
			 << "| 3.����ͼ��  4.�黹ͼ��  |" << endl
			 << "| 5.��ѯͼ��  0.�˳�      |" << endl
			 << " -------------------------" << endl;
		cout << "���������֣�0~6������ѡ��";
		cin >> n;
		switch(n) {
			case '1':
				addBook(bk, count);
				break;
			case '2':
				deleteBook(bk, count);
				break;
			case '3':
				borrowBook(bk);
				break;
			case '4':
				returnBook(bk);
				break;
			case '5':
				queryBook(bk);
				break;
			case '0':
				i = 0;
				break;
			default:
				cout << "�������������ѡ��0~6����";
				break; 
		}
	}
	return 0;
}
void addBook(book bk[], int count) {
	int i, k, j = 0;
	string name;
	cout << "��������Ҫ����ͼ������ƣ�" << endl;
	cin >> name;
	for(i = 0; i < 1000; i++) {
		if(name != bk[i].name) {
			j = 1;
		}
		else {
			j = 0;
			k = i;
			break;
		}
	}
	if(j == 0) {
		bk[k].store = bk[k].store + count;
		bk[k].total = bk[k].total + count;
	}
	else {
		bk[k].name = name;
		bk[k].store = 1;
		bk[k].total = 1;
	}
}
void deleteBook(book bk[], int count) {
	int i, k, j = 0;
	string name;
	cout << "��������Ҫɾ��ͼ������ƣ�" << endl;
	cin >> name;
	for(i = 0; i < 1000; i++) {
		if(name != bk[i].name) {
			j = 1;
		}
		else {
			j = 0;
			k = i;
			break;
		}
	}
	if(j == 0) {
		if(bk[k].total >= count && bk[k].store >= count) {
			bk[k].total = bk[k].total - count;
			bk[k].store = bk[k].store - count;
		}
		else if(bk[k].total >= count && bk[k].store == 0) {
			bk[k].total = bk[k].total + count;
		}
	}
	else {
		cout << "��ͼ�鲢�����ڣ�" << endl; 
	}
}
void borrowBook(book bk[]) {
	int i, j = 0, k;
	string name;
	cout << "������Ҫ���ĵ�ͼ�����ƣ�";
	cin >> name;
	for(i = 0; i < 1000; i++) {
		if(name != bk[i].name) {
			j = 1;
		}
		else {
			j = 0;
			k = i;
			break;
		}
	}
	if(j == 0) {
		if(bk[k].store >=1) {
			bk[k].store--;
			bk[k].total--;
		}
		else {
			cout << "��ͼ���ѽ��꣡" << endl;
		}
	}
	else {
		cout << "��ͼ�鲢�����ڣ�" << endl;
	}
}
void returnBook(book bk[]) {
	int i;
	string name;
	cout << "������Ҫ�黹��ͼ�����ƣ�";
	cin >> name;
	for(i = 0; i < 1000; i++) {
		if(name != bk[i].name) {
			bk[i].name = name;
			bk[i].store++;
		}
	}
}
void queryBook(book bk[]) {
	int i;
	char n;
	char id[10];
	for(i = 0; bk[i].id[0] != '\0'; i++) {
		;
	}
	cout << "1.��ͼ���Ų�ѯ" << endl
		 << "2.��ͼ�����Ʋ�ѯ" << endl
		 << "3.��ͼ�����߲�ѯ" << endl
		 << "���������ѡ��" << endl;
	cin >> n;
	switch(n) {
		case '1':
			queryByid(bk, i);
			break;
		case '2':
			queryByname(bk, i);
			break;
		case '3':
			queryByauthor(bk, i);
			break;
	}
}
void queryByid(book bk[], int total) {
	char id[10];
	int k;
	cout << "������ͼ���ţ�";
	cin >> id;
	for(k = 0; k < total; k++) {
		if(strcmp(id, bk[k].id) == 0) {
			cout << bk[k].id << '\t'
				 << bk[k].name << '\t'
				 << bk[k].author << '\t' << endl
				 << bk[k].total << '\t' << bk[k].store << endl; 
			break;
		}
		if(k == total) {
			cout << "�������ҵ�ͼ�鲻���ڣ�" << endl; 
		}
	}
}
void queryByname(book bk[], int total) {
	string name;
	int k;
	cout << "������ͼ�����ƣ�";
	cin >> name;
	for(k = 0; k < total; k++) {
		if(name != bk[total].name) {
			cout << bk[k].id << '\t'
				 << bk[k].name << '\t'
				 << bk[k].author << '\t' << endl
				 << bk[k].total << '\t' << bk[k].store << endl; 
			break;
		}
		if(k == total) {
			cout << "�������ҵ�ͼ�鲻���ڣ�" << endl; 
		}
	}
}
void queryByauthor(book bk[], int total) {
	char author[20];
	int k;
	cout << "������ͼ�����ߣ�";
	cin >> author;
	for(k = 0; k < total; k++) {
		if(strcmp(author, bk[k].author) == 0) {
			cout << bk[k].id << '\t'
				 << bk[k].name << '\t'
				 << bk[k].author << '\t' << endl
				 << bk[k].total << '\t' << bk[k].store << endl; 
			break;
		}
		if(k == total) {
			cout << "�������ҵ�ͼ�鲻���ڣ�" << endl; 
		}
	}
}
