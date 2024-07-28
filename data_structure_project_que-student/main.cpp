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
    node3 *rear=nullptr;
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
            rear=st=new node3;
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
//********sorting avgmark**************************************
            if(ras->first_avgmark->avgmark>avgmark1){
                    x->next_avgmark=ras->first_avgmark;
                    ras->first_avgmark=x;
                    st=x;
            }
            else if(ras->first_avgmark->next_avgmark==nullptr){
                x->next_avgmark=ras->first_avgmark->next_avgmark;
                ras->first_avgmark->next_avgmark=x;
                rear=x;
            }
            else {
                q=ras->first_avgmark;
                node3 *z=q->next_avgmark;
                while(z->avgmark <avgmark1&&z->next_avgmark!=NULL){
                    q=q->next_avgmark;
                    z=z->next_avgmark;
                }

                if(z->next_avgmark==nullptr&&z->avgmark<avgmark1){
                    x->next_avgmark=nullptr;
                    q->next_avgmark=x;
                    rear=x;
                }
                else{
                    x->next_avgmark=q->next_avgmark;
                    q->next_avgmark=x;
                }
            }
//******sorting id***************************************************
            if (ras->first_id->id>x->id){
                    x->next_id=ras->first_id;
                    ras->first_id=x;
                    st=x;
            }
            else if(ras->first_id->next_id==nullptr){
                x->next_id=nullptr;
                ras->first_id->next_id=x;
                rear=x;
            }
            else {
                q=ras->first_id;
                node3 *z=q->next_id;
                while(z->id <stud_nam1&&z->next_id!=NULL){
                    q=q->next_id;
                    z=z->next_id;
                }

                if(z->next_id==nullptr&&z->id<stud_nam1){
                    x->next_id=nullptr;
                    q->next_id=x;
                    rear=x;
                }
                else{
                    x->next_id=q->next_id;
                    q->next_id=x;
                }
            }
 //**********sorting name**************
            if (ras->first_name->name>name1){
                    x->next_name=ras->first_name->next_name=x;
                    ras->first_name=x;
            }
            else if(ras->first_name->next_name==nullptr){
                x->next_name=nullptr;
                ras->first_name->next_name=x;
            }
            else {
                q=ras->first_name;
                node3 *z=q->next_name;
                while(z->name<name1&&z->next_name!=NULL){
                    q=q->next_name;
                    z=z->next_name;
                }

                if(z->next_name==nullptr&&z->name<name1){
                    x->next_name=nullptr;
                    q->next_name=x;
                    rear=x;
                }
                else{
                    x->next_name=q->next_name;
                    q->next_name=x;
                }
            }
        }
    }
    void remove_with_id(unsigned int a){
        if (isempty()){
                cout<<"\nlist is empty\n***************************************************";
            return;
        }
        node3 *x=ras->first_id;
        node3 *i=ras->first_id;
        node3 *i2=i->next_id;
        node3 *y=ras->first_avgmark;
        node3 *y2=y->next_avgmark;
        node3 *z=ras->first_name;
        node3 *z2=z->next_avgmark;
        while (a!=x->id&&x->next_id!=nullptr){
            x=x->next_id;
        }
        if(x->id!=a){
            cout<<"\nthis id is not in list\n***************************************************";
            return;
        }
//***********remove id ptr******************
        if(x==ras->first_id){
            ras->first_id=x->next_id;
        }
        else{
            while(x!=i2){
                i=i->next_id;
                i2=i2->next_id;
            }
            i->next_id=i2->next_id;
        }
//***********remove avgmark ptr******************

        if(x==ras->first_avgmark){
            ras->first_avgmark=x->next_avgmark;
        }
        else{
            while(x!=y2){
                y=y->next_avgmark;
                y2=y2->next_avgmark;
            }
            y->next_avgmark=y2->next_avgmark;

        }
//***********remove name ptr******************

        if(x==ras->first_name){
            ras->first_name=x->next_name;
        }
        else{
            while(x!=z2){
                z=z->next_name;
                z2=z2->next_name;
            }
            z->next_name=z2->next_name;
        }
        delete x;
        st=ras->first_id;
        rear=ras->first_avgmark;
    }
    void display_searched_id(unsigned int a){
        if (isempty()){
                cout<<"\nlist is empty\n***************************************************";
            return;
        }

        node3 *t=ras->first_id;
        while (a!=t->id&&t->next_id!=nullptr){
            t=t->next_id;
        }
        if(t->id!=a){
            cout<<"\nthis id is not in list\n***************************************************";
            return;
        }
        cout<<"\nname\tid\tavgmark";
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark<<"\n******************************************************";
    }
    void display_sorted_name(){
        if (isempty()){
                cout<<"\nlist is empty\n***************************************************";
            return;
        }
        cout<<"\nname\tid\tavgmark";
        node3 *t=ras->first_name;
        while(t->next_name!=NULL){
            cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
            t=t->next_name;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark<<"\n******************************************************";

    }
    void display_sorted_id(){
        if (isempty()){
                cout<<"\nlist is empty\n***************************************************";
            return;
        }
        cout<<"\nname\tid\tavgmark";
        node3 *t=ras->first_id;
        while(t->next_id!=NULL){
            cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
            t=t->next_id;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark<<"\n******************************************************";
    }
    void display_sorted_avgmark(){
        if (isempty()){
                cout<<"\nlist is empty\n***************************************************";
            return;
        }
        cout<<"\nname\tid\tavgmark";
        node3 *t=ras->first_avgmark;
        while(t->next_avgmark!=NULL){
            cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark;
            t=t->next_avgmark;
        }
        cout<<endl<<t->name<<"\t"<<t->id<<"\t"<<t->avgmark<<"\n******************************************************";
    }
    bool isempty(){
        if (st==NULL)
            return true;
        return false;
    }
};
int main()
{
    list_stud a;
    int x=0;
    while (x!=7){
        cout<<endl<<"insert a number 1-7:\n1=enter a student:\t\t\t2=search id:\n3=delete by id:\t\t\t\t4=display students sorted by name\n5=display students sorted by id\t\t6=display students sorted by average marks\n7=exit\n";
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
