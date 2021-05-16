#include "binaryNodeTree.h"
#include <algorithim>
#include <memory>

template<class ItemType>
int BinaryNodeTree<ItemType>::
    getHeightHelper(std::shared_ptr<BinaryNode<ItemType> > subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        //recurse through the tree and find the longest path and add 1 to it
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr())
                       getHeightHelper(subTreePtr->getRightChildPtr())
}

template<class ItemType>
int BinaryNodeTree<ItemType>::
    getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType> > subTreePtr) const
{
    return 1;
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::
     balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                 std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    return 1;
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::
     moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType> > subTreePtr)
{
    return 1;
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::
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

template<class ItemType>
void BinaryNodeTree<ItemType>::
     destroyTree(std::shared_ptr<BinaryNode<ItemType> > subTreePtr)
{

}

template<class ItemType>
void BinaryNodeTree<ItemType>::
     preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType> > treePtr) const
{

}

template<class ItemType>
void BinaryNodeTree<ItemType>::
     inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType> > treePtr) const
{

}


template<class ItemType>
void BinaryNodeTree<ItemType>::
    postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType> > treePtr) const
{

}


/*
CONSTRUCTOR
*/

template<class ItemType>
BinaryNodeTree<ItemType>::
    BinaryNodeTree(const ItemType& rootItem) : rootPtr(nullptr)
{

}

template<class ItemType>
BinaryNodeTree<ItemType>::
    BinaryNodeTree(const ItemType& rootItem,
                   const std::shared_ptr<BinaryNodeTree<ItemType> > leftTreePtr,
                   const std::shared_ptr<BinaryNodeTree<ItemType> > rightTreePtr)
                   : rootPtr(std::make_shared<BinaryNode<ItemType> >(rootItem,
                                                                    copyTree(leftTreePtr->rootPtr),
                                                                    copyTree(rightTreePtr->rootPtr))

{

}

template<class ItemType>
BinaryNodeTree<ItemType>::
    BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType> >& tree)
{
    rootPtr = copyTree(tree -> rootPtr);
}


template<class ItemType>
bool BinaryNodeTree<ItemType>::
     isEmpty() const
{
    return false;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::
    getHeight() const
{
    return 0;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::
    getNumberOfNodes() const
{
    return 0;
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::
         getRootData() const
{
    return rootPtr->getItem();
}

template<class ItemType>
void BinaryNodeTree<ItemType>::
     add(const ItemType& newData)
{

}

template<class ItemType>
bool BinaryNodeTree<ItemType>::
     remove(const ItemType& data)
{
    return false;
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::
         getEntry(const ItemType& anEntry) const
{
    return 1;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::
     contains(const ItemType& anEntry) const
{
    return false;
}


template<class ItemType>
void BinaryNodeTree<ItemType>::
     preorderTraverse(void visit(ItemType&)) const
{

}


template<class ItemType>
void BinaryNodeTree<ItemType>::
     inorderTraverse(void visit(ItemType&)) const
{

}


template<class ItemType>
void BinaryNodeTree<ItemType>::
     postorderTraverse(void visit(ItemType&)) const
{

}

template<class ItemType>
BinaryNodeTree& BinaryNodeTree<ItemType>::
     operator = (const BinaryNodeTree& rightHandSide)
{
    return rightHandSide;
}
