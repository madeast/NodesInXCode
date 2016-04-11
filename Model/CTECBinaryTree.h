//
//  CTECBinaryTree.hpp
//  NodesInXCode
//
//  Created by Madsen, Easton on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECBinaryTree_h
#define CTECBinaryTree_h

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    bool balanced;
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    Type remove(const Type& value);
    int getHeight();
    bool isBalanced();
    TreeNode<Type>* getRoot();
};

#endif /* CTECBinaryTree_hpp */
