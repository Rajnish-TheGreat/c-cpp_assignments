#include <iostream>

using namespace std;

class number{
    double a,b;
    public:
    void input(){
        cout<<"\nEnter two numbers to divide(a/b): \na= ";
        cin>>a;
        cout<<"\nb= ";
        cin>>b;
    }
    void div(){
        try{
            if(cin.fail())
                throw "Error!!!";
            if(b==0)
                throw 0;
            cout<<"\nAns(a/b)= "<<a/b;
        }
        catch(const int n){
            cout << "\nDivision by "<<n<<" not allowed.\nGo and learn Maths:-D:-D:-D\n";
        }
        catch(const char* Str){
            cout<< Str;
        }
    }
};

int main()
{
    int choice;
    number num;
    do{
        cout<<"\n\tMenu: \n1 Enter number \n2 Perform Division \n3 Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
		switch(choice){
			case 1:
                num.input();
                break;
            case 2:
                num.div();
                break;
            case 3:
                break;
            default:
				cout<<"\nInvalid Choice!!!";
		}
    }while (choice!=3);
    return 0;
}
