#include "LibrarySystem.cpp" 

int main(){
	vector<Administrator> ad;
	vector<Common_User> cuser;
	Bookcontainer bookself;
	
	ifstream inFile;
	
	inFile.open("user.txt");
	string user_name;
	int account_num, password, id, record_num, user_num;
	string bookname;
	char tmp[100];
	inFile >> user_num;
	int i, j, k;
	for(i = 0; i < user_num; i++){
		inFile >> user_name >> account_num >> password >> id >> record_num;
		cuser.push_back(Common_User(account_num, password, user_name,id));
		for(j = 0; j < record_num; j++) {
			inFile >> tmp >> bookname;
			cuser[i].set_record(tmp, bookname);
		}
	}
	inFile.close();
	
	inFile.open("administrator.txt");
	string ad_name;
	int ad_num;
	inFile >> ad_num;
	for(i = 0; i < ad_num; i++) {
		inFile >> ad_name >> account_num >> password;
		ad.push_back(Administrator(account_num, password, ad_name));
	}
	inFile.close();
	
	inFile.open("book.txt");
	int booktype_num, all_num, year, month, day;
	string ISBN, authorname;
	bool ison;
	inFile >> booktype_num;
	for(i = 0; i < booktype_num; i++) {
		inFile >> all_num >> bookname >> authorname >> ISBN >> year >> month >> day >> ison;
		booktype bktp(all_num, ison, bookname, authorname, ISBN, year, month, day);
		bookself.put_book_in(bktp);
		for(j = 0; j < all_num; j++){
			inFile >> record_num;
			for(k = 0; k < record_num; k++){
				inFile >> user_name >> tmp;
				bookself.getvector()[i]->getvector()[j].set_record(tmp, user_name);
			}
		}
	} 
	inFile.close();
	
	int selection = 0;
	selection = menu();
	while(selection){
		if(selection == 1){
			int selection1;
			cout << "\t\t********************" << endl;
			cout << "\t\t*  ��ѡ��ע�����  *" <<endl;
			cout << "\t\t*    1.����Ա      *" <<endl;
			cout << "\t\t*    2.������      *" <<endl;
			cout << "\t\t********************" << endl;
			cin >> selection1;
			string name;
			int account_num, password, id;
			switch(selection1) {
				case 1:
					cout << "������������";
					cin >> name;
					cout << "�������˺ţ�";
					cin >>  account_num;
					cout << "���������룺";
					cin >> password;
					ad.push_back(Administrator(account_num, password, name));
					cout << "ע��ɹ�" << endl;
					break;
				case 2:	
					cout << "������������";
					cin >> name;
					cout << "�������˺ţ�";
					cin >>  account_num;
					cout << "���������룺";
					cin >> password;
					cout << "������ѧ�ţ�";
					cin >> id;
					cuser.push_back(Common_User(account_num, password, name, id));
					cout << "ע��ɹ�" << endl;
					break;
			}
		}
		if(selection == 2) {
			int selection1;
			int temp;
			cout << "\t\t********************" << endl;
			cout << "\t\t*  ��ѡ���¼���  *" <<endl;
			cout << "\t\t*    1.����Ա      *" <<endl;
			cout << "\t\t*    2.������      *" <<endl;
			cout << "\t\t********************" << endl;
			cin >> selection1;
			if(selection1 == 1) {
				int account_num, password;
				cout << "�������˺�: ";
				cin >> account_num;
				cout << "���������룺";
				cin >> password;
				bool success = true;
				while(success) {
					int i;
					for(i = 0; i < ad.size(); i++) {
						if(account_num == ad[i].getaccountnum()) {
							break;
						}
					}
					if(i == ad.size()) {
						cout << "�˺�������������������˺ź�����" << endl;
						cin >> account_num >> password;
					}
					else {
						if(ad[i].login(account_num, password)) {
							cout << "��¼�ɹ�" << endl;
							temp = i;
							success = false;
						}
						else {
							cout << "������������������˺ź�����" << endl;
							cin >> account_num >> password;
						}
					} 
				}
				cout << "**********************************" << endl;
				cout << "*  1.��ͼ��ݿ��������ISBN����  *" <<endl;
				cout << "*  2.�ϼܻ��¼�ĳ����            *" <<endl;
				cout << "*  3.���������߽���              *" <<endl;
				cout << "*  4.���������߻���              *" <<endl;
				cout << "*  5.����ĳ���������            *" <<endl;
				cout << "*  6.����ĳ���������            *" <<endl;
				cout << "*  0.����                        *" << endl;
				cout << "**********************************" << endl;
				cout << "��ѡ����: ";
				int selection2;
				cin >> selection2;
				while(selection2) {
					string bookname, authorname, ISBN;
					int year, month, day, all_num;
					bool ison;
					if(selection2 == 1) {
						cout << "�������������: ";
						cin >>  bookname;
						cout << "�������������֣�";
						cin >> authorname;
						cout << "������ISBN��";
						cin >> ISBN;
						cout << "�����������ݣ�";
						cin >> year;
						cout << "����������·ݣ�";
						cin >> month;
						cout << "����������գ�";
						cin >> day;
						cout << "���������������";
						cin >> all_num;
						cout << "��ѡ���Ƿ��ϼܣ�����1�ϼܣ�����0���ϼ�" << endl;
						cin >> ison;
						booktype bktp(all_num, ison, bookname, authorname, ISBN, year, month, day);
						bookself.put_book_in(bktp);
					}
					if(selection2 == 2) {
						cout << "�������������" << endl;
						bool is1 = true;
						while(is1) {
							int i;
							cin >> bookname;
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
									cout << "����1�ϼܣ�0�¼�" << endl;
									bool ison;
									cin >> ison;
									if(ison) {
										ad[temp].on_self(*bookself.getvector()[i]);
									}
									else {
										ad[temp].off_self(*bookself.getvector()[i]);
									}
									cout << "�����ɹ�" << endl;
									is1 = false;
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "���鲻���ڣ�����������" << endl;
								cin >> bookname;
							}
						}	
					}
					if(selection2 == 3) {
						cout << "����ѧ��������";
						string user_name;
						cin >> user_name;
						cout << "������������";
						cin >> bookname;
						int i, j;
						bool is = true;
						while(is) {
							for(j = 0; j < cuser.size(); j++) {
								if(cuser[j].getname() == user_name) {
									is = false;
									break;
								}
							}
							if(j == cuser.size()) {
								cout << "ѧ��������������������";
								cin >> user_name;
							}
						}
						is = true;
						while(is) {
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
									int k;
									for(k = 0; k < bookself.getvector()[i]->getvector().size(); k++) {
										if(bookself.getvector()[i]->getvector()[k].getIsborrow() == false) {
											ad[temp].help_borrow(cuser[j],bookself.getvector()[i]->getvector()[k]);
											is = false;
											break;
										}
									}
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "���鲻���ڣ�����������" << endl;
								cin >> bookname;
							}
						}
					}
					if(selection2 == 4) {
						cout << "����ѧ��������";
						string user_name;
						cin >> user_name;
						cout << "������������";
						cin >> bookname;
						int i, j;
						bool is = true;
						while(is) {
							for(j = 0; j < cuser.size(); j++) {
								if(cuser[j].getname() == user_name) {
									is = false;
									break;
								}
							}
							if(j == cuser.size()) {
								cout << "ѧ��������������������";
								cin >> user_name;
							}
						}
						is = true;
						while(is) {
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
									int k;
									for(k = 0; k < bookself.getvector()[i]->getvector().size(); k++) {
										if(bookself.getvector()[i]->getvector()[k].getIsborrow() == true) {
											ad[temp].help_return(cuser[j],bookself.getvector()[i]->getvector()[k]);
											is = false;
											break;
										}
									}
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "���鲻���ڣ�����������" << endl;
								cin >> bookname;
							}
						}
					}//�����ߵ�¼�ɹ����ܵ��� 
					if(selection2 == 5) {
						cout << "����������" << endl;
						bool is1 = true;
						while(is1) {
							cin >> bookname;
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
									cout << "���������ӵ�����" << endl;
									int number;
									cin >> number;
									ad[temp].add_book(*bookself.getvector()[i],number);
									cout << "���ӳɹ�" << endl;
									is1 = false;
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "���鲻���ڣ�����������" << endl;
								cin >> bookname;
							}
						}
					}
					if(selection2 == 6) {
						cout << "����������" << endl;
						bool is1 = true;
						while(is1) {
							cin >> bookname;
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
									cout << "��������ٵ�����" << endl;
									int number;
									cin >> number;
									ad[temp].sub_book(*bookself.getvector()[i], number);
									cout << "ɾ���ɹ�" << endl; 
									is1 = false;
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "���鲻���ڣ�����������" << endl;
								cin >> bookname;
							}
						}
					}
					cout << "������0������һ����" << endl;
					int back;
					cin >> back;
					if(back == 0) {
						system("CLS");
						cout << "**********************************" << endl;
						cout << "*  1.��ͼ��ݿ��������ISBN����  *" <<endl;
						cout << "*  2.�ϼܻ��¼�ĳ����            *" <<endl;
						cout << "*  3.���������߽���              *" <<endl;
						cout << "*  4.���������߻���              *" <<endl;
						cout << "*  5.����ĳ���������            *" <<endl;
						cout << "*  6.����ĳ���������            *" <<endl;
						cout << "*  0.����                        *" << endl;
						cout << "**********************************" << endl;
						cout << "��ѡ����: ";
						cin >> selection2;
					}
				}
			}//�����ߵ�¼���� 
			if(selection1 == 2) {
				int account_num, password;
				cout << "�������˺�: ";
				cin >> account_num;
				cout << "���������룺";
				cin >> password; 
				int temp;
				bool is = true;
				while(is){
					int i;
					for(i = 0; i < cuser.size(); i++){
						if(account_num == cuser[i].getaccountnum()) {
							break;
						}
					}
					if(i == cuser.size()) {
						cout << "�˺�������������������˺ź�����" << endl;
					}
					else {
						if(cuser[i].login(account_num, password)) {
							cout << "��¼�ɹ�" << endl;
							temp = i;
							is = false;
						}
						else {
							cout << "������������������˺ź�����" << endl; 
						}
					}
				}
				cout << "****************************" << endl;
				cout << "*  1.�����鼮              *" << endl;
				cout << "*  2.�黹�鼮              *" << endl;
				cout << "*  3.����һ����ļ�¼      *" << endl;
				cout << "*  4.���Ҹ��˼�¼          *" << endl;
				cout << "*  5.����ͼ�����������    *" << endl;
				cout << "*  0.����                  *" << endl;
				cout << "****************************" << endl;
				cout << "��ѡ����: ";
				int selection2;
				cin >> selection2;
				while(selection2) {		
					if(selection2 == 1) {
						cout << "��������Ҫ���ĵ��鼮������" << endl;
						string bookname;
						cin >> bookname;
						int i;
						bool is = true;
						while(is) {
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname && bookself.getvector()[i]->get_ison() == true){
									int j;
									for(j = 0; j < bookself.getvector()[i]->getvector().size(); j++) {
										if(bookself.getvector()[i]->getvector()[j].getIsborrow() == false) {
											cuser[temp].borrow_book(bookself.getvector()[i]->getvector()[j]);
											is = false;
											break;
										}
									}
									if(j == bookself.getvector()[i]->getvector().size()) {
										cout << "���ѱ����" << endl;
										is = false;
									}
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "�����¼ܻ򲻴��ڣ���������������" << endl;
								cin >> bookname; 
							}
						}
					}//selection2 == 1������ 
					if(selection2 == 2) {
						cout << "��Ҫ�黹���鼮������" << endl;
						string bookname;
						cin >> bookname;
						int i;
						bool is = true;
						while(is) {
							for(i = 0; i < bookself.getSize(); i++) {
								if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
									int j;
									for(j = 0; j < bookself.getvector()[i]->getvector().size(); j++) {
										if(bookself.getvector()[i]->getvector()[j].getIsborrow() == true) {
											cuser[temp].return_book(bookself.getvector()[i]->getvector()[j]);
											is = false;
											break;
										}
									}
									break;
								}
							}
							if(i == bookself.getSize()) {
								cout << "�鲻���ڣ���������������" << endl;
								cin >> bookname;
							}
						}
					}
					if(selection2 == 3) {
						string bookname;
						int number;
						cout << "��������Ҫ���Ҽ�¼��������֣�"; 
						cin >> bookname;
						cout << "�����������ͬ��������ţ���ͬ�����еڼ�������";
						cin >> number;
						int i;
						number--;
						for(i = 0; i < bookself.getSize(); i++) {
							if(bookself.getvector()[i]->getvector()[0].getBookName() == bookname) {
								if(number <= bookself.getvector()[i]->get_all_num()) {
									cuser[temp].book_record(bookself.getvector()[i]->getvector()[number]);
								}
								break;
							}
						}
						if(i == bookself.getSize()) {
							cout << "���鲻����" << endl;
						}
					}
					if(selection2 == 4) {
						cuser[temp].my_record();
					}
					if(selection2 == 5) {
						cuser[temp].search_allbook(bookself);
					}
					cout << "������0������һ����" << endl;
					int back;
					cin >> back;
					if(back == 0) {
						system("CLS");
						cout << "***************************" << endl;
						cout << "*  1.�����鼮             *" << endl;
						cout << "*  2.�黹�鼮             *" << endl;
						cout << "*  3.����һ����ļ�¼     *" << endl;
						cout << "*  4.���Ҹ��˼�¼         *" << endl;
						cout << "*  5.����ͼ�����������   *" << endl;
						cout << "*  0.����                 *" << endl;
						cout << "***************************" << endl;
						cout << "��ѡ����: ";
						cin >> selection2;
					} 
				}
			}//selection1������
		}
		cout << "������0����������" << endl;
		int return_menu;
		cin >> return_menu;
		if(return_menu == 0){
			system("CLS");
			int selection = menu();
		}
	}
	
	ofstream outFile;
	
	outFile.open("book_record.txt");
	outFile << bookself.getSize() << endl;
	for(i = 0; i < bookself.getSize(); i++) {
		outFile << bookself.getvector()[i]->get_all_num() << " " ;
		outFile << bookself.getvector()[i]->getvector()[0].getBookName() << " " << bookself.getvector()[i]->getvector()[0].getAuthorName();
		outFile << " " << bookself.getvector()[i]->getvector()[0].getISBN() << " ";
		outFile << bookself.getvector()[i]->getvector()[0].getPublicYear() << " " << bookself.getvector()[i]->getvector()[0].getPublicMonth();
		outFile << " " << bookself.getvector()[i]->getvector()[0].getPublicDay() << " ";
		outFile << bookself.getvector()[i]->get_ison() << endl;
		for(j = 0; j < bookself.getvector()[i]->get_all_num(); j++) {
			outFile << bookself.getvector()[i]->getvector()[j].get_record_num() << endl;
			for(k = 0; k < bookself.getvector()[i]->getvector()[j].get_record_num(); k++) {
				outFile << bookself.getvector()[i]->getvector()[j].get_record()[k].user_name << " ";
				outFile << bookself.getvector()[i]->getvector()[j].get_record()[k].tmp << endl;
			}
		}
	}
	outFile.close();
	
	outFile.open("user_record.txt");
	outFile << cuser.size() << endl;
	for(i = 0; i < cuser.size(); i++) {
		outFile << cuser[i].getname() << " " << cuser[i].getaccountnum() << " " << cuser[i].getpassword() << " ";
		outFile << cuser[i].get_id() << " " << cuser[i].get_record_num() << endl;
		for(j = 0;j < cuser[i].get_record_num();j++){
			outFile << cuser[i].get_record()[j].tmp << " ";
			outFile << cuser[i].get_record()[j].bookname << endl;
		}
	}
	outFile.close();
	
	outFile.open("administrator_record.txt");
	outFile << ad.size() << endl;
	for(i = 0; i < ad.size(); i++) {
		outFile << ad[i].getname() << " " << ad[i].getaccountnum() << " " << ad[i].getpassword() << endl;
	}
	outFile.close();
	
	return 0;
}
