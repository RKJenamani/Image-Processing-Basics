#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{	
	Mat img=imread("Lenna.png",0);
	int i,j,k=0,maxcount,scale;
	int count[256];
	while(k<256)
	{
		count[k]=0;
		for(i=0;i<img.rows;i++)
			for(j=0;j<img.cols;j++)
				if(img.at<uchar>(i,j)==k)
					count[k]++;
	k++;
	}
	maxcount=count[0];
	k=1;
	while(k<256)
	{
		if(count[k]>maxcount)
			maxcount=count[k];
		k++;
	}
	scale=maxcount+10;
	Mat img1(scale,256,CV_8UC1,Scalar(255));
	k=0;
	while(k<256)
	{
		for(i=scale-1;i>=(scale-count[k]);i--)
			img1.at<uchar>(i,k)=0;
		k++;
	}
	namedWindow("scale",WINDOW_NORMAL);
	imshow("scale",img1);
	waitKey(0);
	return 0;
}

