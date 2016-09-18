#include "LibrarySystem.h"

int menu(){
	cout << endl;
	cout << "\t\t****************************" << endl;
	cout << "\t\t*   欢迎使用图书管理系统   *" << endl;
	cout << "\t\t*         1.注册           *" << endl;
	cout << "\t\t*         2.登录           *" << endl;
	cout << "\t\t*         0.退出           *" << endl;
	cout << "\t\t****************************" << endl;
	cout << "  请输入数字选择功能：";
	int sct;
	cin >> sct;
	return sct;
}
Book::Book() {
	isborrow = false;
	bookname = "";
	authorname = "";
	ISBN = "";
	public_year = 0;
	public_month = 0;
	public_day = 0;
}
Book::Book(string bookname, string authorname, string ISBN, int year, int month, int day) {
	isborrow = false;
	this->bookname = bookname;
	this->authorname = authorname;
	this->ISBN = ISBN;
	public_year = year;
	public_month = month;
	public_day = day;
}
void Book::set_borrow(bool borrow) {
	isborrow = borrow;
}
void Book::set_record(char* tmp,string user_name) {
	Book_Record temp;
	strcpy(temp.tmp, tmp);
	temp.user_name = user_name;
	record.push_back(temp);
}
string Book::getAuthorName() const {
	return authorname;
}
string Book::getBookName() const {
	return bookname;
}
string Book::getISBN() const {
	return ISBN;
}
bool Book::getIsborrow() const {
	return isborrow;
}
int Book::get_record_num() {
	return record.size();
}
int Book::getPublicYear() const {
	return public_year;
}
int Book::getPublicMonth() const {
	return public_month;
}
int Book::getPublicDay() const {
	return public_day;
}
vector<Book_Record>& Book::get_record() {
	return record;
}
void Book::record_message(string user_name, choice selection) {
	time_t t = time(0);
	Book_Record temp;
	strftime(temp.tmp, sizeof(temp.tmp), "%Y/%m/%d-%X-%z", localtime(&t));
	string op;
	if(selection == Borrow_book) {
		op = "借阅";
	}
	else if(selection == Return_book) {
		op = "归还";
	}
	int i, j;
	for(i = 0, j = strlen(temp.tmp); i < op.length(); i++, j++) {
		temp.tmp[j] = op[i];
	}
	temp.tmp[j] = 0;
	temp.user_name = user_name;
	record.push_back(temp);
}
void Book::show_record() {
	int i;
	for(i = 0; i < get_record_num(); i++) {
		cout << setiosflags(ios::left); 
		cout << setw(10) << record[i].user_name << setw(30) << record[i].tmp;
		cout << resetiosflags(ios::left);
		cout << endl;
	}
}

booktype::booktype() {
	all_num = 0;
	ison = true;
}
booktype::booktype(int all_num, bool ison, string bookname, string authorname, string ISBN, int year, int month, int day) {
	this->all_num = all_num;
	this->ison = ison;
	int i;
	for(i = 0; i < all_num; i++) {
		book.push_back(Book(bookname, authorname, ISBN, year, month, day));
	}
}
void booktype::operator+=(int num) {
	all_num += num;
	int i;
	for(i = 0; i < num; i++) {
		book.push_back(Book(book[0].getBookName(), book[0].getAuthorName(), book[0].getISBN(), book[0].getPublicYear(),book[0].getPublicMonth(),book[0].getPublicDay()));
	}
}
void booktype::operator-=(int num) {
	all_num -= num;
	int i;
	book.erase(book.end() - num, book.end());
}
booktype::booktype(const booktype& bk) {
	all_num = bk.get_all_num();
	ison = bk.get_ison();
	book = bk.book;
}
void booktype::on_book() {
	ison = true;
}
void booktype::off_book() {
	ison = false;
}
int booktype::get_all_num() const {
	return all_num;
}
bool booktype::get_ison() const {
	return ison;
}
vector<Book>& booktype::getvector() {
	return book;
}

Bookcontainer::Bookcontainer() {
	size = 0;
}
Bookcontainer::~Bookcontainer() {
	int i;
	for(i = 0; i < size; i++) {
		delete bookself[i];
	}
	size = 0;
}
Bookcontainer::Bookcontainer(const Bookcontainer& book) {
	size = book.size;
	int i;
	for(i = 0; i < size; i++){
		bookself[i] = new booktype(*book.bookself[i]);
	}
}
Bookcontainer Bookcontainer::operator=(const Bookcontainer& book) {
	Bookcontainer temp(book);
	return book;
}
bool Bookcontainer::empty() {
	return (size == 0);
}
int Bookcontainer::getSize() {
	return size; 
}
void Bookcontainer::put_book_in(const booktype& book) {
	booktype* temp = new booktype(book);
	bookself.push_back(temp);
	size++;
}
vector<booktype*>& Bookcontainer::getvector() {
	return bookself;
}

