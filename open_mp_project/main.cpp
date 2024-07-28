#include <iostream>
#include <omp.h>
#include <stdio.h>
using namespace std;
float functioni(float x)
{
    return x-5 ;
}
int main()
{
    int n = 4;
    double e = 0.01;
    float a = 0, b = 200, s;
    float y[6];
    while ((b - a) > e)
    {

        s = (b - a) / (n + 1);

        y[0] = functioni(a);
        y[n + 1] = functioni(b);
        #pragma omp parallel
        {

            // for(int k=1 ;k<=n; k++){
            int k = omp_get_thread_num() + 1;
            y[k] = functioni(a + s * k);

            // cout<<y[k];
            // cout<<k;
            #pragma omp barrier
            if ((y[k - 1] * y[k]) < 0)
            {

                b = a + k * s;
                a = a + (k-1) * s;


                cout <<"tnum="<<k<< " a=" << a << ",  b=" << b<<endl;

            }
        }
        if (y[n] * y[n + 1] < 0)
        {
            a = a + n * s;
            cout << "a=" << a << ",  b=" << b <<endl;
        }
    }

    cout << "a=" << a << ",  b=" << b << ", x=" << (a + b) / 2;
    return 0;
}
