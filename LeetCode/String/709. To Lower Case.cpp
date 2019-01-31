class Solution {
public:
    string toLowerCase(string str) {
        //转换大小写
        for(int i = 0 ; i < str.size();i++)
        {
            if( str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;
        }
        //for循环使用引用才能改变值，不然的话是迭代器？
        for (char& c : str) 
//         for(char i : str)
//         {
//             cout << i << endl;
//             if(i >= 'A' && i <= 'Z')
//             {
//                 cout << (int)i << endl;
//                 i = i + 'z' - 'a';
//             }
            
//         }
        return str;
    }
};