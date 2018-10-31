#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{	
	Mat img=imread("Lenna.png",0);
	int i,j,k;
	co
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			if(img.at<uchar>(i,j)>t)
				img1.at<uchar>(i,j)=img1.at<uchar>(i,j)*k;
	namedWindow("scale",WINDOW_NORMAL);
	imshow("scale",img1);
	waitKey(0);
	return 0;
}

