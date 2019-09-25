#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/**
* Welcome to vivo
*/

#define MAX_NUM 101

int diff(vector<int>& vec)
{
    int len = vec.size();
 
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += vec[i];
    }
 
    vector<vector<int>> dp;
    for (int i = 0; i <= len; i++) {
        vector<int>tmp;
        for (int j = 0; j <= sum / 2; ++j) {
            tmp.push_back(0);
        }
        dp.push_back(tmp);
    }
 
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= sum / 2; ++j) {
            if(j>=vec[i-1])dp[i][j] = max(dp[i-1][j],dp[i-1][j-vec[i-1]]+vec[i-1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
 
    return sum - 2*dp[len][sum / 2];
}


int main()
{    
 string str("");
 getline(cin, str);
 vector<int> a(MAX_NUM);
 int i = 0;
 char *p;
 int count = 0;
 
 const char* strs = str.c_str();
 p = strtok((char *)strs, " ");
 while(p)
 {
  a[i] = atoi(p);
  count++;
  p = strtok(NULL, " ");
  i++;
  if(i >= MAX_NUM)
   break;
 }
 
 //int result1 = solution(count, a);
    int result = diff(a);
 cout << result << endl;
 return 0;
}