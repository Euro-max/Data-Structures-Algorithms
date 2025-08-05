#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    Node* current;
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void insert(LinkedList* list, int e) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = e;
    node->next = NULL;
    if (!list->head) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void insertAfter(LinkedList* list, int val, int e) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = e;
    newnode->next = NULL;
    Node* current = list->head;
    while (current && current->val != val) {
        current = current->next;
    }
    if (!current) {
        free(newnode);
        return;
    }
    newnode->next = current->next;
    current->next = newnode;
    if (current == list->tail) list->tail = newnode;
}

void insertBefore(LinkedList* list, int pos, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (pos <= 1 || !list->head) {
        node->next = list->head;
        list->head = node;
        if (!list->tail) list->tail = node;
        return;
    }
    Node* current = list->head;
    int count = 1;
    while (current && count < pos - 1) {
        current = current->next;
        count++;
    }
    if (!current) return;
    node->next = current->next;
    current->next = node;
    if (!node->next) list->tail = node;
}

int findMiddleElement(LinkedList* list) {
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow ? slow->val : -1;
}

int findSMAX(LinkedList* list) {
    if (!list->head) return -1;
    int max1 = list->head->val;
    int max2 = -1;
    Node* current = list->head->next;
    while (current) {
        if (current->val > max1) {
            max2 = max1;
            max1 = current->val;
        } else if (current->val > max2 && current->val != max1) {
            max2 = current->val;
        }
        current = current->next;
    }
    return max2;
}

int first(LinkedList* list, int* e) {
    if (!list->head) return 0;
    *e = list->head->val;
    list->current = list->head;
    return 1;
}

int next(LinkedList* list, int* e) {
    if (!list->current || !list->current->next) return 0;
    list->current = list->current->next;
    *e = list->current->val;
    return 1;
}

int counter(LinkedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void removeVal(LinkedList* list, int val) {
    if (!list->head) return;
    if (list->head->val == val) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    Node* current = list->head;
    while (current->next && current->next->val != val) {
        current = current->next;
    }
    if (!current->next) return;
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    if (!current->next) list->tail = current;
}

void PrintBackWard(Node* head) {
    if (!head) return;
    PrintBackWard(head->next);
    printf("%d ", head->val);
}

void Reverse(LinkedList* list, Node* p) {
    if (!p || !p->next) {
        list->head = p;
        return;
    }
    Reverse(list, p->next);
    p->next->next = p;
    p->next = NULL;
}

void deleteAll(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = list->current = NULL;
}

int main() {
    LinkedList list;
    initList(&list);
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 20);
    insert(&list, 40);

    printf("Second max: %d\n", findSMAX(&list));
    printf("Middle element: %d\n", findMiddleElement(&list));

    printf("List printed backward: ");
    PrintBackWard(list.head);
    printf("\n");

    deleteAll(&list);
    return 0;
}
