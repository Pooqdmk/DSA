/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#define max 20
int F(char symbol){
    switch(symbol){
        case '+':
        case '-':return 2;
        case '/':
        case '*':
        case '%':return 4;
        case '$':
        case '^':return 5;
        case '(':return 0;
        case '#':return -1;
        default:return 8;
    }
}
int G(char symbol){
    switch(symbol){
        case '+':
        case '-':return 1;
        case '/':
        case '*':
        case '%':return 3;
        case '$':
        case '^':return 6;
        case '(':return 9;
        case ')':return 0;
        default:return 7;
    }
}
void push(char s[max],int *top,char symbol){
    (*top)++;
    s[*top]=symbol;
}
char pop(char s[max],int *top){
    char symbol;
    symbol=s[*top];
    (*top)--;
    return symbol;
}
void infix_to_postfix(char infix[100]){
    char postfix[100],symbol,s[max];
    int top=-1,i,j=0;
    push(s,&top,'#');
    for(i=0;infix[i]!='\0';i++){
        symbol=infix[i];
        while(F(s[top])>G(symbol)){
            postfix[j]=pop(s,&top);
            j++;
        }
        if(F(s[top])!=G(symbol)){
            push(s,&top,symbol);
        }
        else{
            top--;
        }
    }
    while(s[top]!='#'){
        postfix[j]=pop(s,&top);
        j++;
    }
    postfix[j]='\0';
    printf("Postfix expression is %s",postfix);
}
int main()
{
    char infix[100];
    printf("Enter an infix expression");
    scanf("%s",infix);
    infix_to_postfix(infix);

    return 0;
}

