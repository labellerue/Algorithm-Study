#include <stdio.h>

int main(void){
	
	//버블정렬 : 옆의 값과 비교해 자리 바꿈 --> 가장 큰 수 부터 배치 
	//! 가장 비효율 ! 
	int i, j, temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	for(i=0 ; i<10 ; i++){
		for(j=0 ; j<10-1-i ; j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}

	}	
	for(i=0 ; i<10 ; i++){
		printf("%d ",array[i]);
	}
	return 0;
}
