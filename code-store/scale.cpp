#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{	
	Mat img=imread("Lenna.png",1);
	int i,j,k,l,z,sum;
	Mat img1(img.rows*3,img.cols*3,CV_8UC3,Scalar(0,0,0));
	Mat img2(img.rows*3/5,img.cols*3/5,CV_8UC3,Scalar(0,0,0));
	//upscale
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{	
			for(k=i*3;k<(i*3+3);k++)
				for(l=j*3;l<(j*3+3);l++)
					img1.at<Vec3b>(k,l)=img.at<Vec3b>(i,j);
		}
	//downscale
	for(i=0;i<img.rows*3/5;i++)
		for(j=0;j<img.cols*3/5;j++)
			for(z=0;z<3;z++)
			{
				sum=0;
				for(k=0;k<5;k++)
					for(l=0;l<5;l++)
						sum=sum+img1.at<Vec3b>(5*i+k,5*j+l)[z];
				img2.at<Vec3b>(i,j)[z]=sum/25;
			}
	cout<<img.rows<<"   "<<img1.rows<<"    "<<img2.rows<<endl;
	namedWindow("lolscale",WINDOW_NORMAL);
	imshow("lolscale",img1);
	waitKey(0);
	return 0;
}

