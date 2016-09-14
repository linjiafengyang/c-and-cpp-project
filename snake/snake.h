#ifndef _H_snake_H
#define _H_snake_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define SNAKE_HEAD 'H'	// 蛇头用字母 H 表示  
#define SNAKE_BOPosy 'X'// 蛇身用字母 X 表示 
#define SNAKE_FOOD '$'  // 食物用美元 $ 表示 
#define FillingMap '.'	// 地图用 '.'表示 
#define Width 12		// 地图的宽  
#define Length 24  		// 地图的长

void Huitu(void);		// 绘制地图 
void Refurbish(void);   // 刷新显示地图
void put_money(void); 	// 在地图上随机产生食物 
void output(void);  	// 取出玩家所输入的控制方向（asdw/ASDW）,并判断方向 
void snakeMove(int, int);// 判断蛇的移动（包括整条蛇的移动或者游戏结束的条件） 
void gameover(void);// 判断游戏是否结束，若游戏结束问玩家是否继续游戏 
int length = 1;			// 用于储存蛇的长度
int over = 0; 		// 用来判断游戏是否结束(自撞或者出界)
int fenshu = 0;			// 计算玩家的得分
char gameMap[Width][Length];	// 定义游戏地图大小   
int  Posx[4] = {0, 0, -1, 1};  	// 左、右、上、下的方向  
int  Posy[4] = {-1, 1, 0, 0};

// 结构体，蛇的每个节点的数据类型 
struct She {
	int x, y;  			// 位置
	int now;   			// 保存当前节点的方向, 0,1,2,3分别为左右上下  
} She[Width * Length];

#endif
