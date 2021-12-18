#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
	struct Node *next;
};

typedef struct Node *node;

node accept(){                       // ACCEPT FUNCTION
    node a;
    a = (node)malloc(sizeof(struct Node));
    printf("\n ENTER the data :");
    scanf("%d",&a->data);
    a->next=NULL;
    return (a);                 // RETURNING THE NODE
}
node create ( node head){
 	node a,newNode;
 	newNode = accept();          // CALLING THE FUNCTION TO MAKE NEW FUNCTION
 	if(head ==NULL){
        head = newNode;
    }
    else{
	 	a= head ;
	 	while(a->next !=NULL){
            a=a->next;
		 }
        a->next=newNode;
    }
    return (head);           // RETURNING THE HEAD
}
node insertion_begin(node head){
 	node temp ;
 	temp = accept();
 	temp->next = head;
 	return (temp);          // RETURING THE NEW HEAD
}
node delete_end(node head){
 	node temp ,temp1;
 	if(head == NULL){
 		printf("\n List is empty \n");
    }
    else{
        temp = head;
	 	while(temp->next!=NULL){
            temp1=temp;
	 		temp = temp->next;
        }
        temp1->next=NULL;
        printf("\n DELETED RECORD IS %d ",temp->data);
        free(temp);              // USING THE FREE FUNCTION TO REMOVE THE MEMORY
    }
    return (head);          // RETURNING THE HEAD
}
node delete_begin( node head){
 	node temp , temp1;
 	if(head == NULL){
 		printf("\n List is empty \n");
    }
    else{
	 	temp =head;
	 	temp1=temp->next;
	    printf("\n DELETED RECORD IS %d ",temp->data);
	    free(temp);
    }
    return (temp1);              //RETURNING THE NEW HEAD
}
void display_rev(node head){
    if(head!= NULL){
 		display_rev(head->next);     //RECURSIVLY CALLING THE DISPLAY FUNCTION
 		printf("%d ",head->data);
    }
}
void display (node n){
 	if(n ==NULL){
 		printf("\n LIST IS EMPTY \n");
 		return ;
    }
 	else{
 		printf(" \nENTERED LINKED LIST :");
 		printf("[ ");
 		while(n != NULL){
 		printf("%d " , n->data);
 		n=n->next;
    }
    printf("]\n ");
    }
}
node rev(node head){
 	node a,b,c;
 	a=NULL;
 	b=head;
 	c=b->next;
 	while(b!=NULL){
 		b->next=NULL;
 		a=b;
 		b=c;
 		if(c != NULL){
            c=c->next;
        }
    }
    return (a);
}


int main(){
	int choice ,option,res;
	node a , head = NULL;
	do{
        printf("\n MENU: \n1.INSERTION OF NODE \n2.DISPLAY THE LINKED LIST \n3.DELETION OF NODE \n4.DISPLAY IN REVERSE \n5.EXIT");
		printf("\n ENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice){
            case 1:
				do{
					printf("\n MENU FOR INSERTION OF NODE \n1.INSERT AT END \n2.INSERT AT BEGINING \n0.RETURN TO MAIN MENU\n");
					printf("\n ENTER YOUR CHOICE: ");
		            scanf("%d",&option);
		            switch(option){
                        case 1:
		            	    head = create(head);
                            break;
                        case 2:
                            head = insertion_begin(head);
                            break;
                    }
                }while(option != 0);
                break ;
			case 2:
				display(head);
                break;
			case 3:
				do{
					printf("\n MENU FOR DELETION OF NODE \n1.DELETE AT END \n2.DELETE AT BEGINING \n0.RETURN TO MAIN MENU\n");
					printf("\n ENTER YOUR CHOICE: ");
		            scanf("%d",&res);
		            switch(res){
		            	case 1:
		            	    head = delete_end(head);
                            break;
                        case 2:
                            head = delete_begin(head);
                            break;
					}
                }while(res != 0);
                break ;
			case 4:
				printf("\n REVERSED LINKED LIST :[ ");
				display_rev(head);
				printf("]\n");
                break ;
			case 5:
                break ;
        }

	}while(choice != 5);
    return 0;
}
