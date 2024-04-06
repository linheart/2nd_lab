using System;

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

    static int Func(int S, int N, int M)
    {
        if (S * M > (S - S / 7) * N)
        {
            return -1;
        }
        return (int)Math.Ceiling((double)S * M / N);
    }

    static void Main(string[] args)
    {
        int S = Init();
        int N = Init();
        int M = Init();

        Console.WriteLine(Func(S, N, M));
    }
}
