typedef struct AVLNode
{
    DataType data;
    int bf;
    struct AVLNode *lchild;
    struct AVLNode *rchild;
}AVLNode, *AVLTree;

#define LH 1
#define EH 0
#define RH -1

void L_Rotate(AVLNode **p);
void R_Rotate(AVLNode **p);
void LeftBalance(AVLNode **p);
void RightBalance(AVLNode **p);
int InsertAVL(AVLNode **t,DataType e,bool *taller);
