#include "sort/sort.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800


using namespace sf;
using namespace std;

bool comp(int &left, int &right) {
    return left < right;
}

bool struct_data;
Sequence<int> *list = new ListSequence<int>;
Sequence<int> *arr = new ArraySequence<int>;

void Bubble() {
    if (struct_data == 0)
        BubbleSort(*arr, comp);
    else
        BubbleSort(*list, comp);
}

void Select() {
    if (struct_data == 0)
        SelectionSort(*arr, comp);
    else
        SelectionSort(*list, comp);
}

void Insert() {
    if (struct_data == 0)
        InsertionSort(*arr, comp);
    else
        InsertionSort(*list, comp);
}

void Shake() {
    if (struct_data == 0)
        ShakerSort(*arr, comp);
    else
        ShakerSort(*list, comp);
}

void Quick() {
    if (struct_data == 0)
        QuickSort(*arr, comp, 0, arr->GetLength() - 1);
    else
        QuickSort(*list, comp, 0, list->GetLength() - 1);
}

void Merge() {
    if (struct_data == 0)
        MergeSort(*arr, comp, 0, arr->GetLength() - 1);
    else
        MergeSort(*list, comp, 0, list->GetLength() - 1);
}

int main() {

    cout << "Use 0) Array or 1) List?" << endl;
    cin >> struct_data;

    char menu;
    cout << "Use random data?(Y/n)" << endl;
    cin >> menu;
    while (menu != 'Y' && menu != 'y' && menu != 'N' && menu != 'n') {
        cout << "Try again" << endl;
        cin >> menu;
    }

    size_t max_number = 100;
    size_t max_quantity = 1000;

    if (menu == 'Y' || menu == 'y') {
        srand(time(nullptr));
        cout << "How many numbers?" << endl;
        cin >> max_quantity;
        cout << "What is the maximum element?" << endl;
        cin >> max_number;
        for (int i = 0; i < max_quantity; ++i) {
            if (struct_data == 0) arr->Append(random() % max_number + 1);
            else list->Append(random() % max_number + 1);
        }
    } else if (menu == 'N' || menu == 'n') {
        int temp;
        for (char *format = "%d"; scanf(format, &temp) == 1; format = "%*[ ]%d") {
            if (temp > max_number)
                max_number = temp;
            if (struct_data == 0) arr->Append(temp);
            else list->Append(temp);
        }
    }

    cout << "How sort?\n" << "1\tQuickSort\n"
                             "2\tMergeSort\n"
                             "3\tBubbleSort\n"
                             "4\tShakerSort\n"
                             "5\tInsertionSort\n"
                             "6\tSelectionSort" << endl;
    int sort_type;
    cin >> sort_type;

    Thread sorting(&Quick);
    sorting.launch();

    switch (sort_type) {
        case 1: {

            Thread sorting(&Quick);
            sorting.launch();
        }
            break;
        case 2: {
            Thread sorting(&Merge);
            sorting.launch();
        }
            break;
        case 3: {
            Thread sorting(&Bubble);
            sorting.launch();
        }
            break;
        case 4: {
            Thread sorting(&Shake);
            sorting.launch();
        }
            break;
        case 5: {
            Thread sorting(&Insert);
            sorting.launch();
        }
            break;
        case 6: {
            Thread sorting(&Select);
            sorting.launch();
        }
            break;
        default:
            return -1;
    }

    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "lab1");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color::White);

        if (struct_data == 0) {
            for (int i = 0; i < arr->GetLength(); ++i) {
                RectangleShape rectangle(Vector2f((float) SCREEN_WIDTH / (float) arr->GetLength() -
                                                  (float) SCREEN_WIDTH / (float) arr->GetLength() / 5.f,
                                                  (float) SCREEN_HEIGHT / (float) max_number *
                                                  (float) ((*arr)[i])));
                rectangle.move((float) SCREEN_WIDTH / (float) arr->GetLength() * (float) i,
                               (float) SCREEN_HEIGHT -
                               (float) SCREEN_HEIGHT / (float) max_number * (float) ((*arr)[i]));
                rectangle.setFillColor(Color::Black);
                window.draw(rectangle);
            }
        } else {
            for (int i = 0; i < list->GetLength(); ++i) {
                RectangleShape rectangle(Vector2f((float) SCREEN_WIDTH / (float) list->GetLength() -
                                                  (float) SCREEN_WIDTH / (float) list->GetLength() / 5.f,
                                                  (float) SCREEN_HEIGHT / (float) max_number *
                                                  (float) ((*list)[i])));
                rectangle.move((float) SCREEN_WIDTH / (float) list->GetLength() * (float) i,
                               (float) SCREEN_HEIGHT -
                               (float) SCREEN_HEIGHT / (float) max_number * (float) ((*list)[i]));
                rectangle.setFillColor(Color::Black);
                window.draw(rectangle);
            }
        }

        window.display();
    }

    return 0;
}