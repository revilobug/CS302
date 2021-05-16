#include <iostream>
#include <memory>
#include "binaryNode.h"

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : item(NULL),
                                     leftChildPtr(nullptr),
                                     rightChildPtr(nullptr)
{
    std::cout<<"binarynode constructed" << std::endl;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem): item(anItem),
                                                          leftChildPtr(nullptr),
                                                          rightChildPtr(nullptr)
{
    std::cout<<"binarynode: parameterized constructed" << std::endl;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
           std::shared_ptr<BinaryNode<ItemType>> leftPtr,
           std::shared_ptr<BinaryNode<ItemType>> rightPtr): item(anItem),
                                                            leftChildPtr(leftPtr),
                                                            rightChildPtr(rightPtr)

{
    std::cout<<"binaryNode: specific paramterized constructed" << std::endl;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    if (leftChildPtr && rightChildPtr)
        return true;

    return false;
}

template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}

template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
    leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
    rightChildPtr = rightPtr;
}
