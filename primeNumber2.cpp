#include <stdio.h>
#include <math.h>

//소수 구하는 알고리즘 
//시간복잡도 O(N^1/2) 
bool isPrimeNum(int x){
	int end = (int)sqrt(x); //특정 숫자의 제곱근까지만 계산  √x(루트 x) 
	for(int i=2 ; i<=end ; i++){
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
//O(N^1/2)
//제곱 수의 경우를 제외 
