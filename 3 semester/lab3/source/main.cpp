#include <SFML/Graphics.hpp>
#include "graph/graph.h"
#include <iostream>

#define WIDTH 900.f
#define HEIGHT 700.f

using namespace sf;
using namespace std;


int main() {

////////////////////////////////////////////////////////////////////////////////////////////////////////

    int menu, display_mode;
    cout << "Graph calculator" << endl;
    cout << "Select mode:" << endl;
    cout << "1. Working with one graph" << endl;
    cout << "2. Working with two graphs" << endl;

    cin >> menu;

    SquareMatrix<bool> matrix;
    Graph graph1(WIDTH, HEIGHT);
    Graph graph2(matrix, WIDTH, HEIGHT);
    Graph graph3(matrix, WIDTH, HEIGHT);

    switch (menu) {
        case 1:
            break;
        case 2: {

            Graph temp(WIDTH, HEIGHT);

            cout << "1. Union of graphs" << endl;
            cout << "2. Intersection of graphs" << endl;

            int operation;
            cin >> operation;

            switch (operation) {
                case 1:
                    graph3.Union(graph1, temp);
                    break;
                case 2:
                    graph3.Intersection(graph1, temp);
                    break;
                default:
                    return -1;
            }
            graph2 = temp;
        }
            break;

        default:
            return -1;
    }

    cout << "Select the display mode: (display in rectangles is poorly optimized,"
            "it is recommended to use circles"
         << endl;
    cout << "1. In circles" << endl;
    cout << "2. In rectangles" << endl;

    cin >> display_mode;

    ContextSettings settings;
    settings.antialiasingLevel = 8;

    int N = 6;
    std::vector<Edge> edges =
            {
                    {0, 1},
                    {0, 4},
                    {0, 5},
                    {4, 5},
                    {1, 4},
                    {1, 3},
                    {2, 3},
                    {2, 4}
            };

    //create graph from edge list
    Graph g(edges, N);

    int K = 3; // number of colors

    std::vector<int> color(N, 0);

    cout << "all k-colorable configurations of the graph" << endl;
    cout << "for k = " << K << ":" << endl;
    kColorable(g, color, K, 0, N);

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML", Style::Default, settings);

////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        switch (menu) {
            case 1: {
                graph1.drawInCircle(window, 1);
                graph1.DepthSearch(window, 2, 4);
            }
                break;
            case 2: {
                switch (display_mode) {
                    case 1: {
                        graph2.drawInCircle(window, 2);
                        graph3.drawInCircle(window, 4);
                    }
                        break;
                    case 2: {
                        graph1.drawInRectangle(window, 1);
                        graph2.drawInRectangle(window, 2);
                        graph3.drawInRectangle(window, 3);
                    }
                        break;;
                    default:
                        return -1;

                }
            }
                break;
        }

        window.display();
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}