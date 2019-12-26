#include <stdio.h>

//소수 구하는 알고리즘 
//시간복잡도 O(N) 
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

//시간복잡도 
//O(N)
//모든 경우의 수를 돌아서. 
