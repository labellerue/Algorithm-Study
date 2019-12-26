#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

//강한결합요소
//줄여서 SCC
//노드끼리 서로가 서로에게 갈 수 있는 경우를 SCC라고 함.
//1→2→3
// 	← 		1,2,3이 사이클이 돌 경우 SCC
//4→5→6	4는 6에게 갈 수 있으나 6은 4에게 갈 수 없으므로 SCC가 안됨 
//방향 그래프일 경우에만 의미가 있음 
//Union find 원리임
//한줄로 세웠을 때 아래 노드 중에 하나라도 상위의 노드롸 연결이 되어 있어야만 SCC가 존재한다.
//ex) 1→2→3→4→5→6→7
//			 ←---
//타잔 알고리즘 :
// DFS를 수행하면서 부모값을 체크하고, 스택에서 해당 부모값이 나올때까지 다 뽑아 체크한다. 


//DFS를 총 노드의 개수만큼 실행
int dfs(int x){
	d[x] = ++id; //노드에 고유 번호 할당
	s.push(x); //스택에 자기 자신 넣기 
	
	int parent= d[x];
	for(int i=0 ; i<a[x].size() ; i++){
		int y = a[x][i];
		if(d[y] == 0) parent = min(parent, dfs(y)); //방문하지 않은 옆 노드로 가기 
		else if(!finished[y]) parent = min(parent, d[y]); //처리중인 옆 노드
	}
	//부모 노드가 자기 자신인 경우
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t==x) break;
		}
		SCC.push_back(scc);
	} 
	//부모 값 반환
	return parent; 
} 


int main(void){
	int v=11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for(int i=1 ; i<=v ; i++){
		if(d[i] == 0){
			dfs(i);
		}
	}
	printf("SCC의 갯수 : %d\n", SCC.size());
	for(int i=0 ; i<SCC.size() ; i++){
		printf("%d번째 SCC는 ", i+1);
		for(int j=0 ; j<SCC[i].size() ; j++){
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//시간 복잡도
//O(V+E) 
