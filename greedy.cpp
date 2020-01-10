#include<iostream>
using namespace std;

//Greedy 알고리즘
//당장 눈 앞에 보이는 최적의 상황만을 쫒는 알고리즘
//가장 단순한 형태 
//항상 최적은 아니지만 어느 정도의 최적에 근사함 
//무조건 크거나, 작거나, 길거나, 짧은 순서대로 접근할 시 유용 
//ex) 거스름 돈 문제 : 무조건 제일 큰 화폐 단위부터 거슬러 준다 

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
	
	cout << "낸 돈 : " << money << '\n';
	cout << "거스름 돈 : "<< change << '\n';
	cout <<  "동전 개수 : " << result;
	
	return 0;
}
 
