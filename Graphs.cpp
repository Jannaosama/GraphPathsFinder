
#include <iostream>
#include <fstream>		
#include <vector>
#include <string>		
#include <iomanip>
#include <string>
#include "Edge.h"
#include <limits.h>	// Deinition of an Edge given in the assignmnet 

using namespace std;
ofstream y("output.txt");
// Constructor
Graphs::Graphs()
{
	E = V = order = 0;
}

// Destructor
Graphs::~Graphs()
{
}


// The number of the Map vertex (0,1,2,..) to (A,B,C,..)
char Graphs::VertexName(const int s) const
{
	return char(s + 65);
}

// Get Graph from text File (file name is stored in string fname) and store it in  in adjacency matrix

void Graphs::getGraph(string fname)
{
	// Local data ...
	weightType weight;
	ifstream source;
	source.open(fname.c_str());
	vector<vector<string>>Vector;
	string line;
	while (getline(source, line))
	{
		stringstream inputString(line);
		vector<string>ve;
		string x;
		while (getline(inputString, x, ',')) {
			ve.push_back(x);
		}
		Vector.push_back(ve);
		ve.clear();

	}
	for (int i = 2; i < Vector.size(); i++)
	{
		for (int j = 1; j < Vector[0].size(); j++)
		{

			Vector[i][j].erase(0, 1);
			Vector[i][j].erase(Vector[i][j].length() - 1, 1);
			int d = stoi(Vector[i][j]);
			AdjMatrix[i - 2][j - 1] = d;
		}

	}

	V = Vector.size() - 2;
	GetEdges();
}

void Graphs::DisplayAdjecencyMatrix() const
{
	int i, j;
	y << "Adjacency Matrix\n";
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
			y << setw(3) << AdjMatrix[i][j] << " ";
		y << endl;
	}
}
//We store all the non-zero edges from the adjecency matrix into an array
void Graphs::GetEdges()
{
	int r, c;
	int i = 0;
	weightType weight;

	// Calculates the diagonals weights
	for (r = 0; r <= V - 2; r++)
		for (c = r + 1; c <= V - 1; c++)
		{
			weight = AdjMatrix[r][c];
			if (weight > 0)
			{
				// Copy (r,c,weight) in the edgeslist[i]
				edges[i].u = r;
				edges[i].v = c;
				edges[i].w = weight;
				i++;
			}
		}

	E = i;		// Number of non-zero edges

}

// Get number of vertices (V)	
int Graphs::NumberOfVertices() const
{
	y << "The number of verticies is " << V << "\n";
	return V;
}

// Get Number of Non-zero edges (E)
int Graphs::NumberOfEdges() const
{
	y << "The number of edges is " << E << "\n";
	return E;
}

// Output an edge (e): Vertex names and weight
void Graphs::printEdge(Edge e) const
{
	y << VertexName(e.u) << " " << VertexName(e.v) << " " << e.w << endl;
}

// Display Graph Edges
void Graphs::DisplayEdges() const
{
	y << "Graph Edges\n";
	for (int i = 0; i < E; i++)
		printEdge(edges[i]);
}

// Shortest paths from node s
// uses Dijkstra's Algorithm
void Graphs::ShortestPath(int src)
{
	vector<int>Distance(V); // The algorithm sorts out the shortest distnace

	//bool condition to check if the vertex in the current node is the shortest in distance from the source 
	bool proceeded[V];

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		Distance[i] = INT_MAX, proceeded[i] = false;

	// Distance of source vertex from itself is always 0 because the element - itself is always zero
	Distance[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		//We choose the nearest unprocessed node from the source node which is originally the first source node in the first interation which is the first node to be processed
		int u = minDistance(Distance, proceeded);

		//Flag the vertices as processed
		proceeded[u] = true;

		// This function is for updating the value of the distance of the picked adjecent vertices 
		for (int v = 0; v < V; v++)
		{
			string s;

			//The distance will be updated if the newer distance is smaller than the older one or if it was not precessesd
			if (!proceeded[v] && AdjMatrix[u][v]
				&& Distance[u] != INT_MAX
				&& Distance[u] + AdjMatrix[u][v] < Distance[v])
			{
				Distance[v] = Distance[u] + AdjMatrix[u][v];
				via[v] = u;
			}
		}
	}


	printSolution(Distance, src);

}

// Print path of the vertex "v" from source "s" to destination "i"
void Graphs::PrintPathSourceToDestination(int s, int i) const
{
	if (i == s) { y << VertexName(s); }
	else {
		PrintPathSourceToDestination(s, via[i]);y << VertexName(i);
	}
}

void Graphs::VisitNode(int k)
{
	val[k] = ++order;
	for (int i = 0; i < V; i++)
	{
		if (AdjMatrix[k][i] != 0) {
			if (val[i] == -2)
			{
				VisitNode(i);
			}
		}


	}

}

// Depth First Search Traversal
void Graphs::DFS_Algorithm()
{
	int h;
	for (h = 0; h < V; h++)
	{
		val[h] = -2;
	}
	for (h = 0; h < V; h++)
	{
		if (val[h] == -2) { VisitNode(h); }
	}

}
int Graphs::minDistance(vector<int>dist, bool proceeded[])
{

	// Initialize min value
	int min = INT_MAX, MinimumIndex;

	for (int v = 0; v < V; v++)
		if (proceeded[v] == false && dist[v] <= min)
			min = dist[v], MinimumIndex = v;

	return MinimumIndex;
}
void  Graphs::printSolution(vector<int>dist, int src)
{
	y << "The Distance of the vertex from the Source path is: " << endl;
	for (int i = 0; i < V; i++)
	{
		char c = i + 65;
		y << c << " \t\t" << dist[i] << "\t\t  ";
		PrintPathSourceToDestination(src, i);y << "\n";
	}
}
void Graphs::Show_DFS() {
	for (int i = 0; i < V; i++)
	{
		char c = 65 + i;
		y << c << "is the " << val[i] << "vertix is visted successfully " << "\n";
	}

}