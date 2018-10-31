#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;

int main()
{	
	Mat img=imread("name.jpg",1);
	int i,j;
	Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
					img1.at<Vec3b>(i,j)=(img.at<Vec3b>(i,j)*1000/(pow((i-img.rows)*3/img.rows,2) + pow((j-img.cols)*3/img.cols,2)));
	namedWindow("scale",WINDOW_NORMAL);
	imshow("scale",img1);
	waitKey(0);
	return 0;
}
	
	
