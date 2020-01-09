//���� 2188 
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int cowToRoom[MAX];
bool selected[MAX];

bool bMatching(int x){
	
	for(int i=0 ; i<a[x].size() ; i++){
		int t = a[x][i]; //x�Ұ� ���ϴ� ��� 
		
		if(selected[t]) continue; //��Ϳ��� ���� ���� Ȯ��
		//�����ϰ� 
		selected[t] = true;
		
		//�� ���� ������ �Ұ� ���ų� || �ٸ� �Ұ� �̹� ���������� �纸���� �� �ִٸ� 
		if(cowToRoom[t] == 0 || bMatching(cowToRoom[t])){ 
			cowToRoom[t] = x;
			return true;
		}
	}
	return false;
	
}

int main(void){
	
	int cowNum, roomNum;
	scanf("%d%d",&cowNum, &roomNum);
	
	for(int i=1 ; i<=cowNum ; i++){
		int x;
		scanf("%d", &x);
		for(int j=0 ; j<x ; j++){
			int y;
			scanf("%d", &y);
			a[i].push_back(y);
		}
	}
	
	int count;
	for(int i=1 ; i<=cowNum ; i++){
		fill(selected, selected+MAX, false);
		if(bMatching(i)) count++;
	}
	printf("%d", count);
	
	return 0;
}

