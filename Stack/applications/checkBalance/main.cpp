#include <iostream>
#include <string>
#include "StackLinked.cpp"
using namespace std;

bool arePair(char open,char close)
{
    if(open=='('&&close==')') return 1;
    else if(open=='{'&&close=='}') return 1;
    else if(open=='['&&close==']') return 1;
    return 0;
}

bool isBalance(string exp)
{
    char c='\0';
    StackLinked<char> s;
    for(unsigned i=0;i<exp.length();i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            s.push(exp[i]);
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            s.getTop(c);
            if(s.isEmpty()||!arePair(c,exp[i])) return 0;
            else
                s.pop(c);
        }
    }
    return s.isEmpty();
}

int main()
{
    string str;
    cout<<"Enter expression: ";
    cin>>str;

    if(isBalance(str))
        cout<<"Expression balanced\n";
    else
        cout<<"Expression unbalanced\n";
    return 0;
}
