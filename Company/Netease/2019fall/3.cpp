#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--){
		int k, m;
		cin >> k >> m;
		vector<int> num(m);
		for(int i = 0;i < m;i++) {
			cin >> num[i];
		}
        if(m==0) {
            cout << 30 / (k+1) << endl;
            continue;
        } else if (k == 0) {
        	cout << 30 << endl;
        	continue;
        }


        int pos = 1;
        int day = 0;
 		while(num[0] - k > pos){
 			cout << "1node:" <<  pos << endl;
 			day++;
 			pos= pos + k + 1;
 		}
 		pos = num[0];
 		//中间情况
		for(int i = 0; i < m-1;i++){
            //间隔大，但是要看i+1和后面的间隔是否还有剩余空间，剩余才能喝
			if(num[i+1] - num[i] > k) {
				pos = num[i];
				// cout << "qujian:" << num[i+1] << " " << num[i] << endl;
				while(num[i+1]-k > pos){
 					cout << "2node:" <<  pos << endl;
					day++;
					pos = pos + k + 1;
				}
                // if((i == m - 2 && 30 - num[i+1] > k))
                //     day--;
                // else

            }
		}
		//剩余情况
		if(num[m - 1] < 30) {
			while(30 - k >= pos){
 				cout << "3node:" <<  pos << endl;
				day++;
				pos = pos + k + 1;
			}
		}
		if(num[m-1] == 30)
			day++;
		cout << day << endl;
	}
	return 0;
}