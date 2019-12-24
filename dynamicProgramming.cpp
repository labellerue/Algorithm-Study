#include <stdio.h>

//컴퓨팅 사고력
//동적 계획법
//하나의 문제를 단 한번만 풀도록 하는 알고리즘 
//이미 계산한 결과는 배열에 저장. 나중에 동일한 게산을 해야할 때 저장된 값을 단순 반환 
//memoization 시간복잡도가 O(N)이 됨. 

int d[100];

int dp(int x){
	if(x == 1) return 1;
	if(x == 2) return 1;
	if(d[x] != 0) return d[x]; //이미 구한 값이라면 그 값 바로 리턴 
	return d[x] = dp(x-1)+dp(x-2);
}

int main(void){
	
	printf("%d", dp(5));
	
	return 0;
}




