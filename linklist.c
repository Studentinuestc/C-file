void LinkListHeadNodeInitial(Link pL)
{
	*pL = (LinkList)malloc(sizeof(LinkListNode)); 
	memset(&((*pL)->data),-1,sizeof(ElemType));
	(*pL)->next = NULL; 
}

void LinkListDestroy(Link pL)
{
	if(pL==NULL || *pL==NULL)
		return;
	LinkListNode * p = *pL;
	LinkListNode * q;
	while(p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*pL = NULL;
}

void LinkListGvShow(Link pL, char * gvfilename, char * title)
{
	LinkListNode * p = *pL;
	FILE *fp = fopen(gvfilename,"w+");
	fprintf(fp,"digraph LinkList { \n");
	fprintf(fp,"rankdir=LinkList; \n");
	fprintf(fp,"labelloc = t; labeljust = m; fontname = \"Microsoft YaHei\"; fontcolor = black; \n");
	fprintf(fp,"label = \"%s\"; \n",title); 
	fprintf(fp,"node [shape=record,fontname=Sans,width=.05,height=0.05];\n");
	fprintf(fp,"edge [color=black,arrowhead=vee,arrowsize=1.0];\n");
	int nodenum=0;
	while(p!=NULL)
	{
		fprintf(fp,"node%d [label = \"{<D> %d | <L>}\"];\n",nodenum++,p->data);
		p = p->next;
	}
	int i;
	for(i=0; i<nodenum-1; i++)
		fprintf(fp,"node%d:L -> node%d:D;\n",i,i+1);
	if(nodenum>0)
	{
		fprintf(fp,"L -> node%d;\n",0);
		fprintf(fp,"node%d:L -> NULL;\n",nodenum-1);		
	}
	fprintf(fp,"}\n");
	fclose(fp);
}

int  LinkListInsertFromHead(Link pL, ElemType e)
{ 
	LinkList L = *pL;
	if(L == NULL)
		return 0x01;
	LinkListNode * p;

	p = (LinkList)malloc(sizeof(LinkListNode));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 0x00;
}

int LinkListInsertFromTail(Link pL, ElemType e)
{
	LinkList L = *pL;
	if(*pL == NULL)
		return 0x01;
	LinkListNode * p;
	LinkListNode * q;
	q = *pL;	
	p = (*pL)->next;
	while(p != NULL)
	{
		q = p;
		p = p->next;
	}
	q->next = (LinkList)malloc(sizeof(LinkListNode));
	q->next->data = e;
	q->next->next = NULL;
	return 0x00;	
}

int LinkListInsert(Link pL, int pos, ElemType e)
{
	LinkList L = *pL;
	if(L == NULL)
		return 0x01;
	LinkListNode * p;
	LinkListNode * q;
	q = p = L->next;
	int counter = 0;
	while(p != NULL && counter++ < pos)
	{
		q = p;
		p = p->next;
	}
	if(counter == 0 || counter != pos)
		return 0x01;
	q->next= (LinkList)malloc(sizeof(LinkListNode));
	q = q->next;
	q->data = e;
	q->next = p;
	return 0x00;
}

LinkListNode * LinkListLocat(Link pL, int pos)
{
	LinkList L = *pL;
	if(L == NULL)
		return NULL;
	LinkListNode * p;
	LinkListNode * q;
	p = L->next;
	int counter = 0;
	while(p != NULL && counter++ < pos)
	{
		p = p->next;
	}
	return p;
}

LinkListNode * LinkListSearch(Link pL, ElemType e)
{
	LinkList L = *pL;
	LinkListNode * p = L;
	if(L == NULL)
		return NULL;
	p = L->next;
	while(p != NULL)
	{
		if(p->data==e)
			return p;
		p = p->next;
	}
	return NULL;
}

int	LinkListLength(LinkList L)
{   
	LinkListNode * p = L;
	int len = 0;
	while(p != NULL)
	{	  
		p = p->next;
		len++;
	}
	return len;	
}

int main(int argc, char *argv[])
{
	int inum;
	LinkList plist;
	Link pplink = &plist;

	if(argc<2)
	{
		printf("linklist.exe [datafile.txt]\n");
		return 0x01;	
	}
	FILE *pdatafile = fopen(argv[1],"r+");

	LinkListHeadNodeInitial(pplink);
	while(EOF != fscanf(pdatafile,"%d",&inum))
		LinkListInsertFromHead(pplink, inum);
	LinkListGvShow(pplink,"LinkListShow[0].gv","LinkListInsertFromHead from argv[2]");	
	LinkListDestroy(pplink);
	
	LinkListHeadNodeInitial(pplink);
	fseek(pdatafile,0,SEEK_SET);
	while(EOF != fscanf(pdatafile,"%d",&inum))
		LinkListInsertFromTail(pplink, inum);
	LinkListGvShow(pplink,"LinkListShow[1].gv","LinkListInsertFromTail from argv[2]");
	LinkListDestroy(pplink);




	LinkListGvShow(pplink,"LinkListShow[2].gv","LinkListDestroy");	
	fclose(pdatafile);
	return 0;
}
//下面是初学者选作
//int LinkListInsertNode(LinkList L, int pos, ElemType e)
//{  
//	LinkListNode * p;
//	LinkListNode * q;
//	int	counter = 0;
//	p = L;
//	while(p!=NULL&&k<i-1)  /*表未查完且未查到第i-1个时重复，找到pre指向第i-1个*/ 
//	{ 
//		pre=pre->next;
//		k=k+1; 
//	}									/*查找第i-1结点*/
//	if(!pre)      /*如当前位置pre为空表已找完还未数到第i个，说明插入位置不合理*/ 
//	{ 
//		printf("插入位置不合理!");
//		return ERROR;
//	}
//	s=(Node*)malloc(sizeof(Node));   /*申请一个新的结点S */
//	s->data=e;                       /*值e置入s的数据域*/
//	s->next=pre->next;			     /*修改指针，完成插入操作*/
//	pre->next=s;
//	return OK;
//}
//
///*在带头结点的单链表L中删除第i个元素，并将删除的元素保存到变量*e中*/
//int DelList(LinkList L,int i,ElemType *e)
//{  
//	Node	*pre;
//	Node	*r;
//	int		k;
//	
//	pre = L;
//	k = 0;
//	
//	while(pre->next!=NULL && k<i-1)	/*寻找被删除结点i的前驱结点i-1使p指向它*/
//	{ 
//		pre=pre->next; 
//		k=k+1;
//	}								/*查找第i-1个结点*/
//	if(!(pre->next))     /* 即while循环是因为p->next=NULL或i<1而跳出的,而是因为没有找到合法的前驱位置，说明删除位置i不合法。*/
//	{
//		printf("删除结点的位置i不合理!");
//		return ERROR;
//	}
//	r=pre->next;
//	pre->next=pre->next->next;    /*修改指针，删除结点r*/
//	*e = r->data;
//	free(r);    /*释放被删除的结点所占的内存空间*/
//	printf("成功删除结点!");
//	
//	return OK;
//}
//
///*将递增有序的单链表LA和LB合并成一个递增有序的单链表LC*/
//LinkList MergeLinkList(LinkList LA, LinkList LB)
//{  
//	Node		*pa,*pb;
//	Node		*r;
//	LinkList	LC; /*将LC初始置空表。pa和pb分别指向两个单链表LA和LB中的第一个结点,r初值为LC*/
//   
//	pa = LA->next;
//	pb = LB->next;
//	LC = LA;
//	LC->next = NULL;
//	r = LC;        /*当两个表中均未处理完时，比较选择将较小值结点插入到新表LC中。*/
//    
//	while(pa!=NULL && pb!=NULL)
//	{
//		if(pa->data <= pb->data)
//		{
//			r->next=pa;
//			r=pa;
//			pa=pa->next;
//		}
//		else
//		{
//			r->next=pb;
//			r=pb;
//			pb=pb->next;
//		}
//	}
//	if(pa) /*若表LA未完，将表LA中后续元素链到新表LC表尾*/
//		r->next=pa;
//	else	 /*否则将表LB中后续元素链到新表LC表尾*/
//		r->next=pb;
//	free(LB);
//	
//	return(LC);
//}
//
///*创建循环链表*/
//void CreateCLinkList(LinkList l)
//{
//	int		num;
//	Node	*p;
//	
//	l->data = -1;
//	l->next = l;
//	
//	printf("请输入循环链表的元素 (以-1结束):\n");
//	scanf("%d",&num);
//	while(num != -1)
//	{
//		p=(Node*)malloc(sizeof(struct Node));
//		p->data=num;
//		p->next=l->next;
//		l->next=p;
//		scanf("%d",&num);
//	}
//}
//
///*创建尾指针表示的循环链表*/
//LinkList CreateRCLinkList()
//{
//	LinkList	l;
//	int			num;
//	Node		*p;
//	
//	l = (Node*)malloc(sizeof(struct Node));
//	l->data = -1;
//	l->next = l;
//	
//	printf("请输入循环链表的元素 (以-1结束):\n");
//	scanf("%d",&num);
//	while(num != -1)
//	{
//		p=(Node*)malloc(sizeof(struct Node));
//		p->data=num;
//		p->next=l->next;
//		l->next=p;
//		scanf("%d",&num);
//	}
//	p=l;
//	while(p->next!=l)
//	{
//		p=p->next;
//	}
//	
//	return p;
//}
//
///*通过键盘输入表中元素值，利用尾插法建单链表,并返回该单链表头指针L*/
//void CreateDList(DoubleList L)
//{ 
//	DoubleLinkListNode	*r, *s;
//	char	c;
//	int		flag; 
//	flag = 1; /*设置一个标志，初值为1，当输入"$"时，flag为0，建表结束*/
//	
//	L->next = L;
//	L->prior = L;
//	r = L;              
//	
//	while(flag)         
//	{
//		c=getchar();
//		if(c!='$')
//		{
//			s=(DoubleLinkListNode*)malloc(sizeof(DoubleLinkListNode));
//			s->data=c;
//			r->next=s;
//			s->prior=r;
//			r=s;
//		}
//		else
//		{
//			flag=0;
//			r->next=L;   
//			L->prior=r;
//		}
//	}
//}
//
//int DlinkIns(DoubleList L,int i,ElemType e)
//{
//	DoubleLinkListNode	*s,*p;
//	int		k;
//	p = L;  
//	k = 0;                    /*从"头"开始，查找第i-1个结点*/
//	while(p->next!=L&&k<i)    /*表未查完且未查到第i-1个时重复，找到p指向第i个*/ 
//	{ 
//		p=p->next;
//		k=k+1; 
//	}					    /*查找第i-1结点*/
//	if(p->next == L)        /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
//	{ 
//		printf("插入位置不合理!");
//		return ERROR;
//	}
//	s=(DoubleLinkListNode*)malloc(sizeof(DoubleLinkListNode));
// 	if (s)
//	{
//		s->data=e;
//		s->prior=p->prior;		
//		p->prior->next=s;	
//		s->next=p;			
//		p->prior=s;			
//		return OK;
//	}
//	else 
//		return ERROR;
//}
//
//int	DlinkDel(DoubleList L,int i,ElemType *e)
//{
//	DoubleLinkListNode	*p;
//	int		k;
//	
//	p = L;  
//	k = 0;                      /* 从"头"开始，查找第i个结点 */
//	
//	while(p->next!=L && k<i)    /*表未查完且未查到第i个时重复，找到p指向第i个*/ 
//	{ 
//		p=p->next;
//		k=k+1; 
//	}								
//	if(p->next == L)       
//	{ 
//		return ERROR;
//	}
//	else
//	{
//		*e=p->data;
//		p->prior->next=p->next;
//		p->next->prior=p->prior;
//		free(p);
//		
//		return OK;
//	}
//}
