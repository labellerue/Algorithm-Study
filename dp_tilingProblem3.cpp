#include <stdio.h>

//백준 2133

int counted[31];
int dp(int x){
	if(x == 0) return 1; //result += 2*dp(x-i) 계산 시 경우의 수를 카운트 해주기 위해 
						 //x가 4일 경우 2일 경우*2일 경우+4일 때 추가적인 경우 
						 //= 3*3+2
	if(x == 1) return 0;
	if(x == 2) return 3;
	if(counted[x]!=0) return counted[x];
	
	int result = 3*dp(x-2);
	for(int i=3 ; i<=x ; i++){
		//짝수일 경우 가지수가 2개씩 능가함 
		//홀수일 경우 불가능.
		if(x%2 < 1){
			result += 2*dp(x-i);
		}
	}
	return counted[x] = result; 
	
}

int main(void){
	int input;
	scanf("%d" , &input);
	
	printf("%d",dp(input));
	
	return 0;
}
