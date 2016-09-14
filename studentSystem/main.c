#include "studentSystem.c"

int main() {
	printf("\n\t\t ╭= = = = = = ■ □ ■= = = = = =╮\n");
	printf("\t\t|	欢迎使用学生信息管理系统    |\n");
	printf("\t\t╰ = = = = = = ■ □ ■= = = = = = ╯\n");
	printf("请按任意键进入操作界面.\n");
	getchar();
	system("cls");	
	while(1) {
		menu_select();
		int option; 
		scanf("%d", &option);//输入菜单的编号0-6，进行系统操作 
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
                printf("该学生的平均分为：%.2f.\n",average(stu));
    			getch();
                break;
		case 0:
				break;
		}
	}
}

