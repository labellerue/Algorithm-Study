//백준 2522

#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int degree[MAX];
vector<int> a[MAX];

void getOrder(int student){
	
	int result[student+1];
	queue<int> q;
	
	//첫 시작점 찾기 : 가장 앞에 와야할 학생
	for(int i=1 ; i<=student ; i++){
		if(degree[i] == 0) q.push(i);
	} 
	
	for(int i=1 ; i<= student ; i++){
		if(q.empty()){
			printf("잘못된 입력입니다.");
			return; 
		}
		
		int x = q.front();
		result[i] = x;
		q.pop();
		
		for(int j=0 ; j<a[x].size() ; j++){
			//시작점이 가리키는 곳 
			int y = a[x][j];
			if(--degree[y] == 0){
				q.push(y);
			}
		}
	}
	for(int i=1 ; i<=student ; i++){
		printf("%d ",result[i]);
	}
}

int main(void){
	int student, num;
	scanf("%d %d", &student, &num);
	for(int i=0 ; i<num ; i++ ){
		int x,y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		degree[y]++;
	}
	getOrder(student);
		
}
