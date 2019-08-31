#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<stdio.h>
#include <algorithm>


using namespace std;

int main()
{
vector<int> vec;
string str;
getline(cin,str);
istringstream is(str);
int temp;
char ch;
while(is>>temp)
{
vec.push_back(temp);
is>>ch;
}
int index = vec.size();

cout<<"count"<<index<<endl;

int k;
cin>>k;
int x;
cin>>x;
vec.push_back(x);
sort(vec.begin(),vec.end());


int fi;
for(int i=0;i<index;i++)
{
if(vec[i] == x)
{
fi = i;
}
}

vector<int> t;
int i = fi-1;
int j = fi+1;

while(k--)
{
if(i==0&&j==index-1)
break;
else if(i==0)
{
t.push_back(vec[j++]);
}
else if(j==index-1)
{
t.push_back(vec[i--]);
}
else if((vec[i]-x)>abs(vec[j]-x))
{
t.push_back(vec[i--]);
}
else if((vec[i]-x)<abs(vec[j]-x))
{
t.push_back(vec[j++]);
}
else
{
t.push_back(vec[i--]);
}
}
int r = t.size();
for(int o = 0;o<r;o++)
{
cout<<t[o]<<endl;
}

}