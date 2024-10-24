#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void initDoublyLinkedList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void displayDoublyLinkedList(DoublyLinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void insertAtPosition(DoublyLinkedList* list, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    int i = 0;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        list->tail = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(temp);
}

void deleteAtEnd(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(temp);
}

void deleteAtPosition(DoublyLinkedList* list, int position) {
    Node* temp = list->head;
    int i = 0;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    } else {
        list->tail = temp;
    }
    free(nodeToDelete);
}

int main() {
    DoublyLinkedList list;
    initDoublyLinkedList(&list);
    insertAtBeginning(&list, 1);
    printf("List before insertion : ");
    displayDoublyLinkedList(&list);

    insertAtBeginning(&list, 2);
    insertAtBeginning(&list, 3);
    printf("After insertion at beginning : ");
    displayDoublyLinkedList(&list);

    insertAtEnd(&list, 4);
    insertAtEnd(&list, 5);
    insertAtEnd(&list, 6);
    printf("After insertion at end : ");
    displayDoublyLinkedList(&list);

    insertAtPosition(&list, 7, 3);
    printf("After insertion at the middle : ");
    displayDoublyLinkedList(&list);

    deleteAtBeginning(&list);
    printf("After deletion at the beginning : ");
    displayDoublyLinkedList(&list);

    deleteAtEnd(&list);
    printf("After deletion at the end : ");
    displayDoublyLinkedList(&list);

    deleteAtPosition(&list, 3);
    printf("After deletion at the middle : ");
    displayDoublyLinkedList(&list);

    return 0;
}