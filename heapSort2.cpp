#include <stdio.h>

int number = 10;
int heap[10] = {26,5,37,1,61,11,59,15,48,19}; 
int main(void){
	
	//먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다. 
	for(int i=1 ; i<number ; i++){
		int c=i;
		do{
			int root = (c-1)/2; //c의 부모 자리 
			if(heap[root] < heap[c]){
				 int temp = heap[root];
				 heap[root] = heap[c];
				 heap[c] = temp;
			}
			c = root; //이렇게 바뀐 자리가 아직 heap이 아닐 경우를 위해 재귀 
		}while(c != 0);
	}
	
	//크기를 줄여가며 반복적으로 힙을 구성 -> 최댓값이 가장 앞으로 옮겨짐 
	//가장 큰 값을 가장 뒤로 보내기 
	for(int i=number-1 ; i>=0 ; i--){
		for(int i=0 ; i<number ; i++){
			printf("%d " , heap[i]);
		}
		printf("\n");
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp; 
		
		//다시 힙 구조 만들기 
		int root = 0;
		int c=1;
		do{
			c=2*root+1;
			//자식 중에 더 큰 값을 찾기
			if(heap[c] < heap[c+1] && c<i-1){
				c++;
			} 
			//루트보다 자식이 더 크다면 교환
			if(heap[root] < heap[c] && c<i){
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			} 
			root = c;
		}while(c<i);
		
	} 
	
//	for(int i=0 ; i<number ; i++){
//		printf("%d " , heap[i]);
//	}
	
	
	return 0;
}


