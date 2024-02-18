/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<math.h>
#define max 20
#include<stdlib.h>
#include<ctype.h>
void push(int s[max],int *top,int symbol){
    (*top)++;
    s[*top]=symbol;
}
int pop(int s[max],int *top){
    int symbol;
    symbol=s[*top];
    (*top)--;
    return symbol;
}
int compute(int op1,int op2,char op){
    switch(op){
        case '+':return (op1+op2);
        case '-':return (op1-op2);
        case '*':return (op1*op2);
        case '%':return (op1%op2);
        case '/':return (op1/op2);
        case '$':
        case '^':return (pow(op1,op2));
        default:exit(0);
    }
    
}
int main()
{
    char postfix[100],symbol;
    printf("Enter an postfix expression");
    scanf("%s",postfix);
    int s[max],i,top=-1,op1,op2,res;
    for(i=0;postfix[i]!='\0';i++){
        symbol=postfix[i];
        if(isdigit(symbol)){
            push(s,&top,symbol-'0');
        }
        else{
            op1=pop(s,&top);
            op2=pop(s,&top);
            res=compute(op1,op2,symbol);
            push(s,&top,res);
        }
    }
    printf("%d",pop(s,&top));

    return 0;
}

