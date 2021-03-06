#include <iostream>
#include <algorithm>

using namespace std;

class Student{
	public:
		string name;
		int score;
		Student(string name, int score){
			this -> name = name;
			this -> score = score;
		}
		//정렬 기준은 '점수가 작은 순서'
		bool operator<(Student &student){
			return this-> score < student.score;
		} 
}; 

bool compare(int a, int b){
	//오름차순 정렬 
	return a<b;
	//내림차순 정렬
	//return a>b; 
}

int main(void){
	
	Student students[] = {
		Student("이소형",90),
		Student("은하영",78),
		Student("엄희수",87),
		Student("강효정",56)
	};
	sort(students, students+4);
	for(int i=0 ; i<4 ; i++){
		cout << students[i].name << ' ';
	}
	
	int a[10] = {9,3,5,4,1,10,8,6,7,2};
	sort(a,a+10,compare);//a배열의 10개를 정렬하라 (메모리 주소로 이해함) , compare: 정렬 방법 기본 오름차순 
	for(int i=0 ; i<10 ; i++){
		cout << a[i] << ' ';
	}
} 
