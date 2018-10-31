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
/*void makeblock(Point begin )
{	
	int i,j;
	for(i=begin.x;i<16;i++)
		for(j=begin.y;j<16;j++)
			img.at<Vec3b>(i,j)=(255,255,255);
}
int isvalid( int i, int j)
{
	 if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else
		return 0;
}*/
struct rrtnode
{ 
   Point value; 
   rrtnode *parent; 
};
vector <rrtnode*> nodeset;	//set of pointers to nodes
Point insidemax(Point a,Point b)
{
	Point c; 
	if(a.x<b.x)
	{	
		c.x=a.x+floor(MAX*cos(atan((float)(b.y-a.y)/(b.x-a.x))));	
		c.y=a.y+floor(MAX*sin(atan((float)(b.y-a.y)/(b.x-a.x))));
		cout<<"downleft"<<endl<<endl;
	}
	else
	{	
		c.x=a.x-floor(MAX*cos(atan((float)(b.y-a.y)/(b.x-a.x))));	
		c.y=a.y-floor(MAX*sin(atan((float)(b.y-a.y)/(b.x-a.x))));
		cout<<"topright"<<endl<<endl;
	}
	return c;
}
void colour(Point P,int B, int G, int R,int size)
{
	int i,j;
	for(i=0;i<size;i++)
			for(j=0;j<size;j++)
					img.at<Vec3b>(j+P.y,i+P.x)={B,G,R};
}
int main()
{
	//start
	rrtnode start,end,nearest,randomnode,realrandom;
	rrtnode *temp,*disp;
	int i,j;
	srand(getpid());
	start.value.x=20;
	start.value.y=20;
	start.parent=NULL;
	colour(start.value,0,255,0,3);
	end.value.x=300;
	end.value.y=300;
	end.parent=NULL;
	realrandom.parent=NULL;
	colour(end.value,255,0,0,3);
	nodeset.push_back(&start);
	while(1)
	{

		//random()
		temp=new rrtnode;
		temp->parent=NULL;
		randomnode.value.x=rand()%360+20;
		randomnode.value.y=rand()%360+20;
		randomnode.parent=NULL;
		nearest=start;
		realrandom.parent=&start;
		for(i=0;i<nodeset.size();i++)
		{	
			if((pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))>(pow((randomnode.value.x-nodeset[i]->value.x),2)+pow((randomnode.value.y-nodeset[i]->value.y),2)))
			{		
				nearest=*nodeset[i];
				realrandom.parent=nodeset[i];
			}
		}	
		if((pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))<MAX2)
		{
			realrandom.value=randomnode.value;
		}
		else
		{
			realrandom.value=insidemax(nearest.value,randomnode.value);
		}
		*temp=realrandom;
		cout<<"temp.parent :"<<temp->parent<<endl;
		cout<<"temp:"<<temp<<endl<<"____________________________"<<endl;
		nodeset.push_back(temp);
		line(img,nearest.value,realrandom.value,{0,0,255},1);
		colour(realrandom.value,255,255,255,2);
		if((pow((realrandom.value.x-end.value.x),2)+pow((realrandom.value.y-end.value.y),2))<MAX2)
		{
			end.parent=nodeset[nodeset.size()-1];
			line(img,end.value,realrandom.value,{0,0,255},1);
			cout<<"path found"<<endl<<endl<<endl<<endl<<endl;
			cout<<"end.parent : "<<end.parent<<endl;
			namedWindow("win1",WINDOW_NORMAL);
			imshow("win1",img);
			waitKey(1000);
			break;

		}
		namedWindow("win1",WINDOW_NORMAL);
		imshow("win1",img);
		waitKey(1);
	}
	disp=&end;
	while(disp!=&start)
	{
		line(img,disp->value,disp->parent->value,{255,255,255},2);
		disp=disp->parent;
		cout<<"loop running"<<endl;
		waitKey(1);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img);
	}
	cout<<"LOOP END BOIS";
	namedWindow("rrtpath",WINDOW_NORMAL);
	imshow("rrtpath",img);
	waitKey(0);
	return 0;
}

 

