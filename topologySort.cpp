#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

//�������� 
//������ ������ �ִ� �۾��� ���ʷ� �����ؾ� �� �� �� ������ �������ֱ� ���� ����ϴ� �˰��� 
//����Ŭ�� ����, �������� �־�� �� 

//�������� : �ش� ����� �ٷ� ���� �ൿ(���) ���� 
//ex) 1->2->3->4 
//	     ��5 �� 	�� ��쿡 1�� ��������=0 / 2,3,5�� ��������=1 / 4�� ��������=2 
//��� :
//1. ���������� 0�� ��带 ť�� ����
//2. ť���� ���Ҹ� ���� ����� ����� ���������� -1���ֱ� 
//3. 1�� 2�� �ݺ�. ��� ���Ҹ� �湮�ϰ��� ť���� ���� ������ ��� 
//	 ��� ���Ҹ� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �����Ѵٴ� �� 

int n, inDegree[MAX]; //��������
vector<int> a[MAX]; 

void topology(){
	int result[MAX];
	queue<int> q;
	
	//1���� ù ���� 
	for(int i=1 ; i<=n ; i++){
		if(inDegree[i] == 0) q.push(i);
	}
	//��� ���Ҹ� �湮�ؾ� �� 
	for(int i=1 ; i<=n ; i++){
		if(q.empty()){
			printf("����Ŭ�� �����մϴ�.");
			return;
		}
		//2�� ����
		int x = q.front();
		q.pop();
		result[i] = x;
		
		for(int j=0 ; j<a[x].size() ; j++){
			int y = a[x][j];
			//2�� ����. �������� -1 ���ֱ�.
			//3�� ����. ���������� 0�� �Ǹ� ť�� ����. 
			if(--inDegree[y] == 0){
				q.push(y);
			}
		}
	}
	for(int i=1 ; i<=n ; i++){
		printf("%d ", result[i]);
	}
}

int main(void){
	
	n=7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	
	topology();
	
	return 0;
}

//�ð� ���⵵
//O(V+E)
//���� ���� + ������ ���� ��ŭ �ð��� �ҿ��.
//�ſ� ���� 


