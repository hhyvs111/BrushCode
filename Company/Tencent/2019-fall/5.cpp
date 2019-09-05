#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t, k;
    cin >> t >> k;
    vector<int> input(2 * t);
    vector<long long> output(t);
    for (int i = 0; i < t; i++) {
        cin >> input[2 * i] >> input[2 * i + 1];
    }

    for (int index = 0; index < t; index++) {
        int a, b;
        a = input[2 * index];
        b = input[2 * index + 1];

        long long sum = b - a + 1;
        vector<int> arr;
        
        for (int i = 2; i <= b; i++) {
            if (!(i%k)) {
                arr.push_back(i);
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            for (int j = max(a, arr[i]); j <= b; j++) {
                sum += j - arr[i] + 1;
            }
        }
        //cout << sum << endl;
        output[index] = sum;
    }

    for (int i = 0; i < output.size(); i++){
        //long long t=100000007;
        cout << output[i]<< endl;}

    system("pause");
    return 0;
}
