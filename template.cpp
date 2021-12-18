#include <bits/stdc++.h>

#define int long long
#define double long double
#define kill(text) cout << text << '\n'; return 0
#define ld long double
#define sz(a) ((int)(a.size()))
#define forn(i, n) for (int i = 0; i < n; ++i)
#define vc vector
#define pii pair <int, int>
#define pb push_back

using namespace std;
const int inf = 1e9 + 7;

/* Preferences */
const bool multitests = true;
const bool buff = true;
const int maxsize = 1e3;
int cur_size = 0;
char buffer[maxsize];

mt19937 rnd(1337);
void flush ();
char getchr () {
    return getchar();
}

void putchr (char c) {
    if (buff) {
        if (cur_size + 1 == maxsize)
            flush();
        buffer[cur_size++] = c;
    } else {
        putchar(c);
    }
}

void flush () {
    for (int i = 0; i < cur_size; ++i)
        putchar(buffer[i]);
    cur_size = 0;
}

int readint () {
    char c = getchr();
    int f = 0, x = 0;
    while (!isdigit(c)) {
        f |= c == '-';
        c = getchr();
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchr();
    }
    return x * (f ? -1 : 1);
}

string readstring () {
    string s;
    char c = getchr();
    while (c == ' ' || c == '\n')
        c = getchr();
    while (c != ' ' && c != '\n') {
        s.push_back(c);
        c = getchar();
    }
    return s;
}

void printstring (string &s) {
    for (int i = 0; i < s.size(); ++i)
        putchr(s[i]);
}

void printstringln (string &s) {
    printstring(s);
    putchr('\n');
}

void printstringsp (string &s) {
    printstring(s);
    putchr(' ');
}

void print (int x) {
    if (x < 0) {
        putchar('-');
        print(-x);
    } else {
        if (x == 0) return;
        print(x / 10);
        putchr(x % 10 + '0');
    }
}

void print_arr (vc <int> &a, char del = ' ') {
    for (int &i: a) {
        print(i);
        putchr(del);
    }
}

void println (int x) {
    print(x);
    putchr('\n');
}

void printsp (int x) {
    print(x);
    putchr(' ');
}

void run (int number_of_test) {
    int n = readint();
    vc <vc <int>> a(2);
    forn (i, n) {
        int t = readint();
        a[t % 2].pb(t);
    }
    print_arr(a[0]);
    print_arr(a[1]);
    putchr('\n');
}

signed main ()
{
    int tests = 1;
    if (multitests) {
        tests = readint();
    }
    for (int i = 0; i < tests; ++i) {
        run(i);
    }
    if (buff)
        flush();
}
