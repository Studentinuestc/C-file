typedef struct BiThrNode
{
    int data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    byte LTag;
    byte RTag;
}BiThrNode,*BiThrTree;

int InOrderThread(BiThrTree *head,BiThrTree bt);
void InThreading(BiThrTree p);
BiThrTree InPreNode(BiThrNode p);
BiThrTree InPostNode(BiThrTree p);
