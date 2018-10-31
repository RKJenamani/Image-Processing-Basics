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

**CONTRAST and BRIGHTNESS**

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
The intensity of the pixel is equal to the mean of intensities of the pixels in the kernel.\
FRACTIONAL SCALING:\
As first downscale then upscale leads to loss of information , first upscale then downscale is preferred.

**BLURRING an IMAGE:**

MEAN BLUR:\
The  new intensity of each pixel is the mean of intensities of the pixels of the kernel centered around this pixel.

MEDIAN BLUR:\
The  new intensity of each pixel is the median of intensities of the pixels of the kernel centered around this pixel.

GAUSSIAN BLUR:\

#### Tasks:

Task 4: Convert the famous image 'Lenna' into greyscale.\
Task 5: Implement mean and median blur on an image.\

# TO BE EDITED

(1) Started with various methods of implementation of gaussian blur like border, basic wrap round, reflection.
For the corners and edges int the images, there
methods are-
(i)Padding
(ii)Wrap Around
(iii)Reflection
Padding and Reflection are the ones which are used the
most.
(2) Introduction to image segmentation using colour extraction, border detection, etc.
Color Extraction-One of the components of segmentation
In this method what we do is define the maximum and
minimum for the R,G,B. According to that
the one which lie in the range are colored white and the
background is colored as black.For this we make six
trackbars for setting the minimum and the maximum for
each of the shade and we extract the component of the
image in that by changing the minimum and the maximum of
the R,G,B(the one which will lie in the range can be
extracted.)
 :: ::  Task : Extraction of colours from an image using six trackbars. :: ::
(3) Introduction to edge detection filters : two types - sobel filter and prewitt filter.
    Each and every element of a kernel is multiplied by the corresponding elements in a specified matrix. Calculation of mean gradient and comparison with the threshold value should return either '0' or 255.

** Prewitt Filter **
In Prewitt  filter the Kernel is multiplied with the values as follows:
    (-1  0  1 )                              
   ( -1  0  1 )                       
      ( -1  0  1 ) 

Sobel filter
In sobel filter the Kernel is multiplied with the values as follows:
      (-1  -2  -1)                               ( -1  0  1 )
gy=⅛  (  0  0  0 )                       gx=⅛    ( -2  0  2 )
      ( 1  2  1 )                               ( -1  0  1 )

Value =sqrt(gy^2+gx^2)

Or approx value=|gx+gy|


(4) To remove noise after edge detection : using erosion - dilation.
    Erosion : If there is any black pixel in the kernel, make the centre pixel black. (Used to remove white spots)
    Dilation : If there is any white pixel in the kernel, make the centre pixel white. (Used to remove black spots)

(5) Using canny library for edge detection :
    Processes done :
    (0) Gaussian blur.
    (0) Sobel/Prewitt edge detection (By default - sobel filter)
    (0) Non-maximum suppression.
    (0) Thresholding(L+H).

    Note : H/L ratio usually lies between 2 and 3.


(1) Started with two types of calling erosion and dilation based on their order of execution in order to remove noice. They are :
    (.) Morphological opening. (erosion, then dilation)
    (.) Morphological closing. (dilation, then erosion)

(2) Introduction to graphs : 
Graph is the combination of the nodes(pixels) and the edges
connecting the node.
    Vertice(node) - representation of each pixel.
    Edge - line joining two adjacent vertices.
    Edge weight - number denoting how difficult is the traversal.

(3) Path traversal methods in graph :
    (.) BFS (Breadth First Search)
    (.) DFS (Depth First Search)
  DFS:     In this method we move in only one path ,i.e., starting from
the parent we move from one child to the other and cover
the whole image.
After the path is over, we then backtrack and see if any part
had multiple child and then move in that path.Here we do
not move along all the children at a time unlike the BFS.
Remember while backtracking the node where we get a
unvisited child first we cover that first.
Mark the node Visited and search for Unvisited Nodes.
It can be executed using i-Recursion or ii-using Stacks

    Usage : to extract features of an image like number of shapes,etc.

    Pseudo code for DFS :

    DFS(start_node) {
        Mark start_node as visited.

        if (Neighbours of start_node have been visited) return;

        for (each neighbour) DFS(neighbour)
    }

BFS:      In this method what we do is move layer wise ,i.e., starting
from the parent we move along all the child of the nodes.
We have to move along all the nodes of a parent, visit all the
childs for a layer of node in the order in which they are
written.
Implemented Using Queues





(4) Implementation of setMouseCallback to get actions of mouse.
    Eg: setMouseCallback("win",onMouse,0);
    void onMouse(int event, int y, int x, int flag, void *a) {}

    List of events : EVENT_LBUTTONDOWN, EVENT_RBUTTONDOWN, EVENT_LBUTTONUP, EVENT_RBUTTONUP, etc.

(5) Introduction to stacks and queues. Implementation of BFS using queue.
    Psuedo Code:
    push(start_node);

    If (queue is not empty) {
        curr = front of queue;
        Pop the last element;

        for (all (v,w) pairs) {
            if (w is not visited)
                mark w as visited.
                push w to queue.
        }
    }

