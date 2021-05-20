#pragma once

#include <stdexcept>

template<class T>
class LinkedList {

public:
    class Node {
        friend class iterator;
        friend class LinkedList;

        Node() : IsEmpty_(true) {};
        explicit Node(T value) : data_(value), IsEmpty_(false) {};
        Node(Node &node) : IsEmpty_(false), data_(node.data_), pNext(node.pNext), pPrev(node.pPrev) {};

    private:
        T data_;
        Node *pNext;
        Node *pPrev;
        bool IsEmpty_;
    };

    class iterator {
        friend class Node;
        friend class LinkedList;

    public:
        //Constructors
        iterator() : node_() {};
        explicit iterator(Node *dn) : node_(dn) {}

        //Copy constructor
        iterator(const iterator &it) : node_(it.node_) {}
        iterator &operator=(const iterator &it) {
            node_ = it.node_;
            return *this;
        }

        //operator == means that two iterators point to the same node
        bool operator==(const iterator &it) const {
            return (node_ == it.node_);
        }
        bool operator!=(const iterator &it) const {
            return !(it == *this);
        }

        iterator &operator++() {
            if (node_->IsEmpty_ == true)
                throw std::out_of_range("incremented an empty iterator");
            if (node_->pNext == nullptr)
                throw std::out_of_range("tried to increment too far past the end");

            node_ = node_->pNext;
            return *this;
        }
        iterator &operator--() {
            if (node_->pPrev->IsEmpty_ == true)
                throw std::out_of_range("decremented an empty iterator");
            if (node_->pPrev == nullptr)
                throw std::out_of_range("tried to decrement past the beginning");

            node_ = node_->pPrev;
            return *this;
        }

        T &operator*() const {
            if (node_->IsEmpty_ == true)
                throw std::out_of_range("tried to dereference an empty iterator");

            return node_->data_;
        }

    private:
        Node *node_;

    };

    friend class iterator;
    friend class Node;

private:
    Node *head_;
    Node *teal_;

    iterator begin_it_;
    iterator end_it_;

public:
    //Constructors
    LinkedList();
    LinkedList(T *data, int length);

    //Copy constructor
    LinkedList(const LinkedList<T> &list);


    //Operations
    [[nodiscard]] bool IsEmpty() const { return head_ == teal_; }
    [[nodiscard]] size_t GetLength() const;
    iterator begin() const { return begin_it_; }
    iterator end() const { return end_it_; }

    void push_front(T node_val);
    void push_back(T node_val);
    bool insert_after(T node_val, const iterator &key_i);
    bool remove_it(iterator &key_i);

    T remove_front();
    T remove_back();

    iterator find(T node_val) const {
        for (Node *dn = head_; dn != teal_; dn = dn->pNext) {
            if (dn->data_ == node_val)
                return iterator(dn);
        }

        //Если node_val нет в списке возвращает end_it_
        return end_it_;
    }
    iterator get_nth(int element_num) const {
        if (element_num < 0)
            return end_it_;

        int count = 0;
        for (Node *dn = head_; dn != teal_; dn = dn->pNext) {
            if (count++ == element_num)
                return iterator(dn);
        }

        return end_it_;
    }

    //Decomposition
    LinkedList<T> *Concat(LinkedList<T> *list) const {};
    LinkedList<T> *GetSubList(int start_index, int end_index) const;

    //Destructor
    ~LinkedList();
};

#include "linkedlist.tpp"