#include <iostream>

using namespace std;

//KMP Knuth-Morris-Pratt 알고리즘
//↓↓↓↓↓이건 단순 문자열 매칭 알고리즘 

int findString(string parent, string pattern){
	int parentSize = parent.size();
	int patternSize = pattern.size();
	for(int i=0 ; i<=parentSize-patternSize ; i++){
		bool finded = true;
		for(int j=0 ; j<patternSize ; j++){
			if(parent[i+j] != pattern[j]){
				finded = false;
				break;
			}
		}
		if(finded){
			return i;
		}
	}
	return -1;
}

int main(void){
	
	string parent = "Hello World";
	string pattern = "oo";
	int result = findString(parent, pattern);
	if(result != -1){
		printf("%d번째 에서 찾았습니다.", result+1);
	}else{
		printf("찾을 수 없습니다"); 
	}
	
	return 0;
}

//시간복잡도 
//O(N*M)
