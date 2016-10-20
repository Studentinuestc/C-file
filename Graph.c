void dfs(int v)
{
    visited[v]=1;
    w=firstadj(g,v);
    while(w!=0)
    {
        if(visited[w]==0)
        dfs(w);
        w=nextadj(g,v,w);
    }
}

void travergraph(g)
{
    for(i=1;i<=n;i++) visited[i]=0;
    for(i=1;i<=n;i++)
          if(visited[i]==o) dfs(i);
}

void bfs(Graph g,int v)
{
    visited[v]=1;
    Enqueue(Q,v);
    while(!Empty(Q))
    {
        if(visited[w]==0)
        {
            visited[w]=1;
            Enqueue[Q,w];
        }
        w=Nextadj[g,v,w];
    }
}
