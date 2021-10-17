#pragma once

#include "../matrix/squareMatrix.h"
//#include <SFML/Graphics.hpp>
#include <cmath>
#include <utility>
#include <iostream>

#define NUM_OF_ROWS 3

class Graph {

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
};