#include <iostream>
#include <vector>
#include <queue> //�켱���� ť �̿� = heap�� ���� �۵� ��� 

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int> > a[7]; //���� ���� 
int dist[7]; //�ּ� ��� 
  
void dijkstra(int start){
	dist[start] = 0; //�ڱ� �ڽ����� ���� ����� 0 
	priority_queue<pair<int, int> > pq; //�� ���� �������� 
	pq.push(make_pair(start,0));
	//����� ������� ó���ϹǷ� ť�� ���
	while(!pq.empty()){
		int current = pq.top().first;
		
		int d = -pq.top().second; //���� ���� ���� ���� ������ ����ȭ(-)
		pq.pop();
		
		//���� ������ ũ�� �Ѿ��
		if(dist[current] < d) continue;
		for(int i=0 ; i<a[current].size() ; i++){
			
			int next = a[current][i].first; //���õ� ����� �� ģ����
			int nextDistance = d + a[current][i].second; //next���� ���ư��� ���
			
			if(nextDistance < dist[next]) { //���� ���� ���ư��� ��� ��
				dist[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		} 
	} 
}
  
int main(void){
	
	//��� �𸣴°����� �ʱ�ȭ, 0�� ���� ��� ���� 
	for(int i=1 ; i<number+1 ; i++){
		dist[i] = INF;
	} 
	
	a[1].push_back(make_pair(2,2));
	a[1].push_back(make_pair(3,5));
	a[1].push_back(make_pair(4,1));
	
	a[2].push_back(make_pair(1,2));
	a[2].push_back(make_pair(3,3));
	a[2].push_back(make_pair(4,2));
	
	a[3].push_back(make_pair(1,5));
	a[3].push_back(make_pair(2,3));
	a[3].push_back(make_pair(4,3));
	a[3].push_back(make_pair(5,1));
	a[3].push_back(make_pair(6,5));
	
	a[4].push_back(make_pair(1,1));
	a[4].push_back(make_pair(2,2));
	a[4].push_back(make_pair(3,3));
	a[4].push_back(make_pair(5,1));
	
	a[5].push_back(make_pair(3,1));
	a[5].push_back(make_pair(4,1));
	a[5].push_back(make_pair(6,2));
	
	a[6].push_back(make_pair(3,5));
	a[6].push_back(make_pair(5,2));
	
	dijkstra(1);
	
	for(int i=1 ; i<number+1 ; i++){
		printf("%d ", dist[i]);
	}
	
	return 0;
}
