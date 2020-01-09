//백준 2188 
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int cowToRoom[MAX];
bool selected[MAX];

bool bMatching(int x){
	
	for(int i=0 ; i<a[x].size() ; i++){
		int t = a[x][i]; //x소가 원하는 축사 
		
		if(selected[t]) continue; //재귀에서 선택 여부 확인
		//선택하고 
		selected[t] = true;
		
		//그 방을 선택한 소가 없거나 || 다른 소가 이미 선택했지만 양보해줄 수 있다면 
		if(cowToRoom[t] == 0 || bMatching(cowToRoom[t])){ 
			cowToRoom[t] = x;
			return true;
		}
	}
	return false;
	
}

int main(void){
	
	int cowNum, roomNum;
	scanf("%d%d",&cowNum, &roomNum);
	
	for(int i=1 ; i<=cowNum ; i++){
		int x;
		scanf("%d", &x);
		for(int j=0 ; j<x ; j++){
			int y;
			scanf("%d", &y);
			a[i].push_back(y);
		}
	}
	
	int count;
	for(int i=1 ; i<=cowNum ; i++){
		fill(selected, selected+MAX, false);
		if(bMatching(i)) count++;
	}
	printf("%d", count);
	
	return 0;
}

