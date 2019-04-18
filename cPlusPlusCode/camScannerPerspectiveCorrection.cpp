#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/calib3d.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Read the book image
    Mat book = imread("../assets/book.jpg");

    vector<Point2f> pts_book, pts_correct;

    //four corners of the book in the image
    pts_book.push_back(Point2f(1456, 1580));
    pts_book.push_back(Point2f(2237, 2048));
    pts_book.push_back(Point2f(1417, 3668));
    pts_book.push_back(Point2f(604, 2744));

    //general aspect ratio of books are 3:4 for so we choose the size (300, 400)
    pts_correct.push_back(Point2f(0, 0));
    pts_correct.push_back(Point2f(299, 0));
    pts_correct.push_back(Point2f(299, 399));
    pts_correct.push_back(Point2f(0, 399));

    //calculate homography from book image to size(300, 400)
    Mat homographyMat = findHomography(pts_book, pts_correct);

    Mat result;

    //warp book for perspective correction (300, 400)
    warpPerspective(book, result, homographyMat, Size(300, 400));

    //create windows to display images
    namedWindow("book", WINDOW_NORMAL);
    namedWindow("correction", WINDOW_NORMAL);

    //display image
    imshow("book", book);
    imshow("correction", result);

    //Press esc to exit the program
    waitKey(0);

    //Close all the opened windows
    destroyAllWindows();
    
    return 0;
}