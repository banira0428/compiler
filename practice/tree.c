#include <stdio.h>

typedef struct node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

Node *newNode(int n){
  Node n_node = {n, NULL, NULL};
  return &n_node;
};
Node *addNode(Node *obj, int n){

}

Node *appendRightEnd(Node *obj, Node *right){

}

Node *deleteNode(Node *obj, int n){

}

void printNodes(Node *obj){
  printf("%d\n",obj->value);
  if(obj->left != NULL){
    printNodes(obj->left);
  }
  if(obj->right != NULL){
    printNodes(obj->right);
  }
}

int main(){

  Node *root = newNode(1);

  printNodes(root);

  return 0;
}