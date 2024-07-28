#include <iostream>
#include <string>

using namespace std;
template<class T>
class stack {
	private:
	    T items[1000];
	    int topi;
    public:
       stack(){
       	topi=-1;
        }
        bool empty (){
        	if (topi==-1)
        	   return true;
        	else
        	   return false;
        }
        void pop (){
        	topi--;
        }
        void push (T x){
        	items[++topi]=x;
        }
        T top (){
        	return items[topi];
        }
        int size(){
            return topi+1;
        }
};
//______________
void error(){
cout<<"\nebarat ghalat ast\n";
}
void par (string in){
    stack <char>a;
    for (int i=0;in[i]!=0;i++){
        if (!(in[i]=='('||in[i]=='['||in[i]=='{'||in[i]==')'||in[i]==']'||in[i]=='}')){

        }
        else if (in[i]=='('||in[i]=='['||in[i]=='{'){
            a.push(in[i]);

            }
        else {
            if(in[i]==')'){
                if(a.top()!='('){
                        error();
                        return;
                    }
                else
                    a.pop();
            }
            else if(in[i]==']'){
                if(a.top()!='['){
                        error();
                        return;
                    }
                else
                    a.pop();
            }
            else if(in[i]=='}'){
                if(a.top()!='{'){
                        error();
                        return;
                    }
                else
                    a.pop();
            }
        }
    }
    if (a.empty())
        cout<<"\nebarat dorost ast\n";
    else
       error();
}
//___________

int main()
{
    string input;
    char post[1000],a='y';
    while (a=='y'){
     cout<<"put in infix: ";
     cin>> input;
     par (input);
     do {
           cout <<"\ndo you whant to contineue?(y,n)";
           cin>>a;
    }while (a!='y'&&a!='n');
    }
    return 0;
}
