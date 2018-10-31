#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("dfs_path.jpg",0);
int isvalid( int i, int j)
{
	 if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else
		return 0;
}	
void DFSfunc(int i, int j)
{	
	img.at<uchar>(i,j)=255;
	//if(img.at<uchar>(i-1,j)=0 && img.at<uchar>(i,j+1)=0 && img.at<uchar>(i+1,j)=0 && img.at<uchar>(i,j-1)=0 )
	//	return 1;
	//else
	//{	
		if(isvalid(i-1,j))
			if(img.at<uchar>(i-1,j)<100)
				DFSfunc(i-1,j);
		if(isvalid(i-1,j-1))
			if(img.at<uchar>(i-1,j-1)<100)
				DFSfunc(i-1,j-1);
		if(isvalid(i-1,j+1))
			if(img.at<uchar>(i-1,j+1)<100)
				DFSfunc(i-1,j+1);
		if(isvalid(i+1,j-1))
			if(img.at<uchar>(i+1,j-1)<100)
				DFSfunc(i+1,j-1);
		if(isvalid(i+1,j+1))
			if(img.at<uchar>(i+1,j+1)<100)
				DFSfunc(i+1,j+1);
		if(isvalid(i,j+1))
			if(img.at<uchar>(i,j+1)<100)
				DFSfunc(i,j+1);
		if(isvalid(i+1,j))
			if(img.at<uchar>(i+1,j)<100)
				DFSfunc(i+1,j);
		if(isvalid(i,j-1))
			if(img.at<uchar>(i,j-1)<100)
				DFSfunc(i,j-1);
}
int main()
{	namedWindow("chaljabhai",WINDOW_NORMAL);
	int i,j,count=0;
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			if(img.at<uchar>(i,j)<100)
			{
				DFSfunc(i,j);
				count++;
			}
	cout<<count<<endl;
	imshow("chaljabhai",img);
	waitKey(0);
	return 0;
}

