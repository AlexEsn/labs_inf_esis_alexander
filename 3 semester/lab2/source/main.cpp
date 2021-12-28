#include "opencv2/imgproc/imgproc.hpp"                              //OpenCV
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>

using namespace cv;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>                                    //SFML

using namespace sf;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tree/TreeNodeVector.h"                                  //for decision tree

#ifdef DEBUG

#include "queue/queue.h"
#include "vector/vector.h"
#include "tree/sparse_matrix_BTree.h"

#else
#include <queue>                                                   //stl
#include <vector>

using namespace std;

#include <boost/numeric/ublas/matrix_sparse.hpp>                   //boost

namespace bst = boost::numeric::ublas;
#endif

#define TRUSTED_INTERVAL  5

double coefficient_threshold[] = {0.95, 0.9, 0.87, 0.94, 0.9, 0.95, 0.94, 0.95, 0.919, 0.925, 0.95, 0.94};  //coefficients for different colors

int main(int argc, char *argv[]) {

    Mat src_img, source_copy_img, result_img, templ_img;

#ifdef DEBUG
    int example_img = 1;
    int num_color_templ = 11;
    bool display_search = false;
    std::string img_path = "../../example/", templ_path = "../../template/";
#else
    if (argc < 4) {
        std::cout << "Not enough parameters" << std::endl;
        std::cout << "Usage:\n" << argv[0]
             << " <image_name_folder> <template_name_folder> <num_img> <num_of_template> <display_search (default: 0)>"
             << std::endl;
        return -1;
    }
    int example_img = stoi(argv[3]);
    int num_color_templ = stoi(argv[4]);
    bool display_search = false;
    if(argc == 6) display_search = stoi(argv[5]);
    std::string img_path = argv[1], templ_path = argv[2];
#endif

    vector<unsigned> figure_number;
    vector<vector<std::pair<double, double>>> figure(num_color_templ);
    vector<compressed_matrix<bool>> figure_compressed;

    for (int j = 0; j < num_color_templ; ++j) {
        src_img = imread(img_path + std::to_string(example_img) + ".jpg");
        templ_img = imread(templ_path + std::to_string(j) + ".jpg");

        src_img.copyTo(source_copy_img);
        matchTemplate(source_copy_img, templ_img, result_img, TM_CCOEFF_NORMED);
        threshold(result_img, result_img, coefficient_threshold[j] - 0.05, 1, THRESH_TOZERO);
        double minVal, maxVal;
        Point minLoc, maxLoc;

        while (true) {
            minMaxLoc(result_img, &minVal, &maxVal, &minLoc, &maxLoc);
            if (maxVal > coefficient_threshold[j]) {
#ifdef DEBUG
                printf("Matched %d %d\n", maxLoc.x, maxLoc.y);
#endif
                figure[j].push_back(std::make_pair((double) maxLoc.x, (double) maxLoc.y));
                rectangle(
                        src_img,
                        maxLoc,
                        Point(maxLoc.x + templ_img.cols, maxLoc.y + templ_img.rows),
                        CV_RGB(0, 255, 0), 10
                );
                floodFill(result_img, maxLoc, cv::Scalar(0), nullptr, cv::Scalar(.1), cv::Scalar(1.));
            } else {
#ifdef DEBUG
                printf("No Matched\n");
#endif
                break;
            }
            for (int i = 0; i < figure[j].size(); ++i) {
                for (int k = 1; k < figure[j].size() - i; ++k) {
                    if (figure[j][k - 1] > figure[j][k])
                        swap(figure[j][k], figure[j][k - 1]);
                }
            }
        }

        if (display_search) {
            imshow("debug_img" + std::to_string(example_img) + std::to_string(j), src_img);
            cv::waitKey(0);
        }
    }
    size_t field_size = 0;
    size_t figure_num = 0;
    for (int i = 0; i < num_color_templ; i++) {

        if (figure[i].empty() || (example_img % 2 != 0 && i == 6) || (example_img % 2 == 0 && i == 10)) continue;
        figure_num++;

        figure_number.push_back(i);

        double up_position = src_img.rows;
        for (int j = 0; j < figure[i].size(); j++)
            if (figure[i][j].second < up_position)
                up_position = figure[i][j].second;


        vector<vector<bool>> figure_matrix(figure[i].size());
        for (int j = 0; j < figure[i].size(); j++) {
            figure_matrix[j].resize(figure[i].size());
            for (int k = 0; k < figure[i].size(); ++k) {
                figure_matrix[j][k] = false;
            }
        }


        figure_matrix[round(abs((figure[i][0].second - up_position) / templ_img.rows))][0] = true;

#ifdef DEBUG
        std::cout << abs((up_position - figure[i][0].second) / templ_img.rows) << std::endl;
        std::cout << templ_img.cols << " " << templ_img.rows << std::endl;
#endif

        queue<std::pair<std::pair<double, double>, std::pair<int, int>>> figure_element;
        figure_element.push(std::make_pair(figure[i][0],
                                           std::make_pair(
                                                   round(abs((figure[i][0].second - up_position) / templ_img.rows)),
                                                   0)));
        figure[i][0] = std::make_pair(0, 0);
        while (!figure_element.empty()) {
            auto temp = figure_element.front();
            double x = temp.first.first;
            double y = temp.first.second;
            int m_i = temp.second.first;
            int m_j = temp.second.second;
            figure_element.pop();
            for (int k = 0; k < figure[i].size(); k++) {
                bool isUsing = false;
                if (figure[i][k].first - x - TRUSTED_INTERVAL <= templ_img.cols &&
                    abs(y - figure[i][k].second) < TRUSTED_INTERVAL) {
                    figure_matrix[m_i][m_j + 1] = true;
                    figure_element.push(std::make_pair(figure[i][k], std::make_pair(m_i, m_j + 1)));
                    isUsing = true;
                }
                if (x - figure[i][k].first >= 0 && x - figure[i][k].first <= templ_img.cols &&
                    abs(y - figure[i][k].second) < TRUSTED_INTERVAL) {
                    figure_matrix[m_i][m_j - 1] = true;
                    figure_element.push(std::make_pair(figure[i][k], std::make_pair(m_i, m_j - 1)));
                    isUsing = true;
                }
                if (figure[i][k].second - y - TRUSTED_INTERVAL <= templ_img.rows &&
                    figure[i][k].second - y - TRUSTED_INTERVAL > 0 &&
                    abs(x - figure[i][k].first) < 10) {
                    figure_matrix[m_i + 1][m_j] = true;
                    figure_element.push(std::make_pair(figure[i][k], std::make_pair(m_i + 1, m_j)));
                    isUsing = true;
                }
                if (y - figure[i][k].second - TRUSTED_INTERVAL <= templ_img.rows && y - figure[i][k].second > 0 &&
                    abs(x - figure[i][k].first) < 10) {
                    figure_matrix[m_i - 1][m_j] = true;
                    figure_element.push(std::make_pair(figure[i][k], std::make_pair(m_i - 1, m_j)));
                    isUsing = true;
                }
                if (isUsing) figure[i][k] = std::make_pair(0, 0);
            }
        }
        figure_compressed.resize(figure_num);
        figure_compressed[figure_num - 1].resize(figure_matrix[0].size(), figure_matrix[0].size(), false);
        for (int j = 0; j < figure_matrix[0].size(); j++) {
            for (int k = 0; k < figure_matrix[0].size(); ++k) {
                if (figure_matrix[j][k]) {
                    figure_compressed[figure_num - 1].push_back(j, k, true);
                    field_size++;
                }
            }
        }


#ifdef DEBUG
        for (size_t j = 0; j < figure_matrix[0].size(); j++) {
            for (size_t k = 0; k < figure_matrix[0].size(); ++k) {
                std::cout << figure_matrix[j][k] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        for (size_t i = 0; i < figure_compressed[figure_num - 1].size1(); ++i) {
            for (size_t j = 0; j < figure_compressed[figure_num - 1].size2(); ++j)
                std::cout << figure_compressed[figure_num - 1](i, j) << ' ';
            std::cout << std::endl;
        }
        std::cout << std::endl;
#endif
    }

    vector<vector<compressed_matrix<int>>> all_figures(figure_num);
    for (int i = 0; i < figure_num; ++i) {
        for (int right_shift = 0; right_shift < sqrt(field_size); right_shift++) {
            for (int down_shift = 0; down_shift < sqrt(field_size); down_shift++) {
                compressed_matrix<int> all_figure(sqrt(field_size), sqrt(field_size));
                for (int j = 0; j < sqrt(field_size); ++j) {
                    for (int k = 0; k < sqrt(field_size); ++k) {
                        if (k + right_shift < sqrt(field_size) && j + down_shift < sqrt(field_size)) {
                            if (figure_compressed[i](j, k)) {
                                all_figure.push_back(j + down_shift, k + right_shift, 1);
                            }
                        }
                    }
                }
                if (all_figure.nnz() < figure_compressed[i].nnz()) break;
                all_figures[i].push_back(all_figure);
            }

        }
    }

#ifdef DEBUG
    for (int i = 0; i < all_figures[0].size(); ++i) {
        for (int j = 0; j < all_figures[0][i].size1(); ++j) {
            for (int k = 0; k < all_figures[0][i].size2(); ++k) {
                std::cout << all_figures[0][i](j, k) << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif

    compressed_matrix<int> root_zero_matrix(sqrt(field_size), sqrt(field_size));
    TreeNodeVector<compressed_matrix<int>> *decision_tree = newNode(root_zero_matrix);
    vector<compressed_matrix<int>> result;
    for (int i = 0; i < figure_num; i++) {
        queue<std::pair<TreeNodeVector<compressed_matrix<int>> *, compressed_matrix<int>>> queue_decision_tree;
        queue_decision_tree.push(std::make_pair(decision_tree, decision_tree->data_));
        while (!queue_decision_tree.empty()) {
            int n = queue_decision_tree.size();

            while (n > 0) {
                auto p = queue_decision_tree.front();
                queue_decision_tree.pop();
                for (int j = 0; j < p.first->child_.size(); j++) {
                    queue_decision_tree.push(std::make_pair(p.first->child_[j], p.second + p.first->child_[j]->data_));
                }

                if (p.first->child_.empty()) {
                    for (int j = 0; j < all_figures[i].size(); ++j) {
                        compressed_matrix<int> temp = p.second + all_figures[i][j];
                        if (temp.nnz() == p.second.nnz() + all_figures[i][j].nnz())
                            p.first->child_.push_back(newNode(temp));
                    }
                }

                n--;
            }
        }
    }


    queue<std::pair<TreeNodeVector<compressed_matrix<int>> *, compressed_matrix<int>>> queue_decision_tree;
    queue_decision_tree.push(std::make_pair(decision_tree, decision_tree->data_));
    while (!queue_decision_tree.empty()) {
        int n = queue_decision_tree.size();

        while (n > 0) {
            auto p = queue_decision_tree.front();
            if (p.second.nnz() == field_size)
                result.push_back(p.second);
            queue_decision_tree.pop();
            for (int i = 0; i < p.first->child_.size(); i++) {
                compressed_matrix<int> temp = p.second + p.first->child_[i]->data_;
                for (int i = 0; i < temp.size1(); ++i) {
                    for (int j = 0; j < temp.size2(); ++j) {
#ifdef DEBUG
                        printf("%2d ", static_cast<int>(temp(i, j)));
#endif
                    }
#ifdef DEBUG
                    std::cout << std::endl;
#endif
                }
#ifdef DEBUG
                std::cout << std::endl;
#endif
                queue_decision_tree.push(std::make_pair(p.first->child_[i], temp));

            }
            n--;
        }
    }

    for (int i = 0; i < figure_number.size() / 2; ++i)
        swap(figure_number[i], figure_number[figure_number.size() - i - 1]);


    for (int i = 0; i < result.size(); ++i) {
        RenderWindow window(VideoMode(800, 800), "SFML draw result" + std::to_string(i));
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
            }
            window.clear(Color::White);

            for (int j = 0; j < result[i].size1(); ++j) {
                for (int k = 0; k < result[i].size2(); ++k) {
                    Texture rect_t;
                    int color = 0, count = result[i](k, j);
                    while (count > 1) {
                        color++;
                        count = count >> 1;
                    }
                    rect_t.loadFromFile(templ_path + std::to_string(figure_number[color]) + ".jpg");
                    Sprite rect;
                    rect.setTexture(rect_t);
                    rect.setPosition(55 * j, 55 * k);
                    window.draw(rect);
                }
            }
            window.display();
        }
    }
    return 0;
}