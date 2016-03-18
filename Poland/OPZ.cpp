#include <string.h>
#include <iostream>

#include "OPZ.h"
#include "TDStack.h"
#include "TStack.h"

using namespace std;

OPZ::OPZ(void)
{
}


OPZ::~OPZ(void)
{
}

void OPZ::SetStr(char *s)
{
	strcpy_s(str,s);
}

void OPZ::SetSt()
{
	int i=0,k1=0,k2=0;

	cout<<"Enter expression!"<<endl;
	while(str[i-1]!='.')
	{
		cin>>str[i];	
		if (str[i]<'('||str[i]>'9'||str[0]=='+'||str[0]=='-'||str[0]=='/'||str[0]=='*')
		{
			throw "bad";
			cout<<"bad symbol.Please continue with correct symbol:"<<endl;
		}	
		else
			i++;
	}
	str[i-1]='\0';
}

void OPZ::PrintOut()
{
	cout<<"postfix string: "<<out<<endl;
}

void OPZ::Process()
{
	int k=0;

	for (int i=0;str[i]!=0;i++)
	{
		if (str[i]>='0'&&str[i]<='9')// операнды переписываются в выходную строку
		{
			out[k]=str[i];
			k++;
		}
		else 
		{
			if (out[k-1]!=' ') out[k++]=' ';

			if(s.IsEmpty())//первая операция помещается в стек
			{
				s.Push(str[i]);
			}
			else 
			{
				if (str[i]=='(')//открывающаяся скобка идет в стек
				{
					s.Push(str[i]);
					continue;
				}

				if(str[i]==')')//нашли закрывающуюся
				{
					int pr=s.Peek();
					while (pr!='(') //ищем парную открывающуюся
					{
						out[k]=s.Pop();
						k++;
						if (out[k-1]!=' ') out[k++]=' ';


						if (s.IsEmpty())
						{

							printf("skobki neparnie");
							break;
						}
						pr=s.Peek();
					}
					pr=s.Pop();// убираем из стека открывающуюся скобку
					//if (out[k-1]!='.') out[k++]='.';
					continue;
				}
				//if (out[k-1]!='.') out[k++]='.';

				int pr=s.Peek();
				while (Prior(pr)>=Prior(str[i])) //Операция выталкивает из стека все операции с большим или равным
												 //приоритетом в выходную строку
				{
					out[k]=s.Pop();
					k++;
					if (out[k-1]!=' ') out[k++]=' ';

					if (s.IsEmpty())
						break;
					pr=s.Peek();
				}
				s.Push(str[i]);
			}
		}
	}
	if (out[k-1]!=' ') out[k++]=' ';

	while(!s.IsEmpty())
	{
		out[k]=s.Pop();
		k++;
		if (out[k-1]!=' ') out[k++]=' ';
	}
	out[k]=0;
}

int OPZ::Prior(char c)
{
		char p[6][2]=
	{
		{'(',0},{')',1},{'+',2},{'-',2},{'*',3},{'/',3}
	};
	for (int i=0;i<6;i++)
	{
		if (c==p[i][0])
			return p[i][1];
	}
	return -1;
}

double OPZ::Calculate()
{
	for (int i=0;out[i]!=0;i++)
	{
		if (out[i]==' ')
			continue;

		if (out[i]>='0'&&out[i]<='9')
		{
			double num=0;
			int ten=10;
			while (out[i]!=' ')
			{
				num=num*ten+(out[i]-'0');
				i++;
			}

			ds.Push(num);
		}
		else 
		{
			double Op2=ds.Pop();
			double Op1=ds.Pop();
			double result=Operation(Op1,Op2,out[i]);
			ds.Push(result);
		}
	}
	return ds.Pop();
}

double OPZ::Operation(double Op1,double Op2,int znak)
{
	switch (znak)
	{
	case '+':
		return Op1+Op2;
	case '-':
		return Op1-Op2;
	case '*':
		return Op1*Op2;
	case '/':
		if (Op2==0)
		{
			cout<<"divide by 0\n";
			return 0;
		}
		return Op1/Op2;
	}
	return 0;
}

void OPZ::PrintStr()
{
	cout<<"infix string: "<<str<<endl;
}

