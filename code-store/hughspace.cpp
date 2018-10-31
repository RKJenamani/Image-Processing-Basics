#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h> 
using namespace std;
using namespace cv;

Mat img=imread("pentagon.png",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
void hughfunc()
{
	int i,j,theta,r;
	for (i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			if(img.at<uchar>(i,j)>200)
				for(theta=0;theta<360;theta++)
				{	
					if(i*cos(theta*3.14/180)+j*sin(theta*3.14/180)>0)
						r=i*cos(theta*3.14/180)+j*sin(theta*3.14/180);
					img1.at<uchar>(img.rows-r,theta)=img1.at<uchar>(img.rows-r,theta)+10;
				}
					
}	
							
					
int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	namedWindow("ch2",WINDOW_NORMAL);
	imshow("ch2",img1);
	hughfunc();
	imshow("chaljabhai",img1);
	waitKey(0);
	return 0;
}

	
