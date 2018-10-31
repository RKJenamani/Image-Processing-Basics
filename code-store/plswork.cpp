#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int th=150;
Mat img=imread("shapes.jpg",0);
int isvalid( int i, int j)
{
	 if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else
		return 0;
}
void DFSfunc(int i, int j)
{	
	img.at<uchar>(i,j)=th;
	//if(img.at<uchar>(i-1,j)=0 && img.at<uchar>(i,j+1)=0 && img.at<uchar>(i+1,j)=0 && img.at<uchar>(i,j-1)=0 )
	//	return 1;
	//else
	//{	
		if(isvalid(i-1,j))
			if(img.at<uchar>(i-1,j)>240)
				DFSfunc(i-1,j);
		if(isvalid(i-1,j-1))
			if(img.at<uchar>(i-1,j-1)>240)
				DFSfunc(i-1,j-1);
		if(isvalid(i-1,j+1))
			if(img.at<uchar>(i-1,j+1)>240)
				DFSfunc(i-1,j+1);
		if(isvalid(i+1,j-1))
			if(img.at<uchar>(i+1,j-1)>240)
				DFSfunc(i+1,j-1);
		if(isvalid(i+1,j+1))
			if(img.at<uchar>(i+1,j+1)>240)
				DFSfunc(i+1,j+1);
		if(isvalid(i,j+1))
			if(img.at<uchar>(i,j+1)>240)
				DFSfunc(i,j+1);
		if(isvalid(i+1,j))
			if(img.at<uchar>(i+1,j)>240)
				DFSfunc(i+1,j);
		if(isvalid(i,j-1))
			if(img.at<uchar>(i,j-1)>240)
				DFSfunc(i,j-1);
}	
void onMouse(int event, int y, int x, int flag, void *a)
{
	if(event==1)
		DFSfunc(x,y);
	imshow("chaljabhai",img);
}
void update_img(int t, void *a)
{
	setMouseCallback("chaljabhai",onMouse,0);
}

int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	
	createTrackbar("change_it", "chaljabhai",&th,255,update_img);
	
	waitKey(0);
	return 0;
}

