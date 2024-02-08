/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
typedef struct sparse{
    int r;
    int c;
    int v;
}S;
void accept(S a[10],int n,int m){
    int i,j,k=1,ele;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("enter the element at row %d and column %d",i,j);
            scanf("%d",&ele);
            if(ele!=0){
                a[k].r=i;
                a[k].c=j;
                a[k].v=ele;
                k++;
            }
        }
    }
    a[0].r=n;
    a[0].c=m;
    a[0].v=k-1;
}
void display(S a[10]){
    int i,j,k=1,m,n;
    m=a[0].c;
    n=a[0].r;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i==a[k].r && j==a[k].c){
                printf("%d \t",a[k].v);
                k++;
            }
            else{
                printf("0 \t");
            }
        }
        printf("\n");
    }
}
int main()
{
    S a[10];
    int m,n;
    printf("enter the size of the matrix");
    scanf("%d%d",&n,&m);
    accept(a,n,m);
    display(a);

    return 0;
}
