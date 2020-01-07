#include <iostream>
using namespace std;

//Rabin Karp �˰��� 
//���ڿ� ��Ī �˰���
//�׻� �������� ������ �Ϲ����� ��� ������ �۵��ϴ� ������ ������ ���� ��Ī �˰���
//�ؽ� ��� ��� 
//��� ��� : 
//���ڸ� ASCII �ڵ�� ��ȯ�� �ڸ����� ������ ���Ѵ�.
//ex) aba => 97*2^2 + 98*2^1 + 97*2^0 = 1069
//	  abb => 97*2^2 + 98*2^1 + 98*2^0 = 1068
//�� �۰� �κ� ���ڿ��� �ؽ� ���� ��ġ�ϴ� ��쿡�� ���ڿ��� ��˻� �Ͽ� ��Ȯ�� ��ġ�ϴ��� Ȯ���ϴ� �˰���
//��, �� ���ھ� ������ �Ű� �ؽð� ���. ��ġ�� �� ���ڿ� ��˻�
//����� ���� ���� :
//������ �Ű��� �� �ٽ� ����ϴ� ���� �ƴ϶�, ���� �� ���� ���� *2���� �� ���Ӱ� ���� ���ڸ� ���Ѵ�.
//���� = 2*(�� �� �ؽ� �� - ���� �� ������ ��ġ) + ���Ӱ� ���� ������ ��ġ 

void findString(string parent, string pattern){
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0 , patternHash = 0 , power =1; //power�� ������ 
	for(int i=0 ; i<=parentSize-patternSize ; i++){
		//���� ù �ؽ� �� ���س���
		if(i == 0){
			for(int j=0 ; j<patternSize ; j++){
				parentHash += parent[patternSize-1-j]*power;
				patternHash += pattern[patternSize-1-j]*power;
				if(j<patternSize-1) power *= 2;
			 }
		//�� ���� ���� �� ���ڸ� ���� ���ο� ���ڸ� ���ϴ� ���� ���� 
		}else{
			if(parentHash != patternHash){
				parentHash = 2 * (parentHash - parent[i-1]*power) + parent[i+patternSize-1];
			}
		} 
		//�ؽð��� ������ ���ڿ� ��˻� 
		if(parentHash == patternHash){
			bool flag = true; //break�� if���� �������� �� ���� flag�� �ʿ� 
			for(int j=0 ; j<patternSize ; j++){
				if(parent[i+j] != pattern[j]){
					flag = false;
					break;
				}
			}
			if(flag) printf("%d��°���� ã�ҽ��ϴ�\n", i+1);
		}
	}
}

int main(void){
	string parent = "ababacabacaabacaaba"; 
	string pattern = "abacaaba";
	findString(parent, pattern);
	
	return 0;
}

//overflow�� �߻��ص� �ؽð��� ������ -> ��/���� �˾Ƽ� �Դٰ��� �ϱ� ������ ��ǻ�� ���꿡 ������ ���� 
//�� ��Ȯ�ϰ� �ؽð��� �������ְ� ��ٸ� ������ ����(MOD)�� �̿� 
//���� �ӵ�
//O(1) 
