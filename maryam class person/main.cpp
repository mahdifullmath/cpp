#include <iostream>

using namespace std;
class Person{
private:
	char name[30];
	int age;
	char gender;


public:
	void getdata(int a){
		cout << "input name: ";
		cin >> name;
		cout << "input age: ";
		cin >> age;
        cout << "input gender \t(F or M): ";
        cin >> gender;
	}
	void display(int a){
		cout << "\nname: "<< name;
		cout << "\nage: "<< age;
		cout << "\ngender: "<< gender;
	}


};

class employee :public Person{
private:
	char company_name[30];
	int Salary;
public:
    Person::getdata;
	Person::display;
	void getdata(){
	    getdata(1);
		cout << "input Company Name: ";
		cin >> company_name;
		cout << "input Salary: ";
		cin >> Salary;
	}
	void display(){
	    display(1);
		cout << "\nCompany Name: "<< company_name;
		cout << "\nSalary: "<< Salary;
	}

};
int main(){
	employee o;

	o.getdata();
	o.display();

	return 0;
}
