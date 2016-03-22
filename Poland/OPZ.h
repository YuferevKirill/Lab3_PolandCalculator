#pragma once
#include "TTStack.h"
//#include "TStack.h"
//#include "TDStack.h"

class OPZ
{
	TTStack<int> s;
	TTStack<double> ds;

	char str[100];
	char out[100];
public:
	OPZ(void);
	~OPZ(void);
	void SetStr(char *s);
	void PrintOut();
	bool Process();
	int Prior(char c);
	double Calculate();
	double Operation(double,double,int);
	void PrintStr();
	bool SetSt();
	double stepen(double,int);

};

