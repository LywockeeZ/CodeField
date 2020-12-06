package SortCompare;

import java.util.Random;
import java.util.Scanner;
import java.lang.Runtime;

public class Test 
{
    public static void main(String[] args) 
    {
        System.out.println("输入要排序的集合大小");
        Scanner in = new Scanner(System.in);
        int size = in.nextInt();

        Random random = new Random();
        int[] a = new int[size];
        for(int i = 0; i < a.length; i++)
        {
            a[i] = random.nextInt(size);
        }

        getSortAnalyse(a, "IS", size);
        getSortAnalyse(a, "TDM", size);
        getSortAnalyse(a, "BUM", size);
        getSortAnalyse(a, "RQ", size);
        getSortAnalyse(a, "QD3P", size);


        
    }

    public static void getSortAnalyse(int[] a, String name, int size)
    {
        Runtime run = Runtime.getRuntime();

        long first = System.nanoTime();
        long start = System.nanoTime();
        long totalMem = 0;
        
        System.out.println(name + "排序消耗时间情况如下(单位纳秒,B)");
        for(int i = 0; i < 10; i++)
        {
            long startMem = run.totalMemory() - run.freeMemory();
            switch(name)
            {
                case "IS":
                    InsertSort.sort(a.clone());
                    break;
                case "TDM":
                    TPMergeSort.sort(a.clone());
                    break;
                case "BUM":
                    BUMergeSort.sort(a.clone());
                    break;
                case "RQ":
                    QuickSort.sort(a.clone());
                    break;
                case "QD3P":
                    QuickSortWith3Way.sort(a.clone());
                    break;
                default:
                    break;
            }
            long end = System.nanoTime();
            long endMem = run.totalMemory() - run.freeMemory();
            totalMem += endMem - startMem;
            System.out.print(end - start + "   ");
            start = end;
        }
        
        long fin = System.nanoTime();
        System.out.println("十次的平均时间为：" + (fin - first)/10);
        System.out.println("十次的平均内存为：" + (totalMem)/10);
        System.out.println("------------------------------------------------------------");
        
        
    }
}