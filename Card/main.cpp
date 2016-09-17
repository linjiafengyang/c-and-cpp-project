#include "card.cpp"
int main() {
	int Dcard_num = 0;
	int Ccard_num = 0;
	int Bcard_num = 0;
	bool is_exit = false;
	deposit_card Deposit_cards[100];
	Campus_card Campus_cards[100];
	binding_card Binding_cards[100];
	input(Ccard_num, Dcard_num, Bcard_num, Campus_cards, Deposit_cards, Binding_cards);
	while(!is_exit) {
		int selection = menu();
		int temp, i, j;
		string id;
		switch(selection) {
			case 1:
				cout << "��������ӵ�У԰������";
				cin >> temp;
				for(i = 0; i < temp; ++i) {
					cout << "�������" << i + 1 << "��У԰�����ţ�" << endl;
					string C_CardID;
					cin >> C_CardID;
					cout << "������ѧ��������" << endl;
					string StudentName;
					cin >> StudentName;
					cout << "������ѧ��ѧ�ţ�" << endl;
					string StudentID;
					cin >> StudentID;
					cout << "������ѧ������ѧԺ��" << endl;
					string college;
					cin >> college;
					cout << "������У԰������" << endl;
					double balance;
					cin >> balance;
					cout << "�ѳɹ���ӵ�" << i + 1 << "��У԰��" << endl;
					Campus_cards[Ccard_num++].set(C_CardID, StudentID, StudentName, college, balance);
				}
				break;
        	case 2:
				cout << "��������ӵĴ������";
				cin >> temp;
				for(i = 0; i < temp; ++i) {
					cout << "�������" << i + 1 << "�Ŵ�����ţ�" << endl;
					string D_CardID;
					cin >> D_CardID;
					cout << "������ѧ��������" << endl;
					string StudentName;
					cin >> StudentName;
					cout << "�����봢�����" << endl;
					double balance;
					cin >> balance;
					cout << "�ѳɹ���ӵ�" << i + 1 << "�Ŵ��" << endl;
					Deposit_cards[Dcard_num++].set(D_CardID, StudentName, balance);
				}
				break;
			case 3:
			{
				cout << "������󶨵�У԰�����ţ�" << endl;
				cin >> id;
				Campus_card * tempC = find_C(id, Campus_cards, Ccard_num);
				cout << "��������Ҫ�󶨵Ĵ������" << endl;
				cin >> temp;
				deposit_card ** tempD = (deposit_card **)malloc(100 * sizeof(deposit_card *));
				for(i = 0; i < temp; ++i) {
					cout << "�������" << i + 1 << "�Ŵ�����ţ�" << endl;
					cin >> id;
					tempD[i] = find_D(id, Deposit_cards, Dcard_num);
					cout << "�ѳɹ��󶨵�" << i + 1 << "�Ŵ��" << endl;
				}
				Binding_cards[Bcard_num++].set(tempC, tempD, temp);
				break;
			}
			case 4:
			{
				cout << "��������Ҫ��ѯ��У԰�����ţ�" << endl;
				cin >> id;
				Campus_card *a = find_C(id, Campus_cards, Ccard_num);
				cout << "У԰�����ţ�" << endl << a->get_C_CardID() << endl;
				cout << "ѧ��������" << endl << a->getStudentName() << endl;
				cout << "ѧ��ѧ�ţ�" << endl << a->getStudentId() << endl;
				cout << "ѧ������ѧԺ" << endl << a->get_college() << endl;
				cout << "��" << endl << a->get_C_balance() << endl;
				cout << "���׼�¼��" << endl;
				a->C_query();
				cout << "�ѳɹ����У԰����Ϣ" << endl;
				break;
			}
			case 5:
			{
				cout << "��������Ҫ��ѯ�Ĵ������" << endl;
				cin >> id;
				deposit_card *b = find_D(id, Deposit_cards, Dcard_num);
				cout << "������ţ�" << endl << b->get_D_CardID() << endl;
				cout << "ѧ��������" << endl << b->getStudentName() << endl;
				cout << "��" << endl << b->get_D_balance() << endl;
				cout << "���׼�¼:" << endl;
				b->D_query();
				cout << "�ѳɹ���ô����Ϣ" << endl;
				break;
			}
			case 6:
			{
				cout << "��������Ҫ��ѯ��У԰��(�Ѱ�)���ţ�" << endl;
				cin >> id;
				binding_card *c = find_B(id, Binding_cards, Bcard_num);
				cout << "У԰�����ţ�" << endl << (c->get_C())->get_C_CardID() << endl;
				cout << "ѧ��������" << endl << (c->get_C())->getStudentName() << endl;
				cout << "ѧ��ѧ�ţ�" << endl << (c->get_C())->getStudentId() << endl;
				cout << "У԰����" << endl << (c->get_C())->get_C_balance() << endl;
				cout << "�ѳɹ���ð󶨿���Ϣ" << endl;
				break;
			}
			case 7:
			{
				double money;
				cout << "��������Ҫ֧���Ľ�" << endl;
				cin >> money;
				cout << "��ѡ��һ��֧����ʽ(1~3)��" << endl;
				cout << "1.У԰��" << endl;
				cout << "2.��� "<< endl;
				cout << "3.�󶨿� "<< endl;
				cin >> temp;
				if(temp == 1) {
					cout << "������У԰�����ţ�" << endl;
					string id;
					cin >> id;
					Campus_card *a = find_C(id, Campus_cards, Ccard_num);
					a->pay(money);
					cout << "�ѳɹ�֧��" << endl; 
				}
				else if(temp == 2) {
					cout << "�����봢����ţ�" << endl;
					string id;
					cin >> id;
					deposit_card *a = find_D(id, Deposit_cards, Dcard_num);
					a->pay(money);
					cout << "�ѳɹ�֧��" << endl;
				}
				else {
					cout << "������У԰��(�Ѱ�)���ţ�" << endl;
					string id;
					cin >> id;
					binding_card *a = find_B(id, Binding_cards, Bcard_num);
					a->pay(money);
					cout << "�ѳɹ�֧��" << endl;
				}
				break;
			}
			case 8:
			{
				cout << "��ѡ��ת�뿨����(1~2)��" << endl;
				cout << "1.У԰��" << endl;
				cout << "2.���" << endl;
				cin >> temp;
				if(temp == 1) {
					cout << "������ת���У԰�����ţ�" << endl;
					string id;
					cin >> id;
					Campus_card *a = find_C(id, Campus_cards, Ccard_num);
					cout << "������ת���Ĵ�����ţ�" << endl;
					cin >> id;
					deposit_card *b = find_D(id, Deposit_cards, Dcard_num);
					cout << "������ת�˽�" << endl;
					double money;
					cin >> money;
					a->transfer(money, *b);
					cout << "ת�˳ɹ�" << endl;
				}
				else if(temp == 2) {
					cout << "������ת��Ĵ�����ţ�" << endl;
					string id;
					cin >> id;
					deposit_card *a = find_D(id, Deposit_cards, Dcard_num);
					cout << "������ת���Ĵ�����ţ�" << endl;
					cin >> id;
					deposit_card *b = find_D(id, Deposit_cards, Dcard_num);
					cout << "������ת�˽�" << endl;
					double money;
					cin >> money;
					a->transfer(money, *b);
					cout << "ת�˳ɹ�" << endl;
				}
				break;
			}
			case 0:
				is_exit = true;
				break;
		}
	}
	output(Ccard_num, Dcard_num, Bcard_num, Campus_cards, Deposit_cards, Binding_cards);
	return 0;
}
