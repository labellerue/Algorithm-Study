#include <stdio.h>

//백준 14852 

long counted[1000001][2];

long dp(int x){
//	if(x == 0) return 1;
//	if(x == 1) return 2;
//	if(counted[x]!=0) return counted[x];
//	
//	int result = 2*dp(x-1)+3*dp(x-2); //배열1 
//	for(int i=3 ; i<=x ; i++){
//		result += 2*dp(x-i);		  //배열2
//	}
//	return counted[x] = result;
	//시간 초과
	//시간 복잡도를 O(N)으로 수정↓↓↓↓↓
	counted[0][0] = 0;
	counted[1][0] = 2;
	counted[2][0] = 7;
	counted[2][1] = 1;
	for(int i=3 ; i<=x ; i++){
		counted[i][1] = (counted[i-1][1] + counted[i-3][0])%1000000007; //배열1 
		counted[i][0] = (2*counted[i-1][0] + 3*counted[i-2][0] + 2*counted[i][1])%1000000007; //배열2 
	}
	return counted[x][0];
}
int main(void){
	int input;
	scanf("%d", &input);
	printf("%d", dp(input));
	
	return 0;
}
