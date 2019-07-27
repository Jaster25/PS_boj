#include<stdio.h>
void quickSort(int *array, int start, int end);

int main() {
	
	int N;
	scanf("%d", &N);
	
	int rope[100000];
		
	int maxWeight = 0;	//���ø� �� �ִ� ��ü�� �ִ� �߷� 
	int weight = 0;	//������ ���ø� �� �ִ� ��ü�� �߷� 
	int k = N;	//����� ���� ����	
	
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &rope[i]);
	}
	
	//������������ �������ֱ� 
	quickSort(rope, 0, N-1);
	
	//�ڿ��� ���� �ϳ��� ���鼭 ���ϱ� 
	for(int i=N-1 ; i>=0 ; i--) {
		
		weight = (rope[i] * (i+1));
		
		if(weight > maxWeight) {
			maxWeight = weight;
		}	
	} 
		
	printf("%d", maxWeight);
}


void quickSort(int *array, int start, int end) {
	
	if(start >= end) return;
	
	int pivot = array[start];
	int toRight = start + 1;
	int toLeft = end;
	
	
	while(toRight <= toLeft) {		//������ ������ �ݺ� 
		
		while(array[toRight] >= pivot) {	//�ǹ����� ū ���� ã�Ƽ� 
			toRight++;
		}
		
		while(array[toLeft] <= pivot && toLeft>start) {	//�ǹ����� ���� ���� ã�Ƽ�
			toLeft--;
		}
		
		
		if(toRight > toLeft) {		//������ ���¸� �ǹ� ��ü
			int temp = array[start];	
			array[start] = array[toLeft];
			array[toLeft] = temp;
		}
		
		else {						//�ƴ� ��� �¿� ��ü 
			int temp = array[toLeft];	
			array[toLeft] = array[toRight];
			array[toRight] = temp;
		}
		
	}
	
	quickSort(array, start, toLeft-1);
	quickSort(array, toLeft+1, end);
}
