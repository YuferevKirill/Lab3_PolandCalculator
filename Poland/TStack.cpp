#include "TStack.h"


TStack::TStack(int s)
{
	Size=s;
	Stack = new int [s];
	top = 0;
}


TStack::~TStack(void)
{
	if (Stack!=0)
		delete []Stack;
}

void TStack::Push(int x)
{
	if (top==Size)
	{
		throw "stack is full";
	}
	Stack[top]=x;
	top++;
}

int TStack::Pop()
{
	if (top==0)
	{
		throw "stack is empty";
	}
	top--;
	return Stack[top];
}

int TStack::Peek()
{
	if (top==0)
	{
		throw "stack is empty";
	}
	return Stack[top-1];
}

bool TStack::IsFull()
{
	if (top==Size)
		return true;
	return false;
}

bool TStack::IsEmpty()
{
	if (top==0)
		return true;
	return false;
}