#include <iostream>

using namespace std;
struct node3{
    string name;
    unsigned int id;
    int avgmark;
    node3 *next_name;
    node3 *next_id;
    node3 *next_avgmark;
};
struct noderas{
    node3 *first_name;
    node3 *first_id;
    node3 *first_avgmark;
};
class list_stud {
private:
    node3 *st=NULL;
    noderas *ras=NULL;

public:
    list_stud (){
        ras=new noderas;
    }
    ~list_stud(){
        delete ras;
    }
    void insert(string name1,unsigned int stud_nam1,int avgmark1){

        if (st==NULL){
            st=new node3;
            st->name=name1;
            st->id=stud_nam1;
            st->avgmark=avgmark1;
            st->next_avgmark=NULL;
            st->next_id=NULL;
            st->next_name=NULL;
            ras->first_avgmark=st;
            ras->first_id=st;
            ras->first_name=st;


        }
        else{
            node3 *q;
            node3 *x=new node3;
            x->id=stud_nam1;
            x->name=name1;
            x->avgmark=avgmark1;
            if(ras->first_avgmark->avgmark>avgmark1){
                    ras->first_avgmark->next_avgmark=x;
                    ras->first_avgmark=x;
                    x->next_avgmark=NULL;
                    st=x;
            }
            else{
                q=ras->first_avgmark;
                while(q->next_avgmark->avgmark <avgmark1&&q->next_avgmark!=NULL){
                    q=q->next_avgmark;
                }
                x->next_avgmark=q->next_avgmark;
                q->next_avgmark=x;
            }
            if (ras->first_id->id>x->id){
                    ras->first_id->next_id=x;
                    ras->first_id=x;
                    x->next_id=NULL;
                    st=x;
            }
            else {
                q=ras->first_id;
                while(q->next_id->id <stud_nam1&&q->next_id!=NULL){
                    q=q->next_id;
                }
                x->next_id=q->next_id;
                q->next_id=x;
            }
            if (ras->first_name->name>name1){
                    ras->first_name->next_name=x;
                    ras->first_name=x;
                    x->next_name=NULL;
                    st=x;
            }
            else{
                q=ras->first_name;
                while(q->next_name->name < name1&&q->next_name!=NULL){
                    q=q->next_name;
                }
                x->next_name=q->next_name;
                q->next_name=x;
            }
        }
    }
    void remove_with_id(unsigned int a){
        if (isempty()){
                cout<<"\nlist is empty";
            return;
        }
        node3 *x=ras->first_id;
        if (a==x->id){
            ras->first_id=ras->first_id->next_id;
            ras->first_avgmark=ras->first_avgmark->next_avgmark;
            ras->first_name=ras->first_name->next_name;
            delete x;
        }
        else{
        node3 *t=ras->first_id->next_id;
        while (a!=t->id&&t!=NULL){
            x=x->next_id;
            t=t->next_id;
        }
        x->next_avgmark=x->next_avgmark->next_avgmark;
        x->next_id=x->next_id->next_id;
        x->next_name=x->next_name->next_name;
        x->next_avgmark=x->next_avgmark->next_avgmark;
        delete t;
        }
    }
    void display_searched_id(unsigned int a){
        node3 *t=ras->first_id;
        while (a!=t->id){
            t=t->next_id;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
    }
    void display_sorted_name(){
        node3 *t=ras->first_name;
        while(t->next_name!=NULL){
            cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
            t=t->next_name;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;

    }
    void display_sorted_id(){
        node3 *t=ras->first_id;
        while(t->next_id!=NULL){
            cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
            t=t->next_id;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
    }
    void display_sorted_avgmark(){
        node3 *t=ras->first_avgmark;
        while(t->next_avgmark!=NULL){
            cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
            t=t->next_avgmark;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
    }
    bool isempty(){
        if (st==NULL)
            return true;
        return false;
    }
};
int main()
{
    list_stud x;
    x.insert("b",2,3);
    x.insert("a",1,2);
    x.display_searched_id(2);
    x.display_sorted_id();
    return 0;
}
