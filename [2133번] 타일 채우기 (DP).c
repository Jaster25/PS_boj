#include<stdio.h>

int d[1000];


int main() {
	
	int N;
	scanf("%d", &N);
	
	//���� ����
	d[0] = 1;
	d[2] = 3;
	
	for(int i=4 ; i<=N ; i+=2) {
		
		//�Ϲ����� ��� 
		d[i] = d[i-2] * 3;
		
		//���� �Ǵ� �ǹ� �� ����  ���� Ÿ��
		for(int j=4 ; i-j>=0 ; j+=2) d[i] += d[i - j] * 2;
	}
	
	printf("%d", d[N]);
}
