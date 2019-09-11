#include<bits/stdc++.h>
using namespace std;
struct movie {
    int m;
    int v;
};

int main(){
    int sm;
    cin >> sm;
    int movieNum;
    cin >> movieNum;
    vector<movie> movies(movieNum+1);
    vector<vector<int>> bag(movieNum+1, vector<int>(sm+1, 0));

    for(int i = 1;i <= movieNum;i++) {
    	cin >> movies[i].m;
    }
    for(int i = 1;i <= movieNum;i++) {
    	cin >> movies[i].v;
    }
    // sort(movies.begin(), movies.end(), cmp);
    // for(int i = 0;i < movieNum;i++) {
    // 	cout << movies[i].m << " " <<  movies[i].v << endl;
    // }


    for(int i = 1;i <= movieNum;i++) {
    	for(int j = 1;j <= sm;j++) {
    		if(j >= movies[i].m) {
    			if(movies[i].v + bag[i-1][j - movies[i].m] > bag[i-1][j])
    				bag[i][j] = movies[i].v + bag[i-1][j - movies[i].m];
    			else
    				bag[i][j] = bag[i-1][j];
    		}
    		else
    			bag[i][j] = bag[i-1][j];
    	}

    }

    cout << bag[movieNum][sm] << endl;
    return 0;
    
}