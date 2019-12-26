#include <stdio.h>

//다익스트라 알고리즘
//다이나믹 / 그리드 알고리즘  
//최단경로 탐색 알고리즘
//ex) 인공위성 GPS에서 가장 많이 사용됨 
//방법 :
//1. 출발 노드 설정
//2. 출발 노드를 기준으로 다른 노드로 가는 길의 비용 저장
//3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택
//4. 그 노드를 거쳐서 특정 노드로 가는 경우를 비교해 최소 비용 갱신
//  (1-3보다 1-2-3으로 가는게 더 저렴하면 비용 갱신 
//3번과 4번 반복 

//2차원 배열 이용 
//0. 0층 배열 
//출발 노드를 1로 설정 
//자기 자신에게 가는 비용은 0 -> 0,0은 0
//1에서 2로 가는데 드는 비용이 2 -> 0,1은 2 
//1에서 3으로 가는데 드는 비용이 5 -> 0,2는 5
//1. 1층 배열 
//출발 노드를 2로 설정 
//자기 자신에게 가는 비용은 0 -> 1,1은 0
//2에서 3으로 가는데 드는 비용이 3 -> 1,2는 3 
//...
//직접적인 연결이 없는 곳은 무한으로 놓기 

//그 다음 갱신 작업 
//다른 노드를 거쳐서 비용 계산을 했을 때 이전 값보다 작으면 갱신 

int number = 6;
int INF = 1000000000; //int의 최대값 

//전체 그래프 초기화
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool visited[6]; //방문 여부 확인 : 행 6개 (출발 노드 1번을 다 방문 했는가) 
int distance[6]; //최소 거리 1 가는데 최소, 2 가는데 최소.. : 열 6개 

//최소 거리를 가지는 점 반환 
int getSmallDistance(){
	int min = INF;
	int index = 0;
	for(int i=0 ; i<number ; i++){
		if(!visited[i] && distance[i] < min){ //방문 안한 곳 중에 더 작은 값 발견 시 
			min = distance[i];
			index = i;
		} 
	}
	return index;
}

//다익스트라 수행 함수 
void dijkstra(int startPoint){ //시작 점 지정 
	for(int i=0 ; i< number ; i++){
		distance[i] = a[startPoint][i]; 
		//일단 그래프의 초기값이 최소 거리값이 된다. 
		//이후 더 작은 값 발견하면 바꿀거야 
	}
	visited[startPoint] = true; //방문했으니 방문 처리 
	for(int i=0 ; i< number -2 ; i++){
		int current = getSmallDistance(); //start행에서 가장 작은 비용 가져오기 
		visited[current] = true;
		
		//가장 작은 비용의 길(=current행)로 넘어가서 기존 distance값과 비교 
		for(int j=0 ; j<6 ; j++){
			if(!visited[j]){ //방문 안한 행 중에 (이미 방문한 노드들은 최소값 다 찾아놓았음) 
				if(distance[current] + a[current][j] < distance[j]){ 
					//한방에 가는 것보다 건너가는게 더 저렴하다면
					distance[j] = distance[current] + a[current][j]; 
				} 
			}
		}
	}
	
}

int main(void){
	dijkstra(0);//0에서 출발해서 각각 1,2,3,4,5에 도착하는 최단거리? 
	for(int i=0 ; i<number ; i++){
		printf("%d ", distance[i]);
	}
	return 0;
} 


//선형탐색 이용
//시간복잡도
//O(N^2) 
//오래걸림.. 
//getSmallDistance()의 수정이 필요함. 








