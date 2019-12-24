#include <iostream>

using namespace std;

//비선형, 순회, 트리 
//일직선상이 아닌 이진트리와 같은 것을 비선형 자료구조라고 부른다.
//데이터의 탐색 속도 증진을 위해 사용하는 구조이다. 
//한번 내려갈 때 마다 탐색할 개수가 1/2씩 줄어듦 
//완전 이진 트리가 아닌 경우 배열로 표현하기 어려움 -> 포인터 사용 

//Preorder Traversal
//1. 자기 자신 처리
//2. 왼쪽 자식 처리
//3. 오른쪽 자식 처리
//Inorder Traversal
//1. 왼쪽 자식 처리
//2. 자기 자신 처리
//3. 오른쪽 자식 처리
//Postorder Traversal : 수식에 사용 
//1. 왼쪽 자식 처리
//2. 오른쪽 자식 처리
//3. 자기 자신 처리 

int number = 15;

//노드 정보 선언
//포인터 선언법 : int *pointer = &n;    *참조연산자 &주소연산자 
typedef struct node *treePointer; //node구조체를 포인터로 사용하겠다. 이름은 treePointer로 선언 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} nody; //nody라는 이름으로 사용 

//전위순회
void preorder(treePointer ptr){
	if(ptr){
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//중위순회
void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
		
	}
}

//후위순회
void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
} 

int main(void){
	//완전 이진트리 만들기 
	nody nodes[number+1]; //노드 담을 배열
	for(int i=1 ; i<=number ; i++){ //초기화 
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
	
	//순회 
	preorder(&nodes[1]);
	printf("\n");
	inorder(&nodes[1]);
	printf("\n");
	postorder(&nodes[1]); 
	
	return 0;
}




























