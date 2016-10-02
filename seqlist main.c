int main(int argc, char *argv[])
{
	SeqList seqlist;
	SeqList * pList;
	pList = &seqlist;
	if(argc<3)
	{
		printf("SeqListTest.exe [maxnum] [datafile.txt]\n");
		return 0x01;	
	}
	int maxnum = atoi(argv[1]);
	FILE *pdatafile = fopen(argv[2],"r+");

// test 0 Read number from a txt file to creat a seq list
	SeqListInitial(pList,maxnum);
	int inum;
	int i = -1;
	while(EOF != fscanf(pdatafile,"%d",&inum))
		SeqListInsert(pList, ++i,inum);
	//SeqListGvShow(pList,"SeqListShow[0].gv","SeqListInsert from argv[2]");

// test 1 Delete pos = 3 number from seq list
	int delnum,delpos;
	delnum = SeqListLocate(pList,3);
	delpos = SeqListSearch(pList,delnum);
	printf("%d\t%d\n",delnum,delpos);
	SeqListDelete(pList, delpos);
	//SeqListGvShow(pList,"SeqListShow[1].gv","SeqListDelete pos 3 from List");

// test 2 Random generate a seq list with maxnum elements
	SeqListSetRandNum(pList,maxnum);
	//SeqListGvShow(pList,"SeqListShow[2].gv","SeqListSetRandNum from argv[1]");

// test 3 Reverse a seq list with maxnum elements	
	SeqListReverse(pList);
	//SeqListGvShow(pList,"SeqListShow[3].gv","SeqListReversed");
	SeqListDestroy(pList);	

	return 0;
}
