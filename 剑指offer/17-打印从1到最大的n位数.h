#pragma once
#include "ͷ�ļ�.h"

//��������


//1.�ַ���ģ�����ּӷ�
//��n=3����ӡ 1 ~ 999�� ������ǿ����жϵ����λ+1���Ƿ�Ϊ0���������Ƿ񵽴�������

//�����ֽ��� + 1���ж��Ƿ���Ҫ��λ�Լ��Ƿ�Խ��

//bool overflow(char* num)
//{
//	//�ж��Ƿ�Խ��
//	bool isOverflow = false;
//	int nTakeover = 0;
//	int len = (int)strlen(num);
//	//�����ֲ���λʱ����ʱ��forѭ��ִֻ��1�Σ�(��break��ȥ)
//	//����漰��λ��������λ��forѭ��ѭ������;(��Ҫ�޸���10��λ��������Ҫ�������ֵ����λ�ĳ�1��
//	//�Լ��ж��Ƿ�Խ��
//	for (int i = len - 1; i >= 0; --i)
//	{
//		//ȡ�� i λ���Ǹ����֣�Ȼ������ж��Ƿ���Ҫ + 1
//		int nSum = num[i] - '0' + nTakeover;
//		//���if������֤�������ֻ�û��+1
//		if (i == len - 1)
//			++nSum;
//		//�ж����λ�Ƿ���10�ˣ���10��Ҫ���н�λ
//		if (nSum == 10)
//		{
//			//>=10��2�������һ������ͨ�Ľ�λ����һ����Խ��
//			//i == 0�����Ѿ��жϵ����λ�ˣ���ʱ���λ���Ǵ���Ҫ��λ��״̬�����λ��nSumҲ��>=10�������ж���Խ��
//			if (i == 0)
//			{
//				isOverflow = true;
//				break;
//			}
//			//��ͨ��λ����
//
//			num[i] = '0';
//			nTakeover = 1;
//		}
//		else//û��10����break�����ǶԸ�����+1��Ŀ���Ѿ�����ˡ�
//		{
//			//��num��iλ�����ֽ���"����"
//			num[i] = nSum + '0';
//			break;
//		}
//	}
//	return isOverflow;
//}
//
////��num�е�����ӡ����
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
//	//����1���ַ����飬���ַ������д�ŵ�������
//	char* num = new char[n + 1];
//	memset(num, '0', n);
//	num[n] = '\0';
//	//��1��ʼ��ӡ������nλ�� --- ÿ����1�����֣��ͽ�����ӡ����
//	while (!overflow(num))
//	{
//		PrintNum(num);
//		cout << " ";
//	}
//	delete[] num;
//}


//����2. �ݹ�ȫ����

//�����PrintNum��ǰһ��������print������ȫ��ͬ
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
////�ݹ�ȫ����
////
//void Recursive(char* num, int len, int index)
//{
//	//��index == len��ʱ�򣬾ʹ���index�������±��Ѿ�������n��λ������ֹͣ�ݹ飬
//	//��ʱ�����־Ϳ��Խ��д�ӡ��(��Ϊǰ��λ�Ѿ���ʼ�������)
//	if (index == len)
//	{
//		PrintNum(num);
//		cout << " ";
//		return;
//	}
//
//	//�ӵ�0λ��ʼȫ����
//	//����0λ(Ҳ�������λ)��0ʱ���ݹ������һλ��ֱ��index == lenʱ���������ֵ�λ����ֹͣ�ݹ飬�����д�ӡ.
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
//	//�����λ��0��ʼ�ݹ飬��index��len��ͬʱ��ֹͣ�������֣�Ȼ���ӡ��������ǰ�ݹ�.
//	Recursive(num, n, index);
//	delete[] num;
//}