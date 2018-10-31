#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("profilepic.jpg",0);
int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	int th=10;
	int i,j,gx,gy;
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=1;i<img.rows-1;i++)
		for(j=1;j<img.cols-1;j++)
		{
			gx=((-1)*img.at<uchar>(i-1,j-1)+(-2)*img.at<uchar>(i-1,j)+(-1)*img.at<uchar>(i-1,j+1)+(1)*img.at<uchar>(i+1,j-1)+(2)*img.at<uchar>(i+1,j)+(1)*img.at<uchar>(i+1,j+1))/8;
			gy=((-1)*img.at<uchar>(i-1,j-1)+(-2)*img.at<uchar>(i,j-1)+(-1)*img.at<uchar>(i+1,j)+(1)*img.at<uchar>(i-1,j+1)+(2)*img.at<uchar>(i,j+1)+(1)*img.at<uchar>(i+1,j+1))/8;
			if(gx*gx+gy*gy>th*th)
				img1.at<uchar>(i,j)=255;
		}
	imwrite("writ.png",img1);
	
	imshow("chaljabhai",img1);
	waitKey(0);
	return 0;
}

