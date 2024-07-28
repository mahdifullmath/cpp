#include <iostream>
#include <stack>
#include <string>
using namespace std;
//______________
bool is_amalvand(char a){
    if (a>='A'&&a<='Z'||a<='z'&&a>='a')
        return true;
    else
        return false;
}
int prc (char a){
    if (a=='('||a=='['||a=='{')
        return 0;
    else if (a=='+'||a=='-')
        return 1;
    else if (a=='*'||a=='/')
        return 2;
    else if (a=='^')
        return 3;
    else
        return 4;
}
//________________
int inf_to_pos (string in,char o[]){
    stack <char>a;
    int amalvand=0,j=0;
    for (int i=0;in[i]!=0;i++){
        if (in [i]=='s'&&in[i+1]=='i'||in[i]=='c'&&in[i+1]=='o'){
            a.push(in[i]);
            i+=2;
        }
        else if (is_amalvand(in[i])){
            amalvand++;
            o[j]=in[i];
            j++;
        }
        else {
            while (!(a.empty())&&(prc(a.top())>=prc(in[i]))){
                if (a.top()=='('){
                    a.pop();
                    i++;
                    if (a.top()=='s'){
                       o[j++]=a.top();
                       a.pop();
                       o[j++]='i';
                       o[j++]='n';
                    }
                    else if (a.top()=='c'){
                       o[j++]=a.top();
                       a.pop();
                       o[j++]='o';
                       o[j++]='s';
                    }
                }
                else
                    o[j++]=a.top();
                    a.pop();
            }
            a.push(in[i]);
        }
    }
    while (!(a.empty())){
        o[j++]=a.top();
        a.pop();
    }
    o[j]=0;
    return amalvand ;

}
int main()
{
    string input;
    char post [1000];
    cin>> input;
    int n;
    n=inf_to_pos (input,post);
    cout << post << endl<<n<<endl;
    return 0;
}
