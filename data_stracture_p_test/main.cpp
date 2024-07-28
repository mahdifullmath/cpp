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
    node<t> *front=nullptr;
    node<t> *rear=nullptr;
public:
    listqueue (){
        que=new noderas<t>;
    }
    ~listqueue(){
        delete que;
    }
    void insert(t a){

        if (front==nullptr){
            front=rear=new node <t>;
            front->info=a;
            que->nextnode=front;
            que->lastnode=rear;
            rear->nextnode=nullptr;
        }
        else{
            node<t> *q;
            q=new node <t>;
            q->info=a;
            if (a<front->info){
                q->nextnode=front;
                front=q;
                que->nextnode=front;
            }
            else if(front->nextnode==nullptr){
                q->nextnode=front->nextnode;
                front->nextnode=q;
                rear=que->lastnode=q;
            }
            else {
                node<t> *z=front;
                node<t> *x=z->nextnode;
                while(x->info<q->info&&x->nextnode!=nullptr){
                    z=z->nextnode;
                    x=x->nextnode;
                }
                if(x->nextnode==nullptr&&x->info<a){
                    q->nextnode=x->nextnode;
                    x->nextnode=q;
                    que->lastnode=rear=q;
                }
                else{
                    q->nextnode=z->nextnode;
                    z->nextnode=q;
                }
            }
        }
    }
    t remove(t a){
        if (front==rear)
            rear=nullptr;
        if(a==front->info){
            node<t> *q=que->nextnode;
            a=q->info;
            front=que->nextnode=q->nextnode;
            delete q;
            q=nullptr;
            return a;
        }
        else{
            node<t> *x=front->nextnode;
            node<t> *z=front;
            while(x->info!=a){
                x=x->nextnode;
                z=z->nextnode;
            }
            if(x==rear){
                node<t> *q=que->lastnode;
                a=q->info;
                rear=que->lastnode=z;
                rear->nextnode=nullptr;
                delete q;
                q=nullptr;
                return a;
            }
            else{
                node<t> *q=x;
                a=q->info;
                z->nextnode=x->nextnode;
                delete q;
                q=nullptr;
                return a;

            }
        }
    }
    t search(t a){
        node <t> *x=front;
        while(x->info!=a){
            x=x->nextnode;
        }
        return x->info;
    }
    bool isempty(){
        if (front==nullptr)
            return true;
        return false;
    }
    void display(){
        node <t> *q=front;
        while(q->nextnode!=nullptr){
            cout<<endl<<q->info;
            q=q->nextnode;
        }
        cout<<endl<<q->info;
    }
};
int main()
{
    listqueue<int> a;
    a.insert(1);
 //   a.insert(87);
    a.insert(3);
    a.insert(2);
    a.insert(4);
    a.insert(5);
 //   a.insert (7);
//    cout<<a.isempty1()<<endl<<a.remove(6)<<endl<<a.isempty1()<<endl<<a.remove(7)<<endl<<a.remove(1)<<endl<<a.remove(2)<<endl<<a.remove(3)<<endl<<a.remove(5)<<endl<<a.isempty1();
    a.display();
    return 0;
}
