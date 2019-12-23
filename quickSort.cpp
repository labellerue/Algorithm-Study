#include <stdio.h>

int number = 10;
int data[10] = {5,8,7,6,10,1,4,3,2,9};

void quickSort(int *data, int start, int end){
	if(start >= end){//���Ұ� 1���� ��� 
		return; 
	}
	
	int key = start; //Ű�� ù��° ����(�ǹ� ��)
	int i = start + 1; //���� ������� (index)
	int j = end; //������ ������� (index)
	int temp;
	
	while(i <= j) {//�������� ���� ���� -�������� Ż��  
		 while(data[i] <= data[key] ){ //Ű ������ ū ���� ���� �� ���� 
//��������while(data[i] >= data[key] ){ 
		 	i++;
		 }
		 while(data[j] >= data[key] && j>start ) {//Ű ������ ���� ���� ���� �� ����  
//��������while(data[j] <= data[key] ) {
		 	j--;
		 }
		 if(i > j){//���� ������ ���¸� Ű ���� ��ü
		 	temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		 }else{ // �������� �ʾ����� �ΰ� ���� ��ü  
		 	temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		 }
	}
	//����� �Լ�  
	quickSort(data, start, j-1); //���� ������ �ǹ��� ������ ���� 
	quickSort(data, j+1, end); //���� ������ �ǹ��� �������� ���� 
}
int main(void){
	//�� ���� :  Ư���� ���� �������� ū ���ڿ� ���� ���ڸ� ���� ��ȯ�� �ڿ� �迭�� ������ ����.
	//�ǹ�(Pivot) ���ذ����� ���� 
	//����) 3/4 5 2 1  ..3�� �������� ���ʿ������� ū ��, �����ʿ������� ���� ���� ã�� ���� �ٲ��� 
	//		3/1 5 2 4  ..�ٽ� 3 ���� 
	//		3/1 2 5 4  ..�̶��� 3 ��������  ū���� ���� ���� ũ�ν� �Ǳ� ������ 3�� ���� ���� �ٲ��� 
	//		2/1 3 5 4  ..���� Pivot�� 2
	//		1/2 3 5 4 
	//		1/2 3 5 4 
	//		1 2 3 5/4  ..���� 5�� ������ ��. 
	quickSort(data, 0, number-1);
	for(int i=0; i<number ; i++){
		printf("%d ", data[i]);
	}
	
	return 0;
}

//��ռӵ�
//O(N*logN) 
//1 2 3 4 5  / 6 7 8 9 10  -> N/2 * N/2 + N/2 * N/2 = 5*5 + 5*5 = 50
//�ٸ� sort�� ��� 1 2 3 4.. ->  N*N = 10*10 = 100

