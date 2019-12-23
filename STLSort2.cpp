#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
			pair<string, pair<int, int> > b){
	// 성적이 같다면 나이가 더 어린 친구가 앞으로 가도록 정렬 
	if(a.second.first == b.second.first){
		return a.second.second > b.second.second;
	}else {
		return a.second.first > b.second.first;
	}
}

//클래스를 사용하지 않고 정렬하기. 
int main(void){
	vector<pair<string,pair<int,int> > > v;
	
	v.push_back(pair<string,pair<int,int> >("이소형", pair<int,int>(90,19931231)));
	v.push_back(pair<string,pair<int,int> >("이소나", pair<int,int>(70,19920130)));
	v.push_back(pair<string,pair<int,int> >("이소라", pair<int,int>(90,19930621)));
	v.push_back(pair<string,pair<int,int> >("이소가", pair<int,int>(80,19961105)));
	v.push_back(pair<string,pair<int,int> >("이소다", pair<int,int>(60,19940819)));
	
	sort(v.begin(), v.end(), compare);
	for(int i=0 ; i<v.size(); i++){
		cout << v[i].first << ' ';
	}
	
	return 0;
}
