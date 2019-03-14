#include<bits/stdc++.h>
using namespace std;
set<char> strs;
int main()
{

    string str;
    //扫描法，再用map？

    while(cin >> str)
    {
    	map<char, int> charMap;
    	set<char> charSet;
		for(auto c : str)
		{
			if(c >='A')
			{
				c = (char)tolower(c);
			}
			charMap[c]++;
		}
		char minchar = 'z';
		for(auto c : str)
		{
			if(c >= 'A')
				c = (char)tolower(c);
			if(charMap[c] == 1)
			{
				if(c < minchar)
					minchar = c;
				break;
			}
			else
			{
				if(c < minchar)
					minchar = c;
				if(charSet.find(c) != charSet.end())
					break;
			}
			charSet.insert(c);
		}
		cout << minchar << endl;
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// set<char> strs;
// int main()
// {

//     string str;
//     //扫描法，再用map？
    
//     while(cin >> str)
//     {
//         for(int i = 0;i < str.size();i++)
//         {
//             if(strs.find((char)tolower(str[i])) != strs.end())
//             {
//                 auto it = strs.find((char)tolower(str[i]));
//                 strs.erase(it);
//             }
//             else
//                 strs.insert((char)tolower(str[i]));
//         }
//         auto it = strs.begin();
        
//         cout << (char)tolower(*it) << endl;
//     }
//     return 0;
// }