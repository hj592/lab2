#include <iostream>
#include <map>
#include <numeric>
#include <iterator>

using namespace std;

typedef struct{
	char name[20];
	int mid;
	int end;
} STUDENT;

int main(){
	map<int,STUDENT> students;
	int sNum = 0;
	
	cout << "num : ";
	cin >> sNum;
	
	for (int i = 0; i<sNum ; i++){
		STUDENT student;
		cout << "name, mid, end : ";
		cin >> student.name>>student.mid>>student.end;
		
		students.emplace(i, student);
		cout << "+"<<student.name << endl;
	}
	
	for(auto i = begin(students); i != end(students); i++){
		cout << i->second.name << "\t"<< i->second.mid << "\t"<< i->second.end << endl;
	}
	return 0;
}
