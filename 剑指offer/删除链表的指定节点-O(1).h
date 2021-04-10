//#pragma once
//#include "头文件.h"
//
////返回删除后的链表的头结点
//
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
// 
////方法1. 可以顺序遍历找到要删的结点，然后删除
//
////方法2. 当删除的结点不是最后1个时，时间复杂度为O(1)；如果是最后1个，时间复杂度O(N)
////思路：将val的下一个结点的值覆盖到自己身上，然后删除下一个结点
//ListNode* deleteNode(ListNode* phead, ListNode* delnode)
//{
//	if (phead == NULL || delnode == NULL)
//		return phead;
//
//	//判断删除的结点不是 尾结点
//	if (delnode->next != NULL)
//	{
//
//	}//链表只有1个结点，且该结点尾要删除的结点
//	else if (delnode == phead)
//	{
//
//	}
//	else//要删除的结点是 尾结点
//	{
//
//	}
//}