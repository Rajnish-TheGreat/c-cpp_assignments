#include <iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>

using namespace std;

class medicine{
    int id;
    char name[20];
    char supplier[20];
    char company[20];
    char exp[20];
    float price;
    int stock;
    public:
    medicine();
    void getDetails();
    void printDetails(int y);
    int matchName(char* entry);
    friend medicine swap(medicine med, medicine medi);
    void printStock();
    void printName();
    void addStock();
    int sellStock();
    int makeAmount(int sell);
    void printBillDetails(int amount, int stocks, int y);
};

std::ofstream file,numFile;
std::ifstream file1,numFile1;
int t;
COORD coord = {0, 0};

void gotoxyz (int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

inline medicine::medicine(){
    id=0;
    price=0;
}

inline void medicine::getDetails(){
    system("CLS");
    SetColor(13);
    gotoxyz(85,15);
    cout<<"Enter medicine ID: ";
    SetColor(9);
    cin>>id;
    SetColor(13);
    gotoxyz(85,18);
    cout<<"Enter medicine name: ";
    fflush(stdin);
    SetColor(9);
    gets(name);
    SetColor(13);
    gotoxyz(85,21);
    cout<<"Enter medicine company name: ";
    fflush(stdin);
    SetColor(9);
    gets(company);
    SetColor(13);
    gotoxyz(85,24);
    cout<<"Enter medicine supplier name: ";
    fflush(stdin);
    SetColor(9);
    gets(supplier);
    gotoxyz(85,27);
    cout<<"Enter the medicine price: ";
    SetColor(9);
    cin>>price;
    SetColor(13);
    gotoxyz(85,30);
    cout<<"Enter medicine stock: ";
    SetColor(9);
    cin>>stock;
    SetColor(13);
    gotoxyz(85,33);
    cout<<"Enter expiry date: ";
    fflush(stdin);
    SetColor(9);
    gets(exp);
}

inline void medicine::printDetails(int y){
    SetColor(3);
    gotoxyz(30,y);
    cout<<id;
    gotoxyz(45,y);
    cout<<name;
    gotoxyz(65,y);
    cout<<company;
    gotoxyz(85,y);
    cout<<supplier;
    gotoxyz(105,y);
    cout<<price;
    gotoxyz(120,y);
    cout<<stock;
    gotoxyz(135,y);
    cout<<exp;
}
inline int medicine::matchName(char *entry){
    int match;
    char namelwr[20], entrylwr[20];
    strcpy(namelwr,name);
    strcpy(entrylwr, entry);
    match = strcmp(entrylwr,strlwr(namelwr));
    if(match==0)
        return 1;
    else
        return 10;
}

inline void medicine::printStock(){
    SetColor(8);
    cout<<stock;
}

inline void medicine::printName(){
    SetColor(8);
    cout<<name;
}

inline void medicine::addStock(){
    int additionalStock;
    gotoxyz(85,20);
    cout<<"Enter added medicine stock: ";
    cin>>additionalStock;
    stock=stock+additionalStock;
}

inline int medicine::sellStock(){
    int sellingStock;
    gotoxyz(85,35);
    cout<<"How many medicine stock you want to sell?";
    cin>>sellingStock;
    if(sellingStock>stock){
        gotoxyz(85,40);
        cout<<"Enough stock not available at the moment, please try adding more stock for "<<name<<"\n";
        return -1;
    }
    stock=stock-sellingStock;
    return sellingStock;
}

inline int medicine::makeAmount(int sell){
    float amount;
    amount = price*sell;
    return amount;
}

medicine swap(medicine med,medicine medi){
    med=medi;
    return med;
}

inline void medicine::printBillDetails(int amount, int stocks, int y){
    gotoxyz(45,y);
    cout<<id;
    gotoxyz(60,y);
    cout<<name;
    gotoxyz(80,y);
    cout<<price;
    gotoxyz(95,y);
    cout<<stocks;
    gotoxyz(110,y);
    cout<<amount;
}

inline void printBill(int *printBillEntries, int *printBillStockEntries, int *printBillAmountEntries, char *username, int num, int loopOpt){
    int i, grandTotal = 0, y=15;
    char namePass[20];
    medicine med[num];
    strcpy(namePass, username);
    file1.open(namePass,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();
    system("CLS");
    gotoxyz(45,15);
    cout<<"Medicine ID";
    gotoxyz(60,15);
    cout<<"Medicine name";
    gotoxyz(80,15);
    cout<<"price per unit";
    gotoxyz(95,15);;
    cout<<"stocks sold";
    gotoxyz(110,15);
    cout<<"Total";
    for (i=0 ; i<loopOpt ; i++){
        y=y+3;
        med[printBillEntries[i]].printBillDetails(printBillAmountEntries[i], printBillStockEntries[i], y);
        cout<<"\n";
        Sleep(100);
    }
    for(i=0 ; i< loopOpt ; i++)
    {
        grandTotal = grandTotal + printBillAmountEntries[i];
    }
    gotoxyz(105,50);
    cout<<"Grand Total: "<<grandTotal;
}

bool fexists(const char *filename){
    ifstream ifile(filename);
    return ifile;
}

inline int readNum(char* username){
    int num;
    bool fileExitst;
    char useName[20];
    strcpy(useName,username);
    strcat(useName,"numfile.txt");
    fileExitst = fexists(useName);
    if(fileExitst==0){
        return 0;
    }
    numFile1.open(useName,ios::in);
    numFile1 >> num;
    if (num<0){
        num=0;
        numFile.open(useName,ios::out);
        numFile << num;
        numFile.close();
        return num;
    }
    numFile1.close();
    return num;
}

inline int increaseNum(int num, char* username)
{    strcat(username,"numfile.txt");
    num++;
    numFile.open(username,ios::out);
    numFile << num;
    numFile.close();
    return num;
}
inline int decreaseNum(int num, char* username)
{    strcat(username,"numfile.txt");
    num--;
    numFile.open(username,ios::out);
    numFile << num;
    numFile.close();
    return num;
}

inline int searchTheMedicine(int num, char* entry, char* username)
{   int match=10,i;
    medicine med[num+1];
    char entryPass[20];
    strcpy(entryPass, entry);
    file1.open(username,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();

    gotoxyz(85,20);
    cout<<"Searching database for medicine";
    for(i=0 ; i<3 ; i++)
    {
        cout<<".";
        Sleep(550);
    }
    cout<<"\n";
    for(i=0 ; i<num ; i++)
    {
        if(match==10)
        {
            match = med[i].matchName(entryPass);
        }
        if(match==1)
        { return i;
        }
    }
    if(i>=num)
    {
        return -1;
    }
}
inline int purchaseMedicine(int num, char* username)
{           
    if(num==0){
        file.open(username,ios::out);
        file << "this is some random text";
        file.close();
    }
    int i;
    char namePass[20];
    strcpy(namePass,username);
    char cont, entry[20];
    medicine med[num+1];
    file1.open(username,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();
    system("CLS");
    gotoxyz(85,15);
    cout<<"Enter name of medicine to add: ";
    fflush(stdin);
    gets(entry);
    i=searchTheMedicine(num,entry,namePass);
    if(i==-1){
        gotoxyz(85,25);
        cout<<"Medicine not found in database, ";
        cout<<"proceeding to add medicine...";
        Sleep(500);
        med[num].getDetails();
        file.open(username,ios::out);
        file.write((char*)&med,sizeof(med));
        file.close();
        num=increaseNum(num,namePass);
        return num;
    }
    else{
        gotoxyz(85,25);
        cout<<"Medicine already exists in database.";
        gotoxyz(85,30);
        cout<<"Do you want to update the stock of ";
        med[i].printName();
        cout<<"(y/n)?";
        gotoxyz(85,35);
        cin>>cont;
        if(cont=='y')
        {   system("CLS");
            gotoxyz(85,15);
            cout<<"Current stock for ";
            med[i].printName();
            cout<<"is ";                
            med[i].printStock();
            med[i].addStock();
            file.open(username,ios::out);
            file.write((char*)&med,sizeof(med));                
            file.close();
            gotoxyz(85,25);
            cout<<"Stock added sucessfully...";
            return num;
        }
    }
}


inline printAllMedicine(int num, char* username)
{    int i, y;
    medicine med[num];
    if (num==0){
        cout<<"No medicines available\n";
        return 0;
    }
    file1.open(username,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();
    system("CLS");
    gotoxyz(30,10);
    cout<<"Medicine ID";
    gotoxyz(45,10);
    cout<<"Medicine Name";
    gotoxyz(65,10);
    cout<<"Company Name";
    gotoxyz(85,10);
    cout<<"Supplier Name";
    gotoxyz(105,10);
    cout<<"Price";
    gotoxyz(120,10);
    cout<<"Stock";
    gotoxyz(135,10);
    cout<<"Expiry date";
    y=10;
    for (i=0 ; i<num ; i++){
        y=y+3;
        med[i].printDetails(y);
        cout<<"\n";
        Sleep(100);
    }
}

inline void searchMedicine(int num, char* username)
{   int i,y=35;
    char namePass[20];
    strcpy(namePass, username);
    char entry[20];
    medicine med[num];
    file1.open(username,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();
    system("CLS");
    gotoxyz(85,15);
    cout<<"Enter name of medicine: ";
    fflush(stdin);
    gets(entry);
    strlwr(entry);
    gotoxyz(85,20);
    i=searchTheMedicine(num,entry,namePass);
    if(i==-1)
    {   gotoxyz(85,25);
        cout<<"Given medicine not found\n";
    }
    else
        {   gotoxyz(85,25);
            printf("Medicine Found in database\n");
            Sleep(250);
            gotoxyz(85,30);
            cout<<"fetching medicine details\n";
            Sleep(250);
            system("CLS");
            gotoxyz(30,10);
            cout<<"Medicine ID";
            gotoxyz(45,10);
            cout<<"Medicine Name";
            gotoxyz(65,10);
            cout<<"Company Name";
            gotoxyz(85,10);
            cout<<"Supplier Name";
            gotoxyz(105,10);
            cout<<"Price";
            gotoxyz(120,10);
            cout<<"Stock";
            gotoxyz(135,10);
            cout<<"Expiry date";

            med[i].printDetails(15);
        }
}


inline int deleteMedicine (int num, char* username)
{   int i;
    char namePass[20];
    strcpy(namePass, username);
    char entry[20];
    medicine med[num];
    file1.open(username,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();
    system("CLS");
    gotoxyz(85,15);
    cout<<"Enter medicine to be deleted: ";
    fflush(stdin);
    gets(entry);
    strlwr(entry);
    i = searchTheMedicine(num,entry,namePass);
    if(i==-1)
    {   gotoxyz(85,25);
        cout<<"Medicine not found in store\n";
        return num;
    }
    else
    {   for(i=i ; i<num ; i++)
        {
            med[i]=swap(med[i],med[i+1]);
        }
        file.open(username,ios::out);
        file.write((char*)&med,sizeof(med));
        file.close();
        num=decreaseNum(num,namePass);
        gotoxyz(85,25);
        cout<<"Medicine deleted sucessfully.\n";
        return num;
    }
}

inline int sellMedicine(int num, char* username)
{   int i,amount=0,sellingStock,printBillEntries[num], loopOpt=0, printBillStockSoldEntries[20], printBillAmountEntries[num];
    char cont='0',entry[20],namePass[20];
    strcpy(namePass,username);
    medicine med[num];
    file1.open(username,ios::in);
    file1.read((char*)&med,sizeof(med));
    file1.close();
    do{
    system("CLS");
    gotoxyz(85,15);
    cout<<"Enter medicine to be sell: ";
    fflush(stdin);
    gets(entry);
    strlwr(entry);

    i = searchTheMedicine(num,entry,namePass);
    if(i==-1)
        {   gotoxyz(85,25);
            cout<<"medicine not found in store\n";

        }
        else
        {   gotoxyz(85,25);
            cout<<"Medicine found";
            gotoxyz(85,30);
            cout<<"Current stock for ";
            med[i].printName();
            cout<<" is ";
            med[i].printStock();
            sellingStock=med[i].sellStock();
            if(sellingStock==-1)
                return num;
            amount = med[i].makeAmount(sellingStock);
            printBillStockSoldEntries[loopOpt]=sellingStock;
            printBillAmountEntries[loopOpt]=amount;
            printBillEntries[loopOpt]= i;
            loopOpt++;
        }
        gotoxyz(85,40);
        cout<<"Do you want to sell more medicines?(y/n) ";
        cin>>cont;
    }while(cont=='y');
        printBill(printBillEntries, printBillStockSoldEntries, printBillAmountEntries, namePass, num, loopOpt);
        gotoxyz(85,54);
        cout<<"Press any key if transaction is sucessfull\n";
        fflush(stdin);
        getchar();
        file.open(username,ios::out);
        file.write((char*)&med,sizeof(med));
        file.close();
        gotoxyz(85,58);
        cout<<"Stock updated sucessfully...";
        return num;
}
inline int chooseOperation()
{   system("CLS");
    int opt;
    gotoxyz(85,15);
    cout<<"Select operation";
    gotoxyz(85,20);
    cout<<"1. Purchase Medicine";
    gotoxyz(85,25);
    cout<<"2. Search Medicine";
    gotoxyz(85,30);
    cout<<"3. Show all medicines";
    gotoxyz(85,35);
    cout<<"4. Delete Medicine";
    gotoxyz(85,40);
    cout<<"5. Sell Medicine";
    gotoxyz(85,45);
    cout<<"6. No. of medicine in Store";
    gotoxyz(85,50);
    cin>> opt;
    return opt;
}


inline void printNumberOfMedicines(int num)
{
    cout<<"the number of total medicines in library is "<<num;
}



