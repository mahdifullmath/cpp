#include <string.h>
#include <iostream>
using namespace std;
struct date{
	int d;
	int m;
	int y; };
	struct kala{
		int bar;
		char name[20];
		int gh;
		date tar;
		};
		 void getkala(kala s[10]){
		 	for(int i=0; i<2;i++){
		 		cin>> s[i].bar;
		 		cin.ignore();
		 		cin.getline (s[i].name,20);
		 		cin>>s[i].gh;
		 	    cin>> s[i].tar.d>>s[i].tar.m>>s[i].tar.y;
		 	}
		 }
	  void displaygh(kala s[10]){
	  	for(int i=0; i<2; i++){
	    	if(s[i].gh>10000){
	    		cout<<s[i].bar<<endl<<s[i].name<<endl<<s[i].gh<<endl<<s[i].tar.d<<"/"<<s[i].tar.m<<"/"<<s[i].tar.y<<endl;
	    	}
	  	}
	  }
	  void chaptar(kala s[10]){
	  	for(int i=0; i<2; i++){
	  	  if(s[i].tar.y==1399&&s[i].tar.m<=7){
	  	  	cout<<s[i].bar<<endl<<s[i].name<<endl<<s[i].gh<<endl<<s[i].tar.d<<"/"<<s[i].tar.m<<"/"<<s[i].tar.y<<endl;
	  	  }
	  	}
	  }
int main(){
	   kala c[10];
	   getkala(c);
	   displaygh(c);
	   chaptar(c);
	   return 0;
}
