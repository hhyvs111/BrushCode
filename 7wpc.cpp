#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while (n--) {
		string strs;
		cin >> strs;
		int len = strs.size();

		int ans = 0;
		int times = len;
	
			for(int i = 1;i <= len;i++) {
				if(strs[i - 1] == 0) continue;
				for(int j = 0; j < len;j++) {
					int min = strs[0];

					if (j + i > len) {
						continue;
					}
					for(int k = j;k < j+i && k < len;k++) {
						// cout << "k:" << k << " " << strs[k] - '0' << " ";
						// cout  << strs[k] - '0' << " ";
						if ((strs[k] - '0') < min) 
							min = strs[k] - '0';
						if (min == 0) break;
					}
					// cout << endl;
					ans += min;
					
				}
			}

			cout << ans << endl;
		}
	return 0;
}
