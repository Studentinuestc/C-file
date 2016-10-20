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
