#include <string.h>
#include <iostream>

#include "OPZ.h"
//#include "TTStack.h"
//#include "TDStack.h"
//#include "TStack.h"

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

bool OPZ::SetSt()
{
	int i=0;
	//int k1=0,k2=0;

	cout<<"Enter expression!"<<endl;
	//while(str[i-1]!='.' && str[i-1]!='\n')
	//{
	//	cin>>str[i];
	//	//if (str[i]<'('||str[i]>'9'||str[0]=='+'||str[0]=='-'||str[0]=='/'||str[0]=='*')
	//	//{
	//	//	//throw "bad";
	//	//	cout<<"bad symbol.Please continue with correct symbol:"<<endl;
	//	//}	
	//	//else
	//		i++;
	//}
	//str[i-1]='\0';
	cin>>str;

	char Op[]="-+*/^";
	for(int i=1;str[i]!=0;i++)
	{
		if(strchr(Op, str[i])) //если нашли знак из Oр
			if(strchr(Op, str[i-1])) //если предыдущий знак из Oр тоже операция
			{
				if(str[i]!=str[i-1])
				{
					cout<<"incorrect string"<<endl;
					return false;
				}
			}
	}
	return true;
}

void OPZ::PrintOut()
{
	cout<<"postfix string: "<<out<<endl;
}

bool OPZ::Process()
{
	int k=0;

	for (int i=0;str[i]!=0;i++)
	{
		if (str[i]>='0'&&str[i]<='9'||str[i]=='.')// операнды переписываются в выходную строку
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
					try
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
					}
					catch (char *s)
					{
						cout<<"  bad symbol!"<<endl;
						return false;
					}

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
		if(s.Peek()=='(')
		{
			cout<<"skobki neparnie!"<<endl;
			return false;
		}

		out[k]=s.Pop();
		k++;
		if (out[k-1]!=' ') out[k++]=' ';
	}
	out[k]=0;
	return true;
}

int OPZ::Prior(char c)
{
	char p[7][2]=
	{
		{'(',0},{')',1},{'+',2},{'-',2},{'*',3},{'/',3},{'^',4}
	};
	for (int i=0;i<7;i++)
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
			double num=0;//целая часть 
			double drob=0;//дробная часть 
			double ten=10;
			while (out[i]!=' '&&out[i]!='.')
			{
				num=num*ten+(out[i]-'0');
				i++;
			}
			if(out[i]=='.')//есть дробная часть
			{
				i++;
				while (out[i]!=' '&&out[i]!='.')
				{
					drob=drob+(out[i]-'0')/ten;
					ten=ten*10;
					i++;
				}
				if(out[i]=='.')
				{
					cout<<"incorrect float number"<<endl;
					return 0;
				}
			}
			ds.Push(num+drob);
		}
		else //3+4*2/(1-5)^2
		{
			try
			{
				double Op2=ds.Pop();
				double Op1=ds.Pop();
				double result=Operation(Op1,Op2,out[i]);
				ds.Push(result);
			}
			catch(char *s)
			{
				cout<<s<<endl;
				return 0;
			}
		}
	}
	if (ds.IsEmpty())
	{
		cout<<"empty expression"<<endl;
		return 0;
	}
	else
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
	case '^':
		{
			double result=0;
			if (Op2==0)
				result=1;
			if (Op2==1)
				result=Op1;
			if (Op2>=2)
				result=stepen(Op1,(int)Op2);
			return result;
		}
	}
	return 0;
}
double OPZ::stepen(double Op1,int Op2)
{
	double result=Op1;

	for (int i=2;i<=Op2;i++)
	{
		result=result*Op1;
	}
	return result;
}

void OPZ::PrintStr()
{
	cout<<"infix string: "<<str<<endl;
}

