#include <iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<process.h>

using namespace std;

class file{
    int roll;
    int age;
    int gr_no;
    char name[50];
    public:
    void input();
    void show();
    char *getn(){
        return name;
    }
};file db;

void file::input(){
    cout<<"Name: ";
    fflush(stdin);
    gets(name);
    fflush(stdin);
    cout<<"\nRoll No: ";
    cin>>roll;
    cout<<"\nGR No: ";
    cin>>gr_no;
    cout<<"\nAge: ";
    cin>>age;
}
void file::show(){
    cout<<"Name==> "<<name<<endl;
    cout<<"Roll_No==> "<<roll<<endl;
    cout<<"GR_No==> "<<gr_no<<endl;
    cout<<"Age ==> "<<age<<endl;
}

void create();
void display();
void add();
void modify();
void del();

fstream fp;

int main(){
    int choice;
    do{
        cout<<"\n\tMenu: \n1 Create DB \n2 Display Record \n3 Add Record \n4 Modify Record \n5 Delete Record \n6 Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                add();
                break;

            case 4:
                modify();
                break;

            case 5:
               del();
                break;

            case 6:
                break;

            default:
                cout<<"\nInvalid Choice";
                break;

        }
    }while(choice != 6);
}

void create(){
    char ch='y';
    fp.open("db.txt",ios::out| ios::binary);
    while(ch=='y' || ch =='Y'){
        db.input();
        fp.write((char*)&db, sizeof(db));
        cout<<"Enter(Y/y) to continue: ";
        cin>>ch;
    }
    fp.close();
}
void display(){
    fp.open("db.txt",ios::in| ios::binary);
    if(!fp){
		cout<<"File not Found";
	}
	else{
        fp.read((char*)&db, sizeof(db));
        while(!fp.eof()){
            db.show();
            fp.read((char*)&db, sizeof(db));
            cout<<"\n";
        }
    }
    fp.close();
}
void add(){
	char ch='y';
	fp.open("db.txt",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		db.input();
		fp.write((char*)&db, sizeof(db));
		cout<<"Enter(Y/y) to continue: ";
        cin>>ch;
	}
	fp.close();
}
void modify(){
    char temp[50];
    cout<<"\nEnter Name of Student: ";
    fflush(stdin);
    gets(temp);
    fflush(stdin);
    fp.open("db.txt",ios::in| ios::out|ios::binary);
    if(!fp){
		cout<<"File not Found";
	}
	else{
        fp.read((char*)&db, sizeof(db));
        while(!fp.eof()){
            if(strcmp(temp,db.getn())==0){
                fp.seekg(0,ios::cur);
                cout<<"Enter New Record.."<<endl;
                db.input();
                fp.seekp(fp.tellg() - sizeof(db));
                fp.write((char*)&db, sizeof(db));
            }
            else
                cout<<"\nRecord not Found"<<endl;
            fp.read((char*)&db, sizeof(db));
        }
	}
    fp.close();
}
void del(){
    char temp[50];
    fflush(stdin);
    cout<<"\nEnter Name of the Student: ";
    gets(temp);
    fflush(stdin);
    ofstream o;
    o.open("new.dat",ios::out|ios::binary);
    fp.open("db.txt",ios::in| ios::binary);
    if(!fp){
        cout<<"File not Found";
    }
    else{
        fp.read((char*)&db, sizeof(db));
        while(!fp.eof()){
            if(strcmp(temp,db.getn())!=0){
                o.write((char*)&db, sizeof(db));
            }
        fp.read((char*)&db, sizeof(db));
        }
    }
    o.close();
    fp.close();
    remove("db.txt");
    rename("new.dat", "db.txt");
}
