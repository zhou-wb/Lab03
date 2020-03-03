#include "QuadrilateralMesh.h"

QuadrilateralMesh::QuadrilateralMesh(std::vector<Vect3d> pos_list, std::vector<std::vector<int> > faces_list)
{
	Vertices.resize(pos_list.size());
	for (unsigned int i=0; i<pos_list.size(); i++)
	{
		Vertices[i].pos = pos_list[i];
	}

	Faces.resize(faces_list.size());
	for (unsigned int i =0; i<faces_list.size(); i++)
	{
		Faces[i].points = faces_list[i];

		for (unsigned int j=0; j<Faces[i].points.size(); j++)
		{
			Vertices[Faces[i].points[j]].faces.push_back(i);

			
			int edge_id = findEdge(Faces[i].points[j], Faces[i].points[(j + 1) % Faces[i].points.size()]);
			if (edge_id == -1)
			{
				Edge edge;
				edge.points.push_back(Faces[i].points[j]);
				edge.points.push_back(Faces[i].points[(j + 1) % Faces[i].points.size()]);
				edge.neighbor_faces.push_back(i);

				Edges.push_back(edge);

				Faces[i].edges.push_back(Edges.size() - 1);
			}
			else
			{
				Edges[edge_id].neighbor_faces.push_back(i);
				Faces[i].edges.push_back(edge_id);
			}
		}		
	}

	for (int i=0; i<Edges.size(); i++)
	{
		int vert_id0 = Edges[i].points[0];
		int vert_id1 = Edges[i].points[1];

		Vertices[vert_id0].edges.push_back(i);
		Vertices[vert_id1].edges.push_back(i);
	}
}

int QuadrilateralMesh::findEdge(int p0, int p1)
{
	for (int i=0; i<Edges.size(); i++)
	{
		if (p0 == Edges[i].points[0] && p1 == Edges[i].points[1])
			return i;
		if (p0 == Edges[i].points[1] && p1 == Edges[i].points[0])
			return i;
	}
	return -1;
}


QuadrilateralMesh::QuadrilateralMesh(std::vector<Vect3d> pos_list, std::vector<std::vector<int> > edges_list, bool edge_sign)
{

}