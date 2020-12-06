package SortCompare;

import java.util.Random;

public class BUMergeSort {

    private static int[] aux;

    public static void sort(int[] a) 
    {
        int N = a.length;
        aux = new int[N];

        for (int sz = 1; sz < N; sz = sz + sz)
            for (int lo = 0; lo < N - sz; lo += sz + sz)
                merge(a, lo, lo + sz - 1, Math.min(lo + sz + sz - 1, N - 1));
    }

    private static void merge(int[] a, int lo, int mid, int hi) 
    {
        int i = lo;
        int j = mid + 1;

        for (int k = lo; k <= hi; ++k) 
            aux[k] = a[k];

        for (int k = lo; k <= hi; ++k) 
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (less(aux[i], aux[j]))
                a[k] = aux[i++];
            else
                a[k] = aux[j++];
    }

    public static boolean less(int a, int b) 
    {
        if (a < b)
            return true;
        else
            return false;
    }

    public static void display(int[] a) 
    {
        for (int i = 0; i < a.length; ++i)
            System.out.print(a[i] + " ");
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