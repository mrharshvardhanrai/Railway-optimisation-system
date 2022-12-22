#include <stdio.h>
#include <limits.h>
#include<string.h>
#define V 37



int key_gen(char [],int [][V]);
void read(int [][V]);
void read();



char city[37][20]={
"AMRITSAR",
"BANGALORE",
"BHUBANESWAR",
"CHENNAI",
"CHANDIGARH"	,
"DELHI"	,
"DEHRADUN",
"DARJEELING"	,
"GANDHINAGAR"	,
"GOA"	,
"GUWAHATI",
"GWALIOR"	,
"HYDERABAD",
"INDORE"	,
"JAMMU"	,
"JAIPUR"	,
"KATHMANDHU",
"KATRA"	,
"KOTA"	,
"KOLKATA"	,
"LUCKNOW"	,
"MATHURA"	,
"MUMBAI"	,
"MYSORE"	,
"MIRZAPUR",
"PATNA"	,
"PUNE"	,
"RANCHI"	,
"RAMESHWARAM"	,
"SURAT"	,
"SHIRIDI"	,
"TIRUVANANTHAPURAM"	,
"UDAIPUR"	,
"VARANASI",
"VELLORE"	,
"VIZAG"	,
"VIJAYAWADA"
};




int minDistance(int dist[],
				int sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == 0 &&
				dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}



void printPath(int parent[], int j)
{

	// Base Case : If j is source
	if (parent[j] == - 1)
		return;

	printPath(parent, parent[j]);

	printf("- %s ", city[j]);

}





int printSolution(int dist[], int n,
					int parent[], int src, int i)
{


		printf("\n%s -> %s \t\t %d\t\t%s ",
					city[src], city[i], dist[i], city[src]);
		printPath(parent, i);

}





void dijkstra(int graph[V][V], int src, int i)
{


	int dist[V];


	int sptSet[V];


	int parent[V];
    parent[src] = -1;

	for (int i = 0; i < V; i++)
	{

		dist[i] = INT_MAX;
		sptSet[i] = 0;
	}


	dist[src] = 0;


	for (int count = 0; count < V - 1; count++)
	{

		int u = minDistance(dist, sptSet);


		sptSet[u] = 1;


		for (int v = 0; v < V; v++)


			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}


	printSolution(dist, V, parent, src, i);
}



int main()
{

	int graph[V][V] = {{ 0, 0, 0, 0, 0, 402, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 722, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 0, 0, 735, 1411, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 433, 0, 0, 627, 0, 0, 125, 0, 0},
{ 0, 0, 0, 0, 0, 238, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 402, 0, 0, 0, 238, 0, 0, 0, 754, 0, 0, 282, 0, 0, 0, 147, 0, 0, 0, 0, 0, 0, 1150, 0, 0, 852, 0, 1300, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 127, 0, 0, 0, 0, 0, 1633, 0, 0, 0, 400, 0, 766, 417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0, 0, 0, 0, 0, 0, 0, 457, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 754, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 0, 0, 184, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0, 0, 0, 0, 0, 0, 823, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 1633, 344, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 282, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 500, 840, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 562, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 357, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 332, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 766, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 152, 0, 0, 0, 0, 0, 417, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 722, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 457, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 468, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 445, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 584, 0, 0, 0},
{ 0, 0, 0, 0, 0, 1150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 236, 184, 0, 0, 0, 0, 0, 0},
{ 0, 127, 0, 0, 0, 0, 0, 0, 0, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 468, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 0, 0, 215, 0, 0, 0},
{ 0, 733, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 502, 0, 0, 0, 0, 0, 0, 404, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 153, 0, 0, 0, 0, 0, 0},
{ 0, 1411, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 357, 0, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0, 0, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 627, 0, 0, 0, 0, 0, 823, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0, 0, 0, 0, 0, 332, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 584, 0, 0, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 697, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 697, 0, 312},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 312, 0}
};






int choice,done=0;
while(!done)
    {
   read(graph);
   printf("\n DO you wish to continue(1/0)\n");

   scanf("%d",&choice);
   if (choice==0)
    break;
    }

    return 0;

    }




void read(int graph[][V])

{



   int src, i, ans, via;


   char source[V],DEST[V],VIA[V];

   printf("ENTER SOURCE STATION(CAPITAL LETTER ONLY)\n");
   scanf("%s",source);
   src=key_gen(source,graph);

    printf("ENTER DESTINATION STATION(CAPITAL LETTER ONLY)\n");
    scanf("%s",DEST);
    i=key_gen(DEST,graph);

    printf("Do you want to take a detour/Via ? (1/0)\n");
    scanf("%d",&ans);
    if(ans==1)
    {

    printf("Via ? \n");
    scanf("%s",VIA);
    via=key_gen(VIA,graph);

	dijkstra(graph, src, via);
    dijkstra(graph, via, i);


    }

    else
    {
    dijkstra(graph,src,i);
    }
}



    int key_gen(char name[V],int graph[][V])
    {

        int i,q=0;
        int temp=-99;
        for(i=0;i<V;i++)
        {


            if(strcmp(city[i],name)==0)
        {

            printf("%d\n",i);
            temp=i;
            q+=1;

        }



    }

    if (q==0)

    {
        printf("wrong input check your spelling\n");
        
        read(graph);




return 0;

    }

    return (temp);
    }
