#include <stdio.h>

//�Ҽ� ���ϴ� �˰��� 
//�ð����⵵ O(N) 
bool isPrimeNum(int x){
	for(int i=2 ; i<x ; i++){
		if(x%i == 0){
			return false;
		}
	}
	return true;
} 
int main(void){
	printf("%d",isPrimeNum(97));
	return 0;
}

//�ð����⵵ 
//O(N)
//��� ����� ���� ���Ƽ�. 
