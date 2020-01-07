#include <iostream>
#include <vector>

using namespace std;

//KMP Knuth-Morris-Pratt �˰���
//���λ�� ���̻縦 ���Ͽ�  

//i : 1���� ����, ��������� ����
//j : i�� ���ڰ� ��ġ�� ��� ����, ��ġ���� ���� ��� 0���� �ٽ� ����
//��ġ ��
//1. table[i]�� ���� j+1 => j��� ���� i�� ��ġ�� ������ �ǹ�(�迭�� 0���� �����̱� ������ +1�� �ϴ� ��) 
//2. i++, j++
//3. ��ġ���� ������ ���� �ݺ�
//4. ��ġ���� ������ j = 0; (j�� ����)


vector<int> makeTable(string pattern){
	vector<int> table(pattern.size(), 0);
	int j=0;
	for(int i=1 ; i<pattern.size() ; i++){
		//i�� j��° ���ڰ� ��ġ���� ���� ��� 
		while(j>0 && pattern[i] != pattern[j]){
			j=table[j-1];
//			j = 0; �� �ϸ� �ȵǳ�??? 
		}
		//i�� j��° ���ڰ� ��ġ�� ��� 
		if(pattern[i] == pattern[j]){
			table[i] = ++j; //j�� ����. i��°�� j+1 �Է� 
		}
	}
	return table;
} 

//��ġ���� �ʰ� �Ǿ��� �� 
//��ġ �ߴ� ��ŭ�� j�� prefix��
//����� i ������ suffix�� ���� ��ġ�ϴ� i�� �迭���� �ٽ� ��
//prefix�� suffix ������ ����ġ�ϴ� �κ��� �ǳ� �ٴ� �� 
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
			if(j == patternSize-1){ //j�� ������ �ٳ���� �� 
				//��ġ�� ���� i���� ���ڿ����̸� ���� 2�� �����ָ� ���� ���� ��ġ�� ���� 
				printf("%d��°���� ã�ҽ��ϴ�.\n", i-patternSize +2);
				j = table[j]; //prefix�� suffix ���� �ǳʶٱ� 
			}else{
				j++; //�� ��Ī �Ǵ°� �ִ��� Ȯ�� 
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

//�ð����⵵ 
//O(N+M)
