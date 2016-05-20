#include <iostream>
#include <stdlib.h>
#include "bst.h"
node::node(int de){
  data = 0;
  depth = de;
  left = NULL;
  right = NULL;
}
node::node(int d,int de){
  data = d;
  depth = de;
  left = NULL;
  right = NULL;
}
bst::bst(){
  this->size = 0;
  head = new node(0);
  head->data = NULL;
  head->left = NULL;
  head->right = NULL;
}

void bst::helpadd(node* root,int data,int depth){
  if(root == NULL){
    root = new node(data,depth);
  }
  else if(root->data < data){
    if (root->right){
      this->helpadd(root->right,data,depth+1);
    }
    else{
      root->right = new node(data,depth+1);
    }
  }
  else if(root->data > data){
    if(root->left){
      this->helpadd(root->left,data,depth+1);
    }
    else{
      root->left = new node(data,depth+1);
    }
  }
  //no duplicates please
  return;
}

void bst::add(int thing){
  this->size++;
  //case empty tree
  if(this->head->data == NULL){
    this->head->data = thing;
    return;
  }
  this->helpadd(this->head,thing,0);
}
int bst::remove(int thing){
  //do later
  
}
void bst::printtree(){
  int index = 1;
  int start = 0;
  node** myQueue = (node**) calloc(sizeof(node*),this->size);
  node* temp;
  myQueue[0] = head;
  int current_depth = -1;
  while(index != start){
    temp = myQueue[start];
    if(temp->depth>current_depth){
      current_depth++;
      std::cout<<std::endl<<current_depth<<":   ";
    }
    std::cout << temp->data<< " | ";
    start = ((start+1)%this->size);
    
    if(temp->left){
      myQueue[index] = temp->left;
      index = ((index+1)%this->size);
    }
    if(temp->right){
      myQueue[index] = temp->right;
      index = ((index+1)%this->size);
    }
  }
  free(myQueue);
}