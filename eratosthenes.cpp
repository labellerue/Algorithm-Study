#include <stdio.h>

//�����佺�׳׽��� ü 
//�Ҽ��� ������ �Ǻ��ϴ� �˰��� 
//��� : 
//1. �� ��ŭ �迭�� �Ҵ�
//2. 2�� ����� 2�� �����ϰ� ��� �����(0���� ��ü) 
//3. 3�� ����� 3�� �����ϰ� ��� �����(0���� ��ü) 
//4. 4�� �������� ������ ����(�̹� 0���� �ٲ�) 
//...
//5. 2���� ������ �����ִ� ���ڵ��� ��� 

//int size = 100000;
//int num[100001];

void isPrimeNumSieve(int x){
	int size = x;
	int num[x+1];

	//1�� �۾� : �� ��ŭ �迭�� �Ҵ� 
	for(int i=2 ; i<=size ; i++){
		num[i] = i;
	}
	
	for(int i=2 ; i<=size ; i++){
		//4�� �۾� : �̹� ���� ���� ��� 
		if(num[i] == 0) continue;
		
		//2,3�� �۾� : i�� ����� �͵��� ��� ���� 
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


