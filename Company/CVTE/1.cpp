#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        int max = 0;
        for(int i = 0 ; i < str.size();i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                int powNum = 1;
                int sum = 0;
                for(; str[i] >= '0' && str[i] <= '9' && i < str.size();i++ )
                {
                    int num = str[i] - '0';
                    cout << num << endl;
                    sum = sum*powNum + num;
                    cout << sum << endl;
                    powNum = 10;
                }
                if(sum > max)
                    max = sum;
            }
        }
        cout << max << endl;
    }
}