#include <stdio.h>
#include <string.h>

void accept(char (*words)[10], int num){
    printf("Enter %d words: ", num);
    for (size_t i = 0; i < num; i++){
        scanf("%s", &words[i]);
    }
}
void display(char (*words)[10], int num){
    printf("\n");
    for (size_t i = 0; i < num; i++){
        printf("%s\t", *(words + i));
    }
}
void insertion_sort(char (*words)[10], int num){
    char temp[10];
    int j, i, pass = 0;
    for (i = 1; i < num; i++){
        int flag = i;
        strcpy(temp, words[i]);
        for (j = i - 1; j >= 0; j--){
            if (strcmp(temp, words[j]) < 0){
                strcpy(words[j + 1], words[j]);
                flag = j;
            }
        }
        strcpy(words[flag], temp);
        pass++;
        printf("\nPass %d: ", pass);
        display(words, num);
    }
}
void selection_sort(char (*words)[10], int num){
    int min_index, pass = 0;
    char temp[10];
    for (size_t i = 0; i < num- 1; i++){
        min_index = i;
        for (size_t j = i + 1; j < num; j++){
            if (strcmp(words[j], words[min_index]) > 0){
                min_index = j;
            }
        }
        strcpy(temp, words[i]);
        strcpy(words[i], words[min_index]);
        strcpy(words[min_index], temp);
        pass++;
        printf("\nPass %d: ", pass);
        display(words, num);

    }
}
void binary_ser(char (*words)[10], int num, char temp[10]){
    int low = 0, flag = 0;
    int high = num- 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (strcmp(temp, words[mid]) == 0){
            printf("\n\nFound at %d: %s", mid, words[mid]);
            flag = 1;
            break;
        }
        else if (strcmp(temp, words[mid]) > 0){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if (flag == 0){
        printf("Word not Found!!!");
    }
}
void search_rec(char (*words)[10], int low, int high, char temp[10]){
    int mid = low + (high - low) / 2;
    int flag = 0;
    if (low <= high){
        if (strcmp(temp, words[mid]) == 0){
            printf("Found at %d : %s", mid, words[mid]);
            flag = 1;
        }
        else if (strcmp(temp, words[mid]) > 0){
            high = mid - 1;
            search_rec(words, low, high, temp);
        }
        else{
            low = mid + 1;
            search_rec(words, low, high, temp);
        }
    }
}
int main()
{
    int num=0, size_of_string,choice;
    char strings_to_sort[10][10],temp[10];
    do{
        printf("\n\tSorting Menu :\n1 Enter words\n2 Display \n3 Sort (Ascending order) \n4 Sort (Descending order) \n5 Search(without Recursion)\n6 Search(using Recursion) \n7 Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nNumber of words you want to enter: ");
            scanf("%d", &num);
            accept(strings_to_sort, num);
            break;
        case 2:
            display(strings_to_sort, num);
            break;
        case 3:
            insertion_sort(strings_to_sort, num);
            break;
        case 4:
            selection_sort(strings_to_sort, num);
            break;
        case 5:
            printf("\nEnter the word to search: ");
            scanf("%s", temp);
            binary_ser(strings_to_sort, num, temp);
            break;
        case 6:
            printf("\nEnter the word to search: ");
            scanf("%s", temp);
            search_rec(strings_to_sort, 0, num - 1, temp);
            break;
        case 7:
            break;
        default:
            printf("Invalid choice!!!");
        }
    }while(choice!=7);
}
