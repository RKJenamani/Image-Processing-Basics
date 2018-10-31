#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main()
{	
	int i,j,k;
	Mat img=imread("Lenna.png",1);
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	cout<<"Input number : 1-> avg 2->max 2 3->weighted";
	cin>>k;
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			if(k==1)
				img1.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;
			else if(k==2)
			{
				if(img.at<Vec3b>(i,j)[0]>img.at<Vec3b>(i,j)[1] && img.at<Vec3b>(i,j)[2]>img.at<Vec3b>(i,j)[1])
					img1.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[2])/2;

				else if(img.at<Vec3b>(i,j)[0]>img.at<Vec3b>(i,j)[2] && img.at<Vec3b>(i,j)[1]>img.at<Vec3b>(i,j)[2])
					img1.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1])/2;

				else
					img1.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/2;
			}
			else
					img1.at<uchar>(i,j)=0.07*(img.at<Vec3b>(i,j)[0]+0.72*img.at<Vec3b>(i,j)[1]+0.21*img.at<Vec3b>(i,j)[2]);
				
		}

	imwrite("Greyscale.png",img1);
	namedWindow("invert",WINDOW_NORMAL);
	imshow("invert",img1);
	waitKey(0);
	return 0;
}
