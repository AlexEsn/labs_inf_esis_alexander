#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <typename T>
class LinkedList
{

private:
    class Node
    {
    public:
        T data;
        Node *pNext;
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node *_head;
    int _length;

public:
    //Constructors
    LinkedList();
    LinkedList(T* data, int count);
    LinkedList(const LinkedList <T>& list);

    //Decomposition
    T& front() const;
    T& back() const;
    void pop_front();
    void pop_back();
    void clear();
    LinkedList<T>* GetSubList (int start_index, int end_index) const;
    int GetLength () const;

    //Operations
    void push_front(const T& data);
    void push_back(const T& data);
    void InsertAt(const T& data, int index); //an iterator would be needed here
    LinkedList<T>* Concat(LinkedList<T> *list) const;


    //Destructor
    ~LinkedList();
};

#endif // LINKEDLIST_H
