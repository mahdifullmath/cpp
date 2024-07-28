#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int win(char a[]);
int winofoghi(char a[]);
int winorib(char a[]);
int winamoodi(char a[]);
int whofirst(){
    int a;
    srand(time(0));
    a=(rand() % (2 - 1+1)) +1;
    if (a==1)
        printf("player is first!\n");
    else
        printf("computer is first!\n");
    return a;
}
void computerturn(char a[]){
    char x[9];
    for(int i=0;i<9;i++){
        x[i]=a[i];
    }
    for(int i=0;i<9;i++){
        if(x[i]!='X'&&x[i]!='O'){
            x[i]='X';
            if(win(x)==1){
                a[i]='X';
                return;
            }
            x[i]=a[i];

        }
    }
    for(int i=0;i<9;i++){
        if(x[i]!='X'&&x[i]!='O'){
            x[i]='O';
            if(win(x)==1){
                a[i]='X';
                return;
            }
            x[i]=a[i];
        }
    }
    if(x[4]!='X'&&x[4]!='O'){
        a[4]='X';
        return;
    }
    for(int i=0;i<9;i++){
        if(x[i]!='X'&&x[i]!='O'){
            a[i]='X';
            return;
        }
    }

}
int win(char a[]){
    if(winofoghi(a)==1||winamoodi(a)==1||winorib(a)==1){
        return 1;
    }
    return 0;
}
int winorib(char a[]){
    if((a[0]==a[4]&&a[4]==a[8])||(a[2]==a[4]&&a[4]==a[6])){
        return 1;
    }
    return 0;
}
int winamoodi(char a[]){
    if((a[0]==a[3]&&a[3]==a[6])||(a[1]==a[4]&&a[4]==a[7])||(a[2]==a[5]&&a[5]==a[8])){
        return 1;
    }
    return 0;
}
int winofoghi(char a[]){
    if((a[0]==a[1]&&a[1]==a[2])||(a[3]==a[4]&&a[4]==a[5])||(a[6]==a[7]&&a[7]==a[8])){
        return 1;
    }
    return 0;
}
int endgame(char a[]){
    if(winofoghi(a)==1||winamoodi(a)==1||winorib(a)==1){
        return 1;
    }
    else if(a[0]!='1'&&a[1]!='2'&&a[2]!='3'&&a[3]!='4'&&a[4]!='5'&&a[5]!='6'&&a[6]!='7'&&a[7]!='8'&&a[8]!='9'){
        return 3;
    }
    return 0;
}
void game(char a[],int x, int t){
     while ((endgame(a))==0){
        if(x==1){
           x=2;
           printf("%c | %c | %c\n----------\n%c | %c | %c\n----------\n%c | %c | %c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);


           while (1){
                printf("\nchose a number:");
                scanf("%d",&t);

                if(a[t-1]==t+48)
                    break;
                printf("\nthis calum is full!");
           }
            t=t+48;
            for(int i=0;i<9;i++){
                if(a[i]==t){
                    a[i]='O';
                }
            }
            system("cls");
        }
        else if(x==2){
            x=1;
            computerturn(a);
        }
    }
    if (endgame(a)==1&&x==2){
        system("cls");
        printf("%c | %c | %c\n----------\n%c | %c | %c\n----------\n%c | %c | %c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
        printf("\nyou win!");
    }
    else if(endgame(a)==1&&x==1){
        system("cls");
        printf("%c | %c | %c\n----------\n%c | %c | %c\n----------\n%c | %c | %c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
        printf("\nyou lose!");
    }
    else if(endgame(a)==3){
        system("cls");
        printf("%c | %c | %c\n----------\n%c | %c | %c\n----------\n%c | %c | %c\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
        printf("\ndrow!");
    }
}
int main()
{
    int x=0,t;
    x=whofirst();
    char a[9];
    a[0]='1',a[1]='2',a[2]='3',a[3]='4',a[4]='5',a[5]='6',a[6]='7',a[7]='8',a[8]='9';
    game(a,x,t);

    return 0;
}
