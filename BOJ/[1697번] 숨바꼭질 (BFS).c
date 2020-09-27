#include<stdio.h>
#define MAX 100001

int N, K;

int visitedTime[MAX];
int queue[MAX];
int front;
int rear;

void enqueue(int a) {
	queue[++rear] = a;
}

int dequeue() {
	return queue[++front];
}

int bfs() {
	
	//�ʱⰪ�� 1�� ����
	enqueue(N);
	visitedTime[N] = 1;
	
	while(front != rear) {
		
		int now = dequeue();
		if(now == K) return visitedTime[now];
		
		
		//���� ���� 
		if(now + 1 <= MAX && visitedTime[now + 1] == 0) {
			enqueue(now + 1);
			visitedTime[now + 1] = visitedTime[now] + 1;
		}
		
		if(now - 1 >= 0 && visitedTime[now - 1] == 0) {
			enqueue(now - 1);
			visitedTime[now - 1] = visitedTime[now] + 1;
		}
	
		if(now * 2 <= MAX && visitedTime[now * 2] == 0) {
			enqueue(now * 2);
			visitedTime[now * 2] = visitedTime[now] + 1;
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &K);
	
	//�ʱⰪ�� 0�� �ƴ� 1�� �Ͽ� �������� �ٽ� 1 ���ֱ� 
	printf("%d", bfs() - 1);
}
