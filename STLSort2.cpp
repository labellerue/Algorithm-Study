#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
			pair<string, pair<int, int> > b){
	// ������ ���ٸ� ���̰� �� � ģ���� ������ ������ ���� 
	if(a.second.first == b.second.first){
		return a.second.second > b.second.second;
	}else {
		return a.second.first > b.second.first;
	}
}

//Ŭ������ ������� �ʰ� �����ϱ�. 
int main(void){
	vector<pair<string,pair<int,int> > > v;
	
	v.push_back(pair<string,pair<int,int> >("�̼���", pair<int,int>(90,19931231)));
	v.push_back(pair<string,pair<int,int> >("�̼ҳ�", pair<int,int>(70,19920130)));
	v.push_back(pair<string,pair<int,int> >("�̼Ҷ�", pair<int,int>(90,19930621)));
	v.push_back(pair<string,pair<int,int> >("�̼Ұ�", pair<int,int>(80,19961105)));
	v.push_back(pair<string,pair<int,int> >("�̼Ҵ�", pair<int,int>(60,19940819)));
	
	sort(v.begin(), v.end(), compare);
	for(int i=0 ; i<v.size(); i++){
		cout << v[i].first << ' ';
	}
	
	return 0;
}
