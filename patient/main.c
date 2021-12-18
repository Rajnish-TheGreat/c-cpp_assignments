#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data[50];
    int priority;
    int patientid;
    struct node *next;
} *front = NULL;

void insert(char name, int id, int pr);
int del();
void display();
int isEmpty();

int main(){
    int ch, id, pr;
    char name[50];

    do{
        printf("\nMenu \n1.Insert\n2.Delete \n3.Display \n4.Quit \nEnter your choice : ");
        scanf ("%d", &ch);
        switch (ch){
            case 1:
                printf("\nEnter Patient ID : ");
                scanf("%d", &id);
                printf("\nEnter Patient Name : ");
                fflush(stdin);
                gets(name);
                printf("\nEnter it's condition \n1.Serious \n2.Non \n3.Normal : ");
                scanf("%d", &pr);
                insert(name, id, pr);
                break;

            case 2:
                printf("\nQueue deleted !!!", del());
                break;

            case 3:
                display ();
                break;

            case 4:
                break;

            default:
                printf("\nInvalid Choice!!!\n");
        }
    }while (ch != 4);
    return 0;
}


void insert (char name, int id, int pr){
    struct node *temp, *p;

    temp = (struct node *) malloc (sizeof (struct node));
    if (temp == NULL){
        printf ("\nInsufficient Memory!!!\n");
        return;
    }
    temp->data[50] = name;
    temp->patientid = id;
    temp->priority = pr;

    if (isEmpty () || pr < front->priority){
        temp->next = front;
        front = temp;
    }
    else{
        p = front;
        while (p->next != NULL && p->next->priority <= pr)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

int del(){
    struct node *temp;
    int id;
    if (isEmpty ()){
        printf ("\nQueue Underflow\n");
        exit (1);
    }
    else{
        temp = front;
        id = temp->patientid;
        front = front->next;
        free (temp);
    }
    return id;
}

int isEmpty (){
    if (front == NULL)
        return 1;
    else
        return 0;
}

void display (){
    struct node *ptr;
    ptr = front;
    if (isEmpty ())
        printf ("\nQueue is empty\n");
    else{
        printf ("\nQueue is :\n");
        printf ("\nID\tName\tPriority\n");
        while (ptr != NULL){
            printf ("%d\t%s\t%d\n", ptr->patientid, ptr->data, ptr->priority);
            ptr = ptr->next;
	    }
    }
}
