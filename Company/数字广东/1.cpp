#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    // cout << str<< endl;
    int sum;
    cin >> sum;
    str = str.substr(1, str.size() - 1);
    // cout << str<< endl;
    stringstream s1(str);
    vector<int> nums;
    //以delim为截止
    //这个getline真的是个神器啊！
    int num;
    char ch;

    while(s1 >> num){
        nums.push_back(num);
        s1 >> ch;
    }
    // for(int i = 0; i < nums.size();i++) {
    //     cout << nums[i] << endl;
    // }
    for(int i = 0; i < nums.size() - 1;i++) {
        for(int j = i+1; j < nums.size();j++) {
            if(nums[i] + nums[j] == sum){
                cout << "[" << i << ", " << j << "]" << endl;
                return 0;
            }
        }
    }
    return 0;
}