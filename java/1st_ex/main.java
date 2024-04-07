import java.util.Scanner;

public class Survaving {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int S = init(scanner);
        int N = init(scanner);
        int M = init(scanner);

        System.out.println(func(S, N, M));
    }

    private static int init(Scanner scanner) {
        int val = scanner.nextInt();
        if (val <= 0) {
            throw new IllegalArgumentException("Invalid input");
        }
        return val;
    }

    private static int func(int S, int N, int M) {
        if (S * M > (S - S / 7) * N) {
            return -1;
        }
        
        int totalDays = S * M / N;
        if ((S * M % N) > 0) {
            totalDays++;
        }
        return totalDays;
    }
}
