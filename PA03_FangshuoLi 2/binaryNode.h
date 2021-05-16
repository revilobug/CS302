#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <memory>
#include <iostream>

template<class ItemType>
class BinaryNode
{
private:
    ItemType item;             // Data portion
    std::shared_ptr<BinaryNode<ItemType> > leftChildPtr;     // Pointer to left child
    std::shared_ptr<BinaryNode<ItemType> > rightChildPtr;    // Pointer to right child
public:
    BinaryNode();
    BinaryNode(const ItemType& anItem);
    BinaryNode(const ItemType& anItem,
               std::shared_ptr<BinaryNode<ItemType> > leftPtr,
               std::shared_ptr<BinaryNode<ItemType> > rightPtr);

    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    bool isLeaf() const;

    auto getLeftChildPtr() const;
    auto getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType> > leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType> > rightPtr);
}; // end BinaryNode




template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : item(NULL),
                                     leftChildPtr(nullptr),
                                     rightChildPtr(nullptr)
{
    //std::cout<<"binarynode constructed" << std::endl;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem): item(anItem),
                                                          leftChildPtr(nullptr),
                                                          rightChildPtr(nullptr)
{
    //std::cout<<"binarynode: parameterized constructed" << std::endl;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
           std::shared_ptr<BinaryNode<ItemType>> leftPtr,
           std::shared_ptr<BinaryNode<ItemType>> rightPtr): item(anItem),
                                                            leftChildPtr(leftPtr),
                                                            rightChildPtr(rightPtr)

{
    //std::cout<<"binaryNode: specific paramterized constructed" << std::endl;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    //set item
    item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    //return
    return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    //if both valid
    if (leftChildPtr && rightChildPtr)
        return true;

    return false;
}

template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
    //return
    return leftChildPtr;
}

template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
    //return
    return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
    //assign value
    leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
    //assign value
    rightChildPtr = rightPtr;
}


#endif
