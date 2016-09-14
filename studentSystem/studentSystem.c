#include "studentSystem.h"
int studentNumber = 0;
student stu[10000];
extern int openFile(student stu[]) {
	FILE *fp1, *fp2;
 	if((fp1 = fopen("studentNumber.txt", "r"))== NULL) {
        printf("获取已记录学生数量失败！\n");
        return -1;
    }
    fscanf(fp1, "%d", &studentNumber);
    fclose(fp1);
    if ((fp2 = fopen("studentMessage.txt", "r")) == NULL) {
        printf("载入已记录学生信息失败！\n");
        return -1;
    } 
    int i = 0, j;
    if (studentNumber == 0) {
        printf("当前记录的学生数为 0.\n");
        return -1;
    }
    i = 0;
    while (i < studentNumber) {
        fscanf(fp2, "%s", &stu[i].studentID);
        fscanf(fp2, "%s", &stu[i].studentName);
        fscanf(fp2, "%s", &stu[i].studentClass);
        for (j = 0; j < subjectNumber; j++) {
            fscanf(fp2, "%f", &stu[i].subjects[j]);
        }
        fscanf(fp2, "%f", &stu[i].total);
        fscanf(fp2, "%d", &stu[i].rank);
        i++;
    }
    fclose(fp2);
    return 1;
}
extern void inputFile(student stu[]) {
    FILE * fp1, * fp2;
    int i;
    fp1 = fopen("studentMessage.txt", "w+");
    for (i = 0; i < studentNumber; i++) {
        fprintf(fp1, "%s\n", stu[i].studentID);
        fprintf(fp1, "%s\n", stu[i].studentName);
        fprintf(fp1, "%s\n", stu[i].studentClass);
        fprintf(fp1, "%f\n", stu[i].subjects[gaoshu]);
        fprintf(fp1, "%f\n", stu[i].subjects[yingyu]);
        fprintf(fp1, "%f\n", stu[i].subjects[chengshe]);
        fprintf(fp1, "%f\n", stu[i].subjects[daolun]);
        fprintf(fp1, "%f\n", stu[i].subjects[xiandai]);
        fprintf(fp1, "%f\n", stu[i].total);
        fprintf(fp1, "%d\n", stu[i].rank);
    }
    fclose(fp1);
    fp2 = fopen("studentNumber.txt", "w+");
    fprintf(fp2, "%d\n", studentNumber);
    fclose(fp2);
}
//功能菜单选择，按0-6进行操作 
extern void menu_select() {
	printf("\t\t   ┌────────┐\n");
	printf("\t\t   │ 1.添加学生信息 │\n");
	printf("\t\t   │ 2.删除学生信息 │\n");
	printf("\t\t   │ 3.修改学生信息 │\n");
	printf("\t\t   │ 4.查询学生信息 │\n");
	printf("\t\t   │ 5.查询成绩     │\n");
	printf("\t\t   │ 6.查询平均分   │\n");
	printf("\t\t   │ 0.退出程序     │\n");
	printf("\t\t   └────────┘\n");
	printf("\n\n请您输入数字(0-6)执行:");
}
//新增学生信息 
extern void append_(student stu[]) {
	int i, j, lenth;
	int temp = 1;
	int addNumber;
	char add_number[5];
	float sum;
	printf("请输入要添加的学生数："); 
	scanf("%d", &addNumber);
	for(i = 0; i < addNumber; i++) {
		char ID[20];
		sum = 0.0;
		temp = 1;
		printf("请输入第%d位学生的学号：", i + 1);
		scanf("%s", ID);
		for(j = 0; j < studentNumber; j++) {
			if(strcmp(ID, stu[j].studentID) == 0) {//判断学生学号是否相同，若相同则表示已录入该学生的信息 
				temp = 0;
				printf("该学生已录入信息，如需修改，请返回菜单重选。\n");
				break;
			}
		}
		if(temp) {//该学生还没录入信息 
			strcpy(stu[studentNumber + i].studentID, ID);//复制学生输入的学号 
			printf("\n");
			printf("请输入第%d位学生的姓名：", i + 1);
			scanf("%s", stu[studentNumber + i].studentName);
			printf("\n");
			printf("请输入第%d位学生的班级：", i + 1);
			scanf("%s", stu[studentNumber + i].studentClass);
			printf("\n");
			printf("请输入第%d位学生的高数成绩：", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[gaoshu]);
			sum = sum + stu[studentNumber + i].subjects[gaoshu];
			printf("\n");
			printf("请输入第%d位学生的英语成绩：", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[yingyu]);
			sum = sum + stu[studentNumber + i].subjects[yingyu];
			printf("\n");
			printf("请输入第%d位学生的程序设计成绩：", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[chengshe]);
			sum = sum + stu[studentNumber + i].subjects[chengshe];
			printf("\n");
			printf("请输入第%d位学生的软件工程导论成绩：", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[daolun]);
			sum = sum + stu[studentNumber + i].subjects[daolun];
			printf("\n");
			printf("请输入第%d位学生的线性代数成绩：", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[xiandai]);
			sum = sum + stu[studentNumber + i].subjects[xiandai];
			printf("\n");
			stu[studentNumber + i].total = sum; 
		}
	}
	if(temp) {//提示用户学生信息录入完毕 
		studentNumber = studentNumber + addNumber;
		sort_(stu);
		inputFile(stu);
		printf("新增学生信息录入完毕！\n");
	}
	printf("请按任意键返回菜单。\n");
	getchar();
}
//删除学生信息 
extern void delete_(student stu[]) {
	int i, j, option;
	int deleteNumber;
	char delete_number[5];
	printf("请输入要删除的学生数目：");
	scanf("%d", &deleteNumber);
	for(i = 0; i < deleteNumber; i++) {
		printf("删除第%d位学生信息\n", i + 1);
		printf("进行选择：1.按学号查找 2.按姓名查找\n");
		scanf("%d", &option);
		switch(option) {
			case 1:
				delete_ByStudentID(stu);
				break;
			case 2:
				delete_ByStudentName(stu);
				break;
		}
	}
	printf("删除成功！请按任意键返回菜单。\n");
	getchar();
	sort_(stu);
	inputFile(stu);//添加到文本里 
}
//根据学生学号删除 
extern void delete_ByStudentID(student stu[]) {
	int i, pos;
	pos = find_ByID(stu);
	for(i = pos; i < studentNumber && i != -1; i++) {
		stu[i] = stu[i + 1];
	}
	if(pos != -1) {
		studentNumber--;
		getchar();
	}
	printf("\n");
}
//根据学生姓名删除 
extern void delete_ByStudentName(student stu[]) {
	int i, pos;
	pos = find_ByName(stu);
	for(i = pos; i < studentNumber && i != -1; i++) {
		stu[i] = stu[i + 1];
	}
	if(pos != -1) {
		studentNumber--;
		getchar();
	}
	printf("\n");
}
//根据学号查找
extern int find_ByID(student stu[]) {
	char tempID[9];
	int i;
	printf("请输入学生学号：");
	scanf("%s", tempID);
	for(i = 0; i < studentNumber; i++) {
		if(strcmp(tempID, stu[i].studentID) == 0) {
			return i;
		}
	}
	printf("\n找不到该学生，请确认输入是否有误。\n");
	getchar();
	return -1;
}
//根据姓名查找 
extern int find_ByName(student stu[]) {
	char tempName[20];
	int i;
	printf("请输入学生姓名：");
	scanf("%s", tempName);
	for(i = 0; i < studentNumber; i++) {
		if(strcmp(tempName, stu[i].studentName) == 0) {
			return i;
		}
	}
	printf("\n找不到该学生，请确认输入是否有误。\n");
	getchar();
	return -1;
}
//修改学生信息
extern void change_(student stu[]) {
	int i, j, temp;
	int pos = -1;
	int option, option1;
	char tempID[20];
	printf("请输入要修改的学生的学号或姓名。\n");
	printf("进行选择：1.按学生学号查询 2.按学生姓名查询\n");
	scanf("%d", &option);
	switch(option) {
		case 1:
			pos = find_ByID(stu);
			break;
		case 2:
			pos = find_ByName(stu);
			break;
	}
	if(pos != -1) {
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("^ 1.修改学号	    2.修改姓名	   ^");
		printf("^ 3.修改班级		4.修改高数成绩 ^");
		printf("^ 5.修改英语成绩	6.修改程设成绩 ^");
		printf("^ 7.修改导论成绩	8.修改线代成绩 ^");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("请输入请您输入数字(1~8)执行:");
		scanf("%d", &option1);
		switch(option1) {
			case 1:
				printf("请输入新的学号：");
				scanf("%s", tempID);
				temp = 1;
				for(i = 0; i < studentNumber; i++) {
					if(strcmp(tempID, stu[i].studentID) == 0) {
						temp = 0;
						printf("该学号已存在！\n");
						break;
					}
				}
				if(temp) {
					strcpy(stu[pos].studentID, tempID);
					printf("\n");
					printf("修改成功！请按任意键返回菜单。\n");
				}
				getchar();
				break;
			case 2:
				printf("请输入新的姓名：");
				scanf("%s", stu[pos].studentName);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
			case 3:
				printf("请输入新的班级：");
				scanf("%s", stu[pos].studentClass);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
			case 4:
				printf("请输入新的高数成绩：");
				stu[pos].total = stu[pos].total + stu[pos].subjects[gaoshu];
				scanf("%f", &stu[pos].subjects[gaoshu]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[gaoshu];
				sort_(stu);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
			case 5:
				printf("请输入新的英语成绩：");
				stu[pos].total = stu[pos].total + stu[pos].subjects[yingyu];
				scanf("%f", &stu[pos].subjects[yingyu]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[yingyu];
				sort_(stu);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
			case 6:
				printf("请输入新的程设成绩：");
				stu[pos].total = stu[pos].total + stu[pos].subjects[chengshe];
				scanf("%f", &stu[pos].subjects[chengshe]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[chengshe];
				sort_(stu);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
			case 7:
				printf("请输入新的导论成绩：");
				stu[pos].total = stu[pos].total + stu[pos].subjects[daolun];
				scanf("%f", &stu[pos].subjects[daolun]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[daolun];
				sort_(stu);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
			case 8:
				printf("请输入新的线代成绩：");
				stu[pos].total = stu[pos].total + stu[pos].subjects[xiandai];
				scanf("%f", &stu[pos].subjects[xiandai]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[xiandai];
				sort_(stu);
				printf("\n");
				printf("修改成功！请按任意键返回菜单。\n");
				getchar();
				break;
		}
		inputFile(stu);
	}
}
//给学生总分排序
extern void sort_(student stu[]) {
	int i, j;
	student temp;
	for(i = 1; i < studentNumber; i++) {
		for(j = 0; j < studentNumber - i; j++) {
			if(stu[j].total > stu[j + 1].total) {
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	for(i = 0; i < studentNumber; i++) {
		stu[i].rank = studentNumber - i;
	}
}
//查询学生信息 
extern void queryStudent(student stu[]) {
	int i, option;
	int pos = -1;
	printf("进行选择：1.按学生学号查询 2.按学生姓名查询");
	printf("\n");
	scanf("%d", &option);
	switch(option) {
		case 1:
			pos = find_ByID(stu);
			break;
		case 2:
			pos = find_ByName(stu);
			break;
	}
	printf("\n\n");
	if((option == 1 || option == 2) && pos != -1) {
		printf("学号	姓名	班级	高数	英语	程设	导论	线代");
		printf("%s	%s	%s	%f	%f	%f	%f	%f	%f	%f	%d\n", stu[pos].studentID, stu[pos].studentName, stu[pos].studentClass, stu[pos].subjects[gaoshu], stu[pos].subjects[yingyu], stu[pos].subjects[chengshe], stu[pos].subjects[daolun], stu[pos].subjects[xiandai], stu[pos].total, stu[pos].rank);
		printf("查询成功！请按任意键返回菜单。\n");
		getchar();
	}
}
//查询学生成绩
extern void queryGrade(student stu[]) {
	int i;
	float range_from, range_to;
	printf("请输入查询总分范围的下界：");
	scanf("%f", &range_from);
	printf("\n");
	printf("请输入查询总分范围的上界：");
	scanf("%f", &range_to);
	printf("\n");
	if(range_from <= range_to) {
		printf("学号	姓名	班级	高数	英语	程设	导论	线代\n");
		for(i = studentNumber - 1; i >= 0; i--) {
			if(stu[i].total <= range_to && stu[i].total >= range_from) {
				printf("%s	%s	%s	%f	%f	%f	%f	%f	%f	%f	%d\n", stu[i].studentID, stu[i].studentName, stu[i].studentClass, stu[i].subjects[gaoshu], stu[i].subjects[yingyu], stu[i].subjects[chengshe], stu[i].subjects[daolun], stu[i].subjects[xiandai], stu[i].total, stu[i].rank);
			}
		}
		printf("查询成功！请按任意键返回菜单。\n");
		getchar();
	}
	else {
		printf("您给的范围不合法！\n");
		getchar();
	}
}
//求成绩的平均值
extern float average(student stu[]) {
    float average, sum = 0;
    int i;
    for (i = 0; i < studentNumber; i++) {
        sum = sum + stu[i].total;
    }
    average = sum / studentNumber;
	return average;
}
