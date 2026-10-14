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

int main (){
    int choice;
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

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
   
    

   
    return 0;
}