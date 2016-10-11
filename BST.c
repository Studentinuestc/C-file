BiTree SearchBST(BiTree bt,KeyType key)
{
    if(bt==null||key=bt->data.key)return bt;
    if(key<bt->data.key)return SearchBST(bt->lchild.key);
    else return SearchBST(bt->rchild.key);
}

int SearchBST(BiTreeNode *bt,int key,BiTreeNode **p,BiTreeNode **q)
{
    if(!bt){*q=*p;return 0;}
    else if(key==bt->data.key){*q=bt;return 1;}
    else if(key<bt->data.key)return SearchBST(bt->lchild,key,&bt,q);
    else return SearchBST(bt->rchild,key,&bt,q);
}

int InsertBST (BiTreeNode **bt,Datatyoe e)
{
    BiTreeNode *qq=new BiTreeNode();
    BiTreeNode *pp=new NoTreeNode();
    BiTreeNode **q=&qq;
    BiTreeNode **p=&pp;
    BiTreeNode *s;
    *q=0x0;
    *p=0x0;
    if(SearchBST(*bt,e.key,p,q)==0)
    {
        s=new BiTreeNode();
        s->data=e;
        s->lchild=s->rchild=0x0;
        if(!(*q))*bt=s;
        else if(e.key<(*q)->data.key)   (*q)->lchild=s;
        else (*q)->rchild=s;
        return 1;
    }
    else return 0;
}

int DeleteNode(BiTreeNode **t,int key)
{
    BITreeNode *pp=new BiTreeNode();
    BiTreeNode *ff=new BiTreeNode();
    BiTreeNode **p=&pp;
    BiTreeNode **f=&ff;
    BiTreeNode *s,*q;
    *p=0x0;*f=0x0;
    int flag=0;
    if(SearchBST(*t,key,f,p)!=0)
    {
        flag=1;
        if(!((*p)->rchild))
        {
            if((*f)->lchild==*p)  (*f)->lchild=(*p)->lchild;
            else (*f)->rchild=(*p)->lchild;
        }
        else 
        {
            if(!((*p)->lchild))
            {
                if((*f)->lchild==*p) (*f)->lchild=(*p)->rchild;
                else (*f)->rchild=(*p)->rchild;
            }
            else
            {
                q=*p;
                s=(*p)->lchild
                while(s->rchild)
                {
                    q=s;
                    s=s->rchild;
                }
                (*p)->data=s->data;
                if(q!=*p)
                    (q)->rchild=s->lchild;
                else
                    (q)->lchild=s->lchild;
            }
        }
    }
    return flag;
}





























