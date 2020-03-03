#pragma once
#include <vector>
#include "math/vect3d.h"

struct Face
{
	std::vector<int> points;//size = 4
	std::vector<int> edges; //size = 4
};

struct Edge
{
	std::vector<int> points; //size = 2
	std::vector<int> neighbor_faces; //size = 2
};

struct Vertex
{
	Vect3d pos;
	std::vector<int> faces;
	std::vector<int> edges;
};


class QuadrilateralMesh
{
public:
	std::vector<Vertex> Vertices;
	std::vector<Face> Faces;
	std::vector<Edge> Edges;

	QuadrilateralMesh(std::vector<Vect3d> pos_list, std::vector<std::vector<int> > faces_list);
	QuadrilateralMesh(std::vector<Vect3d> pos_list, std::vector<std::vector<int> > edges_list, bool edge_sign);

private:
	int findEdge(int p0, int p1);
};

