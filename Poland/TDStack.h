#pragma once
class TDStack
{
	double *Stack;
	int top;
	int Size;
public:
	TDStack(int Size=100);
	~TDStack(void);

	void Push (double x);
	double Pop ();
	bool IsFull();
	bool IsEmpty();
	double Peek();
};

