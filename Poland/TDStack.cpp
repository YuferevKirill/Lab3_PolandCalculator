#include "TDStack.h"

TDStack::TDStack(int s)
{
	Size=s;
	Stack = new double [s];
	top = 0;
}


TDStack::~TDStack(void)
{
	if (Stack!=0)
		delete []Stack;
}

void TDStack::Push(double x)
{
	if (top==Size)
	{
		throw "stack is full";
	}
	Stack[top]=x;
	top++;
}

double TDStack::Pop()
{
	if (top==0)
	{
		throw "stack is empty";
	}
	top--;
	return Stack[top];
}

double TDStack::Peek()
{
	if (top==0)
	{
		throw "stack is empty";
	}
	return Stack[top-1];
}

bool TDStack::IsFull()
{
	if (top==Size)
		return true;
	return false;
}

bool TDStack::IsEmpty()
{
	if (top==0)
		return true;
	return false;
}