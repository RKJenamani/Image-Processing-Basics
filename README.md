# Image-Processing-Basics
### Intoduction to image processing using OpenCV library.

## Image
Each image is made up of a certain no. of pixels say 50*50 or 200*200. Hence each image can be said to be a conglomeration of squares and each square can be denoted by the ordered pair (i,j). Each square projects a single colour. Now two situations arise:

1.Image is Colored

The image is made up of different intensities of the three primary colours Blue, Green and Red. Each of these intensities of these primary colours can be given a value between 0 to 255 (255 denoting maximum intensity of red and 0 denoting total absence of red). Hence a colour is characterised by the ordered pair ( *intensity of blue*, *intensity of green*, *intensity of red*). So

(255,0,0)-> Blue\
(0,255,0)-> Green\
(0,0,255)-> Red\
(0,0,0)-> Black\
(255,255,255) -> White\
(0,255,255)->Yellow

2.Image is Black and White

A pixel can be characterised by a single number denoting the intensity of white. So,

0->Black\
255->White

## Basic Programming

The programming is same as basic C++ with the inclusion of a few classes and functions.
We have to include the following libraries at the start of each IP program.

#include “opencv2/highgui/highgui.hpp”\
#include “opencv2/imgproc/imgproc.hpp”\
#include “opencv2/core/core.hpp”

**To create an image:**

The class ‘Mat’ is used for the intialization of object (an image) with a specified no. of pixels and channel nos.

*Syntax for single channel:* \
Mat imgname(no. of rows, no. of columns, CV_8UC1,Scalar( no. for intensity of W));

*Syntax for triple channel:* \
Mat imgname(no. Of rows, no. of columns,CV_8UC3,Scalar(B,G,R);

**To display an Image:**

*Syntax:*\
namedWindow( “windowname”,WINDOW_NORMAL);\
inshow(“windowname”, imgname);\
waitKey(0);

WINDOW_NORMAL: Size of image not fixed\
alternate: WINDOW_AUTOSIZE: Size of image fixed

**To read no. of pixels from an Imported Image**\
img.rows->gives no. Of rows\
img.cols->gives no. Of columns

*Syntax:* mat img1(img.rows,img.columns,CV_8UC3,scalar(0,255,255);

**To write (save) an Image:**

*Syntax:* imwrite(“name.png”,imgname);\
Saves the image imgname at the same location as code by the name name.png

#### Tasks:

Task 1: Create a yellow box.\
Task 2: Create a checkboard.\
Task 3: Invert an image

## Converting a image

**Methods to convert a COLOUR IMAGE into a GRAYSCALE IMAGE**\
1.G+(R+G+B)/3
2.G=(Max(B,G,R)+Min(B,G,R))/2
3.G=0.21R+0.72G+0.07B (most accurate as eyes are most sensitive to green colour and it takes into account each colour)

**Conversion of an IMAGE into a BINARY IMAGE**\
To convert an image into a binary image, pixels having intensity below a threshold are assigned black while pixels having intensity above a threshold are assigned white.

**Histogram of frequency of intensity in an image**

**CONTRAST and BRIGHTNESS**\

Contrast:Relative difference in intensities of pixels \
Brightness: directly proportional to instensity of pixels

->Multiplying each pixel with a number a will change both brightness and contrast of an image.\
->Adding a number a to each pixel will change the brightness of an image, but not the contrast.

**ROTATION of an IMAGE:**

**MORPHING of 2 IMAGES:**

**SCALING of an IMAGE:**

UPSCALING:\
Each pixel is converted to a kernel\
DOWNSCALE:\
Each kernel is converted to a single pixel\
The intensity of the pixel is equal to the mean of intensities of the pixels in the kernel.
FRACTIONAL SCALING:\
As first downscale then upscale leads to loss of information , first upscale then downscale is preferred.

**BLURRING an IMAGE:**

MEAN BLUR:\
The  new intensity of each pixel is the mean of intensities of the pixels of the kernel centered around this pixel.

MEDIAN BLUR:\
The  new intensity of each pixel is the median of intensities of the pixels of the kernel centered around this pixel.

GAUSSIAN BLUR:\





