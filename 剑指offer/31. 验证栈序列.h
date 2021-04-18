typedef struct
{
    int* _a;
    int _size;
    int _capacity;
}Stack;

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

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int pushi = 0;
    int popi = 0;
    Stack st;
    StackInit(&st);


    while(pushi < pushedSize)
    {
        StackPush(&st, pushed[pushi]);
        ++pushi;
        //只有当栈不为空且 栈顶元素 == pop序列当前下标时才pop出这个元素
        while(!StackEmpty(&st) && StackTop(&st) == popped[popi])
        {
            ++popi;
            StackPop(&st);
        }
    }
    //如果最后栈还不为空，证明它匹配不上StackTop，说明序列不匹配，返回false
    //为空的话，就是true
    return StackEmpty(&st);
}
