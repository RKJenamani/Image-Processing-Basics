#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat img=imread("Lenna.png",0);
namedWindow("nice",WINDOW_NORMAL);
int distance[100][100];
int set[100][100];
struct vertex
{
	int x;
	int y;
}
int empty(int a[][])
{
	lol=1;
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			if(a[i][j]==0)
				lol=0;
		}
	return lol;
}
void Dijkstra(vertex source)
{
	vertex min;
	dist[source.x,source.y]= 0;                     // Distance from source to source is set to 0
	for (i=0;i<img.rows;i++)// Initializations
		for(j=0;j<img.cols;j++)
			if( source.x!=i && source.y!=j)
				dist[i][j]=10000;// Unknown distance function from source to each node set to infinity
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
		{
			set[i][j]=0;  // All nodes initially in Q
		}
			
          while (empty(set)==0)                // The main loop
          {
		min=source;
		for(i=0;i<img.rows;i++)
			for(j=0;j<img.cols;j++)
			{
				if(set[i][j]==0)
				{
					if(distance[i][j]<mindistance)
					{
						
				
			}
			
v := vertex in Q with min dist[v]  // In the first run-through, this vertex is the source node
          remove v from Q 

          for each neighbor u of v:           // where neighbor u has not yet been removed from Q.
              alt := dist[v] + length(v, u)
              if alt < dist[u]:               // A shorter path to u has been found
                  dist[u]  := alt            // Update distance of u 

      return dist[]
  end function

}

