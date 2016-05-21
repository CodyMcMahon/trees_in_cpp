#ifndef BST_H
#define BST_H

class node{
  public:
    node();
    node(int d);
    int data;
    node* left;
    node* right;
};

class bst{
  public:
    bst();
    ~bst();
    bst* copy();
    void add(int thing);
    int remove(int thing);
    void printtree();
    void printinorder();
  protected:
    node* head;
  
  
  private:
    void printinorderhelper(node* root);
    void destroyerHelper(node* root);
    int removehelp(node* root, int data);
    node* removeReplaceHelper(node* root);
    void helpadd(node* root,int data);
    void resizeHeap(node*** myHeap,int* size,int newsize);
    void mkheap(node*** myHeap, int* size,int index,node* root);
    int size;
  
};


#endif