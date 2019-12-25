#include <stdio.h>

//���� 14852 

long counted[1000001][2];

long dp(int x){
//	if(x == 0) return 1;
//	if(x == 1) return 2;
//	if(counted[x]!=0) return counted[x];
//	
//	int result = 2*dp(x-1)+3*dp(x-2); //�迭1 
//	for(int i=3 ; i<=x ; i++){
//		result += 2*dp(x-i);		  //�迭2
//	}
//	return counted[x] = result;
	//�ð� �ʰ�
	//�ð� ���⵵�� O(N)���� ����������
	counted[0][0] = 0;
	counted[1][0] = 2;
	counted[2][0] = 7;
	counted[2][1] = 1;
	for(int i=3 ; i<=x ; i++){
		counted[i][1] = (counted[i-1][1] + counted[i-3][0])%1000000007; //�迭1 
		counted[i][0] = (2*counted[i-1][0] + 3*counted[i-2][0] + 2*counted[i][1])%1000000007; //�迭2 
	}
	return counted[x][0];
}
int main(void){
	int input;
	scanf("%d", &input);
	printf("%d", dp(input));
	
	return 0;
}
