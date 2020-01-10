//백준 1671
#include <iostream>
#include <vector>
#define NUM 51

using namespace std;

vector<int> a[NUM];
int biggerShark[NUM];
bool selected[NUM];
int stat[NUM][3];

bool bMatching(int x){
	
	for(int i=0 ; i<a[x].size() ; i++){
		int t = a[x][i];
		
		if(selected[t]) continue;
		selected[t] = true;
		
		if(biggerShark[t] ==0 || bMatching(biggerShark[t])){
			biggerShark[t] = x;
			return true;
		}
	}
	
	return false;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++){
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	
	//누가 누굴 잡아먹을 수 있는지 a에 넣기
	//중복되지 않게 계산
	//같을 경우가 겹치는 이유는 같을 경우 서로가 잡아먹을 수 있는 경우이기 때문 
	for(int i=1 ; i<n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			if(stat[i][0]==stat[j][0]&&stat[i][1]==stat[j][1]&&stat[i][2]==stat[j][2]){
				a[i].push_back(j);
			}else if(stat[i][0]>=stat[j][0]&&stat[i][1]>=stat[j][1]&&stat[i][2]>=stat[j][2]){
				a[i].push_back(j);
			}else if(stat[i][0]<=stat[j][0]&&stat[i][1]<=stat[j][1]&&stat[i][2]<=stat[j][2]){
				a[j].push_back(i);
			}
		}
	} 
	
	int count=0;
	//최대 두마리를 잡아먹을 수 있음 
	for(int j=0 ; j<2 ; j++){
		for(int i=1 ; i<=n ; i++){
			fill(selected, selected+NUM, false);
			if(bMatching(i)) count++;
		}
	}
	//전체 - 잡아먹히는 상어(매칭 성립된 상어) = 살아 남는 상어 
	printf("%d",n-count);
	
	return 0; 
}
