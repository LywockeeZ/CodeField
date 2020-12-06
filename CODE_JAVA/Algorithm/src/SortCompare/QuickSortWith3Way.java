package SortCompare;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class QuickSortWith3Way
{
    private static int compare(int x, int y) 
    {
        if (x < y) return -1;
        else if (x > y) return 1;
        else return 0;
    }

    private static void exchange(int[] a, int i, int j) 
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void sort(int[] a) 
    {
        /*
        List<Integer> list_a = new ArrayList<Integer>();
        for (int i = 0; i < a.length; ++i) 
            list_a.add(a[i]);
        Collections.shuffle(list_a);*/

        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) 
    {
        if (hi <= lo) return;

        int lt = lo;
        int gt = hi;
        int i = lo;
        int v = a[lo];

        while (i <= gt) 
        {
            int cmp = compare(a[i], v);

            if (cmp < 0) exchange(a, lt++, i++);
            else if (cmp > 0) exchange(a, i, gt--);
            else i++;
        }

        sort(a, lo, lt - 1);
        sort(a, gt + 1, hi);
    }

    public static void display(int[] a) 
    {
        for (int i = 0; i < a.length; ++i)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) 
    {
        int[] a = new int[100000];
        Random r = new Random();

        for (int i = 0; i < 100000; ++i) 
            a[i] = r.nextInt() % 40000;

        System.out.println("处理数据数量：100000");

        // display(a);

        long start_time = System.nanoTime();// 获取当前时间
        sort(a);
        long consumingtime = System.nanoTime() - start_time;

        System.out.println("程序运行时间：" + (consumingtime / 1000) / 1000.0 + "us");
    }

}