static void MakeUsage(float level)
{
    PerformanceCounter p= new PerformceCounter("Processor","% Processor Time","_Title");
    while(true)
    {
        if(p.NextValue()>level)
            System.Threading.Thread.Sleep(10);
    }
}
