#include <iostream>

using namespace std;
template<class t>
struct node{
    t info;
    node *nextnode;
};
template<class t>
struct noderas{
    node<t> *lastnode;
    node<t> *nextnode;
};
template<class t>
class listqueue {
private:
    noderas<t>*que;
    node<t> *front=NULL;
    node<t> *rear=NULL;
public:
    listqueue (){
        que=new noderas<t>;
    }
    void insert1(t a){

        if (front==NULL){
            front=rear=new node <t>;
            front->info=a;
            que->nextnode=front;
            que->lastnode=rear;
            rear->nextnode=NULL;
        }
        else{
            node<t> *q;
            rear->nextnode=q=new node <t>;
            rear=q;
            rear->info=a;
            rear->nextnode=NULL;
            que->lastnode=rear;
        }
    }
    t remove1(){
        if (front==rear)
            rear=NULL;
        t a;
        node<t> *q=que->nextnode;
        a=q->info;
        front=que->nextnode=q->nextnode;
        delete q;
        q=NULL;
        return a;
    }
    bool isempty1(){
        if (front==NULL)
            return true;
        return false;
    }
};
int main()
{
    listqueue<int> a;
    a.insert1(10);
    a.insert1(87);
    cout<<a.isempty1()<<endl<<a.remove1()<<endl<<a.isempty1()<<endl<<a.remove1()<<endl<<a.isempty1();

    return 0;
}
