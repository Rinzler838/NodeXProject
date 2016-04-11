//
//  TreeNode.cpp
//  NodeXProject
//
//  Created by Villalobos, Deigen on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "TreeNode.h"

template <class Type>
TreeNode<Type> :: TreeNode()
{
    this->leftChilde = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
}

template <class Type>
TreeNode<Type> :: TreeNode(const Type & value)
{
    this->leftChilde = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
    
    this->setVaue(value);
}

template <class Type>
TreeNode<Type> :: TreeNode(const Type & value, TreeNode<Type> * parent)
{
    this->leftChilde = nullptr;
    this->rightChild = nullptr;
    this->parent = nullptr;
    
    this->setVaue(value);
    this->setParent(parent);
}