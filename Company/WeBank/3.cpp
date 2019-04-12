#include <iostream>
#include <cstring>
#include <sstream>
 
using namespace std;
string dectobin(long long  a) //十进制转换成二进制 
{
    stringstream bin;
    while(a!=0)
    {
        bin<<a%2;
        a=a/2;
    }
    string binary;
    bin>>binary;
    return binary;
}
bool isPalindrome(string a) //判断是否回文 
{
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=a[a.length()-1-i])
            return false;
    }
    return true;
}
int main()
{
    long long int sum=0;
    long long int n;
    cin >> n ;
    for(int i = 1;i<= n ;i+=2)
    {
        stringstream a;
        a<<i;
        if(isPalindrome(a.str()))
        {
            string binary=dectobin(i);
            if(isPalindrome(binary))
            {
                sum++;
                cout<<i<<" "<<binary<<endl;
            }
        }
    }
    cout<<sum;
    return 0;
}

