// #include<bits/stdc++.h>
// using namespace std;
// struct desk
// {
// 	int len;
// 	int energry;
// };

// bool cmp(desk a, desk b)
// {
// 	return a.len < b.len;
// }

// bool check(vector<desk>& desks, int n)
// {
// 	int mid = n / 2;
// 	// cout << desks[mid].len << "  " << desks[n - 1].len << endl;
// 	if(desks[mid].len == desks[n - 1].len)
// 	{
// 		return true;
// 	}
// 	else
// 		return false;
// }

// int main()
// {
// 	int n;
// 	cin >> n;
// 	vector<desk> desks;
// 	for(int i = 0 ; i < n;i++)
// 	{
// 		desk now;
// 		scanf("%d", &now.len);
// 		now.energry = 0;
// 		// cout << now.len << endl;
// 		desks.push_back(now);
// 	}
// 	for(int i = 0 ; i < n; i++)
// 	{
// 		int energry;
// 		scanf("%d", &energry);
// 		desks[i].energry = energry;
// 	}

// 	sort(desks.begin(), desks.end(), cmp);
// 	// for(int i = 0 ; i < n;i++)
// 	// {
// 	// 	cout << desks[i].len << " " << desks[i].energry << endl;
// 	// }
// 	//只有两条腿那么如果不相等那么就要砍掉最小的那条。
// 	//检查是否相等，就是有中间值和最后一个值是否相等，相等则稳定
// 	int len = n;
// 	int ans = 0;
// 	for(int i = 0 ; i < n;i++)
// 	{
// 		if(check(desks, n - i))
// 			break;
// 		else
// 		{
// 			ans += desks[n - i - 1].energry;
// 		}
// 	}
// 	cout << ans << endl;
// 	return 0;

// }


#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
 
int main(int argc, char *argv[])
{
    int n;
    while (cin >> n) {
        vector<int> len, val;
        // 表示某一个长度的桌腿出现的次数
        unordered_map<int, int> ump;
        len .resize(n), val.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> len[i];
            ++ump[len[i]];
        }
        for (int i = 0; i < n; ++i) {
            cin >> val[i];
        }
        // input finished
        int ret = INT_MAX;
        for (auto &ele:ump) {
            // 以var为最终的桌腿的标准
            int var = ele.first;
            // 表示代价
            int cost = 0;
            vector<pair<int, int> > mp;
            for (int i = 0; i < n; ++i) {
                // 凡是比var大的桌腿都割掉,比它小的加入一个集合
                if (len[i] > var) {
                    cost += val[i];//割掉
                } else if (len[i] < var) {
                    // 比var小的桌腿加入mp集合
                    mp.push_back({val[i], i});
                }
            }
            // 将集合里面的元素按照割掉的代价排序
            sort(mp.begin(), mp.end(), [](const pair<int,int> &p1, const pair<int, int> &p2)
            { return p1.first < p2.first;});
            // 长度为 var 总共的桌腿条数
            int sz_var = ump[var];
            // 比var小的桌腿条数
            int sz_mp = mp.size();
            // 割掉小的，留大的
            if (sz_mp < sz_var) {//无需割掉
                ret = min(ret, cost);
            } else {
                // 需要割掉的条数
                int cnt = sz_mp - sz_var + 1;
                // 肯定是mp割前面的
                for (auto it = mp.begin(); it != next(mp.begin(), cnt); ++it) {
                    cost += it->first;
                }
                ret = min(ret, cost);
            }
        }//for
        cout << ret << endl;
    }//while
    return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
using namespace std;
 
bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
 
 
int main(){
    int n;
    vector<int> res;
    while(cin>>n){
        map<int,int> m;
        vector<pair<int,int> > con;
        vector<int> length(n);
        for(int i=0;i<n;i++){
            cin>>length[i];
        }
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            con.push_back(make_pair(length[i],tmp));
            if(m.find(length[i])!=m.end()){
                m[length[i]]++;
            }else{
                m[length[i]]=1;
            }
        }
        sort(con.begin(),con.end(),compare);
         
        int minValue = INT_MAX;
        int last = 0;
        for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
            int tmp = it->second;
            int count = tmp-1;
            if(count<last){
                count = last-count;
            }else{
                count=0;
            }
            int value = 0;
            for(int i=0;i<n;i++){
                if(con[i].first>it->first){
                    value +=con[i].second;
                }
                if(con[i].first<it->first&&count){
                    value+=con[i].second;
                    count--;
                }
                 
            }
            last+=it->second;
            minValue = min(minValue,value);
        }
        cout<<minValue<<endl;
    }
    return 0;
}

链接：https://www.nowcoder.com/questionTerminal/ba2b1a3cf03c460f88f406d69e607292
来源：牛客网
