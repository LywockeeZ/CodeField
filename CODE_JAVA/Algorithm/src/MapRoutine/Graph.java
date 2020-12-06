package MapRoutine;

import java.util.ArrayList;

public class Graph 
{
    public int h[];
    public int e[];
    public int ne[];
    public int w[];
    private int idx;
    private int size;
    private ArrayList<Pair<Integer, Integer>> pos;

    public Graph(int N, int M)
    {
        size = N;
        h = new int[N];
        e = new int[N];
        ne = new int[M];
        w = new int[M];
        pos = new ArrayList<Pair<Integer, Integer>>(N);
        idx = 0;
    }

    public void setPos(int i, int x, int y)
    {
        Pair<Integer, Integer> Node = pos.get(i);
        Node = new Pair<Integer, Integer>(x, y);
    }

    public void addEdge(int a, int b, int c)
    {
        e[idx] = b;
        ne[idx] = h[a];
        w[idx] = c;
        h[a] = idx++;
    }

    public int getSize()
    {
        return size;
    }
}