#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <utility>
#include "../matrix/squareMatrix.h"
#include "../queue/queue.h"
#include "../stack/stack.h"

#define NUM_OF_ROWS 3

struct Edge {
    size_t src, dst, weight;
};

class Graph {

private:
    SquareMatrix<bool> matrix_;
    float width_;
    float height_;

public:

    Graph(float width, float height);

    explicit Graph(const SquareMatrix<bool> &matrix, float width, float height);
    void drawInCircle(sf::RenderWindow &window, int position);
    void drawInRectangle(sf::RenderWindow &window, int position);

    void Addition(const Graph &graph);
    void Union(const Graph &graph1, const Graph &graph2);
    void Intersection(const Graph &graph1, const Graph &graph2);

    void BFS(sf::RenderWindow &window, int position);
    void DepthSearch(sf::RenderWindow &window, int position, size_t search);
    void SearchOstov(sf::RenderWindow &window, int position, int num_vertex);
};

#include "graph.tpp"