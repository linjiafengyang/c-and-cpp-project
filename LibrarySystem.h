#ifndef LibrarySystem_H
#define LibrarySystem_H

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<iomanip>
#include<ctime>
#include<stdexcept>
using namespace std;

enum choice{Borrow_book, Return_book};//ö�٣�ѡ����Ļ��ǹ黹���� 
struct User_Record {//��¼�û��Ľ��ļ�¼
	char tmp[100];
	string bookname;
};
struct Book_Record {//��¼ĳ����Ľ�����Ϣ 
	char tmp[100];
	string user_name;
};
//�쳣����ļ������� 
class PasswordException: public logic_error {//����������� 
	public:
		PasswordException(): logic_error("Invalid Password") {}
};
class BookException: public logic_error{//�鼮�������� 
	public:
		BookException(): logic_error("Non-existent Book") {}
};
class UserException: public logic_error{//�û��������� 
	public:
		UserException(): logic_error("Non-existent User") {}
};

class Book {
	public:
		Book();//Ĭ�Ϲ��캯�� 
		Book(string bookname, string authorname, string ISBN, int year, int month, int day);//���캯������������������ISBN���������� 
		void set_borrow(bool borrow);//�鱻�� 
		void show_record();//չʾ��Ľ��ļ�¼ 
		void record_message(string user_name,choice selection);//��¼���Ļ�黹��Ϣ�������ֱ�Ϊ�û��������Զ���ı�ʾ���Ļ��ǹ黹���� 
		int getPublicYear() const;//���س������ 
		int getPublicMonth() const;//���س����·� 
		int getPublicDay() const;//���س������� 
		bool getIsborrow() const;//���ش����Ƿ񱻽� 
		string getBookName() const;//����������� 
		string getAuthorName() const;//������������ 
		string getISBN() const;//����ISBN 
		int get_record_num();//������Ľ��ĺ͹黹���� 
		void set_record(char* tmp, string user_name);//д����Ľ��Ĺ黹��¼ 
		vector<Book_Record>& get_record();//����record��Ա 
	private:
		bool isborrow;//�鱻�� 
		string bookname;//����
		string authorname;//�������� 
		string ISBN;//���ISBN 
		int public_year;//��ĳ������ 
		int public_month;//��ĳ����·� 
		int public_day;//��ĳ�����
		vector<Book_Record> record;//��¼��Ľ���/�黹���� 
};
class booktype {
	public:
		booktype();//Ĭ�Ϲ��캯�� 
		booktype(int all_num, bool ison, string bookname, string authorname, string ISBN, int year, int month, int day);
		//���캯�� 
		booktype(const booktype& bk);//�������캯�� 
		void operator+=(int num);//���Ӹ���������� 
		void operator-=(int num);//���ٸ���������� 
		void on_book();//�ϼܸ����� 
		void off_book();//�¼ܸ����� 
		vector<Book>& getvector();//����˽�г�Աbook 
		int get_all_num() const;//��ȡ������� 
		bool get_ison() const;//���ظ������Ƿ��ϼ� 
	private:
		vector<Book> book;//���ͬһ����Ķ��� 
		int all_num;//��������� 
		bool ison;//�������Ƿ��ϼ� 
};
class Bookcontainer {
	public:
		Bookcontainer();//Ĭ�Ϲ��캯�� 
		~Bookcontainer();//�������� 
		Bookcontainer(const Bookcontainer& book);//�������캯�� 
		void show_allbook();//չʾ��ǰͼ����������� 
		void put_book_in(const booktype& book);//��ͼ��� 
		Bookcontainer operator=(const Bookcontainer& book);//�Ⱥ����� 
		vector<booktype*>& getvector(); //���س�Աbookself 
		bool empty();//�Ƿ������ 
		int getSize();//��ȡ����size 
	private:
		vector<booktype*> bookself;//ָ��booktype��ָ��vector 
		int size;//������С 
};
class User {
	public:
		User();//Ĭ�Ϲ��캯�� 
		User(int account_num1, int password1, string name1);//���캯�� 
		virtual bool login(int account_num, int password) throw(PasswordException) = 0;
		//��¼���� 
		virtual void register_(int account_num, int password) = 0;//ע�ắ�� 
		void set_account_num(int account_num1);//�����˺� 
		void set_password(int password1);//�������� 
		int getaccountnum();//��ȡ�˺� 
		string getname();//��ȡ�û����� 
		int getpassword();//��ȡ���� 
	private:
		int account_num;//�˺� 
		int password;//���� 
		string name;//�û����� 
};
class Common_User : public User {
	public:
		Common_User();//Ĭ�Ϲ��캯�� 
		Common_User(int account_num1, int password1, string name1, int id1);//���캯�� 
		bool login(int account_num, int password) throw(PasswordException);//��¼ 
		void register_(int account_num, int password);//ע�� 
		void borrow_book(Book& book);//���� 
		void return_book(Book& book);//���� 
		void search_allbook(Bookcontainer& book);//��ѯ�����鼮 
		void my_record();//��ѯ�Լ��Ľ��ļ�¼ 
		void book_record(Book& book);//��ѯĳ����Ľ��Ĺ黹��¼ 
		void record_message(string bookname, choice what);//��¼������Ϣ 
		int get_record_num();//���ؼ�¼��Ϣ���� 
		int get_id();//��ȡid 
		bool& get_isblacklist();//����isblack 
		vector<User_Record>& get_record();//���ؼ�¼��Ϣ��record 
		void set_record(char* tmp, string bookname);//����record��ֵ 
	private:
		vector<User_Record> record;
		int id;
		bool isblack;
};
class Administrator: public User {
	public:
		Administrator();//Ĭ�Ϲ��캯�� 
		Administrator(int account_num1, int password1, string name1);//���캯�� 
		bool login(int account_num, int password) throw(PasswordException);//��¼ 
		void register_(int account_num, int password);//ע�� 
		void help_borrow(Common_User& user, Book& book);//�����û����� 
		void help_return(Common_User& user, Book& book);//�����û��黹 
		void on_self(booktype& book);//�ϼ�ĳ���� 
		void off_self(booktype& book);//�¼�ĳ���� 
		void set_user_blacklist(Common_User& user);//���ú����� 
		void add_book(booktype& book, int num);//����������� 
		void sub_book(booktype& book, int num);//����������� 
};
#endif
