//백준 4196 
#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX]; //고유한 번호 부여
bool finished[MAX]; //처리된 노드
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX]; //연결된 노드들끼리 그룹을 지어 번호 매기기 
bool inDegree[MAX]; 

//항상 처음 방문하는 노드만 실행 : N번 수행 
int dfs(int x){
	d[x] = ++id; //고유 번호 지정
	s.push(x);
	
	int parent = d[x]; //고유번호
	for(int i=0 ; i< a[x].size() ; i++){
		int t = a[x][i];
		
		if(d[t] == 0) parent = min(parent, dfs(t)); //방문하지 않은 이웃 노드인 경우
		else if(!finished[t]) parent = min(parent,d[t]); //방문은 했지만 아직 처리중인 이웃 노드 
	} 
////////////////////†††††††핵심††††††////////////////////////////

	//부모 노드가 자기 자신인 경우 SCC 형성
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int y = s.top();
			s.pop();
			scc.push_back(y);
			group[y] = SCC.size() +1; //같은 순환끼리 그룹명 지어주기 
			finished[y] = true;
			if(y == x) break; //자기 자신이 나올때까지 반복문 실행 
		}
		SCC.push_back(scc);
	} 
	//자신의 부모 값을 반환
	return parent; 
} 

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		SCC.clear();
		fill(d, d+MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		
		scanf("%d %d", &n, &m);
		for(int i=1 ; i<=n ; i++){
			a[i].clear();
		}
		for(int i=0 ; i<m ; i++){
			int x, y;
			scanf("%d %d", &x,&y);
			a[x].push_back(y);
		}
		
		for(int i=1 ; i<= n ; i++){
			if(d[i] ==0) dfs(i);
		}
		//연결된 이전 도미노가 넘어지면 자동으로 넘어지므로 true값으로 .. 
		for(int i=1 ; i<=n ; i++){
			for(int j=0; j<a[i].size() ; j++){
				int y= a[i][j];
				if(group[i] != group[y]) inDegree[group[y]] = true;
			}
		}
		int result = 0;
		for(int i=1 ; i<= SCC.size() ; i++){
			if(!inDegree[i]) result++;
		}
		printf("%d", result);
	}
	
	return 0;
}
