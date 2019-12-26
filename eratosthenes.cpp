#include <stdio.h>

//에라토스테네스의 체 
//소수를 빠르게 판별하는 알고리즘 
//방법 : 
//1. 수 만큼 배열에 할당
//2. 2의 배수는 2를 제외하고 모두 지우기(0으로 대체) 
//3. 3의 배수는 3을 제외하고 모두 지우기(0으로 대체) 
//4. 4는 지워졌기 때문에 제외(이미 0으로 바뀜) 
//...
//5. 2부터 시작해 남아있는 숫자들을 출력 

//int size = 100000;
//int num[100001];

void isPrimeNumSieve(int x){
	int size = x;
	int num[x+1];

	//1번 작업 : 수 만큼 배열에 할당 
	for(int i=2 ; i<=size ; i++){
		num[i] = i;
	}
	
	for(int i=2 ; i<=size ; i++){
		//4번 작업 : 이미 지운 것은 통과 
		if(num[i] == 0) continue;
		
		//2,3번 작업 : i의 배수인 것들을 모두 제거 
		for(int j= i+i ; j<=size ; j += i){
			num[j] = 0;
		}
	}
	for(int i = 2 ; i<=size ; i++){
		if(num[i] != 0){
			printf("%d ", num[i]);
		}
	}
	
} 

int main(void){
	int input;
	scanf("%d", &input);
	isPrimeNumSieve(input);

	return 0;
}


