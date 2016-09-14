#include "snake.h"

int main() {
	int headx, heady;	// ��ͷ������
	memset(gameMap, FillingMap , sizeof(gameMap));  // ��ʼ����ͼȫ��Ϊ'.'
	system("cls");
	printf("��Ϸ˵����A/a����D/d���ң�S/s���£�W/w����\n");
	printf(" - - - - - - - -");
	printf("\n[���س�����ʼ��Ϸ]\n");
	printf(" - - - - - - - -\n");
	getchar();//����س�����ʼ��Ϸ���� 
	srand(time(NULL));   	//�������
	headx = rand() % Width;// ���������ͷ
	heady = rand() % Length;
	gameMap[headx][heady] = SNAKE_HEAD;
	She[0].x = headx;
	She[0].y = heady;
	She[0].now = -1;
	put_money();		// �������Ǯ $ 
	Huitu();			// ���Ƶ�ͼ
	getch();   			// �ȶ���һ������,ʹ�߿�ʼ���÷�����
	output();  			// ȡ�����������Ŀ��Ʒ���,���жϷ���
	Refurbish();		// ˢ����ʾ��ͼ 
	return 0;
}
// �������Ǯ $
void put_money(void) {
	int foodx, foody;	// Ǯ$������
	while(1) {
		foodx = rand() % Width;		//��������ͷ�����������ͬ 
		foody = rand() % Length;
		if(gameMap[foodx][foody] == '.') { // Ǯ $ ���ܳ���������ռ�е�λ��,ֻ�ܳ�����'.'�У������ɹ�����Ǯ$��������ѭ�� 
			gameMap[foodx][foody] = SNAKE_FOOD;
			break;
		}
	}
}
// ���Ƶ�ͼ
void Huitu(void) {
	printf("������%d\n", fenshu);
	int i, j;
	for(i = 0; i < Width; i++) {
  		for(j = 0; j < Length; j++) {
  			printf("%c", gameMap[i][j]);
		}	
  		printf("\n");
 	}
}
// ȡ�����������Ŀ��Ʒ���,���жϷ���
void output(void) {
	char response;
	if(kbhit() != 0) { 	// kbhitʹ�����Զ���ԭ�з����н�����鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
    	response = getch(); 	// �������ӿ���̨��ȡ�������浽key��
		switch(response) {
			//��������
			case 'A':
			case 'a':
				She[0].now = 0;
        		break;
            //��������
            case 'D':
            case 'd':
				She[0].now = 1;
          		break;
            //��������
			case 'W':
			case 'w':
				She[0].now = 2;
        		break;
            //��������
			case 'S':
			case 's':
				She[0].now = 3;
        		break;
        	default:
        		break;
  		}
 	}
}
// ˢ����ʾ��ͼ
void Refurbish(void) { 
	int x, y;
	while(1) {
  		Sleep(500); 	// �ӳٰ���(1000Ϊ1s),��ÿ����ˢ��һ�ε�ͼ 
		output();   	// ���жϰ������ƶ� 
		x = She[0].x; 	// ��¼��ǰ��ͷ��λ��
		y = She[0].y;
		snakeMove(x, y);// �ж��ߵ��ƶ������������ߵ��ƶ�������Ϸ������������
		gameover();
		system("cls");	// ����������ʾˢ�º�ĵ�ͼ 
		printf("\n\n\n\n");
		Huitu();
	}
}
// �ߵ��ƶ�
void snakeMove(int x, int y) {  	
	int i;
    int t = length;		// ���浱ǰ�ߵĳ���
	gameMap[x][y] = '.';
	She[0].x = She[0].x + Posx[She[0].now];
	She[0].y = She[0].y + Posy[She[0].now];
	// �����ͷ�Ƿ���磬���ж��Ƿ񳬹�Width��Length
	if(She[0].x < 0 || She[0].x >= Width  || She[0].y < 0 || She[0].y >= Length) { 
		over = 1;
	}
	//����ͷ�ĵ�ǰλ���ж���ͷ�ƶ����λ�����
	if(gameMap[She[0].x][She[0].y] == '.') { 		//��Ϊ'.'������ͷ�ɵ����λ��
		gameMap[She[0].x][She[0].y] = 'H';
	}
	else if(gameMap[She[0].x][She[0].y] == '$') { 	//��ΪǮ $
			gameMap[She[0].x][She[0].y] = 'H';		//��ͷ�Ե�Ǯ $����Ǯ��λ�û�����ͷ
			She[length].x = x;   			//�����ӵ�����Ϊԭ��ͷ��λ��
			She[length].y = y;
			She[length].now = She[0].now;
			gameMap[She[length].x][She[length].y] = 'X';	//��ԭ��ͷ��λ�ü������λ�û���'X'
			length++;
			fenshu++;
			put_money();  					//Ǯ $ ������Ҫ����׬Ǯ $ 
		}
	else { 
		over = 1;
	}
	//���������ߵ�λ��
	if(length == t) { 		// ��ʾ��δ�Ե�ʳ������ƶ�
    	for(i = 1; i < length; i++) { 		// ����β��λ����ǰ�ƶ�
			if(i == 1) {  					// ��β��λ������Ϊ'.'�����ƶ�
				gameMap[She[i].x][She[i].y] = '.';
			}
			if(i == length - 1) { 			// ��ͷ���ڵ�λ��Ϊִ��checkBorder()���λ��
				She[i].x = x;
				She[i].y = y;
				She[i].now = She[0].now;
			}
			else {		// ���������ߵ�ǰһ�������λ��
				She[i].x = She[i+1].x;
				She[i].y = She[i+1].y;
				She[i].now = She[i+1].now;
			}
			gameMap[She[i].x][She[i].y] = 'X';// �ƶ���Ҫ��Ϊ����'X'
		}
	}
}
//�ж���Ϸ������� 
void gameover(void) {
	char response;
	if(over) { 		// �ԳԻ���ǽ����Ϸ����
		printf("�����ˣ���Ϸ����\n");
		printf("�����Ϸ�÷��ǣ�%d", fenshu);
		printf("\n���Ƿ�Ҫ������Ϸ����Y/y����: ");
		fenshu = 0;	//�����ݻ�ԭ 
		length = 1;	//�����ݻ�ԭ 
		over = 0;	//�����ݻ�ԭ 
		She[0].now = 0;
		response = getchar();
		if(response == 'Y' || response == 'y') {
			system("cls");//���������main�������¼�����Ϸ 
			main();
		}
	}
}
