//���� 11377
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int manager[MAX];
bool selected[MAX];

bool bMatching(int x){
	
	for(int i=0 ; i<a[x].size() ; i++){
		int t = a[x][i];
		
		if(selected[t]) continue;
		selected[t] = true;
		
		if(manager[t] == 0 || bMatching(manager[t])){ 
			manager[t] = x;
			return true;
		}
	}
	return false;
	
}

int main(void){
	
	int emp, work, k;
	scanf("%d %d %d",&emp, &work, &k);
	
	for(int i=1 ; i<=emp ; i++){
		int x;
		scanf("%d", &x);
		for(int j=0 ; j<x ; j++){
			int y;
			scanf("%d", &y);
			a[i].push_back(y);
		}
	}
	
	int count=0;
	for(int i=1 ; i<=emp ; i++){
		fill(selected, selected+MAX, false);
		if(bMatching(i)) count++;
	}
	//�ѹ� �� ���� �߰� �۾��� ã�� : �Ŵ����� �̹� ���������� �װ� ���ؼ� �۾��� ����� ���ٰž� 
	for(int i=1 ; i<=emp ; i++){
		fill(selected, selected+MAX, false);
		if(bMatching(i)){
			count++;
			k--; 
		}
		if(k==0) break;
	}
	
	printf("%d", count);
	
	return 0;
}

