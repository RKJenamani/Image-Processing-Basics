#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("Lenna.png",0);
namedWindow("kk",WINDOW_NORMAL);
void update_img(int t, void *a)
{
	int i,j;
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			if(img.at<uchar>(i,j)>t)
				img1.at<uchar>(i,j)=255;
	imwrite("Binimg1.png",img1);
	
	imshow("kk",img1);
	
}

int main()
{	
	int th=127;
	createTrackbar("change_it", "kk",&th,255,update_img);
	waitKey(0);
	return 0;
}

