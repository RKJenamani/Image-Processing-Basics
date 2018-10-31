#define MAX 20
#define MAX2 400
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
void makeblock(int x, int y ,int X,int Y)
{	
	int i,j;
	for(i=0;i<X;i++)
		for(j=0;j<Y;j++)
			img.at<Vec3b>(x+i,y+j)={255,255,255};
}
int path_finder(Point pt1,Point pt2)
{
	LineIterator it(img, pt1, pt2, 8);
	vector<Vec3b> buff(it.count);
	for(int i = 0; i < it.count; i++, ++it)
	{
   		 buff[i] = (const Vec3b)*it;cout<<buff[i];

   		 if(buff[i][0]==255 && buff[i][1]==255 && buff[i][2]==255)
   		 {
   		 	cout<<"000000000000000000000000000000000000000"<<endl;
   		 	return 0;
   		 }
   		 	
   		    	
	}
	cout<<"111111111111111111111111111111111111"<<endl;
	waitKey(1);
	return 1;
}
struct rrtnode_s
{ 
   Point value_s; 
   rrtnode_s *parent_s; 
};
struct rrtnode_e
{ 
   Point value_e; 
   rrtnode_e *parent_e; 
};
vector <rrtnode_s*> nodeset_s;	//set of pointers to nodes
vector <rrtnode_e*> nodeset_e;
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
	rrtnode_s start,nearest_s,randomnode_s,realrandom_s;
	rrtnode_e end,nearest_e,randomnode_e,realrandom_e;
	rrtnode_s *temp_s,*disp_s;
	rrtnode_e *temp_e,*disp_e;
	int i,j,p=1;
	makeblock(100,100,50,90);
	makeblock(200,190,120,60);
	makeblock(120,320,60,70);
	srand(getpid());
	start.value_s.x=20;
	start.value_s.y=20;
	start.parent_s=NULL;
	colour(start.value_s,0,255,0,6);
	end.value_e.x=300;
	end.value_e.y=300;
	end.parent_e=NULL;
	realrandom_s.parent_s=NULL;
	realrandom_e.parent_e=NULL;
	colour(end.value_e,255,0,0,6);
	nodeset_s.push_back(&start);
	nodeset_e.push_back(&end);
	while(p)
	{

		//start tree
		startiteration:
		temp_s=new rrtnode_s;
		temp_s->parent_s=NULL;
		randomnode_s.value_s.x=rand()%360+20;
		randomnode_s.value_s.y=rand()%360+20;
		randomnode_s.parent_s=NULL;
		nearest_s=start;
		realrandom_s.parent_s=&start;
		for(i=0;i<nodeset_s.size();i++)
		{	
			if((pow((nearest_s.value_s.x-randomnode_s.value_s.x),2)+pow((nearest_s.value_s.y-randomnode_s.value_s.y),2))>(pow((randomnode_s.value_s.x-nodeset_s[i]->value_s.x),2)+pow((randomnode_s.value_s.y-nodeset_s[i]->value_s.y),2)))
			{		
				nearest_s=*nodeset_s[i];
				realrandom_s.parent_s=nodeset_s[i];
			}
		}	
		if((pow((nearest_s.value_s.x-randomnode_s.value_s.x),2)+pow((nearest_s.value_s.y-randomnode_s.value_s.y),2))<MAX2)
		{
			realrandom_s.value_s=randomnode_s.value_s;
		}
		else
		{
			realrandom_s.value_s=insidemax(nearest_s.value_s,randomnode_s.value_s);
			cout<<"K";
		}
		if(path_finder(realrandom_s.value_s,nearest_s.value_s)==1)
		{
			*temp_s=realrandom_s;
			cout<<"temp.parent :"<<temp_s->parent_s<<endl;
			cout<<"temp:"<<temp_s<<endl<<"____________________________"<<endl;
			nodeset_s.push_back(temp_s);
			line(img,nearest_s.value_s,realrandom_s.value_s,{0,0,255},1);
			colour(realrandom_s.value_s,0,255,255,2);
		}
		else goto startiteration;
		//else cout<<"-----111111--------"<<endl;
		//else continue;
		//end node;
		enditeration:
		temp_e=new rrtnode_e;
		temp_e->parent_e=NULL;
		randomnode_e.value_e.x=rand()%360+20;
		randomnode_e.value_e.y=rand()%360+20;
		randomnode_e.parent_e=NULL;
		nearest_e=end;
		realrandom_e.parent_e=&end;
		for(i=0;i<nodeset_e.size();i++)
		{	
			if((pow((nearest_e.value_e.x-randomnode_e.value_e.x),2)+pow((nearest_e.value_e.y-randomnode_e.value_e.y),2))>(pow((randomnode_e.value_e.x-nodeset_e[i]->value_e.x),2)+pow((randomnode_e.value_e.y-nodeset_e[i]->value_e.y),2)))
			{		
				nearest_e=*nodeset_e[i];
				realrandom_e.parent_e=nodeset_e[i];
			}
		}	
		if((pow((nearest_e.value_e.x-randomnode_e.value_e.x),2)+pow((nearest_e.value_e.y-randomnode_e.value_e.y),2))<MAX2)
		{
			realrandom_e.value_e=randomnode_e.value_e;
		}
		else
		{
			realrandom_e.value_e=insidemax(nearest_e.value_e,randomnode_e.value_e);
		}
		if(path_finder(realrandom_e.value_e,nearest_e.value_e)==1)
		{
			*temp_e=realrandom_e;
			cout<<"temp.parent :"<<temp_e->parent_e<<endl;
			cout<<"temp:"<<temp_e<<endl<<"____________________________"<<endl;
			nodeset_e.push_back(temp_e);
			line(img,nearest_e.value_e,realrandom_e.value_e,{0,0,255},1);
			colour(realrandom_e.value_e,0,255,255,2);
		}
		else goto enditeration;
		
		//check for end
		for(i=0;i<nodeset_s.size();i++)
			for(j=0;j<nodeset_e.size();j++) 
				if((pow((nodeset_e[i]->value_e.x-nodeset_s[j]->value_s.x),2)+pow((nodeset_e[i]->value_e.y-nodeset_s[j]->value_s.y),2))<MAX2)
				{
					disp_s=nodeset_s[j];
					disp_e=nodeset_e[i];
					line(img,nodeset_s[j]->value_s,nodeset_e[i]->value_e,{0,255,0},2);
					//cout<<"path found"<<endl<<endl<<endl<<endl<<endl;
					//cout<<"end.parent : "<<end.parent<<endl;
					p=0;//exits from loop

				}
		namedWindow("win1",WINDOW_NORMAL);
		imshow("win1",img);
		waitKey(1);
		cout<<endl<<"next iteration "<<endl;
	}
	while(disp_s!=&start || disp_e!=&end)
	{
		if(disp_s!=&start)
		{
			line(img,disp_s->value_s,disp_s->parent_s->value_s,{255,255,255},2);
			disp_s=disp_s->parent_s;
		}
		if(disp_e!=&end)
		{
			line(img,disp_e->value_e,disp_e->parent_e->value_e,{255,255,255},2);
			disp_e=disp_e->parent_e;
		}
		cout<<"loop running"<<endl;
		waitKey(100);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img);
	}
	/*while(disp_e!=&end)
	{
		line(img,disp_e->value_e,disp_e->parent_e->value_e,{255,255,255},2);
		disp_e=disp_e->parent_e;
		cout<<"loop running"<<endl;
		waitKey(100);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img);
	}*/
	cout<<"LOOP END BOIS";
	namedWindow("rrtpath",WINDOW_NORMAL);
	imshow("rrtpath",img);
	waitKey(0);
	return 0;
}

 

