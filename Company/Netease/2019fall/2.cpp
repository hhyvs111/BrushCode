#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	int left;
	int right;
};

int main() {
	int n;
	cin >> n;
	while(n--) {
        int k;
        cin >> k;
        vector<node> tree(k);
        //用来找根节点
        vector<int> num(k, 0);
        for(int i = 0;i < k;i++) {
            cin >> tree[i].val >> tree[i].left >> tree[i].right;
            if(tree[i].left != -1)
                num[tree[i].left] = 1;
            if(tree[i].right != -1)
                num[tree[i].right] = 1;
        }
        int root = -1;
        for(int i = 0;i < k;i++) {
            if(num[i] == 0){
                root = i;
                break;
            }
        }
        vector<int> treeSum;
        queue<node> q;
        q.push(tree[root]);
        //层次遍历
        while(!q.empty()) {
            int size = q.size();
            int cnt = 0;
            for(int i = 0;i < size;i++) {
                node head = q.front();
                q.pop();
                cnt += head.val;
                if(head.left != -1){
                	q.push(tree[head.left]);
                }
                if(head.right != -1){
                	q.push(tree[head.right]);
                }
            }
            treeSum.push_back(cnt);
        }
        bool ans = true;
        for(int i = 0;i < treeSum.size() - 1;i++) {
        	if(treeSum[i+1] < treeSum[i]){
        		ans = false;
        		break;
        	}
        }
        if(ans)
        	cout << "YES" << endl;
        else
        	cout << "NO" << endl;
        	
	}
    return 0;
}