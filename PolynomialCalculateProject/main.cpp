#include "polynomial.cpp"
int main() {
	Polynomial a;//���������Ա�������Ա���� 
	bool isQuit = false;//ѭ���˳������������˳�������ϵͳ 
	int count = 0;
	int selection;//�����û��Ĳ���ѡ�� 
	while(!isQuit) {
		selection = a.menu();
	    a.select(selection, count, isQuit);
	}
	return 0;
}
