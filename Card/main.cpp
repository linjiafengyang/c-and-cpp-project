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
				cout << "请输入添加的校园卡数：";
				cin >> temp;
				for(i = 0; i < temp; ++i) {
					cout << "请输入第" << i + 1 << "张校园卡卡号：" << endl;
					string C_CardID;
					cin >> C_CardID;
					cout << "请输入学生姓名：" << endl;
					string StudentName;
					cin >> StudentName;
					cout << "请输入学生学号：" << endl;
					string StudentID;
					cin >> StudentID;
					cout << "请输入学生所在学院：" << endl;
					string college;
					cin >> college;
					cout << "请输入校园卡的余额：" << endl;
					double balance;
					cin >> balance;
					cout << "已成功添加第" << i + 1 << "张校园卡" << endl;
					Campus_cards[Ccard_num++].set(C_CardID, StudentID, StudentName, college, balance);
				}
				break;
        	case 2:
				cout << "请输入添加的储蓄卡数：";
				cin >> temp;
				for(i = 0; i < temp; ++i) {
					cout << "请输入第" << i + 1 << "张储蓄卡卡号：" << endl;
					string D_CardID;
					cin >> D_CardID;
					cout << "请输入学生姓名：" << endl;
					string StudentName;
					cin >> StudentName;
					cout << "请输入储蓄卡的余额：" << endl;
					double balance;
					cin >> balance;
					cout << "已成功添加第" << i + 1 << "张储蓄卡" << endl;
					Deposit_cards[Dcard_num++].set(D_CardID, StudentName, balance);
				}
				break;
			case 3:
			{
				cout << "请输入绑定的校园卡卡号：" << endl;
				cin >> id;
				Campus_card * tempC = find_C(id, Campus_cards, Ccard_num);
				cout << "请输入需要绑定的储蓄卡数：" << endl;
				cin >> temp;
				deposit_card ** tempD = (deposit_card **)malloc(100 * sizeof(deposit_card *));
				for(i = 0; i < temp; ++i) {
					cout << "请输入第" << i + 1 << "张储蓄卡卡号：" << endl;
					cin >> id;
					tempD[i] = find_D(id, Deposit_cards, Dcard_num);
					cout << "已成功绑定第" << i + 1 << "张储蓄卡" << endl;
				}
				Binding_cards[Bcard_num++].set(tempC, tempD, temp);
				break;
			}
			case 4:
			{
				cout << "请输入需要查询的校园卡卡号：" << endl;
				cin >> id;
				Campus_card *a = find_C(id, Campus_cards, Ccard_num);
				cout << "校园卡卡号：" << endl << a->get_C_CardID() << endl;
				cout << "学生姓名：" << endl << a->getStudentName() << endl;
				cout << "学生学号：" << endl << a->getStudentId() << endl;
				cout << "学生所在学院" << endl << a->get_college() << endl;
				cout << "余额：" << endl << a->get_C_balance() << endl;
				cout << "交易记录：" << endl;
				a->C_query();
				cout << "已成功获得校园卡信息" << endl;
				break;
			}
			case 5:
			{
				cout << "请输入需要查询的储蓄卡卡号" << endl;
				cin >> id;
				deposit_card *b = find_D(id, Deposit_cards, Dcard_num);
				cout << "储蓄卡卡号：" << endl << b->get_D_CardID() << endl;
				cout << "学生姓名：" << endl << b->getStudentName() << endl;
				cout << "余额：" << endl << b->get_D_balance() << endl;
				cout << "交易记录:" << endl;
				b->D_query();
				cout << "已成功获得储蓄卡信息" << endl;
				break;
			}
			case 6:
			{
				cout << "请输入需要查询的校园卡(已绑定)卡号：" << endl;
				cin >> id;
				binding_card *c = find_B(id, Binding_cards, Bcard_num);
				cout << "校园卡卡号：" << endl << (c->get_C())->get_C_CardID() << endl;
				cout << "学生姓名：" << endl << (c->get_C())->getStudentName() << endl;
				cout << "学生学号：" << endl << (c->get_C())->getStudentId() << endl;
				cout << "校园卡余额：" << endl << (c->get_C())->get_C_balance() << endl;
				cout << "已成功获得绑定卡信息" << endl;
				break;
			}
			case 7:
			{
				double money;
				cout << "请输入需要支付的金额：" << endl;
				cin >> money;
				cout << "请选择一种支付方式(1~3)：" << endl;
				cout << "1.校园卡" << endl;
				cout << "2.储蓄卡 "<< endl;
				cout << "3.绑定卡 "<< endl;
				cin >> temp;
				if(temp == 1) {
					cout << "请输入校园卡卡号：" << endl;
					string id;
					cin >> id;
					Campus_card *a = find_C(id, Campus_cards, Ccard_num);
					a->pay(money);
					cout << "已成功支付" << endl; 
				}
				else if(temp == 2) {
					cout << "请输入储蓄卡卡号：" << endl;
					string id;
					cin >> id;
					deposit_card *a = find_D(id, Deposit_cards, Dcard_num);
					a->pay(money);
					cout << "已成功支付" << endl;
				}
				else {
					cout << "请输入校园卡(已绑定)卡号：" << endl;
					string id;
					cin >> id;
					binding_card *a = find_B(id, Binding_cards, Bcard_num);
					a->pay(money);
					cout << "已成功支付" << endl;
				}
				break;
			}
			case 8:
			{
				cout << "请选择转入卡类型(1~2)：" << endl;
				cout << "1.校园卡" << endl;
				cout << "2.储蓄卡" << endl;
				cin >> temp;
				if(temp == 1) {
					cout << "请输入转入的校园卡卡号：" << endl;
					string id;
					cin >> id;
					Campus_card *a = find_C(id, Campus_cards, Ccard_num);
					cout << "请输入转出的储蓄卡卡号：" << endl;
					cin >> id;
					deposit_card *b = find_D(id, Deposit_cards, Dcard_num);
					cout << "请输入转账金额：" << endl;
					double money;
					cin >> money;
					a->transfer(money, *b);
					cout << "转账成功" << endl;
				}
				else if(temp == 2) {
					cout << "请输入转入的储蓄卡卡号：" << endl;
					string id;
					cin >> id;
					deposit_card *a = find_D(id, Deposit_cards, Dcard_num);
					cout << "请输入转出的储蓄卡卡号：" << endl;
					cin >> id;
					deposit_card *b = find_D(id, Deposit_cards, Dcard_num);
					cout << "请输入转账金额：" << endl;
					double money;
					cin >> money;
					a->transfer(money, *b);
					cout << "转账成功" << endl;
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
