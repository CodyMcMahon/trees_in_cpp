#ifndef BST_H
#define BST_H

class node{
  public:
    node(int de);
    node(int d,int de);
    int data;
    int depth;
    node* left;
    node* right;
};

class bst{
  public:
    bst();
    void add(int thing);
    int remove(int thing);
    void printtree();
  protected:
    node* head;
  
  
  private:
    void helpadd(node* root,int data,int depth);
    int size;
  
};


#endif