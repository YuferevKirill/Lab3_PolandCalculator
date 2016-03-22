#pragma once
#ifndef __TTSTACK_H__
#define __TTSTACK_H__

#include<iostream>

using namespace std;

template <class ValType>
class TTStack
{
	ValType *TeamStack;
	int Top;
	int Size;
public:
	TTStack(int Size = 100);
	~TTStack();
	void Push(ValType x);
	bool isFull();
	ValType Pop();
	ValType Peek();
	bool IsEmpty();
};

template <class ValType>
TTStack<ValType>::TTStack(int n)
{
	Size=n;
	Top=0;
	if (Size < 0)
		throw"error";
	TeamStack = new ValType[Size];
}

template <class ValType>
TTStack<ValType>::~TTStack()
{
	delete[] TeamStack;
}

template <class ValType>
void TTStack<ValType>::Push(ValType x)
{
	if (isFull())
		throw"error!";
	TeamStack[Top] = x;
	Top++;

}

template <class ValType>
bool TTStack<ValType>::isFull()
{
	return(Top >= Size);
}

template <class ValType>
ValType TTStack<ValType>::Pop()
{
	if (IsEmpty())
		throw"error!";
	Top--;
	return TeamStack[Top];
}

template <class ValType>
bool TTStack<ValType>::IsEmpty()
{
	if (Top==0)
		return true;
	return false;
}

template <class ValType>
ValType TTStack<ValType>::Peek()
{
	if (IsEmpty())
		throw "error!";
	return TeamStack[Top-1];
}

#endif