//���� ����� �ڿ������� + ����� d[]�� 2���� �迭ȭ 
//��ũ�� ���׿����� ��ȣ ����
//#define MAX(a,b) a > b ? a : b �̰� �ȵ� �������� �켱�������� 

#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

//[0]�� ������ 2ĭ �ö�� ���, [1]�� 1ĭ �ö�� ��� 
int d[301][2];
int score[301];

void dp(int i) {
	
	d[i][0] = MAX(d[i-2][0], d[i-2][1]) + score[i];
	d[i][1] = d[i-1][0] + score[i];	//���� ���� ������ ������ 2ĭ ������ ���� ������
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; i++) scanf("%d", &score[i]);
	d[1][0] = d[1][1] = score[1];

	for(int i=2 ; i<=n ; i++) dp(i);
	
	printf("%d", MAX(d[n][0], d[n][1]));
}
