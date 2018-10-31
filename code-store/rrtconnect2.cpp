#define MAX 100
#define MAX2 10000
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
Mat img(4000,4000,CV_8UC3,Scalar(0,0,0));
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
struct rrtnode_e2
{ 
   Point value_e2; 
   rrtnode_e2 *parent_e2; 
};
rrtnode_e end;
rrtnode_e2 end2;
vector <rrtnode_s*> nodeset_s;	//set of pointers to nodes
vector <rrtnode_e*> nodeset_e;	//end point 1;
vector <rrtnode_e2*> nodeset_e2;
void makeblock(int x, int y ,int X,int Y)
{	
	int i,j;
	for(i=0;i<X;i++)
		for(j=0;j<Y;j++)
			img.at<Vec3b>(x+i,y+j)={255,255,255};
	for(i=-100;i<X+100;i++)
		for(j=-100;j<0;j++)
			img.at<Vec3b>(x+i,y+j)={50,50,50};
	for(i=-100;i<X+100;i++)
		for(j=Y;j<Y+100;j++)
			img.at<Vec3b>(x+i,y+j)={50,50,50};
	for(i=-100;i<0;i++)
		for(j=-100;j<Y+100;j++)
			img.at<Vec3b>(x+i,y+j)={50,50,50};
	for(i=X;i<X+100;i++)
		for(j=-100;j<Y+100;j++)
			img.at<Vec3b>(x+i,y+j)={50,50,50};
}
int path_finder(Point pt1,Point pt2)
{
	LineIterator it(img, pt1, pt2, 8);
	vector<Vec3b> buff(it.count);
	for(int i = 0; i < it.count; i++, ++it)
	{
   		 buff[i] = (const Vec3b)*it;
   		 if(buff[i][0]>49 && buff[i][1]>49 && buff[i][2]>49)
   		 	return 0;	    	
	}
	waitKey(1);
	return 1;
}
/*
int path_cross(Point pt1,Point pt2)
{
	LineIterator it(img, pt1, pt2, 8);
	vector<Vec3b> buff(it.count);
	for(int i = 0; i < it.count; i++, ++it)
	{
   		 buff[i] = (const Vec3b)*it;
   		 if(buff[i][0]==0 && buff[i][1]==0 && buff[i][2]==255)
   		 	return 0;	    	
	}
	return 1;
}
*/
Point insidemax(Point a,Point b)
{
	Point c; 
	if(a.x<b.x)
	{	
		c.x=a.x+floor(MAX*cos(atan((float)(b.y-a.y)/(b.x-a.x))));	
		c.y=a.y+floor(MAX*sin(atan((float)(b.y-a.y)/(b.x-a.x))));
	}
	else
	{	
		c.x=a.x-floor(MAX*cos(atan((float)(b.y-a.y)/(b.x-a.x))));	
		c.y=a.y-floor(MAX*sin(atan((float)(b.y-a.y)/(b.x-a.x))));
	}
	return c;
}
void colour(Point P,int B, int G, int R,int size)
{
	int i,j;
	for(i=-size;i<size;i++)
			for(j=-size;j<size;j++)
					img.at<Vec3b>(j+P.y,i+P.x)={B,G,R};
}
void *endtree(void *vargp)
{
	cout<<"THREAD !"<<endl;
	int i;
  	rrtnode_e nearest_e,randomnode_e,realrandom_e;
  	rrtnode_e *temp_e;
  	realrandom_e.parent_e=NULL;
  	enditeration:
		temp_e=new rrtnode_e;
		temp_e->parent_e=NULL;
		randomnode_e.value_e.x=rand()%3600+200;
		randomnode_e.value_e.y=rand()%3600+200;
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
//		if(img.at<Vec3b>(randomnode_e.value_e.x,randomnode_e.value_e.y)[0]==0 && img.at<Vec3b>(randomnode_e.value_e.x,randomnode_e.value_e.y)[1]==0 && img.at<Vec3b>(randomnode_e.value_e.x,randomnode_e.value_e.y)[2]==255)
//			goto enditeration;
		if(path_finder(realrandom_e.value_e,nearest_e.value_e)==1)
		{
			*temp_e=realrandom_e;
			nodeset_e.push_back(temp_e);
			line(img,nearest_e.value_e,realrandom_e.value_e,{0,0,255},3);
			colour(realrandom_e.value_e,0,255,255,10);
		}
		else goto enditeration;
    return NULL;
}
void *endtree2(void *vargp)
{	
	int i;
	rrtnode_e2 nearest_e2,randomnode_e2,realrandom_e2;
	rrtnode_e2 *temp_e2;
	realrandom_e2.parent_e2=NULL;
	end2iteration:
		temp_e2=new rrtnode_e2;
		temp_e2->parent_e2=NULL;
		randomnode_e2.value_e2.x=rand()%3600+200;
		randomnode_e2.value_e2.y=rand()%3600+200;
		randomnode_e2.parent_e2=NULL;
		nearest_e2=end2;
		realrandom_e2.parent_e2=&end2;
		for(i=0;i<nodeset_e2.size();i++)
		{	
			if((pow((nearest_e2.value_e2.x-randomnode_e2.value_e2.x),2)+pow((nearest_e2.value_e2.y-randomnode_e2.value_e2.y),2))>(pow((randomnode_e2.value_e2.x-nodeset_e2[i]->value_e2.x),2)+pow((randomnode_e2.value_e2.y-nodeset_e2[i]->value_e2.y),2)))
			{		
				nearest_e2=*nodeset_e2[i];
				realrandom_e2.parent_e2=nodeset_e2[i];
			}
		}	
		if((pow((nearest_e2.value_e2.x-randomnode_e2.value_e2.x),2)+pow((nearest_e2.value_e2.y-randomnode_e2.value_e2.y),2))<MAX2)
		{
			realrandom_e2.value_e2=randomnode_e2.value_e2;
		}
		else
		{
			realrandom_e2.value_e2=insidemax(nearest_e2.value_e2,randomnode_e2.value_e2);
		}
//		if(img.at<Vec3b>(randomnode_e2.value_e2.x,randomnode_e2.value_e2.y)[0]==0 && img.at<Vec3b>(randomnode_e2.value_e2.x,randomnode_e2.value_e2.y)[1]==0 && img.at<Vec3b>(randomnode_e2.value_e2.x,randomnode_e2.value_e2.y)[2]==255)
//			goto end2iteration;
//		if(path_finder(realrandom_e2.value_e2,nearest_e2.value_e2)==0)
//			goto end2iteration;
		if(path_finder(realrandom_e2.value_e2,nearest_e2.value_e2)==1)
		{
			*temp_e2=realrandom_e2;
			nodeset_e2.push_back(temp_e2);
			line(img,nearest_e2.value_e2,realrandom_e2.value_e2,{0,0,255},3);
			colour(realrandom_e2.value_e2,0,255,255,10);
		}
		else goto end2iteration;
}

