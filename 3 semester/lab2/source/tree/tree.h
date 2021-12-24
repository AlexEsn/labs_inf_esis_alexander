#include <vector>

template<typename T>
struct TreeNode {
    T data_;
    std::vector<TreeNode<T> *> child_;
};

template<typename T>
TreeNode<T> *newNode(T data) {
    TreeNode<T> *temp = new TreeNode<T>;
    temp->data_ = data;
    return temp;
}