#include "studentSystem.h"
int studentNumber = 0;
student stu[10000];
extern int openFile(student stu[]) {
	FILE *fp1, *fp2;
 	if((fp1 = fopen("studentNumber.txt", "r"))== NULL) {
        printf("��ȡ�Ѽ�¼ѧ������ʧ�ܣ�\n");
        return -1;
    }
    fscanf(fp1, "%d", &studentNumber);
    fclose(fp1);
    if ((fp2 = fopen("studentMessage.txt", "r")) == NULL) {
        printf("�����Ѽ�¼ѧ����Ϣʧ�ܣ�\n");
        return -1;
    } 
    int i = 0, j;
    if (studentNumber == 0) {
        printf("��ǰ��¼��ѧ����Ϊ 0.\n");
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
//���ܲ˵�ѡ�񣬰�0-6���в��� 
extern void menu_select() {
	printf("\t\t   ��������������������\n");
	printf("\t\t   �� 1.���ѧ����Ϣ ��\n");
	printf("\t\t   �� 2.ɾ��ѧ����Ϣ ��\n");
	printf("\t\t   �� 3.�޸�ѧ����Ϣ ��\n");
	printf("\t\t   �� 4.��ѯѧ����Ϣ ��\n");
	printf("\t\t   �� 5.��ѯ�ɼ�     ��\n");
	printf("\t\t   �� 6.��ѯƽ����   ��\n");
	printf("\t\t   �� 0.�˳�����     ��\n");
	printf("\t\t   ��������������������\n");
	printf("\n\n������������(0-6)ִ��:");
}
//����ѧ����Ϣ 
extern void append_(student stu[]) {
	int i, j, lenth;
	int temp = 1;
	int addNumber;
	char add_number[5];
	float sum;
	printf("������Ҫ��ӵ�ѧ������"); 
	scanf("%d", &addNumber);
	for(i = 0; i < addNumber; i++) {
		char ID[20];
		sum = 0.0;
		temp = 1;
		printf("�������%dλѧ����ѧ�ţ�", i + 1);
		scanf("%s", ID);
		for(j = 0; j < studentNumber; j++) {
			if(strcmp(ID, stu[j].studentID) == 0) {//�ж�ѧ��ѧ���Ƿ���ͬ������ͬ���ʾ��¼���ѧ������Ϣ 
				temp = 0;
				printf("��ѧ����¼����Ϣ�������޸ģ��뷵�ز˵���ѡ��\n");
				break;
			}
		}
		if(temp) {//��ѧ����û¼����Ϣ 
			strcpy(stu[studentNumber + i].studentID, ID);//����ѧ�������ѧ�� 
			printf("\n");
			printf("�������%dλѧ����������", i + 1);
			scanf("%s", stu[studentNumber + i].studentName);
			printf("\n");
			printf("�������%dλѧ���İ༶��", i + 1);
			scanf("%s", stu[studentNumber + i].studentClass);
			printf("\n");
			printf("�������%dλѧ���ĸ����ɼ���", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[gaoshu]);
			sum = sum + stu[studentNumber + i].subjects[gaoshu];
			printf("\n");
			printf("�������%dλѧ����Ӣ��ɼ���", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[yingyu]);
			sum = sum + stu[studentNumber + i].subjects[yingyu];
			printf("\n");
			printf("�������%dλѧ���ĳ�����Ƴɼ���", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[chengshe]);
			sum = sum + stu[studentNumber + i].subjects[chengshe];
			printf("\n");
			printf("�������%dλѧ����������̵��۳ɼ���", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[daolun]);
			sum = sum + stu[studentNumber + i].subjects[daolun];
			printf("\n");
			printf("�������%dλѧ�������Դ����ɼ���", i + 1);
			scanf("%f", &stu[studentNumber + i].subjects[xiandai]);
			sum = sum + stu[studentNumber + i].subjects[xiandai];
			printf("\n");
			stu[studentNumber + i].total = sum; 
		}
	}
	if(temp) {//��ʾ�û�ѧ����Ϣ¼����� 
		studentNumber = studentNumber + addNumber;
		sort_(stu);
		inputFile(stu);
		printf("����ѧ����Ϣ¼����ϣ�\n");
	}
	printf("�밴��������ز˵���\n");
	getchar();
}
//ɾ��ѧ����Ϣ 
extern void delete_(student stu[]) {
	int i, j, option;
	int deleteNumber;
	char delete_number[5];
	printf("������Ҫɾ����ѧ����Ŀ��");
	scanf("%d", &deleteNumber);
	for(i = 0; i < deleteNumber; i++) {
		printf("ɾ����%dλѧ����Ϣ\n", i + 1);
		printf("����ѡ��1.��ѧ�Ų��� 2.����������\n");
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
	printf("ɾ���ɹ����밴��������ز˵���\n");
	getchar();
	sort_(stu);
	inputFile(stu);//��ӵ��ı��� 
}
//����ѧ��ѧ��ɾ�� 
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
//����ѧ������ɾ�� 
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
//����ѧ�Ų���
extern int find_ByID(student stu[]) {
	char tempID[9];
	int i;
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", tempID);
	for(i = 0; i < studentNumber; i++) {
		if(strcmp(tempID, stu[i].studentID) == 0) {
			return i;
		}
	}
	printf("\n�Ҳ�����ѧ������ȷ�������Ƿ�����\n");
	getchar();
	return -1;
}
//������������ 
extern int find_ByName(student stu[]) {
	char tempName[20];
	int i;
	printf("������ѧ��������");
	scanf("%s", tempName);
	for(i = 0; i < studentNumber; i++) {
		if(strcmp(tempName, stu[i].studentName) == 0) {
			return i;
		}
	}
	printf("\n�Ҳ�����ѧ������ȷ�������Ƿ�����\n");
	getchar();
	return -1;
}
//�޸�ѧ����Ϣ
extern void change_(student stu[]) {
	int i, j, temp;
	int pos = -1;
	int option, option1;
	char tempID[20];
	printf("������Ҫ�޸ĵ�ѧ����ѧ�Ż�������\n");
	printf("����ѡ��1.��ѧ��ѧ�Ų�ѯ 2.��ѧ��������ѯ\n");
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
		printf("^ 1.�޸�ѧ��	    2.�޸�����	   ^");
		printf("^ 3.�޸İ༶		4.�޸ĸ����ɼ� ^");
		printf("^ 5.�޸�Ӣ��ɼ�	6.�޸ĳ���ɼ� ^");
		printf("^ 7.�޸ĵ��۳ɼ�	8.�޸��ߴ��ɼ� ^");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("������������������(1~8)ִ��:");
		scanf("%d", &option1);
		switch(option1) {
			case 1:
				printf("�������µ�ѧ�ţ�");
				scanf("%s", tempID);
				temp = 1;
				for(i = 0; i < studentNumber; i++) {
					if(strcmp(tempID, stu[i].studentID) == 0) {
						temp = 0;
						printf("��ѧ���Ѵ��ڣ�\n");
						break;
					}
				}
				if(temp) {
					strcpy(stu[pos].studentID, tempID);
					printf("\n");
					printf("�޸ĳɹ����밴��������ز˵���\n");
				}
				getchar();
				break;
			case 2:
				printf("�������µ�������");
				scanf("%s", stu[pos].studentName);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
			case 3:
				printf("�������µİ༶��");
				scanf("%s", stu[pos].studentClass);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
			case 4:
				printf("�������µĸ����ɼ���");
				stu[pos].total = stu[pos].total + stu[pos].subjects[gaoshu];
				scanf("%f", &stu[pos].subjects[gaoshu]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[gaoshu];
				sort_(stu);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
			case 5:
				printf("�������µ�Ӣ��ɼ���");
				stu[pos].total = stu[pos].total + stu[pos].subjects[yingyu];
				scanf("%f", &stu[pos].subjects[yingyu]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[yingyu];
				sort_(stu);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
			case 6:
				printf("�������µĳ���ɼ���");
				stu[pos].total = stu[pos].total + stu[pos].subjects[chengshe];
				scanf("%f", &stu[pos].subjects[chengshe]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[chengshe];
				sort_(stu);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
			case 7:
				printf("�������µĵ��۳ɼ���");
				stu[pos].total = stu[pos].total + stu[pos].subjects[daolun];
				scanf("%f", &stu[pos].subjects[daolun]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[daolun];
				sort_(stu);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
			case 8:
				printf("�������µ��ߴ��ɼ���");
				stu[pos].total = stu[pos].total + stu[pos].subjects[xiandai];
				scanf("%f", &stu[pos].subjects[xiandai]);
				stu[pos].total = stu[pos].total + stu[pos].subjects[xiandai];
				sort_(stu);
				printf("\n");
				printf("�޸ĳɹ����밴��������ز˵���\n");
				getchar();
				break;
		}
		inputFile(stu);
	}
}
//��ѧ���ܷ�����
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
//��ѯѧ����Ϣ 
extern void queryStudent(student stu[]) {
	int i, option;
	int pos = -1;
	printf("����ѡ��1.��ѧ��ѧ�Ų�ѯ 2.��ѧ��������ѯ");
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
		printf("ѧ��	����	�༶	����	Ӣ��	����	����	�ߴ�");
		printf("%s	%s	%s	%f	%f	%f	%f	%f	%f	%f	%d\n", stu[pos].studentID, stu[pos].studentName, stu[pos].studentClass, stu[pos].subjects[gaoshu], stu[pos].subjects[yingyu], stu[pos].subjects[chengshe], stu[pos].subjects[daolun], stu[pos].subjects[xiandai], stu[pos].total, stu[pos].rank);
		printf("��ѯ�ɹ����밴��������ز˵���\n");
		getchar();
	}
}
//��ѯѧ���ɼ�
extern void queryGrade(student stu[]) {
	int i;
	float range_from, range_to;
	printf("�������ѯ�ַܷ�Χ���½磺");
	scanf("%f", &range_from);
	printf("\n");
	printf("�������ѯ�ַܷ�Χ���Ͻ磺");
	scanf("%f", &range_to);
	printf("\n");
	if(range_from <= range_to) {
		printf("ѧ��	����	�༶	����	Ӣ��	����	����	�ߴ�\n");
		for(i = studentNumber - 1; i >= 0; i--) {
			if(stu[i].total <= range_to && stu[i].total >= range_from) {
				printf("%s	%s	%s	%f	%f	%f	%f	%f	%f	%f	%d\n", stu[i].studentID, stu[i].studentName, stu[i].studentClass, stu[i].subjects[gaoshu], stu[i].subjects[yingyu], stu[i].subjects[chengshe], stu[i].subjects[daolun], stu[i].subjects[xiandai], stu[i].total, stu[i].rank);
			}
		}
		printf("��ѯ�ɹ����밴��������ز˵���\n");
		getchar();
	}
	else {
		printf("�����ķ�Χ���Ϸ���\n");
		getchar();
	}
}
//��ɼ���ƽ��ֵ
extern float average(student stu[]) {
    float average, sum = 0;
    int i;
    for (i = 0; i < studentNumber; i++) {
        sum = sum + stu[i].total;
    }
    average = sum / studentNumber;
	return average;
}
