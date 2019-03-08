#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        int maxSize = 0;
        int nowSize = 1;
        for(int i = 0; i < str.size() - 1;i++)
        {
            if(str[i] != str[i+1])
                nowSize++;
            else
                nowSize = 1;
            maxSize = nowSize > maxSize ? nowSize : maxSize;
        }
        printf("%d\n", maxSize);
    }
    return 0;
}