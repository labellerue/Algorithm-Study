#include <iostream>
#include <vector>

using namespace std;

//KMP Knuth-Morris-Pratt 알고리즘
//접두사와 접미사를 비교하여  

//i : 1부터 시작, 계속적으로 증가
//j : i와 문자가 일치할 경우 증가, 일치하지 않을 경우 0부터 다시 시작
//일치 시
//1. table[i]의 값을 j+1 => j라는 값이 i와 일치한 갯수를 의미(배열은 0부터 시작이기 때문에 +1을 하는 것) 
//2. i++, j++
//3. 일치하지 않을때 까지 반복
//4. 일치하지 않으면 j = 0; (j의 리셋)


vector<int> makeTable(string pattern){
	vector<int> table(pattern.size(), 0);
	int j=0;
	for(int i=1 ; i<pattern.size() ; i++){
		//i와 j번째 문자가 일치하지 않을 경우 
		while(j>0 && pattern[i] != pattern[j]){
			j=table[j-1];
//			j = 0; 로 하면 안되나??? 
		}
		//i와 j번째 문자가 일치할 경우 
		if(pattern[i] == pattern[j]){
			table[i] = ++j; //j의 증가. i번째에 j+1 입력 
		}
	}
	return table;
} 

//일치하지 않게 되었을 때 
//일치 했던 만큼의 j의 prefix와
//진행된 i 까지의 suffix를 비교해 일치하는 i의 배열에서 다시 비교
//prefix와 suffix 사이의 불일치하는 부분을 건너 뛰는 것 
void KMP(string parent, string pattern){
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j=0;
	
	for(int i=0 ; i<parentSize ; i++){
		while(j>0 && parent[i] != pattern[j]){
			j= table[j-1];
		}
		if(parent[i] == pattern[j]){
			if(j == patternSize-1){ //j가 끝까지 다녀왔을 때 
				//일치의 끝인 i에서 문자열길이를 빼고 2를 더해주면 문자 시작 위치가 나옴 
				printf("%d번째에서 찾았습니다.\n", i-patternSize +2);
				j = table[j]; //prefix와 suffix 사이 건너뛰기 
			}else{
				j++; //더 매칭 되는게 있는지 확인 
			}
		}	
	}
} 

int main(void){
	string parent = "ababacabacaabacaaba"; 
	string pattern = "abacaaba";
	KMP(parent, pattern);
	
	
	return 0;
}

//시간복잡도 
//O(N+M)
