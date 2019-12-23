#include <stdio.h>

int main(void){
	//삽입정렬 : 정렬의 대상을 하나씩 늘려가며 정렬이 필요한 요소를 선택해 삽입.
	//_1_3 2일 때 2의 위치를 1과 3의 사이에 삽입. 
	//정렬이 되어 있다는 가정을 한다는 점에서 속도가 빠름. 정렬 되어 있는건 안 건드림. 
	
	int i, j, temp; 
	int array[10] = {10,5,8,7,6,4,3,2,9,1};
	for(i=0 ; i<9 ; i++){
		j = i;
		//옆의 값보다 작은 값을 발견했을 때 알맞은 자리를 찾을 때까지 왼쪽으로 자리를 바꿔준다. 
		while(array[j] > array[j+1]){
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			j--;
		}
	}
	for(i=0 ; i<10 ; i++){
		printf("%d ",array[i]);
	}
	
	return 0;
}
