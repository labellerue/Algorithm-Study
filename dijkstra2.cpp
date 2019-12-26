#include <iostream>
#include <vector>
#include <queue> //우선순위 큐 이용 = heap과 같은 작동 방식 

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int> > a[7]; //간선 정보 
int dist[7]; //최소 비용 
  
void dijkstra(int start){
	dist[start] = 0; //자기 자신으로 가는 비용은 0 
	priority_queue<pair<int, int> > pq; //힙 구조 내림차순 
	pq.push(make_pair(start,0));
	//가까운 순서대로 처리하므로 큐를 사용
	while(!pq.empty()){
		int current = pq.top().first;
		
		int d = -pq.top().second; //값이 작은 것이 먼저 오도록 음수화(-)
		pq.pop();
		
		//기존 값보다 크면 넘어가기
		if(dist[current] < d) continue;
		for(int i=0 ; i<a[current].size() ; i++){
			
			int next = a[current][i].first; //선택된 노드의 옆 친구들
			int nextDistance = d + a[current][i].second; //next까지 돌아가는 비용
			
			if(nextDistance < dist[next]) { //기존 비용과 돌아가는 비용 비교
				dist[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		} 
	} 
}
  
int main(void){
	
	//비용 모르는값으로 초기화, 0번 방은 사용 안함 
	for(int i=1 ; i<number+1 ; i++){
		dist[i] = INF;
	} 
	
	a[1].push_back(make_pair(2,2));
	a[1].push_back(make_pair(3,5));
	a[1].push_back(make_pair(4,1));
	
	a[2].push_back(make_pair(1,2));
	a[2].push_back(make_pair(3,3));
	a[2].push_back(make_pair(4,2));
	
	a[3].push_back(make_pair(1,5));
	a[3].push_back(make_pair(2,3));
	a[3].push_back(make_pair(4,3));
	a[3].push_back(make_pair(5,1));
	a[3].push_back(make_pair(6,5));
	
	a[4].push_back(make_pair(1,1));
	a[4].push_back(make_pair(2,2));
	a[4].push_back(make_pair(3,3));
	a[4].push_back(make_pair(5,1));
	
	a[5].push_back(make_pair(3,1));
	a[5].push_back(make_pair(4,1));
	a[5].push_back(make_pair(6,2));
	
	a[6].push_back(make_pair(3,5));
	a[6].push_back(make_pair(5,2));
	
	dijkstra(1);
	
	for(int i=1 ; i<number+1 ; i++){
		printf("%d ", dist[i]);
	}
	
	return 0;
}
