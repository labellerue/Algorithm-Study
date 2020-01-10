//���� 4196 
#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX]; //������ ��ȣ �ο�
bool finished[MAX]; //ó���� ���
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX]; //����� ���鳢�� �׷��� ���� ��ȣ �ű�� 
bool inDegree[MAX]; 

//�׻� ó�� �湮�ϴ� ��常 ���� : N�� ���� 
int dfs(int x){
	d[x] = ++id; //���� ��ȣ ����
	s.push(x);
	
	int parent = d[x]; //������ȣ
	for(int i=0 ; i< a[x].size() ; i++){
		int t = a[x][i];
		
		if(d[t] == 0) parent = min(parent, dfs(t)); //�湮���� ���� �̿� ����� ���
		else if(!finished[t]) parent = min(parent,d[t]); //�湮�� ������ ���� ó������ �̿� ��� 
	} 
////////////////////�ӢӢӢӢӢӢ��ٽɢӢӢӢӢӢ�////////////////////////////

	//�θ� ��尡 �ڱ� �ڽ��� ��� SCC ����
	if(parent == d[x]){
		vector<int> scc;
		while(1){
			int y = s.top();
			s.pop();
			scc.push_back(y);
			group[y] = SCC.size() +1; //���� ��ȯ���� �׷�� �����ֱ� 
			finished[y] = true;
			if(y == x) break; //�ڱ� �ڽ��� ���ö����� �ݺ��� ���� 
		}
		SCC.push_back(scc);
	} 
	//�ڽ��� �θ� ���� ��ȯ
	return parent; 
} 

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		SCC.clear();
		fill(d, d+MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		
		scanf("%d %d", &n, &m);
		for(int i=1 ; i<=n ; i++){
			a[i].clear();
		}
		for(int i=0 ; i<m ; i++){
			int x, y;
			scanf("%d %d", &x,&y);
			a[x].push_back(y);
		}
		
		for(int i=1 ; i<= n ; i++){
			if(d[i] ==0) dfs(i);
		}
		//����� ���� ���̳밡 �Ѿ����� �ڵ����� �Ѿ����Ƿ� true������ .. 
		for(int i=1 ; i<=n ; i++){
			for(int j=0; j<a[i].size() ; j++){
				int y= a[i][j];
				if(group[i] != group[y]) inDegree[group[y]] = true;
			}
		}
		int result = 0;
		for(int i=1 ; i<= SCC.size() ; i++){
			if(!inDegree[i]) result++;
		}
		printf("%d", result);
	}
	
	return 0;
}
