#include <stdio.h>
#include <math.h>

//�Ҽ� ���ϴ� �˰��� 
//�ð����⵵ O(N^1/2) 
bool isPrimeNum(int x){
	int end = (int)sqrt(x); //Ư�� ������ �����ٱ����� ���  ��x(��Ʈ x) 
	for(int i=2 ; i<=end ; i++){
		if(x%i == 0){
			return false;
		}
	}
	return true;
} 
int main(void){
	printf("%d",isPrimeNum(97));
	return 0;
}


//�ð����⵵ 
//O(N^1/2)
//���� ���� ��츦 ���� 
