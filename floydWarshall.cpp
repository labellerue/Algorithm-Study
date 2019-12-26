#include <stdio.h>

//��� ������ ��� �������� �ִ� ��� ���ϱ� 
//���İ��� ���� �������� �˰��� ���� 
//��, 2-3�� 2-1�� ���ٰ� 1-3���� ���ư� ���� �� 
//�̰͵� �ٷ� �� �� ���� ��츦 �������� �α� ������
//2-3�� 9, 2-1�� 7, 1-3�� �Ұ���:���� �� �� -> 9 vs 7+�������� ����Ͽ�
//2-3�� �� �����ϴٰ� ��
//�̷��� ��� 1�� ��ġ�� ���
//		 ��� 2�� ��ġ�� ���
//		 ...�ڱ� �ڽ��� ���� 


int number = 4;
int INF = 1000000000;

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall(){
	//��� �׷��� �ʱ�ȭ
	int dist[number][number];
	
	for(int i=0 ; i<number ; i++){
		for(int j=0 ; j<number ; j++){
			dist[i][j] = a[i][j];
		}
	}
	//��ġ�� ��带 �������� �۾��ϱ�  
	//k -> ���İ��� ���
	for(int k=0 ; k<number ; k++){
		//i -> ���  ��� 
		for(int i=0 ; i<number ; i++){
			//j -> ���� ��� 
			for(int j=0 ; j<number ; j++){
				if(dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	} 
	for(int i=0 ; i<number ; i++){
		for(int j=0 ; j<number ; j++){
			printf("%3d ", dist[i][j]);
		}
		printf("\n");
		
	}
}


int main(void){
	
	floydWarshall();
	return 0;
} 


//�ð� ���⵵
//O(N^3)
//���� for�� �̿� 

 
