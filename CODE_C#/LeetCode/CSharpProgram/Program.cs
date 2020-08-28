using System;
using System.Collections.Generic;

namespace CSharpProgram
{

public class Program
{
    public static int count = 0;
    public static List<List<int>> output = new List<List<int>>();
    public static string[] inputs;

    public static void Main()
    {
        int n = int.Parse(Console.ReadLine().Trim());

        for (int i = 0; i < n; i++)
        {
            inputs = Console.ReadLine().Trim().Split(' ');
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                JudgeIsJiao(inputs[i - 1], inputs[j - 1]);
            }
        }
        output.Sort((x, y) => x[0].CompareTo(y[0]));

        for (int i = 0; i < output.count; i++)
        {
            for (int j = 0; j < output[i].count; j++)
            {
                Console.Write(output[i][j]);
                Console.Write(" ");
            }
            Console.Write("\n");
        }
        Console.ReadKey();
    }

    public static void JudgeIsJiao(String orign, string target)
    {
        List<int> orignlist = new List<int>();
        List<int> targetlist = new List<int>();
        bool isJiao = false;
        for (int i = 0; i < orign.count; i++)
        {
            orignlist.add(int.Parse(target[i]));
        }
        for (int j = 0; j < target.count; j++)
        {
            targetlist.add(int.Parse(target[j]));
        }
        isJiao = orignlist.Intersect(targetlist).count > 0;
        if (isJiao)
        {
            List<int> unionlist = CountJiao(orignlist, targetlist);
            unionlist.Sort((x, y) => x.CompareTo(y));
            output.add(unionlist);
        }

    }

    public static List<int> CountJiao(List<int> orign, List<int> target)
    {
        List<int> mergedlist = new List<int>(orign);
        mergedList.AddRange(target.Except(target));
        return mergedList;
    }
}
}
