#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string>

using namespace std;

int Authentication();
void menu();
void show();

class vaccine
{
    typedef struct VACCINE
    {
        int age;
        int temperature;
        int blood_pressure;
        char gender;
        int aadhar_id;
        int mobile_number;
        string profession;
        string address;
        string name;
    } Rec;
    typedef struct INDEX
    {
        int aadhar_id;
        int position;
    } Ind_Rec;
    Rec Records;
    Ind_Rec Ind_Records;

public:
    void add_New_Data();
    void setdata();
    void view_Vaccine_Data();
    void update_Data();
    void search_Data();
    void showdata();
    void show();
    void show_list();
    void search_by_Aadhar();
    void search_by_Age();
    void search_by_Profession();
    void search_by_Gender();
    void display_Data();
};

void vaccine::add_New_Data()
{
    char ch = 'y';
    fstream seqfile;
    fstream indexfile;
    int pos;
    int i = 0;
    indexfile.open("IND.DAT", ios::in | ios::binary);
    indexfile.seekg(0, ios::end);
    i = indexfile.tellg() / sizeof(Ind_Records);
    indexfile.close();

    indexfile.open("IND.DAT", ios::app | ios::binary);
    seqfile.open("VACCINEDB.DAT", ios::app | ios::binary);

    do
    {
        system("cls");
        setdata();
        seqfile.write((char *)&Records, sizeof(Records)) << flush;
        Ind_Records.aadhar_id = Records.aadhar_id;
        Ind_Records.position = i;
        indexfile.write((char *)&Ind_Records, sizeof(Ind_Records));
        cout << "\n\n\t\t\t\t\t\t\t\t\tYOUR DATA HAS BEEN SUCCESSFULLY INSERTED !" << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\tDo you want to add more records?  ";
        i++;
        cin >> ch;
    } while (ch == 'y');
    seqfile.close();
    indexfile.close();
}
void vaccine::setdata()
{
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|              REGISTRATION WINDOW             |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";

    cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter name  :  ";
    cin >> Records.name;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Aadhar  :  ";
    cin >> Records.aadhar_id;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Gender( M|F|O)   :  ";
    cin >> Records.gender;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Age   :  ";
    cin >> Records.age;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Profession (all letters should be small)   :  ";
    cin >> Records.profession;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Blood Pressure   :  ";
    cin >> Records.blood_pressure;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Temperature  :  ";
    cin >> Records.temperature;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Address   :  ";
    cin >> Records.address;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Contact number   :  ";
    cin >> Records.mobile_number;
}
void vaccine ::view_Vaccine_Data()
{
    ifstream ind;
    int i = 0;
    ind.open("VACCINEDB.DAT");
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(vaccine)))
    {
        i++;
    }
    ind.close();
    int ch, num_of_vaccine = 500;
    int s = num_of_vaccine - i;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                 VACCINE STATISTICS           |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|               1. Add More Stock              |\n";
    cout << "\t\t\t\t\t\t\t\t\t|               2. View Available Stock        |\n";
    cout << "\t\t\t\t\t\t\t\t\t|               3. Back                        |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Your Searching Choice : ";
    cin >> ch;

    int f_var = 0;
    fstream file("count.DAT");
    file >> f_var;
    switch (ch)
    {
    case 1:
        int m;
        cout << "\n\t\t\t\t\t\t\t\t\tEnter number of vaccines you want to add : ";
        cin >> m;
        f_var = f_var + m;
        file.seekg(0);
        file << f_var;
        cout << "\n\t\t\t\t\t\t\t\t\tNow total number of vaccines are : " << f_var + s;
        break;

    case 2:
        cout << "\n\t\t\t\t\t\t\t\t\tAvailable number of vaccines are " << s + f_var;
        break;

    case 3:
        system("cls");
        menu();

    default:
        system("cls");
        cout << "\nEnter valid option " << endl;
        menu();
    }
    file.close();
    getch();
}

