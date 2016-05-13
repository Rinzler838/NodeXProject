//
//  CTECBinaryTree.cpp
//  NodeXProject
//
//  Created by Villalobos, Deigen on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.h"

using namespace std;

template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
CTECBinaryTree<Type> :: ~CTECBinaryTree()
{
    while (root != nullptr)
    {
        remove(root);
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: insert(const Type & value)
{
    TreeNode<Type> * insertedNode = new TreeNode<Type>(value);
    
    assert (insertedNode != nullptr);
    
    if (contains(value))
    {
        return false;
    }
    else
    {
        if (value < root->getValue())
        {
            insert(value);
        }
        else
        {
            insert(value);
        }
        return true;
    }
}

template <class Type>
Type CTECBinaryTree<Type> :: remove(const Type & value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> *trailing = current;
    if (!contains(value))
    {
        return value;
    }
    else
    {
        while (current != nullptr&& current->getValue() != value)
        {
            trailing = current;
            if (current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        if (current == root)
        {
            remove(root);
        }
        else if (trailing->getValue() > value)
        {
            remove(trailing->getLeftChild);
        }
        else
        {
            remove(trailing->getRightChild);
        }
    }
}

template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToRemove)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if (nodeToRemove == nullptr)
    {
        cerr << "You can't remove an empty/non-existent thing" << endl;
    }
    else if (nodeToRemove->getRightChild() == nullptr && nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if (nodeToRemove->getRightChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getLeftChild();
        delete temp;
    }
    else if (nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getRightChild();
        delete temp;
    }
    else
    {
        current = nodeToRemove->getLeftChild();
        trailing = nullptr;
        
        while (current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        nodeToRemove->setValue(current->getValue());
        
        if (trailing == nullptr)
        {
            nodeToRemove->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }
}

template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " ";
        inorderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        cout << currentNode->getValue() << " ";
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " ";
    }
}

template <class Type>
int CTECBinaryTree<Type> :: getSize()
{
    calculatedSize(root);
    return size;
}

template <class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        size++;
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    /*
     * Is the value in root? - return true else
     * If the value is not in the root and is less than root - call contains on left child
     * Else if the value is not in the root and is greater then root - call contains on right
     */
    
    if (root->getValue() == value)
    {
        return true;
    }
    else if(value < root->getValue())
    {
        return contains(value, root->getLeftChild());
    }
    else
    {
        return contains(value, root->getRightChild());
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, TreeNode<Type> * currentTree)
{
    /*
     * Is the value in root? - Return true
     * If the value is not in the root and is less than root - Call contains on left child
     * Else if the value is not in the root and is greater then root - Call contains on right child
     */
    
    bool isInTree = false;
    if (currentTree == nullptr)
    {
        isInTree = false;
    }
    
    if (currentTree->getValue() == value)
    {
        isInTree = true;
    }
    else if (value < currentTree->getValue())
    {
        isInTree = contains(value, currentTree->getLeftChild());
    }
    else
    {
        isInTree = contains(value, currentTree->getRightChild());
    }
    return isInTree;
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(TreeNode<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    while (rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(TreeNode<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    while (leftNode->getLeftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}
