#include <stdio.h>
#include <string.h>

struct student{
    char name[10];
    char info[300];
};

int main(void){
    int i;
    struct student students[] = {
        {"svendbent", "Likes math"},
        {"karlMarks", "Top of the class in philosophy."},
        {"maria",     "Plays football,"}
    };
    int count = sizeof(students) / sizeof(students[0]);
    char input[30];
    int found = -1;

    for(i = 0; i < count; i++)
        printf("%s\n", students[i].name);
    
    printf("hvilken persons fil vil du se:\n");
    scanf("%s", &input);
    

    for(i = 0; i < count;i++){
        if(strcmp(students[i].name, input) == 0){
            printf("%s", students[i].info);
            found = i;
        }
    }

    printf("\nwoud you like to change the file:\n");
    scanf("%s", &input);

    if(strcmp(input, "yes") == 0){
        printf("\nnew info:\n");
        scanf(" %299[^\n]", &students[found].info);

        printf("updated info: %s:\n %s", students[found].name, students[found].info);
    }else{
        printf("error");
        return 0;
    }
    return 0;
}