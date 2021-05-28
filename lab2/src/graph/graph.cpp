#include "graph.h"

Graph::Graph(float width, float height) {
    width_ = width;
    height_ = height;
    std::cout << "Enter size (only one number at least 3) and adjacency matrix:" << std::endl;
    std::cin >> matrix_;
    if (matrix_.GetSize() < 3) exit(-1);
}

Graph::Graph(const SquareMatrix<bool> &matrix, float width, float height) {
    width_ = width;
    height_ = height;
    matrix_ = matrix;
}

void Graph::drawInCircle(sf::RenderWindow &window, int position) {

    std::pair<float, float> center(0, height_ / 2);
    if (position == 1) center.first = width_ / 6;
    else if (position == 2) center.first = width_ / 6 + width_ / 3;
    else if (position == 3) center.first = width_ / 6 + 2 * width_ / 3;
    else if (position == 0) center.first = width_ / 2;
    else throw std::out_of_range("Error position");

    float radius = std::min(width_ / (2.0), height_ / (2.0)) * 0.8;
    if (position != 0) radius = std::min(width_ / (2.0 * 3), height_ / (2.0 * 3)) * 0.8;

//        sf::CircleShape shape(radius);
//        shape.setFillColor(WHITE);
//        shape.setPosition(center.first - radius, center.second - radius);
//        window.draw(shape);

    float vertex_raduis = ((2 * M_PI * radius) / matrix_.GetSize()) * 0.15;

    float angle = -M_PI / 2.0;
    float delta = 2 * M_PI / matrix_.GetSize();

    vector<std::pair<float, float>> points;
    for (int i = 0; i < matrix_.GetSize(); i++) {
        float x = (radius * cos(angle)) + center.first;
        float y = (radius * sin(angle)) + center.second;
        points.push_back(std::make_pair(x, y));
        angle += delta;
    }

    for (int i = 0; i < matrix_.GetSize(); i++) {
        for (int j = 0; j < matrix_.GetSize(); j++) {
            if (!matrix_[i][j]) continue;
            int from = i;
            int to = j;
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(points[from].first, points[from].second), sf::Color::Red),
                    sf::Vertex(sf::Vector2f(points[to].first, points[to].second), sf::Color::Red)
            };
            window.draw(line, 2, sf::Lines);
        }
    }

    sf::Font font;
    font.loadFromFile("../../font/arial.ttf");
    sf::Text text("", font,18);

    for (int i = 0; i < points.size(); ++i) {
        sf::CircleShape shapes(vertex_raduis);
        shapes.setFillColor(sf::Color::White);
        shapes.setPosition(points[i].first - vertex_raduis, points[i].second - vertex_raduis);
        window.draw(shapes);
        text.setFillColor(sf::Color::Red);
        text.setString(std::to_string(i + 1));
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.0f,bounds.top + bounds.height / 2.0f);
        text.setPosition(points[i].first, points[i].second);
        window.draw(text);
    }
}

void Graph::drawInRectangle(sf::RenderWindow &window, int position) {

    std::pair<float, float> center(0, height_ / 2);
    if (position == 1) center.first = width_ / 6;
    else if (position == 2) center.first = width_ / 6 + width_ / 3;
    else if (position == 3) center.first = width_ / 6 + 2 * width_ / 3;
    else if (position == 0) center.first = width_ / 2;
    else throw std::out_of_range("Error position");

    float k = 1.1;
    float width = width_ / (3 * k);
    float height = height_ / k;


//        sf::RectangleShape rectangle(sf::Vector2f(width, height));
//        rectangle.setFillColor(RED);
//        rectangle.setPosition(center.first - width/2, center.second - height/2);
//        window.draw(rectangle);

    float radius = 10;
    vector<std::pair<float, float>> points;
    int N = matrix_.GetSize();
    float x = center.first - width / 2 + radius;
    float y = center.second - height / 3;
    for (int i = 0; i < NUM_OF_ROWS - 1; i++) {
        x = center.first - width / 2 + radius;
        for (int j = 0; j < N / NUM_OF_ROWS; ++j) {
            points.push_back(std::make_pair(x, y + i * height / 3));
            x += (width - 2 * N / NUM_OF_ROWS * radius) / (N / NUM_OF_ROWS - 1);
        }
    }

    x = center.first - width / 2 + radius;
    N = N - 2 * N / NUM_OF_ROWS;
    for (int i = 0; i < N; i++) {
        points.push_back(std::make_pair(x, center.second + height / 3));
        x += (width - 2 * N * radius) / (N - 1);

    }

    for (int i = 0; i < matrix_.GetSize(); i++) {
        for (int j = 0; j < matrix_.GetSize(); j++) {
            if (matrix_[i][j] == 0) continue;
            int from = i;
            int to = j;
            sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(points[from].first, points[from].second), sf::Color::White),
                    sf::Vertex(sf::Vector2f(points[to].first, points[to].second), sf::Color::White)
            };
            window.draw(line, 2, sf::Lines);
        }
    }

    sf::Font font;//шрифт
    font.loadFromFile("font/arial.ttf");
    sf::Text text("", font,
                  18);

    for (int i = 0; i < points.size(); ++i) {
        sf::CircleShape shapes(radius);
        shapes.setFillColor(sf::Color::White);
        shapes.setPosition(points[i].first - radius, points[i].second - radius);
        window.draw(shapes);
        text.setFillColor(sf::Color::Red);
        text.setString(std::to_string(i + 1));
        text.setPosition(points[i].first - radius / 2, points[i].second - radius);
        window.draw(text);
    }
}

void Graph::Addition(const Graph &graph) {
    for (int i = 0; i < graph.matrix_.GetSize(); i++)
        for (int j = 0; j < graph.matrix_.GetSize(); j++) {
            matrix_[i][j] = !matrix_[i][j];
        }
}

void Graph::Union(const Graph &graph1, const Graph &graph2) {

    int size = std::min(graph1.matrix_.GetSize(), graph2.matrix_.GetSize());

    if (graph1.matrix_.GetSize() > graph2.matrix_.GetSize()) matrix_ = graph1.matrix_;
    else matrix_ = graph2.matrix_;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            matrix_[i][j] += graph1.matrix_.At(i, j) + graph2.matrix_.At(i, j);
        }
}

void Graph::Intersection(const Graph &graph1, const Graph &graph2) {

    int min_size = std::min(graph1.matrix_.GetSize(), graph2.matrix_.GetSize());

    matrix_.Reset(min_size, min_size);

    for (int i = 0; i < min_size; i++)
        for (int j = 0; j < min_size; j++) {
            matrix_[i][j] = graph1.matrix_.At(i, j) * graph2.matrix_.At(i, j);
        }
}