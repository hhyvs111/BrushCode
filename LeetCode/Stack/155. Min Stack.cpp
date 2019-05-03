## 题意
设计一个最小栈，除了包含普通栈的操作之外，还要设计可以获取当前栈最小值的成员函数。

```
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

## 题解
这种类似的栈设计一定是要用到两个栈的，有点类似栈实现队列也是用了两个栈。

额外设置一个栈s2用来存放最小值，s1则正常存放值。

```c++
//我是猜想每次都记录一个最小值的指针，如果要弹出最小值那么用啥数据结构呢？一个vector吗？

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        //先直接push进去，s1和s2允许重叠
        s1.push(x);
        if(s2.empty() || x <= s2.top())
            s2.push(x);
    }
    
    void pop() {
        //如果当前的s1栈顶也是最小值，那么s2也要pop
        if(s1.top() == getMin())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
        
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    //s2专门用来放这个最小值
    stack<int> s2;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```