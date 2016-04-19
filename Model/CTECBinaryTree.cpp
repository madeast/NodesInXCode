//
//  CTECBinaryTree.cpp
//  NodesInXCode
//
//  Created by Madsen, Easton on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.h"
using namespace std;

template<class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template<class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    TreeNode<Type> * insertedNode(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
        else
        {
            current = root;
            
            while (current != nullptr)
            {
                trailingCurrent = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            } //End while
            if(trailingCurrent->getValue() > value)
            {
                trailingCurrent->setLeftChild(insertedNode);
                insertedNode->setParent(trailingCurrent);
            }
            else
            {
                trailingCurrent->setRightChild(insertedNode);
            }
            
            insertedNode->setParent(trailingCurrent);
        }
        return true;
    }
}


template<class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " " ;
        inorderTraversal(currentNode->getRightChild());
    }
}

template<class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        cout << currentNode->getValue() << " " ;
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
}

template<class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " ;
    }
}

template<class Type>
int CTECBinaryTree<Type>:: getHeight()
{
    calculateSize(root);
    return height;
}
template<class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode->getLeftChild());
        calculateSize(currentNode->getRightChild());
        height++;
    }
}

template<class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    /*
     Is  value in root? - return true else
     If the value is not in the root and is less than rott - call contains on left child.
     Elsethe value is not in the root and is greater thatn root - call contains on right child.
     */
    if(currentTree == nullptr)
    {
        return false;
    }
    else if(currentTree->getRoot()->getValue() == value)
    {
        return contains(value, currentTree->getRoot()->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRoot()->getRightChild());
    }
    return false;
}

template<class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    /*
     Is  value in root? - return true else
     If the value is not in the root and is less than rott - call contains on left child.
     Else the value is not in the root and is greater thatn root - call contains on right child.
     */
    bool isInTree = false;
    if(root->getValue == value)
    {
        return true;
    }
    else if(value < root->getValue)
    {
        isInTree = contains(value, root->getLeftChild());
    }
    else
    {
        isInTree = contains(value, root->getRightChild());
    }
    return false;
}

template<class Type>
Type CTECBinaryTree<Type> :: remove(const Type& value)
{
    
    if(!contains(value))
    {
        return value;
    }
    else
    {
        
    }
//    CTECBinaryTree<Type> *current; //Pointer to traverse the tree.
//    CTECBinaryTree<Type> *trailCurrent; //Pointer behind current pointer.
//    CTECBinaryTree<Type> *temp; //Pointer to delete the node.
//    
//    if(value == NULL)
//    {
//        cerr << "Error: The node to be deleted is NULL" << endl;
//    }
//    else if(value->setLeftChild == NULL && value->setRightChild == NULL)
//    {
//        temp = value;
//        value = NULL;
//        delete temp;
//    }
//    else if(value->setLeftChild == NULL)
//    {
//        
//    }
//    else if(value->setRightChild == NULL)
//    {
//        
//    }
//    else{
//        current = value->setLeftChild;
//        trailCurrent = NULL;
//        
//        while(current->setRightChild != NULL)
//        {
//            trailCurrent = current;
//            current = current->rlink;
//        }// end while
//        
//        value->info = current->rlink;
//        
//        if(trailCurrent == NULL) //current did not move;
//        {
//            value->setLeftChild = current->llink;
//        }
//        else
//        {
//            trailCurrent->rlink = current->llink;
//        }
//        delete current;
//    }
}