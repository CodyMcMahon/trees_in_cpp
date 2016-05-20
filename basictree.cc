#include <iostream>
#include "bst.h"

int main(){
  bst* tree = new bst();
  tree->add(44);
  tree->add(34);
  tree->add(67);
  tree->add(1422);
  tree->add(37);
  tree->add(39);
  tree->add(38);
  tree->printtree();
}