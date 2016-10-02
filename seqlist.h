typedef int ElemType; 

typedef  struct SeqList
{ 
	ElemType	*elem;          // array pointer named elem
    int			length;         // total length of the array elem
	int			last;           // the last position of the elem array
}SeqList;

void	SeqListInitial(SeqList * L, int len);			// initial a sequnce list, the length is len
void	SeqListDestroy(SeqList * L);					// destroy the sequnce list L
void	SeqListSetRandNum(SeqList * L, int n);			// set random value for seq list L for n elements
int		SeqListSearch(SeqList *L, ElemType e);			// search a element from the sequnce list L on value e
ElemType	SeqListLocate(SeqList *L, int pos);			// locate a position pos from the sequnce list L
int		SeqListInsert(SeqList *L, int pos, ElemType e);	// insert a element to the sequnce list L at the position pos
int		SeqListDelete(SeqList *L, int pos);				// delete a element from the sequnce list L at the position pos
void	SeqListReverse(SeqList *L);						// reqList a sequnce list L
void	SeqListGvShow(SeqList *L, char *gvfilename, char *title);	// generate a GV file for further Graphize
