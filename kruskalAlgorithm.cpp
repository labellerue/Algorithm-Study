#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
//�ּ� ��� ���� Ʈ�� 
// ->���� ���� ������� ��� ��带 ����
//ex)�� ���ø� ���η� �����ϰ� �� �� ����� �ּ������� �ϰ��� �� �� ����Ǵ� �˰���
//�ּ� ������ ���� : ��� - 1
//����
//���� ������ ������������ ������ �ڿ� ����� ���� �������� �׷����� ����
//����!! ����Ŭ�� �������� �ʵ��� �Ѵ�. 
//1. ���ĵ� ������ �¿� �׷����� ����
//2. ���Խ�Ű�� ���� ����Ʋ ���̺� Ȯ��
//3. ����Ŭ�� �����ϴ� ��� ������ �������� ���� 

//Union-find�� ����Ŭ Ȯ�� 
int getParent(int parent[], int x){
	if(parent[x] == x) return x; //�ش� ��尡 �θ� ����ΰ� 
	return parent[x] = getParent(parent, parent[x]); //�θ� ����� ���� ã�������� ����(��� �ѹ��̸� ��) 
}
void unionParent(int parent[], int a, int b){ //�θ� ��带 �ϳ��� ����! 
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a<b){
		parent[b] = a;
	}else{
		parent[a] = b;
	}
}
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a==b){
		return 1;
	}else{
		return 0;
	}
}

//���� Ŭ���� ����
class Edge {
	public:
		int node[2];
		int distance; //������ ��� 
		Edge(int a, int b, int distance){
			this ->node[0] = a;
			this ->node[1] = b;
			this ->distance = distance;
		}
		//���� ���� : ������ ����� ���� ���� ���� ��� 
		bool operator < (Edge &edge){
			return this ->distance < edge.distance;
		}
		
		
		
};

int main(void){
	
	int n = 7; //�� ���� 
	int m = 11; //���� ����
	
	vector<Edge> v;
	v.push_back(Edge(1,7,12)); //���� ���� �Է�..
	v.push_back(Edge(1,4,28));
	v.push_back(Edge(1,2,67));
	v.push_back(Edge(1,5,17));
	v.push_back(Edge(2,4,24));
	v.push_back(Edge(2,5,62));
	v.push_back(Edge(3,5,20));
	v.push_back(Edge(3,6,37));
	v.push_back(Edge(4,7,13)); 
	v.push_back(Edge(5,6,45)); 
	v.push_back(Edge(5,7,73));
	
	//������ ����� �������� �������� ����
	sort(v.begin(), v.end());
	
	//�� ������ ���Ե� �׷����� ������� ����
	int parent[n];
	for(int i=0 ; i<n ; i++){
		parent[i] = i;
	}
	
	int sum = 0; //�Ÿ��� �� 
	for(int i=0 ; i<v.size() ; i++){
		//�θ��� ������ ����Ŭ�� ������. 
		//�θ��� ���� ���� ��쿡 �ּ� �������� ����
		//parent�� 0���� ����߱� ������ -1�� ���ִ� �� 
		if(findParent(parent, v[i].node[0] - 1, v[i].node[1]-1) < 1){
			sum += v[i].distance;
			//�θ� ���� ������ ����� ����Ŭ ���� 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1]-1);
		}	
	}
	
	printf("%d\n", sum);
	
	return 0;
}









