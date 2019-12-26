#include <stdio.h>

//���ͽ�Ʈ�� �˰�����
//���̳��� / �׸��� �˰�����  
//�ִܰ�� Ž�� �˰�����
//ex) �ΰ����� GPS���� ���� ���� ���� 
//��� :
//1. ��� ��� ����
//2. ��� ��带 �������� �ٸ� ���� ���� ���� ��� ����
//3. �湮���� ���� ��� �߿��� ���� ����� ���� ��� ����
//4. �� ��带 ���ļ� Ư�� ���� ���� ��츦 ���� �ּ� ��� ����
//  (1-3���� 1-2-3���� ���°� �� �����ϸ� ��� ���� 
//3���� 4�� �ݺ� 

//2���� �迭 �̿� 
//0. 0�� �迭 
//��� ��带 1�� ���� 
//�ڱ� �ڽſ��� ���� ����� 0 -> 0,0�� 0
//1���� 2�� ���µ� ��� ����� 2 -> 0,1�� 2 
//1���� 3���� ���µ� ��� ����� 5 -> 0,2�� 5
//1. 1�� �迭 
//��� ��带 2�� ���� 
//�ڱ� �ڽſ��� ���� ����� 0 -> 1,1�� 0
//2���� 3���� ���µ� ��� ����� 3 -> 1,2�� 3 
//...
//�������� ������ ���� ���� �������� ���� 

//�� ���� ���� �۾� 
//�ٸ� ��带 ���ļ� ��� ����� ���� �� ���� ������ ������ ���� 

int number = 6;
int INF = 1000000000; //int�� �ִ밪 

//��ü �׷��� �ʱ�ȭ
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool visited[6]; //�湮 ���� Ȯ�� : �� 6�� (��� ��� 1���� �� �湮 �ߴ°�) 
int distance[6]; //�ּ� �Ÿ� 1 ���µ� �ּ�, 2 ���µ� �ּ�.. : �� 6�� 

//�ּ� �Ÿ��� ������ �� ��ȯ 
int getSmallDistance(){
	int min = INF;
	int index = 0;
	for(int i=0 ; i<number ; i++){
		if(!visited[i] && distance[i] < min){ //�湮 ���� �� �߿� �� ���� �� �߰� �� 
			min = distance[i];
			index = i;
		} 
	}
	return index;
}

//���ͽ�Ʈ�� ���� �Լ� 
void dijkstra(int startPoint){ //���� �� ���� 
	for(int i=0 ; i< number ; i++){
		distance[i] = a[startPoint][i]; 
		//�ϴ� �׷����� �ʱⰪ�� �ּ� �Ÿ����� �ȴ�. 
		//���� �� ���� �� �߰��ϸ� �ٲܰž� 
	}
	visited[startPoint] = true; //�湮������ �湮 ó�� 
	for(int i=0 ; i< number -2 ; i++){
		int current = getSmallDistance(); //start�࿡�� ���� ���� ��� �������� 
		visited[current] = true;
		
		//���� ���� ����� ��(=current��)�� �Ѿ�� ���� distance���� �� 
		for(int j=0 ; j<6 ; j++){
			if(!visited[j]){ //�湮 ���� �� �߿� (�̹� �湮�� ������ �ּҰ� �� ã�Ƴ�����) 
				if(distance[current] + a[current][j] < distance[j]){ 
					//�ѹ濡 ���� �ͺ��� �ǳʰ��°� �� �����ϴٸ�
					distance[j] = distance[current] + a[current][j]; 
				} 
			}
		}
	}
	
}

int main(void){
	dijkstra(0);//0���� ����ؼ� ���� 1,2,3,4,5�� �����ϴ� �ִܰŸ�? 
	for(int i=0 ; i<number ; i++){
		printf("%d ", distance[i]);
	}
	return 0;
} 


//����Ž�� �̿�
//�ð����⵵
//O(N^2) 
//�����ɸ�.. 
//getSmallDistance()�� ������ �ʿ���. 







