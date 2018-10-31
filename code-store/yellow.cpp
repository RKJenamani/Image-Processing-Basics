
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
int main()
{
	Mat img1(50,50,CV_8UC3,Scalar(0,255,255));
        namedWindow("win",WINDOW_NORMAL);
	imshow("win",img1);
	waitKey(0);
}





