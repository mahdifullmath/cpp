#include <iostream>

using namespace std;
struct cnode{
    char cname[50];
    int cID ;
    int unit;
    float grade;
    cnode *nextcrs;
    cnode (){
        cout << "Enter name : " ; cin >> cname ;
        cout << "Enter cid : " ; cin >> cID ;
        cout << "Enter unit : " ; cin >> unit ;
        cout << "Enter grade : " ; cin >> grade ;
        nextcrs = NULL ;
    }

};
struct snode{
    char fname[15];
    char lname[30];
    int sID;
    cnode *firstcrs;
    snode *nextstd;
    snode(){
        cout << "Enter fname: "; cin >> fname ;
        cout << "Enter lname: "; cin >> lname;
        cout << "Enter sID: "    ; cin >> sID ;
        firstcrs = NULL ;
        nextstd = NULL;
    }

};
snode * gs(snode *s ){
    snode *  q = s ;
    s = new snode ;
    s->nextstd = q ;
    return s ;
}
void serchstd(snode*s){
    int sid ;
    cout << "Enter sid : "; cin >> sid ;
    snode *c = s ;
    while(c != NULL && c->sID != sid ){
        c= c->nextstd ;
    }
    if (c == NULL )cout << "std not fond !!!"<<endl;
    else  {
        cout << string (15 , '*')<<endl;
        cout << c->fname << '\t'<< c->lname <<endl;
        cout << c->sID <<endl;

        cnode * v = c->firstcrs;
        int i = 0 ;
        while(v != NULL){
            cout << ++i << v->cname<<endl;
        }
        cout << string (15 , '*')<<endl;
    }

}

void deletestd(snode *p ){
    int sid ;
    cout << "Enter sid : "; cin >> sid ;
    snode* c = p ;
    snode* q = NULL ;
    while(c != NULL && c->sID != sid){
        q = c ;
        c= c->nextstd ;
    }
    if (c == NULL )cout << "std not fond !!!"<<endl;
    else {
        q->nextstd = c->nextstd ;
        c->nextstd = NULL ;
        delete c ;

    }

}
void addc(snode * s ){
     int sid ;
    cout << "Enter sid : "; cin >> sid ;
    snode *c = s ;
    while(c != NULL && c->sID != sid ){
        c= c->nextstd ;
    }
    if (c == NULL )cout << "std not fond !!!"<<endl;
    else  {
        cnode* q = s->firstcrs;
        s->firstcrs = new cnode ;
        s->firstcrs->nextcrs = q  ;

    }
}

void Attendancel(snode *p){
    int cid ;
    snode *q = p ;
    cout << "Enter cid " ; cin >> cid ;
    cout << "name  " << "lname"<<endl;
    while ( q != NULL){
        cnode* w = p->firstcrs ;
        while(w != NULL){
            if (w->cID == cid){
                cout << q->fname << q->lname <<endl;
                break ;
            }
        }
    }
}

snode * dellesson(snode * s ){
    int sid;
    int cid ;
    snode *q = s ;
    cout << "Enter sid : "; cin >>sid ;
    cout << "Enter cid : "; cin >> cid ;
    while (q != NULL && q->sID != sid ){
        q = q->nextstd ;
    }
    if (q == NULL)cout << "student not found"<<endl;
    else {
        cnode * c  = q->firstcrs ;
        cnode * r = NULL ;
        while (c != NULL && c->cID != cid){
            r = c  ;
            c = c->nextcrs ;
        }
        if (c == NULL )cout <<q->fname << q->lname << " is not this lessen"<<endl;
        else {
            r->nextcrs = c->nextcrs ;
            c->nextcrs = NULL ;
            delete c ;
        }
    }
    return s ;



}

int main()
{
    snode *s;
    int flag  ;
    bool Flag = true ;
    while(Flag){
        cout << "1.add student"<<endl;
        cout << "2.search whit id "<<endl;
        cout << "3.delete whit id "<<endl;
        cout << "4.add lesson "<<endl;
        cout << "5. list of Attendance"<<endl;
        cout << "6. delete lessen for student"<<endl;
        cout << "and or for Exit "<<endl;
        cin >> flag ;
        switch (flag)
        {
        case 1:
            s = gs(s) ;
            break;
        case 2:
            serchstd(s) ;
            break;
        case 3:
            deletestd(s );
            break;
        case 4:
            addc(s);
            break;
        case 5:
            Attendancel ;
            break;
        case 6:
            s = dellesson(s) ;
        break;

        default:
            return 0 ;
            break;
        }
    }



    return 0;
}
