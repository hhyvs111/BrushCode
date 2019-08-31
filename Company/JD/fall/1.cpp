// #include<bits/stdc++.h>

// using namespace std;


// bool isLow(string str, long i) {

// 	if ( str[i] >= 'a' && str[i] <= 'z')
// 		return true;
// 	return false;


// }

// int main() {
// 	long long  n;
// 	cin >> n;

// 	string str;
// 	cin >> str;

// 	long long cnt = 0;
// 	bool islow = true;
// 	if(isLow(str, 0) != islow){

// 		cnt++;
// 		islow = false;

// 	}
// 	for(long i = 0;i < str.size();i++) {

// 		//不切模式
// 		if( i < str.size() - 2 && isLow(str, i) != isLow(str, i+1) && isLow(str, i) == isLow(str, i+2)) {
// 			cnt+=2;
// 			i++;
// 			continue;
// 		}

// 		//模式一致
// 		if (isLow(str, i) == islow)
// 			cnt++;
// 		else{
// 			islow = !islow;
// 			cnt+=2;
// 		}

// 	}
// 	cout << cnt << endl;
// 	return 0;
		

// }




#include <bits/stdc++.h>
using namespace std;

bool isUp(char c){
    if(c >= 'A' && c <= 'Z')return true;
    return false;
}

char a[1000005];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int ans = n;
    bool r = false;
    int len = 0;
    for(int i = 0;i < n;) {
        char c = a[i];
        len = 1;
        //参数一致则直接遍历
        while(++i < n && isUp(a[i]) == isUp(c)){
            len++;
        }
        
        //len走了很长，如果len小于1，说明是
        if(len > 1){

            if(isUp(c) != r){
                ans++;
                r =! r;
            }
        }else {
       		//如果
            if(isUp(c) != r){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

