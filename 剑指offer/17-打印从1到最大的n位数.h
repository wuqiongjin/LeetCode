#pragma once
#include "头文件.h"

//大数问题


//1.字符串模拟数字加法
//当n=3，打印 1 ~ 999， 因此我们可以判断当最高位+1后是否为0，来看它是否到达最大的数

//对数字进行 + 1，判断是否需要进位以及是否越界

//bool overflow(char* num)
//{
//	//判断是否越界
//	bool isOverflow = false;
//	int nTakeover = 0;
//	int len = (int)strlen(num);
//	//当数字不进位时，此时该for循环只执行1次；(会break出去)
//	//如果涉及进位，进几次位，for循环循环几次;(需要修改满10的位，并且需要将该数字的最高位改成1）
//	//以及判断是否越界
//	for (int i = len - 1; i >= 0; --i)
//	{
//		//取出 i 位的那个数字，然后进行判断是否需要 + 1
//		int nSum = num[i] - '0' + nTakeover;
//		//如果if成立，证明该数字还没有+1
//		if (i == len - 1)
//			++nSum;
//		//判断这个位是否满10了，满10需要进行进位
//		if (nSum == 10)
//		{
//			//>=10有2种情况，一种是普通的进位，另一种是越界
//			//i == 0代表已经判断到最高位了，此时最高位还是处于要进位的状态（最高位的nSum也是>=10），则判断它越界
//			if (i == 0)
//			{
//				isOverflow = true;
//				break;
//			}
//			//普通进位操作
//
//			num[i] = '0';
//			nTakeover = 1;
//		}
//		else//没满10，则break【我们对该数字+1的目的已经达成了】
//		{
//			//对num中i位的数字进行"更新"
//			num[i] = nSum + '0';
//			break;
//		}
//	}
//	return isOverflow;
//}
//
////将num中的数打印出来
//void PrintNum(char* num)
//{
//	int len = (int)strlen(num);
//	int i = 0;
//	int firstNotZero = false;
//	for (i = 0; i < len; ++i)
//	{
//		if (num[i] != '0')
//			firstNotZero = true;
//		if (firstNotZero)
//			cout << num[i];
//	}
//}
//
//void Print1ToMaxNDigits(int n)
//{
//	if (n <= 0)
//		return;
//	//开辟1个字符数组，该字符数组中存放单个数字
//	char* num = new char[n + 1];
//	memset(num, '0', n);
//	num[n] = '\0';
//	//从1开始打印到最大的n位数 --- 每产生1个数字，就将它打印出来
//	while (!overflow(num))
//	{
//		PrintNum(num);
//		cout << " ";
//	}
//	delete[] num;
//}


//方法2. 递归全排列

//这里的PrintNum与前一个方法的print功能完全相同
//void PrintNum(char* num)
//{
//	int len = (int)strlen(num);
//	int i = 0;
//	int firstNotZero = false;
//	for (i = 0; i < len; ++i)
//	{
//		if (num[i] != '0')
//			firstNotZero = true;
//		if (firstNotZero)
//			cout << num[i];
//	}
//}
//
////递归全排列
////
//void Recursive(char* num, int len, int index)
//{
//	//当index == len的时候，就代表index所处的下标已经超出了n的位数，则停止递归，
//	//此时的数字就可以进行打印了(因为前几位已经初始化完成了)
//	if (index == len)
//	{
//		PrintNum(num);
//		cout << " ";
//		return;
//	}
//
//	//从第0位开始全排列
//	//当第0位(也就是最高位)是0时，递归调用下一位，直到index == len时，超出数字的位数，停止递归，并进行打印.
//	for (int i = 0; i <= 9; ++i)
//	{
//		num[index] = i + '0';
//		Recursive(num, len, index + 1);
//	}
//}
//
//void Print1ToMaxNDigits(int n)
//{
//	if (n <= 0)
//		return;
//	char* num = new char[n + 1];
//	num[n] = '\0';
//	int index = 0;
//	//从最高位的0开始递归，当index与len相同时，停止更新数字，然后打印并结束当前递归.
//	Recursive(num, n, index);
//	delete[] num;
//}