#ifndef _H_studentSystem_H
#define _H_studentSystem_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define subjectNumber 5
#define gaoshu 0
#define yingyu 1
#define chengshe 2
#define daolun 3
#define xiandai 4

//�����ṹ��student 
typedef struct student {
    char studentID[9];//ѧ��ѧ�ų��� 
    char studentName[20];//�������� 
    char studentClass[10];
    float subjects[subjectNumber];//ѧ����ѧϰ��Ŀ 
    float total;//��¼ѧ�����ܷ� 
    int rank;
}student;

int openFile(student stu[]);
void inputFile(student stu[]);
void menu_select(void);//���ܲ˵�ѡ�� 
void append_(student stu[]);//����ѧ����Ϣ 
void delete_(student stu[]);//ɾ��ѧ����Ϣ 
void change_(student stu[]);//�޸�ѧ����Ϣ 
void queryStudent(student stu[]);//��ѯѧ����Ϣ 
void queryGrade(student stu[]);//��ѯ�ɼ� 
void delete_ByStudentName(student stu[]);//����ѧ������ɾ�� 
void delete_ByStudentID(student stu[]);//����ѧ��ѧ��ɾ�� 
int find_ByName(student stu[]);//������������ 
int find_ByID(student stu[]);//����ѧ�Ų��� 
void sort_(student stu[]);//��ѧ���ܷ�����,���������ı��� 
float average(student stu[]);//��ɼ���ƽ��ֵ 

#endif
