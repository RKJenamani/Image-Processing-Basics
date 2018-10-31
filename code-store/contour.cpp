#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h> 
using namespace std;
using namespace cv;
Mat img=imread("p1.jpg",1);
Mat img1=imread("p2.jpg",1);
int main()
{
	int i,j,k,l,n,x,y,min;
	long long int count,ll;

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
				x=i;
				y=j;
			}
			ll=min;
			cout<<"x= "<<x<<"  y= "<<y<<" count=  "<<count<<"\n"<<"ll -"<<ll<<"min --"<<min<<"\n";
		}
	for(i=x;i<x+img1.rows;i++)
	{
		img.at<Vec3b>(i,y)={0,0,0};
		//img.at<Vec3b>(i,y+1)={0,0,0};
		//img.at<Vec3b>(i,y+2)={0,0,0};
	}
	for(j=y;j<y+img1.cols;j++)
	{
		img.at<Vec3b>(x,j)={0,0,0};
		//img.at<Vec3b>(x+1,j)={0,0,0};
		//img.at<Vec3b>(x+2,j)={0,0,0};
	}
	for(i=x;i<x+img1.rows;i++)
	{
		img.at<Vec3b>(i,y+img1.cols)={0,0,0};
		//img.at<Vec3b>(i,y+1+img1.cols)={0,0,0};
		//img.at<Vec3b>(i,y+2+img1.cols)={0,0,0};
	}
	for(j=y;j<y+img1.cols;j++)
	{
		img.at<Vec3b>(x+img1.rows,j)={0,0,0};
		//img.at<Vec3b>(x+img.rows+1,j)={0,0,0};
		//img.at<Vec3b>(x+img.rows+2,j)={0,0,0};
	}
	namedWindow("lol",WINDOW_NORMAL);
	imshow("lol",img1);
	namedWindow("lel",WINDOW_NORMAL);
	imshow("lel",img);
	waitKey(0);
	return 0;
}
	
		
