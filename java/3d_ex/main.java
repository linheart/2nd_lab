import java.util.Scanner;

public class DuplicateCounter {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = init(scanner);
        if (n <= 0) {
            err("Invalid input");
        }
        
        System.out.println(countingDup(n, scanner));
    }
    
    private static int init(Scanner scanner) {
        return scanner.nextInt();
    }
    
    private static void err(String exc) {
        throw new IllegalArgumentException(exc);
    }
    
    private static int countingDup(int n, Scanner scanner) {
        int count = 0;
        int a, b = init(scanner);
        
        for (int i = 1; i < n; i++) {
            a = init(scanner);
            if (a == b) {
                count++;
            }
            b = a;
        }
        
        return count;
    }
}
