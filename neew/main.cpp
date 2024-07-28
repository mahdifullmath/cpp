#include <iostream>

using namespace std;

#include "algorithm"
#include <list> // for list


class treasure {
public:
    string Name;
    int Mean;
    int Identifier;
};

list<treasure> tot;

void insert(const string &name, int mean, int identifier) {
    tot.push_front({name, mean, identifier});
}

void show_menu() {
    cout << "---------------------Coding By MHF&^%---------------------MahdiFullMath" << endl;
    cout << "Please Choose One Option" << endl;
    cout << ">>>>Print Main Info<(:p)>" << endl;
    cout << ">>>>Insert New Info<(:i)>" << endl;
    cout << ">>>>Search via Identifier<(:s)>" << endl;
    cout << ">>>>Sort Via Name<(:sN)>" << endl;
    cout << ">>>>exit<(:e)>" << endl;
    cout << ">>>>Try>>>> ";
}

void search() {
    int identifier;
    cout << "Please Enter Identifier: ";
    cin >> identifier;
    for (int i = 0; i < tot.size(); i++) {
        auto iteName = tot.begin();
        advance(iteName, i);
        if (iteName->Identifier == identifier) {
            cout << "Name: " << iteName->Name << " ";
            cout << ",Mean: " << iteName->Mean << " ";
            cout << ",Identifier: " << iteName->Identifier << " " << endl;
            break;
        }
    }
}

void sort() {
    list<string> name;
    for (int i = 0; i < tot.size(); i++) {
        auto iteName = tot.begin();
        advance(iteName, i);
        name.push_front(iteName->Name);
    }
    name.sort();
    for (int i = 0; i < name.size(); i++) {
        auto iteName_name = name.begin();
        advance(iteName_name, i);
        for (int j = 0; j < tot.size(); j++) {
            auto iteName_tot = tot.begin();
            advance(iteName_tot, j);
            if (iteName_tot->Name == *iteName_name) {
                cout << "Name: " << iteName_tot->Name << " ";
                cout << ",Mean: " << iteName_tot->Mean << " ";
                cout << ",Identifier: " << iteName_tot->Identifier << " " << endl;
            }
        }
    }
}

void Print() {
    for (auto &i: tot) {
        cout << "Name: " << i.Name << " ";
        cout << ",Mean: " << i.Mean << " ";
        cout << ",Identifier: " << i.Identifier << " " << endl;
    }
}

void Decider(const string &command) {
    if (command == ":p") {
        Print();
    } else if (command == ":i") {
        string name;
        int mean, iden;
        cout << "Your Name is: ";
        cin >> name;
        cout << "Your Mean is: ";
        cin >> mean;
        cout << "Your Identifier is: ";
        cin >> iden;
        insert(name, mean, iden);
    } else if (command == ":s") {
        search();
    } else if (command == ":sN") {
        sort();
    } else if (command == ":e") {
        exit(0);
    }
}

void input_checker() {
    string c;
    cin >> c;
    Decider(c);
}


int main() {
//    tot.push_front({"name", 12, 32});
//    tot.push_front({"mko", 12, 32});
//    tot.push_front({"ali", 12, 32});
    sort();
    while (true) {
        show_menu();
        input_checker();
    }
}
