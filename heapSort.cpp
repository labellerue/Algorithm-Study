#include <stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6}; 
int main(void){
	//힙 트리 구조를 이용하는 정렬 방법 
	//2진 트리. 노드를 두개씩 이어 붙이는 구조 
	//완전 이진트리 : 데이터가 왼쪽에서부터 차근차근 들어감.
	//		1
	//	2		3
	//4	  5	  6   7 
	//힙 : 최소값이나 최대값을 찾아내기 위해 완전 이진트리를 사용. 자식보다 부모 값이 커야함. 
	//heapify algorithm : 부모 노드보다 자식 노드가 클 때 서로 바꾸어 heap을 유지
	 
	//첫번째 힙 구조가 완성되고 가장 큰 수인 가장 위 머리를 가장 아래와 바꿈.
	//그리고 나서 또다시 힙 정렬(heapify) 시작. 
	
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
	
	for(int i=0 ; i<number ; i++){
		printf("%d " , heap[i]);
	}
	
	
	return 0;
}

//시간 복잡도
//O(N * logN)
//트리의 높이 * heapify
//실재 시간 복잡도는 1/2N * logN
//1/2은 작은 수기 때문에 O(N * logN)
