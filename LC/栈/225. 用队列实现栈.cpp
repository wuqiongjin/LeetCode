//一个队列实现栈
class MyStack {
    queue<int> q1;
public:
    MyStack() {}
    
    void push(int x) 
    {
        q1.push(x);
    }
    
    int pop() 
    {
        int size = q1.size();
        while(--size)
        {
            q1.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q1.pop();
        return tmp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

//class MyStack {
//     queue<int> q1;
//     queue<int> q2;
// public:
//     MyStack() {}
    
//     void push(int x) 
//     {
//         q1.push(x);
//     }
    
//     int pop() 
//     {
//         while(q1.size() != 1)
//         {
//             int tmp = q1.front();
//             q1.pop();
//             q2.push(tmp);
//         }

//         while(!q2.empty())
//         {
//             int tmp = q2.front();
//             q2.pop();
//             q1.push(tmp);
//         }
//         int ret = q1.front();
//         q1.pop();
//         return ret;
//     }
    
//     int top() {
//         return q1.back();
//     }
    
//     bool empty() {
//         return (q1.empty() && q2.empty());
//     }
// };

// class MyStack {
// private:
//     queue<int> q1;
//     queue<int> q2;
// public:
//     MyStack() {}
    
//     void push(int x) 
//     {
//         if(q2.empty())
//             q1.push(x);
//         else
//             q2.push(x);
//     }
    
//     int pop()
//     {
//         if(!q1.empty())
//         {
//             while(q1.size() != 1)
//             {
//                 int ret = q1.front();
//                 q1.pop();
//                 q2.push(ret);
//             }
//             int tmp = q1.front();
//             q1.pop();
//             return tmp;
//         }
//         else
//         {
//             while(q2.size() != 1)
//             {
//                 int ret = q2.front();
//                 q2.pop();
//                 q1.push(ret);
//             }
//             int tmp = q2.front();
//             q2.pop();
//             return tmp;
//         }
//     }
    
//     int top() 
//     {
//         if(!q1.empty())
//             return q1.back();
//         else
//             return q2.back();
//     }
    
//     bool empty() 
//     {
//         return (q1.empty() && q2.empty());
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */