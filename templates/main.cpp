#include<iostream>

using namespace std;

template <class t>
class matrices{
    int i,j;
    t m[10][10];
    public:
    void input(int,int);
    void display(matrices&,int,int);
    void sub(matrices&,matrices&,matrices&,int,int);
    void add(matrices&,matrices&,matrices&,int,int);
    void mul(matrices&,matrices&,matrices&,int,int);
};
template <class t> void matrices <t> :: input(int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
}
template <class t> void matrices <t> :: add(matrices<t> &m1,matrices<t> &m2,matrices<t> &m3,int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            m3.m[i][j]=m1.m[i][j]+m2.m[i][j];
            cout<<"\t";
            cout<<m3.m[i][j];
        }
        cout<<"\n";
    }
}
template <class t> void matrices <t> :: sub(matrices <t> &m1,matrices <t> &m2,matrices<t> &m3,int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            m3.m[i][j]=m1.m[i][j]-m2.m[i][j];
            cout<<"\t";
            cout<<m3.m[i][j];
        }
        cout<<"\n";
    }
}
template <class t> void matrices <t> :: mul(matrices <t> &m1,matrices <t> &m2,matrices<t> &m3,int r,int c)
{
    int i,j,k;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            for(k=0;k<r;k++){
                m3.m[i][j]=m[i][j]+(m1.m[i][k]*m2.m[k][j]);
            }
        }
    }
    for(i=0;i<r;i++)
    {
        cout<<"\n";
        for(j=0;j<c;j++)
        {
            cout<<"\t";
            cout<<m3.m[i][j];
        }
    }
}
template <class t> void matrices <t> :: display(matrices<t> &m,int r,int c)
{
    int i=0,j=0;
    for(i=0;i<r;i++)
    {
        cout<<"\n";
        for(j=0;j<c;j++)
        {
            cout<<"\t";
            cout<<m.m[i][j];
        }
    }
}
int main(){
    int r1,r2,c1,c2,choice;
    matrices<double> m1,m2,m3;
    do{
        cout<<"\n\tMenu:\nEnter \n0 Input matrix \n1 For Addition \n2 For Subtraction \n3 For Multiplication \n4 To Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Enter number of rows and column of the first matrix:\n";
                cin>>r1>>c1;
                cout<<"Enter the elements of first matrix:\n";
                m1.input(r1,c1);
                cout<<"Enter number of rows and column of the second matrix:\n";
                cin>>r2>>c2;
                cout<<"Enter the elements of second matrix:\n";
                m2.input(r2,c2);

                cout<<"\nFirst matrix is :\n";
                m1.display(m1,r1,c1);
                cout<<"\nsecond matrix is :\n";
                m2.display(m2,r2,c2);
                break;
            case 1:
                if(r1==r2 && c1==c2){
                    m3.add(m1,m2,m3,r1,c1);
                }
            else
                cout<<"WARNING!!! Can't add matrix of different orders\n";
            break;

            case 2:
                if(r1==r2 && c1==c2){
                    m3.sub(m1,m2,m3,r1,c1);
                }
            else
                cout<<"WARNING!!! Can't subtract matrix of different orders\n";
            break;

            case 3:
                if (c1==r2){
                    m3.mul(m1,m2,m3,r1,c2);
                }
            else
                cout<<"WARNING!!! Can't multiply matrix of entered order\n";
            break;

            case 4:
            break;
            default:
                cout<<"Invalid Choice";
        }
    }while(choice!=4);
    return 0;
}
