package MapRoutine;

public class IndexHeap 
{
    //堆中下标为k的位置存放的值
    int h[];
    //堆中下标为k的位置是第几个插入的
    int hp[];
    //堆中第k个插入的在堆中的下标是几
    int ph[];
    //存放下标为k的节点编号
    int node[];
    //记录当前堆的大小
    int size;
    int idx;

    public IndexHeap(int n)
    {
        h = new int[n];
        hp = new int[n];
        ph = new int[n];
        node = new int[n];
        idx = 0;

        for(int i = 0; i < n; i++) h[i] = -1;
    }

    //加入距离和编号
    public void Push(int x, int b)
    {
        size++;
        idx++;
        ph[idx] = size;
        hp[size] = idx;
        h[size] = x;
        node[size] = b;
        up(size);
    }

    public void Pop()
    {
        heap_swap(1, size);
        size--;
        down(1);
    }

    public int Top()
    {
        return h[1];
    }

    public int TopNode()
    {
        return node[1];
    }

    public boolean empty()
    {
        return size == 0;
    }

    public int getNode(int x)
    {
        return node[x];
    }


    private void down(int x)
    {
        int t = x;
        if(x * 2 <= size && h[x] > h[x * 2]) t = x * 2;
        if(x * 2 + 1 <= size && h[t] > h[x * 2 + 1]) t = x * 2 + 1;
        if(t != x)
        {
            heap_swap(t, x);
            down(t);
        }
    }

    private void up(int x)
    {
        while((x / 2) != 0 && h[x / 2] > h[x])
        {
            heap_swap(x, x / 2);
            x >>= 1;
        }
    }

    private void heap_swap(int a, int b)
    {
        swap(node, a, b);
        swap(ph, hp[a], hp[b]);
        swap(hp, a, b);
        swap(h, a, b);
    }

    private void swap(int[] data, int a, int b)
    {
        int t = data[a];
        data[a] = data[b];
        data[b] = t;
    }
}