(6) Introduction to linked list.

    Syntax :

    struct node {
        int info;
        struct node* next;
    }*head;

    head.info => returns the integer value of info.
    head.next => returns the address of the next node.

(7)
void onMouse(int event,int y,int x,int flag,void *a)
{........}
setMouseCallback(“window_name”,onMouse,0)
The setMouseCallback function is used to bring the changes
in the image on different actions done by the mouse.
event- This is the one which stores the action of the image.
Y-Stores the y-coordinate
x-Stores the x-coordinate
((Be careful here the x and y axis are different from that of
the image))

Horizontal one is x and y is the vertical one.
*setMouseCallback function will be called in the main
function.
For the events, for example
EVENT_LBUTTONDOWN-Left click

EVENT_RBUTTONDOWN-Right click

8)  Stack: It is an abstract data structure based on LIFO (last in first out). When stack is full, it is                                            called stack overflow. It’s functions are:
top(): initialized as -1, it returns a reference to the top element, i.e. the one last entered in the stack.
push(i): it inserts a new element, i at the top of the stack
pop(): it removes the top element from the stack
isEmpty(): it returns boolean true or 1 if the stack is empty or the value of top is -1 and boolean false or 0 otherwise
9)   Queue: It is also an abstract data structure which is however based on FIFO (first in first   out). It’s functions are:
isEmpty() – Returns whether the queue is empty
size() – Returns the size of the queue
front() – Returns a reference to the first element of the  queue
back() – Returns a reference to the last element of the  queue
enQueue(i) – Adds the element ‘g’ at the end of the queue
deQueue() – Deletes the first element of the queue

10)
Dijkstra(Shortest path algorithm)
It is the algorithm of finding the shortest path from starting
node to any node according to the nodes. The path with the
minimum weight gives the shortest path.
we create three lists for each node namely open, closed and parent.
  

 Another path planning algorithm - A star, which is a greedy algorithm.

Hough Transform

Suppose we have a image on which canny has been applied.
Now that book would be black and white and would have deformations like a straight will not be complete, it’ll have spaces in between , it would be broken.

To fix that we need to draw a line which passes through maximum number of those points.

To draw that line hough transform is done.

xcos()   +  ysin()  = r

That’s a general equation of line.
What we do is, for every point on that line after applying canny , we vary theta and get the corresponding value of r and then we plot a graph  of  vs  r.
Now the idea is that which ever line passes through maximum number of points will have the same value of  and r and hence we’ll get some sort of maxima in the graph plotted.

 




That’s a  hough transform applied on a pentagon, that’s we have 5 maximas each giving the value of  and r and hence the equation of line.
Mouse Callback Function


   setMouseCallback("win",onMouse,0);

void onMouse(int event,int y,int x, int flag ,void *a)
{
int z;
if(event==1)                        // Left mouse click
z=f(x,y,75);
else if(event==2)               // Right mouse click
z=f(x,y,125);
imshow("win",img1);
}


Contour Detection

Contours are basically an outline representing or bounding the shape or form of something eg. in this case similar pixels.

There is an in built function for this findContours . 


findContours(image,contours,hierarchy,mode,method);
Where:
Contours : vector<vector<Point>>
Hierarchy : vector<Vec 4i>
Mode : This is of various types:
A. RETR_EXTERNAL  (only external contours)
B.RETR_LIST     (provides list of contours without hierarchy)
C.RETR_COMP (only the outer and it’s two children are considered,rest external)
D.RETR_TREE  (provides list of contours with hierarchy)  
E.RETR_FLOODFILL





    
Image on which contour has been applied, we can clearly see the boundaries of 
            various objects.



3. HSV system of colours

It’s a different system than RGB to define a pixel.
It’s better as in RGB same colour might not look same every time and at every place…
    HSV system takes care of that.
We saw during the color extraction that we had to make six different track bars so as to
extract different colors.
Hence it become very hectic to work on RGB.
Therefore, a new system of HSV is defined.
H-Hue- Degree on the HSV cylinder
S-Saturation- Percentage of the color in the pixel
V-Value- Darkness or the lightness



H : Hue
V : Value
S : Saturation

b’ = b/255
r’ = r/255
g’ = g/255

V = max{b’,g’,r’}

S =  (v-min{r’,g’,b’})/v        if v 0
   = 0                                 otherwise

H = 60(g’ - b’)/(V - min{r’,g’,b’})      if V=r’
   =   120 + 60(b’ - r’)/(V - min{r’,g’,b’})      if V=g’
   =   240 + 60(r’ - g’)/(V - min{r’,g’,b’})      if V=b’           

There is an in built function for this 

cutColour(input_img,output_img,BGR2HSV);

    4. Template Matching
    
A template is a part of a given image.
In template matching we take that template an and try to find it’s best match in the given 
Image by traversing it over the image.

What we do is we take the template or a big kernel of it and then we traverse it across     
the image, we do so by taking the sq. of the difference of colour intensities of the 
corresponding pixels and then adding them up, the kernel of the image with the least
difference is the best match.

5. Corner Detection
It’s basic principle was based on the fact that at a corner the intensities of colour would             change by a large amount in both x and y direction.










