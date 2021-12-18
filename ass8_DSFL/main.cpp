#include <iostream>
#include <iomanip>
#define SIZE 50
using namespace std;

struct Node //creating structure
{
    string name; //student name
    long roll;   //student roll number
    bool flag;   //flag for counter
    int chain;   //for storing chaining element
};

class HashTable //creating HashTable
{
    Node *h;
    int size; //size of table
public:
    HashTable() {}                      //non-parameterized constructor
    HashTable(int);                     //parameterized constructor, it creates hash table with default values
    void without_Replace(long, string); //function implements linear probing using chaining without replacement
    void display();                     //display Hashtable
};

HashTable ::HashTable(int n) //function create hash table with default values
{
    size = n;
    h = new Node[size];

    for (int i = 0; i < n; i++) //assign default values to variables
    {
        h[i].roll = 0;
        h[i].name = "";
        h[i].flag = false;
        h[i].chain = -1; //if there is no chaining, returns -1
    }
    cout << "\nHash Table created successfully !!!" << endl;
}

void HashTable ::without_Replace(long roll, string name) //function implements linear probing using chaining without replacement
{
    int i = 0, j, location;

    location = roll % size; //find modulus of roll number
    j = location;           //modulus value assign to location

    while (h[j].flag && i < size) //if size of created hash table is greater than students already present
    {
        if (h[j].roll % size == roll % size) //perform modulus of that roll and assign its location as hash key
            break;
        j = (j + 1) % size; //same for other element
        i++;
    }
    if (i == size) //if total student is equal is size of created Hash-Table
    {
        cout << "\nHash Table is Full !!!" << endl; //print table is full
        return;
    }

    while (h[j].chain != -1) //if chaining of element is there
        j = h[j].chain;      //return the hash key in the chaining column at that row(position) where it should be actually belong
    location = j;

    while (h[location].flag && i < size)
    {
        location = (location + 1) % size; //if hash-key is already occupied, increase key location by 1
                                          //linear probing at empty location
        i++;                              //perform the complete loop "without replacement"
    }
    if (i == size) //if total student is equal is size of created Hash-Table
    {
        cout << "\nHash Table is Full !!!" << endl; //print table is full
        return;
    }

    h[location].roll = roll;
    h[location].name = name;
    h[location].flag = true;

    if (j != location) //if hash-key is not equal to location
    {
        h[j].chain = location; //then its hash-key is chain to that position where it should be actually belong
    }
}

void HashTable ::display() //function display the created Hash-Table
{
    cout << "\nSr.no\tName\tRoll-Num\tChain" << endl;
    cout << "===================================================================" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i + 1 << setw(10) << h[i].name << setw(15) << h[i].roll << setw(10) << h[i].chain << endl;
    }
}

int main()
{
    int choice, size;
    string name;
    long roll;

    cout << "Enter size of the Hash Table:  "; //ask size for Hash-Table creation
    cin >> size;
    HashTable ht1(size); //alocate Hash-Table of asked size

    //MENU
    do
    {
        cout << "|==============HASH-TABLE==============|" << endl;
        cout << "|--------(With-Out-Replacement)--------|" << endl;
        cout << "|--------------------------------------|" << endl;
        cout << "|          1. Insert Data              |" << endl;
        cout << "|          2. Display Hash-Table       |" << endl;
        cout << "|          3. Exit                     |" << endl;
        cout << "|======================================|" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter student name : ";
            cin >> name;
            cout << "Enter student roll number : ";
            cin >> roll;
            ht1.without_Replace(roll, name);
            cout << "Data inserted successfully !" << endl;
            break;

        case 2:
            ht1.display();
            break;

        case 3:
            break;

        default:
            cout << "\nInvalid Choice!!!" << endl;
        }
    } while (choice != 3);
    return 0;
}
