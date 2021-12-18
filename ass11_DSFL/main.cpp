#include <iostream>
#include <fstream>
#define MAX 10
using namespace std;

class Employee
{
    char name[20];
    int id, salary;

public:
    Employee()
    {
        id = salary = -1;
    }

    void Accept()
    {
        cout << "\nName	: ";
        cin >> name;
        cout << "Emp Id : ";
        cin >> id;
        cout << "Salary	: ";
        cin >> salary;
    }

    void Display()
    {
        cout << "\n"<< name << "\t" << id << "\t" << salary;
    }

    int return_Id()
    {
        return id;
    }
};

class Hashing
{
    struct Chaining
    {
        int key, link;
        long int offset;

        Chaining()
        {
            key = offset = link = -1;
        }
    };

    Chaining HashTable[MAX];

public:
    int Hash(long int);
    int Empty(int);
    void Print();
    void Chaing_WO_Replacement(int, int);
    int Search();
};

int Hashing ::Hash(long int key)
{
    int sum = 0;
    while (key > 0)
    {
        sum += key % 10;
        key = key / 10;
    }
    return sum % 10;
}

int Hashing ::Empty(int location)
{
    int i = location;
    do
    {
        i++;
        i = i % MAX;
    } while (HashTable[i].key != -1 && i != location);
    return i;
}

void Hashing ::Print()
{
    cout << "\nHashvalue\tKey\tOffset\tLink\n";
    for (int i = 0; i < MAX; i++)
    {
        cout << "\n"
             << i << "\t" << HashTable[i].key << "\t";
        cout << HashTable[i].offset << "\t" << HashTable[i].link;
    }
}

void Hashing::Chaing_WO_Replacement(int id, int Addr)
{
    int i = 0, location, pos = -1, Flag = 0;
    char Answer;
    location = Hash(id);
    if (HashTable[location].key == -1) //Location is Empty
    {
        HashTable[location].key = id;
        HashTable[location].offset = Addr;
    }
    else
    {
        pos = Empty(location);
        if (pos == location)
            cout << "Hash Table is Full !\n";
        else //hash table not full
        {
            if (Hash(HashTable[location].key) == Hash(id))
            {
                i = location;
                while (HashTable[i].link != -1)
                    i = HashTable[i].link;
                HashTable[pos].key = id;
                HashTable[pos].offset = Addr;
                ;
                HashTable[i].link = pos;
            }    //if
            else //Present Key Hash != New Key Hash
            {
                i = location + 1;
                while ((i % MAX) != location)
                {
                    if (i == MAX)
                        i = 0;
                    if (Hash(HashTable[i].key) == Hash(id))
                    {
                        Flag = 1;
                        break;
                    }
                    i++;
                } //while
                if (Flag != 1)
                {
                    HashTable[pos].key = id;
                    HashTable[pos].offset = Addr;
                }
                else
                {
                    while (HashTable[i].link != -1)
                        i = HashTable[i].link;
                    HashTable[pos].key = id;
                    HashTable[pos].offset = Addr;
                    HashTable[i].link = pos;
                }
            } //else
        }     //else hash table not full
    }
    Print();
}

int Hashing ::Search()
{
    int location, key, i, Flag;
    cout << "Enter Id Of Employee :";
    cin >> key;
    if (HashTable[location = Hash(key)].key == key)
        return HashTable[location].offset;
    else if (Hash(HashTable[location].key) == Hash(key))
    {
        i = location;
        while (HashTable[i].link != -1)
        {
            i = HashTable[i].link;
            if (HashTable[i].key == key)
                return HashTable[i].offset;
        }
    }
    else
    {
        i = location + 1;
        while ((i % MAX) != location)
        {
            i = i % MAX;
            if (Hash(HashTable[i].key) == Hash(key))
            {
                while (HashTable[i].link != -1)
                {
                    i = HashTable[i].link;
                    if (HashTable[i].key == key)
                        return HashTable[i].offset;
                }
            }
            i++;
        } //while
    }
    return -1;
}

class Database
{
    char filename[15];
    Hashing H;

public:
    void Create();
    void Display();
    void Insert();
    void Modify();
    void Search();
};

void Database ::Create()
{
    ofstream File;
    int id, offset, n;
    cout << "Enter File Name : ";
    cin >> filename;
    cout << "Enter number of records :";
    cin >> n;
    for (int i = 0; i < n; i++)
        Insert();
}

void Database ::Display()
{
    ifstream File;
    Employee E;
    File.open(filename);

    if (File)
    {
        cout << "Name\tEmp-Id \tSalary";
        File.read((char *)(&E), sizeof(E));
        while (!File.eof())
        {
            E.Display();
            File.read((char *)(&E), sizeof(E));
        }
        File.close();
    }
    else
        cout << "\nFile opening Error !";
}

void Database ::Insert()
{
    ofstream File;
    Employee E;
    int id, offset;
    File.open(filename, ios::app);
    E.Accept();
    if (File)
    {
        id = E.return_Id();
        File.seekp(0, ios::end);
        offset = File.tellp();
        H.Chaing_WO_Replacement(id, offset);
        File.write((char *)(&E), sizeof(E));
        File.close();
    }
    else
        cout << "\nFile creation Error !";
}

void Database ::Modify()
{
    long int Addr = H.Search();
    if (Addr > -1)
    {
        fstream File;
        Employee E;
        File.open(filename, ios::in | ios::out);
        File.seekg(Addr, ios::beg);
        File.read((char *)&E, sizeof(E));
        cout << "Existing Details...";
        E.Display();
        cout << "\nEnter New Details(Don't Change Employee ID) : ";
        E.Accept();
        File.seekp(Addr, ios::beg);
        File.write((char *)&E, sizeof(E));
        File.close();
    }
    else
        cout << "\nData not found !";
}

void Database ::Search()
{
    long int Addr = H.Search();
    if (Addr > -1)
    {
        fstream File;
        Employee E;
        File.open(filename, ios::in);
        File.seekg(Addr, ios::beg);
        File.read((char *)&E, sizeof(E));
        cout << "Searching...";
        cout << "\nRecord found !";
        E.Display();
        File.close();
    }
    else
        cout << "Record not found !";
}

int main()
{
    Database db;
    int ch;
    {
        do
        {
            cout << "\n\n|------------------------------------|" << endl;
            cout << "|========EMPLOYEE'S__DATABASE========|" << endl;
            cout << "|------------------------------------|" << endl;
            cout << "|         1. Create Database         |" << endl;
            cout << "|         2. Insert Database         |" << endl;
            cout << "|         3. Display Database        |" << endl;
            cout << "|         4. Modify Database         |" << endl;
            cout << "|         5. Search Database         |" << endl;
            cout << "|         6. Quit                    |" << endl;
            cout << "|====================================|" << endl;
            cout << "Enter your choice : ";
            cin >> ch;

            switch (ch)
            {
            case 1:
                db.Create();
                break;
            case 2:
                db.Insert();
                break;
            case 3:
                db.Display();
                break;
            case 4:
                db.Modify();
                break;
            case 5:
                db.Search();
                break;
            case 6:
                break;
            default:
                cout << "\nERROR : Wrong choice !!!" << endl;
            }
        } while (ch != 6);
        return 0;
    }
}