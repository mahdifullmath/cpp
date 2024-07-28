#include <iostream>
using namespace std;
class Person
{
protected:
	char name[100];
	char family[100];
	char melliat[100];
	int age;
	int melli_num;
public:
	virtual void show_val()
	{
	}
	virtual void get_val() = 0;



	Person()
	{

	}
	Person(char namee[100],char familyy[100],char melliatt[100],int age,int melli_numm)
	{

	}
	Person(char namee[100],char familyy[100])
	{

	}
};
class Employee : public Person {
protected:
	int* salary;
public:
	Employee() {
		salary = new int;
	}
	Employee(int s) {
		salary = new int;
		*salary = s;
	}
	void operator +=(int a) {
		*salary = *salary + a;
	}
	void operator -=(int a) {
		*salary = *salary - a;
	}
	~Employee()
	{
		cout << this << "is free!";
	}
};

class programmer :public Employee
{
private:
	static int i;
public:
	void set_salary(int a);

	programmer()
	{

	}
	programmer()
	{

	}
	programmer(const programmer &a)
	{

	}
	~programmer()
	{
		cout << this << "is free!";
	}


};
void programmer::set_salary(int a)
{

}
int programmer::i = i + 1;
class manager :public Employee
{
	friend class programmer;
	void showsal() {
		cout << name << " " << family << endl;
		cout << *salary;
	}

	manager()
	{

		Employee(8000000);
	}
	~manager()
	{
		cout << this << "is free!!";
	}
};

int main()
{
	const manager m();
	Employee a[10];
	programmer* b;
	b = new programmer[5];

	delete b;
	manager x;
	programmer y;
	Person* z;
	z = &x;
	z->show_val();
	z = &y;
	z->show_val();

	return 0;
}
