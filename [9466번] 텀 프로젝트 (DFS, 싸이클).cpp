#include<iostream>
#include<string.h>
#define MAX 100001
using namespace std;

int N, count;
int student[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int a) {
	
	visited[a] = true;
	int next = student[a];
	
	if(!visited[next])
		dfs(next);

	//�̹� �湮������ �湮�� �������̶�� ����Ŭ�̶� �� 
	else if(!done[next]) {
		//���� �� 
		for(int i = next; i != a; i = student[i])
			count++;
		//�ڱ� �ڽ� 
		count++;
	}
	
	done[a] = true;
}

void reset() {
	count = 0;
	memset(visited, false, N+1);
	memset(done, false, N+1);
}

int main() {
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		reset();
		scanf("%d", &N);
		
		for(int i=1 ; i<=N ; ++i)
			scanf("%d", &student[i]);
		
		for(int i=1 ; i<=N ; ++i)
			if(!visited[i]) dfs(i);
		
		printf("%d\n", N - count);
	}
}
