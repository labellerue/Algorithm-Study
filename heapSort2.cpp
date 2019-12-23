#include <stdio.h>

int number = 10;
int heap[10] = {26,5,37,1,61,11,59,15,48,19}; 
int main(void){
	
	//���� ��ü Ʈ�� ������ �ִ� �� ������ �ٲߴϴ�. 
	for(int i=1 ; i<number ; i++){
		int c=i;
		do{
			int root = (c-1)/2; //c�� �θ� �ڸ� 
			if(heap[root] < heap[c]){
				 int temp = heap[root];
				 heap[root] = heap[c];
				 heap[c] = temp;
			}
			c = root; //�̷��� �ٲ� �ڸ��� ���� heap�� �ƴ� ��츦 ���� ��� 
		}while(c != 0);
	}
	
	//ũ�⸦ �ٿ����� �ݺ������� ���� ���� -> �ִ��� ���� ������ �Ű��� 
	//���� ū ���� ���� �ڷ� ������ 
	for(int i=number-1 ; i>=0 ; i--){
		for(int i=0 ; i<number ; i++){
			printf("%d " , heap[i]);
		}
		printf("\n");
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp; 
		
		//�ٽ� �� ���� ����� 
		int root = 0;
		int c=1;
		do{
			c=2*root+1;
			//�ڽ� �߿� �� ū ���� ã��
			if(heap[c] < heap[c+1] && c<i-1){
				c++;
			} 
			//��Ʈ���� �ڽ��� �� ũ�ٸ� ��ȯ
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


