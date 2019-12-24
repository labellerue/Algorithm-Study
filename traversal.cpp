#include <iostream>

using namespace std;

//����, ��ȸ, Ʈ�� 
//���������� �ƴ� ����Ʈ���� ���� ���� ���� �ڷᱸ����� �θ���.
//�������� Ž�� �ӵ� ������ ���� ����ϴ� �����̴�. 
//�ѹ� ������ �� ���� Ž���� ������ 1/2�� �پ�� 
//���� ���� Ʈ���� �ƴ� ��� �迭�� ǥ���ϱ� ����� -> ������ ��� 

//Preorder Traversal
//1. �ڱ� �ڽ� ó��
//2. ���� �ڽ� ó��
//3. ������ �ڽ� ó��
//Inorder Traversal
//1. ���� �ڽ� ó��
//2. �ڱ� �ڽ� ó��
//3. ������ �ڽ� ó��
//Postorder Traversal : ���Ŀ� ��� 
//1. ���� �ڽ� ó��
//2. ������ �ڽ� ó��
//3. �ڱ� �ڽ� ó�� 

int number = 15;

//��� ���� ����
//������ ����� : int *pointer = &n;    *���������� &�ּҿ����� 
typedef struct node *treePointer; //node����ü�� �����ͷ� ����ϰڴ�. �̸��� treePointer�� ���� 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} nody; //nody��� �̸����� ��� 

//������ȸ
void preorder(treePointer ptr){
	if(ptr){
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//������ȸ
void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
		
	}
}

//������ȸ
void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
} 

int main(void){
	//���� ����Ʈ�� ����� 
	nody nodes[number+1]; //��� ���� �迭
	for(int i=1 ; i<=number ; i++){ //�ʱ�ȭ 
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	} 
	for(int i=2 ; i<=number ; i++){
		if(i%2 ==0){
			nodes[i/2].leftChild = &nodes[i];
		}else{
			nodes[i/2].rightChild = &nodes[i];
		}
	}
	
	//��ȸ 
	preorder(&nodes[1]);
	printf("\n");
	inorder(&nodes[1]);
	printf("\n");
	postorder(&nodes[1]); 
	
	return 0;
}




























