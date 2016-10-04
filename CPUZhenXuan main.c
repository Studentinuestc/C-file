int _tmain(int argc,int _TCHAR* argv[])
{
    DWORD busySpan[COUNT];//array of busy times
    DWORD idleSpan[COUNT];//array of idle times
    int half=INTERVAL/2;
    double radian=0.0;
    for(int i=0;i<COUNT;i++)
    {
        busySpan[i]=(DWORD)(half+(sin(PI*radian)*half));
        idleSpan[i]=INTERVAL-busySpan[i];
        radian+=SPLIT;
    }
    
    DWORD startTime=o;
    int j=0;
    while(true)
    {
        j=j%COUNT;
        startTime=GetTickCount();
        while((GetTickCount()-startTime)<=busySpan[j])
        ;
        Sleep(idleSpan[j]);
        j++;
    }
}
