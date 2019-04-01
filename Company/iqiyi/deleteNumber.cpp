#include<bits/stdc++.h>
using namespace std;
// long long DeleteDigits(string A, long long  k) {
		
//     int ResultSize = A.size() - k;
//     if(ResultSize == 0) 
//     	return 0;
// 	if(ResultSize == 1)
// 		return stoi(A);
// 	int last = 0;//上一次的位置
// 	char NowMin = 0;
// 	string Result;
// 	for(int i = 0; i != ResultSize; i++)
// 	{
// 		NowMin = '9' + 1;
// 		for(int j = last; j != k+i+1; j++)
// 		{
// 			if(A[j] < NowMin)
// 			{
// 				NowMin = A[j];
// 				last = j + 1;
// 			}
// 		}
// 		if(NowMin != '0' || Result.size()==0)
// 			Result += NowMin;;
	
// 	}
// 	return stoll(Result);
// }





string deleteKNumbers(string &str, int k)
{
	string::iterator start;
	bool flag;
	for(int i = k; i > 0; --i)
	{
		flag = 0;
		for(start = str.begin(); start < str.end() - 1; ++start)
		{
			if(*start > *(start + 1)) // 每次删除第一个比下一个数字大的数
			{
				str.erase(start);
				flag = 1;
				break;
			}
		}
		if(!flag) //如果所有数字递增，则删除最后几个数字直接返回
		{
			str.erase(str.end() - i, str.end());
			break;
		}
	}
	return str;
}

    // string DeleteDigits(string A, int k) {
    //     string ret;
    //     if(A.empty())
    //         return ret;
    //     ret=A;    
    //     while(k--){
    //         int i=0;
    //         while(i<ret.length()-1&&ret[i]<=ret[i+1])
    //             ++i;
    //         ret=ret.substr(0,i)+ret.substr(i+1);    
    //     }
    //     int i;
    //     for(i=0;ret[i]=='0';++i);
    //     ret=ret.substr(i);
    //     return ret;
    // }
       string DeleteDigits(string A, int k) {
        // wirte your code here
        int size = A.size();
        if (size <= 0 || size < k) {
            return A;
        }
        string result;
        int newSize = 0;
        for (int i = 0; i < size; i++) {
            while (!result.empty() && result.back() > A[i] && newSize < k) {
                result.pop_back();
                newSize++;
            }
            if (A[i] != '0' || !result.empty()) {
                result.push_back(A[i]);
            }
        }
        if (newSize < k) {
            result.resize(result.size() - k + newSize);
        }
        return result;
    }
int main()
{
	string a;
	long long  k;
	while(cin >> a >> k)
	{
		cout << DeleteDigits(a, k) << endl;
		// cout << deleteKNumbers(a, k) << endl;
	} 
	return 0;
}





