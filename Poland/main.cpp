#include "stdio.h"

#include "TStack.h"

int Prior(char c)
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

int main()

{
	TStack s;
	/*s.Push(1);
	s.Push(2);
	s.Push(3);
	while (!s.IsEmpty())
	{
		int x=s.Pop();
		printf ("%d\n",x);
	}*/
	char str[100]="3+4-1";
	char out[100];
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
						if (s.IsEmpty())
						{
							printf("skobki neparnie");
							break;
						}
						pr=s.Peek();
					}
					pr=s.Pop();// убираем из стека открывающуюся скобку
					continue;
				}

				int pr=s.Peek();
				while (Prior(pr)>=Prior(str[i])) //Операция выталкивает из стека все операции с большим или равным
												 //приоритетом в выходную строку
				{
					out[k]=s.Pop();
					k++;
					if (s.IsEmpty())
						break;
					pr=s.Peek();
				}
				s.Push(str[i]);
			}
		}
	}

	while(!s.IsEmpty())
	{
		out[k]=s.Pop();
		k++;
	}
	out[k]=0;
	printf ("%s\n",out);

	return 0;
}