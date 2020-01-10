//���� 2150 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX]; //������ ��ȣ �ο�
bool finished[MAX]; //ó���� ���
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

//�׻� ó�� �湮�ϴ� ��常 ���� : N�� ���� 
int dfs(int x){
	d[x] = ++id; //���� ��ȣ ����
	s.push(x);
	
	int result = d[x]; //������ȣ
	for(int i=0 ; i< a[x].size() ; i++){
		int t = a[x][i];
		
		if(d[t] == 0) result = min(result, dfs(t)); //�湮���� ���� �̿� ����� ���
		else if(!finished[t]) result = min(result,d[t]); //�湮�� ������ ���� ó������ �̿� ��� 
	} 
////////////////////�ӢӢӢӢӢӢ��ٽɢӢӢӢӢӢ�////////////////////////////

	//�θ� ��尡 �ڱ� �ڽ��� ��� SCC ����
	if(result == d[x]){
		vector<int> scc;
		while(1){
			int y = s.top();
			s.pop();
			scc.push_back(y);
			finished[y] = true;
			if(y == x) break; //�ڱ� �ڽ��� ���ö����� �ݺ��� ���� 
		}
		sort(scc.begin(), scc.end()); //�������� ������������ ����϶�� �� 
		SCC.push_back(scc);
	} 
	//�ڽ��� �θ� ���� ��ȯ
	return result; 
} 

int main(void){
	int v,e;
	scanf("%d %d", &v, &e);
	for(int i=0 ; i<e ; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
	}
	for(int i=1 ; i<=v ; i++){
		if(d[i] == 0) dfs(i);
	}
	printf("%d\n", SCC.size());
	sort(SCC.begin(), SCC.end());
	for(int i=0 ; i<SCC.size() ; i++){
		for(int j=0 ; j<SCC[i].size() ; j++){
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}
