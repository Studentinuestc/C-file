#define max 20
typedef struct ArcCell
{
    int adj;
    char *info;
}ArcCell,AdjMatrix[max][max];

typedef struct
{
    char vers[max];
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph_L;

typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
    int weight;
}arcnode;

typedef struct vnode
{
    int data;
    arcnode *firstarc;
}vnode,adjlist;

typedef struct
{
    adjlist vertices[max];
    int vexnum,arcnum;
}algraph;

typedef struct edge
{
    int tailvertex;
    int headvertex;
    struct edge *hlink;
    struct edge *tlink;
    char *info;
}Edge;

typedef struct vertex
{
    int vertex;
    struct edge *firstin;
    struct edge *firstout;
}Node;

typedef struct Node* Graph;

typedef struct edge
{
    int mark;
    int ivertex;
    int jvertex;
    struct edge* ilink;
    struct edge* jlink;
}Edge;

typedef struct vertex
{
    int vertex;
    struct edge* edge;
}Node;

typedef struct Node* Graph;
