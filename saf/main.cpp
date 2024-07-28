#include <iostream>

using namespace std;
template<class t,int Max>
class priorityqueue1 {
private:
    t items[Max];
    int rear=-1;
public:
    void inserti(t x){
        items[++rear]=x;
    }
    t deletei(){
        t maxx=items[0];
        int ii=0;
        for (int i=0;i<=rear;i++){
            if(items[i]>maxx){
                maxx=items[i];
                ii=i;
            }
        }
        for (int i=ii;i<rear-1;i++){
            swap (items[i],items[i+1]);
        }
        return items [rear--];
    }
    bool isempty(){
        if (rear==-1)
            return 1;
        else
            return 0;
    }
};
template<class t,int Max>
class priorityqueue2{
private:
    t items[Max];
    bool empt[Max]={false};
public:
    void inserti(t x){
        int i=0;
        for (;empt[i]==true;i++){}
        items [i]=x;
        empt [i]=true;
    }
    t deletei(){
        t maxx;
        int ii=0;
        for (int i=0;i<Max;i++){
            if(empt[i]==true){
                maxx=items[i];
                ii=i;
                break;
            }
        }
        for (int i=ii;i<Max;i++){
            if(items[i]>maxx&&empt[i]==true){
                maxx=items[i];
                ii=i;
            }
        }
        empt[ii]=false;
        return items[ii];
    }
    bool isempty(){
        for (int i=0;i<Max;i++){
            if (empt[i]==true)
              return false;
        }
        return true;
    }
};
template<class t,int Max>
class priorityqueue3 {
private:
    t items[Max];
    int rear=-1;
    bool empt[Max]={false};
public:
    void inserti(t x){
        items[++rear]=x;
        empt [rear]=true;
        if (rear==Max-1){
            for (int i=0;i<rear;i++){
                if (empt [i]==false){
                    swap(empt[i],empt[rear]);
                    for (int i=0;i<rear;i++){
                        swap(items[i],items[i+1]);
                    }
                    rear--;
                }
            }
        }
    }
    t deletei(){
        t maxx;
        int ii=0;
        for (int i=0;i<Max;i++){
            if(empt[i]==true){
                maxx=items[i];
                ii=i;
                break;
            }
        }
        for (int i=ii;i<Max;i++){
            if(items[i]>maxx&&empt[i]==true){
                maxx=items[i];
                ii=i;
            }
        }
        empt[ii]=false;
        return items[ii];
    }
    bool isempty(){
        for (int i=0;i<Max;i++){
            if (empt[i]==true)
              return false;
        }
        return true;
    }
};
template<class t,int Max>
class priorityqueue4 {
private:
    t items[Max];
    int rear=-1;
public:
    void inserti(t x){
        int i=rear;
        for (;i>=rear;i--){
            if(items[i]<x){
               break;
            }
        }
        for (int j=rear;j>i;j--){
            swap (items[j],items[j+1]);
        }
        items[i+1]=x;
        rear++;
    }
    t deletei(){
        return items[rear--];
    }
    bool isempty(){
        if (rear==-1)
            return 1;
        else
            return 0;
    }
};
int main()
{
    priorityqueue1<int,10> a;
    a.inserti(100);
    a.inserti(200);
    cout << a.deletei() <<endl <<a.isempty()<<endl;

    priorityqueue2<int,10> a2;
    a2.inserti(100);
    a2.inserti(200);
    cout << a2.deletei() <<endl <<a2.deletei()<<endl<<a2.isempty()<<endl;

    priorityqueue3<int,10> a3;
    a3.inserti(100);
    a3.inserti(10);
    a3.inserti(200);
    cout << a3.deletei() <<endl <<a3.deletei()<<endl<<a3.isempty()<<endl;

    priorityqueue4<int,10> a4;
    a4.inserti(100);
    a4.inserti(10);
    a4.inserti(200);
    cout << a4.deletei() <<endl <<a4.deletei()<<endl<<a4.deletei()<<endl<<a4.isempty()<<endl;
    return 0;
}
