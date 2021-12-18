#include<iostream>
#include<string.h>
using namespace std;
class node{            //class for the creation of node
public :
    int index;
    char name[20];
    int date,month,year,numlikes,numcom,numfrnds;     //information of attach with node
    node *next;          //node pointing to next node
    node(){     //default constructor
        index = 0;
        name[0] = '\0';
        date = 0;
        month = 0;
        year = 0;
        numlikes = 0;
        numcom = 0;
        numfrnds = 0;
        next = NULL;
    }
    node(char n[20],int ind,int d,int m,int y,int nlikes,int ncom){
       strcpy(name,n);
        index = ind;
        date = d;
        month = m;
        year = y;
        numlikes = nlikes;
        numcom = ncom;
        numfrnds = 0;
        next = NULL;
    }
};
class que{        //class to create queue
    node *item[20];  //array of nodes
    int front,rear;
public :
    que(){    //default constructor
    front = -1;
    rear =-1;
    }

    void enqueue(node *p){       //for enqueuing element from rear end
    if(front = -1){
        front++;
    }
    else{
        item[++rear]=p;}
    }

    node *deque(){               //for dequeuing element from frond end
    node *temp = item[front];
    if(rear == front){
        rear = -1;
        front = -1;
    }
    else{
        front++;
    }
    return(temp);
    }
    int isempty(){     //is queue empty
    if(front = -1){
        return 1;
    }
    else{
       return 0;}
    }
};
class Facebook{
    node *F[20];  //size of node list i.e max number of users
    int num_users,mon;
    int frnd[20],visited[20];
public :
    Facebook(){      //default Constructor
    int i;
    cout<<"Enter the number of users : ";
    cin>>num_users;
    for(i=0;i<num_users;i++){
        F[i] = NULL;
        frnd[i]=0;
        visited[i]=0;
    }
    }
    void Add_user();    //for adding user into the network
    void Connect_user();   //for connecting the user
    void Connect(int,int);         //for the actual connection of user
    void Display_userdetails();
    void Max_friends();
    void Traverse_BFS();
    void Traverse_DFS();
    void DFS(node*,int);
};
void Facebook :: Add_user(){
    int i;
    char name[20];
    int index,date,month,year,numcom,numlikes;
    for(i=0;i<num_users;i++){
       index = i;
       cout<<"\n\tEnter details of User "<<i+1<<endl;
       cout<<"Enter Name : ";
       cin>>name;
       cout<<"Enter Date of Birth(dd mm yy) : ";
       cin>>date>>month>>year;
       cout<<"Enter number of comments : ";
       cin>>numcom;
       cout<<"Enter number of Likes : ";
       cin>>numlikes;
       node *nn = new node(name,index,date,month,year,numlikes,numcom);
       F[i] = nn;
    }
}
void Facebook :: Connect_user(){
    int n,src,dest;
    cout<<"\nEnter the number of connections : ";
    cin>>n;
     cout<<"\nEnter the index of source and destination of user : ";
    for(int i=0;i<n;i++){
    cin>>src>>dest;
    Connect(src,dest);
    Connect(dest,src);
    }
}
void Facebook :: Connect(int src,int dest){
    node *p,*q;
    p = F[src];
    q = new node(*F[dest]); //copy of source node
    q->next = NULL;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = q;
    frnd[src]++;
}
void Facebook :: Display_userdetails(){
cout<<"\t________All USER DETAILs________";
cout<<"\n-----------------------------------------------------------------------------------------------------"<<endl;
cout<<"Index |"<<"Name of User|"<<"Date of Birth   |"<<"No. of Likes   | "<<"No. of comments  |"<<"No. of Friends";
cout<<"\n-----------------------------------------------------------------------------------------------------"<<endl;
for(int i = 0;i<num_users;i++){
        node *p = F[i];
        cout<<"\n";
    cout<<p->index<<"\t"<<p->name<<"\t      "<<p->date<<"/"<<p->month<<"/"<<p->year<<"\t\t"<<p->numlikes<<"\t\t   "<<p->numcom<<"\t\t"<<frnd[i];
}
cout<<"\n-----------------------------------------------------------------------------------------------------"<<endl;
}
void Facebook :: Max_friends(){
int max =0,ind;
for(int i =0;i<num_users;i++){
   if(max<frnd[i]){
    max = frnd[i];
    ind = i;
   }
}
cout<<"\nMaximum number of friends are of "<<F[ind]->name<<" and are "<<max<<endl;
}
void Facebook ::Traverse_BFS(){
    que q;
int max = 0,min = 9999;
int ind1,ind2=0;
for(int i=0;i<num_users;i++){
    visited[i]=0;
}
node* node1,*p = F[0];
cout<<"visited "<<p->name<<endl;
visited[p->index] = 1;
max = p->numcom;
min = p->numcom;
ind1 = p->index;
ind2 = p->index;
q.enqueue(p);
while(!q.isempty()){
    node1 = q.deque();
    p = node1->next;
    while(p!=NULL){
        if(visited[p->index]==0){
            if(max<p->numcom){
                max = p->numcom;
                ind1 = p->index;
            }
            if(min>p->numcom){
                min= p->numcom;
                ind2 = p->index;
            }
            cout<<"Visited "<<p->name<<endl;
            visited[p->index]=1;
            q.enqueue(p);
        }
        p=p->next;
    }
}
cout<<"Maximum Comments are "<<max<<" and are of "<<ind1<<endl;
cout<<"Minimum Comments are "<<min<<" and are of "<<ind2<<endl;

}
void Facebook ::Traverse_DFS(){
    cout<<"\nEnter the birthday month to find : ";
    cin>>mon;
    for(int i=0;i<num_users;i++)
        visited[i]=0;
    DFS(F[0],mon);


}
void Facebook ::DFS(node *p,int month){
    if(mon==p->month){
        cout<<" matched "<<p->name<<"\t"<<p->index<<endl;
    }
    cout<<" Visited "<<p->name<<endl;
    visited[p->index] = 1;
    p= p->next;
    while(p!=NULL){
        if(visited[p->index]==0){
            DFS(p,month);

        }
        p = p->next;
    }

}

int main(){
int ch,ans;
Facebook network;
cout<<"\n*****MENU*****";
cout<<"\n1.Add user details to facebook network";
cout<<"\n2.Make a friend connection ";
cout<<"\n3.Find who is having maximum friends";
cout<<"\n4.Find who has post maximum and minimum comments ";
cout<<"\n5.Find users having birthday in given month";
cout<<"\n6.Display the details of all users in the network ";
cout<<"\nENTER YOUR CHOICE:";
    cin>>ch;
do
{
    switch(ch)
    {
    case 1:
       network.Add_user();
    break;
    case 2:
       network.Connect_user();
    break;
    case 3:
       network.Max_friends();
    break;
    case 4:
          network.Traverse_BFS();
    break;
    case 5:
        network.Traverse_DFS();
    break;
    case 6:
         network.Display_userdetails();
    break;
    }
    }while(ch!=7);
}
