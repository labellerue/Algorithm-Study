#include <iostream>
#include <vector>

using namespace std;

//DFS 
//stack 사용
//컴퓨터는 구조적으로 항상 스택의 원리를 사용
//문제 ex)그래프 
//최상단 노드 스택에 넣기			1
//최상단 노드를 방문하지 않은 노드를 방문하고
//스택에 넣기				2
// push 1 -> 2 -> 3 -> 6-> 7
// pop  7 -> 6 -> 3
// push 4 -> 5
// pop  5 -> 4 -> 2 -> 1
//방문하지 않은 인접노드가 없으면 스택에서 최상단 노드를 뺀다. 
/////////반복////////// 

//그런데 stack 사용보다 재귀함수로 구현함.
//컴터는 기본 stack원리이기 때문에  

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x){
	if(c[x]) return; //이미 방문한 노드면 끝
	c[x] = true;
	cout << x << ' ';
	for(int i=0; i<a[x].size() ; i++){
		int y = a[x][i];
		dfs(y);
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

	dfs(1);

	
	return 0;
}
