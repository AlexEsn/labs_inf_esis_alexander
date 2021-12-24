#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>
#include <string>
#include "queue/queue.h"

#define WIDTH 800.f
#define HEIGHT 800.f
#define RADIUS 20.f
#define FONT_SIZE 20.f

using namespace sf;


RenderWindow window;

template<typename T>
struct Node {
private:
    T data_;
    Node *right_;
    Node *left_;

public:
    Node() : right_(nullptr), left_(nullptr) {};
    explicit Node(T value) : right_(nullptr), left_(nullptr), data_(value) {};

    ~Node(){
        Node *node_to_delete = this; //TODO
    }

public:

    void TraverseDFSRootLeftRight(Node *node) {
        if (node == nullptr) return;
        std::cout << "->" << node->data_;
        TraverseDFSRootLeftRight(node->left_);
        TraverseDFSRootLeftRight(node->right_);
    }
    void TraverseDFSRootRightLeft(Node *node) {
        if (node == nullptr) return;
        std::cout << "->" << node->data_;
        TraverseDFSRootRightLeft(node->right_);
        TraverseDFSRootRightLeft(node->left_);
    }
    void TraverseDFSLeftRightRoot(Node *node) {
        if (node == nullptr) return;
        TraverseDFSLeftRightRoot(node->left_);
        TraverseDFSLeftRightRoot(node->right_);
        std::cout << "->" << node->data_;
    }
    void TraverseDFSLeftRootRight(Node *node) {
        if (node == nullptr) return;
        TraverseDFSLeftRootRight(node->left_);
        std::cout << "->" << node->data_;
        TraverseDFSLeftRootRight(node->right_);
    }
    void TraverseDFSRightLeftRoot(Node *node) {
        if (node == nullptr) return;
        TraverseDFSLeftRightRoot(node->right_);
        TraverseDFSLeftRightRoot(node->left_);
        std::cout << "->" << node->data_;
    }
    void TraverseDFSRightRootLeft(Node *node) {
        if (node == nullptr) return;
        TraverseDFSLeftRootRight(node->right_);
        std::cout << "->" << node->data_;
        TraverseDFSLeftRootRight(node->left_);
    }

    size_t Count(Node *node) {
        if (node == nullptr) return 0;
        return Count(node->right_) + Count(node->left_) + 1;
    }
    size_t Deep(Node *node, T value) {
        if (node == nullptr)
            throw std::out_of_range("value do not found");
        if (node->data_ == value)
            return 0;
        if (value < node->data_)
            return Deep(node->left_, value) + 1;
        else
            return Deep(node->right_, value) + 1;
    }
    Node *Find(Node *node, T value) {
        if (node == nullptr) return nullptr;
        if (value < node->data_)
            return Find(node->left_, value);
        else
            return Find(node->right_, value);
    }
    bool Insert(Node *&node, T value) {
        if (node == nullptr) {
            node = new Node(value);
            return true;
        }
        if (node->data_ < value)
            Insert(node->right_, value);
        else if (node->data_ == value) {
            return false;
        } else
            Insert(node->left_, value);
    }
    void ShowBFS(Node *node, Color color) {

        Font font;
        if (!font.loadFromFile("arial.ttf")) throw std::invalid_argument("No font");

        queue<std::pair<Node<T> *, std::pair<float, float>>> queue;
        queue.push(make_pair(node, std::make_pair(WIDTH / 2, HEIGHT / 10)));

        float k = 1;

        while (!queue.empty()) {

            Node<T> *tmp = queue.front().first;

            float x = queue.front().second.first;
            float y = queue.front().second.second;

            CircleShape vertex;
            vertex.setRadius(RADIUS);
            vertex.setOrigin(vertex.getRadius(), vertex.getRadius());
            vertex.setFillColor(color);
            vertex.setPosition(x, y);

            Text text(std::to_string(tmp->data_), font, vertex.getRadius());
            text.setFillColor(Color::Red);
            FloatRect bounds = text.getLocalBounds();
            text.setOrigin(bounds.left + bounds.width / 2.0f,
                           bounds.top + bounds.height / 2.0f);
            text.setPosition(vertex.getPosition().x, vertex.getPosition().y);

            if (tmp->left_ != nullptr) {

                float new_x = x - 6 * RADIUS + RADIUS * tmp->Deep(node, tmp->data_) * 1.2f;
                float new_y = y + 3 * RADIUS;

                queue.push(make_pair(tmp->left_, std::make_pair(new_x, new_y)));

                VertexArray line(Lines, 2);
                line[0].position = Vector2f(x, y);
                line[1].position = Vector2f(new_x, new_y);
                window.draw(line);

            }
            if (tmp->right_ != nullptr) {

                float new_x = x + 6 * RADIUS - RADIUS * tmp->Deep(node, tmp->data_) * 1.2f;
                float new_y = y + 3 * RADIUS;

                queue.push(make_pair(tmp->right_, std::make_pair(new_x, new_y)));

                VertexArray line(Lines, 2);
                line[0].position = Vector2f(x, y);
                line[1].position = Vector2f(new_x, new_y);
                window.draw(line);
            }
            queue.pop();
            window.draw(vertex);
            window.draw(text);

        }
    }
    bool Delete(Node *&node, int value) {
        if (node == nullptr) return false;
        if (node->data_ == value) {
            DeleteNode(node);
            return true;
        }
        return Delete(node->data_ < value ? node->right_ : node->left_, value);
    }
    void DeleteNode(Node *&node) {
        if (node->left_ == nullptr && node->right_ == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left_ == nullptr) {
            Node *right = node->right_;
            delete node;
            node = right;
        } else if (node->right_ == nullptr) {
            Node *left = node->left_;
            delete node;
            node = left;
        } else {
            Node *minParent = node;
            Node *min = node->right_;
            while (min->left_ != nullptr){
                minParent = min;
                min = min->left_;
            }
            node->data_ = min->data_;
            (minParent->left_ == min ? minParent->left_ : minParent->right_) = min->right_;
            delete min;
        }
    }

};

