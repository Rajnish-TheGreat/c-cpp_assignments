#include<stdio.h>
#include<stdbool.h>

//function declaration
void accept(int [10][10],int,int);
void display(int [10][10],int,int);
void add(int [10][10],int [10][10],int ,int ,int [10][10]);
void sub(int [10][10],int [10][10],int ,int ,int [10][10]);
void mul(int [10][10],int [10][10],int ,int ,int [10][10]);
void trans(int [10][10],int,int);
bool saddle(int [10][10],int);



int main()
{
   int matrix1[10][10],matrix2[10][10],matrix3[10][10],r1,r2,c1,c2,choice;
   printf("Enter number of rows and column of the first matrix:\n");
   scanf("%d%d",&r1,&c1);
   printf("Enter the elements of first matrix:\n");      //taking input of first matrix
   accept(matrix1,r1,c1);                                 //function calling

   printf("Enter the number of rows and column of second matrix:\n");
   scanf("%d%d",&r2,&c2);
   printf("Enter the elements of second matrix:\n");      //taking input of second matrix
   accept(matrix2,r2,c2);                                 //function calling

   printf("First matrix is :\n");
   display(matrix1,r1,c1);                               //function calling
   printf("second matrix is :\n");
   display(matrix2,r2,c2);                                 //function calling
  do
     {
    printf("\n\tMenu:\nEnter \n1 For Addition \n2 For Subtraction \n3 For Multiplication \n4 For Transpose \n5 For Saddle \n6 To Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://Addition
         if(r1==r2 && c1==c2)
             add(matrix1,matrix2,r1,c1,matrix3);         //function calling
         else
             printf("WARNING!!! Can't add matrix of different orders\n");
         break;

    case 2://subtraction
         if(r1==r2 && c1==c2)
             sub(matrix1,matrix2,r1,c1,matrix3);        //function calling
         else
             printf("WARNING!!! Can't subtract matrix of different orders\n");
         break;

    case 3://Multiplication
         if(c1==r2)
             mul(matrix1,matrix2,r1,c2,matrix3);        //function calling
         else
             printf("WARNING!!! Can't multiply matrix of entered orders\n");
         break;

    case 4://transpose
         printf("Transpose of matrix 1 is:\n");
         trans(matrix1,r1,c1);
         printf("\nTranspose of matrix 2 is:\n");
         trans(matrix2,r2,c2);
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
void accept(int matrix[10][10],int r,int c) {          //function define
    int i,j;
    for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
           scanf("%d",&matrix[i][j]);
       }
   }
}
void display(int matrix[10][10],int r,int c) {         //function define
  int i,j;
  for(i=0;i<r;i++)
     {
       for(j=0;j<c;j++)
       {
           printf("%d\t",matrix[i][j]);
       }
       printf("\n");
     }
}
void add(int matrix1[10][10],int matrix2[10][10],int r,int c,int matrix3[10][10]) {     //function define
    int i,j;
    printf("Result of matrix Addition:\n");
    for(i=0;i<r;i++)
     {
       for(j=0;j<c;j++)
       {
           matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
           printf("%d\t",matrix3[i][j]);
       }
       printf("\n");
     }
}
void sub(int matrix1[10][10],int matrix2[10][10],int r,int c,int matrix3[10][10]) {     //function define
    int i,j;
    printf("Result of matrix subtraction:\n");
    for(i=0;i<r;i++)
     {
       for(j=0;j<c;j++)
       {
           matrix3[i][j]=matrix1[i][j]-matrix2[i][j];
           printf("%d\t",matrix3[i][j]);
       }
       printf("\n");
     }
}
void mul(int matrix1[10][10],int matrix2[10][10],int r1,int c2,int matrix3[10][10]) { //function define
    int i,j,k,c1,r2,sum=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
          for(k=0;k<r1;k++)
          {
            sum = sum + matrix1[i][k]*matrix2[k][j];
          }
          matrix3[i][j] = sum ;
          sum = 0;
        }
    }
    printf("Result of matrix Multiplication:\n");
    for(i=0;i<r1;i++)
     {
       for(j=0;j<c2;j++)
       {
        printf("%d\t",matrix3[i][j]);
       }
       printf("\n");
     }
}
void trans(int matrix1[10][10],int r1,int c1) {                                         //function define
    int i,j,temp;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            temp = matrix1[i][j];
            matrix1[i][j] = matrix1[j][i];
            matrix1[j][i] = temp;
        }
    }
    for(i=0;i<c1;i++)
    {
        for(j=0;j<r1;j++)
        {

            printf("%d\t",matrix1[j][i]);

        }
        printf("\n");

    }
}
bool saddle(int mat[10][10], int n)
{
    // Process all rows one by one
    for (int i = 0; i < n; i++)
    {
        // Find the minimum element of row i.
        // Also find column index of the minimum element
        int min_row = mat[i][0], col_ind = 0;
        for (int j = 1; j < n; j++)
        {
            if (min_row > mat[i][j])
            {
                min_row = mat[i][j];
                col_ind = j;
            }
        }

        // Check if the minimum element of row is also
        // the maximum element of column or not
        int k;
        for (k = 0; k < n; k++)

            // Note that col_ind is fixed
            if (min_row < mat[k][col_ind])
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
