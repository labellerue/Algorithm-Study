#include<iostream>
using namespace std;

//Greedy �˰���
//���� �� �տ� ���̴� ������ ��Ȳ���� �i�� �˰���
//���� �ܼ��� ���� 
//�׻� ������ �ƴ����� ��� ������ ������ �ٻ��� 
//������ ũ�ų�, �۰ų�, ��ų�, ª�� ������� ������ �� ���� 
//ex) �Ž��� �� ���� : ������ ���� ū ȭ�� �������� �Ž��� �ش� 

int main(void){
	
	int money = 2000 , price =740;
	int change;
	int result = 0;
	change = money - price;
	
	result += change/500;
	change = change%500;
	result += change/100;
	change = change%100;
	result += change/50;
	change = change%50;
	result += change/10;
	
	cout << "�� �� : " << money << '\n';
	cout << "�Ž��� �� : "<< change << '\n';
	cout <<  "���� ���� : " << result;
	
	return 0;
}
 
