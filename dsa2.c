#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a club member
struct ClubMember {
    int misRegistrationNo;
    char name[50];
    struct ClubMember *next;
};

// Function to create a new club member
struct ClubMember *createMember(int misRegistrationNo, const char *name) {
    struct ClubMember *newMember = (struct ClubMember *)malloc(sizeof(struct ClubMember));
    if (newMember == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newMember->misRegistrationNo = misRegistrationNo;
    strcpy(newMember->name, name);
    newMember->next = NULL;
    return newMember;
}

// Function to add a new member to the end of the list
void addMember(struct ClubMember **head, int misRegistrationNo, const char *name) {
    struct ClubMember *newMember = createMember(misRegistrationNo, name);
    if (*head == NULL) {
        *head = newMember;
    } else {
        struct ClubMember *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMember;
    }
}

// Function to delete a member by MIS registration number
void deleteMember(struct ClubMember **head, int misRegistrationNo) {
    struct ClubMember *current = *head;
    struct ClubMember *prev = NULL;
    
    // Find the member to be deleted
    while (current != NULL && current->misRegistrationNo != misRegistrationNo) {
        prev = current;
        current = current->next;
    }
    
    // If the member is found, remove it from the list
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *head = current->next;
        }
        free(current);
        printf("Member with MIS No. %d has been deleted.\n", misRegistrationNo);
    } else {
        printf("Member with MIS No. %d not found.\n", misRegistrationNo);
    }
}

// Function to print the list of club members
void printMembers(struct ClubMember *head) {
    printf("Club Members:\n");
    while (head != NULL) {
        printf("MIS No.: %d, Name: %s\n", head->misRegistrationNo, head->name);
        head = head->next;
    }
}

int main() {
    struct ClubMember *clubMembers = NULL;

    // Add some members to the club
    addMember(&clubMembers, 1234, "John");
    addMember(&clubMembers, 5678, "Alice");
    addMember(&clubMembers, 9012, "Bob");

    // Print the initial list of members
    printMembers(clubMembers);

    // Delete a member by MIS registration number
    deleteMember(&clubMembers, 5678);

    // Print the updated list of members
    printMembers(clubMembers);

    // Free the memory allocated for the list
    while (clubMembers != NULL) {
        struct ClubMember *temp = clubMembers;
        clubMembers = clubMembers->next;
        free(temp);
    }

    return 0;
}
