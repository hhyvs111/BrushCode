#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;

	vector<vector<int>> grid;
	int m;
	for(int i = 0;i < n;i++) {
		string str;
		getline(cin,str);
		// cout << str << endl;
		vector<int> nums;
		istringstream is(str);
        int in;
        char ch;
        while(is >> in) {
            nums.push_back(in);
            is >> ch;
        }
        grid.push_back(nums);
        m = nums.size();
	}


	for(int i = 1;i < m;i+=2) {
		for(int j = 1;j < n;j++) {
			if(grid[i][j] == 0){
				
			}
			if(grid[i][j] != 0 && x != j){
				if(grid[i][x] == 0)
					grid[i][x] = grid[i][j];
				else {
					if(grid[i][x] == grid[i][j]){

						grid[i][j] = 0;
						x++;
					}
					else
						x++;
				}
			}
		}
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m - 1;j++) {
			cout << grid[i][j] << " ";
		}
		cout << grid[i][m - 1] << endl;
	}
	return 0;

}