#include<stdio.h>
#include<cstdlib>
//function declaration
void accept(int*,int);
void display(int*,int);
int intersection(int*,int,int*,int,int*);
int unions(int*,int,int*,int,int*);
int diff1(int*,int,int*,int,int*);
int diff2(int*,int,int*,int,int*);


int main()
{
  int choice,set1[50],set2[50],set3[50],n1,n2,n3;//declaration
  do
     {
    printf("\n\tMenu \n1 To Accept roll number\n2 To find students who like both Math and science\n3 To find students who like either math or science\n4 To find students who like Math only\n5 To find students who like Science only");
    printf("\n6 To Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://for taking input
        printf("Enter the no of students who like Math:\n");
        scanf("%d",&n1);
        printf("Enter the roll number of students who like math:\n",n1);
        accept(set1,n1);                               //function calling

        printf("Enter the no of students who like Science:\n");
        scanf("%d",&n2);
        printf("Enter the roll number of students who like Science:\n",n2);
        accept(set2,n2);                                //function calling
        break;


    case 2://Intersection
        n3=intersection(set1,n1,set2,n2,set3);
        printf("\n Like both Math and Science : ");
        display(set3,n3);
        break;


    case 3://Union
        n3=unions(set1,n1,set2,n2,set3);
        printf("\n Like either Math or Science : ");
        display(set3,n3);
        break;


    case 4://Symmetric difference
        n3=diff1(set1,n1,set2,n2,set3);
        printf("\n Only Math : ");
        display(set3,n3);
        break;

    case 5://Symmetric difference
        n3=diff2(set1,n1,set2,n2,set3);
        printf("\n Only Science : ");
        display(set3,n3);
        break;

    }
  }while(choice!=6);
}
void accept(int set[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&set[i]);
    }

}
void display(int set[],int n)
{
    int i;
    printf("{");
    for(i=0;i<n;i++)
    {
        if(i<(n-1))
        {
            printf("%d ",set[i]);
        }
        else
        {
            printf("%d ",set[i]);
        }
    }
    printf("\b}");
}
int intersection(int set1[],int n1,int set2[],int n2,int set3[])
{
    int i,j,n3=0;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(set1[i]==set2[j])
            {
                set3[n3]=set1[i];
                n3++;
            }
        }
    }
    return n3;
}
int unions(int set1[],int n1,int set2[],int n2,int set3[])
{
    int i,j,n3;
    for(i=0;i<n1;i++)
    {
        set3[i]=set1[i];
    }
    n3=n1;
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n3;j++)
        {
            if(set3[j]==set2[i])
            {
                break;
            }
        }
        if(j==n3)
        {
            set3[n3]=set2[i];
            n3++;
        }
    }
    return n3;
}
int diff1(int set1[],int n1,int set2[],int n2,int set3[])
{
    int i,j,n3=0;
    for(i=0;i<n1;i++)
    {int c=0;
        for(j=0;j<n2;j++)
        {
            if(set1[i]==set2[j])
            {
                c=1;
            }
        }
           if(c==0)
           {
               set3[n3++]=set1[i];
           }
    }return n3;
}
int diff2(int set1[],int n1,int set2[],int n2,int set3[])
{
    int i,j,n3=0;
    for(i=0;i<n2;i++)
    {int c=0;
        for(j=0;j<n1;j++)
        {
            if(set2[i]==set1[j])
            {
                c=1;
            }
        }
           if(c==0)
           {
               set3[n3++]=set2[i];
           }
    }return n3;
}
