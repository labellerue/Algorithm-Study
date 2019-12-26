#include <stdio.h>

//모든 점에서 모든 점으로의 최단 경로 구하기 
//거쳐가는 점을 기준으로 알고리즘 수행 
//즉, 2-3과 2-1로 갔다가 1-3으로 돌아갈 때를 비교 
//이것도 바로 갈 수 없는 경우를 무한으로 두기 때문에
//2-3이 9, 2-1이 7, 1-3이 불가능:무한 일 때 -> 9 vs 7+무한으로 계산하여
//2-3이 더 저렴하다고 봄
//이렇게 노드 1을 거치는 경우
//		 노드 2를 거치는 경우
//		 ...자기 자신은 뺴기 


int number = 4;
int INF = 1000000000;

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall(){
	//결과 그래프 초기화
	int dist[number][number];
	
	for(int i=0 ; i<number ; i++){
		for(int j=0 ; j<number ; j++){
			dist[i][j] = a[i][j];
		}
	}
	//거치는 노드를 기준으로 작업하기  
	//k -> 거쳐가는 노드
	for(int k=0 ; k<number ; k++){
		//i -> 출발  노드 
		for(int i=0 ; i<number ; i++){
			//j -> 도착 노드 
			for(int j=0 ; j<number ; j++){
				if(dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	} 
	for(int i=0 ; i<number ; i++){
		for(int j=0 ; j<number ; j++){
			printf("%3d ", dist[i][j]);
		}
		printf("\n");
		
	}
}


int main(void){
	
	floydWarshall();
	return 0;
} 


//시간 복잡도
//O(N^3)
//삼중 for문 이용 

 
