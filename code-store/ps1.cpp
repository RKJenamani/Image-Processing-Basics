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
Mat img=imread("p1.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int main()
{	
	int c[9],n=0,i=0,j=0,k,l,flag,a,x,y;
	randomize();
	for(k=1;k<=9;k++)
	{
		while(1)
		{		
			a=random(9);
			flag=0;
			for(l=0;l<n;l++)
				if(c[l]==a)
					flag=-1;
			if(flag==-1)
				break;
		}
		c[l]=a;
		n++;
		for(x=a/3;x<img.rows/3+a/3;x++)
			for(y=a%3;y<img.rows/3+a%3;y++)
				{
					img1.at<Vec3b>(i,j)=img.at<Vec3b>(x,y);
					i++;
					j++;
				}
	}
	namedWindow("chaljabhai",WINDOW_NORMAL);
	imshow("chaljabhai",img1);
	waitKey(0);
	imwrite("ps12.jpg",img1);
	return 0;
}	
				
	
		
