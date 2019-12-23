#include <stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6}; 
int main(void){
	//�� Ʈ�� ������ �̿��ϴ� ���� ��� 
	//2�� Ʈ��. ��带 �ΰ��� �̾� ���̴� ���� 
	//���� ����Ʈ�� : �����Ͱ� ���ʿ������� �������� ��.
	//		1
	//	2		3
	//4	  5	  6   7 
	//�� : �ּҰ��̳� �ִ밪�� ã�Ƴ��� ���� ���� ����Ʈ���� ���. �ڽĺ��� �θ� ���� Ŀ����. 
	//heapify algorithm : �θ� ��庸�� �ڽ� ��尡 Ŭ �� ���� �ٲپ� heap�� ����
	 
	//ù���� �� ������ �ϼ��ǰ� ���� ū ���� ���� �� �Ӹ��� ���� �Ʒ��� �ٲ�.
	//�׸��� ���� �Ǵٽ� �� ����(heapify) ����. 
	
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
	
	for(int i=0 ; i<number ; i++){
		printf("%d " , heap[i]);
	}
	
	
	return 0;
}

//�ð� ���⵵
//O(N * logN)
//Ʈ���� ���� * heapify
//���� �ð� ���⵵�� 1/2N * logN
//1/2�� ���� ���� ������ O(N * logN)
