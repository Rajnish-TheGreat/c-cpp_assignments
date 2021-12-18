#include <iostream>

using namespace std;

class Shape{
    protected:
        double len,bre;
    public:
        void virtual getdimensions()=0;
        void virtual compute_area()=0;
};
class triangle:public Shape{
    public:
        void getdimensions(){
            cout<<"\nEnter:";
            cout<<"\nBase: ";
            cin>>len;
            cout<<"\nHeight: ";
            cin>>bre;
        }
        void compute_area(){
            cout<<"\nArea of Triangle: "<<(0.5*len*bre);
        }
};
class rectangle:public Shape
{
    public:
        void getdimensions(){
            cout<<"\nEnter:";
            cout<<"\nLength: ";
            cin>>len;
            cout<<"\nBreadth: ";
            cin>>bre;
        }
        void compute_area(){
            cout<<"\nArea of Rectangle: "<<(len*bre);
        }
};
int main()
{
    int choice;
    Shape * s1;
    triangle t1;
    rectangle r1;
    do{
        cout<<"\n\tMenu: \n1 Calculate area of Triangle \n2 Calculate area of Rectangle \n3 Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
		switch(choice){
			case 1:
                s1=&t1;
                s1->getdimensions();
                s1->compute_area();
                break;
            case 2:
                s1=&r1;
                s1->getdimensions();
                s1->compute_area();
                break;
            case 3:
				break;
			default:
				cout<<"\nInvalid Choice!!!";
		}
    }while (choice!=3);
    return 0;
}
