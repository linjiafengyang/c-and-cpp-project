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
		cout << endl <<" 欢迎进入图书管理系统" << endl;
		cout << " -------------------------" << endl
			 <<	"| 1.增加图书  2.删除图书  |" << endl
			 << "| 3.借阅图书  4.归还图书  |" << endl
			 << "| 5.查询图书  0.退出      |" << endl
			 << " -------------------------" << endl;
		cout << "请输入数字（0~6）进行选择：";
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
				cout << "输入错误，请重新选择（0~6）：";
				break; 
		}
	}
	return 0;
}
void addBook(book bk[], int count) {
	int i, k, j = 0;
	string name;
	cout << "请输入所要增加图书的名称：" << endl;
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
	cout << "请输入所要删除图书的名称：" << endl;
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
		cout << "该图书并不存在！" << endl; 
	}
}
void borrowBook(book bk[]) {
	int i, j = 0, k;
	string name;
	cout << "请输入要借阅的图书名称：";
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
			cout << "该图书已借完！" << endl;
		}
	}
	else {
		cout << "该图书并不存在！" << endl;
	}
}
void returnBook(book bk[]) {
	int i;
	string name;
	cout << "请输入要归还的图书名称：";
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
	cout << "1.按图书编号查询" << endl
		 << "2.按图书名称查询" << endl
		 << "3.按图书作者查询" << endl
		 << "请输入号码选择：" << endl;
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
	cout << "请输入图书编号：";
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
			cout << "您所查找的图书不存在！" << endl; 
		}
	}
}
void queryByname(book bk[], int total) {
	string name;
	int k;
	cout << "请输入图书名称：";
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
			cout << "您所查找的图书不存在！" << endl; 
		}
	}
}
void queryByauthor(book bk[], int total) {
	char author[20];
	int k;
	cout << "请输入图书作者：";
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
			cout << "您所查找的图书不存在！" << endl; 
		}
	}
}