User::User() {
	account_num = 0;
	password = 0;
	name = "";
}
User::User(int account_num1, int password1, string name1 = "") {
	account_num = account_num1;
	password = password1;
	name = name1;
}
void User::set_account_num(int account_num1) {
	account_num = account_num1;
}
void User::set_password(int password1) {
	password = password1;
}
int User::getaccountnum() {
	return account_num;
}
int User::getpassword() {
	return password;
}
string User::getname() {
	return name;
}
int Common_User::get_id() {
	return id;
}
bool& Common_User::get_isblacklist() {
	return isblack;
}

Common_User::Common_User(): User() {
	id = 0;
	isblack = false;
}
Common_User::Common_User(int account_num1, int password1, string name1, int id1): User(account_num1, password1, name1) {
	id = id1;
	isblack = false;
}
void Common_User::register_(int account_num1, int password1) {
	set_account_num(account_num1);
	set_password(password1);
}
bool Common_User::login(int account_num, int password) throw(PasswordException) {
	if(account_num == getaccountnum() && password == getpassword()) {
		return true;
	}
	else {
		throw PasswordException();
	}
}
void Common_User::set_record(char* tmp, string bookname) {
	User_Record temp;
	strcpy(temp.tmp, tmp);
	temp.bookname = bookname;
	record.push_back(temp);
}
int Common_User::get_record_num() {
	return record.size();
}
void Common_User::borrow_book(Book& book){
	book.set_borrow(true);
	choice a = Borrow_book;
	book.record_message(getname(), a);
	record_message(book.getBookName(), a);
}
void Common_User::return_book(Book& book){
	book.set_borrow(false);
	choice a = Return_book;
	book.record_message(getname(), a);
	record_message(book.getBookName(), a);
}
void Common_User::search_allbook(Bookcontainer& book) {
	cout << "图书馆内藏书如下" << endl;
	int i;
	for(i = 0;i < book.getvector().size();i++){
		cout << "书名：" << book.getvector()[i]->getvector()[0].getBookName() << "  数量：" << book.getvector()[i]->get_all_num();
		cout << "  作者：" << book.getvector()[i]->getvector()[0].getAuthorName() << "  出版日期：";
		cout << book.getvector()[i]->getvector()[0].getPublicYear() << "-" << book.getvector()[i]->getvector()[0].getPublicMonth();
		cout << "-" << book.getvector()[i]->getvector()[0].getPublicDay() << endl;
	}
}
void Common_User::my_record() {
	int i;
	for(i = 0; i < get_record_num(); i++) {
		cout << setiosflags(ios::left); 
		cout << setw(10) << record[i].bookname << setw(30) << record[i].tmp;
		cout << resetiosflags(ios::left);
		cout << endl;
	}
}
void Common_User::record_message(string bookname, choice selection){
	time_t t = time(0);
	User_Record temp;
	strftime(temp.tmp, sizeof(temp.tmp), "%Y/%m/%d-%X-%z", localtime(&t));
	string op;
	if(selection == Borrow_book) {
		op = "借阅";
	}
	else if(selection == Return_book) {
		op = "归还";
	}
	int i, j;
	for(i = 0, j = strlen(temp.tmp); i < op.length(); i++, j++) {
		temp.tmp[j] = op[i];
	}
	temp.tmp[j] = 0;
	temp.bookname = bookname;
	record.push_back(temp);
}
void Common_User::book_record(Book& book) {
	book.show_record();
}
vector<User_Record>& Common_User::get_record() {
	return record;
}

Administrator::Administrator(): User() {}
Administrator::Administrator(int account_num1, int password1, string name1): User(account_num1, password1, name1) {}
void Administrator::register_(int account_num, int password) {
	set_account_num(account_num);
	set_password(password);
}
bool Administrator::login(int account_num, int password) throw(PasswordException) {
	if(account_num == getaccountnum() && password == getpassword()) {
		return true;
	}
	else {
		throw PasswordException();
	}
}
void Administrator::help_borrow(Common_User& user, Book& book) {
	user.borrow_book(book);
}
void Administrator::help_return(Common_User& user, Book& book) {
	user.return_book(book);
}
void Administrator::on_self(booktype& book) {
	book.on_book();
}
void Administrator::off_self(booktype& book) {
	book.off_book();
}
void Administrator::add_book(booktype& book, int num) {
	book += num;
}
void Administrator::sub_book(booktype& book,int num) {
	book -= num;
}
void Administrator::set_user_blacklist(Common_User& user) {
	user.get_isblacklist() = true;
}
