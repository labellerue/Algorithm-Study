//���� 1516 

#include <iostream>
#include <queue>
#include <vector>
#define MAX 501
using namespace std;

int n, degree[MAX], time[MAX], result[MAX];
vector<int> a[MAX];

void getBuildTime(){
	
	queue<int> q;
	
	//ù ������ ã�� : ���� ���� �ϰ��Ǿ� �� �ǹ� 
	for(int i=1 ; i<=n ; i++){
		if(degree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}
	}
	
	for(int i=1 ; i<= n ; i++){
	
		int x = q.front();
		q.pop(); 
		for(int j=0 ; j<a[x].size() ; j++){
			//�ǹ�x�� ���� �ǹ� 
			int y = a[x][j];
			result[y] = max(result[y], result[x]+time[y]);
			if(--degree[y] == 0){
				q.push(y);
			}
		}
	}
	for(int i=1 ; i<=n ; i++){
		printf("%d\n",result[i]);
	}
}

int main(void){
	
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++){
		scanf("%d", &time[i]);
		for(int j=1 ; j<MAX ; j++){
			int building;
			scanf("%d", &building);
			if(building == -1) break;
			a[building].push_back(i);
			degree[i]++;
		}
	}
	getBuildTime();
		
}
