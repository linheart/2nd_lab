using System;

class Program
{
    static void Err(string exc)
    {
        throw new Exception(exc);
    }

    static int Init()
    {
        return int.Parse(Console.ReadLine());
    }

    static int CountingDup(int n)
    {
        int a = Init();
        int b = a;
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            a = Init();
            if (a == b)
            {
                count++;
            }
            b = a;
        }
        return count;
    }

    static void Main(string[] args)
    {
        int n = Init();
        if (n <= 0)
        {
            Err("Invalid input");
        }

        Console.WriteLine(CountingDup(n));
    }
}
