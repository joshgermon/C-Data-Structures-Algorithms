#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void printList(Node* head) {
    if(head == NULL) {
        printf("Your list is empty.");
        return;
    }
    int idx = 0;
    Node* curr = head;
    while(curr != NULL) {
        int value = curr->value;
        printf("->%d", value);
        curr = curr->next;
        idx++;
    }
    printf("\n");
}

void addToHead(Node** head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void addToTail(Node* head, int value) {
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    curr->next = newNode;
}

void addAtIndex(Node* head, int value, int index) {
    int i = 0;
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
        i++;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
}

void deleteAtIndex(Node* head, int index) {
    int i = 0;
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
        i++;
    }
}

void freeLinkedList(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}

int main(int argc, char *argv[]) {
    Node* list = malloc(sizeof(Node));
    list->value=1;
    Node* newNode = malloc(sizeof(Node));
    list->next = newNode;

    addToTail(list, 123);
    addToHead(&list, 222);
    addToTail(list, 111);
    addToHead(&list, 444);
    // while(1) {
    //     printf("********************\n");
    //     printf("My C Linked List:\n");
    //     printList(list);
    //     int opt;
    //     int val;
    //     printf("1) Add to head\n2) Add to tail\n");
    //     scanf("%d", &opt);
    //     switch (opt) {
    //         case 1:
    //             printf("Value to add:");
    //             scanf("%d", &val);
    //             addToHead(&list, val);
    //             break;
    //         case 2:
    //             printf("Value to add:");
    //             scanf("%d", &val);
    //             addToTail(list, val);
    //             break;
    //     }
    // }

    // freeLinkedList(list);
    return 0;
}
