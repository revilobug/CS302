#include "BinarySearchTree.h"
#include <memory>
#include <iostream>
#include <algorithim>

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template <class ItemType>
BinarySearchTree(const ItemType& rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem))
{

}

// template <class ItemType>
// BinarySearchTree(const BinarySearchTree<ItemType>& tree)
// {
//     (*this) = tree;
// }

template <class ItemType>
bool BinarySearchTree::isEmpty() const
{
    if (rootPtr != nullptr)
        return false;

    return true;
}

template <class ItemType>
int BinarySearchTree::getHeight() const
{
    return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::
    getHeightHelper(std::shared_ptr<BinaryNode<ItemType> > subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        //recurse through the tree and find the longest path and add 1 to it
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr())
                       getHeightHelper(subTreePtr->getRightChildPtr());
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    int count = 0;
    if (rootPtr != nullptr)
    {
        count = getNumberOfNodesHelper(rootPtr);
    }
    return count;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::
    getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType> > subTreePtr) const
{
    int count = 1;
    if (subTreePtr->getLeftChildPtr() != nullptr)
    {
        count += getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
    }
    if (subTreePtr->getRightChildPtr() != nullptr)
    {
        count += getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }

    return count;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
    return rootPtr->getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
    rootPtr -> setItem(newData);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
               std::shared_ptr<BinaryNode<ItemType>> newNode)
{
    if (subTreePtr == nullptr)
        return newNodePtr
    else if (subTreePtr->getItem() > newNodePtr->getItem())
    {
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
    preorderHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        std::cout << subTreePtr->getItem() << std::endl;
        preorderHelper(subTreePtr->getLeftChildPtr());
        preorderHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>:: inorderTraverse() const
{
    inorderHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        inorderHelper(subTreePtr->getLeftChildPtr());
        std::cout << subTreePtr->getItem() << std::endl;
        inorderHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>:: postorderTraverse() const
{
    postorderHelper(rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        postorderHelper(subTreePtr->getLeftChildPtr());
        postorderHelper(subTreePtr->getRightChildPtr());
        std::cout << subTreePtr->getItem() << std::endl;
    }
}

template<class ItemType>
auto BinarySearchTree<ItemType>::
     copyTree(const std::shared_ptr<BinaryNode<ItemType> > oldTreeRootPtr) const
{
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    if (oldTreeRootPtr != nullptr)
    {
        newTreePtr= std::make_shared<BinaryNode<ItemType>> (oldTreeRootPtr->getItem(), nullptr, nullptr);
        newTreePtr -> setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTreePtr -> setRightChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    }
    return newTreePtr;
}



//
// template<class ItemType>
// bool BinarySearchTree<ItemType>::remove(const ItemType& target)
// {
//     bool success;
//     removeValue(rootPtr, target, success);
//
//     return success;
// }
//
// template<class ItemType>
// auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
//                  const ItemType target,
//                  bool& isSuccessful)
// {
//     if (subTreePtr == nullptr)
//         isSuccessful = false;
//     else if (subTreePtr->getItem() == target)
//     {
//         removeNode(subTreePtr);
//         isSuccessful = true;
//     } else if (subTreePtr -> getItem() > target)
//     {
//         tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
//         subTreePtr->setLeftChildPtr(tempPtr);
//     } else
//     {
//         tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
//         subTreePtr->setRightChildPtr(tempPtr);
//     }
//     return subTreePtr;
// }
//
// template<class ItemType>
// auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
// {
//     if (nodePtr->isLeaf())
//     {
//
//         return nodePtr;
//     }
//     else if ()
// }
