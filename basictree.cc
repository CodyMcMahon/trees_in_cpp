#include <iostream>
#include "bst.h"

int main(){
  bst* tree = new bst();
  tree->add(20);
  tree->add(25);
  tree->add(23);
  tree->add(24);
  tree->add(22);
  tree->add(27);
  tree->add(26);
  tree->add(28);
  std::cout<<"normal tree"<<std::endl;
  tree->printtree();
  tree->printinorder();
  
  std::cout<<std::endl<<std::endl<<"remove 23"<<std::endl;
  tree->remove(23);
  tree->printtree();
  tree->printinorder();
  std::cout<<std::endl;
  std::cout<<std::endl<<std::endl<<"remove 25"<<std::endl;
  
  tree->remove(25);
  tree->printtree();
  tree->printinorder();
  std::cout<<std::endl;
  std::cout<<std::endl<<std::endl<<"remove 20"<<std::endl;
  
  tree->remove(28);
  tree->printtree();
  tree->printinorder();
  std::cout<<std::endl;
  std::cout<<std::endl<<std::endl<<"remove 28"<<std::endl;
  
  tree->remove(28);
  tree->printtree();
  tree->printinorder();
  delete tree;
}