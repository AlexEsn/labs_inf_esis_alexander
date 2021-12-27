#include "gtest/gtest.h"
#include "tree/AVL.h"

TEST(ConstructBTree, Constr) {
    BTree<int> Btree;
    EXPECT_EQ(Btree.Size(), 0);
}

TEST(ConstructBTree, ConstrWithElement) {
    BTree<int> Btree(5);
    EXPECT_EQ(Btree.Size(), 1);
}

TEST(BTree, Insert) {
    BTree<int> Btree(5);
    Btree.Insert(11);
    EXPECT_EQ(Btree.Size(), 2);
}

TEST(BTree, InsertExsist) {
    BTree<int> Btree(5);
    Btree.Insert(11);
    EXPECT_EQ(Btree.Size(), 2);
    Btree.Insert(11);
    EXPECT_EQ(Btree.Size(), 2);
}

TEST(BTree, Remove) {
    BTree<int> Btree(5);
    Btree.Insert(11);
    Btree.Remove(11);
    EXPECT_EQ(Btree.Size(), 1);
}

TEST(BTree, RemoveNonExistent) {
    BTree<int> Btree(5);
    Btree.Insert(11);
    Btree.Remove(11);
    Btree.Remove(11);
    Btree.Remove(11);
    Btree.Remove(11);
    EXPECT_EQ(Btree.Size(), 1);
}