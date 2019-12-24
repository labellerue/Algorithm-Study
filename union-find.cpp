#include <stdio.h>

//합집합 찾기
// = 서로소 집합(Disjoint-Set) 알고리즘 

//부모 노드를 찾는 함수  
int getParent(int parent[], int x){
	if(parent[x] == x) return x; //해당 노드가 부모 노드인가 
	return parent[x] = getParent(parent, parent[x]); //부모 노드의 값을 찾을때까지 돌자(재귀 한번이면 됨) 
}

//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b){ //부모 노드를 하나로 통일! 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a<b){
		parent[b] = a;
	}else{
		parent[a] = b;
	}
}

//같은 부모를 가진 노드인지 확인 
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a==b){
		return 1;
	}else{
		return 0;
	}
}

int main(void){
	
	int parent[11];
	for(int i=1 ; i<11 ; i++){
		parent[i] = i;
	}
	
	unionParent(parent, 1,2);
	unionParent(parent, 2,3);
	unionParent(parent, 3,4);
	
	unionParent(parent, 5,6);
	unionParent(parent, 6,7);
	unionParent(parent, 7,8);
	unionParent(parent, 8,9);
	
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent,1,5));
	unionParent(parent,2,9);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent,1,5));
	
	return 0;
}
 
