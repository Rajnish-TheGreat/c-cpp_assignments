#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct student
{
    int roll_no;
    char name[20];
    int age;
    int mark;
} ss;

typedef struct index
{
    int iroll_no;
    long offset;
    int flag;
} is;

FILE *ptr = NULL;
FILE *iptr = NULL;
char f_name[20];  /*master file*/
char if_name[20]; /*index file*/

/*
The SORT_FILE Function
Input:none
Output:1 or -1
Called By:ADD_RECORD
Calls:none

*/
int SORT_FILE()
{
    int size; // used for stored the total size of file
    int i, j;
    is ind, ind_temp; // create object for the index file, ind_temp is used for the temperory object
    ss stud;          // object created for the structure student
    int flag = 0;     // flag is set for the checking the status of the program

    iptr = fopen(if_name, "rb +"); // open a binary file in read mode with write
    if (iptr == NULL)
    {
        cout << "File not opened"; // when index file pointer is null
        return -1;
    }

    ptr = fopen(f_name, "rb +"); // open a binary file in read mode with write
    if (ptr == NULL)
    {
        cout << "File not opened"; // if master file is null
        return -1;
    }

    size = 0; // initialise size to 0

    while (fread(&ind, sizeof(is), 1, iptr)) // loop for counting total size of the index file
        size++;

    fclose(iptr);                  // close index file
    iptr = fopen(if_name, "rb +"); // open a binary file in read mode with write
    if (iptr == NULL)
    {
        cout << "File not opened"; //when index file pointer is null
        return -1;
    }

    for (i = 0; i < size; i++)
    {
        flag = 0; // set flag to zero
        for (j = 0; j < size - (i + 1); j++)
        {
            fseek(iptr, j * sizeof(is), SEEK_SET);
            fread(&ind, sizeof(is), 1, iptr);
            fread(&ind_temp, sizeof(is), 1, iptr);
            if (ind.iroll_no > ind_temp.iroll_no)
            {
                fseek(iptr, j * sizeof(is), SEEK_SET);
                fwrite(&ind_temp, sizeof(is), 1, iptr);
                fseek(iptr, (j + 1) * sizeof(is), SEEK_SET);
                fwrite(&ind, sizeof(is), 1, iptr);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    fclose(iptr);
    return 1;
}

/*
The ADD_RECORD Function
Input:none
Output:1 or -1
Called By:main
Calls:SORT_FILE

*/
int ADD_RECORD()
{
    ss stud;
    is ind;
    long offset;

    ptr = fopen(f_name, "rb+");
    if (ptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }

    while (fread(&stud, sizeof(stud), 1, ptr))
        ;

    offset = ftell(ptr);

    cout << "Enter the name of the student: ";
    fflush(stdin);
    cin >> stud.name;
    cout << "Enter the roll no.of the student: ";
    fflush(stdin);
    cin >> stud.roll_no;
    cout << "Enter the age of the student: ";
    fflush(stdin);
    cin >> stud.age;
    cout << "Enter the marks of the student: ";
    fflush(stdin);
    cin >> stud.mark;

    fwrite(&stud, sizeof(stud), 1, ptr);
    fclose(ptr);
    iptr = fopen(if_name, "ab +");
    if (iptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }
    ind.iroll_no = stud.roll_no;
    ind.offset = offset;
    ind.flag = 1;
    fwrite(&ind, sizeof(ind), 1, iptr);
    fclose(iptr);
    SORT_FILE();
    return 1;
}

/*
The DELETE_RECORD Function
Input:roll_no
Output:either -1 or 1
Called By:main
Calls:none

*/
int DELETE_RECORD(int roll_no)
{
    is ind;
    int flag = 0;

    iptr = fopen(if_name, "rb +");
    if (iptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }
    while (fread(&ind, sizeof(is), 1, iptr))
    {
        if (ind.iroll_no == roll_no)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        ind.flag = -1;
        fseek(iptr, -(long)sizeof(is), SEEK_CUR);
        fwrite(&ind, sizeof(is), 1, iptr);
        fclose(iptr);
        return 1;
    }
    fclose(iptr);
    return -1;
}

/*
The MODIFY_RECORD Function
Input:roll_no
Output:1
Called By: main
Calls:none

*/

int MODIFY_RECORD(int roll_no)
{
    is ind;
    ss stud;
    int flag = 0;

    iptr = fopen(if_name, "rb +");
    if (iptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }
    while (fread(&ind, sizeof(is), 1, iptr))
    {
        if (ind.iroll_no == roll_no)
        {
            flag = 1;
            break;
        }
    }
    fclose(iptr);

    if (flag == 1)
    {
        ptr = fopen(f_name, "rb +");
        if (ptr == NULL)
        {
            cout << "File not opened";
            return -1;
        }
        fseek(ptr, ind.offset, SEEK_SET);
        fread(&stud, sizeof(stud), 1, ptr);

        cout << "Enter the name of the student: ";
        fflush(stdin);
        cin >> stud.name;
        cout << "Enter the age of the student: ";
        fflush(stdin);
        cin >> stud.age;
        cout << "Enter the marks of the student: ";
        fflush(stdin);
        cin >> stud.mark;

        fseek(ptr, -(long)sizeof(stud), SEEK_CUR);

        fwrite(&stud, sizeof(stud), 1, ptr);
        fclose(ptr);
        return 1;
    }
    return -1;
}

/*
The SEARCH_RECORD Function
Input:roll_no
Output:if record found then 1
Called By:main
Calls:none

*/

int SEARCH_RECORD(int roll_no)
{
    is ind;
    ss stud;

    iptr = fopen(if_name, "rb +");
    if (iptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }
    while (fread(&ind, sizeof(is), 1, iptr))
    {
        if (ind.iroll_no == roll_no && ind.flag == 1)
        {
            fclose(iptr);
            return 1;
        }
    }
    fclose(iptr);
    return -1;
}
/*
The DISPLAY_ALL_RECORD Function
Input:none
Output:-1 if no record prsent otherwise 1
Called By:main
Calls:none

*/

int DISPLAY_ALL_RECORD()
{
    is ind;
    ss stud;

    iptr = fopen(if_name, "rb +");
    if (iptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }

    ptr = fopen(f_name, "rb +");
    if (ptr == NULL)
    {
        cout << "File not opened";
        return -1;
    }
    while (fread(&ind, sizeof(is), 1, iptr))
    {
        if (ind.flag == 1)
        {
            fseek(ptr, ind.offset, SEEK_SET);
            fread(&stud, sizeof(stud), 1, ptr);

            printf("\n\n\nRoll: % d ", stud.roll_no);
            printf("\nName: % s", stud.name);
            printf("\nAge: % d", stud.age);
            printf("\nMarks: % d", stud.mark);
        }
    }
    fclose(iptr);
    fclose(ptr);
    return 1;
}

int main(void)
{
    int choice;
    int status;
    int roll_no;
    char ch;
    cout << "Enter the file name : ";
    cin >> f_name;
    cout << "Enter the index file name : ";
    cin >> if_name;
    ptr = fopen(f_name, "wb");
    if (ptr == NULL)
    {
        cout << "File not found !";
        exit(0);
    }
    iptr = fopen(if_name, "wb");
    if (iptr == NULL)
    {
        cout << "File not found !";
        exit(0);
    }
    fclose(ptr);
    fclose(iptr);
    while (1)
    {
        cout << "\n1.Add";
        cout << "\n2.Delete";
        cout << "\n3.Modify";
        cout << "\n4.Search";
        cout << "\n5.Display";
        cout << "\n6.Exit";
        cout << "\nEnter the choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            status = ADD_RECORD();
            if (status == 1)
                cout << "The record has been successfully added.";
            else
                cout << "The record could not be added.";
            break;
        case 2:
            cout << "Enter the roll_no of the record to deleted : ";
            cin >> roll_no;
            status = DELETE_RECORD(roll_no);
            if (status == 1)
                cout << "The record has been successfully deleted.";
            else
                cout << "The record could not be found.";
            break;
        case 3:
            cout << "Enter the roll_no of the record to modify : ";
            cin >> roll_no;
            status = MODIFY_RECORD(roll_no);
            if (status == 1)
                cout << "The record has been successfully modified.";
            else
                cout << "THe record could not be found.";
            break;
        case 4:
            cout << "Enter the roll_no of the record to searched : ";
            cin >> roll_no;
            status = SEARCH_RECORD(roll_no);
            if (status == 1)
                cout << "The record has been found.";
            else
                cout << "THe record could not be found.";
            break;
        case 5:
            DISPLAY_ALL_RECORD();
            break;
        case 6:
            break;
        default:
            cout << "Inavlid Choice!!!";
        }
        cout << "\nDo u want to continue : ";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            break;
    }
    return 0;
}