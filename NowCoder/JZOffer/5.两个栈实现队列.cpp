class Solution
{
    //思路：
    //入队列把数据都输入到栈A，然后出出列的时候把数据都输出到栈B，这样数据就倒过来了，然后弹出B栈的栈顶就实现了出队列。
public:
    //a用来入队列
    void push(int node) {
        stackA.push(node);
    }

    int pop() {
        if(stackB.empty())
        {
            while(!stackA.empty())
            {
                stackB.push(stackA.top());
                stackA.pop();
            }
         
        }
        //和java等不同，c++要先弹出这个栈顶
        int a = stackB.top();
        stackB.top(); 
        return a;
    }
private:
    stack<int> stackA;
    stack<int> stackB;
};