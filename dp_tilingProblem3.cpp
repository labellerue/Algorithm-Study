#include <stdio.h>

//���� 2133

int counted[31];
int dp(int x){
	if(x == 0) return 1; //result += 2*dp(x-i) ��� �� ����� ���� ī��Ʈ ���ֱ� ���� 
						 //x�� 4�� ��� 2�� ���*2�� ���+4�� �� �߰����� ��� 
						 //= 3*3+2
	if(x == 1) return 0;
	if(x == 2) return 3;
	if(counted[x]!=0) return counted[x];
	
	int result = 3*dp(x-2);
	for(int i=3 ; i<=x ; i++){
		//¦���� ��� �������� 2���� �ɰ��� 
		//Ȧ���� ��� �Ұ���.
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
