#include "StackLinked.cpp"

//check char that send is in between 0 and 9
bool isDigit(char c)
{
    return (c>='0'&&c<='9');
}

//return 1 if op2 is more than op1 in precedent other return 0
bool precedent(char op1,char op2)
{
    if(op1=='^') //because op1 is the most precedence and this error
        return 0;

    else if(op1=='*'||op1=='/') //return 1 if precedence of op2 is more than op1
        return (op2=='^');

    else if(op1=='+'||op1=='-') //return 0 if op1 equal op2 in precedence
        return !(op2=='+'||op2=='-');
}

void infixToPostfix(char *infix,char *postfix)
{
    int i=0,j=0;
    char inf,top;
    //define s as stack and initialize it
    StackLinked<char> s;

    //iteration to string like (7^5/5*3+1) that user passing it
    for(i;(inf=infix[i])!='\0';i++)
        if (isDigit(inf))
            postfix[j++]=inf;
        else
        {
            if(!s.isEmpty())
            {
                s.getTop(top);
                //are (inf) operand can push over (top) operand in stack?
                while(!s.isEmpty()&&!precedent(top,inf))
                {
                    s.pop(top);
                    postfix[j++]=top;
                    s.getTop(top);
                }
            }
            s.push(inf);
        }

	//to get reminder operators in stack and pop them in postfix array
	while(!s.isEmpty())
	{
		s.pop(top);
		postfix[j++]=top;
	}
	postfix[j]='\0';
}
