#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store contact information
struct Contact {
    char name[50];
    char phone[15];
    struct Contact* left;
    struct Contact* right;
};

// Function to create a new contact node
struct Contact* createContactNode(const char* name, const char* phone) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->left = NULL;
    newContact->right = NULL;
    return newContact;
}

// Function to insert a new contact into the BST
struct Contact* insertContact(struct Contact* root, const char* name, const char* phone) {
    if (root == NULL) {
        return createContactNode(name, phone);
    }

    // Compare names to decide the position in the BST
    int compareResult = strcmp(name, root->name);

    // If name is smaller, go left; if larger, go right
    if (compareResult < 0) {
        root->left = insertContact(root->left, name, phone);
    } else if (compareResult > 0) {
        root->right = insertContact(root->right, name, phone);
    }

    return root;
}

// Function to display contacts using an inorder traversal of the BST
void displayContactsInOrder(struct Contact* root) {
    if (root != NULL) {
        displayContactsInOrder(root->left);
        printf("%s\t%s\n", root->name, root->phone);
        displayContactsInOrder(root->right);
    }
}

int main() {
    struct Contact* phoneDirectory = NULL; // Root of the BST

    int choice;
    do {
        // Display menu
        printf("\nPhone Directory Menu:\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], phone[15];
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the phone number: ");
                scanf("%s", phone);
                phoneDirectory = insertContact(phoneDirectory, name, phone);
                printf("Contact added successfully.\n");
                break;
            }
            case 2:
                printf("Phone Directory:\n");
                displayContactsInOrder(phoneDirectory);
                break;
            case 3:
                printf("Exiting the phone directory.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    

    return 0;
}
