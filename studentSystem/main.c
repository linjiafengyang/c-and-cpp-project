#include "studentSystem.c"

int main() {
	printf("\n\t\t �q= = = = = = �� �� ��= = = = = =�r\n");
	printf("\t\t|	��ӭʹ��ѧ����Ϣ����ϵͳ    |\n");
	printf("\t\t�t = = = = = = �� �� ��= = = = = = �s\n");
	printf("�밴����������������.\n");
	getchar();
	system("cls");	
	while(1) {
		menu_select();
		int option; 
		scanf("%d", &option);//����˵��ı��0-6������ϵͳ���� 
		if(option == 0) {
        	break;
		}
        switch(option) {
        case 1 : 
                openFile(stu);
                append_(stu);
                break;
        case 2 :
                openFile(stu);
                delete_(stu);
                break;       

        case 3 : 
                openFile(stu);
                change_(stu);
                break;
        case 4 :
                openFile(stu);
                queryStudent(stu);
                break;
        case 5 : 
                openFile(stu);
                queryGrade(stu);
                break;
        case 6 : 
                openFile(stu);
                printf("��ѧ����ƽ����Ϊ��%.2f.\n",average(stu));
    			getch();
                break;
		case 0:
				break;
		}
	}
}

