#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("a.png",1);
int rn=0,rx=127,bn=0,bx=127,gn=0,gx=127;
void morph(int t, void *a)
{
	int i,j;

	Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			if(img.at<Vec3b>(i,j)[0]<=bx && img.at<Vec3b>(i,j)[0]>=bn)
				img1.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
			if(img.at<Vec3b>(i,j)[1]<=gx && img.at<Vec3b>(i,j)[1]>=gn)
				img1.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];

			if(img.at<Vec3b>(i,j)[2]<=rx && img.at<Vec3b>(i,j)[2]>=rn)
				img1.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
		}
	//imwrite("morph.png",img2);
	
	imshow("chaljabhai",img1);
	waitKey(500);
	
}

int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	createTrackbar("red_max", "chaljabhai",&rx,255,morph);
	createTrackbar("red_min", "chaljabhai",&rn,255,morph);
	createTrackbar("blue_max", "chaljabhai",&bx,255,morph);
	createTrackbar("blue_min", "chaljabhai",&bn,255,morph);
	createTrackbar("green_max", "chaljabhai",&gx,255,morph);
	createTrackbar("green_min", "chaljabhai",&gn,255,morph);
	waitKey(0);
	return 0;
}

