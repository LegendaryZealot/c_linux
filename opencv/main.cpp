#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char *args[]){
    Mat img =imread(args[1]);
    imshow("image",img);
    waitKey();
    return 0;
}
