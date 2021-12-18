#include<iostream>

using namespace std;

class complex
{
    float real,img;
    public:
    complex(){
        real = 0;
        img = 0;
    }
    void input(){
        cout<<"\nReal Part: ";
        cin>>real;
        cout<<"\nImaginary Part: ";
        cin>>img;
    }
    void display(){
        if(img<0)
            cout<<"\nComplex Number: "<<real<<img<<"i";
        else
            cout<<"\nComplex Number: "<<real<<"+"<<img<<"i";
    }
    friend complex operator+(complex c1, complex c2);
    friend complex operator-(complex c1, complex c2);
    complex operator*(complex c1);
    complex operator/(complex c1);

};

complex operator+(complex c1,complex c2){
    complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}
complex operator-(complex c1,complex c2){
    complex temp;
    temp.real = c1.real - c2.real;
    temp.img = c1.img - c2.img;
    return temp;
}
complex complex::operator*(complex c2){
    complex temp;
    temp.real=real*c2.real-img*c2.img;
    temp.img=real*c2.img+img*c2.real;
    return temp;
}
complex complex::operator/(complex c2){
    complex temp;
    float real_num, img_num,den;
    real_num=real*c2.real+img*c2.img;
    den=c2.real*c2.real+c2.img*c2.img;
    img_num=img*c2.real-real*c2.img;
    temp.real=real_num/den;
    temp.img=img_num/den;
    return temp;
}
int main(){
    int choice;
    complex c1,c2,c3;
    cout<<"\nEnter 1st Complex number";
    c1.input();
    cout<<"\nEnter 2nd Complex number";
    c2.input();
    cout<<"\nEntered Complex numbers are: \n";
    c1.display();
    c2.display();
    do
    {
        cout<<"\n\tMENU: \n1.Addition \n2.Subtraction \n3.Multiplication \n4.Division \n5.Exit \nEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            c3=c1+c2;
            c3.display();
            break;
        case 2:
            c3=c1-c2;
            c3.display();
            break;
        case 3:
            c3=c1*c2;
            c3.display();
            break;
        case 4:
            c3=c1/c2;
            c3.display();
            break;
        default:
            cout<<"Invalid Choice";
            break;
        }
    }while(choice!=5);
    return 0;
}

