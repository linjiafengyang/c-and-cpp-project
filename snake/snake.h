#ifndef _H_snake_H
#define _H_snake_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define SNAKE_HEAD 'H'	// ��ͷ����ĸ H ��ʾ  
#define SNAKE_BOPosy 'X'// ��������ĸ X ��ʾ 
#define SNAKE_FOOD '$'  // ʳ������Ԫ $ ��ʾ 
#define FillingMap '.'	// ��ͼ�� '.'��ʾ 
#define Width 12		// ��ͼ�Ŀ�  
#define Length 24  		// ��ͼ�ĳ�

void Huitu(void);		// ���Ƶ�ͼ 
void Refurbish(void);   // ˢ����ʾ��ͼ
void put_money(void); 	// �ڵ�ͼ���������ʳ�� 
void output(void);  	// ȡ�����������Ŀ��Ʒ���asdw/ASDW��,���жϷ��� 
void snakeMove(int, int);// �ж��ߵ��ƶ������������ߵ��ƶ�������Ϸ������������ 
void gameover(void);// �ж���Ϸ�Ƿ����������Ϸ����������Ƿ������Ϸ 
int length = 1;			// ���ڴ����ߵĳ���
int over = 0; 		// �����ж���Ϸ�Ƿ����(��ײ���߳���)
int fenshu = 0;			// ������ҵĵ÷�
char gameMap[Width][Length];	// ������Ϸ��ͼ��С   
int  Posx[4] = {0, 0, -1, 1};  	// ���ҡ��ϡ��µķ���  
int  Posy[4] = {-1, 1, 0, 0};

// �ṹ�壬�ߵ�ÿ���ڵ���������� 
struct She {
	int x, y;  			// λ��
	int now;   			// ���浱ǰ�ڵ�ķ���, 0,1,2,3�ֱ�Ϊ��������  
} She[Width * Length];

#endif
