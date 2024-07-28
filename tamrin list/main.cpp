#include <iostream>

using namespace std;
template <class t>
struct node{
    t info;
    node<t> *next;
};
template <class t>
void display(node <t>*a){
    node <t>*p=a;
    while(p!=NULL){
        cout<<p->info<<endl;
        p=p->next;
    }
}
template <class t>
void deletenode(node <t>*p){
    if(p->next==NULL){
        return;
    }
    else{
        deletenode(p->next);
        delete p;
        p=NULL;
    }
}
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
    display(a);
    deletenode(a);

    return 0;
}
