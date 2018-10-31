#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("writ.png",0);
int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	int i,j,k,l;
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
        //img1=img
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			img1.at<uchar>(i,j)=img.at<uchar>(i,j);
//erosion
	for(i=1;i<img.rows-1;i++)
		for(j=1;j<img.cols-1;j++)	
			for(k=i-1;k<i+2;k++)
				for(l=j-1;l<j+2;l++)
					if(img.at<uchar>(k,l)==0)
						img1.at<uchar>(i,j)=0;
	
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			img.at<uchar>(i,j)=img1.at<uchar>(i,j);
	
//dilation
	for(i=1;i<img.rows-1;i++)
		for(j=1;j<img.cols-1;j++)	
			for(k=i-1;k<i+2;k++)
				for(l=j-1;l<j+2;l++)
					if(img.at<uchar>(k,l)==255)
						img1.at<uchar>(i,j)=255;

	//imwrite("writ.png",img1);
imshow("chaljabhai11",img);
	
	imshow("chaljabhai",img1);
	waitKey(0);
	return 0;
}

