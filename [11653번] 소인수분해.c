#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	
	int i=2;
	while(N > 1) {

		//�� ���� Ǯ�� 
		if(N % i ==0) {
			printf("%d\n", i);
			N /= i;	
		}
		else i++;

//		for(int i=2 ; i<=N ; ++i) {
//			if(N % i == 0) {
//				printf("%d\n", i);
//				N /= i;
//				break;
//			}
//		}
	} 
}

