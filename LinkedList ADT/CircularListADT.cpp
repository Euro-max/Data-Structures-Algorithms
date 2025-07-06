struct Node{
int data;
Node*next;
};
Node*cursor=NULL;
void Create(){
  cursor=nullptr;
};
bool isEmpty(){
  return cursor==nullptr;
}
void Insert(int value){
  Node*newnode=new Node;
newnode->data=value;
if(isEmpty()){
cursor=newnode;
cursor->next=cursor;
}
else{
newnode->next=cursor->next;
cursor->next=newnode;
cursor=newnode;
}
}
void Delete(){
  if(isEmpty()){ 
    cout<<"Nothing to delete";
  }
  else if(cursor->next=cursor){ 
    delete cursor;
    cursor=NULL;
  }
else{
Node*temp=cursor->next;
cursor->next=temp->next;
delete temp;
}
}
void PrintList(){
if (isEmpty()) {
        cout << "List is empty\n";
        return;
    }

    Node* head = cursor->next;
    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
void InsertAt(int value, int pos){
  Node* newnode = new Node;
    newnode->data = value;

    if (isEmpty()) {
        // If empty, insert the first node
        cursor = newnode;
        cursor->next = cursor;
        return;
    }

    Node* head = cursor->next;  // Start at head
    int i = 0;

    // Special case: insert at head (position 0)
    if (pos == 0) {
        newnode->next = temp;
        cursor->next = newnode;
        return;
    }

    // Traverse to the node just before the desired position
    while (i < pos - 1 && head != cursor->next) {
        head = head->next;
        i++;
    }

    // Insert after temp
    newnode->next = head->next;
    head->next = newnode;

    // Optional: update cursor if inserted at end
    if (head == cursor) {
        cursor = newnode;
    }
}
void DeleteAt(int position) {
    if (isEmpty()) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    Node* temp = cursor->next;  // head

    // Special case: delete head
    if (position == 0) {
        if (cursor == cursor->next) {
            // Only one node
            delete cursor;
            cursor = NULL;
        } else {
            cursor->next = temp->next;
            delete temp;
        }
        return;
    }

    // Traverse to node before the one to delete
    int i = 0;
    Node* prev = temp;
    while (i < position - 1 && prev->next != cursor->next) {
        prev = prev->next;
        i++;
    }

    Node* toDelete = prev->next;

    // Check if position is out of bounds
    if (toDelete == cursor->next && i != position - 1) {
        cout << "Invalid position.\n";
        return;
    }

    prev->next = toDelete->next;

    // Update cursor if needed
    if (toDelete == cursor) {
        cursor = prev;
    }

    delete toDelete;
}
