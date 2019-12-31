#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000 

using namespace std;

//네트워크 플로우 
//에드몬드 카프 알고리즘 
//특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정
//용량 제한이 있는 경우에.. 
//ex)교통체증, 네트워크 데이터 전송 
//최대 유량 문제  : 유량/용량
//BFS 너비 우선 탐색 사용 
//순서 없이 가능한 모든 경로를 찾아 유량을 확인함.
//음의 유량 계산 (남아있는 모든 가능한 경로를 더 찾아내기 위해)
//  : 반대 방향으로의 흐름을 만들어 유량 빼기 실행 
//즉, BFS를 사용해서 모든 가능한 경로를 다 찾아 남아있는 용량만큼 유량을 흘려 보내기 

int n=6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end){
	while(1){
		fill(d, d+MAX, -1); //-1로 초기화 
		queue<int> q;
		q.push(start);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int i=0 ; i<a[x].size() ; i++){
				int y = a[x][i];
				//방문하지 않은 노드 중에 용량이 남은 경우 
				if(c[x][y] - f[x][y] > 0 && d[y] == -1){
					q.push(y);
					d[y] = x; //지나간 경로 저장
					if(y==end) break; //도착! 
					
				}
			}
		}
		if(d[end] == -1) break; //모든 경로를 찾았을 때 탈출 
		int flow = INF;
		for(int i=end ; i!= start ; i= d[i]){ //거꾸로 최소 유량 탐색(반대 방향으로 만들어 유량 빼기)
			flow = min(flow, c[d[i]][i] - f[d[i]][i]); 
		}
		//최소 유량만큼 추가
		for(int i=end ; i!=start ; i=d[i]){
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		} 
		result += flow;
	}
}

int main(void){
	
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;
	
	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;
	
	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;
	
	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;
	
	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;
	
	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;
	
	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;
	
	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;
	
	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;
	
	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;
	
	maxFlow(1,6);
	printf("%d", result);
		
	return 0;
}

//개념 설명 
//https://www.zerocho.com/category/Algorithm/post/5893405b588acb00186d39e0

//시간복잡도
//O(VE^2)
//정점*간선의 제곱 

