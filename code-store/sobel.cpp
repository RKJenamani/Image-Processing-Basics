#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h> 
using namespace std;
using namespace cv;
Mat img=imread("f3.jpg",1);
void sobel(int t, void *a)
{
	int i,j,k;
	Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			for(k=0;k<3;k++)
			{
				img2.at<Vec3b>(i,j)[k]=(t*img.at<Vec3b>(i,j)[k]+(1000-t)*img1.at<Vec3b>(i,j)[k])/1000;
			}
		}
	//imwrite("morph.png",img2);
	
	imshow("chaljabhai",img2);
	waitKey(500);
	
}

int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	imshow("win1", img);
	waitKey(2000);
	imshow("win2", img1);
	waitKey(2000);
	int th=127;
	createTrackbar("change_it", "chaljabhai",&th,1000,morph);
	waitKey(0);
	return 0;
}

