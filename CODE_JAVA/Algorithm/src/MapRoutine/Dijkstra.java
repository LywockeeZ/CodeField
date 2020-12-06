package MapRoutine;

import java.util.LinkedList;
import java.util.Queue;

public class Dijkstra 
{
    //图中点的个数
    private int n;
    private int[] dist;
    private boolean[] st;
    private Graph g;
    //记录更新过的点数，在下一次更新前还原
    private Queue<Integer> recorder;

    public Dijkstra(Graph G)
    {
        g = G;
        n = g.getSize();
        dist = new int[n];
        st = new boolean[n];
        recorder = new LinkedList<Integer>();

        for(int i = 0; i < n; i++)
        {
            dist[i] = Integer.MAX_VALUE;
            st[i] = false;
        }
    }

    public int FindShortPath(int start, int end)
    {
        if(!recorder.isEmpty()) initDijkstra();

        IndexHeap heap = new IndexHeap(n);
        //Queue<Integer> path = new LinkedList<Integer>();
        
        dist[start] = 0;
        heap.Push(0, start);
        recorder.add(start);

        boolean isEnd = false;
        while(!heap.empty())
        {
            int distance = heap.Top();
            int node = heap.TopNode();
            if(st[node]) continue;
            st[node] = true;

            if(node == end) isEnd = true;

            for(int i = g.h[node]; i != -1; i = g.ne[i])
            {
                int j = g.e[i];
                if(dist[j] > distance + g.w[i])
                {
                    dist[j] = distance + g.w[i];
                    heap.Push(dist[j], j);
                    recorder.add(j);
                }
            }

            if(isEnd) break;
        }

        return dist[end];
    }

    private void initDijkstra()
    {
        for (int i : recorder) 
        {
            dist[i] = Integer.MAX_VALUE;
            st[i] = false;
        }
    }
}