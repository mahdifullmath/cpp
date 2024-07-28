#include <iostream>
#include <iomanip>

using namespace std;

bool promising(int* s, int satr, int n){
    if (satr == 0){
        return true;
    }
    for (int i = 0; i <= satr - 1; i++){
        for (int j = i + 1; j <= satr; j++){
            if ((s[i] >= n) || (s[j] >= n) || (s[i] == s[j] || i - j == s[i] - s[j] || i - j == s[j] - s[i])){
                return false;
            }
        }
    }
    return true;
}


void print_queen(int *s, int satr, int n){
    static int counter = 0;
    if (promising(s,satr,n)){
        if (satr == n-1){
            int row = 0;
            if(row)
            counter++;
            cout << setw(3) << counter << ": ";
            for (int i=0; i < n; i++){
                cout << setw(2) << "(" << row << "," <<s[i] << ")";
                row++;
                }
            cout << endl;
        }
        else{
            for (int j=0; j < n; j++){
                s[satr + 1] = j;
                print_queen(s,satr+1,n);
            }
        }
    }
}

void queen(int n){
    int s[n];
    for (int i=0; i < n; i++) {
        s[0] = i;
        print_queen(s,0,n);
    }
}


int main(){
 int n;
 cout << "Enter n:";
 cin >> n;
 queen(n);

 return 0;
}

