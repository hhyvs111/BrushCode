#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    char line[250];
    // 循环读入多行数据
    while (cin.getline(line, 250)) {
        string str = "";
        char cstr[20];
        int k = 0;
        sscanf(line, "%s %d", cstr, &k);
        str = cstr;
        if(str.size() - k == 0)
            {
                cout << 0 << endl;
                continue;
            }
        int pos = 0;
        int len = k;
        int min = INT_MAX;
        int min_pos = pos;
        while (true)
        {
            if (len >= str.length() - pos)
            {
                str.erase(pos, len);
                break;
            }
            min = INT_MAX;
            min_pos = pos;
            for (int i = pos; i <= pos + len; i++)
            {
                if (str[i] - '0' < min)
                {
                    min = str[i] - '0';
                    min_pos = i;
                }
            }
            len = len - (min_pos - pos);
            str.erase(pos, min_pos - pos);
            pos++;
        }
        int cut = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '0')
            {
                cut = i;
                break;
            }
        }
        str.erase(0, cut);

        int zero = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0')
            {
                zero++;;
            }
            else break;
        }
        // cout << str.size() << endl;
        // cout << " " << zero << endl;
        if(zero != 0)
            cout << str.substr(zero - 1, str.size() - zero + 1) << endl;
        else
         cout << str << endl;
    }
    return 0;
}