#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;
bool prcd(char op1,char op2){//check precendence
    if(op1=='^' && op2!='^')
        return true;
    if(op2!='+' && op2!='-')
        return false;
    if(op1=='*'||op1=='/')
        return false;
	if (op1 == '+' || op1 == '-')
	    return true;
	if (op1 == '^' && op2 != '^')
		return true;
	if ((op1 == '*' || op1 == '/') && (op2 == '^'))
        return true;
    if(op2=='sin'||op2=='cos'||op2=='-')
        return false;
    if(op1=='sin'||op1=='cos'||op1=='-')
        return true;
	if (op1 == '(' && op2 != '(')
		return false;
	if (op1 != ')' && op2 == ')')
		return false;
    if(op1 == '(' && op2 == ')')
        return true;
}
int main (){
    cout<<prcd (')','+');
}
