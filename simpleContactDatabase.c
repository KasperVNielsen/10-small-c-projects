#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100


struct Contact{
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];

int count = 0;

void viewContacts() {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n===== Contact List =====\n");

    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("\n");
    }
}

void addContact(struct Contact contacts[], int *count) {
     if (*count >= MAX_CONTACTS) {
        printf("Contact limit reached.\n");
        return;
    }

    printf("enter name: \n");
    scanf("%s", contacts[*count].name);

    printf("\nenter phone number: \n");
    scanf("%s", contacts[*count].phone);

    printf("enter email: \n");
    scanf("%s", contacts[*count].email);

    (*count)++;
    printf("Contact added successfully.\n");
}

int findContact(struct Contact contacts[], int *count,char searchName[50]) {
    for (int i = 0; i < *count; i++) {
        if (strstr(contacts[i].name, searchName) != NULL) {
             printf("Name: %s\n", contacts[i].name);
             printf("Phone: %s\n", contacts[i].phone);
             printf("Email: %s\n", contacts[i].email);
        }
        else{printf("No matching contact found.\n");}
    }
    return -1;
}

void updateContact(struct Contact contacts[], int *count, char input[50]){
    printf("What would you like to change (name/email/phone/all)? ");
    scanf("%49s", input);
    for(int i = 0; i < *count; i++)
        if (strcmp(input, "name") == 0) {
            printf("New name: ");
            scanf("%49s", contacts[i].name);
        } else if (strcmp(input, "email") == 0) {
            printf("New email: ");
            scanf("%49s", contacts[i].email);
        } else if (strcmp(input, "phone") == 0) {
            printf("New phone: ");
            scanf("%49s", contacts[i].phone);
        } else if (strcmp(input, "all") == 0) {
            printf("New name: ");
            scanf("%49s", contacts[i].name);
            printf("New phone: ");
            scanf("%49s", contacts[i].phone);
            printf("New email: ");
            scanf("%49s", contacts[i].email);
        } else {
            printf("Unknown field.\n");
        }
}

void deleteContact(struct Contact contacts[], int *count, char input[50]){
   
    printf("input name to delete:\n");
    scanf("%49s", input);
    for(int i = 0; i < *count; i++){
        if(strstr(input,contacts[i].name) != NULL){
            contacts[i].name;
            contacts[i].phone;
            contacts[i].email;
            (*count)--;
            printf("deleted sucessfully");
            break;
        }
    }
}

int main (){
    int choice;
    char searchinput[50];
    char input[50];
    while (1)
    {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                printf("search name;\n");
                scanf("%s", searchinput);
                findContact(contacts, &count, searchinput);
                break;
            case 4:
                updateContact(contacts, &count, input);
                break;
            case 5:
                deleteContact(contacts, &count, input);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}