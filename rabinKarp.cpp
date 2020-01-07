#include <iostream>
using namespace std;

//Rabin Karp 알고리즘 
//문자열 매칭 알고리즘
//항상 빠르지는 않지만 일반적인 경우 빠르게 작동하는 간단한 구조의 문자 매칭 알고리즘
//해시 기법 사용 
//계산 방법 : 
//문자를 ASCII 코드로 변환해 자릿수의 제곱을 곱한다.
//ex) aba => 97*2^2 + 98*2^1 + 97*2^0 = 1069
//	  abb => 97*2^2 + 98*2^1 + 98*2^0 = 1068
//긴 글과 부분 문자열의 해시 값이 일치하는 경우에만 문자열을 재검사 하여 정확히 일치하는지 확인하는 알고리즘
//즉, 한 문자씩 옆으로 옮겨 해시값 계산. 일치할 시 문자열 재검사
//계산이 빠른 이유 :
//옆으로 옮겼을 때 다시 계산하는 것이 아니라, 가장 앞 값을 빼고 *2수행 후 새롭게 들어온 문자를 더한다.
//공식 = 2*(긴 글 해시 값 - 가장 앞 문자의 수치) + 새롭게 들어온 문자의 수치 

void findString(string parent, string pattern){
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0 , patternHash = 0 , power =1; //power는 제곱수 
	for(int i=0 ; i<=parentSize-patternSize ; i++){
		//먼저 첫 해시 값 구해놓기
		if(i == 0){
			for(int j=0 ; j<patternSize ; j++){
				parentHash += parent[patternSize-1-j]*power;
				patternHash += pattern[patternSize-1-j]*power;
				if(j<patternSize-1) power *= 2;
			 }
		//긴 글의 가장 앞 문자를 빼고 새로운 문자를 더하는 공식 실행 
		}else{
			if(parentHash != patternHash){
				parentHash = 2 * (parentHash - parent[i-1]*power) + parent[i+patternSize-1];
			}
		} 
		//해시값이 같으니 문자열 재검사 
		if(parentHash == patternHash){
			bool flag = true; //break로 if문을 빠져나올 수 없어 flag가 필요 
			for(int j=0 ; j<patternSize ; j++){
				if(parent[i+j] != pattern[j]){
					flag = false;
					break;
				}
			}
			if(flag) printf("%d번째에서 찾았습니다\n", i+1);
		}
	}
}

int main(void){
	string parent = "ababacabacaabacaaba"; 
	string pattern = "abacaaba";
	findString(parent, pattern);
	
	return 0;
}

//overflow가 발생해도 해시값이 동일함 -> 음/양을 알아서 왔다갔다 하기 때문에 컴퓨터 연산에 문제가 없음 
//더 정확하게 해시값을 검증해주고 싷다면 나머지 연산(MOD)를 이용 
//연산 속도
//O(1) 
