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
		//���� ������ '������ ���� ����'
		bool operator<(Student &student){
			return this-> score < student.score;
		} 
}; 

bool compare(int a, int b){
	//�������� ���� 
	return a<b;
	//�������� ����
	//return a>b; 
}

int main(void){
	
	Student students[] = {
		Student("�̼���",90),
		Student("���Ͽ�",78),
		Student("�����",87),
		Student("��ȿ��",56)
	};
	sort(students, students+4);
	for(int i=0 ; i<4 ; i++){
		cout << students[i].name << ' ';
	}
	
	int a[10] = {9,3,5,4,1,10,8,6,7,2};
	sort(a,a+10,compare);//a�迭�� 10���� �����϶� (�޸� �ּҷ� ������) , compare: ���� ��� �⺻ �������� 
	for(int i=0 ; i<10 ; i++){
		cout << a[i] << ' ';
	}
} 
