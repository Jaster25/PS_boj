#include<stdio.h>
#define MAX 1001
typedef enum{false, true} bool;
typedef struct {
	int y,x;
} Point;

int tomato[MAX][MAX];
int visitedDay[MAX][MAX];

//M�� x��ǥ N�� y��ǥ 
int M,N;

Point queue[MAX * MAX];
int front;
int rear;

bool isEmpty() {
	return (front == rear);
}

void enqueue(int Y, int X) {
	
	Point temp = {Y, X};
	queue[++rear] = temp;
}

Point dequeue() {
	
	return queue[++front];
}

bool bfs() {
	
	while( !isEmpty() ) {
		
		Point now = dequeue();
		int nowX = now.x;
		int nowY = now.y;
		
		int vectX[4] = {0,0,-1,1};
		int vectY[4] = {-1,1,0,0};
		
		for(int i=0 ; i<4 ; ++i) {
			int nextX = nowX + vectX[i];
			int nextY = nowY + vectY[i];
			
			//���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����.
			if(nextX >= 1 && nextX <= M && nextY >= 1 && nextY <=N) {
				if(tomato[nextY][nextX] == 0 && visitedDay[nextY][nextX] == 0) {
					enqueue(nextY, nextX);
					tomato[nextY][nextX] = 1;
					visitedDay[nextY][nextX] = visitedDay[nowY][nowX] + 1;
				}
			}
		}
	}
}

int main() {
	
	scanf("%d%d", &M, &N);
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			scanf("%d", &tomato[i][j]);
			visitedDay[i][j] = 0;
		}
	}
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			if(tomato[i][j] == 1) {
				enqueue(i,j);
				visitedDay[i][j] = 1;
			}
		}
	}
	
	bfs();
	
	//�ּ� ��¥ ã�� + ���� ��Ȳ Ȯ�� 
	int day = 0;
	int check = 1;
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ;++j) {
			
			if(day < visitedDay[i][j]) day = visitedDay[i][j];
			
			if(tomato[i][j] == 0) {
				printf("-1");
				return 0;	
			}
		}
	}
	
	//ó�� ���� �丶���� ���¸� 1�� �����ؼ� �ٽ� �������
	if(day == 1) printf("0");
	else printf("%d", day - 1);
}
