#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("Lenna.jpg",1);
int isvalid( int i, int j)
{
	 if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else
		return 0;
}
int main()
{	
	
	int i,j,k,l,z,m,d=0,median,o,p,temp,arr[20],sum;
	Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	cout<<"input 1->Mean 2->Median 3->Gaussian";cin>>m;
	if(m==1)
	{
		for(i=0;i<img.rows;i++)
			for(j=0;j<img.cols;j++)
			{	
				for(z=0;z<3;z++)
				{
					sum=0;
					for (k=i-1;k<i+2;k++)
						for(l=j-1;l<j+2;l++)
						{
							if(isvalid(k,l)==1)
								sum=sum+img.at<Vec3b>(k,l)[z];
						}
				img1.at<Vec3b>(i,j)[z]=sum/9;
				}
			}
	
	}
	else if (m==2)
	{	
		for(i=0;i<img.rows;i++)
			for(j=0;j<img.cols;j++)
			{	
				for(z=0;z<3;z++)
				{	d=0;
					for (k=i-1;k<i+2;k++)
						for(l=j-1;l<j+2;l++)
						{
							if(isvalid(k,l)==1)
							{
								arr[d]=img.at<Vec3b>(k,l)[z];
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
					img1.at<Vec3b>(i,j)[z]=median;
				}
			}
	}
	namedWindow("lolscale",WINDOW_NORMAL);
	imshow("lolscale",img1);
	waitKey(0);
	return 0;
}

