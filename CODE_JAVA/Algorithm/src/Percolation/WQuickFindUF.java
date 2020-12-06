package Percolation;

public class WQuickFindUF extends QuickFindUF 
{
    //各个根节点对应的分量大小
    private int[] sz;

    public WQuickFindUF(int N)
    {
        super(N);
        
        sz = new int[n];
        for(int i = 0; i < n; i++)
            sz[i] = 1;
    }

    @Override
    public void reset()
    {
        super.reset();
        for(int i = 0; i < n; i++)
            sz[i] = 1;
    }

    @Override
    public int find(int p)
    {
        while(p != id[p]) p = id[p];
        return p;
    }

    @Override
    public void union(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if(i == j) return;

        //将小树的根节点连接到大树的根节点
        if(sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }
    
}