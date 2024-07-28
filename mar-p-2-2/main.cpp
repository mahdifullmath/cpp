#include <iostream>
using namespace std;

void zarb ( int a[7][3], int b[3][5]){
    int c[7][5];
    for (int i=0;i<7;i++){
        for (int j=0;j<5;j++){
            c[i][j]=0;
        }
    }
    cout<<"A x B = :\n";
    for(int i = 0; i < 7; i++){
        for( int j = 0; j < 5; j++){
            for(int k = 0; k < 3; k++)
                c[i][j] += a[i][k] * b[k][j];


            cout<<' '<<c[i][j]<<'\t';
        }
        cout<<endl;
    }

}

int main() {

    int a[7][3] ;
    int b[3][5] ;
    cout<<"input a[7][3]:\n";
    for (int i=0;i<7;i++){
        for (int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    cout<<"input b[3][5]:\n";
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            cin>>b[i][j];
        }
    }
    zarb (a,b);

    return 0;
}
