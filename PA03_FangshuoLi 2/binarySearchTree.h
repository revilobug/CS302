/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "binaryNode.h"
#include <memory>
#include <iostream>
#include <algorithm>

template<class ItemType>
class BinarySearchTree
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------

    // Places a given new node at its proper position in this binary
    auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                    std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

    // Helps get height
    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    // Traversal Helpers
    void postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    void preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    void inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    //tree copy
    auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

    //get number of nodes
    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;

    ItemType getRootData() const;
    void setRootData(const ItemType& newData);

    bool add(const ItemType& newEntry);
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;

}; // end BinarySearchTree

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
    //for debugging purposes
    std::cout << "BST constructed" << std::endl;
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem))
{
    //for debugging puposes
    std::cout << "BST parameter constructed" << std::endl;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    //if the rootPtr is not null, then it is not empty
    if (rootPtr != nullptr)
        return false;

    return true;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    //call height helper function with rootPtr as first node
    return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::
    getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    //if gone too far, return 0
    if (subTreePtr == nullptr)
        return 0;
    else
        //recurse through the tree and find the longest path and add 1 to it
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                       getHeightHelper(subTreePtr->getRightChildPtr())
                      );
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    //set count to 0
    int count = 0;

    //if rootPtr is not null then call get node helper
    if (rootPtr != nullptr)
    {
        count = getNumberOfNodesHelper(rootPtr);
    }

    //return count
    return count;
}

template<class ItemType>
int BinarySearchTree<ItemType>::
    getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    //set count to 1 so it can increment
    int count = 1;

    //if not a leaf
    if (subTreePtr->getLeftChildPtr() != nullptr)
    {
        //recuse and add 1 for each node
        count += getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
    }
    if (subTreePtr->getRightChildPtr() != nullptr)
    {
        //recurse and add 1 for each node
        count += getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }

    //return count
    return count;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
    //protection
    if (rootPtr != nullptr)
        return rootPtr->getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
    //protection
    if (rootPtr != nullptr)
        rootPtr -> setItem(newData);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
    //if rootPtr has not been defined
    if (rootPtr == nullptr)
    {
        //create an object for rootPtr with newEntry as the item
        rootPtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
        //no need to continue
        return true;
    }

    //create a temporary new pointer with newEntry
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);

    //place new node in rootPtr tree
    rootPtr = placeNode(rootPtr, newNodePtr);

    //return true always
    return true;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
               std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    //create a temp pointer
    std::shared_ptr<BinaryNode<ItemType>> tempPtr;

    //if tree root is null
    if (subTreePtr == nullptr)
        //end by returning as is
        return newNodePtr;

    //if the new node is less than the current item
    else if (subTreePtr->getItem() > newNodePtr->getItem())
    {
        //recall placenode with the left child instead
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        //place node once reached correct position
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        //recall placenode with the left child instead
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        //place node once reached correct position
        subTreePtr->setRightChildPtr(tempPtr);
    }

    //return the tree
    return subTreePtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
    //call helper
    preorderHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    //if not nullptr
    if (subTreePtr != nullptr)
    {
        //print, left, right
        std::cout << subTreePtr->getItem() << std::endl;
        preorderHelper(subTreePtr->getLeftChildPtr());
        preorderHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>:: inorderTraverse() const
{
    //call helper
    inorderHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    //if not nullptr
    if (subTreePtr != nullptr)
    {
        //left, print, right
        inorderHelper(subTreePtr->getLeftChildPtr());
        std::cout << subTreePtr->getItem() << std::endl;
        inorderHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>:: postorderTraverse() const
{
    //call helper
    postorderHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    //if not nullptr
    if (subTreePtr != nullptr)
    {
        //left, right, print
        postorderHelper(subTreePtr->getLeftChildPtr());
        postorderHelper(subTreePtr->getRightChildPtr());
        std::cout << subTreePtr->getItem() << std::endl;
    }
}

template<class ItemType>
auto BinarySearchTree<ItemType>::
     copyTree(const std::shared_ptr<BinaryNode<ItemType> > oldTreeRootPtr) const
{
    //create the new treeptr
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    //if not nullptr
    if (oldTreeRootPtr != nullptr)
    {
        //set right settings
        newTreePtr= std::make_shared<BinaryNode<ItemType>> (oldTreeRootPtr->getItem(), nullptr, nullptr);
        newTreePtr -> setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTreePtr -> setRightChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    }
    return newTreePtr;
}

#endif
