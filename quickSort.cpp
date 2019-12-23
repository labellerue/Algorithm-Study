#include <stdio.h>

int number = 10;
int data[10] = {5,8,7,6,10,1,4,3,2,9};

void quickSort(int *data, int start, int end){
	if(start >= end){//원소가 1개인 경우 
		return; 
	}
	
	int key = start; //키는 첫번째 원소(피벗 값)
	int i = start + 1; //왼쪽 출발지점 (index)
	int j = end; //오른쪽 출발지점 (index)
	int temp;
	
	while(i <= j) {//엊갈릴때 까지 돌림 -엊갈리면 탈출  
		 while(data[i] <= data[key] ){ //키 값보다 큰 값을 만날 때 까지 
//내림차순while(data[i] >= data[key] ){ 
		 	i++;
		 }
		 while(data[j] >= data[key] && j>start ) {//키 값보다 작은 값을 만날 때 까지  
//내림차순while(data[j] <= data[key] ) {
		 	j--;
		 }
		 if(i > j){//현재 엇갈린 상태면 키 값과 교체
		 	temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		 }else{ // 엇갈리지 않았으면 두개 값을 교체  
		 	temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		 }
	}
	//재귀적 함수  
	quickSort(data, start, j-1); //새로 정해진 피벗의 왼쪽을 정렬 
	quickSort(data, j+1, end); //새로 정해진 피벗의 오른쪽을 정렬 
}
int main(void){
	//퀵 정렬 :  특정한 값을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눔.
	//피벗(Pivot) 기준값으로 분할 
	//예시) 3/4 5 2 1  ..3을 기준으로 왼쪽에서부터 큰 값, 오른쪽에서부터 작은 값을 찾아 서로 바꿔줌 
	//		3/1 5 2 4  ..다시 3 기준 
	//		3/1 2 5 4  ..이때는 3 기준으로  큰값과 작은 값이 크로싱 되기 때문에 3과 작은 값을 바꿔줌 
	//		2/1 3 5 4  ..이제 Pivot은 2
	//		1/2 3 5 4 
	//		1/2 3 5 4 
	//		1 2 3 5/4  ..이제 5가 기준이 됨. 
	quickSort(data, 0, number-1);
	for(int i=0; i<number ; i++){
		printf("%d ", data[i]);
	}
	
	return 0;
}

//평균속도
//O(N*logN) 
//1 2 3 4 5  / 6 7 8 9 10  -> N/2 * N/2 + N/2 * N/2 = 5*5 + 5*5 = 50
//다른 sort의 경우 1 2 3 4.. ->  N*N = 10*10 = 100

