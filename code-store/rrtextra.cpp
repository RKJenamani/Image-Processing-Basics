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
void makeblock(int x, int y ,int X,int Y)
{	
	int i,j;
	for(i=0;i<X;i++)
		for(j=0;j<Y;j++)
			img.at<Vec3b>(x+i,y+j)={255,255,255};
}
int isvalid( int i, int j)
{
	 if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else
		return 0;
}
int path_finder(Point pt1,Point pt2)
{
	LineIterator it(img, pt1, pt2, 8);
	vector<Vec3b> buff(it.count);
	for(int i = 0; i < it.count; i++, ++it)
	{
   		 buff[i] = (const Vec3b)*it;
   		 if(buff[i][0]==255 && buff[i][1]==255 && buff[i][2]==255)
   		 {
   		 	///cout<<"000000000000000000000000000000000000000"<<endl;
   		 	return 0;
   		 }
   		 	
   		 cout<<buff[i];
   	
	}
	//cout<<"111111111111111111111111111111111111"<<endl;
	return 1;
}
struct rrtnode
{ 
   Point value; 
   rrtnode *parent; 
};
vector <rrtnode*> nodeset;	//setofnodes
//vector <rrtnode> :: iterator it;
//int distance(rrtnode a, rrtnode b)
//{
//	return (pow((a.value.x-b.value.x),2)+pow((a.value.y-b.value.y),2));
//}
Point insidemax(Point a,Point b)
{
	Point c;
//	if ((((float)(b.y-a.y)/(b.x-a.x)))>0)
//	{   
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
//	cout<<"(b.y-a.y)/(b.x-a.x))) :"<<(float)(b.y-a.y)/(b.x-a.x)<<endl;
//	cout<<"atan((b.y-a.y)/(b.x-a.x)))  :"<<atan((float)(b.y-a.y)/(b.x-a.x))<<endl;
//	cout<<"floor(MAX COS )= "<<floor(MAX*cos(atan((float)(b.y-a.y)/(b.x-a.x))));
//	cout<<"floor (MAX SIN )= "<<floor(MAX*sin(atan((float)(b.y-a.y)/(b.x-a.x))));
//	}
	
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
	makeblock(100,100,40,60);
	makeblock(200,170,60,30);
	makeblock(120,300,50,70);
	/*for(i=0;i<40;i++)
		for(j=0;j<40;j++)
			img.at<Vec3b>(100+i,100+j)={255,255,255};
	for(i=0;i<40;i++)
		for(j=0;j<60;j++)
			img.at<Vec3b>(200+i,170+j)={255,255,255};*/
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
//cout<<"vector nodes :";
		for(i=0;i<nodeset.size();i++)
		{	
				//cout<<"RANDOM NODE : "<<randomnode.value<<endl;
				//if(distance(nearest,randomnode)<distance(randomnode,*it))
				//cout<<(pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))<<endl;
				//cout<<(pow((randomnode.value.x-nodeset[i]->value.x),2)+pow((randomnode.value.y-nodeset[i]->value.y),2))<<endl;
				if((pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))>(pow((randomnode.value.x-nodeset[i]->value.x),2)+pow((randomnode.value.y-nodeset[i]->value.y),2)))
				{		
					nearest=*nodeset[i];
					realrandom.parent=nodeset[i];
					//cout<<&(*it)<<"---------------";

				}//cout<<&(*it)<<"---------------"<<endl;
			//	cout<<" Size of nodeset"<<nodeset.size()<<endl;
		}
		
		//cout<<endl<<"----------"<<endl<<(pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))<<endl<<"---------------"<<endl;
			
		if((pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))<MAX2)
		{
			//cout<<endl<<"----------"<<endl<<(pow((nearest.value.x-randomnode.value.x),2)+pow((nearest.value.y-randomnode.value.y),2))<<endl<<"---------------"<<endl;
			realrandom.value=randomnode.value;
		}
		else
		{
			realrandom.value=insidemax(nearest.value,randomnode.value);
			//cout<<insidemax(nearest.value,randomnode.value)<<"<- insidemax"<<endl;
		}
//		for(i=0;i<2;i++)
//			for(j=0;j<2;j++)
//					img.at<Vec3b>(j+randomnode.value.y,i+randomnode.value.x)={255,0,0};
		if(path_finder(realrandom.value,nearest.value)==1)
		{
		*temp=realrandom;
		//realrandom.parent=&nearest;
		cout<<"temp.parent :"<<temp->parent<<endl;
		cout<<"temp:"<<temp<<endl<<"____________________________"<<endl;
		nodeset.push_back(temp);
		line(img,nearest.value,realrandom.value,{0,0,255},1);
		//cout<<"Realrandom X:"<<realrandom.value.x<< " Y:"<<realrandom.value.y<<endl;
		//for(i=0;i<2;i++)
		//	for(j=0;j<2;j++)
		//			img.at<Vec3b>(j+randomnode.value.y,i+randomnode.value.x)={255,0,0};
		colour(realrandom.value,255,255,0,2);
		//cout<<"lololol";
		}
		else
		{
			continue;
		}
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
	//draw path
	disp=&end;
	while(disp!=&start)
	{
		line(img,disp->value,disp->parent->value,{255,255,255},2);
		
		cout<<disp<<"--------";//cout<<"temp->parent= : "<<temp->parent<<"---------temp->parent->parent"<<temp->parent->parent<<endl<<"-iiiii";
		disp=disp->parent;
		//cout<<temp->parent<<endl;
		cout<<"loop running"<<endl;
		waitKey(1);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img);
	}
	cout<<"LOOP END BOIS";
	waitKey(0);
	namedWindow("wint",WINDOW_NORMAL);
		imshow("wint",img);
	return 0;
}

 

