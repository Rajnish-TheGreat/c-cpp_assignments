#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
class stack
{
    struct node
    {
        int data;
        node *next;
    }*top;
    public:
        stack();
        void push(int);
        int pop();
        int readtop();
        int isempty();
};
class charstack		//declaration of character stack
{
    struct node
    {
        char data;
        node *next;
    }*top;
    public:
        charstack();
        void push(char);
        char pop();
        char readtop();
        int isempty();
};
class expression		//declaration of operations of expression in class expression
{
    char infix[20];
    char postfix[20];
    char prefix[20];
    stack stk;
    charstack chr;
    int res,elements,operand1,operand2,operat;
    public:
        void getexpression();           //get an expression as input
        void displaypost();             //Displaying Postfix Expression
        void displaypre();              //Displaying Prefix  Expression
        int evaluatepost();				//evaluation of postfix expression
        int evaluatepre();        		//evaluation of prefix expression
        int calculate(int,int,char);	//calculating the values of variables in the expresssion
        void convintopost();	        //converting an infix expression to postfix expression
        int precedence(char);	        //function defining the precedence of some operators
        void convintopre();		        //converting an infix expression to prefix
};
int stack::isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
stack::stack()
{
    top=NULL;
}
void stack::push(int element)
{
    node *temp=new struct node;
    temp->data=element;
    if(top==NULL)
    {
        top=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
int stack::pop()
{
    int no;
    node *temp;
    no=top->data;
    temp=top;
    top=top->next;
    temp->next=NULL;
    delete temp;
    return no;
}
int stack::readtop()
{
    if(isempty()==1)
    {
        return -1;
    }
    else
    {
        int temp;
        temp=top->data;
        return temp;
    }
}
int charstack::isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
charstack::charstack()
{
    top=NULL;
}
void charstack::push(char element)
{
    node *temp=new struct node;
    temp->data=element;
    if(top==NULL)
    {
        top=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
char charstack::pop()
{
    char data;
    node *temp;
    data=top->data;
    temp=top;
    top=top->next;
    temp->next=NULL;
    delete temp;
    return data;
}
char charstack::readtop()
{
    if(isempty()==1)
    {
        return -1;
    }
    else
    {
        char temp;
        temp=top->data;
        return temp;
    }
}
void expression::getexpression()
{
    cout<<"\nEnter Infix Expression : ";
    cin>>infix;
}
void expression::displaypost()
{
    int len;
    cout<<"\n Infix Expression  :  ";
    len=strlen(infix);
    for(int i=0;i<len;i++)
    {
        cout<<infix[i]<<" ";
    }
    cout<<endl;
    cout<<"\n Postfix Expression : ";
    len=strlen(postfix);
    for(int i=0;i<len;i++)
    {
        cout<<postfix[i]<<" ";
    }
    cout<<endl;
}
void expression::displaypre()
{
    int len;
    cout<<"\n Infix Expression  :  ";
    len=strlen(infix);
    for(int i=0;i<len;i++)
    {
        cout<<infix[i]<<" ";
    }
    cout<<endl;
    cout<<"\n Prefix Expression : ";
    len=strlen(prefix);
    for(int i=0;i<len;i++)
    {
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
}
void expression::convintopost()
{
    char element,x; int i,j=0;
        //stk.push('(');      //to solve for expressions without brackets
        for(i=0;i<strlen(infix);i++)
        {
            element=infix[i];
            if(isalnum(element)!=0)                //check if it is operand
            {
                postfix[j++]=infix[i];
            }
            else
            {
                if(element=='(')                    //if opening bracket push on stack
                {
                    chr.push(element);
                }
                else {
                   if(element==')')
                        {
                            while(chr.readtop()!='(')
                            {
                               postfix[j++]=chr.pop();
                            }
                        }                                   //check preccedence of operators
                   else {
                            while( (precedence(element) < precedence(chr.readtop())) && chr.isempty()!=1)
                            {
                                x=chr.pop();
                                if(x!='(' && x!=')')
                                postfix[j++]=x;
                            }
                            if(element!='(' && element!=')')        //to check for any stray brackets
                            chr.push(element);
                        }
                    }
            }
       }

        while(chr.isempty()!=1)     //to pop remaining elements of stack
            {
            x=chr.pop();
            if(x!='(' && x!=')')
            postfix[j++]=x;
            }
    postfix[j]='\0';
}
void expression::convintopre()	//declaration of function ot convert infix to prefix
{
    charstack prestack,opstack;
    int i,len; char element,temp;
    len=strlen(infix);

    for(i=len-1;i>=0;i--)
    {
        element=infix[i];
        if(element==')')            //check if it is bracket
          {
              opstack.push(element);
          }
         else if(element=='(')          //push the opeartors inside brackets to prestack
         {
              while(opstack.readtop()!=')')
             {
                temp=opstack.pop();
                if(temp!='(')
                prestack.push(temp);
             }
         }
        else
        {
              if(isalnum(element)!=0)
            {
               prestack.push(element);      //to check if it is operand
            }
          else
          {
                  while(precedence(opstack.readtop()) > precedence(element) && !opstack.isempty())
                  {
                  temp=opstack.pop();

                  if(temp!=')')
                  prestack.push(temp);

                  }
              opstack.push(element);
          }

      }
    }
    while(opstack.isempty()!=1)     //check for remaining elements on stack
        {
            temp=opstack.pop();
            if(temp!='(' && temp!=')')
            prestack.push(temp);
        }

    i=0;
    while(prestack.isempty()!=1)
    {                                     //insert elements for prestack to array
        prefix[i++]=prestack.pop();
    }

    prefix[i]='\0';
}
int expression::evaluatepost()	//declaration of evaluation of postfix expression
{
    int i=0,val;
    while(postfix[i]!='\0')
    {
        if(isalnum(postfix[i])!=0)
        {
            cout<<"Enter the value for "<<postfix[i];
            cin>>val;
            stk.push(val);
        }
        else
        {
            operand1=stk.pop();
            operand2=stk.pop();
            res=calculate(operand1,operand2,postfix[i]);
            stk.push(res);
        }
        i++;
    }
    return res;
}
int expression::evaluatepre()	//declaration of evaluation of prefix expression
{
    int i,len,val;
    len=strlen(prefix);
    i=len-1;
    while(i>=0)
    {
        if(isalnum(prefix[i])!=0)
        {
            cout<<"Enter the value for  "<<prefix[i]<<" ";
            cin>>val;
            stk.push(val);
        }
        else
        {
            operand2=stk.pop();
            operand1=stk.pop();
            res=calculate(operand2,operand1,prefix[i]);
            stk.push(res);
        }
        i--;
    }
    return res;
}
int expression::calculate(int operand1,int operand2,char operat)//declaration of calculation function
{
    if(operat=='*')
    {
        return operand2*operand1;
    }
    else if(operat=='-')
    {
        return operand2-operand1;
    }
    else if(operat=='/')
    {
        return operand2/operand1;
    }
    else if(operat=='+')
    {
        return operand2+operand1;
    }
    else if(operat=='$')
    {
        return pow(operand2,operand1);
    }
}
int expression::precedence(char a)
{
    if(a=='*' || a=='/' || a=='$')
    {
        return 2;
    }
    else if(a=='+' || a=='-')
    {
        return 1;
    }
    return 0;
}
int main()
{
    stack s;
    expression e;
    int cho,result;
    do
    {
        cout<<"\n1. Enter Expression ";
        cout<<"\n2. Display Postfix  ";
        cout<<"\n3. Display Prefix   ";
        cout<<"\n4. Evaluate Postfix ";
        cout<<"\n5. Evaluate Prefix ";
        cout<<"\n6. Exit ";
        cout<<"\n   Enter your choice : ";
        cin>>cho;
        if(cho==1)
        {
            e.getexpression();
        }
        else if(cho==2)
        {
            e.convintopost();
            e.displaypost();
        }
        else if(cho==3)
        {
            e.convintopre();
            e.displaypre();
        }
        else if(cho==4)
        {
            result=e.evaluatepost();
            cout<<"\n Result = "<<result<<endl;
        }
        else if(cho==5)
        {
            result=e.evaluatepre();
            cout<<"\n Result = "<<result<<endl;
        }
    }while(cho!=6);
}

