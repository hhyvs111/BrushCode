
#include <stdio.h>
#include <string.h>
int a[1005][1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	int n;
	scanf("%d",&n);
	int c;
	int d=0;
	memset(a,0,sizeof(a));
	a[1][0]=1;a[2][0]=1;//第一个和第二个数要先保存下来 
	for(int i=3;i<=n;i++)//从第三个数开始都是等于前两个数的和 
	{
		c=0;//保存余数 
		for(int j=0;j<=d;j++)
		{
			a[i][j]=a[i-1][j]+a[i-2][j]+c;//计算结果 
			c=a[i][j]/10;//将其他的数进位 
			a[i][j]%=10;//将大于10的数要余数 
		}
		while(c!=0)//最后一位要是大于10，需要进位，并且最高位也需要加1！ 
		{
			a[i][++d]=c%10;
			c/=10;
		}
	}
	for(int i=d;i>=0;i--)//输出需要求的数的所有的位所有的值！ 
	{
		printf("%d",a[n][i]);
	}
	printf("\n");
	}
	return 0;
}
