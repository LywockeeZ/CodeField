package SortCompare;
 
import java.util.Random;

public class InsertSort 
{

    private static void exchange(int[] a,int i,int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
 
    public static void sort(int[] a)
    {
        for(int i=1;i<a.length;++i)
            for(int j=i;j>0&&less(a[j],a[j-1]);--j)
                exchange(a, j, j-1);
    }

    private static boolean less(int x, int y) 
    {
        return x<y;
    }

    public static void display(int[] a)
    {
        for(int i=0;i<a.length;++i)
            System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) 
    {
        int[] a = new int[100000];
        Random r = new Random();

        for(int i = 0;i<100000;++i)
            a[i] = r.nextInt() % 40000;

        System.out.println("处理数据数量：100000");

        //display(a);

        long startTime3 = System.currentTimeMillis();//获取当前时间
        sort(a);
        long endTime3 = System.currentTimeMillis();

        System.out.println("程序运行时间："+(endTime3-startTime3)+"ms");
    }

}
