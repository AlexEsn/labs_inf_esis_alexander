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

    //Decomposition
    LinkedList<T> *Concat(LinkedList<T> *list) const {};

    LinkedList<T> *GetSubList(int start_index, int end_index) const;

    [[nodiscard]] size_t GetLength() const;

    //Operations
    [[nodiscard]] bool IsEmpty() const { return head_ == teal_; }

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

    //Destructor
    ~LinkedList();
};

template<typename T>
LinkedList<T>::LinkedList() {
    head_ = teal_ = new Node;
    head_->pNext = nullptr;
    teal_->pPrev = nullptr;

    begin_it_ = iterator(head_);
    end_it_ = iterator(teal_);
}

template<typename T>
LinkedList<T>::LinkedList(T *data, int length) : LinkedList() {
    if (length < 0)
        throw std::length_error("negative size");

    for (int i = 0; i < length; i++)
        push_back(data[i]);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    head_ = teal_ = new Node;
    head_->pNext = nullptr;
    teal_->pPrev = nullptr;

    begin_it_ = iterator(head_);
    end_it_ = iterator(teal_);

    for (iterator it = list.begin(); it != list.end(); ++it)
        this->push_back(*it);
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node *node_to_delete = head_;
    for (Node *next_node = head_; next_node != teal_;) {
        next_node = next_node->pNext;
        delete node_to_delete;
        node_to_delete = next_node;
    }
    delete node_to_delete;
}

template<typename T>
size_t LinkedList<T>::GetLength() const {

    int count = 0;
    for (Node *dn = head_; dn != teal_; dn = dn->pNext) ++count;

    return count;

}

template<typename T>
void LinkedList<T>::push_front(T node_val) {
    Node *node_to_add = new Node(node_val);
    node_to_add->pNext = head_;
    node_to_add->pPrev = nullptr;
    head_->pPrev = node_to_add;
    head_ = node_to_add;
    //так как head_ изменился, нужно изменить begin_it_
    begin_it_ = iterator(head_);
}

template<typename T>
void LinkedList<T>::push_back(T node_val) {
    if (IsEmpty())
        push_front(node_val);
    else {
        Node *node_to_add = new Node(node_val);
        node_to_add->pNext = teal_;
        node_to_add->pPrev = teal_->pPrev;
        teal_->pPrev->pNext = node_to_add;
        teal_->pPrev = node_to_add;
        //изменяем end_it_
        end_it_ = iterator(teal_);
    }

}

template<typename T>
bool LinkedList<T>::insert_after(T node_val, const LinkedList::iterator &key_i) {
    for (Node *dn = head_; dn != teal_; dn = dn->pNext) {
        //Найден ли узел для заданного итератора
        if (dn == key_i.node_) {
            Node *node_to_add = new Node(node_val);
            node_to_add->pPrev = dn;
            node_to_add->pNext = dn->pNext;
            dn->pNext->pPrev = node_to_add;
            dn->pNext = node_to_add;
            return true;
        }
    }
    return false;
}

template<typename T>
T LinkedList<T>::remove_front() {
    if (IsEmpty())
        throw std::out_of_range("tried to remove from an empty list");

    Node *node_to_remove = head_;
    T return_val = node_to_remove->data_;
    head_ = node_to_remove->pNext;
    head_->pPrev = 0;
    begin_it_ = iterator(head_);

    delete node_to_remove;
    return return_val;

}

template<typename T>
T LinkedList<T>::remove_back() {
    if (IsEmpty())
        throw std::out_of_range("tried to remove from an empty list");

    Node *node_to_remove = teal_->pPrev;

    if (node_to_remove->pPrev == 0) {
        return remove_front();
    } else {
        T return_val = node_to_remove->data_;
        node_to_remove->pPrev->pNext = teal_;
        teal_->pPrev = node_to_remove->pPrev;
        delete node_to_remove;
        return return_val;
    }
}

template<typename T>
bool LinkedList<T>::remove_it(LinkedList::iterator &key_i) {
    for (Node *dn = head_; dn != teal_; dn = dn->pNext) {
        //Найден ли узел для заданного итератора
        if (dn == key_i.the_node) {
            dn->pPrev->pNext = dn->pNext;
            dn->pNext->pPrev = dn->pPrev;
            delete dn;
            key_i.the_node = 0;
            return true;
        }
    }

    return false;
}

template<typename T>
LinkedList<T> *LinkedList<T>::GetSubList(int start_index, int end_index) const {
    return nullptr;
}