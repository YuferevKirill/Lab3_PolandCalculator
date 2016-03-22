#include "stdio.h"
#include <iostream>
#include "OPZ.h"
using namespace std;

int main()
{

	OPZ opz;
	//opz.SetStr("((1234-713)*22)/3");
	if (opz.SetSt())
	{
		opz.PrintStr();
		if (opz.Process())
		{
			opz.PrintOut();
			double result=opz.Calculate();
			cout<<"calculation result: "<<result<<endl;
		}
	}
	return 0;
}