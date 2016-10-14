void HuffmanCoding(HNode *HT,NCode *HC,int *w,int n)
{
    if(n<=1) return;
    m=2*n-1;
    HT=(HNode *)malloc(m.sizeof(HNode));
    for(p=HT,i=1;i<n;++i,++p,++w)
    {
        (*p)->weight=*w;
        (*p)->lchild=-1;
        (*p)->rchild=-1;
        (*p)->parent=-1;
    }
    for(;i<m;++i,++p)
    {
        (*p)->weight=0;
        (*p)->lchild=-1;
        (*p)->rchild=-1;
        (*p)->parent=-1;
    }
    for(i=n;i<m;++i)
    {
        m1=m2=MAXVALUE;
        x1=x2=0;
        for(j=0;j<i;++j)
        {
            if(HT[j].parent==-1&&HT[j].weight<m1)
            {
                m1=m2;
                x1=x2;
                m1=HT[j].weight;
                x1=j;
            }
            else if(HT[j].parent==-1&&HT[j].weight<m2)
            {
                m2=HT[j].weight;
                x2=j;
            }
        }
        HT[x1].parent=i;
        HT[x2].parent=i;
        HT[i].lchild=x1;
        HT[i].rchild=x2;
        HT[i].weight=m1+m2;
    }
    HC=(HNode*)mallco(n*sizeof(HNode));
    for(i=0;i<n;++i)
    {
        start=n-1;
        for(c=i,f=HT[i].parent;f!=-1;c=f,f=HT[f].parent)
            if(HT[f].lchild=c) HC[i].bit[start--]=0;
            else HC[i].bit[start--]=1;
    }
}
