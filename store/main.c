#include<stdio.h>


struct details{
     char item_name[20];
     int price;
     int serialNo;
     int quantity;
     char mfg[20];
   };

void create(struct details[] ,int n);
void display(struct details[], int n);
void search(struct details[],int n);
int insert(struct details[],int n);
void modify(struct details[],int n);
void sort(struct details[],int n);
int del(struct details[],int n);

void main(){
    struct details s[20];
    int n = 0,choice;
    do{
        printf("\n\tMenu :\n1 Create DataBase\n2 Display Database\n3 Search in Database\n4 Insert in Database\n5 Modify Database\n6 Sort Database\n7 Delete a data from Database\n8 Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the no. of entries\n");
            scanf("%d",&n);
            fflush(stdin);
            create(s,n);
            break;
        case 2:
            display(s,n);
            break;
        case 3:
            search(s,n);
            break;
        case 4:
            n = insert(s,n);
            break;
        case 5:
            modify(s,n);
            break;
        case 6:
            sort(s,n);
            break;
        case 7:
            n = del(s,n);
            break;
        default:
            printf("\nEnter valid preference\n");
        }
    }while(choice!=8);
}

void create(struct details s[20] ,int n){
    for(int i =0;i<n;i++){
        printf("Item name: ");
        scanf("%s",s[i].item_name);
        fflush(stdin);                                       //This is used to clear buffer memory
        printf("\nItem code: ");
        scanf("%d",&s[i].serialNo);
        fflush(stdin);
        printf("\nQuantity: ");
        scanf("%d",&s[i].quantity);
        fflush(stdin);
        printf("\nPrice: ");
        scanf("%d",&s[i].price);
        fflush(stdin);
        printf("\nManufacture date: ");
        scanf("%s", s[i].mfg);
        fflush(stdin);
     }
}
void display(struct details s[20] ,int n){
    printf("\t\t\t***** INVENTORY ***** \n");
    printf("------------------------------------------------------------------\n");
    printf("S.No | Name | QUANTITY | PRICE | MFG.DATE \n");
    printf("------------------------------------------------------------------\n");
    for(int i =0;i<n;i++){
        printf("%d  %s %d        %d           %s\n",s[i].serialNo,s[i].item_name,s[i].quantity,s[i].price,s[i].mfg);
    }
    printf("\n------------------------------------------------------------------\n");
}
void search(struct details s[20],int n){
    int serial = 0,flag = 0;
    printf("\nEnter Serial No: ");
    scanf("%d",&serial);
    for(int i = 0;i<n;i++){
        if(s[i].serialNo == serial){
            flag = 1;
            printf("\t\t\t***** INVENTORY ***** \n");
            printf("------------------------------------------------------------------\n");
            printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE| MFG.DATE \n");
            printf("------------------------------------------------------------------\n");
            printf("%d %s %d            %d          %s\n",s[i].serialNo,s[i].item_name,s[i].quantity,s[i].price,s[i].mfg);
            printf("------------------------------------------------------------------\n");
            break;
            }
    }
    if(flag ==0)
        printf("\nItem not found\n");
}
int insert(struct details s[20],int n){
     int a = 1,k = 0;
     printf("\nEnter No of Items To Add: ");
     scanf("%d",&k);
     while(n + k > 20){
        printf("\nDatabase capacity exceeded!\n");
        printf("\nEnter the no. of entries to insert(less than %d)\n",k);
        scanf("%d",&k);
        fflush(stdin);
    }
    for(int i = 0;i<k;i++){
        printf("Item name: ");
        scanf("%s",s[i+n].item_name);
        fflush(stdin);
        printf("\nItem code: ");
        scanf("%d",&s[i+n].serialNo);
        fflush(stdin);
        printf("\nQuantity: ");
        scanf("%s",&s[i+n].quantity);
        fflush(stdin);
        printf("\nPrice: ");
        scanf("%s",&s[i+n].price);
        fflush(stdin);
        printf("\nManufacture date: ");
        scanf("%s", s[i+n].mfg);
        fflush(stdin);
    }
    return n+k;
}
void modify(struct details s[20],int n){
    int serial = 0,flag = 0;
    printf("\nEnter Serial Number: ");
    scanf("%d",&serial);
    for(int i = 0;i<n;i++){
        if(s[i].serialNo == serial){
            flag = 1;
            printf("Item name: ");
            scanf("%s",s[i].item_name);
            fflush(stdin);
            printf("\nQuantity: ");
            scanf("%s",&s[i].quantity);
            fflush(stdin);
            printf("\nPrice: ");
            scanf("%s",&s[i].price);
            fflush(stdin);
            printf("\nManufacture date: ");
            scanf("%s", s[i].mfg);
            fflush(stdin);
            break;
        }
    }
    if(flag ==0)
        printf("\nItem not available\n");
}
void sort(struct details s[20],int n){
    struct details temp;
    for(int i =0;i<n -1 ;i++){
        for(int j = 0;j<n - i - 1;j++){
            if(s[j].serialNo>s[j+1].serialNo){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}
int del(struct details s[20],int n){
    int i,serial = 0;
    printf("\nEnter Serial No: ");
    scanf("%d",&serial);
    for (i = 0; i < n; i++){
        if (s[i].serialNo == serial)
        break;
    }
    if (i == n){
        printf("\nItem not found\n");
    }
    for (i; i < n; i++){
        s[i] = s[i + 1];
    }
    printf("\nRecord successfully deleted\n");
    n--;
    return n;
}


