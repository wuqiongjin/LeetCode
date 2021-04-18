typedef struct
{
    int* _a;
    int _size;
    int _capacity;
}Stack;

typedef struct 
{
    Stack* _dataStack;
    Stack* _assistStack;
} MinStack;

/** initialize your data structure here. */

void StackInit(Stack* st)
{
   

    st->_a = (int*)malloc(sizeof(int)*3);
    st->_capacity = 3;
    st->_size = 0;
}

void CheckCapacity(Stack* st)
{
    if(st->_size == st->_capacity)
    {
        int newCapacity = 2 * st->_capacity;
        st->_a = (int*)realloc(st->_a, sizeof(int)*newCapacity);
        st->_capacity = newCapacity;
    }
}

void StackPush(Stack* st, int val)
{
    CheckCapacity(st);
    st->_a[st->_size++] = val;
}

void StackPop(Stack* st)
{
    st->_size--;
}

int StackTop(Stack* st)
{
    return st->_a[st->_size - 1];
}

bool StackEmpty(Stack* st)
{
    return st->_size == 0 ? true : false;
}

void StackDestory(Stack* st)
{
    free(st->_a);
}



MinStack* minStackCreate() 
{
    MinStack* mst = (MinStack*)malloc(sizeof(MinStack));
    //**************************************************************//
     //这一处别忘了给mst中的2个栈的指针开辟空间（因为我们定义的MinStack中是2个指针变量，它们需要你给它们分配空间）
     //开空间必须在这里开，如果在StackIinit函数中开的话，我们不能传mst->_dataStack，而是传mst。。
     //如果传mst->_dataStack就相当于你传了一个野指针。（它还没被开辟空间，你就传走了）
     //所以你需要在传它之前开辟好空间（初始化的工作交给StackInit）
    mst->_dataStack = (Stack*)malloc(sizeof(Stack));
    mst->_assistStack = (Stack*)malloc(sizeof(Stack));

    StackInit(mst->_dataStack);
    StackInit(mst->_assistStack);
    return mst;
}

void minStackPush(MinStack* obj, int val) 
{
    StackPush(obj->_dataStack, val);
    if(!StackEmpty(obj->_assistStack))
    {
        //进行入栈前的判断，如果该val小于等于 辅助栈中的栈顶元素，入栈
        //这样其实就相当于每个元素都进行了比较，保证当数据栈即使将当前最小的元素Pop了，辅助栈中仍有第二小的元素会顶替
        if(val <= StackTop(obj->_assistStack))
            StackPush(obj->_assistStack, val);
    }
    else
        StackPush(obj->_assistStack, val);       
}

void minStackPop(MinStack* obj) 
{
    if(!StackEmpty(obj->_dataStack))
    {
        int del = StackTop(obj->_dataStack);
        StackPop(obj->_dataStack);
        if(del == StackTop(obj->_assistStack))
        {
            StackPop(obj->_assistStack);
        }
    }
}

int minStackTop(MinStack* obj) 
{
    return StackTop(obj->_dataStack);
}

int minStackGetMin(MinStack* obj) 
{
    return StackTop(obj->_assistStack);
}

void minStackFree(MinStack* obj) 
{
    StackDestory(obj->_dataStack);
    StackDestory(obj->_assistStack);
    free(obj->_dataStack);
    free(obj->_assistStack);
    free(obj);
}

