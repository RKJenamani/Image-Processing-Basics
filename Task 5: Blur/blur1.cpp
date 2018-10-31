#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("index.jpg",0);
int isvalid( int i, int j)
{
	 if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else
		return 0;
}
int main()
{	
	
	int i,j,k,l,m,d=0,median,o,p,temp,arr[20],sum;
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	cout<<"input 1->Mean 2->Median";cin>>m;
	if(m==1)
	{
		for(i=0;i<img.rows;i++)
			for(j=0;j<img.cols;j++)
			{	
				sum=0;
				for (k=i-1;k<i+2;k++)
					for(l=j-1;l<j+2;l++)
					{
						if(isvalid(k,l)==1)
							sum=sum+img.at<uchar>(k,l);
					}
				img1.at<uchar>(i,j)=sum/9;
			}
	
	}
	else
	{	
		for(i=0;i<img.rows;i++)
			for(j=0;j<img.cols;j++)
			{	
				d=0;
				for (k=i-1;k<i+2;k++)
					for(l=j-1;l<j+2;l++)
					{
						if(isvalid(k,l)==1)
							{
								arr[d]=img.at<uchar>(k,l);
								d++;
							}
					}
				//bubble sort
				for(o=0; o<d-1; o++)
				{
					for(p=0; p<(d-1-o); p++)
					{
						if(arr[p]>arr[p+1])
						{
							temp=arr[p];
							arr[p]=arr[p+1];
							arr[p+1]=temp;
						}						
					}
					
				}
				median=arr[d/2];
				img1.at<uchar>(i,j)=median;
			}
	}
	namedWindow("lolscale",WINDOW_NORMAL);
	imshow("lolscale",img1);
	waitKey(0);
	return 0;
}

