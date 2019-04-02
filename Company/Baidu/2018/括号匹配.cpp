#include<bits/stdc++.h>
using namespace std;
int main(){
	//这里只能在开始和结尾处添加括号
	string str;
	while(cin >> str){
		stack<char> s;
		for(int i = 0 ; i < str.size();i++){
			if(str[i] == '['){
				s.push(str[i]);
			}
			else{
				//如果可以匹配直接pop
				if(!s.empty() && s.top() == '[')
					s.pop();
				else
					s.push(']');
			}
		}
		//循环完后看栈里是否还有数据，因为剩下的就是左右不均的状态，只有]]][[[类似这样的存在？
		while(!s.empty()){

			if(s.top() == '[')
				str.append("]");
			else
				str.insert(0, "[");
			s.pop();
		}
		cout << str << endl;
	}
	return 0;
}