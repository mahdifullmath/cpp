#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 1;

int mark[MAXN];
string conds[8] = {
    "is less than",
    "is not less than",
    "is greater than",
    "is not greater than",
    "is a prime",
    "is not a prime",
    "is palindromic",
    "is not palindromic"
};

int reverse(int x) {
    int r = 0;
    while(x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}
int shift_left(int x) {
    if(x < 10) return x;
    int p = 1;
    for(; p <= x ; p *= 10);
    p /= 10;
    return (x - x / p * p) * 10 + x / p;
}
int shift_right(int x) {
    if(x < 10) return x;
    int p = 1;
    for(; p <= x ; p *= 10);
    p /= 10;
    return x % 10 * p + x / 10;
}
int digits_sum(int x) {
    int r = 0;
    while(x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}
int to_int(string s) {
    int r = 0;
    for( auto c: s ) {
        r = r * 10 + c - '0';
    }
    return r;
}
int is_prime(int x) {
    if(x == 1) return 0;
    for( int i = 2 ; i * i <= x ; i ++ )
        if(x % i == 0)
            return 0;
    return 1;
}
int is_palindromic(int x) {
    return x == reverse(x);
}
int eval(string pre, int x) {
    if(pre == "x") {
        return x;
    } else if(pre.substr(0, 7) == "reverse") {
        return reverse(x);
    } else if(pre.substr(0,10) == "shift_left") {
        return shift_left(x);
    } else if(pre.substr(0,11) == "shift_right") {
        return shift_right(x);
    } else if(pre.substr(0, 10) == "digits_sum") {
        return digits_sum(x);
    } else {
        return -1;
    }
}
int calc(int x, string cond, int y) {
    if(cond == "is less than") return x < y;
    if(cond == "is not less than") return x >= y;
    if(cond == "is greater than") return x > y;
    if(cond == "is not greater than") return x <= y;
    if(cond == "is a prime") return is_prime(x);
    if(cond == "is not a prime") return !is_prime(x);
    if(cond == "is palindromic") return is_palindromic(x);
    if(cond == "is not palindromic") return !is_palindromic(x);
}
void Do(string pre, string cond, string suf) {
    for( int i = 1 ; i < MAXN ; i ++ ) {
        int x = eval(pre, i), y = 0;
        if(suf.size() > 0) {
            y = to_int(suf);
        }
        mark[i] &= calc(x, cond, y);
    }
}
void parse(string s) {
    string suffix, prefix;
    int r;
    for( int i = 0 ; i < 8 ; i ++ ) {
        if((r = s.find(conds[i])) != s.npos) {
            prefix = s.substr(0, r-1);
            if(i < 4)
                suffix = s.substr(r + conds[i].size()+1);
            Do(prefix, conds[i], suffix);
        }
    }
}

int main() {
    string s;
    int n;
    cin >> n;
    cin.ignore();
    fill(mark, mark+MAXN, 1);
    for( int i = 0 ; i < n ; i ++ ) {
        getline(cin, s);
        parse(s);
    }
    int ans = 0;
    for( int i = 1 ; i < MAXN ; i ++ ) {
        ans += mark[i];
    }
    int cur = 0;
    for( int i = 1 ; i < MAXN ; i ++ )
        if(!is_prime(i) && shift_left(i) <= 5653)
            cur ++;
    cerr << "cur " << cur << endl;
    cout << ans << endl;
    return 0;
}

