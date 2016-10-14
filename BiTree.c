void PreOrder(BiTree bt)
{
    if(bt!=null)
    {
        visit(bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

void InOrder(BiTree bt)
{
    if(bt!=null)
    {
        InOrder(bt->lchild);
        visit(bt->data);
        InOrder(bt->rchild);
    }
}

void PostOrder(BiTree bt)
{
    if(bt!=null)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        visit(bt->data);
    }
}

void LevelOrder(BiTree bt)
{
    BiTreeNode Queue[MAXNODE];
    int front,rear;
    if(bt==null)return;
    front=-1;rear=0;
    Queue[rear]=bt;
    while(rear!=front)
    {
        front++;
        visit(Queue[front]->data);
        if(Queue[front]->lchild!=null)
        {
            rear++;
            Queue[rear]=Queue[front]->lchild;
        }
        if(Queue[front]->rchild!=null)
        {
            rear++;
            Queue[rear]=Queue[front]->rchild;
        }
    }
}

void NRInOrder(BiTree bt)
{
    BiTree S[MAXNODE],p=bt;
    int top=-1;
    if(bt==null)return;
    while(!(p==null&&top==0))
    while(p!=null)
    {
    {
        if(top<MAXNODE-1)
        S[top++]=p;
        else{printf("flow\n");return;}
        p=p->lchild;
    }
    if(top==-1)return;
    else
    {
        p=S[--top];
        visit(p->data);
        p=p->rchild;
    }
    }
}

void PreInOrd(char preord[],char inord[],int i,int j,int k,BiTree *t)
{
    int m;
    (*t)=new BiNode;
    (*t)->data=preord[i];
    m=k;
    while(inord[m]!=preord[i])m++;
    if(m==k)(*t)->lchild=null;
    else PreInOrd(preord,inord,i+1,i+m-k,k,m-1,&((*t)->lchild));
    if(m==h)(*t)->rchild=null;
    else PreInOrd(preord,inord,i+m-k+1,j,m+1,h,&((*t)->lchild));
}

void CreateBiTree(char preord[],char inord[],int n,BiTree root)
{
    if(n<=0)root=null;
    else PreInOrd(preord,inord,1,n,1,n,&root);
}

int BitreeLeaf(BiTree bt)
{
    if(bt==null)return 0;
    if(bt->lchild==null&bt->rchild==null)return 1;
    return(BitreeLeaf(bt->lchild)+BitreeLeaf(bt->rchild));
}

int BitreeLeaf(BiTree bt)
{
    if(bt==null) return 0;
    if(bt->lchild==null&&bf->rchild==null) return 1;
    return (BitreeLeaf(bt->lchild)+BitreeLeaf(bt->rchild));
}

int BitreeDepth(BiTree bt)
{
    if(bt==null) return 0;
    if(bt->lchild==null&&bt->rchild==null) return 1;
    depthL=BitreeDepth(bt->lchild);
    depthL=BitreeDepth(bt->rchild);
    return 1+max(depthL,depthR);
}

／／max(左右子树深度，左子树最远距，右子树最远距)
