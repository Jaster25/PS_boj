#include<stdio.h>
#include<math.h>

int A, B;
int m;
int a[26];

void toB(int num) {
	if(num == 0) {
		return;
	}
	
	toB(num / B);
	printf("%d ", num % B);
}

int main() {
	
	scanf("%d%d", &A, &B);
	scanf("%d", &m);
	
	for(int i=1 ; i<=m ; ++i) {
		scanf("%d", &a[i]);
	}
	
	//A������ 10�������� 
	int sum = 0;
	int count = 0;
	for(int i=m ; i>=1 ; --i) {
		sum += a[i] * pow(A, count++);
	}
	
	//10������ B��������
	toB(sum);
}
