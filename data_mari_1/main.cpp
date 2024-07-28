#include <iostream>

using namespace std;
template <class t>
struct node{
    t info;
    node<t> *next;
};
//-------------------------------------
template <class t>
void display(node <t>*a){
    node <t>*p=a;
    while(p!=NULL){
        cout<<p->info<<endl;
        p=p->next;
    }
}
//-------------------------------------
template <class t>
void displayrev(node <t>*a){
    node <t>*p=a;

    if(p->next==NULL){
        cout<<p->info<<endl;
        return;
    }

    displayrev(p->next);
    cout<<p->info<<endl;

}
//------------------------------------
template <class t>
void deletenode(node<t>*a,node <t>*d){
    if (d==a){
        a=d->next;
        delete d;
        d=NULL;
    }
    node<t>*p=a;
    for (int i=0;p->next==d;i++){
        p=p->next;
    }
    node<t>*q=p;
    node<t>*s=p->next;
    q->next=q->next->next;
    delete s;
    s=NULL;
}
//--------------------------------------
template<class t>
void delete_n(node<t> *p,int n){
    node<t>*q=p;
    for (int i=0;i<n;i++){
        q=q->next;
    }
    deletenode(p,q);
}
//-------------------------------------
template<class t>
void delete_x(node<t> *p,t x){
    node<t>*q=p;
    for (int i=0;q->next==NULL;i++){
        if (q->info==x){
            deletenode(p,q);
        }
        q=q->next;
    }
}
//----------------------------------------------
template<class t>
void sortlist(node <t>*a){
    node <t>*p=a;
    for (;p->next!=NULL ;p=p->next){
  	   for (node <t>*q=a; q->next!=NULL;q=q->next){
		 if (q->info>q->next->info)
	 	{
			swap (q->info,q->next->info);
		 }
       }
    }
}
int main()
{
    int x=1;
    node <int>*a=new node <int>;
    node <int>*p=a;
    node <int>*q=p;
    while (1){
        cin>>x;
        if (x<0){
            delete p;
            q->next=NULL;
            p=NULL;
            break;
        }
        else{
            p->info=x;
            q=p;
            p=p->next=new node <int>;
        }
    }
    sortlist(a);
    //display(a);
    //displayrev(a);
    //delete_n(a,3);
   // delete_x(a,x);
    display(a);


    return 0;
}
