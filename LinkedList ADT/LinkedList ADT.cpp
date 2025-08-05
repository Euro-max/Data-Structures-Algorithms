#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
    };

    Node* head;
    Node* tail;
    Node* current;

public:
    LinkedList();
    void insert(const int &e);
    void insert(int val, int e);
    void insertBEFORE(int i, int val);
    int findMiddleElement(LinkedList &A);
    bool first(int &e);
    bool next(int &e);
    int counter();
    void remove(const int &val);
    bool deleterAll();
    void PrintBackWard(Node*);
    LinkedList::Node* merge(LinkedList::Node *a, LinkedList::Node *b);
    LinkedList::Node* FindMiddleNode();
    ~LinkedList();
    int findSMAX();
    void Reverse(Node*);
    pair<LinkedList::Node*, LinkedList::Node*> split(LinkedList::Node*);
    LinkedList::Node* mergeSort(LinkedList::Node*);
    LinkedList::Node* PrintwithNoDuplicates(LinkedList::Node*);
    LinkedList::Node* removeDuplicates(LinkedList::Node*);
    void Conc(LinkedList &A, LinkedList &B);

    Node* getHead() { return head; } // helper to access private head
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

int LinkedList::findMiddleElement(LinkedList &A) {
    Node* slow = A.head;
    Node* fast = A.head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow ? slow->val : -1;
}

bool LinkedList::deleterAll() {
   if (!head) return false;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    current = nullptr;

    return true;
}

int LinkedList::findSMAX() {
    if (!head) return -1;
    int max1 = head->val;
    int max2 = -1;
    Node* current = head->next;
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

void LinkedList::insert(int val, int e) {
    Node* newnode = new Node{e, nullptr};
    if (!head) {
        delete newnode;
        return;
    }
    Node* current = head;
    while (current && current->val != val) {
        current = current->next;
    }
    if (!current) {
        delete newnode;
        return;
    }
    newnode->next = current->next;
    current->next = newnode;
    if (current == tail) tail = newnode;
}

void LinkedList::insert(const int &e) {
    Node* node = new Node{e, nullptr};
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

bool LinkedList::first(int &e) {
    if (!head) return false;
    e = head->val;
    current = head;
    return true;
}

bool LinkedList::next(int &e) {
    if (!current || !current->next) return false;
    current = current->next;
    e = current->val;
    return true;
}

int LinkedList::counter() {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void LinkedList::Conc(LinkedList &A, LinkedList &B) {
    if (!A.head) {
        head = B.head;
        tail = B.tail;
        return;
    }
    head = A.head;
    Node* current = A.head;
    while (current->next) {
        current = current->next;
    }
    current->next = B.head;
    if (B.tail) tail = B.tail;
}

void LinkedList::remove(const int &val) {
    if (!head) return;
    if (head->val == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next && current->next->val != val) {
        current = current->next;
    }
    if (!current->next) return;
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    if (!current->next) tail = current;
}

void LinkedList::insertBEFORE(int i, int val) {
    Node* node = new Node{val, nullptr};
    if (i <= 1 || !head) {
        node->next = head;
        head = node;
        if (!tail) tail = node;
        return;
    }
    Node* current = head;
    int count = 1;
    while (current && count < i - 1) {
        current = current->next;
        count++;
    }
    if (!current) return;
    node->next = current->next;
    current->next = node;
    if (!node->next) tail = node;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::PrintBackWard(Node* head) {
    if (!head) return;
    PrintBackWard(head->next);
    cout << head->val << " ";
}

void LinkedList::Reverse(Node* p) {
    if (!p || !p->next) {
        head = p;
        return;
    }
    Reverse(p->next);
    p->next->next = p;
    p->next = nullptr;
}

LinkedList::Node* LinkedList::merge(LinkedList::Node* a, LinkedList::Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val < b->val) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

LinkedList::Node* LinkedList::FindMiddleNode() {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

pair<LinkedList::Node*, LinkedList::Node*> LinkedList::split(LinkedList::Node* head) {
    if (!head || !head->next) return {head, nullptr};
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = slow->next;
    slow->next = nullptr;
    return {head, second};
}

LinkedList::Node* LinkedList::mergeSort(LinkedList::Node* head) {
    if (!head || !head->next) return head;
    auto [a, b] = split(head);
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a, b);
}

LinkedList::Node* LinkedList::PrintwithNoDuplicates(LinkedList::Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            current = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}

LinkedList::Node* LinkedList::removeDuplicates(LinkedList::Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(20);
    list.insert(40);

    cout << "Second max: " << list.findSMAX() << endl;

    int mid = list.findMiddleElement(list);
    cout << "Middle element: " << mid << endl;

    cout << "List printed backward: ";
    list.PrintBackWard(list.getHead());
    cout << endl;

    return 0;
}
