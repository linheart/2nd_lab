using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Err(string exc)
    {
        throw new Exception(exc);
    }

    static int Init()
    {
        int val = int.Parse(Console.ReadLine());
        if (val <= 0)
        {
            Err("Invalid input");
        }
        return val;
    }

    static void Cmp(List<int> arr, int v)
    {
        if (v < arr.Max())
        {
            Err("The volume of the watering can is not enough to water the flower");
        }
    }

    static int CountingSteps(List<int> arr, int v)
    {
        int count = 0;
        int tmp = v;

        for (int i = 0; i < arr.Count; i++)
        {
            if (tmp < arr[i])
            {
                tmp = v;
                count += (i) * 2;
            }
            count++;
            tmp -= arr[i];
        }

        return count;
    }

    static void Main(string[] args)
    {
        int n = Init();

        List<int> arr = new List<int>();
        for (int i = 0; i < n; i++)
        {
            arr.Add(Init());
        }

        int v = Init();

        Cmp(arr, v);

        Console.WriteLine(CountingSteps(arr, v));
    }
}
