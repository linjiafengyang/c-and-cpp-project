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

enum choice{Borrow_book, Return_book};//枚举：选择借阅还是归还操作 
struct User_Record {//记录用户的借阅记录
	char tmp[100];
	string bookname;
};
struct Book_Record {//记录某本书的借阅信息 
	char tmp[100];
	string user_name;
};
//异常处理的几种类型 
class PasswordException: public logic_error {//密码错误类型 
	public:
		PasswordException(): logic_error("Invalid Password") {}
};
class BookException: public logic_error{//书籍错误类型 
	public:
		BookException(): logic_error("Non-existent Book") {}
};
class UserException: public logic_error{//用户错误类型 
	public:
		UserException(): logic_error("Non-existent User") {}
};

class Book {
	public:
		Book();//默认构造函数 
		Book(string bookname, string authorname, string ISBN, int year, int month, int day);//构造函数，书名，作者名，ISBN，出版日期 
		void set_borrow(bool borrow);//书被借 
		void show_record();//展示书的借阅记录 
		void record_message(string user_name,choice selection);//记录借阅或归还信息，参数分别为用户姓名和自定义的表示借阅还是归还类型 
		int getPublicYear() const;//返回出版年份 
		int getPublicMonth() const;//返回出版月份 
		int getPublicDay() const;//返回出版日期 
		bool getIsborrow() const;//返回此书是否被借 
		string getBookName() const;//返回书的名字 
		string getAuthorName() const;//返回作者名字 
		string getISBN() const;//返回ISBN 
		int get_record_num();//返回书的借阅和归还次数 
		void set_record(char* tmp, string user_name);//写入书的借阅归还记录 
		vector<Book_Record>& get_record();//返回record成员 
	private:
		bool isborrow;//书被借 
		string bookname;//书名
		string authorname;//作者名字 
		string ISBN;//书的ISBN 
		int public_year;//书的出版年份 
		int public_month;//书的出版月份 
		int public_day;//书的出版日
		vector<Book_Record> record;//记录书的借阅/归还日期 
};
class booktype {
	public:
		booktype();//默认构造函数 
		booktype(int all_num, bool ison, string bookname, string authorname, string ISBN, int year, int month, int day);
		//构造函数 
		booktype(const booktype& bk);//拷贝构造函数 
		void operator+=(int num);//增加该种书的数量 
		void operator-=(int num);//减少该种书的数量 
		void on_book();//上架该种书 
		void off_book();//下架该种书 
		vector<Book>& getvector();//返回私有成员book 
		int get_all_num() const;//获取书的总量 
		bool get_ison() const;//返回该种书是否上架 
	private:
		vector<Book> book;//存放同一种书的对象 
		int all_num;//书的总数量 
		bool ison;//该种书是否上架 
};
class Bookcontainer {
	public:
		Bookcontainer();//默认构造函数 
		~Bookcontainer();//析构函数 
		Bookcontainer(const Bookcontainer& book);//拷贝构造函数 
		void show_allbook();//展示当前图书馆内所有书 
		void put_book_in(const booktype& book);//往图书馆 
		Bookcontainer operator=(const Bookcontainer& book);//等号重载 
		vector<booktype*>& getvector(); //返回成员bookself 
		bool empty();//是否空容器 
		int getSize();//获取容器size 
	private:
		vector<booktype*> bookself;//指向booktype的指针vector 
		int size;//容器大小 
};
class User {
	public:
		User();//默认构造函数 
		User(int account_num1, int password1, string name1);//构造函数 
		virtual bool login(int account_num, int password) throw(PasswordException) = 0;
		//登录函数 
		virtual void register_(int account_num, int password) = 0;//注册函数 
		void set_account_num(int account_num1);//设置账号 
		void set_password(int password1);//设置密码 
		int getaccountnum();//获取账号 
		string getname();//获取用户名字 
		int getpassword();//获取密码 
	private:
		int account_num;//账号 
		int password;//密码 
		string name;//用户密码 
};
class Common_User : public User {
	public:
		Common_User();//默认构造函数 
		Common_User(int account_num1, int password1, string name1, int id1);//构造函数 
		bool login(int account_num, int password) throw(PasswordException);//登录 
		void register_(int account_num, int password);//注册 
		void borrow_book(Book& book);//借书 
		void return_book(Book& book);//还书 
		void search_allbook(Bookcontainer& book);//查询所有书籍 
		void my_record();//查询自己的借阅记录 
		void book_record(Book& book);//查询某本书的借阅归还记录 
		void record_message(string bookname, choice what);//记录借阅信息 
		int get_record_num();//返回记录消息条数 
		int get_id();//获取id 
		bool& get_isblacklist();//返回isblack 
		vector<User_Record>& get_record();//返回记录消息的record 
		void set_record(char* tmp, string bookname);//设置record的值 
	private:
		vector<User_Record> record;
		int id;
		bool isblack;
};
class Administrator: public User {
	public:
		Administrator();//默认构造函数 
		Administrator(int account_num1, int password1, string name1);//构造函数 
		bool login(int account_num, int password) throw(PasswordException);//登录 
		void register_(int account_num, int password);//注册 
		void help_borrow(Common_User& user, Book& book);//帮助用户借阅 
		void help_return(Common_User& user, Book& book);//帮助用户归还 
		void on_self(booktype& book);//上架某种书 
		void off_self(booktype& book);//下架某种书 
		void set_user_blacklist(Common_User& user);//设置黑名单 
		void add_book(booktype& book, int num);//增加书的数量 
		void sub_book(booktype& book, int num);//减少书的数量 
};
#endif
