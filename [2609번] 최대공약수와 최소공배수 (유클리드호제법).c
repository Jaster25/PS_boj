#include<stdio.h>

//��Ŭ���� ȣ����
//x�� y�� ����(�A) ������ ���� R�̶�� ���� ��,
//x�� y�� �ִ������� y�� r�� �ִ������� ���� 

int a,b;
int gcd, lcm;

int GCD(int x, int y) {
	if(y==0) return x;
	
	GCD(y, x % y);
}

int main() {
	
	scanf("%d%d", &a, &b);

	if(a>b) gcd = GCD(a,b);
	else gcd = GCD(b,a);
	
	lcm = a * b / gcd;
	
	printf("%d\n%d", gcd, lcm);
}
