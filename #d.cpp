#include <iostream>
#include <cstring>
using namespace std;

int count=1;

class Person
{
	char name[20];
	int age;
	
	public:
		Person(char *_name, int _age)
		{
			strcpy(name, _name);
			age=_age;
			cout << count << "th object" << endl;
			count++;
			showData();
		}
		void showData()
		{
			cout << " name : " << name;
			cout << ", age : " << age << endl;
		}
};


int main()
{
	Person p1("Lim", 28);
	Person p2("Taek", 36);
}
