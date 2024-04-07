import java.util.Scanner;

public class WateringPlants {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = init(scanner);
        
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = init(scanner);
        }
        
        int v = init(scanner);
        
        cmp(arr, v);
        
        System.out.println(countingSteps(arr, v));
    }
    
    private static int init(Scanner scanner) {
        int val = scanner.nextInt();
        if (val <= 0) {
            throw new IllegalArgumentException("Invalid input");
        }
        return val;
    }
    
    private static void cmp(int[] arr, int v) {
        for (int j : arr) {
            if (v < j) {
                throw new IllegalArgumentException("The volume of the watering can is not enough to water the flower");
            }
        }
    }
    
    private static int countingSteps(int[] arr, int v) {
        int count = 0;
        int tmp = v;
        
        for (int i = 0; i < arr.length; i++) {
            if (tmp < arr[i]) {
                tmp = v;
                count += i * 2;
            }
            count++;
            tmp -= arr[i];
        }
        
        return count;
    }
}
