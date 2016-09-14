#include "snake.h"

int main() {
	int headx, heady;	// 蛇头的坐标
	memset(gameMap, FillingMap , sizeof(gameMap));  // 初始化地图全部为'.'
	system("cls");
	printf("游戏说明：A/a向左，D/d向右，S/s向下，W/w向上\n");
	printf(" - - - - - - - -");
	printf("\n[按回车键开始游戏]\n");
	printf(" - - - - - - - -\n");
	getchar();//输入回车键开始游戏界面 
	srand(time(NULL));   	//随机种子
	headx = rand() % Width;// 随机产生蛇头
	heady = rand() % Length;
	gameMap[headx][heady] = SNAKE_HEAD;
	She[0].x = headx;
	She[0].y = heady;
	She[0].now = -1;
	put_money();		// 随机产生钱 $ 
	Huitu();			// 绘制地图
	getch();   			// 先读入一个按键,使蛇开始往该方向走
	output();  			// 取出玩家所输入的控制方向,并判断方向
	Refurbish();		// 刷新显示地图 
	return 0;
}
// 随机产生钱 $
void put_money(void) {
	int foodx, foody;	// 钱$的坐标
	while(1) {
		foodx = rand() % Width;		//和上面蛇头的随机产生相同 
		foody = rand() % Length;
		if(gameMap[foodx][foody] == '.') { // 钱 $ 不能出现在蛇所占有的位置,只能出现在'.'中，如若成功产生钱$，则跳出循环 
			gameMap[foodx][foody] = SNAKE_FOOD;
			break;
		}
	}
}
// 绘制地图
void Huitu(void) {
	printf("分数：%d\n", fenshu);
	int i, j;
	for(i = 0; i < Width; i++) {
  		for(j = 0; j < Length; j++) {
  			printf("%c", gameMap[i][j]);
		}	
  		printf("\n");
 	}
}
// 取出玩家所输入的控制方向,并判断方向
void output(void) {
	char response;
	if(kbhit() != 0) { 	// kbhit使蛇能自动按原有方向行进，检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
    	response = getch(); 	// 将按键从控制台中取出并保存到key中
		switch(response) {
			//方向向左
			case 'A':
			case 'a':
				She[0].now = 0;
        		break;
            //方向向右
            case 'D':
            case 'd':
				She[0].now = 1;
          		break;
            //方向向上
			case 'W':
			case 'w':
				She[0].now = 2;
        		break;
            //方向向下
			case 'S':
			case 's':
				She[0].now = 3;
        		break;
        	default:
        		break;
  		}
 	}
}
// 刷新显示地图
void Refurbish(void) { 
	int x, y;
	while(1) {
  		Sleep(500); 	// 延迟半秒(1000为1s),即每半秒刷新一次地图 
		output();   	// 先判断按键在移动 
		x = She[0].x; 	// 记录当前蛇头的位置
		y = She[0].y;
		snakeMove(x, y);// 判断蛇的移动（包括整条蛇的移动或者游戏结束的条件）
		gameover();
		system("cls");	// 清屏后再显示刷新后的地图 
		printf("\n\n\n\n");
		Huitu();
	}
}
// 蛇的移动
void snakeMove(int x, int y) {  	
	int i;
    int t = length;		// 保存当前蛇的长度
	gameMap[x][y] = '.';
	She[0].x = She[0].x + Posx[She[0].now];
	She[0].y = She[0].y + Posy[She[0].now];
	// 检测蛇头是否出界，即判断是否超过Width和Length
	if(She[0].x < 0 || She[0].x >= Width  || She[0].y < 0 || She[0].y >= Length) { 
		over = 1;
	}
	//以蛇头的当前位置判断蛇头移动后的位置情况
	if(gameMap[She[0].x][She[0].y] == '.') { 		//若为'.'，即蛇头可到这个位置
		gameMap[She[0].x][She[0].y] = 'H';
	}
	else if(gameMap[She[0].x][She[0].y] == '$') { 	//若为钱 $
			gameMap[She[0].x][She[0].y] = 'H';		//蛇头吃掉钱 $，即钱的位置换成蛇头
			She[length].x = x;   			//新增加的蛇身为原蛇头的位置
			She[length].y = y;
			She[length].now = She[0].now;
			gameMap[She[length].x][She[length].y] = 'X';	//将原蛇头的位置即蛇身的位置换成'X'
			length++;
			fenshu++;
			put_money();  					//钱 $ 吃完了要继续赚钱 $ 
		}
	else { 
		over = 1;
	}
	//更改整条蛇的位置
	if(length == t) { 		// 表示蛇未吃到食物，蛇身移动
    	for(i = 1; i < length; i++) { 		// 从蛇尾的位置向前移动
			if(i == 1) {  					// 蛇尾的位置设置为'.'后再移动
				gameMap[She[i].x][She[i].y] = '.';
			}
			if(i == length - 1) { 			// 蛇头现在的位置为执行checkBorder()后的位置
				She[i].x = x;
				She[i].y = y;
				She[i].now = She[0].now;
			}
			else {		// 其他蛇身都走到前一个蛇身的位置
				She[i].x = She[i+1].x;
				She[i].y = She[i+1].y;
				She[i].now = She[i+1].now;
			}
			gameMap[She[i].x][She[i].y] = 'X';// 移动后要改为蛇身'X'
		}
	}
}
//判断游戏结束与否 
void gameover(void) {
	char response;
	if(over) { 		// 自吃或碰墙即游戏结束
		printf("您输了，游戏结束\n");
		printf("你的游戏得分是：%d", fenshu);
		printf("\n您是否要继续游戏？按Y/y继续: ");
		fenshu = 0;	//把数据还原 
		length = 1;	//把数据还原 
		over = 0;	//把数据还原 
		She[0].now = 0;
		response = getchar();
		if(response == 'Y' || response == 'y') {
			system("cls");//清屏后调用main函数重新加载游戏 
			main();
		}
	}
}
