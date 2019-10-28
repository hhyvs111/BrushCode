#include<bits/stdc++.h>
using namespace std;
int main(){
        char a[] = "abc";
char *b = "abc";
char c[] = {'a', 'b', 'c'};

        if(a == b)
                cout << "a = b" << endl;
        else
                cout << "a != b" << endl;

        if(strcmp(a,c) == 0)
                cout << "b = c" << endl;
        else
                cout << "b != c" << endl;

        cout << sizeof(a) << endl;
        return 0;
}