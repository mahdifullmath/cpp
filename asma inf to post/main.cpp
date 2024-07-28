#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;
//tavabe---------------------------------------------------------------
float eval(float d,float n,char k);
bool prcd(char op1,char op2);
bool isoperand(char a[]);
bool isoperator(char q);
bool highprcd(char a, char b);
int operatorweight(char a,char b);
string infix_to_postfix(string infix);
string calculation(string postfix);
int Max = 100;
//stack----------------------------------------------------------------
template<class t , int Max>
class stack{
private:
    t items[100];
    int top;
public:
    stack(){
        top=-1;
    }
    bool empty(){
        if(top==-1)
            return true;
        return false;
    }
    bool push(t x){
        if(top==Max-1)
            return false;
        items[++top]=x;
        return true;
    }
    t pop(){
        if(empty()){
            cout<<"stack is empty.";
        }
        return items[top--];
    }
    t stacktop(){
        if(empty()){
           cout<<"stack is empty.";
           exit(1);
        }
        return items[top];
    }

};
//main-------------------------------------------------------------
int main()
{
    string infix;
    string f;
    cout<<"Enter infix expression : "<<endl;
    cin>>infix;
    cout<<"Postfix expression : "<<infix_to_postfix(infix)<<endl;
    return 0;
}
//------------------------------------------------------------------
bool prcd
 (char o2,char o1){
    if (o1=='^'){
        if (o2=='^'||o2=='('||o2=='['||o2=='{')
            return true;
        else
            return false;
    }
    else if (o1=='*'||o1=='/'){
        if (o2=='^'||o2=='('||o2=='['||o2=='{')
            return true;
        else
            return false;
    }
    else if (o1=='+'||o1=='-'){
        if (o2=='+'||o2=='-'||o2==')'||o2==']'||o2=='}')
            return false;
        else
            return true;
    }
    else if (o1=='('||o1=='['||o1=='{'){
        if (o2==')'||o2==']'||o2=='}')
            return false;
        else
            return true;
    }
    else if (o1=='!'){
        if (o2==')'||o2==']'||o2=='}')
            return false;
        else
            return true;
    }
    else
        return true;
}
//-------------------------------------------------------------------
bool isoperand(char a){//Check weather the character is operand
      if(a>='A' && a<='Z'){
          return true;}
      if(a>='a' && a<='z'){
         return true;}
      if(a>='0' && a<='9') {
        return true;}
    return false;
    }
//----------------------------------------------------------------------
bool isoperator(char q){//Check weather the character is operator
        if(q=='*' || q=='/' || q=='+' || q=='-' || q=='^' || q=='(' || q == ')'|| q == '-'||q=='cos'||q=='sin')
            return true;
        else
            return false;
}
//-------------------------------------------------------------------------
int operatorweight(char a,char b)//Add weight to the operator
{
    switch(a)
   {
        case '(' :
            return 1;
            break;
        case '-' :
            return 2;
            break;
        case '+' :
            return 3;
            break;
        case '*' :
            return 4;
            break;
        case '/' :
            return 5;
            break;
        case '^':
            return 6;
        case '!':
            return 7;

    }
}
int fact (float k){
    int t=1;
    for(int i=k;i>=1;i--)
        t=t*i;
    return t;
}
//-------------------------------------------------------------------------
float eval(float d,float n,char k){
    int i;
    if(k =='*')
        return float(d*n);
    if(k =='/')
        return float(d/n);
    if(k =='-')
        return float(d-n);
    if(k =='+')
        return float(d+n);
    if(k =='^');
	    return pow(d,n);
    if(k =='sin')
        return sin(d);
    if(k =='cos')
        return cos(d);
    if(k =='-')
        return -d;
    if(k=='!')
        return (fact(d));
    }
//--------------------------------------------------------------------------
string infix_to_postfix(string infix){
	string postfix = "";
	stack<char, 100> s;
    int j = 0;
    while(infix[j]!=NULL){
        if(infix[j]=='s')
            if(infix[j+1]=='i')
                if(infix[j+2]=='n'){
                    infix[j+2]='sin';
                        j=j+2; }
        if(infix[j]=='c')
            if(infix[j+1]=='o')
                if(infix[j+2]=='s'){
                    infix[j+2]='cos';
                        j+=2; }
        if(infix[j]=='_')
            if(isoperator(infix[j-1]))
                infix[j]='-';
        if(infix[j]=='(')
            s.push(infix[j]);

        else if(infix[j]==')'){
            while(s.stacktop()!= '('){
                    postfix = postfix + s.stacktop();
                    s.pop();
            }
                  s.pop();
            }
        else if(isoperand(infix[j])){
            postfix += infix[j];
        }
        else if(isoperator(infix[j]))
        {
            while(!s.empty() && !prcd(infix[j],s.stacktop()) )
            {
                postfix+= s.stacktop();
                s.pop();
            }
            s.push(infix[j]);
        }


        j++;
    }
    while(!s.empty()){
        postfix+= s.stacktop();
        s.pop();
    }
    cout<<postfix;
    calculation(postfix);
}
//-------------------------------------------------------------------------------
string calculation(string postfix){
    char javab[100]={'\0'};
    stack <float,100> f;
    float x,y,z;
    int i=0;
    while(postfix[i]!=NULL){
        if(isoperand (postfix[i])){
            cout<<"\n enter postfix meghdar "<<postfix[i]<<" : ";
            cin>>javab[i];
    }
        else
            javab[i]=postfix[i];
        i++;
    }
    int q=0;
    while(javab[q]!=NULL){
        if(!isoperator(javab[q]))
            f.push(javab[q]-48);
        if(isoperator(javab[q])){
            x=f.pop();
        if(!f.empty()){
            y=f.pop();
            z=eval(x,y,javab[q]);
            f.push(z);
        }
        else {
            z=eval(x,0,javab[q]);
            f.push(z);}
        }
        q++;
    }
    cout<<" calculation = "<<f.stacktop();
}
