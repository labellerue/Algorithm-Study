#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

//위상정렬 
//순서가 정해져 있는 작업을 차례로 수행해야 할 때 그 순서를 결정해주기 위해 사용하는 알고리즘 
//사이클이 없음, 시작점이 있어야 함 

//진입차수 : 해당 노드의 바로 이전 행동(경로) 개수 
//ex) 1->2->3->4 
//	     ↘5 ↗ 	이 경우에 1의 진입차수=0 / 2,3,5의 진입차수=1 / 4의 진입차수=2 
//방법 :
//1. 진입차수가 0인 노드를 큐에 삽입
//2. 큐에서 원소를 꺼내 연결된 노드의 진입차수를 -1해주기 
//3. 1과 2의 반복. 모든 원소를 방문하고나서 큐에서 꺼낸 순서가 결과 
//	 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다는 뜻 

int n, inDegree[MAX]; //진입차수
vector<int> a[MAX]; 

void topology(){
	int result[MAX];
	queue<int> q;
	
	//1번의 첫 실행 
	for(int i=1 ; i<=n ; i++){
		if(inDegree[i] == 0) q.push(i);
	}
	//모든 원소를 방문해야 함 
	for(int i=1 ; i<=n ; i++){
		if(q.empty()){
			printf("사이클이 존재합니다.");
			return;
		}
		//2번 실행
		int x = q.front();
		q.pop();
		result[i] = x;
		
		for(int j=0 ; j<a[x].size() ; j++){
			int y = a[x][j];
			//2번 실행. 진입차수 -1 해주기.
			//3번 실행. 진입차수가 0이 되면 큐에 삽입. 
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

//시간 복잡도
//O(V+E)
//점의 갯수 + 간선의 갯수 만큼 시간이 소요됨.
//매우 빠름 


