// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     vector<int> v;
//     getline(cin, s);
//     int strSize = s.size();
//     istringstream is(s.substr(1, strSize - 2));
//     int inter;
//     char ch;

//     while (is >> inter)
//     {
//          v.push_back(inter);
//          is >> ch;
//     }
//     // for(int i = 0;i < v.size();i++)
//     // {
//     //     cout << v[i] << endl;
//     // }
//     int d;
//     cin >> d;
//     int len = v.size();
//     int cnt = 0;
//     for(int i = 0;i < len;i++)
//     {
//         for(int j = 0; j < len;j++){
//             if(i == j)
//                 continue;
//             // cout << v[i] << " " << v[j] << endl;
//             int diff = abs(v[i] - v[j]);
//             if(diff <= d)
//                 cnt++;
//         }
//     }
//     double ans =  ((double)cnt / (double)(len * (len - 1)));
//     // cout << cnt << " " << ((len * (len + 1)) / 2) << endl;
//     printf("%lf", ans );
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int d;
    vector<int> v;
    getline(cin, s);
    int strSize = s.size();
    string subStr = s.substr(1, strSize - 2);
    istringstream is(subStr);
    int in;
    char ch;
    while (is >> in)
    {
         v.push_back(in);
         is >> ch;
    }

    cin >> d;
    int len = v.size();
    int cnt = 0;
    for(int i = 0;i < len;i++){
        for(int j = 0; j < len;j++){
            if(i == j)
                continue;
            if(abs(v[i] - v[j]) <= d)
                cnt++;
        }
    }
    int sum = len * (len - 1);
    
    printf("%lf",(double)cnt / (double)sum);
    return 0;
}