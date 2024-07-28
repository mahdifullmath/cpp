#include <iostream>
#include <cstring>
using namespace std;

struct Person
{
	string name;
	string family;
	float id_number;
	int age;

};
class Student
{
private:
    Person P1;
	int student_number;

public:


	void daryaft()
	{
		cout << "name: " << endl;
		cin >> P1.name;
		cout << "family: " << endl;
		cin >> P1.family;
		cout << "idnum: " << endl;
		cin >> P1.id_number;
		cout << "age: " << endl;
		cin >> P1.age;
	}
	void display()
	{
		cout << "name: " << P1.name << endl << "family: " << P1.family << endl << "id number: " << P1.id_number << endl << "age: " << P1.age << endl;
	}

	void Sort(Student slist[],int s)
	{
		Student temp;
		int Q = 0;
		for (int i = 0; i < s + 1; i++)
		{
			for (int j = 0; j < s - 1; j++)
			{
				if (slist[j].P1.family[Q] > slist[j + 1].P1.family[Q])
				{
					temp = slist[j];
					slist[j] = slist[j + 1];
					slist[j + 1] = temp;
					Q = 0;
					continue;
				}
				if (slist[j].P1.family[Q] == slist[j + 1].P1.family[Q])
				{
					Q++;
					j--;
				}
				else
				{
					Q = 0;
				}
			}
		}
	}

 Student()
	{
	}
 Student(Person a, int b)
	{
	b = student_number;
	}
	~Student()
	{

	}
	void Sort(Student a1[],int t,Student a2[],int t2,Student x[]){
    for (int i=0;i<t;i++){
        x[i]=a1[i];
	}
	for (int i=0;i<t2;i++){
        x[i+t]=a2[i];
	}
    for (int i=0; i<t+t2;i++){
  	   for (int i=0; i<t+t2-1;i++){
		 if (x.student_number[i]>x.student_number[i+1])
	 	{
			swap (x[i],x[i+1]);
		 }
  	  }
	  }
	}


};

int main()
{
		Person a1[5];
	for (int i = 0; i <= 5; i++)
	{
		cin >>  a1[i+1].name;
	}
	Student aa[5];
	Student bb[5];
	for (int i = 0; i < 5; i++)
	{
		aa[i].P1.name = a1[i].name;
}
	for (int i = 0; i < 4; i++)
	{
		bb[i].P1.name;
}

	return 0;
}
