class Solution {
public:
	//这里要直接修改这个str
	void replaceSpace(char *str,int length) {
        int blankCnt = 0;
        int cnt = 0;
        for(int i = 0;i < length; i++)
        {
            if(str[i] == ' ')
            {
                blankCnt++;
            }
        }
        //直接分配多一个字符
        char newStr[length + blankCnt*3 + 1]; //
        for(int i = 0;i < length;i++)
        {
            if(str[i] == ' ')
            {
                newStr[cnt++] = '%';
                newStr[cnt++] = '2';
                newStr[cnt++] = '0';
            }
            else
            {
                newStr[cnt++] = str[i];
            }
        }
        newStr[cnt] = '\0';
        strcpy(str, newStr);
	}
};
//这样做很耗时，虽然也是o(n)实现，