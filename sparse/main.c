#include <stdio.h>
#define MAX 20
#define MAX2 20

void accept(int a[10][10], int row, int column);
void display_sparse(int b[MAX][3]);
void create_sparse(int a[10][10], int row, int column, int b[MAX][3]);
void simple_transpos(int b[MAX][3],int tran[MAX][3]);
void fast_transpos(int b[MAX][3],int tran[MAX][3]);
void add(int b[MAX][3],int d[MAX2][3],int tran[MAX][3]);

int main(){
    int a[10][10], b[MAX][3], c[10][10], d[MAX2][3], tran[MAX][3], row, column, row2, column2, choice;
    printf("Enter number of rows and column of first the matrix:\n");
    scanf("%d%d", &row, &column);
    accept(a, row, column);
    printf("Enter number of rows and column of second the matrix:\n");
    scanf("%d%d", &row2, &column2);
    accept(c, row2, column2);

    printf("First matrix is :\n");
    display(a,row,column);
    printf("Second matrix is :\n");
    display(c,row2,column2);

    do{
        printf("\n\tMenu:\nEnter \n1 Create Sparse matrix \n2 Simple Transpose \n3 Fast Transpose \n4 Add sparse matrix \n5 To Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create_sparse(a, row, column, b);
            printf("Sparse of first matrix is :\n");
            display_sparse(b);
            create_sparse(c, row2, column2,d);
            printf("Sparse of second matrix is :\n");
            display_sparse(d);
            break;
        case 2:
            simple_transpos(b,tran);
            printf("Sparse first matrix transpose :\n");
            display_sparse(tran);
            simple_transpos(d,tran);
            printf("Sparse second matrix transpose :\n");
            display_sparse(tran);
            break;
        case 3:
            fast_transpos(b,tran);
            printf("Sparse first matrix transpose :\n");
            display_sparse(tran);
            fast_transpos(d,tran);
            printf("Sparse second matrix transpose :\n");
            display_sparse(tran);
            break;
        case 4:
            add(b,d,tran);
            break;
        case 5:
            break;
        }
    }while(choice!=5);
    return 0;
}

void accept(int a[10][10], int row, int column){
    int i, j;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < row; i++){
        for (j = 0; j < column; j++)
            scanf("%d", &a[i][j]);
    }
}

void display(int a[10][10],int row,int column){
  int i,j;
  for(i=0;i<row;i++)
     {
       for(j=0;j<column;j++)
       {
           printf("%d\t",a[i][j]);
       }
       printf("\n");
     }
}

void create_sparse(int a[10][10], int row, int column, int b[MAX][3])
{
    int i, j, k;
    k = 1;
    b[0][0] = row;
    b[0][1] = column;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k - 1;
    }
}

void display_sparse(int b[MAX][3]){
    int i, column;
    column = b[0][2];
    printf("\nSparse form\n\n");
    for (i = 0; i <= column; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

void simple_transpos(int b[MAX][3],int tran[MAX][3]){
    int k=1;
    tran[0][0]=b[0][1];
    tran[0][1]=b[0][0];
    tran[0][2]=b[0][2];
    printf("Transpose is: \n");
    for(int i=0;i<b[0][1];i++){
        for(int j=1;j<=b[0][2];j++){
            if(b[j][1]==i){
                tran[k][0]=b[j][1];
                tran[k][1]=b[j][0];
                tran[k][2]=b[j][2];
                k++;
            }
        }
    }
}

void fast_transpos(int b[MAX][3],int tran[MAX][3]){
    int m,n,t,i,k,col_num,total[MAX],index[MAX];
    m=b[0][0];
    n=b[0][1];
    t=b[0][2];
    tran[0][0]=n;
    tran[0][1]=m;
    tran[0][2]=t;
    for(i=0;i<n;i++)
        total[i]=0;
    for(i=1;i<=t;i++)
    {
        col_num=b[i][1];
        total[col_num]++;
    }
    index[0]=1;
    for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];

    for(i=1;i<=t;i++)
    {
        col_num=b[i][1];
        k=index[col_num];
        index[col_num]++;
        tran[k][0]=b[i][1];
        tran[k][1]=b[i][0];
        tran[k][2]=b[i][2];
    }
}

void add(int b[MAX][3],int d[MAX2][3],int tran[MAX][3]){
    int i,j,column = b[0][2], column2 = d[0][2];
    if(column2==column){
        printf("Result of Addition:\n");
        for(i=0;i<column;i++)
        {
            for(j=0;j<3;j++)
            {
                tran[i][j]=b[i][j]+d[i][j];
                printf("%d\t",tran[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Can't add matrix of different order");
}
