typedef struct BiTreeNode
{
    int data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode, *BiTree;

void PreOrder(BiTree bt);
void InOrder(BiTree bt);
void PostOrder(BiTree bt);
void LevelOrder(BiTree bt);
void NRInOrder(BiTree bt);
void PreInOrd(char preord[],char inord[],int i,int j,int k,int h,BiTree *t);
void CreateBiTree(char preord[],char inord[],int n,BiTree root);
int BitreeLeaf(BiTree bt);
int BitreeDepth(BiTree bt); 
//a树的宽度
