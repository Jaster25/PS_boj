#include<stdio.h>
#include<stdlib.h>
#define MAX 10001

typedef struct Node {
	struct Node *Left;
	struct Node *Right;
	int Key;
} Node; 

Node *createNode(int data) {
	Node *newNode = (Node*) malloc (sizeof(Node));
	newNode->Key = data;
	newNode->Left = NULL;
	newNode->Right = NULL;

	return newNode;
}

void postOrder(Node *R) {
	if(R == NULL) return;
	
	postOrder(R->Left);
	postOrder(R->Right);
	printf("%d\n", R->Key);
}

Node *node[MAX];
Node *root;

int main() {
	
	int data, index = 0;

	//Root ���� 
	scanf("%d", &data);
	root = node[++index] = createNode(data);
	
	while(scanf("%d", &data) != EOF) {

		node[++index] = createNode(data);
		
		Node *horse = root;
		while(1) {
			//�������� 
			if(horse->Key > data) {
				if(horse->Left == NULL) {
					horse->Left = node[index];
					break;
				}
				if(horse->Left != NULL) {
					horse = horse->Left;
				}
			}
		
			//���������� 
			else if(horse->Key < data) {
				if(horse->Right == NULL) {
					horse->Right = node[index];
					break;
				}
				if(horse->Right != NULL) {
					horse = horse->Right;
				}
			}	
		}
	}
	
	postOrder(root);
}
