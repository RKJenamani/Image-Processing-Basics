# Image-Processing-Basics
## Intoduction to image processing using OpenCV library.

### Image
Each image is made up of a certain no. of pixels say 50*50 or 200*200. Hence each image can be said to be a conglomeration of squares and each square can be denoted by the ordered pair (i,j). Each square projects a single colour. Now two situations arise:

1.Image is Colored

The image is made up of different intensities of the three primary colours Blue, Green and Red. Each of these intensities of these primary colours can be given a value between 0 to 255 (255 denoting maximum intensity of red and 0 denoting total absence of red). Hence a colour is characterised by the ordered pair ( *intensity of blue*, *intensity of green*, *intensity of red*). So

(255,0,0)-> Blue

(0,255,0)-> Green

(0,0,255)-> Red

(0,0,0)-> Black

(255,255,255) -> White

(0,255,255)->Yellow

2.Image is Black and White

A pixel can be characterised by a single number denoting the intensity of white. So,

0->Black
255->White

### Programming

The programming is same as basic C++ with the inclusion of a few classes and functions.
We have to include the following libraries at the start of each IP program.

#include “opencv2/highgui/highgui.hpp”
#include “opencv2/imgproc/imgproc.hpp”
#include “opencv2/core/core.hpp”

### To create an img

The class ‘Mat’ is used for the intialization of object (an image) with a specified no. of pixels and channel nos.

*Syntax for single channel:*

Mat imgname(no. of rows, no. of columns, CV_8UC1,Scalar( no. for intensity of W));

*Syntax for triple channel:*

Mat imgname(no. Of rows, no. of columns,CV_8UC3,Scalar(B,G,R);

*To display an Image:*

namedWindow( “windowname”,WINDOW_NORMAL);
inshow(“windowname”, imgname);
waitKey(0);


WINDOW_NORMAL: Size of image not fixed
alternate: WINDOW_AUTOSIZE: Size of image fixed

