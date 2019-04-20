#include<iostream>
#include<vector>
using namespace std;
 
vector<int> FindTwoOnce(vector<int> num){
    if(num.size()<=2)               //对符合要求的num数组，只有两个元素则直接返回
        return num;
    int res=0;                      //存储数组所有元素异或的结果
    for(int i=0;i<num.size();i++){
        res ^= num[i];
    }
    int index=0;                    //存储异或结果二进制表示中，从右往左第一个为1的下标
    for(int i=0;i<32;i++){
        int temp=res;
        if((temp>>i) & 1 == 1){     //第i位为1
            index=i;
            cout << index << endl;
            break;
        }
    }
    vector<int> result;             //存储问题结果的数组
    result.push_back(0);
    result.push_back(0);
    for(int i=0;i<num.size();i++){
        int tmp = (num[i] >> index);
            cout << tmp << endl;
        if((num[i]>>index) & 1 == 1)//第i位是1的一类
            result[0] ^= num[i];
        else                        //第i位是0的一类
            result[1] ^= num[i];
    }
    return result;
}
 
int main(){
    vector<int> num;
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(5);
    vector<int> result=FindTwoOnce(num);
    cout<<result[0]<<' '<<result[1]<<endl;
    return 0;
}

