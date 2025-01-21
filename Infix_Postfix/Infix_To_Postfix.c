#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK '\0'
#define TAB '\t'
#define MAX 50

void push(char symbol);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space(char);
char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int main()
{
    long int value;
    top = -1;
    printf("Enter Infix: ");
    gets(infix);
    infix_to_postfix(); //to convert infix expression to postfix expression
    printf("Postfix: %s\n", postfix);
    value = eval_post(); //evaluate postfix expression
    printf("Value of Expression: %d\n", value);
    return 0;
}

void infix_to_postfix()
{
 unsigned int i,p=0;
 char next;
 char symbol;
 for(i=0;i<strlen(infix);i++)// it will scan infix expression using strlen function
 {
 symbol= infix[i];
 if(!white_space(symbol))
 {
 switch(symbol)
 {
 case '(': push(symbol);
 break;
 case ')':while((next=pop())!='(')
 postfix[p++]=next;
 break;
 case '+':
 case '-':
 case '*':
 case '/':
 case '%':
 case '^':
 while(!IsEmpty()&& priority(stack[top])>=priority(symbol))// when symbol is character it will check the content of the stack and priority
 postfix[p++]=pop();//if TOS has higher priority it will pop the content from the stack and will append to postfix array
 push(symbol);// when the symbol has higher priority push the content on the stack
 break;
 default:postfix[p++]=symbol;//if the symbol is operand, append it to postfix array
 }
 }
 }
while(!IsEmpty())// after scanning it will pop all the content from the stack till the stack is empty
 postfix[p++]=pop();
postfix[p]='\0';
}
int priority(char symbol)// to check the priority of the symbol
{
 switch(symbol)
 {
 case '(': return 0;
 case '+':
 case '-': return 1;
 case '*':
 case '/':
 case '%': return 2;
 case '^': return 3;
 default: return 0;
 }
}
void push(char symbol)// to push the content on the stack
{
 if(top>MAX)
 {
 printf("stack Overflow\n");
 exit(1);
 }
 stack[++top]=symbol;
}
long int pop()// to pop the content from the stack, long int is used to allocate wider range of memory
{
 if(IsEmpty())
 {
 printf("Stack Underflow");
 exit(1);
 }
 return (stack[top--]);
}
int IsEmpty()
{
 if(top==-1)
 return 1;
 else
 return 0;
}
int white_space(char symbol)
{
 if(symbol==BLANK||symbol==TAB)
 return 1;
 else
 return 0;
}
long int eval_post()//to evaluate postfix expression
{
 long int a,b,temp,result;
 unsigned int i;
 for(i=0; i<strlen(postfix);i++)
 {
 if(postfix[i]<='9' && postfix[i]>='0')
 push(postfix[i]-'0');
 else
 {
 a=pop();
 b=pop();
 switch(postfix[i])
 {
 case '+':temp=b+a;
 break;
 case '-':temp=b-a;
 break;
 case '*':temp=b*a;
 break;
 case '/':temp=b/a;
 break;
 case '%':temp=b%a;
 break;
 case '^':temp=pow(b,a);
 }
 push(temp);
 }
 }
 result=pop();
 return result;
}
