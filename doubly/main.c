#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int n;
    struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;

void insert1();
void insert2();
void insert3();
void display();
void inverse(int);
void modify();
void del();

int count = 0;

void main()
{
    int ch;
    h = NULL;
    temp = temp1 = NULL;
    do{
        printf("\n Menu: \n1 Insert at beginning \n2 Insert at end \n3 Insert at position i \n4 Display from beginning \n5 Display from end \n6 Deletion of node \n7 Modify a node \n8 Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                insert1();
                break;
            case 2:
                insert2();
                break;
            case 3:
                insert3();
                break;
            case 4:
                display();
                break;
            case 5:
                temp2 = h;
                if (temp2 == NULL)
                    printf("\n Error : List empty to display ");
                else
                {
                    printf("\n Reverse order of linked list is : ");
                    inverse(temp2->n);
                }
                break;
            case 6:
                del();
                break;
            case 7:
                modify();
                break;
            case 8:
                break;
            default:
                printf("\nInvalid Choice!!!");
        }
    }while(ch!=8);
}

void create()
{
    int data;

    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}

/*  TO insert at beginning */
void insert1()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

/* To insert at end */
void insert2()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

/* To insert at any position */
void insert3()
{
    int pos, i = 2;

    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create();
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}
/* Traverse from beginning */
void display()
{
    temp2 = h;

    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : ");

    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->n);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
}

/* To traverse from end recursively */
void inverse(int i)
{
    if (temp2 != NULL)
    {
        i = temp2->n;
        temp2 = temp2->next;
        inverse(i);
        printf(" %d ", i);
    }
}
/* To del an element */
void del()
{
    int i = 1, pos;

    printf("\n Enter position to be deld : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error : Position out of range to del");
        return;
    }
    if (h == NULL)
    {
        printf("\n Error : Empty list no elements to del");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node deld from list");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node deld from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
            h = temp2->next;
        printf("\n Node deld");
        free(temp2);
    }
    count--;
}
/* To modify a node value in the list */
void modify()
{
    int data, data1;

    printf("\n Enter node data to be modifyd : ");
    scanf("%d", &data);
    printf("\n Enter new data : ");
    scanf("%d", &data1);
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("\n Error : List empty no node to modify");
        return;
    }
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {

            temp2->n = data1;
            display();
            return;
        }
        else
            temp2 = temp2->next;
    }

    printf("\n Error : %d not found in list to modify", data);
}
