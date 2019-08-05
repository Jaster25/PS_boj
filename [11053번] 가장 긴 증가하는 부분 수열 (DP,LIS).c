#include<stdio.h>


/*
//O(n * n) �ð����⵵ Ǯ��

int d[1001];
int seq[1001];

int main() {
	
	//max=0 ���� �ʱ�ȭ�� ��� 1 1 �Է½� 0 ��� 
	int max=1;
	int n;
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; ++i) {
		scanf("%d", &seq[i]);
	}
	
	//���� ���� 
	d[1] = 1;
	
	for(int i=2 ; i<=n ; ++i) {
		
		d[i] = 1;
		for(int j=1 ; j<=i ; ++j) {
			if(seq[i] > seq[j] && d[i] <= d[j]) {
				d[i] = d[j] + 1;
			}
		}
		
		if(d[i] > max) max = d[i];
	}
	
	printf("%d", max);
}
*/

int d[1001];
int seq[1001];

//O(N * logN) �ð����⵵ Ǯ�� 
int main() {
	
	int d_size = 0;
	int n;
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; ++i) {
		scanf("%d", &seq[i]);
	}
	
	//�ʱ� ���� 
	d[1] = seq[1];
	d_size++;
	
	for(int i=2 ; i<=n ; ++i) {
		
		if(d[d_size] < seq[i]) d[++d_size] = seq[i];
		
		else {
			for(int j=d_size ; j>=1 ; --j) {
				if(seq[i] < d[j] && seq[i] > d[j-1]) d[j] = seq[i];
			}
		}
	}
	
	printf("%d", d_size);
}
