# Dijkstra SSP
 Dijkstra SSP for a weighted directed graph with non-negative weights utilising a heap.
 Time Complexity is optimized to O((|V| + |E|)log|V|)

 The sample input file is a follows:

 The first line of the input file contains an integer, n, indicating the number of vertices
 of the input graph.

 Each of the remaining lines contains a triple ”i j w”, where 1 ≤ i, j ≤ n, indicating an
 edge from vertex i to vertex j with cost w.

 Vertex 1 is used as the source.

 The output of my program is as follows:

 The printed adjacency list in a reasonable format with each edge along with its weight

 The shortest path tree edges with shortest path weights, the edges are listed in order 
 in which they are produced by the algorithm. For each shortest path tree 

 For each shortest path tree edge (i, j), i have printed “(i, j) : w” in a separate line, where w is the 
 shortest path weight from the source to vertex j.

 the code can be ran after compiling with "./dssp input.txt"