int main()
{
	pthread_t tid1, tid2;
	cout<<" program ";
	pthread_create( &tid1, NULL, &endtree, NULL);
				pthread_create( &tid2, NULL, &endtree2, NULL);
	//start
	rrtnode_s start,nearest_s,randomnode_s,realrandom_s;
	rrtnode_s *temp_s,*disp_s, *disp_s2;
	rrtnode_e *disp_e;
	rrtnode_e2 *disp_e2;
	int i,j,p=1,q=1;
	makeblock(1000,1000,500,900);
	makeblock(2000,1900,1200,600);
	makeblock(1200,3200,600,700);
	srand(getpid());
	start.value_s.x=200;
	start.value_s.y=200;
	start.parent_s=NULL;
	colour(start.value_s,0,255,0,30);
	end.value_e.x=3000;
	end.value_e.y=3000;
	end.parent_e=NULL;
	end2.value_e2.x=3000;
	end2.value_e2.y=1000;
	end2.parent_e2=NULL;
	realrandom_s.parent_s=NULL;
	
	colour(end.value_e,255,0,0,30);
	colour(end2.value_e2,255,0,0,30);
	nodeset_s.push_back(&start);
	nodeset_e.push_back(&end);
	nodeset_e2.push_back(&end2);
	while(p || q)
	{

		//start tree
		startiteration:
		temp_s=new rrtnode_s;
		temp_s->parent_s=NULL;
		randomnode_s.value_s.x=rand()%3600+200;
		randomnode_s.value_s.y=rand()%3600+200;
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
		}
		if(img.at<Vec3b>(randomnode_s.value_s.x,randomnode_s.value_s.y)[0]==0 && img.at<Vec3b>(randomnode_s.value_s.x,randomnode_s.value_s.y)[1]==0 && img.at<Vec3b>(randomnode_s.value_s.x,randomnode_s.value_s.y)[2]==255)
			goto startiteration;
//		if(path_cross(realrandom_s.value_s,nearest_s.value_s)==0)
//			goto startiteration;
		if(path_finder(realrandom_s.value_s,nearest_s.value_s)==1)
		{
			*temp_s=realrandom_s;
			nodeset_s.push_back(temp_s);
			line(img,nearest_s.value_s,realrandom_s.value_s,{0,0,255},3);
			colour(realrandom_s.value_s,0,255,255,10);
		}
		else goto startiteration;
		//end node;
		if(p)
		{
			pthread_join(tid1, NULL);
		
		//check for end
		for(i=0;i<nodeset_s.size();i++)
			for(j=0;j<nodeset_e.size();j++) 
				if((pow((nodeset_e[i]->value_e.x-nodeset_s[j]->value_s.x),2)+pow((nodeset_e[i]->value_e.y-nodeset_s[j]->value_s.y),2))<MAX2)
				{
					disp_s=nodeset_s[j];
					disp_e=nodeset_e[i];
					line(img,nodeset_s[j]->value_s,nodeset_e[i]->value_e,{0,255,0},6);
					p=0;//exits from loop

				}
		
		namedWindow("win1",WINDOW_NORMAL);
		imshow("win1",img);
		waitKey(1);
		}
		if(q)
		{

			pthread_join(tid2, NULL);
		
		//check for end
		for(i=0;i<nodeset_s.size();i++)
			for(j=0;j<nodeset_e2.size();j++) 
				if((pow((nodeset_e2[i]->value_e2.x-nodeset_s[j]->value_s.x),2)+pow((nodeset_e2[i]->value_e2.y-nodeset_s[j]->value_s.y),2))<MAX2)
				{
					disp_s2=nodeset_s[j];
					disp_e2=nodeset_e2[i];
					line(img,nodeset_s[j]->value_s,nodeset_e2[i]->value_e2,{0,255,0},6);
					q=0;//exits from loop

				}
		namedWindow("win1",WINDOW_NORMAL);
		imshow("win1",img);
		waitKey(1);
		}

	}
	while(disp_s!=&start || disp_e!=&end)
	{
		if(disp_s!=&start)
		{
			line(img,disp_s->value_s,disp_s->parent_s->value_s,{0,255,255},6);
			disp_s=disp_s->parent_s;rr
		}
		if(disp_e!=&end)
		{
			line(img,disp_e->value_e,disp_e->parent_e->value_e,{0,255,255},6);
			disp_e=disp_e->parent_e;
		}
		waitKey(100);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img);
	}

	while(disp_s2!=&start || disp_e2!=&end2)
	{

		if(disp_s2!=&start)
		{
			line(img,disp_s2->value_s,disp_s2->parent_s->value_s,{255,255,0},6);
			disp_s2=disp_s2->parent_s;
		}
		if(disp_e2!=&end2)
		{
			line(img,disp_e2->value_e2,disp_e2->parent_e2->value_e2,{255,255,0},6);
			disp_e2=disp_e2->parent_e2;
		}
		waitKey(100);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img);
	}
	cout<<"PATH FOUND BOIS";
	namedWindow("rrtpath11",WINDOW_NORMAL);
	imshow("rrtpath",img);
	waitKey(0);
	return 0;
}

 

