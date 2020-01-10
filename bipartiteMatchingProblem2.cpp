//백준 11375
//백준 11376
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int manager[MAX];
bool selected[MAX];

bool bMatching(int x){
	
	for(int i=0 ; i<a[x].size() ; i++){
		int t = a[x][i];
		
		if(selected[t]) continue;
		selected[t] = true;
		
		if(manager[t] == 0 || bMatching(manager[t])){ 
			manager[t] = x;
			return true;
		}
	}
	return false;
	
}

int main(void){
	
	int emp, work;
	scanf("%d %d",&emp, &work);
	
	for(int i=1 ; i<=emp ; i++){
		int x;
		scanf("%d", &x);
		for(int j=0 ; j<x ; j++){
			int y;
			scanf("%d", &y);
			a[i].push_back(y);
		}
	}
	
	int count=0;
	//백준 11376 한 직원 당 일을 두개씩 할 수 있다면.. 2번 실행해 매니저 없는 배열 채우기 
	for(int j=0 ; j<2 ; j++){
		for(int i=1 ; i<=emp ; i++){
			fill(selected, selected+MAX, false);
			if(bMatching(i)) count++;
		}
	}
	printf("%d", count);
	
	return 0;
}

