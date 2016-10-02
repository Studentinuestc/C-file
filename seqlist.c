void SeqListInitial(SeqList * L, int len)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)*len);
	memset(L->elem, 0, sizeof(ElemType)*len);
	L->length = len;
	L->last = -1;
}

void SeqListDestroy(SeqList * L)
{
	if(L->elem)
		free(L->elem);
	L->length = 0;
	L->last = -1;
}

void SeqListSetRandNum(SeqList * L, int n)
{
	int i;
	if(L->elem==NULL || L->length < n)
	{
		printf("SetRandNumSeqList over range\n");
		return;		
	}

	for(i=0; i<n; i++)
		L->elem[i] = rand()%100;
	L->last = n-1;
}

int  SeqListSearch(SeqList *L, ElemType e)
{	
	int i=0; 
	while ((i<=L->last)&&(L->elem[i]!=e))
		i++;
	if  (i<=L->last)
		return(i);
  	else
		return(-1);
}

ElemType  SeqListLocate(SeqList *L, int pos)
{	
	if(pos >= 0 && pos <= L->last)
		return(L->elem[pos]);
 	else
		return(0xFFFF);
}

int  SeqListInsert(SeqList *L, int pos, ElemType e)
{ 
	int	i;
	if((pos<0) || pos>L->length-1)
	{
		printf("InsertSeqList over range\n");
		return(0x01);
	}
	for(i=L->last;i>=pos;i--)
		L->elem[i+1]=L->elem[i];
	L->elem[pos]=e;
	L->last++;
	return(0x00);
}

int  SeqListDelete(SeqList *L, int pos)
{ 
	int	i;
	if(pos<0||pos>L->last)   
	{ 
		printf("DeletSeqList over range\n");
		return(0x01);
	}
	for(i=pos; i<L->last; i++)
		L->elem[i] = L->elem[i+1];   /* 将后面的元素依次前移 */
	L->last--;
	return(0x00);
}

void SeqListReverse(SeqList *L)
{
	int i;
	if(L->last<=0)
		return;
	for(i=0; i<L->last/2; i++)
	{
		ElemType temp;
		temp = L->elem[i];
		L->elem[i] = L->elem[L->last - i];
		L->elem[L->last-i] = temp;
	}
}

void SeqListGvShow(SeqList *L, char *gvfilename, char *title)
{
	int i;
	FILE *fp = fopen(gvfilename,"w+");
	fprintf(fp,"digraph SeqList { \n");
	fprintf(fp,"labelloc = t; labeljust = m; fontname = \"Microsoft YaHei\"; fontcolor = black; \n");
	fprintf(fp,"label = \"%s\"; \n",title);
	fprintf(fp,"node [fontname = \"Microsoft YaHei\", color=darkgreen, shape=record, height=.1]; \n");
	fprintf(fp,"edge [fontname = \"Microsoft YaHei\", color=darkgreen, style=solid]; \n");
	fprintf(fp,"struct [ label = \"{val|add}");
	for(i=0; i<=L->last; i++)
		fprintf(fp," | {%2d|%2d}", L->elem[i], i);
	for(i=L->last+1; i<L->length; i++)
		fprintf(fp," | {NA|%2d}", i);	
	fprintf(fp,"\"]; \n}\n");
	fclose(fp);
}
