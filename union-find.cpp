#include <stdio.h>

//������ ã��
// = ���μ� ����(Disjoint-Set) �˰��� 

//�θ� ��带 ã�� �Լ�  
int getParent(int parent[], int x){
	if(parent[x] == x) return x; //�ش� ��尡 �θ� ����ΰ� 
	return parent[x] = getParent(parent, parent[x]); //�θ� ����� ���� ã�������� ����(��� �ѹ��̸� ��) 
}

//�� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b){ //�θ� ��带 �ϳ��� ����! 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a<b){
		parent[b] = a;
	}else{
		parent[a] = b;
	}
}

//���� �θ� ���� ������� Ȯ�� 
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
	
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent,1,5));
	unionParent(parent,2,9);
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent,1,5));
	
	return 0;
}
 
