BiThrTree pre;
int InOrderThread(BiThrTree *head,BiThrTree bt)
{
    *head=new BiThrNode;
    if(*head==null)return 0;
    (*head)->LTag=0;(*head)->RTag=1;
    (*head)->rchild=*head;
    if(bt==null)(*head)->lchild=*head;
    else
    {
        (*head)->lchild=bt;
        pre=*head;
        InThreading(bt);
        pre->rchild=*head;
        pre->LTag=1;
        (*head)->rchild=pre;
    }
    return 1;
}

void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(p->lchild==null)
        {
            p->LTag=1;
            p->lchild=pre;
        }
        if(pre->rchild==null)
        {
            pre->RTag=1;
            pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild);
    }
}

BiThrTree InPreNode(BithrTree p)
{
    BiThrTree pre;
    pre=p->lchild;
    if(p->LTag!=1)
      while(pre->RTag==0)pre=Pre->rchild;
      return pre;
}

BiThrTree InPostNode(BiThrTree p)
{
    BiThrTree post;
    post=p->rchild;
    if(p->RTag!=1)
      while(post->LTag==0)post=post->lchild;
      return post;
}

