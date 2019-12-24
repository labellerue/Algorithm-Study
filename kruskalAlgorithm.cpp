#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
//최소 비용 신장 트리 
// ->가장 적은 배용으로 모든 노드를 연결
//ex)각 도시를 도로로 연결하고 할 때 비용을 최소한으로 하고자 할 때 적용되는 알고리즘
//최소 개수의 간선 : 노드 - 1
//원리
//간선 정보를 오름차순으로 정렬한 뒤에 비용이 적은 간선부터 그래프에 포함
//주의!! 사이클이 형성되지 않도록 한다. 
//1. 정렬된 순서에 맞에 그래프에 포함
//2. 포함시키기 전에 사이틀 테이블 확인
//3. 사이클을 형성하는 경우 간선을 포함하지 않음 

//Union-find로 사이클 확인 
int getParent(int parent[], int x){
	if(parent[x] == x) return x; //해당 노드가 부모 노드인가 
	return parent[x] = getParent(parent, parent[x]); //부모 노드의 값을 찾을때까지 돌자(재귀 한번이면 됨) 
}
void unionParent(int parent[], int a, int b){ //부모 노드를 하나로 통일! 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a<b){
		parent[b] = a;
	}else{
		parent[a] = b;
	}
}
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a==b){
		return 1;
	}else{
		return 0;
	}
}

//간선 클래스 선언
class Edge {
	public:
		int node[2];
		int distance; //간선의 비용 
		Edge(int a, int b, int distance){
			this ->node[0] = a;
			this ->node[1] = b;
			this ->distance = distance;
		}
		//정렬 기준 : 간선의 비용이 작은 것이 먼저 출력 
		bool operator < (Edge &edge){
			return this ->distance < edge.distance;
		}
		
		
		
};

int main(void){
	
	int n = 7; //점 개수 
	int m = 11; //간선 개수
	
	vector<Edge> v;
	v.push_back(Edge(1,7,12)); //간선 정보 입력..
	v.push_back(Edge(1,4,28));
	v.push_back(Edge(1,2,67));
	v.push_back(Edge(1,5,17));
	v.push_back(Edge(2,4,24));
	v.push_back(Edge(2,5,62));
	v.push_back(Edge(3,5,20));
	v.push_back(Edge(3,6,37));
	v.push_back(Edge(4,7,13)); 
	v.push_back(Edge(5,6,45)); 
	v.push_back(Edge(5,7,73));
	
	//간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	
	//각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for(int i=0 ; i<n ; i++){
		parent[i] = i;
	}
	
	int sum = 0; //거리의 합 
	for(int i=0 ; i<v.size() ; i++){
		//부모값이 같으면 사이클이 형성됨. 
		//부모값이 같지 않은 경우에 최소 간선으로 여김
		//parent를 0부터 계산했기 때문에 -1을 해주는 것 
		if(findParent(parent, v[i].node[0] - 1, v[i].node[1]-1) < 1){
			sum += v[i].distance;
			//부모를 같은 값으로 만들어 사이클 예방 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1]-1);
		}	
	}
	
	printf("%d\n", sum);
	
	return 0;
}









