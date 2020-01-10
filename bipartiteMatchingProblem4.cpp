//���� 1671
#include <iostream>
#include <vector>
#define NUM 51

using namespace std;

vector<int> a[NUM];
int biggerShark[NUM];
bool selected[NUM];
int stat[NUM][3];

bool bMatching(int x){
	
	for(int i=0 ; i<a[x].size() ; i++){
		int t = a[x][i];
		
		if(selected[t]) continue;
		selected[t] = true;
		
		if(biggerShark[t] ==0 || bMatching(biggerShark[t])){
			biggerShark[t] = x;
			return true;
		}
	}
	
	return false;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++){
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	
	//���� ���� ��Ƹ��� �� �ִ��� a�� �ֱ�
	//�ߺ����� �ʰ� ���
	//���� ��찡 ��ġ�� ������ ���� ��� ���ΰ� ��Ƹ��� �� �ִ� ����̱� ���� 
	for(int i=1 ; i<n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			if(stat[i][0]==stat[j][0]&&stat[i][1]==stat[j][1]&&stat[i][2]==stat[j][2]){
				a[i].push_back(j);
			}else if(stat[i][0]>=stat[j][0]&&stat[i][1]>=stat[j][1]&&stat[i][2]>=stat[j][2]){
				a[i].push_back(j);
			}else if(stat[i][0]<=stat[j][0]&&stat[i][1]<=stat[j][1]&&stat[i][2]<=stat[j][2]){
				a[j].push_back(i);
			}
		}
	} 
	
	int count=0;
	//�ִ� �θ����� ��Ƹ��� �� ���� 
	for(int j=0 ; j<2 ; j++){
		for(int i=1 ; i<=n ; i++){
			fill(selected, selected+NUM, false);
			if(bMatching(i)) count++;
		}
	}
	//��ü - ��Ƹ����� ���(��Ī ������ ���) = ��� ���� ��� 
	printf("%d",n-count);
	
	return 0; 
}
