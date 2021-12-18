#include<stdio.h>
//function declaration
void accept(int*,int);
void display(int*,int);
int inter(int*,int,int*,int,int*);
int uni(int*,int,int*,int,int*);
int diff(int*,int,int*,int,int*);
void main()
{
  int choice,set1[50],set2[50],set3[50],n1,n2,n3,f;//declaration
  do
     {
    printf("\n\tMenu:");
    printf("\nchoose 1 To Accept 2 sets");
    printf("\nchoose 2 To display 2 sets");
    printf("\nchoose 3 To find Intersection of 2 sets");
    printf("\nchoose 4 To find Union of 2 sets");
    printf("\nchoose 5 To find Difference of 2 sets");
    printf("\nchoose 6 To Exit");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://for taking input
        printf("Enter the no of elements in Set 1:\n");
        scanf("%d",&n1);
        printf("Enter the %d elements of set 1:\n",n1);
        accept(set1,n1);                               //function calling

        printf("Enter the no of elements in Set 2:\n");
        scanf("%d",&n2);
        printf("Enter the %d elements of set 2:\n",n2);
        accept(set2,n2);                                //function calling


        break;

    case 2://for display
        printf("\n Elements in First set :");
        display(set1,n1);

        printf("\n Elements in Second set :");
        display(set2,n2);
        break;

    case 3://Intersection
        n3=inter(set1,n1,set2,n2,set3);
        printf("\n Intersection : ");
        display(set3,n3);
        break;


    case 4://Union
        n3=uni(set1,n1,set2,n2,set3);
        printf("\n Union : ");
        display(set3,n3);
        break;


    case 5://Symmetric difference
        n3=diff(set1,n1,set2,n2,set3);
        printf("\n  Difference(A-B) : ");
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
     //scanf("%d",&set[i]);

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
int inter(int set1[],int n1,int set2[],int n2,int set3[])
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
int uni(int set1[],int n1,int set2[],int n2,int set3[])
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
int diff(int set1[],int n1,int set2[],int n2,int set3[])
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