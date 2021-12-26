#pragma once

#include "../matrix/squareMatrix.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

#define NUM_OF_ROWS 3

struct Edge {
    size_t src, dst;
};

class Graph {

public:
    std::vector<int> *adj_list;

    Graph(std::vector<Edge> const &edges, int N)
    {
        adj_list = new std::vector<int>[N];

        for (int i = 0; i < (int) edges.size(); ++i)
        {
            int src = edges[i].src;
            int dst = edges[i].dst;
            adj_list[src].push_back(dst);
            adj_list[dst].push_back(src);
        }
    }

private:
    SquareMatrix<bool> matrix_;
    float width_;
    float height_;

public:

    Graph(float width, float height);
    explicit Graph(const SquareMatrix<bool> &matrix, float width, float height);

    void drawInCircle(sf::RenderWindow &window,int position);
    void drawInRectangle(sf::RenderWindow &window, int position);

    void Addition(const Graph &graph);
    void Union(const Graph &graph1, const Graph &graph2);
    void Intersection(const Graph &graph1, const Graph &graph2);

    void BFS(sf::RenderWindow &window, int position);
    void DepthSearch(sf::RenderWindow &window, int position, size_t search);
};