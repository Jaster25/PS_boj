#include<stdio.h>
#define MAX 1000001

//�������׳׽��� ���� (�Ҽ� �Ǻ���)
//N�� �Ҽ��̱� ���� �ʿ� ��� ������ N�� N�� �����ٺ���
//ũ�� ���� � �Ҽ��ε� �������� �ʴ´�. 

int prime[MAX];

int main() {
	
	for(int i=2 ; i<MAX ; ++i) prime[i] = 1;
	for(int i=2 ; i*i < MAX ; ++i) {
		for(int j=2 ; prime[i] && i*j < MAX ; ++j) {
			prime[i * j] = 0;
		}
	}
	
	int N;
	scanf("%d", &N);
	while(N != 0) {
		
		for(int i=2 ; i <= N/2 ; ++i) {
			
			if(prime[i] == 1 && prime[N-i] == 1) {
				printf("%d = %d + %d\n", N, i, N-i);
				break;
			}
		}
				
		scanf("%d", &N);
	}
}
