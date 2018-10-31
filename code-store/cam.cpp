#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	VideoCapture vid(0);
	Mat frame;namedWindow("win",WINDOW_AUTOSIZE);
	while(1)
	{
		vid>>frame;
		//vid.read(frame);
		
		imshow("win",frame);
		waitKey(50);
	}
	return 0;
}
