class MinStack
{
private:
    int minNum = INT_MAX;
    stack<int> s;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (x < minNum)
            minNum = x;
        s.push(x);
        s.push(minNum);
    }

    void pop()
    {
        s.pop();
        // minNum = s.top();
        s.pop();
        if (s.empty())
            minNum = INT_MAX;
        else
            minNum = s.top();
    }

    int top()
    {
        int x = s.top();
        s.pop();
        int x1 = s.top();
        s.push(x);
        return x1;
    }

    int min()
    {
        return s.top();
    }
};

/**
 * @brief 
 * 
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */