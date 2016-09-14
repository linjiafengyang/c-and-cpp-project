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

//构建结构体student 
typedef struct student {
    char studentID[9];//学生学号长度 
    char studentName[20];//姓名长度 
    char studentClass[10];
    float subjects[subjectNumber];//学生的学习科目 
    float total;//记录学生的总分 
    int rank;
}student;

int openFile(student stu[]);
void inputFile(student stu[]);
void menu_select(void);//功能菜单选择 
void append_(student stu[]);//新增学生信息 
void delete_(student stu[]);//删除学生信息 
void change_(student stu[]);//修改学生信息 
void queryStudent(student stu[]);//查询学生信息 
void queryGrade(student stu[]);//查询成绩 
void delete_ByStudentName(student stu[]);//根据学生姓名删除 
void delete_ByStudentID(student stu[]);//根据学生学号删除 
int find_ByName(student stu[]);//根据姓名查找 
int find_ByID(student stu[]);//根据学号查找 
void sort_(student stu[]);//给学生总分排序,并保存在文本中 
float average(student stu[]);//求成绩的平均值 

#endif
