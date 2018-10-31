#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
using namespace cv;
Mat jumbled=imread("jumbled.jpg",1);
Mat original=imread("original.jpg",1);
Mat jumbled1(jumbled.rows,jumbled.cols,CV_8UC3,Scalar(0,0,0));

struct xy
{
	int x;
	int y;
};
xy templatematching(Mat img, Mat img1)
{
	int i,j,k,l,n,min;
	long long int count;
	xy lol;
	for(i=0;i<img.rows-img1.rows;i++)
		for(j=0;j<img.cols-img1.cols;j++)
		{
			count=0;
			for(k=i;k<i+10;k++)
				for(l=j;l<j+10;l++)
					for(n=0;n<3;n++)
				count=count+pow((img.at<Vec3b>(k,l)[n]-img1.at<Vec3b>(k-i,l-j)[n]),2);
			if(i==0 && j==0)
				min=count;
			if(count<min)
			{
				min=count;
				lol.x=i;
				lol.y=j;
			}
		}
	return lol;
}
int main()
{	
	Mat kernel(original.rows/3,original.cols/3,CV_8UC3,Scalar(0,0,0));
	int m=0,n=0,o,p,i,j,k;
	xy lol;
	for(k=0;k<9;k++)
	{
		for(i=k/3;i<kernel.rows+k/3;i++,m++)
			for(j=k%3;j<kernel.cls+k%3,j++,n++)
				kernel.at<Vec3b>(i,j)=jumbled.at<Vec3b>(m,n);
		lol=templatematching(original,kernel);
		for(i=lol.x,o=0;i<kernel.rows+lol.x;i++,o++)
			for(j=lol.y,p=0;j<kernel.cols+lol.y;j++),p++
				jumbled1.at<Vec3b>(i,j)=kernel.at<Vec3b>(o,p);
	}
	namedWindow("chaljabhai",WINDOW_NORMAL);
	imshow("chaljabhai",jumbled1);
	waitKey(0);
	return 0;
}
				
	
	
	
