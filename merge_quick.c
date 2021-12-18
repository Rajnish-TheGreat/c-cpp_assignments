#include<stdio.h>

void accept(int number[25], int count){
    printf("Enter %d elements: ", count);
    for (size_t i = 0; i < count; i++){
        scanf("%d", &number[i]);
    }
}
void display(int number[25], int count){
    printf("\n");
    for (size_t i = 0; i < count; i++){
        printf("%d\t", number[i]);
    }
}
void quicksort(int number[25],int first,int last){
    int i, j, pivot, temp;
    if(first<last){
    pivot=first;
    i=first;
    j=last;
    while(i<j){
        while(number[i]<=number[pivot]&&i<last)
            i++;
        while(number[j]>number[pivot])
            j--;
        if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
        }
    }
    temp=number[pivot];
    number[pivot]=number[j];
    number[j]=temp;
    display(number,last+1);
    quicksort(number,first,j-1);
    quicksort(number,j+1,last);
    
    }
}
void partition(int number[25],int first,int last)
{
    int mid;
    if(first < last)
    {
        mid = (first + last) / 2;
        partition(number,first, mid);
        partition(number,mid + 1,last);
        mergeSort(number,first,mid,last);
        display(number,last+1);
    }
}
void mergeSort(int list[],int first,int centred,int last)
{
    int i, centre, k, low, temp[50];
    low = first;
    i = first;
    centre = centred + 1;
    while ((low <= centred) && (centre <= last))
    {
        if (list[low] <= list[centre])
        {
            temp[i] = list[low];
            low++;
        }
        else
        {
            temp[i] = list[centre];
            centre++;
        }
        i++;
    }
    if (low > centred)
    {
        for (k = centre; k <= last; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = low; k <= centred; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    for (k = first; k <= last; k++)
    {
        list[k] = temp[k];
    }
}
int main(){
    int i, count, number[25], choice;
    do{
        printf("\n\tSorting Menu :\n1 Enter number\n2 Display \n3 Sort (Iterative) \n4 Sort (Recursive) \n5 Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nNumber of elements you want to enter: ");
            scanf("%d",&count);
            accept(number,count);
            break;
        case 2:
            display(number,count);
            break;
        case 3:
            quicksort(number,0,count-1);
            break;
        case 4:
            partition(number,0,count-1);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice!!!");
        }
    }while(choice!=5);
    return 0;
}
