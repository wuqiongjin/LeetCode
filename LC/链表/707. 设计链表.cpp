//就很恶心，这题。。。。太恶心了，index从0开始的
//还有超过链表长度的index不插入，但是负数index就可以头插...实在是无语了
struct mListNode
{
    int _val;
    mListNode* _prev;
    mListNode* _next;

    mListNode(int val = 0)
        :_val(val),
         _prev(nullptr),
         _next(nullptr)
    {}
};


class MyLinkedList {
private:
    mListNode* _head;
public:
    MyLinkedList() 
    {
        mListNode* DummyHead = new mListNode();
        DummyHead->_next = DummyHead;
        DummyHead->_prev = DummyHead;
        
        _head = DummyHead;
        //头结点永远指向的是DummyHead!!!但是头结点不存放数据
        //DummyHead->_next指向真正存放数据的第一个结点
        //DummyHead->_prev指向tail
    }
    
    int get(int index) 
    {
        mListNode* cur = _head->_next;
        while(index > 0 && cur != _head)
        {
            cur = cur->_next;
            --index;
        }

        if(index == 0 && cur != _head)
            return cur->_val;
        return -1;
    }
    
    void addAtHead(int val)
    {
        mListNode* newNode = new mListNode(val);
        mListNode* Next = _head->_next;

        newNode->_next = Next;
        newNode->_prev = _head;
        Next->_prev = newNode;
        _head->_next = newNode;
    }
    
    void addAtTail(int val) 
    {
        mListNode* newNode = new mListNode(val);
        mListNode* Next = _head;
        mListNode* Prev = _head->_prev;

        newNode->_next = Next;
        newNode->_prev = Prev;
        Next->_prev = newNode;
        Prev->_next = newNode;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index < 0)
        {
            addAtHead(val);
            return;
        }

        mListNode* newNode = new mListNode(val);
        mListNode* cur = _head->_next;
        while(index > 0 && cur != _head)
        {
            --index;
            cur = cur->_next;
        }

        if(cur == _head)
        {
            if(index == 0)
                addAtTail(val);
            return;
        }
        else
        {
            mListNode* Prev = cur->_prev;
            newNode->_next = cur;
            newNode->_prev = Prev;

            Prev->_next = newNode;
            cur->_prev = newNode;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        mListNode* cur = _head->_next;

        while(cur != _head && index > 0)
        {
            --index;
            cur = cur->_next;   
        }

        if(index == 0 && cur != _head)
        {
            mListNode* Prev = cur->_prev;
            mListNode* Next = cur->_next;
            Prev->_next = Next;
            Next->_prev = Prev;
            delete cur;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */