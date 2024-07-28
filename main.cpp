#include <iostream>
using namespace std;

//Part1
//this struct is for the List of Lessons

struct LessonList{
char LessonName[20];
char FirstLesson[20];
int Unit;
int LessonUnit;
int LessonID;
float Grade;
bool Abcent_Present;
LessonList* Next1;
};

//Part2
//this struct is for the List of Students

struct StudentList{
char FirstName[20];
char LastName[20];
int StudentID;
LessonList* F;
StudentList* Next1;
};

//Part3
//This Function is for New Student

void NewStudent(StudentList* P){
cout << "Enter student first name : \n";
cin >> P -> FirstName;
cout << "Enter student last name : \n";
cin >> P -> LastName;
cout << "Enter student id : \n";
cin >> P -> StudentID;
cout << "\n";
 P = P -> Next1;
}

//Part4
//This Function is for Searching a new Student

void SearchingStudent(StudentList* P){
 long int id;
cout << "Enter ID of a Student :\n";
cin >> id;
while (P->Next1 != NULL){
if (P->StudentID = id){
    cout << P->StudentID<< "\n";
        cout << P->FirstName << "\n";
            cout << P->LastName << "\n";
}
else{
P = P->Next1 ;
}
}
}

//Part5
//This Function is for Delete a Student Information

void DeleteInformation_Student(StudentList* P){
long int ID;
cout << "Enter ID : " << endl ;
cin >> ID;
StudentList* s = P;
StudentList* q = P;
while (q->Next1 != NULL && q->StudentID != ID){
q = q->Next1;
}
if (q == NULL){
cout << "Student not found !" << endl ;
}
if (q->StudentID == P->StudentID){
P = P->Next1;
q->Next1 = NULL;
delete q;
}
else{
s->Next1 = q->Next1;
q->Next1 = NULL;
delete q;
}
}

//Part6
//This Function is for Add a New Lesson for Every Student

void AddLesson_Student(StudentList* P){
long int Id;
cout << "Enter ID :\n";
cin >> Id;
while (P->Next1 != NULL && P->StudentID != Id){
P = P->Next1;
}
if (P == NULL){
cout << "Student not found !!\n";
}
else{
/*if (P->Next1 == NULL){
cout << "Enter " << P -> FirstName << "new lesson name :\n";
cin >> P -> LessonName;
cout << "Enter " << P->FirstName << "new lesson id :\n";
cin >> P -> LessonID;
cout << "Enter " << P->FirstName << "new lesson unit :\n";
cin >> P -> LessonUnit;
}
}
        }*/
    }
}

//Part7
//This Function is for The List of Lessons of a Student

void LessonList_Student(StudentList* P){
long int X;
cout << "Enter student id : \n";
cin >> X;
while (P->Next1 != NULL && P->StudentID != X){
P = P->Next1 ;
}
if (P->Next1 == NULL){
cout << "Student not found !" << endl ;
}
else{
cout << P->FirstName << " " << P->LastName << " lessons : " << endl ;
/*while (P->Next1 != NULL){
int i = 1;
cout << i << "lesson " << P->LessonName << "\n";
i++;
P->LessonName = P->LessonName->Next1;
        }*/ // This Block has Some errors
    }
}

//Part8
//This Function is for Absent-Present of a Student

void AbsentPresent_Student(StudentList* P, LessonList* L){
int LessonId;
cout << "Enter Lesson ID : " << endl;
cin >> LessonId ;
while (L->Next1 != NULL && L->LessonID != LessonId){
L = L->Next1;
}

if (L->Next1 == NULL){
cout << "Lesson not found !!\n";
}

else{
   /* while (P->Next1 != NULL){
        while (P->Nextl != NULL){
            if (P->LessonID == LessonId){
                cout << P->FirstName << " " << P->LastName << " ";
                    if (P->FirstLesson->AbsentPresent_Student == 1){
                        cout << "He/She is in Class " << endl;
                        }
                    if (P->FirstLesson->AbsentPresent_Student == 0){
                        cout << "He/She is not in Class !" << endl;
                    }
                }
                        else{
                            P->FisrtLesson = P->FirstLesson->Nextl;
                        }
            }
            P = P->Next1;
        }*/ // This Block has Some errors
    }
}

//Part9
//This Function is for Delete a Lesson

void Delete_Lesson(StudentList* P){
long int StudenID;
int LessID;
cout << "Enter Student ID : " << endl ;
cin >> StudenID;
cout << "Enter Lesson ID :  " << endl ;
cin >> LessID;
while (P->Next1 != NULL && P->StudentID != StudenID){
P = P->Next1;
                    }
if (P->Next1 == NULL){
cout << "There is no Student in this School with this Informations ! " << endl ;
}
else{
        LessonList* L;
        LessonList* L2;
        /*L = P->FirstName;
while (P->FirstName->LessonID != NULL && P->FirstName->LessonID != LessID){
                P->FirstName = P->FirstName->nextl;
                }
if (P->FirstName->LessonID == NULL){
        cout << " Lesson is not exists ! " << endl;
            }
else{
if (L == P->FirstName){
        L = L->Nextl;
            P->FirstName->Nextl = NULL;
                delete P->FirstName->Nextl;
                }
else{
        L2->Nextl = P->FirstName->Nextl;
            P->FirstName->Nextl = NULL;
                delete P->FirstName;
            }
        }*/
    }
}

//Part10
//Main

int main(){
        StudentList* Student;
        LessonList* Lesson;
        int Menu;
        int P;
            cout << "Menu : "<< endl << "1.Add student " << endl << "2.Search student"<< endl << "3.Delete student" << endl << "4.Add lesson" << endl << "5.lesson list "<< endl << "6.Absent-Present : "<< endl << "7.Delete lesson" <<" 8.Exit " << endl;
                cin >> Menu;
            if (Menu == 1){
        NewStudent(P);
        }
            if (Menu == 2){
        SearchingStudent(P);
        }
            if (Menu == 3){
        DeleteInformation_Student(P);
        }
            if (Menu == 4){
        AddLesson_Student(P);
        }
            if (Menu == 5){
        LessonList_Student(P);
        }
            if (Menu == 6){
        AbsentPresent_Student(P,l);
        }
            if (Menu == 7){
        Delete_Lesson(P);
        }
        if (Menu == 8){
        cout << endl << "\t\t  closed \t\t";

        }
    }


