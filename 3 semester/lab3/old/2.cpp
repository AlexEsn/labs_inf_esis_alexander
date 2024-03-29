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

bool use_mask;
Mat img, templ, mask, result;
const char *image_window = "Source Image";
const char *result_window = "Result window";
int match_method = TM_SQDIFF_NORMED;

int main(int argc, char **argv) {
//    if (argc < 3) {
//        cout << "Not enough parameters" << endl;
//        cout << "Usage:\n" << argv[0] << " <image_name> <template_name> [<mask_name>]" << endl;
//        return -1;
//    }
//    img = imread(argv[1], IMREAD_COLOR);
//    templ = imread(argv[2], IMREAD_COLOR);
    img = imread("example/1.jpg", IMREAD_COLOR);
    templ = imread("template/5.jpg", IMREAD_COLOR);
    if (argc > 3) {
        use_mask = true;
        mask = imread(argv[3], IMREAD_COLOR);
    }
    if (img.empty() || templ.empty() || (use_mask && mask.empty())) {
        cout << "Can't read one of the images" << endl;
        return EXIT_FAILURE;
    }
//    const char *trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
//    createTrackbar(trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod);

    Mat img_display;
    img.copyTo(img_display);

    int result_cols = img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;

    result.create(result_rows, result_cols, CV_32FC1);

    bool method_accepts_mask = (TM_SQDIFF == match_method || match_method == TM_CCORR_NORMED);

    if (use_mask && method_accepts_mask) { matchTemplate(img, templ, result, match_method, mask); }
    else { matchTemplate(img, templ, result, match_method); }
    normalize(result, result, 0, 1, NORM_MINMAX, -1);

    double minVal, maxVal;
    Point minLoc, maxLoc, matchLoc;

    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    double min_thresh = (minVal + 1e-6) * 1.5;
    printf("%.20lf\n", min_thresh);

    for(int k=1;k<=5;k++)
    {
        minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
        result.at<float>(minLoc.x,minLoc.y)=1.0;
        result.at<float>(maxLoc.x,maxLoc.y)=0.0;

        /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
        if( match_method  == TM_SQDIFF || match_method == TM_SQDIFF_NORMED )
        { matchLoc = minLoc; }
        else
        { matchLoc = maxLoc; }

        /// Show me what you got
        rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
        rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
    }

    imshow(image_window, img_display);
    waitKey(0);
    return EXIT_SUCCESS;
}