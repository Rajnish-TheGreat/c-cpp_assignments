#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include"medicines.h"
#include"login.h"
using namespace std;


void gotoxyzw (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    int medNum,cont;
    char usernamearray[20], usernamePass[20];
    char* username ;
    username = login(usernamearray);
    strcpy(usernamePass,username);


    getchar();

    medNum = readNum(usernamePass);

    do{
        switch(chooseOperation()){
            case 1:
                medNum = purchaseMedicine(medNum,usernamePass);
                break;
            case 2:
                searchMedicine(medNum,usernamePass);
                break;
            case 3:
                printAllMedicine(medNum,usernamePass);
                break;
            case 4:
                medNum= deleteMedicine(medNum,usernamePass);
                break;
            case 5:
                medNum=sellMedicine(medNum,usernamePass);
                break;
            case 6:
                printNumberOfMedicines(medNum);
                break;
            default:
                cout<<"Invalid Choice of operation\n";
                Sleep(700);

        } 
    gotoxyzw(85,60);
    cout<<"Press 1 to continue or anything else to exit\n";
    gotoxyzw(85,63);
    cin>>cont;


    }while(cont==1);

return 0;




}

