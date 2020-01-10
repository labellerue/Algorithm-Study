//백준 2150 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX]; //고유한 번호 부여
bool finished[MAX]; //처리된 노드
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

//항상 처음 방문하는 노드만 실행 : N번 수행 
int dfs(int x){
	d[x] = ++id; //고유 번호 지정
	s.push(x);
	
	int result = d[x]; //고유번호
	for(int i=0 ; i< a[x].size() ; i++){
		int t = a[x][i];
		
		if(d[t] == 0) result = min(result, dfs(t)); //방문하지 않은 이웃 노드인 경우
		else if(!finished[t]) result = min(result,d[t]); //방문은 했지만 아직 처리중인 이웃 노드 
	} 
////////////////////†††††††핵심††††††////////////////////////////

	//부모 노드가 자기 자신인 경우 SCC 형성
	if(result == d[x]){
		vector<int> scc;
		while(1){
			int y = s.top();
			s.pop();
			scc.push_back(y);
			finished[y] = true;
			if(y == x) break; //자기 자신이 나올때까지 반복문 실행 
		}
		sort(scc.begin(), scc.end()); //문제에서 오름차순으로 출력하라고 함 
		SCC.push_back(scc);
	} 
	//자신의 부모 값을 반환
	return result; 
} 

int main(void){
	int v,e;
	scanf("%d %d", &v, &e);
	for(int i=0 ; i<e ; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
	}
	for(int i=1 ; i<=v ; i++){
		if(d[i] == 0) dfs(i);
	}
	printf("%d\n", SCC.size());
	sort(SCC.begin(), SCC.end());
	for(int i=0 ; i<SCC.size() ; i++){
		for(int j=0 ; j<SCC[i].size() ; j++){
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
