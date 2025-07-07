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
    void insertBEFORE(int i,int val);
    int findMiddleElement(LinkedList &A);
    bool first(int &e);       // Should be non-const reference to modify e
    bool next(int &e);  
    int counter();
    void remove(const int&val);
    bool deleterAll(int i);
    void PrintBackWard(Node*);
    Node*merge(Node*a,Node*b);
    Node*FindMiddleNode();
    ~LinkedList();// Should be non-const reference to modify e
    int findSMAX();
    void Reverse(Node*);
    pair<Node*,Node*> split(Node*);
    Node*mergeSort(Node*);
};

LinkedList::LinkedList() {
    head = NULL;
    tail = nullptr;
    current = nullptr;
}

  int LinkedList::findMiddleElement(LinkedList &A){
      Node*slow=A.head;
      Node*fast=A.head;
      while(fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
      }
      return slow->val;
     
  }
 bool LinkedList::deleterAll(int i) {
    if (head == nullptr) return false;  // Empty list case
    
    Node* current = head;
    bool deletedAny = false;  // Track if we deleted anything
    
    // Need to handle head node separately
    if (head->val == i) {
        Node* temp = head;
        head = head->next;
        delete temp;
        deletedAny = true;
        current = head;  // Reset current after head changes
    }

    while (current != nullptr && current->next != nullptr) {
        if (current->next->val == i) {
            Node* temp = current->next;
            current->next = temp->next;  // Fix: Correct pointer update
            delete temp;
            deletedAny = true;
            // Don't advance current here as next node might also match
        } else {
            current = current->next;
        }
    }
    
    return deletedAny;  // Return whether we deleted anything
}

    int LinkedList::findSMAX(){
        int max1=head->val;
        int max2=-1;
        Node*current=head;
        while(current!=NULL){
            if(current->val>max1){
                max2=max1;
                max1=current->val;
            }
            else if(current->val>max2&&current->val!=max1){
                max2=current->val;
            }
            current=current->next;
        }
        return max2;
    }
    
void LinkedList::insert(int val, int e) {
    Node* newnode = new Node;
    newnode->val = e;
    newnode->next = nullptr;

    if (head == nullptr) {
        // List is empty, can't insert after specific value
        delete newnode;
        return;
    }

    Node* current = head;
    // Find the node with value 'val'
    while (current != nullptr && current->val != val) {
        current = current->next;
    }

    if (current == nullptr) {
        // Value 'val' not found in list
        delete newnode;
        return;
    }

    // Insert after 'current' node
    newnode->next = current->next;
    current->next = newnode;

    // Update tail if inserting after last node
    if (current == tail) {
        tail = newnode;
    }
}

void LinkedList::insert(const int &e) {
    Node* node = new Node;
    node->val = e;
    node->next = nullptr;
    
    if (head == nullptr) {
        head = node;
    } else {
        tail->next = node;
    }
    tail = node;
}

bool LinkedList::first(int &e) {
    if (head == nullptr) return false;
    e = head->val;
    current = head;
    return true;
}

bool LinkedList::next(int &e) {
    if (current == nullptr || current->next == nullptr) return false;
    current = current->next;
    e = current->val;  // Fixed: should be 'val' not 'elem'
    return true;
}
int LinkedList::counter(){
    Node* current=head;
    int count=0;
    while(current->next!=NULL){
        current=current->next;
        count++;
    }
    return count+1;
    
}
void LinkedList::Conc(LinkedList &A, LinkedList&B){
   if (A.head == nullptr) {
        // If A is empty, assign B
        this->head = B.head;
        return;
    }
    this->head = A.head;

    // Traverse to the end of A
    Node* current = A.head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Link last node of A to head of B
    current->next = B.head;
   
}
/*void LinkedList::insert(int pos,int&e){
    Node*node=new Node;
    node->next=NULL;
    node->val=e;
    Node*current=head;
    int i=0;
    while(current->next!=NULL&&i<pos-1){
        current=current->next;
        i++;
    }
    node->next = current->next; // New node points to successor
current->next = node;
}*/
void LinkedList::remove(const int &val) {  
        if (head == NULL) {
            return;
        }
        
        // Handle case where head needs to be deleted
        if (head->val == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        current = head;
        while (current->next!= NULL && current->next->val != val) {
            current = current->next;
        }
        
        if (current->next == NULL) {
            return;  // Value not found
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    void LinkedList::insertBEFORE(int i,int val){
        Node* node=new Node;
        node->val=val;
        if(head==NULL){
            head->val=val;
            head->next=nullptr;
        }
        Node*current=head;
        int count=1;
        while(current!=NULL&&count<i-1){
            current=current->next;
            count++;
        }
         node->next = current->next;
    current->next = node;
    }

/*void DoubleLinkedList::insert(const int &e){
    Node* node=new Node;
    node->info=e;
    if(head==NULL) {
        head=node;
        node->next=NULL;
    }
    Node*current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    node->prev=current;
    current->next=node;
    node->next=NULL;}*/


LinkedList::~LinkedList(){
    if(head==NULL){
        return;
    }
    Node*current=head;
    while(current->next!=NULL){
       Node*next=current->next;
       delete current;
       current=next;
        
    }
    
    return;
}
void LinkedList:: PrintBackWard(Node*head) {
    if(head==nullptr)return;
    else if(head->next==nullptr) cout<<head->val;
     else{
       PrintBackWard(head->next);
       cout<<head->val;
     }
    }
void LinkedList::Reverse(Node*p){
  if(p->next==NULL){
    head=p; //Now head is the last node of the list
    return;
  }
  Reverse(p->next);
  //Executed after the recursive call
  Node*q=p->next; //The old link
  q->next=p;  //The new link points from the last node(head now) to its previous node
  p->next=NULL; //delete the old link pointing from the previous to the last node
}
Node* LinkedList::merge(Node*a,Node*b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    Node*c;
    if(a->val<b->val){
        c=a;
        c->next=merge(a->next,b);
}
else if(b->val<a->val){
c=b;
c->next=merge(a,b->next);
}
return c;
}
Node*LinkedList::FindMiddleNode(){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
}
return slow;
}
pair<Node*,Node*>LinkedList::split(Node*head ){ //This is your linked list
Node*a=head;
Node*mid=FindMiddleNode(head);
Node*b=mid->next;
mid->next=NULL;
return {a,b}; //pair<,> is used to return multiple values. Why? Because return a,b; will only return b since comma operator is of higher precedence.
}
Node* LinkedList::mergeSort(Node*head){
if(head==nullptr || head->next=NULL){
return head;
}
Node*mid=FindMiddleNode(head);
Node*a=head;
Node*b=mid->next;
mid->next=NULL;
a=mergeSort(a); //Recursive sort
b=mergeSort(b);
return merge(a,b);
}
int main() {
  
    return 0;
}
