

EPSILON = max length of an edge in the tree;
K = max number of nodes in the tree;

rrt(start,end){
	startNode = new Node at start;
	startTree = new RRTree(startNode);
	endNode = new Node at end;
	endTree = new RRTree(endNode);

	return makePath(startTree,endTree);	
}

makePath(t1,t2){
	qRandom = new Node at random location;
	qNear = nearest node to qRandom in t1;
	qNew = new Node EPSILON away from qNear
			in direction of qRandom;

	t1.add(qNew);
	if(there's a path from qNew to the closest node in t2){
		path = path from qNew to root of t1;
		path.append(path from qNew to root of t2);
		return path;
	}else if(size(t1) < K){
		return makePath(t2,t1);
	}else{
		return FAIL;
	}
}

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
using namespace cv;

Mat img=imread("rrtimg.png",1);
struct coordinates
{
	int x;
	int y;
}
int rrt(coordinates start, coordinates end)
{
	coordinates startTree[1000]={start};
	coordinates endTree[1000]={end}; 
	return makePath(startTree,1,endTree,1);
}
int makepath(coordinates t1[1000],int size1, coordinates t2[1000],int size2)
{
	srand(getpid());
	coordinates qRandom;
	qRandom.x=rand()%img.rows;
	qRandom.y=rand()%img.cols;
	min=
	for(i=0;i<size1;i++)
	{
		i
	
		












void main()
{
	