template<typename T>
struct BTree {

public:
    friend struct Node<T>;
    Node<T> *root_;
    size_t num_vertex_ = 0;

public:
    BTree() : root_(new Node<T>) {};
    explicit BTree(T value) : root_(new Node<T>(value)) {};


    bool Add(T value) {
        if (root_ == nullptr) root_ = new Node<T>(value);
        bool isNewVertexAdd = root_->Insert(root_, value);
        if (isNewVertexAdd) num_vertex_++;
        return isNewVertexAdd;
    }
    void Print(Color color) {
        root_->ShowBFS(root_, color);
    }
    bool Remove(T value) {
        bool isVertexRemove = root_->Delete(root_, value);
        if (isVertexRemove) num_vertex_--;
        return isVertexRemove;
    }
    [[nodiscard]] size_t Size() const {
        return num_vertex_;
    }
    bool Contains(T value){
        if(root_->Find(root_, value) != nullptr) return true;
        else return false;
    }
    void Balance(){

    }
    void Traverse() {
        root_->TraverseDFSRootLeftRight(root_);
    }
    void Traverse(const std::string& route){
        if(route == "KLP") root_->TraverseDFSRootLeftRight(root_);
        else if(route == "KPL") root_->TraverseDFSRootRightLeft(root_);
        else if(route == "LPK") root_->TraverseDFSLeftRightRoot(root_);
        else if(route == "LKP") root_->TraverseDFSLeftRootRight(root_);
        else if(route == "PLK") root_->TraverseDFSRightLeftRoot(root_);
        else if(route == "PKL") root_->TraverseDFSRightRootLeft(root_);
        else throw std::logic_error("The string does not meet the condition");
    }

    ~BTree(){
        delete root_;
    }
};

void print() {
    BTree<int> Tree(50);
    for (int i = 0; i < 20; ++i) {
        window.clear(Color::Black);
        Tree.Add(rand() % 100);
        Tree.Print(Color::White);
        window.display();
        sleep(milliseconds(800));
    }
}

void draw() {
    print();
    while (window.isOpen()) {
    }
}

int main() {

    srand(time(nullptr));

    BTree<int> Tree(8);
    Tree.Add(3);
    Tree.Add(1);
    Tree.Add(6);
    Tree.Add(4);
    Tree.Add(7);
    Tree.Add(10);
    Tree.Add(14);
    Tree.Add(13);
//    Tree.Remove(8);
    Tree.root_->TraverseDFSLeftRootRight(Tree.root_);

    window.create(VideoMode(WIDTH, HEIGHT), "SFML");

//    Thread thread(&draw);
//    thread.launch();

    window.clear();
    Tree.Print(Color::White);
    window.display();

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        sleep(milliseconds(1));
    }

    return 0;
}