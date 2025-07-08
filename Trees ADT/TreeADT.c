#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<Math.h>
#include<stdbool.h>
class Tree{
private:
struct Node{
int data;
Node*left;
Node*right;};
public:
Tree(){
  Node*root=nullptr;
  root->left=nullptr;
  root->right=nullptr;
}
Node* CreateNode(int value){
  Node*newnode=malloc(sizeof(Node));
  if(newnode!=NULL){
newnode->data=value;
newnode->right=nullptr;
newnode->left=nullptr;
  }
  return newnode;
}
void PreOrder(Node*root){
  if(root==nullptr)return;
  else{
    printf("%c",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
  }
}
void InOrder(Node*root){
  if(root==nullptr)return;
  else{
    PreOrder(root->left);
    printf("%c",root->data);
    PreOrder(root->right);
  }
}
void PostOrder(Node*root){
  if(root==nullptr)return;
  else{
    PreOrder(root->left);
    PreOrder(root->right);
    printf("%c",root->data);
  }
}
void BFS(Node*root){
  if(!root)return;
  queue<Node*>q;
  q.push(root);
  while(!q.isEmpty){
    Node*current=q.front();
    q.pop();
    printf("%c",current->data);
    if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
}
}
int FindHeight(Node*root){
  if(!root) return -1;
int leftHeight=FindHeight(root->left);
int rightHeight=FindHeight(root->right);
return Math.max(leftHeight,rightHeight)+1;
}
int FindMin(Node*root){ //Remember you are looking for the deepest left subtree specifically the left node
  if(!root)return -1;
  Node*current=root;
  while(current->left!=nullptr){
    current=current->left;
}
return current->data;
}
int FindMax(Node*root){ //Remember you are looking for the deepest right subtree specifically the right node
  if(!root)return -1;
  Node*current=root;
  while(current->right!=nullptr){
    current=current->right;
}
return current->data;
}
bool isBalanced(Node*root){
  if(!root)return true;
int leftHeight=FindHeight(root->left);
int rightHeight=FindHeight(root->right);
if(Math.abs(leftHeight-rightHeight)<=1) return true;
return isBalanced(root->left)&&isBalanced(root->right);
}
bool Insert(Node**rootptr,int data){
  Node*root=*rootptr;
  Node*mynode=CreateNode(data);
  if(root==NULL){
    root=mynode;
    return true;
  }
  if(data==root->data)return false;
  else if(root->data<data) return Insert(&(root->right),data);
  else return Insert(&(root->left),data); //double pointer
}
bool Search(Node*root,int target){ //if BST
  if(!root)return false;
   if (root->data == target) return true;
  if(target<root->data) return Search(root->left,target);
  if(target>root->data) return Search(root->right,target);
}
bool TSearch(Node*root,int target){ //if not BST
   if(!root)return false;
   if (root->data == target) return true;
  return Search(root->left,target)||Search(root->right,target);
}
bool isBST(Node*root,int minVal,int maxVal){
  if (!root) return true;

    if (root->data <= minVal || root->data >= maxVal) //Import climits so that you pass in INT_MIN as argument for the parameter minVal
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}
}
