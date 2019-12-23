#include <stdio.h>

int main(void){
	//선택정렬 : 가장 작은 것을 앞으로 보내자
	int i, j, min, index, temp;
	int array[10] = {1,10,5,8,7,6,4,3,2,9};
	for(i=0 ; i<10 ; i++){
		min = 9999;
		for(j=i ; j<10 ; j++){
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for(i=0 ; i<10 ; i++){
		printf("%d ",array[i]);
	}
	return 0;
}
