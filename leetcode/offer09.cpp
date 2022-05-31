class CQueue
{
private:
    stack<int> s1, s2;

public:
    CQueue() {}

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (s1.empty() && s2.empty())
            return -1;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */