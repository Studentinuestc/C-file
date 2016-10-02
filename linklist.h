typedef int ElemType;

typedef struct LinkListNode   
{ 
	ElemType				data;
	struct LinkListNode		*next;
}LinkListNode, *LinkList, **Link;

typedef struct DoubleLinkListNode
{
	ElemType		data;
	struct DoubleLinkListNode	*prior;
 	struct DoubleLinkListNode	*next;
}DoubleLinkListNode,	*DoubleList;

void LinkListHeadNodeInitial(Link pL);
void LinkListDestroy(Link pL);
void LinkListGvShow(Link pL, char * gvfilename, char * title);
int  LinkListInsertFromHead(Link pL, ElemType e);
int LinkListInsertFromTail(Link pL, ElemType e);
int LinkListInsert(Link pL, int pos, ElemType e);
LinkListNode * LinkListLocat(Link pL, int pos);
LinkListNode * LinkListSearch(Link pL, ElemType e);
int	LinkListLength(LinkList L);
int main(int argc, char *argv[]);
int LinkListInsertNode(LinkList L, int pos, ElemType e);
int DelList(LinkList L,int i,ElemType *e);
LinkList MergeLinkList(LinkList LA, LinkList LB);
void CreateCLinkList(LinkList l);
LinkList CreateRCLinkList();
void CreateDList(DoubleList L);
int DlinkIns(DoubleList L,int i,ElemType e);
int	DlinkDel(DoubleList L,int i,ElemType *e);