void vaccine::update_Data()
{
    int pos, id;
    int New_age;
    string New_name;
    int New_temperature;
    int New_blood_pressure;
    char New_gender;
    int New_mobile_number;
    string New_profession;
    string New_address;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tFor updation,";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter the Aadhar no. for searching ";
    cin >> id;
    fstream seqfile;
    fstream indexfile;
    seqfile.open("VACCINEDB.DAT", ios::in | ios::out | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::out | ios::binary);
    indexfile.seekg(0, ios::beg);

    pos = -1;

    while (indexfile.read((char *)&Ind_Records, sizeof(Ind_Records)))
    {
        if (id == Ind_Records.aadhar_id)
        {
            pos = Ind_Records.position;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tERROR : The record is not present in the file";
        return;
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter the values for updation...";
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter name  :  ";
        cin >> New_name;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Gender( M|F|O)   :  ";
        cin >> New_gender;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Age   :  ";
        cin >> New_age;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Profession (all letters should be small)   :  ";
        cin >> New_profession;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Blood Pressure   :  ";
        cin >> New_blood_pressure;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Temperature  :  ";
        cin >> New_temperature;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Address   :  ";
        cin >> New_address;
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Contact number   :  ";
        cin >> New_mobile_number;

        int offset = pos * sizeof(Rec);
        seqfile.seekp(offset);
        Records.name = New_name;
        Records.aadhar_id = id;
        Records.gender = New_gender;
        Records.age = New_age;
        Records.profession = New_profession;
        Records.blood_pressure = New_blood_pressure;
        Records.temperature = New_temperature;
        Records.address = New_address;
        Records.mobile_number = New_mobile_number;

        seqfile.write((char *)&Records, sizeof(Records)) << flush;
        cout << "\n\n\t\t\t\t\t\t\t\t\tThe record is updated!!!";
    }
    seqfile.close();
    indexfile.close();
    getch();
}

void vaccine::search_Data()
{
    vaccine item;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|               SEARCHING DATABASE             |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                  1. By AADHAR                |\n";
    cout << "\t\t\t\t\t\t\t\t\t|                  2. By AGE                   |\n";
    cout << "\t\t\t\t\t\t\t\t\t|                  3. By PROFESSION            |\n";
    cout << "\t\t\t\t\t\t\t\t\t|                  4. By GENDER                |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Your Searching Choice : ";

    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        search_by_Aadhar();
        getch();
        break;

    case 2:
        system("cls");
        search_by_Age();
        getch();
        break;

    case 3:
        system("cls");
        search_by_Profession();
        getch();
        break;

    case 4:
        system("cls");
        search_by_Gender();
        getch();
        break;

    default:
        system("cls");
        cout << "ENTER VALID OPTION !" << endl;
        menu();
    }
}

void vaccine::showdata()
{
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                PERSON DETAILS                |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tName   :   " << Records.name << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tAadhar :   " << Records.aadhar_id << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tAge    :   " << Records.age << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tProfession :   " << Records.profession << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tGender :   " << Records.gender << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tBlood Pressure :   " << Records.blood_pressure << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tBody Temperature   :   " << Records.temperature << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tAddress    : " << Records.address << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\tMobile number  :   " << Records.mobile_number << endl;
}

void vaccine ::show()
{
    cout << setw(20) << setiosflags(ios::left) << "\n\n\t\t\t\t\tName ";
    cout << setw(20) << "Aadhar No.";
    cout << setw(10) << "Age";
    cout << setw(18) << "Profession";
    cout << setw(8) << "B.P.";
    cout << setw(15) << "Temperature";
    cout << setw(7) << "Gender";
    cout << setw(15) << "Mobile No.";
    cout << "Address" << endl;
}

