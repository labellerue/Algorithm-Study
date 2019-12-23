#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//BFS
//너비를 우선으로 하여 탐색하는 것
//최단 경로 찾기 ex)미로탐색
//Queue 사용!
//시작 노드를 큐에 넣기			1
//시작 노드를 방문처리			1 
//큐에서 노드 꺼내기			'1'
//그에 연결된 노드 중 방문하지 않은 노드를 방문하고
//차례대로 큐에 넣기			2 3
/////////반복////////// 

//1에서 가까운 노드들 부터 탐색이 이루어짐.

int number = 7;
int c[7]; //방문처리 
vector<int> a[8]; //인덱스 노드를 1부터 처리하게 해주기 위해. 

void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()){
		 int x = q.front();
		 q.pop();
		 printf("%d ",x);
		 for(int i=0 ; i<a[x].size(); i++){
		 	int y= a[x][i];
			 if(!c[y]){
			 	q.push(y);
			 	c[y] = true;
			 }	
		 }
		 
	}
}

int main(void){
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);


	
	return 0;
}
