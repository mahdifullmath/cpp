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
struct node3{
    string name;
    unsigned int id;
    int avgmark;
    node3 *nextnode;
};
template<class t>
class listqueue {
public:
    noderas<t>*que;
    node<t> *front=nullptr;
    node<t> *rear=nullptr;

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
};
class list3_stu{
private:
    listqueue<string> name;
    listqueue<unsigned int> id;
    listqueue<int> avgmark;
    node3 *front=nullptr;
//    node3 *rear=nullptr;
public:
    void insert(string name1,unsigned int stud_nam1,int avgmark1){
        name.insert(name1);
        id.insert(stud_nam1);
        avgmark.insert(avgmark1);

        node3 *q=new node3;
        q->name=name1;
        q->id=stud_nam1;
        q->avgmark=avgmark1;
        q->nextnode=front;
        front=q;
    }
    void remove_with_id(unsigned int a){
        if (isempty1()){
                cout<<"\nlist is empty";
            return;
        }
        node3 *x=front;
        serch_node3_id(x,a);
        id.remove(x->id);
        avgmark.remove(x->avgmark);
        name.remove(x->name);
        remove1(x);
    }
    void remove1(node3 *a){
         if(a==front){
            node3 *q=a;
            front=q->nextnode;
            delete q;
            q=nullptr;
        }
        else{
            node3 *x=front->nextnode;
            node3 *z=front;
            while(x!=a){
                x=x->nextnode;
                z=z->nextnode;
            }
            node3 *q=x;
            z->nextnode=x->nextnode;
            delete q;
            q=nullptr;
        }
    }
    void serch_node3_id(node3 *x,unsigned int a){
        x=front;
        while(x->id!=a){
            x=x->nextnode;
        }
    }
    void serch_node3_name(node3 *x,string a){
        x=front;
        while(x->name!=a){
            x=x->nextnode;
        }
    }
    void serch_node3_avgmark(node3 *x,int a){
        x=front;
        while(x->avgmark!=a){
            x=x->nextnode;
        }
    }
    void display_searched_id(unsigned int a){
        node3 *x=front;
        serch_node3_id(x,a);
        cout<<endl<<x->name<<"\t"<<x->id<<"\t"<<x->avgmark<<"\n******************************************************";
    }
     void display_sorted_name(){
        node<string> *t=name.front;
        while(t->nextnode!=nullptr){
            node3 *x=front;
            serch_node3_name(x,t->info);
            t=t->nextnode;
            cout<<endl<<x->name<<"\t"<<x->id<<"\t"<<x->avgmark<<"\n******************************************************";
        }
     }
    void display_sorted_id(){
        node<unsigned int> *t=id.front;
        while(t->nextnode!=nullptr){
            node3 *x=front;
            serch_node3_id(x,t->info);
            t=t->nextnode;
            cout<<endl<<x->name<<"\t"<<x->id<<"\t"<<x->avgmark<<"\n******************************************************";
        }
     }
    void display_sorted_avgmark(){
        node<int> *t=avgmark.front;
        while(t->nextnode!=nullptr){
            node3 *x=front;
            serch_node3_avgmark(x,t->info);
            t=t->nextnode;
            cout<<endl<<x->name<<"\t"<<x->id<<"\t"<<x->avgmark<<"\n******************************************************";
        }
    }
    bool isempty1(){
        return id.isempty();
    }


};

int main()
{
    list3_stu a;
    int x=0;
    while (x!=7){
        cout<<endl<<"insert a number 1-7:\n1=enter a student:\n2=search id:\n3=delete by id:\n4=display students sorted by name\n5=display students sorted by id\n6=display students sorted by average marks\n7=exit\n";
        cin>>x;
        if (x==1){
            string name;
            cout<<"\nenter student name pleas:";
            cin>>name;
            unsigned int id;
            cout<<"\nenter student id:";
            cin>>id;
            int avg;
            cout<<"\nenter student average mark:";
            cin>>avg;
            a.insert (name,id,avg);
        }
        if(x==2){
            cout<<"\n enter id:";
            unsigned int s;
            cin>>s;
            a.display_searched_id(s);

        }
        if(x==3){
            cout<<"\n enter id:";
            unsigned int s;
            cin>>s;
            a.remove_with_id(s);
        }
        if(x==4){
            a.display_sorted_name();
        }
        if(x==5){
            a.display_sorted_id();
        }
        if(x==6){
            a.display_sorted_avgmark();
        }

    }
    return 0;
}
