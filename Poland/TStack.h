#pragma once
class TStack
{
	int *Stack;
	int top;
	int Size;
public:
	TStack(int Size=100);
	~TStack(void);

	void Push (int x);
	int Pop ();
	bool IsFull();
	bool IsEmpty();
	int Peek();
};

