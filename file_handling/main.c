#include <stdio.h>
#include <stdlib.h>
struct emp
{
	char name[20];
	int id;
	int exp;
	int salary;
} e;


void create()
{
    FILE *fpo;
    fpo = fopen("employee.txt","a+");
    if (fpo == NULL)
        printf("File cant be opened");
    else{
        fflush(stdin);
        printf("Employee name : ");
        scanf("%s", e.name);
        fflush(stdin);
        printf("\nEmployee ID: ");
        scanf("%d", &e.id);
        fflush(stdin);
        printf("\nExperience(in months): ");
        scanf("%d", &e.exp);
        fflush(stdin);
        printf("Salary : ");
        scanf("%d", &e.salary);
        fflush(stdin);
        fwrite(&e, sizeof(e), 1, fpo);
        fclose(fpo);
    }
}

void display()
{
    FILE *fpo;
	fpo = fopen("Employee.txt", "r");
	if (fpo == NULL)
        printf("File cant be opened");
    else{
        printf("\nID\tName\tExperience\tSalary\n\n");
        while (fread(&e, sizeof(e), 1, fpo))
            printf("  %d\t%s\t%d\t\t%d\n", e.id, e.name,e.exp ,e.salary);
        fclose(fpo);
    }
}

void search()
{
	FILE *fpo;
	int s, r;
	printf("\nEmployee ID: ");
	scanf("%d", &r);
	if (search_id(r) == 0)
		printf("\nID number %d not found", r);
	else
	{
		fpo = fopen("Employee.txt", "r");
		while (fread(&e, sizeof(e), 1, fpo))
		{
			s = e.id;
			if (s == r)
			{
				printf("\nEmployee ID: %d", e.id);
				printf("\nEmployee Name: %s ", e.name);
				printf("\nExperience(in months): %d ", e.exp);
				printf("\nSalary: %d\n", e.salary);
			}
		}
		fclose(fpo);
	}
}

void del()
{
	FILE *fpo;
	FILE *fpt;
	int s, r;
	printf("\nEmployee ID: ");
	scanf("%d", &r);
	if (search_id(r) == 0)
		printf("ID number %d not found", r);
	else
	{
		fpo = fopen("Employee.txt", "r");
		fpt = fopen("TempFile", "w");
		while (fread(&e, sizeof(e), 1, fpo))
		{
			s = e.id;
			if (s != r)
				fwrite(&e, sizeof(e), 1, fpt);
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Employee.txt", "w");
		fpt = fopen("TempFile", "r");
		while (fread(&e, sizeof(e), 1, fpt))
			fwrite(&e, sizeof(e), 1, fpo);
		printf("\nRECORD DELETED SUCCESSFULLY !!!\n");
		fclose(fpo);
		fclose(fpt);
	}
}

void modify()
{
	int id_no;
	FILE *fpt;
	FILE *fpo;
	int s, r, ch;
	int search_id;
	printf("Employee ID: ");
	scanf("%d", &r);
	id_no = search_id;
	if (id_no == 0)
	{
		printf("ID number : %d is not Available in the file", r);
	}
	else
	{
		fpo = fopen("Employee.txt", "r");
		fpt = fopen("TempFile", "w");
		while (fread(&e, sizeof(e), 1, fpo))
		{
			s = e.id;
			if (s != r)
				fwrite(&e, sizeof(e), 1, fpt);
			else
			{
				printf("\n\t1. Update Experience");
				printf("\n\t2. Update Salary");
				printf("\n\t3. Update both Experience and Salary");
				printf("\nEnter your choice:");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1:
					printf("\nExperience(in months): ");
					scanf("%d", &e.exp);
					break;

				case 2:
					printf("\nEmployee New Salary: ");
					scanf("%d", &e.salary);
					break;

				case 3:
					printf("\nExperience(in months): ");
					scanf("%d", &e.exp);
					printf("\nEmployee New Salary: ");
					scanf("%d", &e.salary);
					break;

				default:
					printf("Invalid Selection");
					break;
				}
				fwrite(&e, sizeof(e), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Employee.txt", "w");
		fpt = fopen("TempFile", "r");
		while (fread(&e, sizeof(e), 1, fpt))
		{
			fwrite(&e, sizeof(e), 1, fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("RECORD MODIFIED SUCCESSFULLY !!!");
	}
}

void bubble()
{
	int a[20], count = 0, i, j, temp, c;
	FILE *fpo;
	fpo = fopen("Employee.txt", "r");
	while (fread(&e, sizeof(e), 1, fpo))
	{
		a[count] = e.id;
		count++;
	}
	c = count;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("\nID Number\tName\tExperience\tSalary\n\n");
	count = c;
	for (i = 0; i < count; i++)
	{
		rewind(fpo);
		while (fread(&e, sizeof(e), 1, fpo))
		{
			if (a[i] == e.id)
				printf("  %d\t\t%s\t%d\t%d\n", e.id, e.name,e.exp ,e.salary);
		}
	}
}

int search_id(int id_no)
{
	FILE *fpo;
	int c = 0;
	fpo = fopen("Employee.txt", "r");
	while (!feof(fpo))
	{
		fread(&e, sizeof(e), 1, fpo);

		if (id_no == e.id)
		{
			fclose(fpo);
			return 1;
		}
	}
	fclose(fpo);
	return 0;
}

int EMPTY()
{
	int c = 0;
	FILE *fp;
	fp = fopen("Employee.txt", "r");
	while (fread(&e, sizeof(e), 1, fp))
		c = 1;
	fclose(fp);
	return c;
}

void main()
{
	int choice, t;
	do
	{
        printf("\n\tMenu :\n1 Add Employee\n2 Display Database\n3 Search in Database\n4 Delete a record\n5 Modify Database\n6 Sort Database\n7 Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		printf("\n\n");

		switch (choice)
		{
		case 1:
			create();
			break;

		case 2:
			t = EMPTY();
			if (t == 0)
				printf("\nFile Can't be opened");
			else
				display();
			break;

		case 3:
			search();
			break;

		case 4:
			del();
			break;

		case 5:
			modify();
			break;

		case 6:
			t = EMPTY();
			if (t == 0)
				printf("\n The file is EMPTY !!!");
			else
				bubble();
			break;

		default:
			printf("\nInvalid Option");
			break;
		}
	} while (choice != 7);
}
