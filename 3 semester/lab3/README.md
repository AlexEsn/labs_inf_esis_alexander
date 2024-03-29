# Лабораторная работа №3

## **По курсу «Языки программирования и методы программирования»**

_Цель: написать программу на C++, реализующую алгоритмы (поиска) на графах_

Для реализации были выбраны:

- Задача о рюкзаке
- Неориентированный граф
- Поиск кратчайших путей
- Поиск остова графа

## Задача о рюкзаке

В задаче было построено дерево решений, для этого использовалось n-арное дерево решений(исходники ```lab3/source/tree/TreeNodeVector.h```). Программа может работать, как с STL и Boost, а также и на реализованных ранее контейнерах, для работы с STL надо выбрать флаг ```-DDEBUG```. Также с этим флагом можно увидеть процесс подбора. Был реализован графический вывод с библиотекой SFML и OpenCV.

## Неориентированный граф

Граф написан с использование матрицы смежности. Матрица в свою очередь используется самописная на собственном векторе. На данном графе реализован поиск кратчайшего пути алгоритмом Дейкстры ($O(N^2)$) и поиск остова алгоритмом Краскалы ($O(M* log_2(N) + N^2)$).

## Тесты

Были написаны тесты с полным покрытием граничных и некорректных значений. В качестве платформы используется Google Test. Можно включить все тесты при компиляции с cmake параметром ```ctest```.