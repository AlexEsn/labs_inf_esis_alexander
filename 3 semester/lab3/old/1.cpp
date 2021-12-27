#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/core/core.hpp>

#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {

    Mat frame, f1, f2, head;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 6; j <= 6; ++j) {
            frame = imread("example/" + to_string(i) + ".jpg");
            head = imread("template/" + to_string(j) + ".jpg");

            int method = TM_CCOEFF_NORMED;
            float threshold = 0.9;
            frame.copyTo(f1);
            matchTemplate(f1, head, f2, method);
            cv::threshold(f2, f2, threshold - .05, 1, THRESH_TOZERO);
            double minVal, maxVal;
            cv::Point minLoc, maxLoc;

            while (true) {
                minMaxLoc(f2, &minVal, &maxVal, &minLoc, &maxLoc);
                if (maxVal > threshold) {
                    printf("Matched %d %d\n", minLoc.x, minLoc.y);
                    rectangle(
                            frame,
                            maxLoc,
                            cv::Point(maxLoc.x + head.cols, maxLoc.y + head.rows),
                            CV_RGB(0, 255, 0), 10
                    );
                    floodFill(f2, maxLoc, cv::Scalar(0), nullptr, cv::Scalar(.1), cv::Scalar(1.));
                } else {
                    printf("No More Matches");
                    break;
                }
            }

            cv::imshow("debug_img" + to_string(i) + to_string(j), frame);
        }
    }

    waitKey(0);

    return 0;
}