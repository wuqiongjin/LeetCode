//#pragma once
//#include "ͷ�ļ�.h"
//
////����ɾ����������ͷ���
//
//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};
// 
////����1. ����˳������ҵ�Ҫɾ�Ľ�㣬Ȼ��ɾ��
//
////����2. ��ɾ���Ľ�㲻�����1��ʱ��ʱ�临�Ӷ�ΪO(1)����������1����ʱ�临�Ӷ�O(N)
////˼·����val����һ������ֵ���ǵ��Լ����ϣ�Ȼ��ɾ����һ�����
//ListNode* deleteNode(ListNode* phead, ListNode* delnode)
//{
//	if (phead == NULL || delnode == NULL)
//		return phead;
//
//	//�ж�ɾ���Ľ�㲻�� β���
//	if (delnode->next != NULL)
//	{
//
//	}//����ֻ��1����㣬�Ҹý��βҪɾ���Ľ��
//	else if (delnode == phead)
//	{
//
//	}
//	else//Ҫɾ���Ľ���� β���
//	{
//
//	}
//}