#include<stdio.h>
#include<string.h>

//�Է��� ���� 10000000���� �Ϲ����� Ǯ�̷δ� �޸� �ʰ� �߻��� 
//������ 10000���Ͽ��� ���ĸ��� ī�����ϴ� Ǯ�� 

int ar[10001] = {0,};

int main() {
	
	int N;
	scanf("%d", &N);
	
	int num;
	for(int i=0 ; i<N ; ++i) {
		scanf("%d", &num);
		ar[num]++;
	}
	
	for(int i=1 ; i<=10000 ; ++i) {
		while(ar[i] >= 1) {
			printf("%d\n", i);
			ar[i]--;
		}
	}
}
