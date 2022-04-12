class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
    }
    
    void push(int x) 
    {
        s1.push(x);
    }
    
    int pop() 
    {
        if(!s2.empty())
        {
            int tmp = s2.top();
            s2.pop();
            return tmp;  
        }
        else
        {
            while(!s1.empty())
            {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
            int ret = s2.top();
            s2.pop();
            return ret;
        }
    }
    
    int peek() 
    {
        if(!s2.empty())
        {
            int ret = s2.top();
            return ret;
        }

        while(!s1.empty())
        {
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
        return s2.top();
    }
    
    bool empty() 
    {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */