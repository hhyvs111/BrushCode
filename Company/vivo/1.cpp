#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**
 * Welcome to vivo !
 */
 
int solution(int a[], int N)
{
    int ans = 0;
    if(N == 0)
        return 0;
        // TODO Write your code here
    int reach = a[0];
    for(int i = 1;i < N && reach >= i;i++){
        if(i + a[i] > reach){
            ans++;
            reach = i + a[i];
        }
    }
    if(reach >= N - 1)
        return ans;
    else
        return -1;
}

int main()
{
	string str("");
	getline(cin, str);
	int a[2000];
	int i = 0;
	char *p;
	int count = 0;
	
	const char* strs = str.c_str();
	p = strtok((char *)strs, " ");
	while(p)
	{
		a[i] = atoi(p);
		count++;
		p = strtok(NULL, " ");
		i++;
		if(i >= 2000)
			break;
	}

	int num = solution(a, count);
	cout << num << endl;
	return 0;
}