#include<stdio.h>
#define MIN(a,b) (a<b ? a : b)
#include<math.h>

//j�� �ִ� �������� Ǯ�� Ʋ���� ex 12�� ���
//���� �ݺ������� ������ ���尪�� �־� n*n�� �ȳ����µ�
 
int dp[1000001] = {0,};

int main() {

	int N;
	scanf("%d", &N);

	dp[1] = 1;
	
	for(int i=1 ; i<=N ; ++i) {
		
		dp[i] = i;
		for(int j=1 ; j<=(int)sqrt(i) ; ++j) {
			dp[i] = MIN(dp[i], dp[i-j*j] + 1);
		}
	}
		
	printf("%d", dp[N]);
} 
