#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

//���� ���¸� 3�ܰ�� ����� ǰ
//0��, 1�� ,2�� ���� ���� 

int amount[10001];
int d[10001][3];

int main() {

	int n;
	int max = 0;
	
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; ++i) {
		scanf("%d", &amount[i]);
	}
	
	//���� ����
	d[1][1] = d[1][2] = amount[1];
	 
	for(int i=2 ; i<=n ; ++i) {
		
		d[i][0] = MAX( MAX(d[i-1][0], d[i-1][1]), d[i-1][2] );
		d[i][1] = d[i-1][0] + amount[i];
		d[i][2] = d[i-1][1] + amount[i];
	}
	
	max = MAX( MAX(d[n][0], d[n][1]), d[n][2] );
	
	printf("%d", max);
}
