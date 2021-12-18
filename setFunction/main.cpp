#include<iostream>
using namespace std;

void unionofarray(int a[],int b[], int m ,int n)
{
  int i=0,j=0;
    cout<<"\n\nUnion Of Array\n\n";

  while(i<m && j<n)
    {
      if(a[i]<b[j])
        cout<<a[i++]<<" ";
      else if(a[i]>b[j])
        cout<<b[j++]<<" " ;
      else
      {
        cout<<a[i++]<<" ";
        j++;
      }
    }
  while(i<m)
    cout<<a[i++]<<" ";
  while(j<n)
    cout<<b[j++]<<" ";
}
void intersection(int a[],int b[],int m,int n)
{
  int i=0,j=0;
    cout<<"\n\nIntersection Of Array\n\n";
    while(i<m && j<n)
    {
        if(a[i]<b[j])
      i++;
      else if(a[i]>b[j])
      j++ ;
      else
      {
        cout<<a[i++]<<" ";
        j++;
      }
    }
}

int main()
{
  int m,i,j,n,ch,a[100],b[100];
  char opt;
  cout<<"Enter The Size Of First Array \n";
  cin>>m;
  cout<<"\nEnter The Element In First Array \n";
  for(i=0;i<m;i++)
  {
    cin>>a[i];
  }

  cout<<"\nEnter The Size Of Second Array \n";
  cin>>n;
  cout<<"\nEnter The Element In Second Array \n";
  for(j=0;j<n;j++)
  {
    cin>>b[j];
  }
  do {
  cout<<"Press\n1.Union\n2.Intersection\n";
  cin>>ch;
  switch(ch) {
    case 1:
      unionofarray(a,b,m,n);
      break;
    case 2:
      intersection(a,b,m,n);
      break;
    default:
      cout<<"Invalid Choice";
  }
  cout << "\nDo you want to continue(y/n) : ";
  cin >> opt;
  }while(opt == 'y');

  return 0;
}
