int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    //必须先判断是否为NULL。注意这里不能用 矩阵的大小去判断，因为 *matrixColSize为空指针NULL，无法解引用去求大小。。。
    if(matrixSize == 0 || *matrixColSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int l = 0;
    int r = *matrixColSize - 1;
    int t = 0;
    int b = matrixSize - 1;
    *returnSize = (r + 1) * (b + 1); 
    int* res = (int*)malloc(sizeof(int)*(*returnSize));

    int i = 0;
    int index = 0;
    //定义4个边界，l，r，t，b
    while(1)
    {
        for(i = l; i <= r; ++i)
        {
            res[index++] = matrix[t][i];
        }
        if(++t > b)
            break;
        for(i = t; i <= b; ++i)
        {
            res[index++] = matrix[i][r];
        }
        if(--r < l)
            break;
        for(i = r; i >= l; --i)
        {
            res[index++] = matrix[b][i];
        }
        if(--b < t)
            break;
        for(i = b; i >= t; --i)
        {
            res[index++] = matrix[i][l];
        }
        if(++l > r)
            break;
    }
        return res;
}