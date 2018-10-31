#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
int main()
{	
	int i,j;
	Mat img=imread("invertimage.jpg",1);
	Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			img1.at<Vec3b>(i,img.cols-j-1)=img.at<Vec3b>(i,j);
	imwrite("name.jpg",img1);
	namedWindow("invert",WINDOW_NORMAL);
	imshow("invert",img1);
	waitKey(0);
	return 0;
}
