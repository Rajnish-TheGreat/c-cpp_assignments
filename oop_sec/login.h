#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<time.h>

using namespace std;

class profile{
    char username[20];
    char password[20];
public:
    void getProfileDetails();
    int matchUsername(char* inputUsername);
    int matchPassword(char* inputPassword);
};

ofstream profileNumFileOut, profileFileOut;
ifstream profileNumFileIn, profileFileIn;
int st;



void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int ForgC, int t){
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

inline void profile::getProfileDetails(){
    system("CLS");
    gotoxy(160,10);
    time_t t;
    time(&t);
    SetColor(14);
    cout<<ctime(&t);
    SetColor(13);
    gotoxy(85,15);
    cout<<"Enter your Username: ";
    fflush(stdin);
    SetColor(9);
    gets(username);
    SetColor(13);
    gotoxy(85,20);
    cout<<"Enter your Password: ";
    fflush(stdin);
    SetColor(9);
    gets(password);
}

inline int profile::matchUsername(char* inputUsername){
    int cmp;
    char usernameLwr[20];
    strcpy(usernameLwr,username);
    cmp = strcmp(strlwr(inputUsername), strlwr(usernameLwr));
    if(cmp==0)
        return 1;
    else
        return 10;
}

inline int profile::matchPassword(char* inputPassword){
    int  cmp;
    cmp=strcmp(password, inputPassword);
    if(cmp==0)
        return 1;
    else
        return 0;
}
inline int readNumberOfProfiles(){
    int num=0;
    profileNumFileIn.open("profileNumFile.txt",ios::in);
    profileNumFileIn >> num;
    if(num<0){
        profileNumFileOut.open("profileNumFile.txt",ios::out);
        profileNumFileOut << 0;
        profileNumFileOut.close();
        return 0;
    }
    profileNumFileIn.close();
    return num;
}

inline int increaseProfileCount(int num){
    num++;
    profileNumFileOut.open("profileNumFile.txt",ios::out);
    profileNumFileOut << num;
    profileNumFileOut.close();
    return num;
}


inline int decreaseProfileCount(int num){
    num--;
    profileNumFileOut.open("profileNumFile.txt",ios::out);
    profileNumFileOut << num;
    profileNumFileOut.close();
    return num;
}

inline char* signInUser(int num, char *username)
{   int i, matchU=10, matchP=10;
    profile pro[num];
    profileFileIn.open("profileData.txt",ios::in);
    profileFileIn.read((char*)&pro,sizeof(pro));
    profileFileIn.close();
    char inputUsername[20], inputPassword[20];
    system("CLS");
    gotoxy(160,10);
    time_t t;
    time(&t);
    SetColor(14);
    cout<<ctime(&t);
    SetColor(13);
    gotoxy(85,15);
    cout<<"Enter your username: ";
    fflush(stdin);
    SetColor(9);
    gets(inputUsername);
    SetColor(13);
    gotoxy(85,20);
    cout<<"Enter your password: ";
    fflush(stdin);
    SetColor(9);
    gets(inputPassword);
    for(i=0 ; i< num ; i++)
    {
        if(matchU==10){
            matchU= pro[i].matchUsername(inputUsername);
        }
        if(matchU==1){
            matchP = pro[i].matchPassword(inputPassword);
            if(matchP==1){
                gotoxy(85,25);
                cout<<"Login Successful\n";
                strcpy(username,inputUsername);
                return username;
            }
            else
            {   gotoxy(85,25);
                cout<<"Login failed!!!\n";
                exit(1);
            }
        }
    }
    if(i>=num)
        gotoxy(85,25);
        cout<<"Error 404\n";
        exit(1);


}

inline int addUser(int num)
{
    profile pro[num+1];
    profileFileIn.open("profileData.txt",ios::in);
    profileFileIn.read((char*)&pro,sizeof(pro));
    profileFileIn.close();
    pro[num].getProfileDetails();
    profileFileOut.open("profileData.txt", ios::out);
    profileFileOut.write((char*)&pro,sizeof(pro));
    profileFileOut.close();
    num = increaseProfileCount(num);
    gotoxy(85,20);
    cout<<"Profile added\n";
    return num;
}

inline void printCurrentNumberOfUsers(int num)
{
    cout<<"current no. of profiles is "<<num<<"\n";
}
inline int chooseLoginOperation()
{   int opt;
    system("CLS");
    gotoxy(160,10);
    time_t t;
    time(&t);
    SetColor(14);
    cout<<ctime(&t);
    SetColor(13);
    gotoxy(85,10);
    cout<<"Choose login operation";
    gotoxy(85,15);
    SetColor(6);
    cout<<"1.Sign-In for existing user";
    gotoxy(85,20);
    SetColor(6);
    cout<<"2.Add new user";
    gotoxy(85,25);
    cin>>opt;
    return opt;
}
char* login(char *usernameMain)
{   int num;
    char username[20];
    char* usernamePtr;
    num = readNumberOfProfiles();
do{
    switch(chooseLoginOperation())
    { case 1:
        usernamePtr = signInUser(num, username);
        strcpy(usernameMain,usernamePtr);
        return usernameMain;
        break;
    case 2:
        num = addUser(num);
        break;
    case 3:
        printCurrentNumberOfUsers(num);
        break;

    }
    getchar();
    }while(1);
}

