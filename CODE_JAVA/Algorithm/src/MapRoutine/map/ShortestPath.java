/*************************************************************************
 *  Compilation:  javac ShortestPath.java
 *  Execution:    java ShortestPath file < input.txt
 *  Dependencies: EuclideanGraph.java Dijkstra.java In.java StdIn.java Turtle.java
 *
 *  Reads in a map from a file, and two integers s and d from standard input,
 *  and plots the shortest path from s to d using turtle graphics.
 *
 *  % java ShortestPath usa.txt
 *  0 5000
 *
 ****************************************************************************/
package MapRoutine.map;

public class ShortestPath {

    public static void main(String[] args) {

        

        // read in the graph from a file
        In graphin = new In("files/usa.txt");
        EuclideanGraph G = new EuclideanGraph(graphin);
        System.err.println("Done reading the graph " + "files/usa.txt");
        System.err.println("Enter query pair from stdin");
        
    
        // read in the s-d pair from standard input
        Dijkstra dijkstra = new Dijkstra(G);
        DijkstraImprove dijkstra1 = new DijkstraImprove(G);
        int s = StdIn.readInt();
        int d = StdIn.readInt();

        long startTime = System.currentTimeMillis();//获取当前时间
        double dist = dijkstra.distance(s, d);
        long endTime = System.currentTimeMillis();
        System.out.println("原算法程序:\n最短路径：" + dist + "\n运行时间："+(endTime-startTime)+"ms\n");

        long startTime1 = System.currentTimeMillis();//获取当前时间
        double dist2 = dijkstra1.distance(s, d);
        long endTime1 = System.currentTimeMillis();
        System.out.println("改进后算法程序:\n最短路径：" + dist2 + "\n运行时间："+(endTime1-startTime1)+"ms\n");

        Turtle.create(1000, 700);
        G.draw();

        System.out.println("路径为：");
        dijkstra1.showPath(s, d);
        dijkstra1.drawPath(s, d, 1);

        Turtle.render();
        
    }

}

 

