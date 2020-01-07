#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

//�̺и�Ī Bipartite Matching
//��Ī ���α׷� : A������ B������ �����ϴ� ��� 
//ȿ������ ��Ģ => �ִ� ��Ī(Max Matching) 
//��Ʈ��ũ �÷ο�� ����
//DFS�� ���� ����ġ�� 1�� ����

//����
//1�� A,B,C�� ����
//2�� A�� ����
//3�� B�� ����
//�� �� ���� ȿ������ ��Ī��?
//1���� ������ A���� ��Ī
//2�� A�� ����Ŵ
//�̹� A�� ���� �Ǿ��� ������ 1�� �ٸ� ���� ������ �� �ִ��� Ȯ��
//1 -> B
//2 -> A
//3�� B�� ����Ŵ
//1�� �ٸ� ���� ������ �� �ִ��� Ȯ��
//1 -> C
//2 -> A
//3 -> B


vector<int> a[MAX];
int who[MAX]; //B�׷��� ������ A�׷� ����� 
bool selected[MAX]; //�̹� ó�� �� ������ üũ 
int n = 3, m;

//��Ī�� ������ ��� true, ������ ��� false 
//x�� ����� ��Ī ���ִ� �Լ� : �Լ� �ѹ��� �Ѹ�/ �ѹ���Ī 
bool dfs(int x){
	//ex)ù�Ͽ��� A�׷� 1�� �����ϰ� return true;
	//	���� �Ͽ� selected�� �����ϰ� 2�� x�� �ֱ�.
	//	who[t]���� �̹� ��Ī�� ����� �ִ� �� �߰�. 1�� �ٸ� �Ͱ� ��Ī
	//	�� �۾��� �Ұ����� ��쿡 return false 
	
	//����� ��� ��� Ȯ��.
	for(int i=0 ; i<a[x].size() ; i++){
		 int t = a[x][i]; 
		 //x����� ������ i�� �̹� ���� �Ǿ���? 
		 if(selected[t]) continue;
		 //�ȵǾ����� ����!
		 selected[t] = true;
		 
		 //��Ī�� ����� ���ų�, �̹� ��Ī�� B�׷��� ���̰� �ٸ� ���̿� ��Ī�� ������ ��
		 if(who[t] == 0 || dfs(who[t])){ 
		 	who[t] = x;
		 	return true;
		 } 
	} 
	return false;
}

int main(void){
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	
	int count = 0;
	for(int i=0 ; i<=n ; i++){
		fill(selected, selected+MAX, false);
		if(dfs(i)) count++; //��Ī ���� 
	}
	printf("%d���� ��Ī�� �̷�������ϴ�.\n", count);
	for(int i=1 ; i<=100 ; i++){
		if(who[i] !=0 ){
			printf("%d -> %d\n" , who[i] , i);
		}
	} 
	
	return 0;
} 

//�ð� ���⵵
//O(V*E) 
