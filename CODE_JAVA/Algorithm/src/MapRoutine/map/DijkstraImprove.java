package MapRoutine.map;

import java.awt.Color;

//改进第1问，找到点就停止

public class DijkstraImprove 
{
    private static double INFINITY = Double.MAX_VALUE;
    private static double EPSILON = 0.000001;
    private EuclideanGraph G;
    private double[] dist;
    private int[] pred;

    public DijkstraImprove(EuclideanGraph G) 
    {
        this.G = G;
    }

    // 返回s到d的最短路
    public double distance(int s, int d) 
    {
        dijkstra(s, d, 0);
        return dist[d];
    }

    // print shortest path from s to d (interchange s and d to print in right order)
    public void showPath(int d, int s) {
        dijkstra(s, d, 0);

        if (pred[d] == -1) {
            System.out.println(d + " is unreachable from " + s);
            return;
        }

        for (int v = d; v != s; v = pred[v])
            System.out.print(v + "-");

        System.out.println(s);
    }

    // plot shortest path from s to d
    public void drawPath(int s, int d, int draw) {
        dijkstra(s, d, draw);

        if (pred[d] == -1)
            return;

        Turtle.setColor(Color.red);

        for (int v = d; v != s; v = pred[v])
            G.point(v).drawTo(G.point(pred[v]));

        Turtle.render();
    }

    // Dijkstra's algorithm to find shortest path from s to d
    public void dijkstra(int s, int d, int draw) {
        int V = G.V();

        // initialize
        dist = new double[V];
        pred = new int[V];

        for (int v = 0; v < V; v++)
            dist[v] = INFINITY;

        for (int v = 0; v < V; v++)
            pred[v] = -1;

        // priority queue
        IndexPQ pq = new IndexPQ(V);

        for (int v = 0; v < V; v++)
            pq.insert(v, dist[v]);// 这里可以优化

        // set distance of source
        dist[s] = 0.0;
        pred[s] = s;
        pq.change(s, dist[s]);

        // run Dijkstra's algorithm
        while (!pq.isEmpty()) 
        {
            int v = pq.delMin();
            //System.out.println("process " + v + " " + dist[v]);

            if (d == v)
            {
                // System.out.println("找到d点，终止算法");
                // System.out.println(pred[v]);
                break;
            }

            // v not reachable from s so stop
            if (pred[v] == -1)
                break;

            // scan through all nodes w adjacent to v
            IntIterator i = G.neighbors(v);

            while (i.hasNext()) 
            {
                int w = i.next();
                if (draw == 1)
                {
                    Turtle.setColor(Color.yellow);
                    G.point(v).drawTo(G.point(w));
                    Turtle.render();

                    try
                    {
                        for (long j = 0; j < 100000; j++);
                    }
                    catch (Exception e) {
                    } // 每画一条边都延时
                }

                if (dist[v] + G.distance(v, w) < dist[w] - EPSILON) 
                {
                    dist[w] = dist[v] + G.distance(v, w);
                    pq.change(w, dist[w]);
                    pred[w] = v;
                    //System.out.println("    lower " + w + " to " + dist[w]);
                }

            }

        }
        //System.out.println("Shortest distance is: " + dist[d]);

    }

}