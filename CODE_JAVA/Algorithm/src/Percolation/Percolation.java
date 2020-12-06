package Percolation;

import java.util.Random;

public class Percolation {

    private int n;
    private int[][] grid;
    private int[] dx = {0, 1, 0, -1};
    private int[] dy = {-1, 0, 1, 0};
    private int count = 0;

    public Percolation(int N)
    {
        if(N <= 0) throw new IllegalArgumentException();

        n = N;
        grid = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                grid[i][j] = 0;
    }

    public void reset()
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                grid[i][j] = 0;
    }

    public void open(int i, int j)
    {
        if(i < 1 || i > n || j < 1 || j > n)
            throw new IndexOutOfBoundsException();

        if(!isOpen(i, j))
        {
            grid[i][j] = 1;
        }
    }

    public boolean isOpen(int i, int j)
    {
        return (grid[i][j] != 0);
    }

    public boolean isFull(int i, int j, QuickFindUF uf)
    {
        if(!isOpen(i, j)) return false;

        int x = (i - 1) * n + j - 1;
        for(int a = 0; a < n; a++)
        {
            if(!isOpen(1, a + 1)) continue;
            //如果与上界连通，说明是满
            if(uf.connected(a, x)) 
            {
                return true;
            }
        }
            
        return false;
    }

    //根据uf方法进行percolate,返回open的个数
    public int percolates(QuickFindUF uf)
    {
        Random r = new Random(System.currentTimeMillis());
        boolean isPercolate = false;
        do 
        {
            int i = r.nextInt(n) + 1;
            int j = r.nextInt(n) + 1;
            if(!isOpen(i, j))
            {
                open(i, j);
                count++;

                UnionAround(i, j, uf);

                for(int a = n, b = 1; b <= n; b++)
                    if(isOpen(a, b) && isFull(a, b, uf)) isPercolate = true;
            }
        } while (!isPercolate);
        
        return count;
    }

    public void printGrid()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                if(grid[i][j] == 0)
                    System.out.print("██");
                else System.out.print("  ");
            System.out.println();
        }
            
    }

    public int getCount()
    {
        return count;
    }

    private void UnionAround(int i, int j, QuickFindUF uf)
    {
        for(int a = 0; a < 4; a++)
                {
                    int x = i + dx[a];
                    int y = j + dy[a];
                    if(x >= 1 && x <= n && y >= 1 && y <= n && isOpen(x, y))
                        uf.union((x - 1) * n + y - 1, (i - 1) * n + j - 1);
                }
    }

    public static void main(String[] args) 
    {
        int N = 10;
        Percolation p = new Percolation(N);
        //QuickFindUF qUf = new QuickFindUF(N);
        WQuickFindUF wUf = new WQuickFindUF(N);

        System.out.println(p.percolates(wUf));

        p.printGrid();
    }
}