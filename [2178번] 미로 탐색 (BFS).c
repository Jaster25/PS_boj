#include<stdio.h>

typedef enum {false, true} bool;
typedef struct{
	int x;
	int y;
} position;

position queue[10001];
int front = 0;
int rear = 0;

int map[101][101] = {0, };
int visited[101][101] = {0, };
int N, M;

//���� ������ 
int vectX[4] = {0, 0, 1, -1};
int vectY[4] = {1, -1, 0, 0};

void enqueue(int x, int y) {
	
	position temp;
	temp.x = x;
	temp.y = y;
	
	queue[++rear] = temp;
}

position dequeue() {

	return queue[++front];
}

bool isEmpty() {
	if(front == rear) return true;	
	else return false;	
}

void bfs() {
	
	position now;
		
	while( !isEmpty() ) {
		
		now = dequeue();
		int nextX;
		int nextY;
		
		for(int i=0 ; i<4 ; i++) {
		
			nextX = now.x + vectX[i];
			nextY = now.y + vectY[i];
			
			//Ž�������� ������ Ȯ��
			//�ùٸ� �������� 
			if(nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= M) {
				//���� �´��� 
				if(map[nextX][nextY] == 1) {
					//�湮������ ������ 
					if(visited[nextX][nextY] == 0) {
						
						enqueue(nextX, nextY);
						visited[nextX][nextY] = visited[now.x][now.y] + 1;
					}
				}
			}
		}	
	} 
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=M ; j++)
			scanf("%1d", &map[i][j]);
	
	enqueue(1,1);
	visited[1][1] = 1;
	bfs();
	
	printf("%d", visited[N][M]);
}


/*
4 6
101111
101010
101011
111011


3 4
1111
1001
1101
*/
