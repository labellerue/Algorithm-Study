#include <iostream>

using namespace std;

//KMP Knuth-Morris-Pratt �˰���
//�������̰� �ܼ� ���ڿ� ��Ī �˰��� 

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
		printf("%d��° ���� ã�ҽ��ϴ�.", result+1);
	}else{
		printf("ã�� �� �����ϴ�"); 
	}
	
	return 0;
}

//�ð����⵵ 
//O(N*M)
