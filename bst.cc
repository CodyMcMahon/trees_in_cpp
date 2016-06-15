// a bst with bst things in it
// the print creates a heap and then prints the heap with all the empty node it might have
// this is slow but provides a great end user experience which is my #1 priority :)

#include <iostream>
#include <stdlib.h>
#include "bst.h"

//heap macros
// i for collision reasons 
// p = parent
// lc = left child
// rc = right child
#define ip(i) (i-1)/2
#define ilc(i) 2*i+1
#define irc(i) 2*i+2


node::node(){
  data = 0;
  left = NULL;
  right = NULL;
}
node::node(int d){
  data = d;
  left = NULL;
  right = NULL;
}
bst::bst(){
  this->size = 0;
}

void bst::destroyerHelper(node* root){
  if (root->right){
    destroyerHelper(root->right);
  }
  if (root->left){
    destroyerHelper(root->left);
  }
  delete root;
}

bst::~bst(){
  this->destroyerHelper(head);
}

bst* bst::copy(){
  bst* temp = new bst();
  this->copyHelper(bst);
  
}

void bst::helpadd(node* root,int data){
  if(root == NULL){
    root = new node(data);
  }
  else if(root->data < data){
    if (root->right){
      this->helpadd(root->right,data);
    }
    else{
      root->right = new node(data);
    }
  }
  else if(root->data > data){
    if(root->left){
      this->helpadd(root->left,data);
    }
    else{
      root->left = new node(data);
    }
  }
  //no duplicates please
  return;
}

void bst::add(int thing){
  this->size++;
  //case empty tree
  if(this->head == NULL){
    head = new node(thing);
    head->left = NULL;
    head->right = NULL;
    return;
  }
  this->helpadd(this->head,thing);
}


node* bst::removeReplaceHelper(node* root){
  node* temp = root;
  node* temp2;
  if(temp->right){
    //delete root;
    temp = temp->right;
  }
  else if(temp->left){
    delete root;
    return temp->left;
  }
  else{
    delete root;
    return NULL;
  }
  
  if(temp->left){
    while(temp->left->left){
      temp = temp->left;
    }
    temp2 = temp->left;
    temp->left = temp->left->right;
    temp2->left = root->left;
    temp2->right = root->right;
    delete root;
    return temp2;
  }
  else{
    temp->left = root->left;
    delete root;
    return temp;
  }
}

int bst::removehelp(node* root, int data){
  int temp;
  if(root->data < data){
    if(root->right){
      if(root->right->data == data){
        root->right = this->removeReplaceHelper(root->right);
        return data;
      }
      else{
        this->removehelp(root->right, data);
      }
    }
    else{
      return 0;
    }
  }
  else if(root->data > data){
    if(root->left){
      if(root->left->data == data){
        root->left = this->removeReplaceHelper(root->left);
        return data;
      }
      else{
        this->removehelp(root->left, data);
      }
    }
    else{
      return 0;
    }
  }
}


int bst::remove(int thing){
  if (this->head){
    if (this->head->data == thing){
      size--;
      this->head = removeReplaceHelper(this->head);
      return thing;
    }
    else{
      if(removehelp(this->head,thing)){
        size--;
        return thing;
      }
      else{
        return 0;
      }
    }
  }
    
  else{
    return 0;
  }
}

void bst::resizeHeap(node*** myHeap,int* size,int newsize){
  *myHeap = (node**) realloc(*myHeap, sizeof(node*) * newsize);
  for(int i = *size;i<newsize;i++){
    (*myHeap)[i] = NULL;
  }
  *size = newsize;
}

void bst::mkheap(node*** myHeap,int* size,int index,node* root){
  (*myHeap)[index] = root;
  if(root->left){
    if(ilc(index) >= *size){
      resizeHeap(myHeap,size,ilc(index) + 1);
    }
    mkheap(myHeap,size,ilc(index),root->left);
  }
  if(root->right){
    if(irc(index) >= *size){
      resizeHeap(myHeap,size,irc(index) + 1);
    }
    mkheap(myHeap,size,irc(index),root->right);
  }
}

void bst::printtree(){
  int c = 1;
  int depth = 1;
  int size = this->size;
  node** myHeap = (node**) calloc(sizeof(node*),this->size);
  //for(int i = 0;i<this.size;i++){
    //myHeap[i] = -1;
  //}
  mkheap(&myHeap,&size,0,this->head);
  //myHeap[10] = new node(63);
  std::cout<<" | ";
  for(int i = 0;i<size;i++){
    if (c == 0){
      std::cout<<std::endl<<std::endl<<" | ";
      depth *= 2;
      c = depth - 1;
    }
    else{
      c--;
    }
    if(myHeap[i]){
      std::cout<<myHeap[i]->data<<" | ";
    }
    else{
      std::cout<<"XX"<<" | ";
    }
  }
  for(int i = c;i>0;i--){
    std::cout<<"XX"<<" | ";
  }
  std::cout<<std::endl;
  free(myHeap);
}



void bst::printinorderhelper(node* root){
  if (root->left){
    printinorderhelper(root->left);
  }
    std::cout<<root->data<<" | ";
  if (root->right){
    printinorderhelper(root->right);
  }
}

void bst::printinorder(){
  std::cout<<" | ";
  if(this->head){
    this->printinorderhelper(head);
  }
  else{
    std::cout<<"nil";
  }
  std::cout<<std::endl;
}
