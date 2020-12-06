package Percolation;

import java.util.ArrayList;
import java.util.OptionalDouble;
 
public class PercolationStats {
    
    //结果数据数组
    private ArrayList<Double> result;
 
    public PercolationStats(int n, int trials)   
    {
        if(n <= 0 || trials <= 0)
            throw new java.lang.IllegalArgumentException("n and trials must be >= 1");

        result = new ArrayList<>(100);
        
        for(int i = 0; i < trials; i ++)
        {
            Percolation p = new Percolation(n);
            QuickFindUF Uf = new WQuickFindUF(n);
            double d = (double)p.percolates(Uf) / (n * n);
            result.add(d);
        }
    }

    public PercolationStats(int n, int trials, boolean isWQF)   
    {
        if(n <= 0 || trials <= 0)
            throw new java.lang.IllegalArgumentException("n and trials must be >= 1");

        result = new ArrayList<>(100);
        
        for(int i = 0; i < trials; i ++)
        {
            Percolation p = new Percolation(n);
            WQuickFindUF Uf = new WQuickFindUF(n);
            double d = (double)p.percolates(Uf) / (n * n);
            result.add(d);
        }
    }

    public double mean()                          
    {
        OptionalDouble avrg = result.stream().mapToDouble(r->r).average();
        return avrg.getAsDouble();
    }

    //标准差
    public double stddev()                        
    {
        double sum = result.stream().mapToDouble(r->(r-this.mean())*(r-this.mean())).sum();
        double avrg = sum / (double)(result.size()-1);
        return Math.sqrt(avrg);
    }

    //左边置信区间
    public double confidenceLo()                  
    {
        return (this.mean()-(1.96*this.stddev()/Math.sqrt((double)result.size())));
    }

    //右边置信区间
    public double confidenceHi()                  
    {
        return (this.mean()+(1.96*this.stddev()/Math.sqrt((double)result.size())));
    }

    public static void main(String[] args)
    {
        int n = 20, T = 10;

        long startTime = System.currentTimeMillis();    //获取开始时间
        PercolationStats ps = new PercolationStats(n,T);
        String s = "%-20s = %-1.15f \n";
        System.out.println("使用QuickFind");
        System.out.println("Creating PercolationStates(" + n + ", " + T + ")");
        System.out.printf(s, "mean()", ps.mean());
        System.out.printf(s, "stddev()", ps.stddev());
        System.out.printf(s, "confidenceLo()", ps.confidenceLo());
        System.out.printf(s, "confidenceHi()", ps.confidenceHi());
        long endTime = System.currentTimeMillis();    //获取结束时间
        System.out.println("运行时间：" + (endTime - startTime) + "ms"); 


        
        long startTime2 = System.currentTimeMillis();    //获取开始时间
        PercolationStats ps2 = new PercolationStats(n,T, true);
        System.out.println("使用WQuickFind");
        System.out.println("Creating PercolationStates(" + n + ", " + T + ")");
        System.out.printf(s, "mean()", ps2.mean());
        System.out.printf(s, "stddev()", ps2.stddev());
        System.out.printf(s, "confidenceLo()", ps2.confidenceLo());
        System.out.printf(s, "confidenceHi()", ps2.confidenceHi());
        long endTime2 = System.currentTimeMillis();    //获取结束时间
        System.out.println("运行时间：" + (endTime2 - startTime2) + "ms");
    }
}