#define MAX 10
#define MAX2 100
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
using namespace cv;
Mat img(400,400,CV_8UC3,Scalar(0,0,0));
int main()
{	
	Point value1,value2;
	value1.x=10;
	value1.y=40;
	value2.x=370;
	value2.y=260;
	line(img,value1,value2,{255,255,255},1);
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
	return 0;
}