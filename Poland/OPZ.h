#pragma once
#include "TStack.h"
#include "TDStack.h"

class OPZ
{
	TStack s;
	TDStack ds;

	char str[100];
	char out[100];
public:
	OPZ(void);
	~OPZ(void);
	void SetStr(char *s);
	void PrintOut();
	void Process();
	int Prior(char c);
	double Calculate();
	double Operation(double,double,int);
	void PrintStr();
	void SetSt();

};

