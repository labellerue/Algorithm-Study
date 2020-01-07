#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

//이분매칭 Bipartite Matching
//매칭 프로그램 : A집단이 B집단을 선택하는 방법 
//효과적인 매칙 => 최대 매칭(Max Matching) 
//네트워크 플로우와 유사
//DFS로 실행 가중치를 1로 설정

//예시
//1은 A,B,C를 원함
//2는 A를 원함
//3은 B를 원함
//이 떄 가장 효율적인 매칭은?
//1부터 시작해 A부터 매칭
//2가 A를 가리킴
//이미 A는 선택 되었기 때문에 1이 다른 것을 선택할 수 있는지 확인
//1 -> B
//2 -> A
//3이 B를 가리킴
//1이 다른 것을 선택할 수 있는지 확인
//1 -> C
//2 -> A
//3 -> B


vector<int> a[MAX];
int who[MAX]; //B그룹을 선택한 A그룹 당사자 
bool selected[MAX]; //이미 처리 한 것인지 체크 
int n = 3, m;

//매칭에 성공한 경우 true, 실패한 경우 false 
//x번 사람을 매칭 해주는 함수 : 함수 한번에 한명/ 한번매칭 
bool dfs(int x){
	//ex)첫턴에서 A그룹 1을 선택하고 return true;
	//	다음 턴에 selected를 리셋하고 2를 x에 넣기.
	//	who[t]에서 이미 매칭된 사람이 있는 것 발견. 1을 다른 것과 매칭
	//	위 작업이 불가능할 경우에 return false 
	
	//연결된 모든 노드 확인.
	for(int i=0 ; i<a[x].size() ; i++){
		 int t = a[x][i]; 
		 //x사람이 선택한 i가 이미 선택 되었니? 
		 if(selected[t]) continue;
		 //안되었으면 선택!
		 selected[t] = true;
		 
		 //매칭된 사람이 없거나, 이미 매칭된 B그룹의 아이가 다른 아이와 매칭이 가능할 때
		 if(who[t] == 0 || dfs(who[t])){ 
		 	who[t] = x;
		 	return true;
		 } 
	} 
	return false;
}

int main(void){
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	
	int count = 0;
	for(int i=0 ; i<=n ; i++){
		fill(selected, selected+MAX, false);
		if(dfs(i)) count++; //매칭 성공 
	}
	printf("%d개의 매칭이 이루어졌습니다.\n", count);
	for(int i=1 ; i<=100 ; i++){
		if(who[i] !=0 ){
			printf("%d -> %d\n" , who[i] , i);
		}
	} 
	
	return 0;
} 

//시간 복잡도
//O(V*E) 
