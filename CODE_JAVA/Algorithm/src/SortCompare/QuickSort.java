package SortCompare;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class QuickSort {

    private static boolean less(int x, int y) {
        return x < y;
    }

    private static void exchange(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void sort(int[] a) {
        /*List<Integer> list_a = new ArrayList<Integer>();

        for (int i = 0; i < a.length; ++i) 
            list_a.add(a[i]);

        Collections.shuffle(list_a);*/
        sort(a, 0, a.length - 1);
    }

    public static void sort(int[] a, int lo, int hi) {
        if (hi <= lo)
            return;

        int j = partition(a, lo, hi);

        sort(a, lo, j - 1);
        sort(a, j + 1, hi);
    }

    private static int partition(int[] a, int lo, int hi) 
    {
        int i = lo;
        int j = hi + 1;

        while (true)
        {
            while (less(a[++i], a[lo])) 
                if (i == hi) break;

            while (less(a[lo], a[--j]))
                if (j == lo) break;

            if (i >= j) break;

            exchange(a, i, j);
        }

        exchange(a, lo, j);
        return j;
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
