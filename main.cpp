#include <bits/stdc++.h>
using namespace std;
 #include"Graphs.h"
 #include"Edge.h"
 #include"Graphs.cpp"
int main() {
 Graphs Graph1; Graphs Graph2;
 Graph1.getGraph("TestG.csv");
Graph1.NumberOfEdges();
Graph1.NumberOfVertices();
Graph1.DisplayAdjecencyMatrix(); 
Graph1.DisplayEdges();
Graph1.ShortestPath(0);
Graph1.DFS_Algorithm();
Graph1.Show_DFS();
Graph2.getGraph("CitiesG.csv");
Graph2.NumberOfEdges();
Graph2.NumberOfVertices();
Graph2.DisplayAdjecencyMatrix(); 
Graph2.DisplayEdges();
Graph2.ShortestPath(0);
Graph2.DFS_Algorithm();
Graph2.Show_DFS();
}

