#include <iostream>

using namespace std;
int gh(int x){
    if (x==0)
        return x;
    if (x>0)
        return gh(x-1)-1;
    if (x<0)
    return gh(x+1)+1;
}

int main()
{
    cout << sizeof(float) << endl;
    return 0;
}
