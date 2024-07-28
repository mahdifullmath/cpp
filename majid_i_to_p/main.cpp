#include <iostream>
#include <cmath>
#include <string>
#include <conio.h>
using namespace std;

//Stack Class
template <class T,int MAX>
class stack {
    private:
        T items[MAX];
        int top = -1;
    public:
        //Check Stack Is Full Or Not?
        bool isFull(){
            if(top==MAX)
                return true;
            return false;
        }
        //Check Stack Is Empty Or Not?
        bool isEmpty(){
            if(top==-1)
                return true;
            return false;
        }
        //Push
        void push(T data){
            if(!isFull())
                items[++top] = data;
            else
                cout<<"Could not insert data, Stack is full.\n";
        }
        //Pop
        T pop(){
            if(!isEmpty())
                return items[top--];
            else
                cout<<"Could not retrieve data, Stack is empty.\n";
        }
        //Show Top Item
        T peek(){
            if(!isEmpty())
                return items[top];
            else
                cout<<"Could not show any data, Stack is empty.\n";
        }
};

//Check The Symbol Is Operator Or Not?
bool isOperator(char symbol){
    if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^'||symbol=='sin'||symbol=='cos'||symbol=='('||symbol==')'||symbol=='$'||symbol=='#'||symbol=='!')
        return true;
    return false;
}
//Check Precedence
//If Precedence True -> Push Else -> Pop
bool precedence(char symbol_1,char symbol_2){
    if(symbol_1=='('||symbol_2=='(')
        return true;
    if(symbol_2=='$'||symbol_2=='#'||symbol_2=='!')
        return false;
    if(symbol_1=='$'||symbol_1=='#'||symbol_1=='!')
        return true;
    if(symbol_1!='^'&&symbol_2=='^')
        return false;
    if(symbol_1=='*'||symbol_1=='/')
        if(symbol_2=='^'||symbol_2=='*'||symbol_2=='/')
            return false;
    if(symbol_1=='+'||symbol_1=='-')
        return false;
    return true;
}
//Converts Infix Expression To Postfix
void infix_to_postfix(char infix[],char postfix[]){
    stack<char,100> operators;
    int j=0;
    for(int i=0;infix[i]!=NULL;i++){
        //Convert Sin To Character $
        if(infix[i]=='s'&&infix[i+1]=='i'&&infix[i+2]=='n'){
            i+=2;
            infix[i]='$';
        }
        //Convert Cos To Character #
        if(infix[i]=='c'&&infix[i+1]=='o'&&infix[i+2]=='s'){
            i+=2;
            infix[i]='#';
        }
        //Convert Symmetry To Character !
        if(infix[i]=='-'&&isOperator(infix[i-1])){
            infix[i]='!';
        }
        if(!isOperator(infix[i])){
            postfix[j++]=infix[i];
        }
        else{
            if(infix[i]==')'){
                while (operators.peek()!='('){
                    postfix[j++]=operators.pop();
                    if(postfix[j-1]=='$'){
                        postfix[--j]='s';
                        postfix[++j]='i';
                        postfix[++j]='n';
                        j++;
                    }
                    if(postfix[j-1]=='#'){
                        postfix[--j]='c';
                        postfix[++j]='o';
                        postfix[++j]='s';
                        j++;
                    }
                }
                operators.pop();
            }
            else{
                while (!operators.isEmpty()&&!precedence(infix[i],operators.peek())){
                    postfix[j++]=operators.pop();
                    if(postfix[j-1]=='$'){
                        postfix[--j]='s';
                        postfix[++j]='i';
                        postfix[++j]='n';
                        j++;
                    }
                    if(postfix[j-1]=='#'){
                        postfix[--j]='c';
                        postfix[++j]='o';
                        postfix[++j]='s';
                        j++;
                    }
                }
                operators.push(infix[i]);
            }
        }
    }
    while(!operators.isEmpty()){
        postfix[j++]=operators.pop();
        if(postfix[j-1]=='$'){
            postfix[--j]='s';
            postfix[++j]='i';
            postfix[++j]='n';
            j++;
        }
        if(postfix[j-1]=='#'){
            postfix[--j]='c';
            postfix[++j]='o';
            postfix[++j]='s';
            j++;
        }
    }
}
//Function To Get Inputs
void input_operands(char postfix[],string operands[]){
    int j=0;
    for(int i=0;postfix[i]!=NULL;i++){
        if(postfix[i]=='s'&&postfix[i+1]=='i'&&postfix[i+2]=='n'){
            i+=2;
            operands[j++]="sin";
        }
        else if(postfix[i]=='c'&&postfix[i+1]=='o'&&postfix[i+2]=='s'){
            i+=2;
            operands[j++]="cos";
        }
        else{
            if(!isOperator(postfix[i])){
                cout<<postfix[i]<<" = ";
                cin>>operands[j++];

            }
            else{
                operands[j++]=postfix[i];
            }
        }
    }
    cout<<endl;
}
//Do Operations
float operation(float operand_1,float operand_2,string symbol){
    if(symbol=="+")
        return operand_1+operand_2;
    else if(symbol=="-")
        return operand_1-operand_2;
    else if(symbol=="/")
        return operand_1/operand_2;
    else if(symbol=="*")
        return operand_1*operand_2;
    else if(symbol=="^")
        return pow(operand_1,operand_2);
    else if(symbol=="sin")
        return sin(operand_1);
    else if(symbol=="cos")
        return cos(operand_1);
    else if(symbol=="!")
        return -(operand_1);
}
//Function To Calculate Result
float PostfixEval(string operands[]){
    stack<float,100> cal;
    float operand_1,operand_2;
    for(int i=0;operands[i]!="";i++){
        if(operands[i]=="sin"||operands[i]=="cos"||operands[i]=="!"){
            operand_1=cal.pop();
            cal.push(operation(operand_1,0,operands[i]));
        }
        else{
            if(operands[i][0]=='-'&&operands[i][1]!=NULL){
               cal.push(-stof(operands[i].erase(0,1)));
            }
            else{
                if(isOperator(operands[i][0])){
                    operand_2=cal.pop();
                    if(!cal.isEmpty())
                        operand_1=cal.pop();
                    else
                        operand_1=0;
                    cal.push(operation(operand_1,operand_2,operands[i]));
                }
                else{
                    cal.push(stof(operands[i]));
                }
            }
        }
    }
    return cal.peek();
}
int main(){
    cout<<"First Project Of Data Structure.\nBy Majid Masoudi Pour.\n\n\nPress Any Key To Continue ...";
    getch();
    bool will_continue = true;
    while(will_continue){
        system("cls");
        char infix[100]={NULL},postfix[100]={NULL};
        string operands[100];
        cout<<"Infix expression is: ";
        cin>>infix;
        infix_to_postfix(infix,postfix);
        cout<<"Postfix expression is: ";
        for(int i=0;postfix[i]!=NULL;i++){
            if(postfix[i]!='!')
                cout<<postfix[i];
            else
                cout<<'!';
        }
        cout<<endl<<endl<<"Enter Operands:"<<endl;
        input_operands(postfix,operands);
        cout<<"Result: "<<PostfixEval(operands)<<endl;
        cout<<"\nDo You Want Check Another Expression? ( Type \"yes\" or \"no\" ): ";
        string will_continue_test;
        cin>>will_continue_test;
        if(will_continue_test=="no")
            will_continue = false;
    }
    cout<<"\nGood Luck.\n";
    return 0;
}
