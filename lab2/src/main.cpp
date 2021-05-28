#include <SFML/Graphics.hpp>
#include "graph/graph.h"

#define WIDTH 900.f
#define HEIGHT 700.f

using namespace sf;
using namespace std;


int main() {

////////////////////////////////////////////////////////////////////////////////////////////////////////

    int menu, display_mode;
    cout << "Graph calculator" << endl;
    cout << "Select an action:" << endl;
    cout << "1. Union of graphs" << endl;
    cout << "2. Intersection of graphs" << endl;

    cin >> menu;

    cout << "Select the display mode: (display in rectangles is poorly optimized,"
            "it is recommended to use circles"
         << endl;
    cout << "1. In circles" << endl;
    cout << "2. In rectangles" << endl;


    cin >> display_mode;

    SquareMatrix<bool> matrix;
    Graph graph1(WIDTH, HEIGHT);
    Graph graph2(WIDTH, HEIGHT);
    Graph graph3(matrix, WIDTH, HEIGHT);


    switch (menu) {
        case 1:
            graph3.Union(graph1, graph2);
            break;
        case 2:
            graph3.Intersection(graph1, graph2);
            break;
        default:
            return -1;
    }


    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML", Style::Default, settings);

////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        switch (display_mode) {
            case 1: {
                graph1.drawInCircle(window, 1);
                graph2.drawInCircle(window, 2);
                graph3.drawInCircle(window, 3);
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

        window.display();
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}