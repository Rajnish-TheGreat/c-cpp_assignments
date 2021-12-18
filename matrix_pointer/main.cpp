#include<stdio.h>
#include<stdlib.h>

int** accept(int row ,int column){
    int**m1,i,j;
    m1 = (int**)malloc(row*sizeof(int));
    for(i=0;i<row;i++)
    {
        *(m1+i) = (int*)malloc(column*sizeof(int));
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",(*(m1+i)+j));
        }
    }
    return m1;
}
void display(int**m1,int row,int column){
    int i,j;
    for(i=0;i<row;i++)
    {
        printf("\n");
        for(j=0;j<column;j++)
        {
            printf("%d\t",*(*(m1+i)+j));
        }
    }
    printf("\n");
}
int**add(int row,int column){
    int**m1;
    int i,j;
    m1 = (int**)malloc(row*sizeof(int));
    for(i=0;i<row;i++)
    {
        *(m1+i) = (int*)malloc(row*sizeof(int*));
    }
    return m1;
}
int**addition(int**m1,int**m2,int row,int column){
    int**m3;
    int i,j;
    m3 = add(row,column);
    for(i=0;i<row;i++)
    {
        printf("\n");
        for(j=0;j<column;j++)
        {
            *(*(m3+i)+j) =*(*(m1+i)+j) + *(*(m2+i)+j);
        }
    }
 return m3;
}
int**subtraction(int**m1,int**m2,int row,int column){
    int**m3;
    int i,j;
    m3 = add(row,column);
    for(i=0;i<row;i++)
    {
        printf("\n");
        for(j=0;j<column;j++)
        {
            *(*(m3+i)+j) =*(*(m1+i)+j) - *(*(m2+i)+j);
        }
    }
 return m3;
}
int**multiplication(int**m1,int**m2,int r1,int c1,int c2){
    int**m3,i,j,k,sum=0;
    m3 = add(r1,c2);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<r1;k++)
            {
                sum = sum + ((*(*(m1+i)+k)) * (*(*(m2+k)+j)));
            }
            *(*(m3+i)+j) = sum;
            sum=0;
        }
    }
    return m3;
}
void transpose(int**m1,int r1,int c1)
{
    int i,j,temp;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<i;j++)
        {
        temp = *(*(m1+i)+j);
        *(*(m1+i)+j) = *(*(m1+j)+i);
        *(*(m1+j)+i) = temp;
        }
    }
}
bool saddle(int**mat ,int n)
{
    // Process all rows one by one
    for (int i = 0; i < n; i++)
    {
        // Find the minimum element of row i.
        // Also find column index of the minimum element
        int min_row = *(*(mat + i) + 0), col_ind = 0;
        for (int j = 1; j < n; j++)
        {
            if (min_row > *(*(mat + i)+j))
            {
                min_row = *(*(mat + i)+j);
                col_ind = j;
            }
        }

        // Check if the minimum element of row is also
        // the maximum element of column or not
        int k;
        for (k = 0; k < n; k++)

            // Note that col_ind is fixed
            if (min_row < *(*(mat + k)+col_ind))
                break;

        // If saddle point is present in this row then
        // print it
        if (k == n)
        {
           printf(" %d\n",min_row);
           return true;
        }
    }

    // If Saddle Point not found
    return false;
}


int main()
{
    int **matrix1,**matrix2,**matrix3,r1,r2,c1,c2,choice,temp;
    printf("Enter number of rows and column of first matrix:\n");
    scanf("%d%d",&r1,&c1);
    printf("Enter the elements of first matrix:\n");      //taking input of first matrix
    matrix1 = accept(r1,c1);                                 //function calling

    printf("Enter the number of rows and column of second matrix:\n");
    scanf("%d%d",&r2,&c2);
    printf("Enter the elements of second matrix:\n");      //taking input of second matrix
    matrix2 = accept(r2,c2);                                 //function calling

    printf("First matrix is :\n");
    display(matrix1,r1,c1);                               //function calling
    printf("Second matrix is :\n");
    display(matrix2,r2,c2);                                 //function calling
    do {
        printf("\n\tMenu:\nEnter \n1 For Addition \n2 For Subtraction \n3 For Multiplication \n4 For Transpose \n5 For Saddle \n6 To Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1://Addition
                if(r1==r2 && c1==c2){
                    matrix3 = addition(matrix1,matrix2,r1,c1);         //function calling
                    display(matrix3,r1,c1);
                }
                else
                    printf("WARNING!!! Can't add matrix of different orders\n");
                break;

        case 2://subtraction
            if(r1==r2 && c1==c2){
                matrix3 = subtraction(matrix1,matrix2,r1,c1);         //function calling
                display(matrix3,r1,c1);
            }
            else
                printf("WARNING!!! Can't add matrix of different orders\n");
            break;

        case 3://Multiplication
            if(c1==r2){
                matrix3 = multiplication(matrix1,matrix2,r1,c1,c2);        //function calling
                display(matrix3,r1,c2);
            }
            else
                printf("WARNING!!! Can't multiply matrix of entered orders\n");
            break;

        case 4://transpose
            printf("\nTranspose of matrix 1 is:\n");
            transpose(matrix1,r1,c1);
            display(matrix1,r1,c1);
            printf("\nTranspose of matrix 2 is:\n");
            transpose(matrix2,r2,c2);
            display(matrix2,r2,c2);
            break;
        case 5://saddle
            if(r1==c1){
                printf("Saddle Point of matrix 1 is: ");
                saddle(matrix1,r1);
            }
            if(r2==c2){
                printf("Saddle Point of matrix 2 is: ");
                saddle(matrix2,r2);
            }
        }
    }while(choice!=6);
}
