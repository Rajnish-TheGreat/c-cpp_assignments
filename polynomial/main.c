#include<stdio.h>
#include<conio.h>
#include<math.h>

typedef struct node{
    int expo,coef;
    struct node *next;
}node;

node *insert(node*head,int expo1,int coef1){
    node *p,*q;
    p=(node *)malloc(sizeof(node));
    p->expo=expo1;
    p->coef=coef1;
    p->next=NULL;
    if(head==NULL){
        head=p;
        head->next=head;
        return(head);
    }
    if(expo1>head->expo){
        p->next=head->next;
        head->next=p;
        head=p;
        return(head);
    }
    if(expo1==head->expo){
        head->coef=head->coef+coef1;
        return(head);
    }
    q=head;
    while(q->next!=head&&expo1>=q->next->expo)
            q=q->next;
        if(p->expo==q->expo)
            q->coef=q->coef+coef1;
        else{
            p->next=q->next;
            q->next=p;
        }

    return(head);
}
node *create(){
    int n,i,expo1,coef1;
    node *head=NULL;
    printf("\nEnter no of terms of polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nExponent %d: ", i+1);
        scanf("%d",&expo1);
        printf("\nCoefficient %d: ", i+1);
        scanf("%d",&coef1);
        head=insert(head,expo1,coef1);
    }
    return(head);
}
node *add(node *p1,node *p2){
    node *p;
    node *head=NULL;
    printf("\n\nAddition of polynomial:");
    p=p1->next;
    do{
        head=insert(head,p->expo,p->coef);
        p=p->next;
    }while(p!=p1->next);
    p=p2->next;
    do{
        head=insert(head,p->expo,p->coef);
        p=p->next;
    }while(p!=p2->next);
    return(head);
}
node *multi(node *p1,node *p2){
    node *head1,*head2;
    node *head=NULL;
    printf("\n\n\nMultiplication of polynomial: ");
    head2=p2->next;
    do{
        head1=p1->next;
        do{
            head=insert(head,head1->expo+head2->expo,head1->coef*head2->coef);
            head1=head1->next;
        }while(head1!=p1->next);
        head2=head2->next;
    }while(head2!=p2->next);
    return(head);
}
int eval(node *head,int x){
    node *p;
    int ans=0;
    p=head->next;
    do{
        ans=ans+p->coef*pow(x,p->expo);
        p=p->next;
    }while(p!=head->next);
    return(ans);
}
void display(node *head){
    node *p,*q;
    int n=0;
    q=head->next;
    p=head->next;
    do{
        n++;
        q=q->next;
    }while(q!=head->next);
    printf("\n\tThe polynomial is: ");
    do{
        if(n-1){
            printf("%dx^(%d) + ",p->coef,p->expo);
            p=p->next;
        }
        else{
            printf(" %dx^(%d)",p->coef,p->expo);
            p=p->next;
        }
    n--;
    }while(p!=head->next);
}
void main(){
    char ans;
    int a,x,ch;
    node *p1,*p2,*p3;
    p1=p2=p3=NULL;
    p1=create();
    display(p1);
    p2=create();
    display(p2);
    do{
        printf("\n Menu: \n1 Add \n2 Multiply \n3 Evaluate \n4 Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
                p3=add(p1,p2);
                display(p3);
                break;
            case 2 :
                p3=multi(p1,p2);
                display(p3);
                break;
            case 3 :
                printf("\nEnter the value of x: ");
                scanf("%d",&x);
                printf("\nValue for polynomial 1 = %d",eval(p1,x));
                printf("\nValue for polynomial 2 = %d",eval(p2,x));
                break;
            case 4 :
                break;
            default :
                printf("Invalid choice!!!!");
                break;
        }
    }while(ch!=4);
}
