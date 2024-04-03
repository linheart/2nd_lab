use std::io::stdin;

fn counting_steps(arr: &Vec<i32>, v: i32) -> i32 {
    let mut count = 0;
    let mut tmp = v;

    for i in 0..arr.len() {
        if tmp < arr[i] {
            tmp = v;
            count += i * 2;
        }
        count += 1;
        tmp -= arr[i];
    }

    count
}

fn main() {
    let mut input = String::new();
    
    stdin().read_line(&mut input).expect("Failed to read line");
    let n: usize = input.trim().parse().expect("Input was not a number");
    input.clear();
    
    stdin().read_line(&mut input).expect("Failed to read line");
    let arr: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    if arr.len() != n {
        panic!("The array does not consist of n elements");
    }
    input.clear();
    
    stdin().read_line(&mut input).expect("Failed to read line");
    let v: i32 = input.trim().parse().expect("Input was not a number");
    
    if v < *arr.iter().max().unwrap() {
        panic!("The volume of the watering can is not enough to water the flower");
    }
    
    println!("{}", counting_steps(&arr, v));
}