void vaccine ::show_list()
{
    cout << "\n\t\t\t\t\t";
    cout << setw(20) << setiosflags(ios::left) << Records.name;
    cout << setw(15) << Records.aadhar_id;
    cout << setw(8) << Records.age;
    cout << setw(15) << Records.profession;
    cout << setw(15) << Records.blood_pressure;
    cout << setw(15) << Records.temperature;
    cout << setw(7) << Records.gender;
    cout << setw(15) << Records.mobile_number;
    cout << Records.address << endl;
}

void vaccine ::search_by_Aadhar()
{
    fstream seqfile;
    fstream indexfile;
    int id, pos, offset;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                SEARCHING BY AADHAR           |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter the Aadhar no. for searching the record ";
    cin >> id;

    indexfile.open("IND.DAT", ios::in | ios::binary);
    pos = -1;

    while (indexfile.read((char *)&Ind_Records, sizeof(Ind_Records)))
    {
        if (id == Ind_Records.aadhar_id)
        {
            pos = Ind_Records.position;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tRecord is not present in the file";
        return;
    }

    offset = pos * sizeof(Records);
    seqfile.open("VACCINEDB.DAT", ios::in | ios::binary);
    seqfile.seekg(offset, ios::beg);
    seqfile.read((char *)&Records, sizeof(Records));

    if (Records.aadhar_id == -1)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tRecord is not present in the file";
        return;
    }
    else
    {
        showdata();
    }
    seqfile.close();
    indexfile.close();
}

void vaccine::search_by_Age()
{
    fstream seqfile("VACCINEDB.DAT");
    int flag = 0;
    int a, p = 0;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                 SEARCHING BY AGE             |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Age Choice : ";
    cin >> a;

    show();
    seqfile.read((char *)&Records, sizeof(Records));
    while (!seqfile.eof())
    {
        if (a == Records.age)
        {
            show_list();
            flag = 1;
            p++;
        }
        seqfile.read((char *)&Records, sizeof(Records));
    }
    if (flag == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tERROR : Age search results not found !" << endl;
    }
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tNumber of people vaccinated by this age are " << p;
    seqfile.close();
}

void vaccine::search_by_Profession()
{
    ifstream seqfile("VACCINEDB.DAT");
    int flag = 0, p = 0;
    string prof;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|              SEARCHING BY PROFESSION         |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Profession (all letters should be small) : ";
    cin >> prof;
    show();
    seqfile.read((char *)&Records, sizeof(Records));
    while (!seqfile.eof())
    {
        if (prof.compare(Records.profession) == 0)
        {
            show_list();
            flag = 1;
            p++;
        }
        seqfile.read((char *)&Records, sizeof(Records));
    }
    if (flag == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tERROR : Profession search results not found !" << endl;
    }
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tNumber of people vaccinated  by this Profession are " << p;

    seqfile.close();
}

void vaccine::search_by_Gender()
{
    ifstream seqfile("VACCINEDB.DAT");
    int flag = 0;
    char g;
    int p = 0;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                SEARCHING BY GENDER           |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Gender Choice (M|F|O) : ";
    cin >> g;
    show();
    seqfile.read((char *)&Records, sizeof(Records));
    while (!seqfile.eof())
    {
        if (toupper(g) == toupper(Records.gender))
        {
            show_list();
            flag = 1;
            p++;
        }
        seqfile.read((char *)&Records, sizeof(Records));
    }
    if (flag == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tERROR : Gender search results not found !" << endl;
    }
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tNumber of people vaccinated  by this Gender are " << p;
    seqfile.close();
}

