void L_Rotate(AVLNode **p)
{
    AVLNode *rp=(*p)->rchild;
    (*p)->rchild=rp->lrchild;
    rp->lchild=*p;
    *p=rp;
}

void R_Rotate(AVLNode **p)
{
    AVLNode **lp=(*p)->lchild;
    (*p)->lchild=lp->rchild;
    lp->rchild=*p;
    *p=lp;
}

void LeftBalance(AVLNode **p)
{
    AVLNode *lp=(*p)->lchild;
    AVLNode *rd;
    switch(lp->bf)
    {
        case LH:
          (*p)->bf=lp->bf=EH;
           R_Rotate(p);
           break;
        case EH:
          (*p)->bf=LH;
          break;
        case RH:
          rd=lp->rchild;
          switch(rd->bf)
          {
              case LH:
                (*p)->bf=RH;
                lp->bf=EH;
                break;
              case EH:
                (*p)->bf=lp->bf=EH;
                break;
              case RH:
                (*p)->bf=EH;
                lp->bf=EH;
                break;
          }
          rd->bf=EH;
          L_Rotate(&(*p)->lchild);
          R_Rotate(p);
    }
}

void RightBalance(AVLNode **p)
{
    AVLNode *rp=(*p)->rchild;
    AVLNode *ld;
    switch(rp->bf)
    {
        case LH:
          (*p)->bf=rp->bf=EH;
          L_Rotate(p);
          break;
        case EH:
          (*p)->bf=RH;
          break;
        case RH:
          ld=lp->lchild;
          switch(ld->bf)
          {
              case LH:
                (*p)->bf=EH;
                rp->bf=LH;
                break;
              case EH:
                (*p)->bf=rp->bf=EH;
                break;
              case RH:
                (*p)->bf=RH;
                rp->bf=EH;
                break;
          }
          ld->bf=EH;
          R_Rotate(&(*P)->rchild);
          L_Rotate(p);
    }
}