void vaccine::display_Data()
{
    fstream seqfile;
    fstream indexfile;
    int i = 0, n = 0;
    seqfile.open("VACCINEDB.DAT", ios::in | ios::out | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::out | ios::binary);
    indexfile.seekg(0, ios::beg);
    seqfile.seekg(0, ios::beg);
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;
    show();
    while (indexfile.read((char *)&Ind_Records, sizeof(Ind_Records)))
    {
        i = Ind_Records.position * sizeof(Rec);
        seqfile.seekg(i, ios::beg);
        seqfile.read((char *)&Records, sizeof(Records));

        if (Records.aadhar_id != -1)
        {
            show_list();
            n++;
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\t\t\tERROR : There is no record in database !" << endl;
        }
    }
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tTotal Number of people vaccinated= " << n;
    seqfile.close();
    indexfile.close();
    getch();
}
void menu()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|                     MENU                     |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
    cout << "\t\t\t\t\t\t\t\t\t|              1. Add NEW Record               |\n";
    cout << "\t\t\t\t\t\t\t\t\t|              2. View Vaccine DATA            |\n";
    cout << "\t\t\t\t\t\t\t\t\t|              3. Update Data Record           |\n";
    cout << "\t\t\t\t\t\t\t\t\t|              4. Search Data Record           |\n";
    cout << "\t\t\t\t\t\t\t\t\t|              5. Display all Record           |\n";
    cout << "\t\t\t\t\t\t\t\t\t|              6. Exit                         |\n";
    cout << "\t\t\t\t\t\t\t\t\t|==============================================|\n";
}

int main()
{
    int k = 3;
    int num_vac;
    vaccine obj;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t V  A  C  C  I  N  E      M  A  N  A  G  E  M  E  N  T      S  Y  S  T  E  M\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t|===============================================================================================================|" << endl;
    cout << "\n\n\n\t\t\t\t\t\t Press any key to continue  " << endl;
    getch();

B:
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease wait for few seconds";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(700);

    system("cls");
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t|===============================================================|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t  L  O  G  I  N    W  I  N  D  O  W  \t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|" << endl;
    cout << "\t\t\t\t\t\t\t|===============================================================|" << endl;

    while (k >= 1)
    {
        int c = Authentication();
        if (c == 1)
            break;
        else
            cout << "\n\n\t\t\t\t\t\t\t\tERROR: wrong User Name OR Password !\n\n\t\t\t\t\t\t\tYou Can try Only " << k - 1 << " times more.";
        k--;

        if (k < 1)
        {
            for (int i = 59; i >= 0; i--)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE !";
                cout << "\n\n\n\n\n\n\t\t\t\t\t\tTRY AFTER " << i << " SECONDS...";
                Sleep(1000);
            }
            k = 3;
            goto B;
        }
    }

    int ch;
    do
    {
        menu();
        cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Your Choice : ";
        cin >> ch;
        vaccine v1;
        switch (ch)
        {
        case 1:
            system("cls");
            obj.add_New_Data();
            break;

        case 2:
            system("cls");
            obj.view_Vaccine_Data();
            break;

        case 3:
            system("cls");
            obj.update_Data();
            break;

        case 4:
            system("cls");
            obj.search_Data();
            break;

        case 5:
            system("cls");
            obj.display_Data();
            break;

        case 6:
            system("cls");
            exit(0);

        default:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            cout << "\n\n\t\t\t\t\t****HAVE A NICE DAY*****";
            Sleep(3000);
            exit(0);
        }
    } while (ch != 0);
    return 0;
}

int Authentication()
{
    char username[30], passwd[20];
    int ch, i = 0, cap = 0, capt = 0;
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t USER NAME :  ";
    fflush(stdin);
    gets(username);
    cout << "\n\t\t\t\t\t\t\t\t PASSWORD :  ";

    while ((ch = getch()) != 13)
    {
        cout << "*";
        passwd[i] = ch;
        i++;
    }
    passwd[i] = '\0';
    srand(time(0));
    cap = rand();
    cout << "\n\n\t\t\t\t\t\t\t\t CAPTCHA :  " << cap;
    cout << "\n\n\t\t\t\t\t\t\t\t Please enter the valid captcha :  ";
    cin >> capt;
    if ((strcmp(username, "vaccine") == 0) && (strcmp(passwd, "Vaccine@2021") == 0) && cap == capt)
        return 1;
    else
        return 0;
}
